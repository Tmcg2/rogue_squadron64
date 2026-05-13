"""Find containing function for callsites of given target symbols across the recompiled output."""
import re, sys
from pathlib import Path

RECOMP_DIR = Path("E:/Projects/N64Recomp/RecompiledFuncs")
targets = sys.argv[1:] if len(sys.argv) > 1 else []

func_re = re.compile(r"^RECOMP_FUNC void (\w+)\(uint8_t\* rdram")
# Match `   target(rdram, ctx);` — leading whitespace, target call, no other context
call_re_per_target = {t: re.compile(r"^\s+" + re.escape(t) + r"\(rdram, ctx\);") for t in targets}

results = {t: [] for t in targets}
for fpath in sorted(RECOMP_DIR.glob("funcs_*.c")):
    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
        cur_fn = ""
        for ln_no, line in enumerate(f, start=1):
            m = func_re.match(line)
            if m:
                cur_fn = m.group(1)
                continue
            for t, cre in call_re_per_target.items():
                if cre.match(line):
                    results[t].append((fpath.name, ln_no, cur_fn))

for t, hits in results.items():
    print(f"=== {t} ({len(hits)} callers) ===")
    for fn_path, ln, caller in hits:
        print(f"  {fn_path}:{ln} <- {caller}")
