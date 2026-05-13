"""Find unnamed func_HHHH that load specific string addresses (lui+addiu).

Per-register lui tracking: lui $rN, hi  ->  ADD32(ctx->rN, lo) computes
the address (hi << 16) + lo. We track each register's last lui value and
only emit a hit when ADD32 uses that same register.
"""
import re
import sys
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
SYM_FILE = Path("E:/Projects/rogue_squadron64/symbol_files/main_overlay.txt")

strs = {}
str_re = re.compile(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);.*'([^']+)'")
str_re2 = re.compile(r'^(\w+)\s*=\s*0x([0-9A-Fa-f]+);.*"([^"]+)"')
for line in SYM_FILE.read_text(encoding="utf-8", errors="replace").splitlines():
    m = str_re.search(line) or str_re2.search(line)
    if m and "type:asciz" in line:
        strs[int(m.group(2), 16)] = (m.group(1), m.group(3))

print(f"# Loaded {len(strs)} named string addresses", file=sys.stderr)

func_start = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
unnamed_re = re.compile(r"^func_[0-9A-Fa-f]{8}$")
lui_re = re.compile(r"ctx->(\w+)\s*=\s*S32\(0X([0-9A-Fa-f]+)\s*<<\s*16\)")
add_re = re.compile(r"ctx->(\w+)\s*=\s*ADD32\(ctx->(\w+),\s*(-?)0X([0-9A-Fa-f]+)\)")

result = {}

for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    cur_func = None
    lui_vals = {}
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            m = func_start.match(line.strip())
            if m:
                name = m.group(1)
                cur_func = name if unnamed_re.match(name) else None
                lui_vals = {}
                continue
            if cur_func is None:
                continue
            m = lui_re.search(line)
            if m:
                reg = m.group(1)
                hi = int(m.group(2), 16) << 16
                lui_vals[reg] = hi
                continue
            m = add_re.search(line)
            if m:
                dst, src, sign, off_s = m.group(1), m.group(2), m.group(3), m.group(4)
                if src in lui_vals:
                    off = int(off_s, 16) * (-1 if sign == "-" else 1)
                    addr = (lui_vals[src] + off) & 0xFFFFFFFF
                    if addr in strs:
                        result.setdefault(cur_func, set()).add(
                            (addr, strs[addr][0], strs[addr][1])
                        )
                if dst in lui_vals and dst != src:
                    del lui_vals[dst]

for func, refs in sorted(result.items()):
    for (addr, name, val) in sorted(refs):
        print(f"{func}\t0x{addr:08X}\t{name}\t{val!r}")
