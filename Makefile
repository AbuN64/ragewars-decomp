# Turok: Rage Wars: matching build.
# make check             builds every version ROM from the committed sources and verifies its SHA-1.
# make check CHECK=tree  verifies only that the committed generated files are present (no ROMs needed).
# make extract           splits every baserom into asm/<version>/ with splat; a data file's section is its stand-in's.
#                        A build extracts a version that has no asm/<version>/ yet on its own.
# Tool commands default to conventional names; put local paths in local.mk.
SHELL := /bin/sh
.SUFFIXES:
.DELETE_ON_ERROR:
.SECONDARY:
.SECONDEXPANSION:
.DEFAULT_GOAL := all
Q = $(if $(filter 1,$(V)),,@)
NAME := RageWars
VERSIONS := de eu eu-x us us-rev1
CHECK ?= rom
-include local.mk
ifneq ($(JOBS),)
ifeq ($(filter -j% --jobserver%,$(MAKEFLAGS)),)
MAKEFLAGS += -j$(JOBS)
endif
endif
ifneq ($(filter default undefined,$(origin AS)),)
AS := mips-linux-gnu-as
endif
ifneq ($(filter default undefined,$(origin CPP)),)
CPP := cpp
endif
ifneq ($(filter default undefined,$(origin LD)),)
LD := mips-linux-gnu-ld
endif
ifneq ($(filter default undefined,$(origin N64LINK)),)
N64LINK := tools/n64link/n64link
endif
ifneq ($(filter default undefined,$(origin OBJCOPY)),)
OBJCOPY := mips-linux-gnu-objcopy
endif
ifneq ($(filter default undefined,$(origin SPLAT)),)
SPLAT := splat
endif
CC_gcc_2_7_2_kmc ?= tools/gcc-2.7.2-kmc/cc1
AS_gcc_2_7_2_kmc ?= $(AS)
TOOLCHAIN_gcc_2_7_2_kmc ?= tools/gcc-2.7.2-kmc/.stamp
CC_gcc_2_8_1_sn64 ?= tools/gcc-2.8.1-sn64/cc1
AS_gcc_2_8_1_sn64 ?= $(AS)
TOOLCHAIN_gcc_2_8_1_sn64 ?= tools/gcc-2.8.1-sn64/.stamp
VMACRO_de := VERSION_DE
SHA1_de := a6daacbd0e7f77c73208cf494aefc24703060b17
ROM0_de := 0
VMACRO_eu := VERSION_EU
SHA1_eu := 46b474fac79a4b21535bb6c78ce3039a2c202359
ROM0_eu := 0
VMACRO_eu-x := VERSION_EU_X
SHA1_eu-x := 0b54615930a55675955eef8d8a22f1dfc34d2b44
ROM0_eu-x := 0
VMACRO_us := VERSION_US
SHA1_us := 9f8cb190831945f6f707aa8c2b20e04fa4276795
ROM0_us := 0
VMACRO_us-rev1 := VERSION_US_REV1
SHA1_us-rev1 := 037fb397cee2669048ed6b762a64698de4a4d88a
ROM0_us-rev1 := 0
STAMPS := tools/n64link/.stamp $(TOOLCHAIN_gcc_2_7_2_kmc) $(TOOLCHAIN_gcc_2_8_1_sn64)

# The first path word under build/ is the version: build/<version>/<source path>.o
ver = $(firstword $(subst /, ,$1))
src = $(patsubst $(call ver,$1)/%,%,$1)
DEFINES = -D$(VMACRO_$(call ver,$*))
INCLUDES = -Iinclude -I$(dir $<)
ASINC = -Iasm/$(call ver,$*)
# Every version macro for the assembler, 1 for the version built and 0 for the others: library assembly keeps the
# lines its versions disagree on in `.if VERSION_A || VERSION_B` blocks
ASDEFS = $(foreach w,$(VERSIONS),--defsym $(VMACRO_$(w))=$(if $(filter $(w),$(call ver,$*)),1,0))
TC := gcc_2_8_1_sn64
CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
ASFLAGS := -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3

