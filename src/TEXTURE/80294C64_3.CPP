#include "include_asm.h"

#if defined(VERSION_US_REV1)
#ifdef NON_MATCHING
/* The names m2c output assumes (its valid-syntax macros), so a draft compiles on its own. */
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
#define M2C_FIELD(base, type, offset) (*(type)((char *)(base) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK(...) (0)
#define M2C_SYNC(...) (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENTSTATE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WORLD.H"
#include "RENDER_4/8028FD2C_6.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "SDK/AUDIO/802BD1A8_19.H"
#include "TYPES.H"
#include "stddef.h"
u32 func_8028FE3C_de(s32, s32, s32, u32 *);
s32 func_802BD400_de(void *);
extern s32 D_00295B90_us_rev1;
extern s32 D_8014AEC0;
extern Node80253610 *D_8014AECC;
extern s32 D_8014AED0;
extern s32 D_8014AED4;
extern s8 D_8014CFE8_us_rev1;
extern s8 D_auto_800CA5F8;
extern s8 D_auto_rodata_func_80294CA0_us_rev1_800CA5D0_unclaimed_CB1E0;
extern s8 D_auto_src_ragewars_resident_strings_CB1D0_us_rev1;

extern void func_80294CA0_us_rev1(void) {
    u32 sp28;
    s32 **temp_v0_2;
    s32 *temp_s2;
    s32 *temp_s3;
    s32 *temp_s5;
    s32 temp_hi;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_s0;
    s8 *var_a0;
    s8 *var_a1;
    u32 temp_v0;
    u8 *temp_v1_2;
    void *temp_s1;
    void *temp_v0_3;

    if (D_8014AECC != NULL) {
        func_80253754_de(NULL, D_8014AECC);
    }
    D_8014AECC = NULL;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    temp_v0 = func_8028FE3C_de(D_8011FE88.unk50, D_8011FE88.unk20, M2C_FIELD(&D_8014AEBC, s32 *, 0), &sp28);
    temp_v0_2 = func_8025193C_de(0, temp_v0 - 1, temp_v0, sp28, 9U, -1, &D_00295B90_us_rev1, &D_auto_src_ragewars_resident_strings_CB1D0_us_rev1, 1U);
    temp_s3 = *temp_v0_2;
    temp_s2 = func_8028FDB4_de(temp_s3, 1);
    temp_s5 = func_8028FDB4_de(temp_s3, 2);
    if (M2C_FIELD(&D_8014AEBC, s32 *, 4) < 0) {
        do {
            temp_v1 = M2C_FIELD(&D_8014AEBC, s32 *, 4) + *temp_s2;
            M2C_FIELD(&D_8014AEBC, s32 *, 4) = temp_v1;
        } while (temp_v1 < 0);
    }
    temp_hi = (s32) M2C_FIELD(&D_8014AEC0, s32 *, 0) % (s32) *temp_s2;
    temp_s0 = (s32) M2C_FIELD(&D_8014AEC0, s32 *, 0) % (s32) *temp_s5;
    M2C_FIELD(&D_8014AEC0, s32 ***, 0xC) = temp_v0_2;
    M2C_FIELD(&D_8014AEC0, void **, 0x14) = func_8028FDB4_de(temp_s2, temp_hi);
    M2C_FIELD(&D_8014AEC0, void **, 0x18) = func_8028FDB4_de(temp_s5, temp_s0);
    temp_v0_3 = func_8028FDB4_de(temp_s3, 0);
    M2C_FIELD(&D_8014AEC0, s32 **, 0x2124) = temp_s5;
    M2C_FIELD(&D_8014AEC0, void **, 0x10) = temp_v0_3;
    M2C_FIELD(&D_8014AEC0, s32 *, 8) = 0;
    M2C_FIELD(&D_8014AEC0, s32 **, 0x211C) = temp_s3;
    M2C_FIELD(&D_8014AEC0, s32 **, 0x2120) = temp_s2;
    if (*temp_s3 == 4) {
        temp_s1 = func_8028FDB4_de(temp_s3, 3);
        var_s0 = 0;
loop_7:
        temp_v1_2 = temp_s1 + var_s0;
        if (var_s0 < func_802BD400_de(temp_s1)) {
            var_s0 += 1;
            if (*temp_v1_2 == 0x2E) {
                *temp_v1_2 = 0;
            } else {
                goto loop_7;
            }
        }
        var_a0 = &D_8014CFE8_us_rev1;
        var_a1 = &D_auto_rodata_func_80294CA0_us_rev1_800CA5D0_unclaimed_CB1E0;
        var_a2 = M2C_FIELD(&D_8014CFE8_us_rev1, s32 *, -0x212C);
    } else {
        var_a0 = &D_8014AEC0 + 0x2128;
        var_a1 = &D_auto_800CA5F8;
        var_a2 = M2C_FIELD(&D_8014AEC0, s32 *, -4);
    }
    func_802BD320_de(var_a0, var_a1, var_a2, temp_hi, *temp_s2);
    D_8014D068 = 0;
}
#else
INCLUDE_ASM("span_1000", func_80294CA0_us_rev1);
#endif
#endif

#if defined(VERSION_US_REV1)
/* Handles repeated menu navigation inputs and draws the current menu display.
 * The index/value/changed words form the contiguous selection record; named globals
 * and owner fields provide views of that same menu state. */
