#!/usr/bin/env python3
"""Build llvm-objcopy --redefine-syms mapping from the symbol file.

For each renamed entry `NAME = 0xADDRESS;` in main_overlay.txt that has a
non-func_ name, emit `func_<addr_lowercase> NAME` if the ELF currently
contains the `func_<addr>` symbol at that address.
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path("E:/Projects/rogue_squadron64")
SYM_FILE = REPO / "symbol_files" / "main_overlay.txt"
ELF = REPO / "build" / "roguesquadron.elf"

# Parse symbol file: capture all `name = 0xADDRESS;` entries.
SYM_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;")

renames = {}  # addr_int -> new_name
for line in SYM_FILE.read_text(encoding="utf-8", errors="replace").splitlines():
    line = line.split("//", 1)[0]  # strip line comments
    m = SYM_RE.match(line.strip())
    if not m:
        continue
    name = m.group(1)
    addr = int(m.group(2), 16)
    # Skip auto-generated func_HHHHHHHH entries — those aren't renames.
    if name.startswith("func_") and len(name) == 13 and all(c in "0123456789abcdefABCDEF" for c in name[5:]):
        continue
    # Skip D_HHHHHHHH (data symbols already correctly named).
    if name.startswith("D_") and len(name) == 10 and all(c in "0123456789abcdefABCDEF" for c in name[2:]):
        continue
    # Skip fake_func_HHHHHHHH.
    if name.startswith("fake_func_"):
        continue
    renames[addr] = name

print(f"# {len(renames)} non-generic symbol-file entries", file=sys.stderr)

# Get current ELF symbols.
nm_out = subprocess.run(
    ["llvm-nm", str(ELF)],
    capture_output=True, text=True, check=True,
).stdout

elf_func_at_addr = {}  # addr_int -> name (only func_* names)
elf_name_at_addr = {}  # addr_int -> name (any name)
for ln in nm_out.splitlines():
    parts = ln.split()
    if len(parts) < 3:
        continue
    addr_str, kind, name = parts[0], parts[1], parts[2]
    try:
        addr = int(addr_str, 16)
    except ValueError:
        continue
    elf_name_at_addr.setdefault(addr, []).append(name)
    if name.startswith("func_") and kind in ("t", "T"):
        elf_func_at_addr[addr] = name

# Build map.
mapping = []
already_named = 0
no_func_at_addr = 0
for addr, new_name in renames.items():
    # Is the name already in the ELF?
    names_here = elf_name_at_addr.get(addr, [])
    if new_name in names_here:
        already_named += 1
        continue
    # Is there a func_<addr> at this address to rename?
    cur = elf_func_at_addr.get(addr)
    if cur is None:
        no_func_at_addr += 1
        continue
    mapping.append((cur, new_name))

print(f"# {already_named} already named correctly in ELF", file=sys.stderr)
print(f"# {no_func_at_addr} have no matching func_* in ELF (likely overlay/non-func or merged)", file=sys.stderr)
print(f"# {len(mapping)} renames will be applied", file=sys.stderr)

# Write mapping file.
out_path = REPO / "build" / "redefine-syms.txt"
with out_path.open("w", encoding="utf-8") as f:
    for old, new in mapping:
        f.write(f"{old} {new}\n")

print(str(out_path))