# One recipe per toolchain in use; a path picks its toolchain and flags below.
define PREPROCESS_gcc_2_7_2_kmc
$(Q)$(CPP) $(CPPFLAGS) -MMD -MP -MF $(@:.i.ok=.d) -MT $@ $(DEFINES) $(INCLUDES) $< > $(@:.ok=.new)
endef
COMPILE_gcc_2_7_2_kmc = { [ ! -f $(@:.o=.s) ] || mv -f $(@:.o=.s) $(@:.o=.s.prev); } && $(CC_gcc_2_7_2_kmc) -quiet $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s) && $(if $(NOALIGN),python3 -I -c "$$STRIP_ALIGN" $(@:.o=.s) $(NOALIGN),true) && if [ -z "$(filter-out %.i.ok,$?)" ] && [ -f $@ ] && [ -f $(@:.o=.s.prev) ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && cmp -s $(@:.o=.s) $(@:.o=.s.prev); then rm -f $(@:.o=.s.prev) && touch $@ && : > $@.same; else rm -f $(@:.o=.s.prev) && $(N64LINK) asn64 --as $(AS_gcc_2_7_2_kmc) $(ASFLAGS) $(ASINC) $(@:.o=.s) -o $@; fi
define PREPROCESS_gcc_2_8_1_sn64
$(Q)$(CPP) $(CPPFLAGS) -MMD -MP -MF $(@:.i.ok=.d) -MT $@ $(DEFINES) $(INCLUDES) $< > $(@:.ok=.new)
endef
COMPILE_gcc_2_8_1_sn64 = { [ ! -f $(@:.o=.s) ] || mv -f $(@:.o=.s) $(@:.o=.s.prev); } && $(CC_gcc_2_8_1_sn64) -quiet $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s) && $(if $(NOALIGN),python3 -I -c "$$STRIP_ALIGN" $(@:.o=.s) $(NOALIGN),true) && sed -i -E 's/^([ \t]*\.word[ \t]+\.L[0-9]+)[ \t]*$$/\1-0x80000000/' $(@:.o=.s) && if [ -z "$(filter-out %.i.ok,$?)" ] && [ -f $@ ] && [ -f $(@:.o=.s.prev) ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && cmp -s $(@:.o=.s) $(@:.o=.s.prev); then rm -f $(@:.o=.s.prev) && touch $@ && : > $@.same; else rm -f $(@:.o=.s.prev) && $(N64LINK) asn64 --as $(AS_gcc_2_8_1_sn64) $(ASFLAGS) $(ASINC) $(@:.o=.s) -o $@ && $(OBJCOPY) --set-section-flags .rdata=alloc,load,readonly,data,contents $@; fi
# Per-file facts ([file] rows of config.toml): a toolchain and flags for a path or a directory.
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/802013D8.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/802013D8.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/802013D8.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_2.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_2.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_3.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200500_3.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200568_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800_3.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200800_3.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14_2.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/80200B14_2.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/MATH/80299368.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/MATH/80299368.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/MATH/80299368.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fno-thread-jumps -fno-rerun-cse-after-loop
$(foreach v,$(VERSIONS),build/$(v)/src/IO/io_hostmemory.CPP.o): TC := gcc_2_7_2_kmc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/io_hostmemory.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/IO/io_hostmemory.CPP.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1B60.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1B60.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1B60.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/PRINTF/802C1880_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/LIBGCC/802C6A00_25.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/LIBGCC/802C6A00_25.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/SDK/LIBGCC/802C6A00_25.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -ffast-math -fno-delayed-branch
# The size each object's .text has in the ROM: a compiler may pad the section past its last function, and a zero tail
# past that size is cut from the section header before the object links.
-include $(VERSIONS:%=versions/%/text_sizes.mk)
# Compare each object's last successful size with its own target-specific value during second expansion.
# A shared text_sizes.mk timestamp would rebuild every object; removed sizes must also invalidate the old trim.
text_size_changed = $(if $(filter x$(TEXTSIZE),x$(file <$@.textsize)),,text-size-changed)
.PHONY: text-size-changed
text-size-changed:
TRIM_TEXT = python3 -I -c 'import struct,sys;p,n=sys.argv[1],int(sys.argv[2],0);d=bytearray(open(p,"rb").read());o=struct.unpack_from(">I",d,32)[0];e,c,x=struct.unpack_from(">HHH",d,46);s=struct.unpack_from(">I",d,o+x*e+16)[0];t=[o+k*e for k in range(c) if d[s+struct.unpack_from(">I",d,o+k*e)[0]:].split(b"\0")[0]==b".text"];f,z=struct.unpack_from(">II",d,t[0]+16) if t else (0,0);t and z>n and not d[f+n:f+z].strip(b"\0") and (struct.pack_into(">I",d,t[0]+20,n),open(p,"wb").write(d))'

.PHONY: all check extract
all: check
ifeq ($(CHECK),tree)
check:
	$(Q)for f in Makefile $(NAME).ld include/include_asm.h $(VERSIONS:%=versions/%/splat.yaml); do test -s $$f || { echo "$$f is missing" >&2; exit 1; }; done
else ifeq ($(CHECK),rom)
check: $(VERSIONS:%=build/%/$(NAME).z64)
else
$(error CHECK must be rom or tree)
endif

# A data file holds the ROM bytes from its symbol to the next one, in the section its stand-in names: its own
# section line goes, no .align asks more than its first address has (alignment counts from the section start),
# and a .double, which the assembler would align, is written as its two words.
DATA_SED := -e '/^\.section /d' -e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8})([0-9A-F]{8}) \*/\s*)\.double .*@\1.word 0x\2, 0x\3@'
# An instruction splat marks handwritten (a 64-bit load in 32-bit code, a coprocessor move) is written as the word it
# is: the assembler would expand or re-encode it. So is a 64-bit load, store or divide with no symbol operand: under
# the 32-bit ABI the assembler expands it into several instructions; one with a %lo(symbol) operand keeps the
# relocation on the word, whose low half the link fills. A `b` is spelled as the branch its word is: an
# assembler may encode `b` as either beq or bgez. A handwritten line that carries a relocation (%hi, %lo, %gp_rel)
# keeps its symbol: as a .word the link has no operand to fill, and the %lo of a lui/addiu pair is left unpaired.
CODE_SED := -e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*)[^%]*/\* handwritten instruction \*/$$@\1.word 0x\2@' \
	-e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{4})[0-9A-F]{4} \*/\s*)(ld|sd|ldl|ldr|sdl|sdr|lld|scd)\s[^%]*%lo\(([A-Za-z0-9_.]+)\).*@\1.reloc ., R_MIPS_LO16, \4\n    .word 0x\20000@' \
	-e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*)(ld|sd|ldl|ldr|sdl|sdr|lld|scd|ddiv|ddivu)\s[^%]*$$@\1.word 0x\2@' \
	-e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} 1000[0-9A-F]{4} \*/\s*)b(\s+)@\1beq\2$$zero, $$zero, @' \
	-e 's@^(\s*/\* [0-9A-F]+ [0-9A-F]{8} 0401[0-9A-F]{4} \*/\s*)b(\s+)@\1bgez\2$$zero, @'
