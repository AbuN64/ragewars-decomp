#include "include_asm.h"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "MULTI/804453C4.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
/* Steps a menu spinner for the entry func_8022A5A0_de finds in D_80145040: advances its repeat timer by D_800D2988, wrapping at D_800E2810, and while the menu is active (state 1) decrements its value above zero when func_80264388_de reports the decrease input, or else increments it below its maximum when func_802643A0_de reports the increase input, restarting the timer on a change. Returns zero. */




extern char D_80145040[];
extern Spinner D_800E63C0[];

extern s32 func_8022A5A0_de(char *, s32);



s32 func_80445964_de(void *unused, MenuRecAt20V1 *menu) {
    s32 i;
    f32 t;

    i = func_8022A5A0_de(D_80145040, menu->id);
    t = D_800E63C0[i].timer + D_800D2988;
    D_800E63C0[i].timer = t;
    if (t >= (15.0f)) {
        D_800E63C0[i].timer = t - (15.0f);
    }
    if (menu->state == 1) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E63C0[i].value > 0) {
            D_800E63C0[i].value--;
            D_800E63C0[i].timer = 0.0f;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E63C0[i].value < D_800E63C0[i].max) {
                D_800E63C0[i].value++;
                D_800E63C0[i].timer = 0.0f;
            }
        }
    }
    return 0;
}
#endif

#if defined(VERSION_US_REV1)
INCLUDE_RODATA("data_800C", rodata_func_80445964_de_800E2810);
#endif

#if defined(VERSION_US_REV1)
typedef struct SpinnerTimer { f32 timer; s32 max; char pad[16]; } SpinnerTimer;
typedef struct SpinnerValue { s32 value; char pad[20]; } SpinnerValue;
extern char D_80145040[];
extern SpinnerTimer D_800E20A4_de[];
extern SpinnerValue D_800E63C0[];
extern s32 func_8022A5A0_de(char *, s32);
#ifdef NON_MATCHING
typedef struct SpinnerSetupMenu { char pad0[0xC]; char *object; char pad10[0xC]; s32 id; } SpinnerSetupMenu;
extern char D_8014641C_us_rev1[];
extern char *D_800D3C44;
int func_80446330_us_rev1(void *arg0) {
    SpinnerSetupMenu *menu = arg0;
    s32 index;
    s32 k;
    s32 selected;
    s32 trailing;
    s32 remaining;
    s32 i;
    char *src;
    char *ref;
    char *dst;
    u32 *flags;
    u8 a;
    u8 b;

    index = func_8022A5A0_de(D_80145040, menu->id);
    selected = (index >= 0 && index < 4) ? index : 0;
    for (k = 0; k < 4; k++) {
        flags = (u32 *)(menu->object + 0x30 + k * 0x28);
        if (k == selected) {
            *flags |= 0x1800000;
        } else {
            *flags &= 0xFE7FFFFF;
        }
    }
    D_800E20A4_de[index].timer = 0;
    dst = D_800E20AC + index * 24;
    src = D_8014641C_us_rev1 + index * 150;
    trailing = 0;
    i = 8;
    do {
        i--;
        if (src[i] != 0x20) {
            break;
        }
        trailing++;
    } while (i > 0);
    ref = D_800D3C44;
    i = 6;
    {
        char *p = src;
        do {
            b = *p++;
            a = *ref++;
            i--;
            if (b != a || b == 0) {
                break;
            }
        } while (i != 0);
        if (b == a) {
            trailing = 8;
        }
    }
    for (i = 0; i < 8 - trailing; i++) {
        *dst++ = *src++;
    }
    *dst = 0;
    D_800E63C0[index].value = 8 - trailing;
    D_800E20A4_de[index].max = 8 - trailing;
    return 8 - trailing;
}
#else
INCLUDE_ASM("ovl_80400000", func_80446330_us_rev1);
#endif
#endif

#if defined(VERSION_US_REV1)
extern f32 D_800E2810;
extern f32 D_800D2988;
s32 func_80445964_de(void *unused, MenuRecAt20V1 *menu) {
    s32 i;
    f32 t;

    i = func_8022A5A0_de(D_80145040, menu->id);
    t = D_800E20A4_de[i].timer + D_800D2988;
    D_800E20A4_de[i].timer = t;
    if (t >= D_800E2810) {
        D_800E20A4_de[i].timer = t - D_800E2810;
    }
    if (menu->state == 1) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E63C0[i].value > 0) {
            D_800E63C0[i].value--;
            D_800E20A4_de[i].timer = 0;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E63C0[i].value < D_800E20A4_de[i].max) {
                D_800E63C0[i].value++;
                D_800E20A4_de[i].timer = 0;
            }
        }
    }
    return 0;
}
#endif
