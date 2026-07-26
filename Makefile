PYTHON := python3

LDSCRIPT := roguesquadron.ld

TOOLSDIR := ./tools

CROSS   := mips-linux-gnu-
AS      := $(CROSS)as
LD      := $(CROSS)ld
CPP     := $(CROSS)cpp
OBJCOPY := $(CROSS)objcopy

MODERNASN := $(PYTHON) $(TOOLSDIR)/modern-asn64.py $(AS)

CPPFLAGS := -E -lang-c -undef -D__GNUC__=2 -Dmips -D__mips__ -D__mips -Dn64 -D__n64__ -D__n64 -D_PSYQ -D__EXTENSIONS__ -D_MIPSEB -D__CHAR_UNSIGNED__ -I ./include/ -DINCLUDE_ASM_USE_MACRO_INC
CFLAGS := -quiet -O2 -G0 -mips2
ASFLAGS := -march=vr4300 -mabi=32 -mgp32 -mfp32 -mips3 -G0 -O2 -I./include

N64COMPILERPATH := ~/compilers/gccsn2.7.2sn0001
N64CC           := $(N64COMPILERPATH)/cc1n64.exe
N64AS           := $(N64COMPILERPATH)/asn64.exe

IDOCOMPILERPATH := ~/compilers/ido5.3
IDOCC           := $(IDOCOMPILERPATH)/cc

ASM_DIRS  := $(shell find asm -type d -not -path "asm/nonmatchings*")
S_FILES   := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES := $(shell find assets -type f -name "*.bin" -not -path "assets/main*")
C_FILES   := $(shell find src -type f -name "*.c")
O_FILES   := $(S_FILES:%.s=build/%.o) $(BIN_FILES:%.bin=build/%.o) $(C_FILES:%.c=build/%.o)

$(shell mkdir -p $(foreach dir,$(ASM_DIRS) assets,build/$(dir)))

SYMBOL_FILES := undefined_funcs_auto.txt undefined_syms_auto.txt symbol_files/cinematic_overlay.txt symbol_files/libultra.txt symbol_files/main_overlay.txt symbol_files/menu_overlay.txt symbol_files/mission_overlay.txt symbol_files/zlib.txt

.PHONY: clean

tyler.z64: tyler.elf
	$(OBJCOPY) $< $@ -O binary

tyler.elf: $(O_FILES)
	$(LD) -EB -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@

build/%.o: %.c
	mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o build/$<.i
	$(N64CC) $(CFLAGS) build/$<.i -o build/$<.s
	$(MODERNASN) $(ASFLAGS) build/$<.s -o $@

build/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

build/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

clean:
	rm -rf build/*
	rm tyler.elf
