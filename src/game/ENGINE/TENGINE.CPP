#include "include_asm.h"
#include "COMMON/PAKQUEUESTATE.H"
#include "TEXTURE/80294C64.H"

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
#include "sdk/AUDIO/802BD1A8_19.H"
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

/* 132/159 words (positional); remaining: one delay-slot fill (move s5,s4 belongs in the bne delay slot; ours annuls with bnel), same instructions otherwise */
void func_80294CA0_us_rev1(void) {
    u32 sp28;
    u32 key;
    s32 **res;
    s32 *s3;
    s32 *s2;
    s32 hi;
    s32 lo;
    s32 idx;
    s32 *s5;
    char *s1;
    s32 *sel;
    s32 t;
    void *v;
    Shared_World *w;
    u8 *name;
    s32 i;
    w = &D_8011FE88;
    if (D_8014AECC != NULL) {
        func_80253754_de(NULL, D_8014AECC);
    }
    sel = (s32 *)&D_8014AEBC;
    D_8014AECC = NULL;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    key = func_8028FE3C_de(w->unk50, w->unk20, sel[0], &sp28);
    res = func_8025193C_de(0, key - 1, key, sp28, 9, -1, &D_00295B90_us_rev1, &D_auto_src_ragewars_resident_strings_CB1D0_us_rev1, 1);
    s3 = *res;
    s2 = func_8028FDB4_de(s3, 1);
    s5 = func_8028FDB4_de(s3, 2);
    if (sel[1] < 0) {
        s32 *p = &sel[1];
        do {
            t = *p + *s2;
            *p = t;
        } while (t < 0);
    }
    s1 = (char *)&D_8014AEC0;
    hi = *(s32 *)s1 % *s2;
    lo = *(s32 *)s1 % *s5;
    *(s32 ***)(s1 + 0xC) = res;
    *(void **)(s1 + 0x14) = func_8028FDB4_de(s2, hi);
    *(void **)(s1 + 0x18) = func_8028FDB4_de(s5, lo);
    v = func_8028FDB4_de(s3, 0);
    *(s32 **)(s1 + 0x2124) = s5;
    *(void **)(s1 + 0x10) = v;
    *(s32 *)(s1 + 8) = 0;
    *(s32 **)(s1 + 0x211C) = s3;
    *(s32 **)(s1 + 0x2120) = s2;
    if (*s3 == 4) {
        s5 = (s32 *)hi;
        name = func_8028FDB4_de(s3, 3);
        for (i = 0; i < func_802BD400_de(name); i++) {
            if (name[i] == 0x2E) {
                name[i] = 0;
                break;
            }
        }
        func_802BD320_de(&D_8014CFE8_us_rev1, &D_auto_rodata_func_80294CA0_us_rev1_800CA5D0_unclaimed_CB1E0, *(s32 *)(&D_8014CFE8_us_rev1 - 0x212C), (s32)s5, *s2, name);
    } else {
        func_802BD320_de(s1 + 0x2128, &D_auto_800CA5F8, *(s32 *)(s1 - 4), hi, *s2);
    }
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
        if (D_8010F328[0].buttons & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0.alternateTitle == 0) {
                    Camera_PostScreenMessage(&D_80145088, (u8 *)&D_80145088 + 0x40, D_800CA60C);
                    D_8014AEB0.titleWasShown = 1;
                } else {
                    Camera_PostScreenMessage(&D_80145088, (u8 *)&D_80145088 + 0x40, D_auto_800CA620);
                }
                D_auto_800D2AFC = 1;
                D_8014AEB0.alternateTitle = (u8) ((u8) D_8014AEB0.alternateTitle < 1U);
            }
        } else {
            D_auto_800D2AFC = 0;
        }
        if (D_8010F328[0].buttons & 0x2000) {
            if (D_8010F328[0].buttons & 0x200) {
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
            if (D_8010F328[0].buttons & 0x100) {
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
            if (D_8010F328[0].buttons & 0x200) {
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
            if (D_8010F328[0].buttons & 0x100) {
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
            if (D_8010F328[0].buttons & 0x400) {
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
            if (D_8010F328[0].buttons & 0x800) {
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
