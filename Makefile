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
ifeq ($(NON_MATCHING),1)
.DEFAULT_GOAL := nm
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
CC_gcc_2_7_2_sn64 ?= tools/gcc-2.7.2-sn64/cc1
AS_gcc_2_7_2_sn64 ?= $(AS)
TOOLCHAIN_gcc_2_7_2_sn64 ?= tools/gcc-2.7.2-sn64/.stamp
CC_gcc_2_8_1_sn64 ?= tools/gcc-2.8.1-sn64/cc1
AS_gcc_2_8_1_sn64 ?= $(AS)
TOOLCHAIN_gcc_2_8_1_sn64 ?= tools/gcc-2.8.1-sn64/.stamp
VMACRO_de := VERSION_DE
SHA1_de := a6daacbd0e7f77c73208cf494aefc24703060b17
ROM0_de := 0
ROM_SECTIONS_de :=
VMACRO_eu := VERSION_EU
SHA1_eu := 46b474fac79a4b21535bb6c78ce3039a2c202359
ROM0_eu := 0
ROM_SECTIONS_eu :=
VMACRO_eu-x := VERSION_EU_X
SHA1_eu-x := 0b54615930a55675955eef8d8a22f1dfc34d2b44
ROM0_eu-x := 0
ROM_SECTIONS_eu-x :=
VMACRO_us := VERSION_US
SHA1_us := 9f8cb190831945f6f707aa8c2b20e04fa4276795
ROM0_us := 0
ROM_SECTIONS_us :=
VMACRO_us-rev1 := VERSION_US_REV1
SHA1_us-rev1 := 037fb397cee2669048ed6b762a64698de4a4d88a
ROM0_us-rev1 := 0
ROM_SECTIONS_us-rev1 :=
STAMPS := tools/n64link/.stamp $(TOOLCHAIN_gcc_2_7_2_sn64) $(TOOLCHAIN_gcc_2_8_1_sn64)

# The first path word under build/ is the version: build/<version>/<source path>.o
ver = $(firstword $(filter-out nm nmraw,$(subst /, ,$1)))
src = $(patsubst $(call ver,$1)/%,%,$(patsubst nmraw/%,%,$(patsubst nm/%,%,$1)))
DEFINES = -D$(VMACRO_$(call ver,$*)) $(if $(filter nmraw/%,$*),-DNON_MATCHING)
INCLUDES = -Iinclude -I$(dir $<)
ASINC = -Iasm/$(call ver,$*)
# Every version macro for the assembler, 1 for the version built and 0 for the others: library assembly keeps the
# lines its versions disagree on in `.if VERSION_A || VERSION_B` blocks
ASDEFS = $(foreach w,$(VERSIONS),--defsym $(VMACRO_$(w))=$(if $(filter $(w),$(call ver,$*)),1,0))
TC := gcc_2_8_1_sn64
CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
ASFLAGS := -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3

# One recipe per toolchain in use; a path picks its toolchain and flags below.
define PREPROCESS_gcc_2_7_2_sn64
$(Q)$(CPP) $(CPPFLAGS) -MMD -MP -MF $(@:.i.ok=.d) -MT $@ $(DEFINES) $(INCLUDES) $< > $(@:.ok=.new)
endef
COMPILE_gcc_2_7_2_sn64 = if [ -f $(@:.o=.s.prev) ]; then rm -f $(@:.o=.s); elif [ -f $(@:.o=.s) ]; then mv -f $(@:.o=.s) $(@:.o=.s.prev); fi && $(CC_gcc_2_7_2_sn64) -quiet $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s) && test -s $(@:.o=.s) && $(if $(NOALIGN),python3 -I -c "$$STRIP_ALIGN" $(@:.o=.s) $(NOALIGN),true) && $(if $(HILO),python3 -I -c "$$HILO_HAZARD" $(@:.o=.s),true) && sed -i -E 's/^([ \t]*\.word[ \t]+[.$$]L[0-9]+)[ \t]*$$/\1-0x80000000/' $(@:.o=.s) && if [ -z "$(filter-out %.i.ok,$?)$(flags_changed)" ] && [ -f $@ ] && [ -f $(@:.o=.s.prev) ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && cmp -s $(@:.o=.s) $(@:.o=.s.prev); then rm -f $(@:.o=.s.prev) && touch $@ && : > $@.same; else rm -f $(@:.o=.s.prev) && $(N64LINK) asn64 --as $(AS_gcc_2_7_2_sn64) $(ASFLAGS) $(ASINC) $(@:.o=.s) -o $@; fi
define PREPROCESS_gcc_2_8_1_sn64
$(Q)$(CPP) $(CPPFLAGS) -MMD -MP -MF $(@:.i.ok=.d) -MT $@ $(DEFINES) $(INCLUDES) $< > $(@:.ok=.new)
endef
COMPILE_gcc_2_8_1_sn64 = if [ -f $(@:.o=.s.prev) ]; then rm -f $(@:.o=.s); elif [ -f $(@:.o=.s) ]; then mv -f $(@:.o=.s) $(@:.o=.s.prev); fi && $(CC_gcc_2_8_1_sn64) -quiet $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s) && test -s $(@:.o=.s) && $(if $(NOALIGN),python3 -I -c "$$STRIP_ALIGN" $(@:.o=.s) $(NOALIGN),true) && $(if $(HILO),python3 -I -c "$$HILO_HAZARD" $(@:.o=.s),true) && sed -i -E 's/^([ \t]*\.word[ \t]+[.$$]L[0-9]+)[ \t]*$$/\1-0x80000000/' $(@:.o=.s) && if [ -z "$(filter-out %.i.ok,$?)$(flags_changed)" ] && [ -f $@ ] && [ -f $(@:.o=.s.prev) ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && cmp -s $(@:.o=.s) $(@:.o=.s.prev); then rm -f $(@:.o=.s.prev) && touch $@ && : > $@.same; else rm -f $(@:.o=.s.prev) && $(N64LINK) asn64 --as $(AS_gcc_2_8_1_sn64) $(ASFLAGS) $(ASINC) $(@:.o=.s) -o $@ && $(OBJCOPY) --set-section-flags .rdata=alloc,load,readonly,data,contents $@; fi
# Per-file facts ([file] rows of config.toml): a toolchain and flags for a path or a directory.
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/rnc/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/rnc/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/rnc/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/%.o): TC := gcc_2_7_2_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/%.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2 -fno-exceptions
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/game/MATH/80299368.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/game/MATH/80299368.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/game/MATH/80299368.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fno-thread-jumps -fno-rerun-cse-after-loop
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200568_3.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200568_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200568_3.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/80200800_4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/802022E0_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/802022E0_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libsn/802022E0_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/env.c.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/env.c.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/env.c.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -ffast-math -fno-delayed-branch
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/rnc/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/rnc/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/rnc/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/%.o): TC := gcc_2_7_2_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/%.o): CFLAGS := -G0 -mips3 -mgp32 -mfp32 -O2 -fno-exceptions
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/%.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/%.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/%.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/game/MATH/80299368.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/game/MATH/80299368.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/game/MATH/80299368.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fno-thread-jumps -fno-rerun-cse-after-loop
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200568_3.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200568_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200568_3.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/80200800_4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/802022E0_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/802022E0_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libsn/802022E0_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/env.c.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/env.c.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/env.c.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libgcc/802C6A00_25.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/lib_802BB630/802BC380.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -ffast-math -fno-delayed-branch
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1B60.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5320.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C5914.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): HILO := 1
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/pfs/80447BB0_9.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_3.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C3EA4_4.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -fforce-addr
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
# The R4000 reads HI/LO late: an mfhi/mflo needs two instructions before the next mult/div/mthi/mtlo. The assembler the
# ROMs were made with wrote two nops where the compiler placed the two back to back (gas lays the gap itself only when
# one instruction is already between, so here they stay adjacent). A toolchain row's hilo_hazard_nops puts those two
# nops into the compiler's assembly, only in `.set reorder` text, where the assembler owns the slots.
define HILO_HAZARD
import re, sys
path, out, last, reorder = sys.argv[1], [], None, True
for line in open(path):
    text = line.split("#", 1)[0].strip()
    if text.startswith(".set"):
        if re.match(r"\.set\s+noreorder\b", text):
            reorder = False
        elif re.match(r"\.set\s+reorder\b", text):
            reorder = True
    elif text and not text.startswith(".") and not re.match(r"[\w.\x24]+:", text):
        word = text.split(None, 1)[0]
        if word in ("mult", "multu", "dmult", "dmultu", "div", "divu", "ddiv", "ddivu", "mthi", "mtlo"):
            if reorder and last == 0 and (len(text.split(",")) < 3 or word.startswith("m")):
                out.append("\tnop\n\tnop\n")
        last = 0 if word in ("mfhi", "mflo") else (None if last is None else last + 1)
    out.append(line)