# An object whose data starts off an 8-byte boundary in the ROM (NOALIGN in text_sizes.mk, the start's address mod 8)
# has the alignment its compiler asks for and the start does not meet dropped from the data sections of its assembly:
# the assembler pads from the section start, so it would pad where the ROM, aligned by address, did not. Off a word
# boundary the ROM packs the data at the byte: all alignment goes and words and halves are spelled as unaligned data.
define STRIP_ALIGN
import re, sys
path, start, section, out = sys.argv[1], int(sys.argv[2]), "text", []
for line in open(path):
    found = re.match(r"\s*\.section\s+\.?(\w+)", line) or re.match(r"\s*\.(text|data|rdata|sdata|bss|rodata)\b", line)
    if found:
        section = found.group(1)
    elif section in ("data", "rdata", "rodata", "sdata"):
        asked = re.match(r"\s*\.(p2)?align\b\s*(\d*)", line)
        if asked and (start % 4 or (asked.group(2) and start % (1 << int(asked.group(2))))):
            continue
        if start % 4:
            line = re.sub(r"^(\s*)\.word\b", r"\1.4byte", re.sub(r"^(\s*)\.(half|short)\b", r"\1.2byte", line))
    out.append(line)
open(path, "w").write("".join(out))
endef
export STRIP_ALIGN
# A data piece is the ROM bytes from its address to the next row of splat.yaml: splat drops string padding, a partial
# last word and whole tiny pieces, so each extracted data file is rewritten as its ROM slice, every label kept at its
# offset (from the ROM column of the line after it).
define FILL_DATA
import os, re, sys
v = sys.argv[1]
rom = open("roms/baserom.%s.z64" % v, "rb").read()
rows = []
for line in open("versions/%s/splat.yaml" % v):
    m = re.match(r"\s+- \[0x([0-9A-Fa-f]+)(?:, (\w+), (\S+))?\]", line) or re.match(r"\s+start: 0x([0-9A-Fa-f]+)()()", line)
    if m:
        rows.append((int(m.group(1), 16), m.group(2), m.group(3)))
