"""Find functions matching the NPC handler dispatch shape.

The protocol (project_npc_handler_protocol.md) is: handler(slot, action, msg)
with action codes 1/2/3/4/0x1000. Recompiled handlers always start with:
  - andi a1, a1, 0xFFFF      → ctx->r5 = ctx->r5 & 0xFFFF
  - addiu v0, zero, 2        → ctx->r2 = ADD32(0, 0x2)
  - beq a1, v0, action2_label
  - slti v0, a1, 3
  - beq v0, zero, ...
  - addiu v0, zero, 1
  - beq a1, v0, action1_label

So we look for the consecutive `ctx->r5 = ctx->r5 & 0XFFFF` and
`ctx->r2 = ADD32(0, 0X2)` pattern early in a function body.
"""
import re
import sys
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
func_start = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
unnamed = re.compile(r"^func_[0-9A-Fa-f]{8}$")
mask = re.compile(r"ctx->r5\s*=\s*ctx->r5\s*&\s*0XFFFF")
const2 = re.compile(r"ctx->r2\s*=\s*ADD32\(0,\s*0X2\)")
end_re = re.compile(r"^\s*;\}\s*$")

hits = []
for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    cur_func = None
    body_lines = []
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        for i, line in enumerate(f):
            m = func_start.match(line.strip())
            if m:
                cur_func = m.group(1)
                body_lines = []
                continue
            if cur_func is None:
                continue
            if end_re.match(line):
                cur_func = None
                continue
            body_lines.append(line)
            if len(body_lines) > 80:
                continue
            # Check shape: both lines in first 80 lines
            if len(body_lines) == 80:
                joined = "\n".join(body_lines)
                if mask.search(joined) and const2.search(joined):
                    if unnamed.match(cur_func):
                        hits.append((cur_func, fpath.name))

# Filter out duplicates
seen = set()
out = []
for h in hits:
    if h[0] not in seen:
        seen.add(h[0])
        out.append(h)

print(f"# Unnamed handler-shape candidates: {len(out)}", file=sys.stderr)
for func, fn in out:
    print(f"{func}\t{fn}")