open(path, "w").write("".join(out))
endef
export HILO_HAZARD
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
# splat writes every extracted file again, so each new date would remake every object of the version (through the
# extraction stamp and the files a source names) although nothing changed. A file whose bytes are the same gets its old
# date back. A changed or added file reaches exactly the objects whose lines name it (build/asm.deps), so the stamp
# keeps its date unless the shared asm/<v>/include changed; an object that named a file the extraction no longer
# makes (asm.deps as make read it before the extraction) is dated long ago, so make compiles it and says what it lacks.
define KEEP_DATES
import hashlib, json, os, sys
mode, version = sys.argv[1], sys.argv[2]
root, keep = "asm/" + version, "build/.extract-dates-" + version + ".json"
stamp = root + "/.extracted"
def scan():
    found = {}
    for here, _, names in os.walk(root):
        for name in names:
            path = os.path.join(here, name)
            if path != stamp:
                with open(path, "rb") as data:
                    found[path] = hashlib.sha1(data.read()).hexdigest()
    return found
if mode == "save":
    os.makedirs("build", exist_ok=True)
    files = {path: [digest, os.stat(path).st_mtime_ns] for path, digest in scan().items()}
    when = os.stat(stamp).st_mtime_ns if os.path.exists(stamp) else None
    with open(keep, "w") as out:
        json.dump({"files": files, "stamp": when}, out)
else:
    with open(keep) as saved:
        old = json.load(saved)
    files = scan()
    for path, digest in files.items():
        if old["files"].get(path, [None])[0] == digest:
            os.utime(path, ns=(old["files"][path][1], old["files"][path][1]))
    moved = set(files) ^ set(old["files"]) | {path for path in files if old["files"].get(path, [None])[0] != files[path]}
    if old["stamp"] is not None and not any(path.startswith(root + "/include/") for path in moved):
        os.utime(stamp, ns=(old["stamp"], old["stamp"]))
    gone = set(old["files"]) - set(files)
    if gone and os.path.exists("build/asm.deps"):
        for line in open("build/asm.deps"):
            target, _, named = line.partition(": ")
            if gone.intersection(named.split()) and os.path.exists(target):
                os.utime(target, ns=(1000000000, 1000000000))
    os.remove(keep)
endef
export KEEP_DATES
# One extraction per input: a version whose baserom, splat.yaml, symbol_addrs.txt, splat and extract recipe are those of its last
# extraction (build/.extract-key-<v>) is not split again, so a build or probe extracts only a version whose inputs it changed.
# `make extract-force-<v>` (or removing asm/<v>/.extracted) splits regardless. One recipe, no sub-make (parallel sub-makes raced
# on remaking the included files). Bump rev1 when the recipe changes.
export EXTRACT_RECIPE := rev1 $(DATA_SED) $(CODE_SED)
EXTRACT_KEY = { cat roms/baserom.$*.z64 versions/$*/splat.yaml versions/$*/symbol_addrs.txt; $(SPLAT) --version 2>&1; printf %s "$$EXTRACT_RECIPE"; } | sha1sum | cut -d" " -f1
# asm/<v>/.extracted has only the ROM as prerequisite: a rebase that changed symbol_addrs.txt or splat.yaml left stale asm. A version whose
# two files differ from build/.extract-src-<v> (or have no record) gets the phony extract-stale: the full key is checked once, then recorded.
SRC_KEY = cat versions/$*/splat.yaml versions/$*/symbol_addrs.txt 2>/dev/null | sha1sum | cut -d" " -f1
.PHONY: extract-stale
$(foreach v,$(VERSIONS),$(if $(wildcard build/.extract-key-$(v)),$(if $(filter $(shell cat versions/$(v)/splat.yaml versions/$(v)/symbol_addrs.txt 2>/dev/null | sha1sum | cut -d" " -f1),$(shell cat build/.extract-src-$(v) 2>/dev/null)),,$(eval asm/$(v)/.extracted: extract-stale))))
extract: $(VERSIONS:%=extract-%)
extract-force-%:
	$(Q)rm -f build/.extract-key-$* && $(MAKE) --no-print-directory extract-$*
# Records the inputs asm/<v>/ holds the extraction of (the tool that extracts runs it too).
extract-stamp-%:
	$(Q)mkdir -p build && { $(EXTRACT_KEY); } > build/.extract-key-$* && { $(SRC_KEY); } > build/.extract-src-$*
extract-%:
	$(Q)mkdir -p build; flock build/.extract-lock-$* $(MAKE) --no-print-directory extract-do-$*
extract-do-%:
	$(Q)mkdir -p build; if test -f asm/$*/.extracted && test "$$($(EXTRACT_KEY))" = "$$(cat build/.extract-key-$* 2>/dev/null)"; then rm -f build/.extract-run-$*; echo "extract-$*: inputs unchanged, not split again (make extract-force-$* splits)"; { $(SRC_KEY); } > build/.extract-src-$*; else touch build/.extract-run-$*; fi
	$(Q)test -e build/.extract-run-$* || exit 0; python3 -I -c "$$KEEP_DATES" save $*
	$(Q)test -e build/.extract-run-$* || exit 0; $(SPLAT) split versions/$*/splat.yaml
	$(Q)test -e build/.extract-run-$* || exit 0; find asm/$* \( -name '*.data.s' -o -name '*.rodata.s' \) | while read f; do \
		case $$(grep -m1 -oE '^ */\* [0-9A-F]+ [0-9A-F]{8}' "$$f" | tail -c 2) in \
		0*) c='';; 8*) c='s/^\.align [4-9]/.align 3/';; [4C]*) c='s/^\.align [3-9]/.align 2/';; \
		[26AE]*) c='s/^\.align [2-9]/.align 1/';; *) c='s/^\.align [1-9]/.align 0/';; esac; \
		sed -E $(DATA_SED) -e "$$c" "$$f" > "$${f%.*.s}.s" && rm "$$f"; done
	$(Q)test -e build/.extract-run-$* || exit 0; python3 -I -c "$$FILL_DATA" $*
	$(Q)test -e build/.extract-run-$* || exit 0; find asm/$*/nonmatchings -name '*.s' -exec sed -i -E $(CODE_SED) {} +
	$(Q)test -e build/.extract-run-$* || exit 0; touch asm/$*/.extracted
	$(Q)test -e build/.extract-run-$* || exit 0; python3 -I -c "$$KEEP_DATES" restore $*
	$(Q)test -e build/.extract-run-$* || exit 0; { $(EXTRACT_KEY); } > build/.extract-key-$* && { $(SRC_KEY); } > build/.extract-src-$* && rm -f build/.extract-run-$*
