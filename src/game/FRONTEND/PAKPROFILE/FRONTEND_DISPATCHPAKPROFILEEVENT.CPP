#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/FRONTEND_SETPLAYERPROFILELINK.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "FRONTEND/FRONTEND_DISPATCHPAKPROFILEEVENT.H"
#include "COMMON/UNUSED.H"

/* 8042E080_64.CPP */
/* Fills entry i of the 12-byte records at offset 0x2DF8 of the object D_800E54A4 points to with
   two values and marks it set. */

void Frontend_SetPlayerProfileLink(s32 first, s32 second, s32 index) {
    D_800E54A4->links[index].player = first;
    D_800E54A4->links[index].entry = second;
    D_800E54A4->links[index].state = 1;
}

/* 8042E080_65.CPP */
/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_ReturnProfileEventZero(void) {
    return 0;
}

/* 8042E080_66.CPP */
/* Releases the object D_800E54A4 holds through Cache_FreeMemory, clears D_800E54A4, calls
   Tsmos_ActivateControllerState and Tsmos_SetTimerState with 1, and returns zero. */
extern void Tsmos_ActivateControllerState(void);
extern void Tsmos_SetTimerState(s32);

s32 Frontend_DestroyPakProfileScreen(void) {
    Cache_FreeMemory(D_800E54A4);
    D_800E54A4 = 0;
    Tsmos_ActivateControllerState();
    Tsmos_SetTimerState(1);
    return 0;
}

/* 8042E080_67.CPP */
/* Handles a packed message for a player in D_800E54A4: when the player (low half) is in state 12, the
   message type (high half) is 3 and the argument is 4 or 5, moves the player to phase 2 with a zero
   timer; always returns 0. */

int Frontend_ResetNameRepeatOnEvent(int unused0, int unused1, unsigned int message, int arg) {
    PlayerRecAtBA4 *p = (PlayerRecAtBA4 *)((char *)D_800E54A4 + (message & 0xFFFF) * 0xB68);

    if (p->state == 12 && (message >> 16) == 3 && arg < 6 && arg >= 4) {
        p->timer = 0;
        p->phase = 2;
    }
    return 0;
}

/* 8042E080_68.CPP */
#if !(defined(VERSION_US))
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E54A8, an actor kind at D_800E54AC and a handler at D_800E54B0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80435C54)(void *, s32, s32, s32, s32);

extern FieldRow D_800E54A8[];
extern Handler80435C54 D_800E54B0;

s32 Frontend_DispatchPakProfileEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80435C54 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E54B0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E54B0;
        index = 0;
        do {
            if (D_800E54A8[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E54AC[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}
#endif
