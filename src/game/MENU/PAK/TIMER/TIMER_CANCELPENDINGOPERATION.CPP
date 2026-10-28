#include "include_asm.h"
#include "COMMON/MENURECAT24.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/RECORDRECAT1C.H"
#include "MENU/PAK_PROFILE_PROMPT_VIEWS.H"
#include "COMMON/EXTERNS_20.H"
#include "stddef.h"
#include "TYPES.H"
#include "MENU/PAK/TIMER_CANCELPENDINGOPERATION.H"

extern s32 D_8015375C;

extern s32 Snapshot_CheckStatusPrompt(MenuPakBeginProfileLoad *, s32, s32);

extern void *Menu_OpenDialog(struct func_8025E5B0_S1 *, struct Dialog *, s32, s32, s32);

static __inline__ void pakShow(MenuPakBeginProfileLoad *menu) {
    s32 channel;
    if (D_8015375C) channel = D_800E28C8;
    else channel = menu->slot->unk4;
    if (Snapshot_CheckStatusPrompt(menu, channel, 1)) {
        D_80153784 = 1;
        Menu_OpenDialog(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
    } else {
        Menu_OpenDialog(&D_80145040.dialogOwner, menu->prompt, (s32)menu->player, (s32)menu->slot, 0);
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

static __inline__ void *menuPrompt(MenuPakBeginProfileLoad *menu) {
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
void Note_ProbeStatus(s32);

 /* extern */
s32 Note_GetStatus(s32);

/* Clears the word held in D_800E28C0. */
extern s32 D_800E28C0;

/* Dialog resources are opaque ROM addresses. The list-builder ABI carries
 * player, slot, and optional formatting data as three raw 32-bit words. */
s32 Timer_CancelPendingOperation(void *unused, MenuPakBeginProfileLoad *menu) {
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
        Menu_OpenDialog(owner, prompt, (s32)menu->player, (s32)menu->slot, 0);
        return 1;
    default: return 1;
    }
    Menu_OpenDialog(owner, prompt, (s32)player, (s32)slot, 0);
    return 1;
}

 /* extern */
void Timer_SelectAvailableChannel(void) {
    s32 channel;
    s32 attempts;
    s32 unavailable;
    if (D_800E28C8 == -1) {
        channel = 0;
        attempts = 0;
    unavailable = -2;
loop_2:
        Note_ProbeStatus(channel);
        if (Note_GetStatus(channel) == unavailable) {
            channel += 1;
            if (channel >= 4) {
                channel = 0;
            }
            attempts += 1;
            if (attempts < 4) {
                goto loop_2;
            }
        }
        if (attempts == 4) {
            channel = -1;
        }
        D_800E28C8 = channel;
    }
}

/* Returns whether D_800E28C8 holds anything other than -1. */
s32 Timer_HasSelectedChannel(void) {
    return D_800E28C8 != -1;
}

void Timer_ClearTimerFlag(void) {
    D_800E28C0 = 0;
}

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DBA84[17] = {
    0x00000000, 0x0040A988, 0x0040A988, 0x0040A9B8, 0x0040A9A8, 0x0040A988, 0x0040A998, 0x0040A988,
    0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A988, 0x0040A9C8,
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