# An object assembles extracted files its source only names through a macro: every object follows the extraction.
asm/%/.extracted: | roms/baserom.%.z64
	+$(Q)$(MAKE) --no-print-directory extract-$*

# Both scripts run before make reads a directory of build/: make keeps the listing it first read, so a stamp the sweep
# removes later would still look present.
# The compiler's assembly for a unit holds only an `.include` line for each extracted file its INCLUDE_ASM, INCLUDE_RODATA
# and INCLUDE_DATA lines name: the assembler reads the file's content, so an edit in place (a symbol renamed by hand or
# by a tool, with the .i unchanged and the compile answered by the cache) is an input of the object that no other rule
# lists, and the object would keep the old symbols until it is deleted. Every source's object so depends on the files
# of each version that its lines name and that exist (a line another version does not extract adds nothing).
define ASM_DEPS
import os, re, sys
named = re.compile(rb'INCLUDE_(ASM|RODATA|DATA)\(\s*"(\w+)"\s*,\s*(\w+)\s*[,)]')
for here, _, names in sorted(os.walk("src")):
    for name in sorted(names):
        path = os.path.join(here, name)
        with open(path, "rb") as source:
            found = sorted(set(named.findall(source.read())))
        for version in sys.argv[1:]:
            files = []
            for kind, segment, symbol in found:
                folder = "nonmatchings" if kind == b"ASM" else "data"
                asm = "asm/%s/%s/%s/%s.s" % (version, folder, segment.decode(), symbol.decode())
                if os.path.exists(asm):
                    files.append(asm)
            if files:
                print("build/%s/%s.o: %s" % (version, path, " ".join(files)))
endef
$(shell mkdir -p build)
$(file >build/asm-deps.py,$(ASM_DEPS))
$(shell python3 -I build/asm-deps.py $(VERSIONS) >build/asm.deps)
-include build/asm.deps

# Make trusts file dates, and a date can lie: a tree copied, rebased or fast-forwarded gives a stamp that is newer than the
# inputs it was made from. STAMP_SWEEP runs before make reads any date. For each .i.ok stamp it hashes the inputs the
# preprocess read (the source and every header in its .d); for each object it hashes the extracted files the
# object assembles (its .i is dated by the preprocess rule, which writes it only when its bytes change) (asm.deps). The hashes seen at the last sweep are kept beside the stamp's date (build/.inputs.json).
# A stamp whose date did not move but whose inputs' bytes did was made from other bytes: it is dated long ago (make
# skips a missing stamp when the object is newer than the source), so make makes it again, and an object is removed. A stamp that was rebuilt since (its date moved) records the bytes it now has.
define STAMP_SWEEP
import hashlib, json, os, sys
state_path = "build/.inputs.json"
seen = {}
def digest(path):
    if path not in seen:
        try:
            with open(path, "rb") as handle:
                seen[path] = hashlib.sha1(handle.read()).hexdigest()
        except OSError:
            seen[path] = "-"
    return seen[path]
def dependencies(dfile):
    try:
        text = open(dfile).read()
    except OSError:
        return None
    names = []
    for line in text.replace(chr(92) + chr(10), " ").splitlines():
        target, colon, named = line.partition(": ")
        if colon and named.strip():
            names += named.split()
    return names
def stamp_key(stamp):
    deps = dependencies(stamp[: -len(".i.ok")] + ".d")
    return None if deps is None else hashlib.sha1(" ".join(digest(d) for d in deps).encode()).hexdigest()
def object_key(obj, extracted):
    return hashlib.sha1(" ".join(digest(a) for a in sorted(set(extracted))).encode()).hexdigest()
log_path = "build/.inputs.log"
def replay(state, path):
    try:
        with open(path) as handle:
            for line in handle:
                try:
                    name, when, key = json.loads(line)
                except ValueError:
                    continue
                state[name] = [when, key]
    except OSError:
        pass
def load():
    try:
        with open(state_path) as handle:
            state = json.load(handle)
    except (OSError, ValueError):
        state = {}
    replay(state, log_path)
    return state
def save(state):
    os.makedirs("build", exist_ok=True)
    tmp = state_path + "." + str(os.getpid())
    with open(tmp, "w") as handle:
        json.dump(state, handle)
    os.replace(tmp, state_path)
if sys.argv[1] == "record":
    path, key = sys.argv[2], None
    key = stamp_key(path) if path.endswith(".i.ok") else object_key(path, sys.argv[3:])
    if key is not None:
        line = (json.dumps([path, os.stat(path).st_mtime_ns, key]) + chr(10)).encode()
        fd = os.open(log_path, os.O_WRONLY | os.O_APPEND | os.O_CREAT, 0o644)
        try:
            os.write(fd, line)
        finally:
            os.close(fd)
    sys.exit(0)
pending = log_path + "." + str(os.getpid())
try:
    os.replace(log_path, pending)
except OSError:
    pending = None
state = load()
if pending:
    replay(state, pending)
asm = {}
if os.path.exists("build/asm.deps"):
    for line in open("build/asm.deps"):
        target, _, named = line.partition(": ")
        asm[target] = named.split()
removed = 0
def check(path, key):
    global removed
    if key is None:
        return
    try:
        when = os.stat(path).st_mtime_ns
    except OSError:
        state.pop(path, None)
        return
    old = state.get(path)
    if old and old[0] == when and old[1] != key:
        if path.endswith(".o"):
            os.unlink(path)
        else:
            os.utime(path, ns=(1000000000, 1000000000))
        state.pop(path, None)
        removed += 1
    else:
        state[path] = [when, key]
versions = set(sys.argv[2:])
def twin(obj):
    parts = obj.split("/")
    return obj if parts[1] in versions else "/".join(parts[:1] + parts[2:])
for here, _, names in os.walk("build"):
    for name in names:
        if name.endswith(".i.ok"):
            stamp = os.path.join(here, name)
            check(stamp, stamp_key(stamp))
            obj = stamp[: -len(".i.ok")] + ".o"
            check(obj, object_key(obj, asm.get(twin(obj), [])))
save(state)
if pending:
    os.unlink(pending)
if removed:
    sys.stderr.write("stamp sweep: %d outputs made from other bytes than their inputs now hold were dropped\n" % removed)
endef
$(file >build/stamp-sweep.py,$(STAMP_SWEEP))
$(shell python3 -I build/stamp-sweep.py sweep $(VERSIONS) >&2)
# The link script names every object, so no rule here lists a file.
$(foreach v,$(VERSIONS),$(eval OBJS_$(v) := $(addprefix build/$(v)/,$(shell $(CPP) -P -undef -D$(VMACRO_$(v)) $(NAME).ld 2>/dev/null | grep -oE '[[:alnum:]_./+-]+[.]o' | sort -u))))
-include $(foreach v,$(VERSIONS),$(OBJS_$(v):.o=.d))


