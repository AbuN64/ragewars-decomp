#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405DC0.h"
#include "types.h"




























/* Releases temporary profile buffers and opens the controller-pak prompt for the selected player and channel, labelling the port prompt by channel. */







extern char D_0044E4F8[];
extern char D_0044FB2C[];
extern char D_0044FFA4[];
extern char D_00450BF0_de[];
extern char D_00450C14_de[];
extern char D_00450C38_de[];
extern char D_00450C5C_de[];
extern char D_80145040[];
extern char D_8014561C[];



extern s32 D_8014ADA0;
extern s32 D_8014D480;

extern s32 D_8015375C;



extern void *D_800DE860_de;
extern struct Shape_typemap_165 *D_800DE864_de;
extern s32 D_800DE868;
extern s32 D_800E28BC;

extern SharedPlayer_func_8022A398_de *func_8022A5C0_de(void *profiles, PakMenuSlot *slot);
extern void func_80253838_de(void *heap, void *block);
extern void func_80253908_de(s32 heap);
extern void func_80442574_de(void *buffer, char *message, SharedPlayer_func_8022A398_de *player, char *title, s32 channel);

static inline void get_channel(MenuRecAt20V3 *menu, s32 *channel) {
    if (D_8015375C != 0) {
        *channel = D_800E28C8;
    } else {
        *channel = menu->slot->unk4;
    }
}

s32 func_804085E0_de(void *unused, MenuRecAt20V3 *menu) {
    s32 channel;
    char *label;
    s8 port;
    SharedPlayer_func_8022A398_de *target;
    SharedPlayer_func_8022A398_de *player;

    if (D_800DE860_de != 0 || D_800DE864_de != 0) {
        func_80253908_de(0);
    }
    if (D_800DE860_de != 0) {
        func_80253838_de(0, D_800DE860_de);
    }
    if (D_800DE864_de != 0) {
        func_80253838_de(0, D_800DE864_de);
    }
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
    D_8014D480 = 0;
    get_channel(menu, &channel);
    if (D_8015375C != 0) {
        D_8014ADA0 = 0;
        D_80146D60 = 0;
        D_8014AD9C = 1;
        D_80142CAC = 0;
        func_80442574_de(D_8014561C, D_0044E4F8, 0, (char *)menu->slot, 0);
        return 1;
    }
    if (D_8014D4EC_de != 0) {
        if (D_80153760 != 0) {
            D_80153784 = 1;
            target = func_8022A5C0_de(D_80145040, menu->slot);
            func_80442574_de(target->views5DC.view5DC_6.storage + 0x554, D_0044FB2C, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
        if (D_8014D4C0_de != 0) {
            D_80153784 = 1;
            port = menu->slot->unk4;
            player = menu->player;
            channel = port;
            target = player;
            switch (channel) {
            default:
            case 0:
                label = D_00450BF0_de;
                break;
            case 1:
                label = D_00450C14_de;
                break;
            case 2:
                label = D_00450C38_de;
                break;
            case 3:
                label = D_00450C5C_de;
                break;
            }
            func_80442574_de(target->views5DC.view5DC_6.storage + 0x554, label, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
    } else {
        target = func_8022A5C0_de(D_80145040, menu->slot);
        if (D_80153760 != 0) {
            D_80153784 = 1;
            func_80442574_de(D_80145040 + 0x5DC, D_0044FFA4, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
        if (D_8014D4C0_de != 0) {
            D_80153784 = 1;
            return 1;
        }
    }
    return 0;
}
