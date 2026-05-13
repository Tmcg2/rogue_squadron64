"""Find tiny unnamed func_HHHH (< N MIPS instructions before returning)."""
import re
import sys
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
func_re = re.compile(r"^RECOMP_FUNC void (func_[0-9A-Fa-f]{8})\(uint8_t\* rdram")
end_re = re.compile(r"^\s*;\}\s*$")
mips_comment_re = re.compile(r"^\s*// 0x[0-9A-Fa-f]{8}:")

MAX_INSTR = 8  # tiny

results = []
for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        in_func = None
        instr_count = 0
        body_lines = []
        for line in f:
            m = func_re.match(line.strip())
            if m:
                if in_func and instr_count <= MAX_INSTR:
                    results.append((in_func, instr_count, fpath.name, body_lines))
                in_func = m.group(1)
                instr_count = 0
                body_lines = []
                continue
            if in_func and end_re.match(line):
                if instr_count <= MAX_INSTR:
                    results.append((in_func, instr_count, fpath.name, body_lines))
                in_func = None
                instr_count = 0
                body_lines = []
                continue
            if in_func:
                if mips_comment_re.match(line):
                    instr_count += 1
                    body_lines.append(line.rstrip())

for name, n, fn, body in results:
    print(f"{name}\t{n}\t{fn}")