# An object follows the text its source preprocesses to, not the time its headers were written: the .i is replaced only
# when its bytes change, so a header edit that leaves a source's text alone (a comment, a part another version reads)
# preprocesses that source again and compiles nothing. The stamp (.i.ok) carries the header times; the object compiles
# when its .i is newer than it or another input (the extraction, the text size) changed, else it is only touched.
# A flags row (TC, CPPFLAGS, CFLAGS of a [file] row, the toolchain's compiler) that changes remakes the objects it
# reaches: each object keeps the flags it was made with beside it (`.flags` for the compile, `.i.ok.flags` for the
# preprocess) and, when its own flags differ, make sees one more prerequisite that is out of date. A stamp a build never
# wrote (an object made before the stamps) is trusted, so the first run after an upgrade rebuilds nothing.
# The compile key of a unit (tools: hdrkey, below). The .i is kept, and the object with it, when the key of the new
# preprocess equals the key of the one the object was made from: the key leaves out every top-level declaration (extern,
# prototype, typedef, struct/union/enum definition) the unit never names, so a header edit that adds or changes a
# declaration this unit does not use compiles nothing. Without a C compiler the .i is compared byte for byte.
HOSTCC ?= cc
HDRKEY := build/hdrkey
define HDRKEY_C
/* hdrkey: the compile key of a preprocessed C unit (cpp -P output).
 *
 * Prints the unit with every top-level declaration it never references left out: extern variables, prototypes,
 * typedefs and struct/union/enum definitions whose names are not used, transitively, by what is kept. Function
 * and variable definitions, pragmas and anything not understood are always kept, in their order. The text is
 * compilable C (whitespace collapsed to one space where the source had any), so cc1 gives the same object for
 * it as for the full unit; two units with equal keys compile to the same object.
 * Anything this parser does not understand makes the key the whole file ("RAW" and its bytes): a key may be
 * less reduced, never wrong.
 *
 *   hdrkey FILE            key to stdout
 *   hdrkey --stats FILE    key to stdout, one line "items kept dropped" to stderr
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { T_ID, T_NUM, T_STR, T_PRAG, T_PUNCT };
typedef struct { int off, len, kind, id, sp; } Tok;
typedef struct { int a, b, root, kept, d0, nd; } Item;

static char *src; static long srclen;
static Tok *tk; static int ntk, ctk;
static Item *it; static int nit, cit;
static int *defs; static int ndefs, cdefs;
static int fallback;

/* identifier table: open addressing; kw[] marks C keywords, td[] typedef names */
typedef struct { int off, len, kw, td; } Name;
static Name *nm; static int nnm, cnm; static int *tab; static int tabn;

static const char *KW[] = {"auto","break","case","char","const","continue","default","do","double","else","enum",
 "extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct",
 "switch","typedef","union","unsigned","void","volatile","while","inline","__inline","__inline__","__volatile__",
 "__const","__const__","__signed__","asm","__asm","__asm__","__attribute__","__attribute","__extension__",
 "__typeof__","typeof","restrict","__restrict","_Bool",0};

static unsigned hash(const char *s, int n) { unsigned h = 2166136261u; while (n--) h = (h ^ (unsigned char)*s++) * 16777619u; return h; }
static int intern(const char *s, int n) {
    unsigned h = hash(s, n) & (tabn - 1);
    while (tab[h] >= 0) {
        Name *x = &nm[tab[h]];
        if (x->len == n && !memcmp(src + x->off, s, n)) return tab[h];
        h = (h + 1) & (tabn - 1);
    }
    if (nnm == cnm) { cnm = cnm ? cnm * 2 : 1024; nm = realloc(nm, cnm * sizeof *nm); }
    nm[nnm].off = s - src; nm[nnm].len = n; nm[nnm].kw = 0; nm[nnm].td = 0;
    tab[h] = nnm;
    return nnm++;
}

static int dbg;
static void badat(int line, int tokidx) { if (!fallback && dbg) { fprintf(stderr, "RAW at hdrkey.c:%d token %d\n", line, tokidx); if (tokidx > 0 && tokidx < ntk) { int o = tk[tokidx].off; fprintf(stderr, "%.*s\n", 200, src + (o > 100 ? o - 100 : 0)); } } fallback = 1; }
#define bad() badat(__LINE__, i)

static int isid0(int c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == 36; }
static int isid(int c) { return isid0(c) || (c >= '0' && c <= '9'); }
static int isdig(int c) { return c >= '0' && c <= '9'; }

static void addtok(int off, int len, int kind, int id, int sp) {
    if (ntk == ctk) { ctk = ctk ? ctk * 2 : 4096; tk = realloc(tk, ctk * sizeof *tk); }
    tk[ntk].off = off; tk[ntk].len = len; tk[ntk].kind = kind; tk[ntk].id = id; tk[ntk].sp = sp; ntk++;
}

static void lex(void) {
    long i = 0; int sp = 0, bol = 1;
    while (i < srclen) {
        int c = (unsigned char)src[i];
        if (c == '\n') { bol = 1; sp = 1; i++; continue; }
        if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v') { sp = 1; i++; continue; }
        if (c == '#' && bol) {               /* a directive left by cpp -P (pragma, ident): kept verbatim */
            long j = i;
            while (j < srclen && src[j] != '\n') { if (src[j] == '\\' && j + 1 < srclen) j++; j++; }
            addtok(i, j - i, T_PRAG, -1, sp); i = j; sp = 1; continue;
        }
        bol = 0;
        if (isid0(c)) {
            long j = i + 1; while (j < srclen && isid((unsigned char)src[j])) j++;
            addtok(i, j - i, T_ID, intern(src + i, j - i), sp); i = j; sp = 0; continue;
        }
        if (isdig(c) || (c == '.' && i + 1 < srclen && isdig((unsigned char)src[i + 1]))) {
            long j = i + 1;
            while (j < srclen) {
                int d = (unsigned char)src[j];
                if ((d == '+' || d == '-') && (src[j-1]=='e'||src[j-1]=='E'||src[j-1]=='p'||src[j-1]=='P')) { j++; continue; }
                if (isid(d) || d == '.') { j++; continue; }
                break;
            }
            addtok(i, j - i, T_NUM, -1, sp); i = j; sp = 0; continue;
        }
        if (c == '"' || c == '\'') {
            long j = i + 1;
            while (j < srclen && src[j] != c) { if (src[j] == '\\') j++; if (j < srclen && src[j] == '\n') { bad(); break; } j++; }
            if (j >= srclen) { bad(); return; }
            addtok(i, j + 1 - i, T_STR, -1, sp); i = j + 1; sp = 0; continue;
        }
        addtok(i, 1, T_PUNCT, -1, sp); i++; sp = 0;
    }
}

static int is_p(int i, char c) { return i >= 0 && i < ntk && tk[i].kind == T_PUNCT && src[tk[i].off] == c; }
static int is_id(int i) { return i >= 0 && i < ntk && tk[i].kind == T_ID; }
static int is_kw(int i, const char *w) {
    return is_id(i) && tk[i].len == (int)strlen(w) && !memcmp(src + tk[i].off, w, tk[i].len);
}
static int iskwid(int i) { return is_id(i) && nm[tk[i].id].kw; }

