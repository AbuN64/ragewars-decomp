#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "MULTI/804453C4.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
/* Steps a menu spinner for the entry func_8022A5A0_de finds in D_80145040: advances its repeat timer by D_800D2988, wrapping at D_800E2810, and while the menu is active (state 1) decrements its value above zero when func_80264388_de reports the decrease input, or else increments it below its maximum when func_802643A0_de reports the increase input, restarting the timer on a change. Returns zero. */




extern char D_80145040[];
extern Spinner D_800E63C0[];

extern s32 Weapons_GetPlayerIndex(char *, s32);



s32 func_80445964_de(void *unused, MenuRecAt20V1 *menu) {
    s32 i;
    f32 t;

    i = Weapons_GetPlayerIndex(D_80145040, menu->id);
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
const unsigned int rodata_func_80445964_de_800E2810[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_US_REV1)
extern char D_80145040[];
extern Spinner D_800E63C0[];
extern s32 Weapons_GetPlayerIndex(char *, s32);
extern u8 *D_800D3C44;
/* Highlights the name slot func_8022A5A0_de finds for the menu (display flags 0x1800000 on its model part,
   cleared on the other three), resets that spinner's timer and copies the slot's name (trailing blanks
   dropped, none when it starts like the default name) into the spinner; value and max = its length. */
void Multi_SetupNameSpinner(MenuRecAt20V1 *menu) {
    s32 index;
    s32 trailing;
    s32 i;
    u8 *source;
    u8 *defaultName;
    u8 *name;
    char *destination;
    u8 defaultChar;
    s32 nameChar;
    index = Weapons_GetPlayerIndex(D_80145040, menu->id);
    switch (index) {
        default:
        case 0:
            menu->model->part[0].flags |= 0x1800000;
            menu->model->part[1].flags &= ~0x1800000;
            menu->model->part[2].flags &= ~0x1800000;
            menu->model->part[3].flags &= ~0x1800000;
            break;
        case 1:
            menu->model->part[1].flags |= 0x1800000;
            menu->model->part[0].flags &= ~0x1800000;
            menu->model->part[2].flags &= ~0x1800000;
            menu->model->part[3].flags &= ~0x1800000;
            break;
        case 2:
            menu->model->part[2].flags |= 0x1800000;
            menu->model->part[0].flags &= ~0x1800000;
            menu->model->part[1].flags &= ~0x1800000;
            menu->model->part[3].flags &= ~0x1800000;
            break;
        case 3:
            menu->model->part[3].flags |= 0x1800000;
            menu->model->part[0].flags &= ~0x1800000;
            menu->model->part[1].flags &= ~0x1800000;
            menu->model->part[2].flags &= ~0x1800000;
            break;
    }
    D_800E63C0[index].timer = 0;
    destination = D_800E63C0[index].name;
    source = D_801462C8.playerSettings[index].name;
    i = 8;
    trailing = 0;
    while (i > 0) {
        i--;
        if (source[i] != ' ') {
            break;
        }
        trailing++;
    }
    name = source;
    defaultName = D_800D3C44;
    i = 6;
    do {
        nameChar = *name++;
        defaultChar = *defaultName++;
        i--;
        if ((u8)nameChar != defaultChar || (u8)nameChar == 0) {
            break;
        }
    } while (i == 0);
    /* The ROM loops only while the count is 0, so this compares the first character. */
    if (nameChar == defaultChar) {
        trailing = 8;
    }
    for (i = 0; i < 8 - trailing; i++) {
        *destination++ = *source++;
    }
    *destination = 0;
    D_800E63C0[index].value = 8 - trailing;
    D_800E63C0[index].max = 8 - trailing;
}
#endif

#if defined(VERSION_US_REV1)
extern f32 D_800E2810;
s32 func_80445964_de(void *unused, MenuRecAt20V1 *menu) {
    s32 i;
    f32 t;

    i = Weapons_GetPlayerIndex(D_80145040, menu->id);
    t = D_800E63C0[i].timer + D_800D2988;
    D_800E63C0[i].timer = t;
    if (t >= D_800E2810) {
        D_800E63C0[i].timer = t - D_800E2810;
    }
    if (menu->state == 1) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E63C0[i].value > 0) {
            D_800E63C0[i].value--;
            D_800E63C0[i].timer = 0;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E63C0[i].value < D_800E63C0[i].max) {
                D_800E63C0[i].value++;
                D_800E63C0[i].timer = 0;
            }
        }
    }
    return 0;
}
#endif
