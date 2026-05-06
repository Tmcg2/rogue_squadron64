#!/usr/bin/env python3
"""
Generate a 32-bit big-endian MIPS ELF from rogue_squadron.z64 + symbol_files/.
Produces build/roguesquadron.elf consumable by N64Recomp.
"""
import struct, os, re, sys

ROM = "rogue_squadron.z64"
OUT = "build/roguesquadron.elf"

# Maps source file → section index (1-based, .rom_anchor=1, .entry=2, .text=3, overlays=4-6)
OVERLAY_FILE_TO_SHNDX = {
    "symbol_files/mission_overlay.txt":   4,
    "symbol_files/menu_overlay.txt":      5,
    "symbol_files/cinematic_overlay.txt": 6,
}

# ROM offset, VRAM base, size, section name
# NOTE: .rom_anchor at ROM offset 0 forces N64Recomp's min_load_address=0, which is
# required for the entrypoint detection check (rom_address == 0x1000) to work.
SECTIONS = [
    (0x000000, 0x00000000, 0x0040,   ".rom_anchor"),   # N64 header — dummy VRAM, no symbols
    (0x001000, 0x80000400, 0x0040,   ".entry"),
    (0x001040, 0x80000440, 0xA4CF0,  ".text"),
    (0x0A5D30, 0x800A5130, 0x665A0,  ".ovl.mission"),
    (0x10C2D0, 0x800A5130, 0x283F0,  ".ovl.menu"),
    (0x137580, 0x800A5130, 0x0B810,  ".ovl.cinematic"),
]

# BSS regions: (VRAM, size, section index offset, name)
BSS_SECTIONS = [
    (0x800B0940, 0x15B0,  ".bss.cinematic"),
    (0x800CD520, 0x2EC0,  ".bss.menu"),
    (0x8010B6D0, 0x1B30,  ".bss.mission"),
    (0x8010D200, 0x47490, ".bss"),
]

# ELF constants
ELFMAG        = b"\x7fELF"
ELFCLASS32    = 1
ELFDATA2MSB   = 2
ET_EXEC       = 2
EM_MIPS       = 8
EV_CURRENT    = 1
PT_LOAD       = 1
PF_R, PF_W, PF_X = 4, 2, 1
SHT_NULL      = 0
SHT_PROGBITS  = 1
SHT_SYMTAB    = 2
SHT_STRTAB    = 3
SHT_NOBITS    = 8
SHF_ALLOC     = 0x2
SHF_EXECINSTR = 0x4
STB_GLOBAL    = 1
STT_NOTYPE    = 0
STT_OBJECT    = 1
STT_FUNC      = 2
STV_DEFAULT   = 0
SHN_UNDEF     = 0
SHN_ABS       = 0xFFF1

B = ">"  # big-endian

def elf_header(e_phoff, e_shoff, e_phnum, e_shnum, e_shstrndx):
    return struct.pack(
        f"{B}4sBBBBBxxxxxxxHHIIIIIHHHHHH",
        ELFMAG, ELFCLASS32, ELFDATA2MSB, EV_CURRENT, 0, 0,
        ET_EXEC, EM_MIPS, EV_CURRENT,
        0,          # e_entry
        e_phoff, e_shoff,
        0x1000,     # e_flags: MIPS
        52,         # e_ehsize
        32,         # e_phentsize
        e_phnum,
        40,         # e_shentsize
        e_shnum,
        e_shstrndx,
    )

def phdr(p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align=0x10):
    return struct.pack(f"{B}IIIIIIII",
        p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align)

def shdr(sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size,
         sh_link=0, sh_info=0, sh_addralign=1, sh_entsize=0):
    return struct.pack(f"{B}IIIIIIIIII",
        sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size,
        sh_link, sh_info, sh_addralign, sh_entsize)

def sym_entry(st_name, st_value, st_size, st_info, st_other, st_shndx):
    return struct.pack(f"{B}IIIBBH",
        st_name, st_value, st_size, st_info, st_other, st_shndx)