/* index of the token after the group opened at i (( [ {), or -1 when unbalanced */
static int skip_group(int i) {
    int d = 0;
    for (; i < ntk; i++) {
        if (tk[i].kind != T_PUNCT) continue;
        char c = src[tk[i].off];
        if (c == '(' || c == '[' || c == '{') d++;
        else if (c == ')' || c == ']' || c == '}') { if (--d == 0) return i + 1; if (d < 0) return -1; }
    }
    return -1;
}

static void adddef(int id) {
    if (ndefs == cdefs) { cdefs = cdefs ? cdefs * 2 : 4096; defs = realloc(defs, cdefs * sizeof *defs); }
    defs[ndefs++] = id;
}

/* Split [a,b) into declarators at depth-0 commas and collect names. Returns 0 when it cannot say what is
 * declared (the item is then kept). *allfn is set to 1 when every declarator is a function declarator. */
static int declare(int a, int b, int *allfn, int noadd) {
    int i = a, seg = 1, nfn = 0, nvar = 0;
    while (i < b) {
        /* one segment */
        int last = -1, kind = 0, j = i;     /* kind: 0 none, 1 var, 2 fn */
        while (j < b) {
            if (is_p(j, ',')) break;
            if (iskwid(j) && (is_kw(j, "struct") || is_kw(j, "union") || is_kw(j, "enum"))) {
                int k = j + 1;
                while (is_kw(k, "__attribute__")) { k = skip_group(k + 1); if (k < 0) return 0; }
                if (is_id(k) && !iskwid(k)) { if (!noadd) adddef(tk[k].id); k++; }
                if (is_p(k, '{')) {
                    int e = skip_group(k); if (e < 0) return 0;
                    if (is_kw(j, "enum")) {      /* enumerators: identifiers after { or , at brace depth 1 */
                        int d = 0;
                        for (int m = k; m < e; m++) {
                            if (is_p(m, '{') || is_p(m, '(') || is_p(m, '[')) d++;
                            else if (is_p(m, '}') || is_p(m, ')') || is_p(m, ']')) d--;
                            else if (d == 1 && is_id(m) && (is_p(m - 1, '{') || is_p(m - 1, ',')) && !noadd) adddef(tk[m].id);
                        }
                    } else {                    /* nested tags and enums inside: add their names too */
                        for (int m = k; m < e; m++)
                            if ((is_kw(m, "struct") || is_kw(m, "union") || is_kw(m, "enum")) && is_id(m + 1) && !iskwid(m + 1) && !noadd)
                                adddef(tk[m + 1].id);
                        for (int m = k; m < e; m++)
                            if (is_kw(m, "enum")) return 0;     /* enum inside a struct body: do not guess */
                    }
                    k = e;
                }
                j = k; continue;
            }
            if (is_kw(j, "__attribute__") || is_kw(j, "__attribute")) { j = skip_group(j + 1); if (j < 0) return 0; continue; }
            if (is_kw(j, "asm") || is_kw(j, "__asm") || is_kw(j, "__asm__")) return 0;
            if (is_p(j, '{')) return 0;
            if (is_id(j)) { if (!iskwid(j)) last = j; j++; continue; }
            if (is_p(j, '[')) { if (last >= 0) { kind = 1; } j = skip_group(j); if (j < 0) return 0; continue; }
            if (is_p(j, '=')) return 0;
            if (is_p(j, '(') && last == -2) { j = skip_group(j); if (j < 0) return 0; continue; }   /* params of a (*name) */
            if (is_p(j, '(')) {
                int nx = j + 1;
                if (is_p(nx, '*') || is_p(nx, '(') || is_p(nx, '^')) {      /* (*name)(...): a pointer declarator */
                    int e = skip_group(j); if (e < 0) return 0;
                    int any = 0;
                    for (int m = j + 1; m < e - 1; m++) if (is_id(m) && !iskwid(m)) { if (!noadd) adddef(tk[m].id); any = 1; }
                    if (!any) return 0;
                    kind = 1; last = -2; j = e; continue;
                }
                if (last < 0) return 0;
                int e = skip_group(j); if (e < 0) return 0;
                if (e - j == 3 && is_id(j + 1) && !iskwid(j + 1) && !nm[tk[j + 1].id].td) {
                    /* (name) after a type: a parenthesised declarator or an untyped parameter; keep both */
                    if (!noadd) { adddef(tk[last].id); adddef(tk[j + 1].id); }
                    kind = 2; last = -2; j = e; continue;
                }
                if (!noadd) adddef(tk[last].id);
                kind = 2; last = -2; j = e; continue;
            }
            j++;
        }
        if (kind == 0 && last >= 0) { kind = 1; }
        if (kind == 1 && last >= 0) { if (!noadd) adddef(tk[last].id); }
        if (kind == 0 && last < 0 && seg == 1 && j >= b) { /* specifiers only (struct S {...}; or struct S;) */ }
        else if (kind == 0) return 0;
        if (kind == 2) nfn++; else if (kind == 1) nvar++;
        i = j + 1; seg++;
    }
    *allfn = (nfn > 0 && nvar == 0);
    return 1;
}

static void classify(Item *x) {
    int a = x->a, b = x->b;
    x->d0 = ndefs; x->nd = 0; x->root = 1;
    if (!is_p(b - 1, ';')) return;          /* a function definition: always kept */
    int e = b - 1, typedef_ = 0, extern_ = 0;
    for (int i = a; i < e; i++) {
        if (tk[i].kind == T_PRAG) return;
        if (is_kw(i, "typedef")) typedef_ = 1;
        else if (is_kw(i, "extern")) extern_ = 1;
        else if (is_p(i, '{')) { int g = skip_group(i); if (g < 0) return; i = g - 1; }
    }
    if (e == a) return;                     /* a stray ; */
    int allfn = 0;
    if (!declare(a, e, &allfn, 0)) { ndefs = x->d0; return; }
    if (!typedef_ && !extern_ && !allfn) {
        /* a variable definition allocates space and is kept; a declaration of no variable (struct S {...};) is a type */
        for (int i = a; i < e; i++) {
            if (is_p(i, '{')) { i = skip_group(i) - 1; continue; }
            if (is_id(i) && !iskwid(i) && !(i > a && (is_kw(i - 1, "struct") || is_kw(i - 1, "union") || is_kw(i - 1, "enum"))))
                { ndefs = x->d0; return; }
        }
    }
    x->root = 0; x->nd = ndefs - x->d0;
}

static int bad_after_paren(int i) {      /* K&R: ) followed by an identifier that is not an attribute/asm */
    return is_id(i) && !is_kw(i, "__attribute__") && !is_kw(i, "__attribute") && !is_kw(i, "asm") && !is_kw(i, "__asm__") && !is_kw(i, "__asm");
}