for (start, kind, name), (end, _, _) in zip(rows, rows[1:]):
    path = "asm/%s/data/%s.s" % (v, name)
    if kind not in ("data", "rodata") or not os.path.exists(path):
        continue
    head, labels, waiting = [], [], []
    for line in open(path):
        text = line.strip()
        m = re.match(r"(?:dlabel|glabel)\s+(\S+)", text)
        at = re.match(r"/\* ([0-9A-F]+) [0-9A-F]{8}", text)
        if m:
            waiting.append(m.group(1))
        elif text.startswith(".include"):
            head.append(text)
        elif at and waiting:
            labels += [(int(at.group(1), 16), n) for n in waiting]
            waiting = []
    labels += [(end, n) for n in waiting]
    out, here = head, start
    for offset, label in sorted(labels, key=lambda row: row[0]) + [(end, None)]:
        offset = min(max(offset, start), end)
        out += ["    .byte " + ", ".join("0x%02X" % b for b in rom[k : min(k + 16, offset)]) for k in range(here, offset, 16)]
        out += ["dlabel " + label] if label else []
        here = offset
    open(path, "w").write("\n".join(out) + "\n")
endef
export FILL_DATA
extract: $(VERSIONS:%=extract-%)
extract-%:
	$(Q)$(SPLAT) split versions/$*/splat.yaml
	$(Q)find asm/$* \( -name '*.data.s' -o -name '*.rodata.s' \) | while read f; do \
		case $$(grep -m1 -oE '^ */\* [0-9A-F]+ [0-9A-F]{8}' "$$f" | tail -c 2) in \
		0*) c='';; 8*) c='s/^\.align [4-9]/.align 3/';; [4C]*) c='s/^\.align [3-9]/.align 2/';; \
		[26AE]*) c='s/^\.align [2-9]/.align 1/';; *) c='s/^\.align [1-9]/.align 0/';; esac; \
		sed -E $(DATA_SED) -e "$$c" "$$f" > "$${f%.*.s}.s" && rm "$$f"; done
	$(Q)python3 -I -c "$$FILL_DATA" $*
	$(Q)find asm/$*/nonmatchings -name '*.s' -exec sed -i -E $(CODE_SED) {} +
	$(Q)touch asm/$*/.extracted
