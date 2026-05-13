"""Find tiny unnamed wrappers that call spawnNpcOfType."""
import re
import sys
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
func_start = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
unnamed = re.compile(r"^func_[0-9A-Fa-f]{8}$")
end_re = re.compile(r"^\s*;\}\s*$")
mips_instr = re.compile(r"^\s*// 0x[0-9A-Fa-f]{8}:")
spawn_call = re.compile(r"\bspawnNpcOfType\(rdram,\s*ctx\)")

MAX_INSTR = 40

for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    cur_func = None
    instr_count = 0
    has_spawn = False
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            m = func_start.match(line.strip())
            if m:
                if cur_func and unnamed.match(cur_func) and has_spawn and instr_count <= MAX_INSTR:
                    print(f"{cur_func}\t{instr_count}\t{fpath.name}")
                cur_func = m.group(1)
                instr_count = 0
                has_spawn = False
                continue
            if cur_func is None:
                continue
            if end_re.match(line):
                if unnamed.match(cur_func) and has_spawn and instr_count <= MAX_INSTR:
                    print(f"{cur_func}\t{instr_count}\t{fpath.name}")
                cur_func = None
                continue
            if mips_instr.match(line):
                instr_count += 1
            if spawn_call.search(line):
                has_spawn = True