static void split(void) {
    int i = 0;
    while (i < ntk && !fallback) {
        int a = i;
        if (tk[i].kind == T_PRAG) { i++; goto push; }
        int pd = 0, eq = 0;
        for (;;) {
            if (i >= ntk) { bad(); return; }
            if (tk[i].kind == T_PRAG) { i++; continue; }
            if (pd == 0 && (is_kw(i, "__attribute__") || is_kw(i, "__attribute"))) {
                int g = skip_group(i + 1); if (g < 0) { bad(); return; }
                i = g; continue;
            }
            if (tk[i].kind == T_PUNCT) {
                char c = src[tk[i].off];
                if (c == '(' || c == '[') { pd++; i++; continue; }
                if (c == ')' || c == ']') {
                    if (--pd < 0) { bad(); return; }
                    i++;
                    if (c == ')' && pd == 0 && !eq && bad_after_paren(i)) { bad(); return; }
                    continue;
                }
                if (c == '=' && pd == 0) eq = 1;
                if (c == '{' && pd == 0) {
                    int g = skip_group(i); if (g < 0) { bad(); return; }
                    int p = i - 1;
                    while (p >= a && tk[p].kind == T_PRAG) p--;
                    int agg = 0, fn = 0; (void)agg;
                    if (p >= a && is_p(p, '=')) agg = 1;
                    else if (p >= a && (is_kw(p, "struct") || is_kw(p, "union") || is_kw(p, "enum"))) agg = 1;
                    else if (p - 1 >= a && is_id(p) && (is_kw(p - 1, "struct") || is_kw(p - 1, "union") || is_kw(p - 1, "enum"))) agg = 1;
                    else if (p >= a && is_p(p, ')')) {
                        int ty = 0;
                        for (int m = a, d = 0; m < i; m++) {
                            if (is_p(m, '(') || is_p(m, '[') || is_p(m, '{')) d++;
                            else if (is_p(m, ')') || is_p(m, ']') || is_p(m, '}')) d--;
                            else if (d == 0 && is_kw(m, "typedef")) ty = 1;
                        }
                        if (ty) { bad(); return; }
                        fn = 1;
                    } else { bad(); return; }
                    i = g;
                    if (fn) { goto push; }
                    continue;
                }
                if (c == '}') { bad(); return; }
                if (c == ';' && pd == 0) { i++; goto push; }
            }
            i++;
        }
    push:
        if (nit == cit) { cit = cit ? cit * 2 : 1024; it = realloc(it, cit * sizeof *it); }
        it[nit].a = a; it[nit].b = i; it[nit].root = 1; it[nit].kept = 0; it[nit].d0 = 0; it[nit].nd = 0; nit++;
    }
}

static void emit_tokens(FILE *o, int a, int b) {
    for (int i = a; i < b; i++) {
        if (tk[i].kind == T_PRAG) { fputc('\n', o); fwrite(src + tk[i].off, 1, tk[i].len, o); fputc('\n', o); continue; }
        if (tk[i].sp && i > a) fputc(' ', o);
        fwrite(src + tk[i].off, 1, tk[i].len, o);
    }
}

int main(int argc, char **argv) {
    int stats = 0; const char *path = 0;
    for (int i = 1; i < argc; i++) { if (!strcmp(argv[i], "--stats")) stats = dbg = 1; else path = argv[i]; }
    if (!path) { fprintf(stderr, "usage: hdrkey [--stats] FILE\n"); return 2; }
    FILE *f = fopen(path, "rb"); if (!f) { perror(path); return 2; }
    fseek(f, 0, SEEK_END); srclen = ftell(f); fseek(f, 0, SEEK_SET);
    src = malloc(srclen + 1);
    if (fread(src, 1, srclen, f) != (size_t)srclen) { perror(path); return 2; }
    src[srclen] = 0; fclose(f);
    tabn = 1 << 12; while (tabn < srclen / 4) tabn <<= 1;
    tab = malloc(tabn * sizeof *tab); memset(tab, -1, tabn * sizeof *tab);
    /* keywords live in a static copy appended to the buffer so intern() can point into src */
    {
        long extra = 0; for (int i = 0; KW[i]; i++) extra += strlen(KW[i]) + 1;
        src = realloc(src, srclen + extra + 1);
        long p = srclen;
        for (int i = 0; KW[i]; i++) { int n = strlen(KW[i]); memcpy(src + p, KW[i], n); int id = intern(src + p, n); nm[id].kw = 1; p += n + 1; src[p - 1] = 0; }
    }
    long full = srclen;
    srclen = full;
    lex();
    if (!fallback) split();
    if (!fallback) {
        /* typedef names first: they tell a type in (name) apart from a declarator */
        for (int pass = 0; pass < 2; pass++) {
            ndefs = 0;
            for (int k = 0; k < nit; k++) {
                Item *x = &it[k];
                if (pass == 0) {
                    int e = x->b - 1, a = x->a, isty = 0;
                    if (!is_p(e, ';')) continue;
                    for (int i = a; i < e; i++) { if (is_kw(i, "typedef")) isty = 1; if (is_p(i, '{')) { int g = skip_group(i); if (g < 0) break; i = g - 1; } }
                    if (!isty) continue;
                    int fnx = 0, d0 = ndefs;
                    if (declare(a, e, &fnx, 0)) for (int q = d0; q < ndefs; q++) nm[defs[q]].td = 1;
                    ndefs = d0;
                } else classify(x);
            }
        }
        /* reachability: roots first, then declarations naming something live */
        int *head = malloc((nnm + 1) * sizeof *head), *nxt = malloc((ndefs + 1) * sizeof *nxt), *own = malloc((ndefs + 1) * sizeof *own);
        char *live = calloc(nnm + 1, 1);
        int *stack = malloc((ntk + nnm + 16) * sizeof *stack), sp = 0;
        for (int i = 0; i < nnm; i++) head[i] = -1;
        for (int k = 0; k < nit; k++) if (!it[k].root) for (int q = it[k].d0; q < it[k].d0 + it[k].nd; q++) { own[q] = k; nxt[q] = head[defs[q]]; head[defs[q]] = q; }
        #define KEEP(K) do { Item *y = &it[K]; y->kept = 1; for (int m = y->a; m < y->b; m++) if (tk[m].kind == T_ID && !live[tk[m].id]) { live[tk[m].id] = 1; stack[sp++] = tk[m].id; } } while (0)
        for (int k = 0; k < nit; k++) if (it[k].root) KEEP(k);
        while (sp) {
            int id = stack[--sp];
            for (int q = head[id]; q >= 0; q = nxt[q]) if (!it[own[q]].kept) KEEP(own[q]);
        }
        int kept = 0, dropped = 0;
        for (int k = 0; k < nit; k++) { if (it[k].kept) kept++; else dropped++; }
        for (int k = 0; k < nit; k++) if (it[k].kept) { emit_tokens(stdout, it[k].a, it[k].b); fputc('\n', stdout); }
        if (stats) fprintf(stderr, "%d %d %d\n", nit, kept, dropped);
        return 0;
    }
    fputs("RAW\n", stdout);
    fwrite(src, 1, full, stdout);
    if (stats) fprintf(stderr, "RAW\n");
    return 0;
}
endef
$(HDRKEY): Makefile
	$(Q)mkdir -p build
	$(file >build/hdrkey.c,$(HDRKEY_C))
	$(Q)$(HOSTCC) -O2 -o $@ build/hdrkey.c 2>/dev/null || rm -f $@