# An object assembles extracted files its source only names through a macro: every object follows the extraction.
asm/%/.extracted: | roms/baserom.%.z64
	+$(Q)$(MAKE) --no-print-directory extract-$*

# The link script names every object, so no rule here lists a file.
$(foreach v,$(VERSIONS),$(eval OBJS_$(v) := $(addprefix build/$(v)/,$(shell $(CPP) -P -undef -D$(VMACRO_$(v)) $(NAME).ld 2>/dev/null | grep -oE '[[:alnum:]_./+-]+[.]o' | sort -u))))
-include $(foreach v,$(VERSIONS),$(OBJS_$(v):.o=.d))

# An object follows the text its source preprocesses to, not the time its headers were written: the .i is replaced only
# when its bytes change, so a header edit that leaves a source's text alone (a comment, a part another version reads)
# preprocesses that source again and compiles nothing. The stamp (.i.ok) carries the header times; the object compiles
# when its .i is newer than it or another input (the extraction, the text size) changed, else it is only touched.
build/%.i.ok: $$(call src,$$*) | $(STAMPS)
	$(Q)mkdir -p $(@D)
	$(PREPROCESS_$(TC))
	$(Q)if cmp -s $(@:.ok=.new) $(@:.ok=); then rm -f $(@:.ok=.new); else mv -f $(@:.ok=.new) $(@:.ok=); fi
	$(Q)touch $@