def parse_asm_labels(asm_dirs, src_file_tag):
    """Extract glabel function addresses (and nonmatching sizes) from splat .s files."""
    GLABEL_RE      = re.compile(r"^glabel\s+(\w+)")
    NONMATCH_RE    = re.compile(r"^nonmatching\s+(\w+),\s*(0x[0-9A-Fa-f]+|\d+)")
    ADDR_RE        = re.compile(r"/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})")
    syms = {}       # name -> (vram, is_func, size, src_file_tag)
    nonmatch_sizes = {}  # name -> size (from nonmatching annotations)
    for asm_dir in asm_dirs:
        if not os.path.isdir(asm_dir):
            continue
        for root, _dirs, files in os.walk(asm_dir):
          for fname in files:
            if not fname.endswith(".s"):
                continue
            path = os.path.join(root, fname)
            pending_label = None
            for line in open(path, encoding="utf-8", errors="replace"):
                line = line.rstrip()
                nm = NONMATCH_RE.match(line)
                if nm:
                    nonmatch_sizes[nm.group(1)] = int(nm.group(2), 0)
                    continue
                m = GLABEL_RE.match(line)
                if m:
                    pending_label = m.group(1)
                    continue
                if pending_label:
                    am = ADDR_RE.search(line)
                    if am:
                        vram = int(am.group(1), 16)
                        if pending_label not in syms:
                            size = nonmatch_sizes.get(pending_label, 0)
                            syms[pending_label] = (vram, True, size, src_file_tag)
                    pending_label = None
    return [(n, v, f, s, p) for n, (v, f, s, p) in syms.items()]