#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/CHANNEL.H"

struct MenuGlobalRecAt21B8;

struct SelectionRecAt8;

struct Message;
extern struct MenuGlobalRecAt21B8 D_8014AEB0;
extern s32 D_8014AEC0;


void func_80294F1C_us_rev1(void) {
    f32 scale;
    s32 temp_a0;
    s32 regpart_temp_a0; 
    s32 count_0;
    s32 count_1;
    s32 count_2;
    s32 count_3;
    s32 count_4;
    s32 count_5;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_10; 
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_v1;
    s32 var_v1_2;
    s32 minusOne; 
    struct SelectionRecAt8 *selection; 


    if (D_800D2AE0 != 0) {
        if (D_8010B3D8 & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0.alternateTitle == 0) {
                    func_80237E80_de(&D_80145088, (u8 *)&D_80145088 + 0x40, D_800CA60C);
                    D_8014AEB0.titleWasShown = 1;
                } else {
                    func_80237E80_de(&D_80145088, (u8 *)&D_80145088 + 0x40, D_auto_800CA620);
                }
                D_auto_800D2AFC = 1;
                D_8014AEB0.alternateTitle = (u8) ((u8) D_8014AEB0.alternateTitle < 1U);
            }
        } else {
            D_auto_800D2AFC = 0;
        }
        if (D_8010B3D8 & 0x2000) {
            if (D_8010B3D8 & 0x200) {
                count_0 = D_800D2AEC;
                temp_v1 = count_0; 
                count_0 += 1;
                D_800D2AEC = count_0;
                if (temp_v1 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AEC = 0;
                    D_8014AEC0 -= 1;
                }
            }
            if (D_8010B3D8 & 0x100) {
                count_1 = D_800D2AF0;
                temp_v1_2 = count_1; 
                count_1 += 1;
                D_800D2AF0 = count_1;
                if (temp_v1_2 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AF0 = 0;
                    D_8014AEC0 += 1;
                }
            }
        } else {
            if (D_8010B3D8 & 0x200) {
                count_2 = D_auto_800D2AE4;
                temp_v1_3 = count_2; 
                count_2 += 1;
                D_auto_800D2AE4 = count_2;
                if (temp_v1_3 >= 3) {
                    minusOne = D_8014AEBC;
                    minusOne -= 1;
                    temp_v0_2 = minusOne + D_8014AEB8.unk0;
                    var_v1 = temp_v0_2 % D_8014AEB8.unk0;
                    D_8014AEB0.titleWasShown = 1;
                    ((struct SelectionRecAt8 *)&D_8014AEBC)->index = minusOne;
                    D_8014AEBC = var_v1;
                    if ((f32) var_v1 < 0.0f) {
                        var_v1 = -var_v1;
                    }
                    D_8014AEB0.selectionIndex = var_v1;
                    D_auto_800D2AE4 = 0;
                }
            }
            if (D_8010B3D8 & 0x100) {
                count_3 = D_auto_800D2AE8;
                temp_v1_4 = count_3; 
                count_3 += 1;
                D_auto_800D2AE8 = count_3;
                if (temp_v1_4 >= 3) {
                    temp_v1_5 = D_8014AEBC + 1;
                    temp_a0 = temp_v1_5 % D_8014AEB8.unk0;
                    D_auto_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_5; 
                    D_8014AEBC = temp_a0;
                }
            }
            if (D_8010B3D8 & 0x400) {
                count_4 = D_auto_800D2AF4;
                temp_v1_7 = count_4; 
                count_4 += 1;
                D_auto_800D2AF4 = count_4;
                if (temp_v1_7 >= 3) {
                    regpart_temp_a0 = D_8014AEBC - 5;
                    temp_v0_3 = regpart_temp_a0 + D_8014AEB8.unk0;
                    var_v1_2 = temp_v0_3 % D_8014AEB8.unk0;
                    D_8014AEB0.selectionIndex = regpart_temp_a0;
                    selection = (struct SelectionRecAt8 *)&D_8014AEBC;
                    D_8014AEBC = var_v1_2;
                    if ((f32) var_v1_2 < 0.0f) {
                        var_v1_2 = -var_v1_2;
                    }
                    selection->index = var_v1_2;
                    selection->changed = 1;
                    D_auto_800D2AF4 = 0;
                }
            }
            if (D_8010B3D8 & 0x800) {
                count_5 = D_auto_800D2AF8;
                temp_v1_8 = count_5; 
                count_5 += 1;
                D_auto_800D2AF8 = count_5;
                if (temp_v1_8 >= 3) {
                    temp_v1_9 = D_8014AEBC + 5;
                    temp_a0 = temp_v1_9 % D_8014AEB8.unk0;
                    D_auto_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_9; 
                    D_8014AEBC = temp_a0;
                }
            }
        }
        D_8014AEB0.frameCount += 1;
        if (D_8014AEB0.titleWasShown != 0) {
            func_80294CA0_us_rev1();
            D_8014AEB0.titleWasShown = 0;
        }
        func_802A84F8_de();
        scale = D_auto_800CA634;
        func_802A8710_de();
        func_802AAB68_de(scale, scale);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de((char *)&D_8014AEB0.displayData, 0x10, D_800E28D4 - 0x30, 0xFF, 0, 0, scale, scale);
    }
}
#endif