build/%.o: build/%.i.ok asm/$$(call ver,$$*)/.extracted $$(text_size_changed) | $(STAMPS)
	$(Q)if [ -z "$(filter-out %.i.ok,$?)" ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && [ -f $@ ] && \
	[ $(@:.o=.i) -ot $@ ]; then touch $@; \
	else $(COMPILE_$(TC)) && if [ -f $@.same ]; then rm -f $@.same; else $(if $(TEXTSIZE),$(TRIM_TEXT) $@ $(TEXTSIZE),true) && \
	printf '%s\n' '$(TEXTSIZE)' > $@.textsize; fi; fi
build/%.s.o: $$(call src,$$*).s $$(text_size_changed) | $(STAMPS)
	$(Q)mkdir -p $(@D)
	$(Q)$(AS) $(ASFLAGS) $(ASDEFS) $(ASINC) -Iinclude $< -o $@
	$(Q)$(if $(TEXTSIZE),$(TRIM_TEXT) $@ $(TEXTSIZE))
	$(Q)printf '%s\n' '$(TEXTSIZE)' > $@.textsize
build/%.bin.o: asm/%.bin
	$(Q)mkdir -p $(@D)
	$(Q)$(OBJCOPY) -I binary -O elf32-tradbigmips -B mips $< $@
# splat writes a binary piece while it extracts the version.
asm/%.bin: | asm/$$(call ver,$$*)/.extracted
	$(Q)test -f $@ || { echo "$@ is missing: run make extract-$(call ver,$*)" >&2; exit 1; }

# The whole ROM links once per version, from build/<version>/, so object paths in the script stay short.
build/%/link.ld: $(NAME).ld
	$(Q)mkdir -p $(@D)
	$(Q)$(CPP) -P -undef -D$(VMACRO_$*) $< > $@
# Every fact of symbol_addrs.txt and aliases.txt and every name splat left undefined, PROVIDEd: what no object defines (data outside
# the ROM). So is every name splat made up that the extracted assembly spells, at the address the name carries: a .L
# label the assembler keeps out of the object, or a label inside bytes a C file compiles.
build/%/undefined_syms.ld: versions/%/symbol_addrs.txt build/%/undefined_syms_auto.txt build/%/undefined_funcs_auto.txt asm/%/.extracted $$(wildcard versions/$$*/aliases.txt)
	$(Q)sed -nE 's/^([A-Za-z_.][A-Za-z0-9_.$$]*)[[:space:]]*=[[:space:]]*(0x[0-9A-Fa-f]+);.*/PROVIDE(\1 = \2);/p' $^ > $@
	$(Q)grep -rhoE --include='*.s' '[A-Za-z_.]*auto_[0-9A-F]{8}\b' asm/$* | sort -u | sed -E 's/^([A-Za-z_.]*auto_(.*))$$/PROVIDE(\1 = 0x\2);/' >> $@
# splat writes these while it extracts the version.
build/%/undefined_syms_auto.txt build/%/undefined_funcs_auto.txt: | asm/%/.extracted
	$(Q)test -f $@ || { echo "$@ is missing: run make extract-$*" >&2; exit 1; }
build/%/$(NAME).elf: $$(OBJS_$$*) build/%/link.ld build/%/undefined_syms.ld
	$(Q)cd build/$* && $(LD) -T link.ld -o $(NAME).elf
build/%/$(NAME).bin: build/%/$(NAME).elf
	$(Q)$(OBJCOPY) -O binary --gap-fill 0 $< $@
build/%/$(NAME).z64: build/%/$(NAME).bin roms/baserom.%.z64
	$(Q){ head -c $(ROM0_$*) roms/baserom.$*.z64; cat $<; } > $@
	$(Q)truncate -s $$(wc -c < roms/baserom.$*.z64) $@
	$(Q)test "$$(sha1sum < $@ | cut -d' ' -f1)" = $(SHA1_$*) || { echo "$@: SHA-1 is not $(SHA1_$*)" >&2; exit 1; }

tools/n64link/.stamp:
	$(Q)mkdir -p tools/n64link && curl -fsSL https://github.com/AbuN64/mas-n64/releases/download/v0.2.0/n64link-v0.2.0-linux-x86_64.tar.gz -o tools/n64link.tar.gz && echo '061d7bc69f21228c7029f4f530cd980bab3a35749751a43f2823d03d95be4ef7  tools/n64link.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/n64link.tar.gz -C tools/n64link --strip-components=1 n64link-v0.2.0-linux-x86_64/n64link && rm -f tools/n64link.tar.gz && cd tools/n64link && printf '%s\n' '583e544840d04123fa7e26c7416316ffe410139351e07cd3395d4bd5ec609c3c  n64link' | sha256sum -c - >/dev/null && touch .stamp

tools/gcc-2.7.2-kmc/.stamp:
	$(Q)mkdir -p tools/gcc-2.7.2-kmc && curl -fsSL https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz -o tools/gcc-2.7.2-kmc.tar.gz && echo 'ff3e299c1d952c0a5cb39f7790a208d0c547cf93986eb5607f820c935cedc288  tools/gcc-2.7.2-kmc.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/gcc-2.7.2-kmc.tar.gz -C tools/gcc-2.7.2-kmc cc1 && rm -f tools/gcc-2.7.2-kmc.tar.gz && cd tools/gcc-2.7.2-kmc && printf '%s\n' 'c4976e94ebf81d0ab1336f631fb752fbe6e0e0810e90a24da11e6ed1d5223b8a  cc1' | sha256sum -c - >/dev/null && touch .stamp

tools/gcc-2.8.1-sn64/.stamp:
	$(Q)mkdir -p tools/gcc-2.8.1-sn64 && curl -fsSL https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz -o tools/gcc-2.8.1-sn64.tar.gz && echo '1156cf0d6a88a64c20e2a10fc9445d99cb9a38518f432b1669528dfa82ebb45f  tools/gcc-2.8.1-sn64.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/gcc-2.8.1-sn64.tar.gz -C tools/gcc-2.8.1-sn64 cc1 && rm -f tools/gcc-2.8.1-sn64.tar.gz && cd tools/gcc-2.8.1-sn64 && printf '%s\n' 'd1ddfe21dfa61840a83f833c8bd45ed7e2f606c3d9c351d2ec732fb6e4f97c89  cc1' | sha256sum -c - >/dev/null && touch .stamp

