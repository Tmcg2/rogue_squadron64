WIBO := ~/compilers/wibo-x86_64

CROSS := mips-linux-gnu-
AS := $(CROSS)as
LD := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy

N64COMPILERPATH := ~/compilers/gccsn2.7.2sn0001
N64CC := $(N64COMPILERPATH)/cc1n64.exe

IDOCOMPILERPATH := ~/compilers/ido5.3
IDOCC := $(IDOCOMPILERPATH)/cc

ASM_DIRS  := $(shell find asm -type d -not -path "asm/nonmatchings*")
S_FILES   := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES := $(shell find assets -type f -name "*.bin" -not -path "assets/main*")
C_FILES   := $(shell find src -type f -name "*.c")
O_FILES   := $(S_FILES:%.s=build/%.o) $(BIN_FILES:%.bin=build/%.o) $(C_FILES:%.c=build/%.o)

$(shell mkdir -p $(foreach dir,$(ASM_DIRS) assets,build/$(dir)))

SYMBOL_FILES := undefined_funcs_auto.txt undefined_syms_auto.txt symbol_files/cinematic_overlay.txt symbol_files/libultra.txt symbol_files/main_overlay.txt symbol_files/menu_overlay.txt symbol_files/mission_overlay.txt symbol_files/zlib.txt

build/%o: %.c
	$(N64CC) $< -o $@

build/%.o: %.s
	$(AS) -I ./include -march=vr4300 -mabi=32 -mgp32 -mfp32 -mips3 -G0 -o $@ $<

build/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

.PHONY: clean

tyler.elf: $(O_FILES) roguesquadron.ld
	$(LD) -EB -T ./roguesquadron.ld -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@

tyler.z64: tyler.elf
	$(OBJCOPY) $< $@ -O binary

clean:
	rm -rf build/*
