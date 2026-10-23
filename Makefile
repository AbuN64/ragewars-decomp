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
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
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
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C6420.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/audio/802C5E90.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): TC := gcc_2_8_1_sn64
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CPPFLAGS := -P -undef -nostdinc -D_LANGUAGE_C -D__GNUC__=2 -D__STDARG_GCC -DF3DEX_GBI_2 -Isrc/sdk/libgcc
$(foreach v,$(VERSIONS),build/nmraw/$(v)/src/sdk/libultra/libc/802C1880_2.CPP.o): CFLAGS := -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -mfp32
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
extract: $(VERSIONS:%=extract-%)
extract-%:
	$(Q)python3 -I -c "$$KEEP_DATES" save $*
	$(Q)$(SPLAT) split versions/$*/splat.yaml
	$(Q)find asm/$* \( -name '*.data.s' -o -name '*.rodata.s' \) | while read f; do \
		case $$(grep -m1 -oE '^ */\* [0-9A-F]+ [0-9A-F]{8}' "$$f" | tail -c 2) in \
		0*) c='';; 8*) c='s/^\.align [4-9]/.align 3/';; [4C]*) c='s/^\.align [3-9]/.align 2/';; \
		[26AE]*) c='s/^\.align [2-9]/.align 1/';; *) c='s/^\.align [1-9]/.align 0/';; esac; \
		sed -E $(DATA_SED) -e "$$c" "$$f" > "$${f%.*.s}.s" && rm "$$f"; done
	$(Q)python3 -I -c "$$FILL_DATA" $*
	$(Q)find asm/$*/nonmatchings -name '*.s' -exec sed -i -E $(CODE_SED) {} +
	$(Q)touch asm/$*/.extracted
	$(Q)python3 -I -c "$$KEEP_DATES" restore $*
# An object assembles extracted files its source only names through a macro: every object follows the extraction.
asm/%/.extracted: | roms/baserom.%.z64
	+$(Q)$(MAKE) --no-print-directory extract-$*

# The link script names every object, so no rule here lists a file.
$(foreach v,$(VERSIONS),$(eval OBJS_$(v) := $(addprefix build/$(v)/,$(shell $(CPP) -P -undef -D$(VMACRO_$(v)) $(NAME).ld 2>/dev/null | grep -oE '[[:alnum:]_./+-]+[.]o' | sort -u))))
-include $(foreach v,$(VERSIONS),$(OBJS_$(v):.o=.d))

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

# An object follows the text its source preprocesses to, not the time its headers were written: the .i is replaced only
# when its bytes change, so a header edit that leaves a source's text alone (a comment, a part another version reads)
# preprocesses that source again and compiles nothing. The stamp (.i.ok) carries the header times; the object compiles
# when its .i is newer than it or another input (the extraction, the text size) changed, else it is only touched.
# A flags row (TC, CPPFLAGS, CFLAGS of a [file] row, the toolchain's compiler) that changes remakes the objects it
# reaches: each object keeps the flags it was made with beside it (`.flags` for the compile, `.i.ok.flags` for the
# preprocess) and, when its own flags differ, make sees one more prerequisite that is out of date. A stamp a build never
# wrote (an object made before the stamps) is trusted, so the first run after an upgrade rebuilds nothing.
shq = '$(subst ','\'',$(1))'
CC_FLAGS = $(TC) $(CC_$(TC)) $(CFLAGS) $(ASFLAGS) $(DEFINES)
PP_FLAGS = $(TC) $(CPPFLAGS) $(DEFINES)
same_flags = $(and $(findstring $(1),$(2)),$(findstring $(2),$(1)))
flags_changed = $(if $(wildcard $@.flags),$(if $(call same_flags,$(CC_FLAGS),$(file <$@.flags)),,flags-changed))
pp_flags_changed = $(if $(wildcard $@.flags),$(if $(call same_flags,$(PP_FLAGS),$(file <$@.flags)),,flags-changed))
.PHONY: flags-changed
flags-changed:
build/%.i.ok: $$(call src,$$*) $$(pp_flags_changed) | $(STAMPS)
	$(Q)mkdir -p $(@D)
	$(PREPROCESS_$(TC))
	$(Q)if cmp -s $(@:.ok=.new) $(@:.ok=); then rm -f $(@:.ok=.new); else mv -f $(@:.ok=.new) $(@:.ok=); fi
	$(Q)printf '%s\n' $(call shq,$(PP_FLAGS)) > $@.flags
	$(Q)touch $@
build/%.o: build/%.i.ok asm/$$(call ver,$$*)/.extracted $$(text_size_changed) $$(flags_changed) | $(STAMPS)
	$(Q)if [ -z "$(filter-out %.i.ok,$?)$(flags_changed)" ] && [ "x$(file <$@.textsize)" = "x$(TEXTSIZE)" ] && [ -f $@ ] && \
	[ $(@:.o=.i) -ot $@ ]; then printf '%s\n' $(call shq,$(CC_FLAGS)) > $@.flags; touch $@; \
	else $(COMPILE_$(TC)) && if [ -f $@.same ]; then rm -f $@.same; else $(if $(TEXTSIZE),$(TRIM_TEXT) $@ $(TEXTSIZE),true) && \
	printf '%s\n' '$(TEXTSIZE)' > $@.textsize; fi && printf '%s\n' $(call shq,$(CC_FLAGS)) > $@.flags; fi
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
$(shell sed -E 's@^build/@build/nmraw/@' build/asm.deps > build/asm-nmraw.deps)
-include build/asm-nmraw.deps
$(shell cat $(VERSIONS:%=versions/%/text_sizes.mk) | sed -E 's@^build/@build/nmraw/@' > build/text_sizes_nmraw.mk)
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
	$(Q)$(OBJCOPY) -O binary --gap-fill 0 $< $@
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