shq = '$(subst ','\'',$(1))'
CC_FLAGS = $(TC) $(CC_$(TC)) $(CFLAGS) $(ASFLAGS) $(DEFINES)
PP_FLAGS = $(TC) $(CPPFLAGS) $(DEFINES)
same_flags = $(and $(findstring $(1),$(2)),$(findstring $(2),$(1)))
flags_changed = $(if $(wildcard $@.flags),$(if $(call same_flags,$(CC_FLAGS),$(file <$@.flags)),,flags-changed))
pp_flags_changed = $(if $(wildcard $@.flags),$(if $(call same_flags,$(PP_FLAGS),$(file <$@.flags)),,flags-changed))
.PHONY: flags-changed
flags-changed:
build/%.i.ok: $$(call src,$$*) $$(pp_flags_changed) | $(STAMPS) $(HDRKEY)
	$(Q)mkdir -p $(@D)
	$(PREPROCESS_$(TC))
	$(Q)n=$(@:.ok=.new); i=$(@:.ok=); k=$(@:.ok=.key); \
	if cmp -s $$n $$i; then rm -f $$n; else keep=; \
	  if [ -x $(HDRKEY) ] && $(HDRKEY) $$n > $$k.new; then \
	    if [ -f $$i ] && { [ $$k -nt $$i ] || $(HDRKEY) $$i > $$k; } && cmp -s $$k.new $$k; then keep=1; fi; \
	  else rm -f $$k.new; fi; \
	  if [ -n "$$keep" ]; then rm -f $$n $$k.new; \
	  else mv -f $$n $$i; if [ -s $$k.new ]; then mv -f $$k.new $$k; else rm -f $$k $$k.new; fi; fi; \
	fi
	$(Q)printf '%s\n' $(call shq,$(PP_FLAGS)) > $@.flags
	$(Q)touch $@
	$(Q)python3 -I build/stamp-sweep.py record $@
