"""Find unnamed func_HHHH that are called by many named-caller functions.

High named-caller fan-in is a strong semantic constraint: if 5 different
named functions call func_X, the body must do something coherent that
fits all 5 caller contexts.
"""
import re
import sys
from pathlib import Path
from collections import defaultdict

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
func_start = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
call_re = re.compile(r"^\s+(\w+)\(rdram,\s*ctx\);")
unnamed = re.compile(r"^func_[0-9A-Fa-f]{8}$")

callers_of = defaultdict(set)

for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    cur = None
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            m = func_start.match(line.strip())
            if m:
                cur = m.group(1)
                continue
            if cur is None:
                continue
            m = call_re.match(line)
            if m:
                callee = m.group(1)
                if unnamed.match(callee) and not unnamed.match(cur):
                    callers_of[callee].add(cur)

# Sort by number of distinct named callers, descending.
ranked = sorted(callers_of.items(), key=lambda kv: -len(kv[1]))
for callee, callers in ranked[:50]:
    if len(callers) < 4:
        break
    print(f"{callee}  ({len(callers)} named callers)")
    for c in sorted(callers)[:8]:
        print(f"    {c}")