def parse_symbols(files):
    """Return list of (name, vram, is_func, size, src_file) sorted by vram."""
    SYM_RE = re.compile(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;(.*)$")
    syms = {}
    for path in files:
        if not os.path.exists(path):
            continue
        for line in open(path, encoding="utf-8"):
            line = line.strip()
            m = SYM_RE.match(line)
            if not m:
                continue
            name, addr_s, comment = m.group(1), m.group(2), m.group(3)
            vram = int(addr_s, 16)
            if "defined:false" in comment:
                continue
            size_m = re.search(r"size:(0x[0-9A-Fa-f]+|\d+)", comment)
            size = int(size_m.group(1), 0) if size_m else 0
            # Data markers: explicit type (non-func), explicit size blob, name_end range,
            # or naming conventions (D_ = data label, junk_ = junk data).
            is_data = (
                ("type:" in comment and "type:func" not in comment) or
                "size:" in comment or
                "name_end:" in comment or
                name.startswith("D_") or
                name.startswith("junk_")
            )
            is_func = not is_data
            if name not in syms:
                syms[name] = (vram, is_func, size, path)
    return [(n, v, f, s, p) for n, (v, f, s, p) in sorted(syms.items(), key=lambda x: x[1][0])]


def vram_to_shndx(vram, src_file):
    """Return 1-based section index. Overlay symbols use src_file for disambiguation."""
    # Overlay symbols: use source file mapping
    if src_file in OVERLAY_FILE_TO_SHNDX:
        expected_shndx = OVERLAY_FILE_TO_SHNDX[src_file]
        _, base, size, _ = SECTIONS[expected_shndx - 1]
        if base <= vram < base + size:
            return expected_shndx
        return SHN_UNDEF  # symbol VRAM doesn't fit the overlay

    # Main/libultra/zlib: use VRAM range (.entry=index 1, .text=index 2, skip .rom_anchor=0)
    for i in range(1, 3):
        rom_off, base, size, _ = SECTIONS[i]
        if base <= vram < base + size:
            return i + 1  # 1-based section index

    return SHN_UNDEF


def build_strtab(names):
    """Build a string table blob. Offset 0 is always the empty string."""
    blob = b"\x00"
    offsets = {"": 0}
    for n in names:
        if n == "" or n in offsets:
            continue
        offsets[n] = len(blob)
        blob += n.encode() + b"\x00"
    return blob, offsets


def main():
    os.makedirs("build", exist_ok=True)
    rom = open(ROM, "rb").read()

    sec_data = [rom[rom_off: rom_off + size] for rom_off, _, size, _ in SECTIONS]

    all_syms = parse_symbols(
        ["symbol_files/main_overlay.txt", "symbol_files/mission_overlay.txt",
         "symbol_files/menu_overlay.txt", "symbol_files/cinematic_overlay.txt",
         "symbol_files/libultra.txt", "symbol_files/zlib.txt"]
    )
    # Supplement with glabel boundaries from splat-generated ASM files
    asm_labels = (
        parse_asm_labels(["asm/main", "asm/libultra", "asm/nonmatchings/main",
                          "asm/nonmatchings/libultra"], "symbol_files/main_overlay.txt") +
        parse_asm_labels(["asm/mission_overlay", "asm/nonmatchings/mission_overlay"],
                         "symbol_files/mission_overlay.txt") +
        parse_asm_labels(["asm/menu_overlay", "asm/nonmatchings/menu_overlay"],
                         "symbol_files/menu_overlay.txt") +
        parse_asm_labels(["asm/cinematic_overlay", "asm/nonmatchings/cinematic_overlay"],
                         "symbol_files/cinematic_overlay.txt")
    )
    # Merge: symbol_files take precedence for address/type; asm_labels provide sizes.
    # If a symbol_file entry has size=0 and asm has a nonzero size, use the asm size.
    sym_map = {s[0]: s for s in all_syms}
    for sym in asm_labels:
        name = sym[0]
        if name not in sym_map:
            sym_map[name] = sym
        elif sym[4] and sym_map[name][3] == 0 and sym[3] > 0:
            # Keep symbol_file vram/type/srcfile; update size from asm
            n, v, f, _, p = sym_map[name]
            sym_map[name] = (n, v, f, sym[3], p)
    # Entry segment symbols not in any symbol file (from asm/entry_point.s)
    for sym in [
        ("func_80000400", 0x80000400, True, 0xC,  "symbol_files/main_overlay.txt"),
        ("func_8000040C", 0x8000040C, True, 0x34, "symbol_files/main_overlay.txt"),
    ]:
        sym_map[sym[0]] = sym  # always use hardcoded entry sizes
    all_syms = sorted(sym_map.values(), key=lambda x: x[1])

    # Assign section indices; drop STT_FUNC symbols that don't map to a code section
    resolved = []
    skipped_funcs = 0
    for name, vram, is_func, size, src_file in all_syms:
        shndx = vram_to_shndx(vram, src_file)
        if shndx == SHN_UNDEF:
            if is_func:
                skipped_funcs += 1
                continue  # don't emit phantom functions N64Recomp would crash on
            # data/BSS: check BSS sections
            for bss_vram, bss_size, _ in BSS_SECTIONS:
                if bss_vram <= vram < bss_vram + bss_size:
                    shndx = SHN_ABS
                    break
        resolved.append((name, vram, is_func, size, shndx))

    print(f"Loaded {len(all_syms)} symbols, {len(resolved)} emitted, {skipped_funcs} unmapped functions skipped")

    # Compute missing function sizes: distance to next function in same section.
    # N64Recomp skips zero-size STT_FUNC symbols during JAL resolution.
    sec_end = {i + 1: SECTIONS[i][1] + SECTIONS[i][2] for i in range(len(SECTIONS))}
    funcs_by_sec = {}
    for i, (name, vram, is_func, size, shndx) in enumerate(resolved):
        if is_func and shndx not in (SHN_UNDEF, SHN_ABS):
            funcs_by_sec.setdefault(shndx, []).append(i)

    resolved_sized = []
    for i, (name, vram, is_func, size, shndx) in enumerate(resolved):
        if is_func and size == 0 and shndx not in (SHN_UNDEF, SHN_ABS):
            peers = funcs_by_sec.get(shndx, [])
            pos = next((j for j, idx in enumerate(peers) if idx == i), None)
            if pos is not None and pos + 1 < len(peers):
                next_vram = resolved[peers[pos + 1]][1]
            else:
                next_vram = sec_end.get(shndx, vram + 4)
            size = max(4, next_vram - vram)
        resolved_sized.append((name, vram, is_func, size, shndx))
    resolved = resolved_sized

    # Build string tables
    sec_names = [s[3] for s in SECTIONS]
    bss_names = [b[2] for b in BSS_SECTIONS]
    extra_names = [".symtab", ".strtab", ".shstrtab"]

    shstrtab_blob, shname_off = build_strtab(sec_names + bss_names + extra_names)
    strtab_blob, sym_off = build_strtab([s[0] for s in resolved])

    # Build symbol table
    symtab_entries = [sym_entry(0, 0, 0, 0, 0, 0)]  # null symbol
    for name, vram, is_func, size, shndx in resolved:
        st_type = STT_FUNC if (is_func and shndx not in (SHN_UNDEF, SHN_ABS)) else STT_OBJECT
        info = (STB_GLOBAL << 4) | st_type
        symtab_entries.append(sym_entry(sym_off[name], vram, size, info, STV_DEFAULT, shndx))
    symtab_blob = b"".join(symtab_entries)

    # Layout
    n_code = len(SECTIONS)
    n_bss  = len(BSS_SECTIONS)
    n_secs = 1 + n_code + n_bss + 3  # NULL + code + bss + symtab/strtab/shstrtab

    ehdr_size = 52
    n_phdrs   = n_code
    phdr_off  = ehdr_size
    data_off  = phdr_off + 32 * n_phdrs
    if data_off % 16:
        data_off += 16 - (data_off % 16)

    file_offs = []
    cur = data_off
    for d in sec_data:
        file_offs.append(cur)
        cur += len(d)
        if cur % 4:
            cur += 4 - (cur % 4)

    symtab_off  = cur; cur += len(symtab_blob)
    strtab_off  = cur; cur += len(strtab_blob)
    shstrtab_off = cur; cur += len(shstrtab_blob)
    if cur % 4: cur += 4 - (cur % 4)
    shdr_off = cur

    shstrndx = 1 + n_code + n_bss + 2
    symtab_shndx = 1 + n_code + n_bss
    strtab_shndx = symtab_shndx + 1

    out = bytearray()
    out += elf_header(phdr_off, shdr_off, n_phdrs, n_secs, shstrndx)
    while len(out) < data_off:
        out += b"\x00"

    for i, d in enumerate(sec_data):
        assert len(out) == file_offs[i], f"offset mismatch section {i}"
        out += d
        while len(out) % 4: out += b"\x00"

    assert len(out) == symtab_off;  out += symtab_blob
    assert len(out) == strtab_off;  out += strtab_blob
    assert len(out) == shstrtab_off; out += shstrtab_blob
    while len(out) % 4: out += b"\x00"
    assert len(out) == shdr_off

    # Section headers
    out += shdr(0, SHT_NULL, 0, 0, 0, 0)  # NULL
    for i, (rom_off, vram, size, name) in enumerate(SECTIONS):
        out += shdr(shname_off[name], SHT_PROGBITS,
                    SHF_ALLOC | SHF_EXECINSTR, vram,
                    file_offs[i], len(sec_data[i]), sh_addralign=16)
    for vram, size, name in BSS_SECTIONS:
        out += shdr(shname_off[name], SHT_NOBITS, SHF_ALLOC, vram, 0, size, sh_addralign=16)
    out += shdr(shname_off[".symtab"], SHT_SYMTAB, 0, 0,
                symtab_off, len(symtab_blob),
                sh_link=strtab_shndx, sh_info=1, sh_addralign=4, sh_entsize=16)
    out += shdr(shname_off[".strtab"], SHT_STRTAB, 0, 0, strtab_off, len(strtab_blob))
    out += shdr(shname_off[".shstrtab"], SHT_STRTAB, 0, 0, shstrtab_off, len(shstrtab_blob))

    # Write program headers. p_paddr = ROM offset so N64Recomp computes correct rom_addr.
    phdrs = bytearray()
    for i, (rom_off, vram, size, _) in enumerate(SECTIONS):
        phdrs += phdr(PT_LOAD, file_offs[i], vram, rom_off, len(sec_data[i]), size, PF_R | PF_X)
    out[phdr_off:phdr_off + len(phdrs)] = phdrs

    open(OUT, "wb").write(out)
    print(f"Wrote {OUT} ({len(out):,} bytes, {len(symtab_entries)} symbols, {n_secs} sections)")


if __name__ == "__main__":
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/..")
    main()
