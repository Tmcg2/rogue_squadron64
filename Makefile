PYTHON := python3

LDSCRIPT := roguesquadron.ld

TOOLSDIR := ./tools

CROSS   := mips-linux-gnu-
AS      := $(CROSS)as
LD      := $(CROSS)ld
CPP     := $(CROSS)cpp
OBJCOPY := $(CROSS)objcopy

MODERNASN := $(PYTHON) $(TOOLSDIR)/modern-asn64.py $(AS)

INCLUDE_DIRS := -I ./include/ -I ./ultralib/include/
DEFINES      := -DINCLUDE_ASM_USE_MACRO_INC -D_LANGUAGE_C
CPPFLAGS     := -E -lang-c
CFLAGS       := -quiet -O2 -G0 -mips3
ASFLAGS      := -EB -mabi=32 -mfp32 -mgp32 -mtune=vr4300 -march=vr4300 -mips3 -G0 -I./include

N64COMPILERPATH := $(TOOLSDIR)/gcc2.8.1sn/
N64CC           := $(N64COMPILERPATH)/cc1n64.exe

IDOCOMPILERPATH := $(TOOLSDIR)/ido5.3
IDOCC           := $(IDOCOMPILERPATH)/cc

C_DIRS    := $(shell find src -type d)
C_FILES   := $(foreach dir,$(C_DIRS),$(wildcard $(dir)/*.c))
ASM_DIRS  := $(shell find asm -type d -not -path "asm/nonmatchings*")
ASM_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES := $(shell find assets -type f -name "*.bin" -not -path "assets/main*")
O_FILES   := $(ASM_FILES:%.s=build/%.o) $(BIN_FILES:%.bin=build/%.o) $(C_FILES:%.c=build/%.o)

BUILD_DIRS := $(C_DIRS:%=build/%) $(ASM_DIRS:%=build/%)

SYMBOL_FILES := undefined_funcs_auto.txt undefined_syms_auto.txt symbol_files/cinematic_overlay.txt symbol_files/libultra.txt symbol_files/main_overlay.txt symbol_files/menu_overlay.txt symbol_files/mission_overlay.txt symbol_files/zlib.txt

.PHONY: clean

build/tyler.z64: build/tyler.elf
	$(OBJCOPY) $< $@ -O binary

build/tyler.elf: $(O_FILES) $(LDSCRIPT)
	$(LD) -Map=$@.map -EB -G0 -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@

$(BUILD_DIRS):
	mkdir -p $@

$(N64CC):
	mkdir -p "$(@D)"
	wget "https://github.com/marijnvdwerf/sn64/releases/download/1%2C0%2C0%2C2/cc1n64.exe" -P "$(@D)"
	chmod +x "$@"

$(IDOCC):
	mkdir -p "$(@D)"
	wget "https://github.com/decompals/ido-static-recomp/releases/download/v1.2/ido-5.3-recomp-linux.tar.gz" -P "$(@D)"
	tar xzf "$(@D)/ido-5.3-recomp-linux.tar.gz" -C "$(@D)"

build/%.o: %.c | $(BUILD_DIRS) $(N64CC)
	$(CPP) $(INCLUDE_DIRS) $(DEFINES) $(CPPFLAGS) $< -o build/$<.i
	$(N64CC) $(CFLAGS) build/$<.i -o build/$<.s
	$(MODERNASN) $(ASFLAGS) build/$<.s -o $@

build/%.o: %.s | $(BUILD_DIRS)
	$(AS) $(ASFLAGS) -o $@ $<

build/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

clean:
	rm -rf $(BUILD_DIRS)