build/%.o: build/%.i.ok asm/$$(call ver,$$*)/.extracted $$(text_size_changed) $$(flags_changed) | $(STAMPS)
	$(Q)if [ -z "$(filter-out %.i.ok,$?)$(flags_changed)" ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && [ -f $@ ] && \
	[ $(@:.o=.i) -ot $@ ]; then printf '%s\n' $(call shq,$(CC_FLAGS)) > $@.flags; touch $@; \
	else $(COMPILE_$(TC)) && if [ -f $@.same ]; then rm -f $@.same; else $(if $(TEXTSIZE),$(TRIM_TEXT) $@ $(TEXTSIZE),true) && \
	printf '%s\n' '$(TEXTSIZE)' > $@.textsize; fi && printf '%s\n' $(call shq,$(CC_FLAGS)) > $@.flags; fi
	$(Q)python3 -I build/stamp-sweep.py record $@ $(filter-out %/.extracted,$(filter asm/%,$^))
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
# Preprocessed sources retain auto-address references even when a new extraction no longer spells that label.
build/%/undefined_syms.ld: versions/%/symbol_addrs.txt build/%/undefined_syms_auto.txt build/%/undefined_funcs_auto.txt asm/%/.extracted $$(OBJS_$$*) $$(wildcard versions/$$*/aliases.txt)
	$(Q)sed -nE 's/^([A-Za-z_.][A-Za-z0-9_.$$]*)[[:space:]]*=[[:space:]]*(0x[0-9A-Fa-f]+);.*/PROVIDE(\1 = \2);/p' $^ > $@
	$(Q)grep -rhoE --include='*.s' --include='*.i' '[A-Za-z_.]*auto_[0-9A-F]{8}\b' asm/$* build/$* | sort -u | sed -E 's/^([A-Za-z_.]*auto_(.*))$$/PROVIDE(\1 = 0x\2);/' >> $@
# splat writes these while it extracts the version.
build/%/undefined_syms_auto.txt build/%/undefined_funcs_auto.txt: | asm/%/.extracted
	$(Q)test -f $@ || { echo "$@ is missing: run make extract-$*" >&2; exit 1; }
build/%/$(NAME).elf: $$(OBJS_$$*) build/%/link.ld build/%/undefined_syms.ld
	$(Q)cd build/$* && $(LD) -T link.ld -o $(NAME).elf
build/%/$(NAME).bin: build/%/$(NAME).elf
	$(Q)$(OBJCOPY) $(ROM_SECTIONS_$*) -O binary --gap-fill 0 $< $@
build/%/$(NAME).z64: build/%/$(NAME).bin roms/baserom.%.z64
	$(Q){ head -c $(ROM0_$*) roms/baserom.$*.z64; cat $<; } > $@
	$(Q)truncate -s $$(wc -c < roms/baserom.$*.z64) $@
	$(Q)test "$$(sha1sum < $@ | cut -d' ' -f1)" = $(SHA1_$*) || { echo "$@: SHA-1 is not $(SHA1_$*)" >&2; exit 1; }

# make NON_MATCHING=1 (or make nm): every draft compiles in (-DNON_MATCHING) and one ROM per version
# links under build/nm/<version>/. The drafts compile into a second tree build/nmraw/<version>/ with the
# matching build's rules and flags. A unit whose NON_MATCHING object keeps the unit's size (NM_PICK: the same
# sections, a text no longer than the ROM's, zero-filled to it) takes the matching object's place in the link; any
# other unit keeps its matching object. The ROM so keeps its size and every unit's address, and matches no SHA-1, so
# nothing here checks one. build/nm/<version>/report.txt names the units whose draft is in (and how many symbols
# move in them) and the ones left out (and the section that grew).
define NM_PICK
import os, shutil, struct, subprocess, sys
def read(path):
    d = open(path, "rb").read()
    o = struct.unpack_from(">I", d, 32)[0]
    e, c, x = struct.unpack_from(">HHH", d, 46)
    rows = [struct.unpack_from(">10I", d, o + k * e) for k in range(c)]
    names = d[rows[x][4]:rows[x][4] + rows[x][5]]
    name = lambda r: names[r[0]:].split(b"\0")[0].decode()
    skip = (".pdr", ".comment", ".mdebug", ".reginfo", ".gnu.attributes")
    sizes = {name(r): r[5] for r in rows if r[1] in (1, 8) and name(r) not in skip}
    data = {name(r): d[r[4]:r[4] + r[5]] for r in rows if r[1] == 1 and name(r) not in skip}
    syms, table, undef = set(), {}, set()
    for k, r in enumerate(rows):
        if r[1] == 2:
            strs = d[rows[r[6]][4]:rows[r[6]][4] + rows[r[6]][5]]
            for j in range(r[5] // 16):
                n, v, z, i, _, sh = struct.unpack_from(">IIIBBH", d, r[4] + 16 * j)
                s = strs[n:].split(b"\0")[0].decode()
                table[(k, j)] = s
                if sh == 0 and s and j and i >> 4:
                    undef.add(s)
                if 0 < sh < 0xFF00 and i & 15 not in (3, 4) and s and not s.startswith(".L"):
                    syms.add((s, name(rows[sh]), v))
    relocs = set()
    for r in rows:
        if r[1] == 9 and name(rows[r[7]]) not in skip:
            for j in range(r[5] // 8):
                off, info = struct.unpack_from(">II", d, r[4] + 8 * j)
                relocs.add((name(rows[r[7]]), off, info & 255, table.get((r[6], info >> 8), "")))
    return sizes, syms, data, relocs, undef
raw, matching, out, objcopy, ld = sys.argv[1:6]
a, b = read(raw), read(matching)
rest = lambda sizes: {k: v for k, v in sizes.items() if k != ".text"}
missing = sorted(a[4] - b[4] - {x[0] for x in b[1]})
if missing:
    # a draft naming a symbol the unit does not (a fuzzy draft's own data name) cannot link to this ROM
    verdict, pick = "left-out undefined " + " ".join(missing[:3]), matching
elif a == b:
    verdict, pick = "same", matching
elif a[:2] == b[:2]:
    verdict, pick = "draft", raw
elif rest(a[0]) == rest(b[0]) and a[0].get(".text", 0) <= b[0].get(".text", 0):
    # a shorter text keeps the unit's size when zeros fill the rest: the next unit starts where it did
    # ld -r keeps the relocations, which objcopy --update-section drops from a section it replaces
    open(out + ".lds", "w").write("SECTIONS { .text : { *(.text) . = %d; } }\n" % b[0][".text"])
    subprocess.run([ld, "-r", "-T", out + ".lds", "-o", out, raw], check=True)
    os.remove(out + ".lds")
    moved = len({sym[0] for sym in a[1] ^ b[1]})
    verdict, pick = "draft-padded %d bytes, %d symbols move" % (b[0][".text"] - a[0][".text"], moved), None
else:
    grown = [k for k in sorted(set(a[0]) | set(b[0])) if a[0].get(k, 0) != b[0].get(k, 0)]
    why = " ".join("%s:%d->%d" % (k, b[0].get(k, 0), a[0].get(k, 0)) for k in grown)
    verdict, pick = "left-out " + (why or "symbols moved"), matching
if pick:
    shutil.copyfile(pick, out)
open(out + ".pick", "w").write("%s %s\n" % (verdict, out))
endef
export NM_PICK
.PHONY: nm
nm: $(VERSIONS:%=build/nm/%/$(NAME).z64)
$(foreach v,$(VERSIONS),$(eval OBJS_nm_$(v) := $(patsubst build/$(v)/%,build/nm/$(v)/%,$(OBJS_$(v)))))
-include $(foreach v,$(VERSIONS),$(patsubst build/$(v)/%,build/nmraw/$(v)/%,$(OBJS_$(v):.o=.d)))
# A raw object follows the extracted files its matching twin names, and takes the same text sizes.
$(shell sed -E 's@^build/@build/nmraw/@' build/asm.deps > build/asm-nmraw.deps.$$$$ && mv build/asm-nmraw.deps.$$$$ build/asm-nmraw.deps)
-include build/asm-nmraw.deps
$(shell cat $(VERSIONS:%=versions/%/text_sizes.mk) | sed -E 's@^build/@build/nmraw/@' > build/text_sizes_nmraw.mk.$$$$ && mv build/text_sizes_nmraw.mk.$$$$ build/text_sizes_nmraw.mk)
-include build/text_sizes_nmraw.mk
build/nm/%.o: build/nmraw/%.o build/%.o
	$(Q)mkdir -p $(@D)
	$(Q)python3 -I -c "$$NM_PICK" $^ $@ $(OBJCOPY) $(LD)
# An assembly or binary piece is the matching build's.
build/nm/%.s.o: build/%.s.o
	$(Q)mkdir -p $(@D)
	$(Q)cp -p $< $@
build/nm/%.bin.o: build/%.bin.o
	$(Q)mkdir -p $(@D)
	$(Q)cp -p $< $@
# Static pattern rules: build/%/link.ld would also match build/nm/<version>/link.ld and write an empty script.
$(VERSIONS:%=build/nm/%/link.ld): build/nm/%/link.ld: build/%/link.ld
	$(Q)mkdir -p $(@D)
	$(Q)cp $< $@
$(VERSIONS:%=build/nm/%/undefined_syms.ld): build/nm/%/undefined_syms.ld: build/%/undefined_syms.ld
	$(Q)mkdir -p $(@D)
	$(Q)cp $< $@
# A draft may define a name that this version's ROM keeps as data, or the other way round: the first definition in link
# order wins and link.err lists every such name; any other link error stops the build.
$(VERSIONS:%=build/nm/%/$(NAME).elf): build/nm/%/$(NAME).elf: $$(OBJS_nm_$$*) build/nm/%/link.ld \
	build/nm/%/undefined_syms.ld
	$(Q)cd build/nm/$* && { $(LD) -T link.ld -o $(NAME).elf 2> link.err \
	|| $(LD) -T link.ld --allow-multiple-definition -o $(NAME).elf 2>> link.err; } \
	|| { cat build/nm/$*/link.err >&2; exit 1; }
$(VERSIONS:%=build/nm/%/$(NAME).bin): build/nm/%/$(NAME).bin: build/nm/%/$(NAME).elf
	$(Q)$(OBJCOPY) $(ROM_SECTIONS_$*) -O binary --gap-fill 0 $< $@
$(VERSIONS:%=build/nm/%/$(NAME).z64): build/nm/%/$(NAME).z64: build/nm/%/$(NAME).bin roms/baserom.%.z64
	$(Q){ head -c $(ROM0_$*) roms/baserom.$*.z64; cat $<; } > $@
	$(Q)truncate -s $$(wc -c < roms/baserom.$*.z64) $@
	$(Q)cat $(addsuffix .pick,$(OBJS_nm_$*)) 2>/dev/null | grep -v '^same ' | sort > build/nm/$*/report.txt; \
	echo "NM ROM $*: $$(grep -c '^draft' build/nm/$*/report.txt) unit(s) with drafts in," \
	"$$(grep -c '^left-out' build/nm/$*/report.txt) left out (build/nm/$*/report.txt)"

tools/n64link/.stamp:
	$(Q)mkdir -p tools/n64link && curl -fsSL https://github.com/AbuN64/mas-n64/releases/download/v0.2.0/n64link-v0.2.0-linux-x86_64.tar.gz -o tools/n64link.tar.gz && echo '061d7bc69f21228c7029f4f530cd980bab3a35749751a43f2823d03d95be4ef7  tools/n64link.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/n64link.tar.gz -C tools/n64link --strip-components=1 n64link-v0.2.0-linux-x86_64/n64link && rm -f tools/n64link.tar.gz && cd tools/n64link && printf '%s\n' '583e544840d04123fa7e26c7416316ffe410139351e07cd3395d4bd5ec609c3c  n64link' | sha256sum -c - >/dev/null && touch .stamp

tools/gcc-2.7.2-sn64/.stamp:
	$(Q)mkdir -p tools/gcc-2.7.2-sn64 && curl -fsSL https://github.com/decompals/SN64-gcc/releases/download/gcc-2.7.2-970404/SN64-gcc-2.7.2-970404-linux.tar.gz -o tools/gcc-2.7.2-sn64.tar.gz && echo '60abe17c2562f5ae28444fe4f783fa8217d84b73e59e29cf39c41f7551d968f4  tools/gcc-2.7.2-sn64.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/gcc-2.7.2-sn64.tar.gz -C tools/gcc-2.7.2-sn64 cc1 && rm -f tools/gcc-2.7.2-sn64.tar.gz && cd tools/gcc-2.7.2-sn64 && printf '%s\n' '566d91772fc1435d23dbca5e8040d3e441b31375b2aec4f430e5cddc5d70d8d4  cc1' | sha256sum -c - >/dev/null && touch .stamp

tools/gcc-2.8.1-sn64/.stamp:
	$(Q)mkdir -p tools/gcc-2.8.1-sn64 && curl -fsSL https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz -o tools/gcc-2.8.1-sn64.tar.gz && echo '1156cf0d6a88a64c20e2a10fc9445d99cb9a38518f432b1669528dfa82ebb45f  tools/gcc-2.8.1-sn64.tar.gz' | sha256sum -c - >/dev/null && tar -xzf tools/gcc-2.8.1-sn64.tar.gz -C tools/gcc-2.8.1-sn64 cc1 && rm -f tools/gcc-2.8.1-sn64.tar.gz && cd tools/gcc-2.8.1-sn64 && printf '%s\n' 'd1ddfe21dfa61840a83f833c8bd45ed7e2f606c3d9c351d2ec732fb6e4f97c89  cc1' | sha256sum -c - >/dev/null && touch .stamp

