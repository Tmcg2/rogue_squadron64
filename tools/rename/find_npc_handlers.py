"""Enumerate NPC handlers by tracking the first arg passed to spawnNpcOfType.

The handler function pointer is passed in $a0 (ctx->r4). The recompiled
C materializes it via lui + addiu — we track ctx->r4 backward from each
spawnNpcOfType(rdram, ctx) call to find the materialized address.

Per-register lui tracking across function boundaries (resets per function).
"""
import re
import sys
from collections import defaultdict
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")

func_start = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
lui_re = re.compile(r"ctx->(r\d+|r1)\s*=\s*S32\(0X([0-9A-Fa-f]+)\s*<<\s*16\)")
add_re = re.compile(r"ctx->(r\d+|r1)\s*=\s*ADD32\(ctx->(r\d+|r1),\s*(-?)0X([0-9A-Fa-f]+)\)")
spawn_call = re.compile(r"\bspawnNpcOfType\(rdram,\s*ctx\)")

handlers = defaultdict(list)  # handler_addr -> [(caller_func, file)]

for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    cur_func = None
    reg_values = {}  # reg name -> resolved address value
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            stripped = line.strip()
            m = func_start.match(stripped)
            if m:
                cur_func = m.group(1)
                reg_values = {}
                continue
            if cur_func is None:
                continue
            # Track lui: ctx->rN = S32(0xHHHH << 16)
            m = lui_re.search(line)
            if m:
                reg = m.group(1)
                hi = int(m.group(2), 16) << 16
                reg_values[reg] = hi & 0xFFFFFFFF
                continue
            # Track ADD32: ctx->rDst = ADD32(ctx->rSrc, offset)
            m = add_re.search(line)
            if m:
                dst, src, sign, off_s = m.group(1), m.group(2), m.group(3), m.group(4)
                if src in reg_values:
                    off = int(off_s, 16) * (-1 if sign == "-" else 1)
                    new_val = (reg_values[src] + off) & 0xFFFFFFFF
                    reg_values[dst] = new_val
                elif dst in reg_values and dst != src:
                    # invalidate stale tracking when dst is reused
                    del reg_values[dst]
                continue
            # Track direct addu (move): ctx->rDst = ADD32(ctx->rSrc, 0)
            m = re.search(r"ctx->(r\d+)\s*=\s*ADD32\(ctx->(r\d+),\s*0\)", line)
            if m:
                dst, src = m.group(1), m.group(2)
                if src in reg_values:
                    reg_values[dst] = reg_values[src]
                elif dst in reg_values and dst != src:
                    del reg_values[dst]
                continue
            # Detect spawnNpcOfType call site — capture r4
            if spawn_call.search(line):
                handler_addr = reg_values.get("r4")
                if handler_addr is not None and 0x80000000 <= handler_addr < 0x80800000:
                    handlers[handler_addr].append((cur_func, fpath.name))

print(f"# Distinct handler addresses passed to spawnNpcOfType: {len(handlers)}", file=sys.stderr)
ranked = sorted(handlers.items(), key=lambda kv: -len(kv[1]))
for addr, callers in ranked:
    print(f"0x{addr:08X}\t{len(callers):3d}\t{callers[0][0]} ({callers[0][1]})")
