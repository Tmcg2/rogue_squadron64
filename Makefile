PYTHON := python3

LDSCRIPT := roguesquadron.ld

TOOLSDIR := ./tools

CROSS   := mips-linux-gnu-
# AS      := $(CROSS)as
LD      := $(CROSS)ld
CPP     := $(CROSS)cpp
OBJCOPY := $(CROSS)objcopy

MODERNASN := $(PYTHON) $(TOOLSDIR)/modern-asn64.py
WIBO := $(TOOLSDIR)/wibo-x86_64

INCLUDE_DIRS := -I ./include/ -I ./ultralib/include/
DEFINES      := -DINCLUDE_ASM_USE_MACRO_INC -D_LANGUAGE_C
CPPFLAGS     := -E -lang-c
CFLAGS       := -quiet -O2 -G0 -mips3 -mhard-float
ASFLAGS      := -arch=vr4300 -abi=32 -mips3 -G0 -I./include

COMPILERSPATH := $(TOOLSDIR)/compilers

281SNCC    := $(COMPILERSPATH)/gcc281sn/cc1n64.exe
281SNAS    := $(COMPILERSPATH)/gcc281sn/asn64.exe
272SN001CC := $(COMPILERSPATH)/gcc272sn0001/cc1n64.exe
272SN001AS := $(COMPILERSPATH)/gcc272sn0001/asn64.exe

CC := $(281SNCC)
AS := $(281SNAS)

PSYQ := $(COMPILERSPATH)/psyq-obj-parser

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
	$(LD) -Map=$@.map -EB -T $(LDSCRIPT) -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@

$(BUILD_DIRS):
	mkdir -p $@

$(281SNCC):
	mkdir -p "$(@D)"
	wget "https://github.com/marijnvdwerf/sn64/releases/download/1%2C0%2C0%2C2/cc1n64.exe" -P "$(@D)"
	chmod +x "$@"

$(281SNAS):
	mkdir -p "$(@D)"
	wget "https://github.com/marijnvdwerf/sn64/releases/download/1%2C0%2C0%2C2/asn64.exe" -P "$(@D)"
	chmod +x "$@"

$(PSYQ):
	mkdir -p "$(@D)"
	wget "https://github.com/decompme/compilers/releases/download/compilers/psyq-obj-parser.tar.gz" -P "$(@D)"
	tar xzf "$(@D)/psyq-obj-parser.tar.gz" -C "$(@D)"
	chmod +x $@

$(272SN001CC) $(272SN001AS) &:
	mkdir -p "$(@D)"
	wget "https://github.com/decompme/compilers/releases/download/compilers/n64_sn272_0001.tar.gz" -P "$(@D)"
	tar xzf "$(@D)/n64_sn272_0001.tar.gz" -C "$(@D)"
	chmod +x $@

$(WIBO):
	mkdir -p "$(@D)"
	wget "https://github.com/decompals/wibo/releases/download/1.2.0/wibo-x86_64" -P "$(@D)"
	chmod +x "$@"

build/src/%.o: src/%.c | $(281SNCC) $(281SNAS) $(272SN001CC) $(272SN001AS) $(PSYQ) $(WIBO) $(BUILD_DIRS)
	$(CPP) $(INCLUDE_DIRS) $(DEFINES) $(CPPFLAGS) $< -o $@.i
	$(WIBO) $(CC) $(CFLAGS) $@.i -o $@.s
	$(WIBO) $(AS) $(ASFLAGS) $@.s -o $@.obj
	$(PSYQ) $@.obj -o $@ -b -n -s

build/src/main/03310.o: CC = $(272SN001CC)
build/src/main/03310.o: AS = $(272SN001AS)
build/src/main/04030.o: CC = $(272SN001CC)
build/src/main/04030.o: AS = $(272SN001AS)
build/src/main/1D000.o: CC = $(272SN001CC)
build/src/main/1D000.o: AS = $(272SN001AS)
build/src/main/1EE30.o: CC = $(272SN001CC)
build/src/main/1EE30.o: AS = $(272SN001AS)
build/src/zlib/%.o: CC = $(272SN001CC)
build/src/zlib/%.o: AS = $(272SN001AS)
build/src/zlib/%.o: CFLAGS = -quiet -O3 -G0 -mips3

build/%.o: %.s | $(BUILD_DIRS)
	$(MODERNASN) $(CROSS)as -DINCLUDE_ASM_USE_MACRO_INC -march=vr4300 -mabi=32 -mips3 -G0 -I./include -o $@ $<

build/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

clean:
	rm -rf $(BUILD_DIRS)
