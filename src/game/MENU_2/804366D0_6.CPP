#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/SCREEN.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
extern StyleNextState *D_800E5694;
#include "MENU_2/804366D0_3.H"
#include "MENU_2/804366D0_6.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E5694 holds through func_802547E4_de, clears D_800E5694 and returns zero. */



/* Calls MarkMenuEventHandled; when func_80299A08_de reports 0x1C8, passes the word at offset 0x14 of the
   object D_800E5694 points to to func_804369E8_de, then passes -1 to func_8042E988_de if func_802999A0_de
   reports 0x16 for zero and 0xB otherwise, and calls func_802998A8_de. Returns zero. */





/* Calls MarkMenuEventHandled, then passes -1 to func_8042E988_de when func_802999A0_de reports 0x16 for zero
   and 0xB otherwise, then calls func_802998A8_de. Returns zero. */
extern void MarkMenuEventHandled();


void MarkMenuEventHandled();

                                  /* extern */
s32 func_802A0C08_de(void *, s32, ...);

                  /* extern */

                               /* extern */

                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
#else
#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5710, an actor kind at D_800E5714 and a handler at D_800E5718: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80437454)(void *, s32, s32, s32, s32);



extern Handler80437454 D_800E5718;

s32 func_8043701C_de(void) {
    func_802547E4_de(D_800E5694);
    D_800E5694 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8043704C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80437054_de(void) {
    return 0;
}

s32 func_8043705C_de(void) {
    MarkMenuEventHandled();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x1C4) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x1C8) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x1CC) {
#endif
        func_804369E8_de(D_800E5694->item);
        func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
        func_802998A8_de();
    }
    return 0;
}

s32 func_804370CC_de(void) {
    MarkMenuEventHandled();
    func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
    func_802998A8_de();
    return 0;
}

s32 func_80437114_de(s32 unused0, s32 unused1, s32 unused2, s32 arg3) {
    s32 temp_v0;

    MarkMenuEventHandled();
    if (arg3 == 1) {
        func_804369E8_de(D_800E5694->item);
        temp_v0 = D_800E5694->item + 1;
        D_800E5694->item = temp_v0;
        if (temp_v0 >= 4) {
            D_800E5694->item = 0;
        }
        func_804368F8_de(D_800E5694->item);
        func_802A0C08_de(D_800E5694->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5694->item + 1);
        D_800E5694->label->text = (void *) (D_800E5694->text);
        return 0;
    }
    return 0;
}

s32 func_804371C4_de(s32 unused0, s32 unused1, s32 unused2, s32 arg3) {
    s32 temp_v0;

    MarkMenuEventHandled();
    if (arg3 == 1) {
        func_804369E8_de(D_800E5694->item);
        temp_v0 = D_800E5694->item - 1;
        D_800E5694->item = temp_v0;
        if (temp_v0 < 0) {
            D_800E5694->item = 3;
        }
        func_804368F8_de(D_800E5694->item);
        func_802A0C08_de(D_800E5694->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5694->item + 1);
        D_800E5694->label->text = (void *) (D_800E5694->text);
        return 0;
    }
    return 0;
}

s32 func_80437274_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80437454 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5718 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5718;
        index = 0;
        do {
            if (D_800E5710[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5714[index].value;
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

#if defined(VERSION_EU_X)
unsigned int func_80437304_de_padding_12826C[1] = {
    0xAC6201C0,
};
#endif
