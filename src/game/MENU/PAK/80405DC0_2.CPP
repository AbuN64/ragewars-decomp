#include "include_asm.h"
#include "COMMON/MENURECAT24.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/RECORDRECAT1C.H"
#include "MENU/80405DC0.H"
#include "COMMON/EXTERNS_20.H"
#include "stddef.h"
#include "TYPES.H"
#include "MENU/PAK/80405DC0_2.H"

extern s32 D_8015375C;

extern s32 func_80406178_de(Menu_func_804066BC_de *, s32, s32);

extern void *func_80442574_de(struct func_8025E5B0_S1 *, struct Dialog *, s32, s32, s32);

static __inline__ void pakShow(Menu_func_804066BC_de *menu) {
    s32 channel;
    if (D_8015375C) channel = D_800E28C8;
    else channel = menu->slot->unk4;
    if (func_80406178_de(menu, channel, 1)) {
        D_80153784 = 1;
        func_80442574_de(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
    } else {
        func_80442574_de(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
    }
}

static __inline__ void *pakPrompt(s32 *channel) {
    char *result;
    switch (*channel) {
    case 0:
    default: result = D_00450BF0_de; break;
    case 1: result = D_00450C14_de; break;
    case 2: result = D_00450C38_de; break;
    case 3: result = D_00450C5C_de; break;
    }
    return result;
}

static __inline__ void *menuPrompt(Menu_func_804066BC_de *menu) {
    s32 channel;
    void *prompt;
        prompt = 0;
        if (D_8014D4C0_de) {
            if (D_8014D4EC_de) {
                channel = menu->slot->unk4;
                prompt = pakPrompt(&channel);
            }
        } else if (D_80153760) {
            prompt = D_0044FFA4;
            if (D_8014D4EC_de) prompt = D_0044FB50;
        }
    return prompt;
}

/* Finds the first available controller slot and caches its index. */
void func_80404E28_de(s32);

 /* extern */
s32 func_80404F04_de(s32);

/* Clears the word held in D_800E28C0. */
extern s32 D_800E28C0;

/* Dialog resources are opaque ROM addresses. The list-builder ABI carries
 * player, slot, and optional formatting data as three raw 32-bit words. */
s32 func_80409448_de(void *unused, Menu_func_804066BC_de *menu) {
    s32 channel;
    void *prompt;
    void *owner;
    ObjRecAt5DC *player;
    PakMenuSlot *slot;
    switch (D_80153778) {
    case 4: pakShow(menu); return 1;
    case 3: pakShow(menu); return 1;
    case 0: pakShow(menu); return 1;
    case 1:
    case 2:
        D_80153784 = 1;
        D_8014D480 = 0;
        if (D_8015375C) {
            D_8014ADA0 = 1;
            return 1;
        }
        prompt = menuPrompt(menu);
        if (!prompt) prompt = menu->prompt;
        if (menu->player) owner = menu->player->unk5DC + 0x554;
        else owner = &D_80145040.dialogOwner;
        func_80442574_de(owner, prompt, (s32)menu->player, (s32)menu->slot, 0);
        return 1;
    default: return 1;
    }
    func_80442574_de(owner, prompt, (s32)player, (s32)slot, 0);
    return 1;
}

 /* extern */
void func_80409744_de(void) {
    s32 var_s0;
    s32 var_s1;
    s32 unavailable;
    if (D_800E28C8 == -1) {
        var_s0 = 0;
        var_s1 = 0;
    unavailable = -2;
loop_2:
        func_80404E28_de(var_s0);
        if (func_80404F04_de(var_s0) == unavailable) {
            var_s0 += 1;
            if (var_s0 >= 4) {
                var_s0 = 0;
            }
            var_s1 += 1;
            if (var_s1 < 4) {
                goto loop_2;
            }
        }
        if (var_s1 == 4) {
            var_s0 = -1;
        }
        D_800E28C8 = var_s0;
    }
}

/* Returns whether D_800E28C8 holds anything other than -1. */
s32 func_804097D4_de(void) {
    return D_800E28C8 != -1;
}

void func_804097E8_de(void) {
    D_800E28C0 = 0;
}

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DBA84[17] = {
    0x00000000, 0x0040A988, 0x0040A988, 0x0040A9B8, 0x0040A9A8, 0x0040A988, 0x0040A998, 0x0040A988,
    0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A9C8,
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8614[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_unresolved_800ED454[17] = {
    0x00000000, 0x0040ACC8, 0x0040ACC8, 0x0040AD28, 0x0040AD08, 0x0040ACC8, 0x0040ACE8, 0x0040ACC8,
    0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040ACC8, 0x0040AD48,
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DCDD4[1] = {
    0x00000000,
};
#endif
