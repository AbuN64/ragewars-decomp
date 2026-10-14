#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405DC0.h"
/* Confirms the pak menu prompt for state D_80153778: in states 4, 3 and 0 it rechecks the selected
   channel's pak through func_80406178_de (marking the menu busy and showing the menu prompt when that
   reports a problem), then refreshes the pak and deletes note D_8014D4C4 (state 4, showing the
   D_0044EB70 or D_0044EBDC result), deletes note D_8014D4FC and saves through func_80407578_de (state 3,
   showing D_0044EBDC on failure) or repairs the pak through func_804051D4_de (state 0, showing D_0044EB94
   or D_0044ED20); in states 1 and 2 it flags D_80142CAC in the pak manager and shows the menu
   prompt. Returns 1. Written as a plain switch whose jump table the build places. */
#include "types.h"





extern s32 D_80153778;
extern s32 D_8015375C;


extern s32 D_8014D4C4;






extern char D_8014561C[];


extern char D_0044EB94[];


extern char D_0044ED20[];

extern s32 func_80406178_de(Menu_func_80409144_de *menu, s32 ch, s32 quiet);
extern void func_80404E28_de(s32 ch);
extern s32 func_80404858_de(s32 ch, s32 index);
extern s32 func_804051D4_de(s32 ch);
extern s32 func_80407578_de(void *owner, Menu_func_80409144_de *menu, void *arg);
extern void func_80442574_de(char *, char *, void *, func_80242278_S1 *, char *);

s32 func_80409144_de(void *owner, Menu_func_80409144_de *menu, void *arg) {
    s32 ch;

    switch (D_80153778) {
        case 4:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (func_80406178_de(menu, ch, 1) != 0) {
                D_80153784 = 1;
                func_80442574_de(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            func_80404E28_de(ch);
            if (func_80404858_de(ch, D_8014D4C4) == 0) {
                func_80442574_de(D_8014561C, D_0044EB70, menu->player, menu->slot, menu->prompt);
            } else {
                func_80442574_de(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
            }
            break;
        case 3:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (func_80406178_de(menu, ch, 1) != 0) {
                D_80153784 = 1;
                func_80442574_de(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            func_80404E28_de(ch);
            if (func_80404858_de(ch, D_8014D4FC) == 0) {
                func_80407578_de(owner, menu, arg);
                return 1;
            }
            func_80442574_de(D_8014561C, D_0044EBDC, menu->player, menu->slot, menu->prompt);
            break;
        case 0:
            if (D_8015375C != 0) {
                ch = D_800E28C8;
            } else {
                ch = menu->slot->unk4;
            }
            if (func_80406178_de(menu, ch, 1) != 0) {
                D_80153784 = 1;
                func_80442574_de(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
                break;
            }
            func_80404E28_de(ch);
            if (func_804051D4_de(ch) == 0) {
                func_80442574_de(D_8014561C, D_0044EB94, menu->player, menu->slot, menu->prompt);
            } else {
                func_80442574_de(D_8014561C, D_0044ED20, menu->player, menu->slot, menu->prompt);
            }
            break;
        case 1:
        case 2:
            if (D_8015375C != 0) {
                D_80142CAC = 1;
            }
            func_80442574_de(D_8014561C, menu->prompt, menu->player, menu->slot, 0);
            break;
    }
    return 1;
}
