#include "types.h"

typedef struct { char pad0[4]; s8 channel; } PakSlot;
typedef struct { char pad0[0x554]; char prompt[1]; } PakPlayerData;
typedef struct { char pad0[0x5DC]; PakPlayerData *data; } PakPlayer;
typedef struct { char pad0[0x1C]; PakPlayer *player; PakSlot *slot; char *prompt; } PakMenu;
extern s32 D_80153778, D_8015375C, D_80153784, D_8014D480, D_8014ADA0, D_8014D4C0_de, D_8014D4EC_de, D_80153760, D_800E28C8;
extern char D_8014561C[], D_0044FFA4[], D_0044FB50[], D_00450BF0_de[], D_00450C14_de[], D_00450C38_de[], D_00450C5C_de[];
extern s32 func_80406178_de(PakMenu *, s32, s32);
extern void func_80442574_de(void *, char *, PakPlayer *, PakSlot *, s32);

s32 func_80409448_de(void *unused, PakMenu *menu) {
    s32 channel;
    char *prompt;
    void *owner;
    switch (D_80153778) {
    case 0:
        channel = D_800E28C8;
        if (D_8015375C == 0) channel = menu->slot->channel;
        if (func_80406178_de(menu, channel, 1)) D_80153784 = 1;
        owner = D_8014561C;
        prompt = menu->prompt;
        break;
    case 1:
    case 2:
        D_80153784 = 1;
        D_8014D480 = 0;
        if (D_8015375C) {
            D_8014ADA0 = 1;
            D_8014D480 = 0;
            D_80153784 = 1;
            return 1;
        }
        prompt = 0;
        if (D_8014D4C0_de == 0) {
            if (D_80153760) { prompt = D_0044FFA4; if (D_8014D4EC_de) prompt = D_0044FB50; }
        } else if (D_8014D4EC_de) {
            switch (menu->slot->channel) {
            case 1: prompt = D_00450C14_de; break;
            case 2: prompt = D_00450C38_de; break;
            case 3: prompt = D_00450C5C_de; break;
            default: prompt = D_00450BF0_de; break;
            }
        }
        if (prompt == 0) prompt = menu->prompt;
        if (menu->player == 0) owner = D_8014561C;
        else owner = menu->player->data->prompt;
        break;
    case 3:
        channel = D_800E28C8;
        if (D_8015375C == 0) channel = menu->slot->channel;
        if (func_80406178_de(menu, channel, 1)) D_80153784 = 1;
        owner = D_8014561C;
        prompt = menu->prompt;
        break;
    case 4:
        channel = D_800E28C8;
        if (D_8015375C == 0) channel = menu->slot->channel;
        if (func_80406178_de(menu, channel, 1)) D_80153784 = 1;
        owner = D_8014561C;
        prompt = menu->prompt;
        break;
    default: return 1;
    }
    func_80442574_de(owner, prompt, menu->player, menu->slot, 0);
    return 1;
}
