#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SESSIONHANDLERROW.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 Weapons_GetFirstPlayer(void *);

void func_80291074_de(void *object) {
    f32 time;
    f32 height;
    s32 line;
    if (D_80142898 != 0) {
        time = D_80142CB4 - D_800D2988;
        D_80142CB4 = time;
        if (time <= 0.0f) {
            Weapons_GetFirstPlayer(&D_80145040);
            if (D_800CD784_de != 0) {
                if (D_800CD780 == 0) {
                    func_802947C8_de(object, 0x7CF);
                    return;
                }
                goto advance;
            }
            if (D_800CD780 != 0) {
advance:
                Render_SetTransitionTarget(object, 1);
                D_801462C8.counters.m_bCreditsSeenOnce = 1;
            }
        }
    } else {
        if (D_800E28D4 >= 223) {
            D_80146CB8 -= D_800C53F0_de;
        } else {
            D_80146CB8 -= D_800C53F4_de;
        }
        height = (f32)D_800E28D4 * D_800C53F8_de;
        if (D_80146CB8 <= -height) {
            line = D_8011B9F0 + 1;
            D_8011B9F0 = line;
            D_80146CB8 += height;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            if (D_800D3E14_de[D_80152789][line] == 0) {
#else
            if (D_800D3E14_de[0][line] == 0) {
#endif
                D_80142898 = 1;
                D_80142CB4 = D_800C56AC_eu;
            }
        }
    }
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern int Weapons_GetFirstPlayer(void *arg0);


void func_80291074_de(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_v1;

    if (D_80142898 != 0) {
        temp_f0 = D_80142CB4 - D_800D2988;
        D_80142CB4 = temp_f0;
        if (temp_f0 <= 0.0f) {
            Weapons_GetFirstPlayer(&D_80145040);
            if (D_800CD784_de != 0) {
                if (D_800CD780 == 0) {
                    func_802947C8_de(arg0, 0x7CF);
                    return;
                }
                goto block_6;
            }
            if (D_800CD780 != 0) {
block_6:
                Render_SetTransitionTarget(arg0, 1);
                D_801462C8.counters.m_bCreditsSeenOnce = 1;
            }
        }
    } else {
        if (D_800E28D4 >= 0xDF) {
            D_80146CB8 -= D_800C53F0_de;
        } else {
            D_80146CB8 -= D_800C53F4_de;
        }
        temp_f1 = (f32)D_800E28D4 * D_800C53F8_de;
        if (D_80146CB8 <= -temp_f1) {
            temp_v1 = D_8011B9F0 + 1;
            D_8011B9F0 = temp_v1;
            D_80146CB8 += temp_f1;
            if (D_800D3E14_de[0][temp_v1] == 0) {
                D_80142898 = 1;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                D_80142CB4 = D_800C56AC_eu;
#else
                D_80142CB4 = D_800C53FC_de;
#endif
            }
        }
    }
}
#endif
