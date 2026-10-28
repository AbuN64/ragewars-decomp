#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "MULTI/INITIAL.H"
#include "COMMON/AIPROFILE.H"
#include "SYSTEM/8025E280.H"

struct func_8025E5B0_S1;
struct ParamsPakAllocateMenu;
struct Dialog;
extern void *Menu_AllocateMenu(struct func_8025E5B0_S1 *owner, struct ParamsPakAllocateMenu *params, struct Dialog *list);


/* Reads an object's sub-record kind byte and forwards it to two per-kind setup routines. */





extern void Control_EnableControllerPak(s32 kind);

extern void Note_ProbeStatus(s32 kind);

/* Marks the selected record's byte tag and clears the active menu state. */
extern void Control_EnableControllerPak(int);

extern s32 D_800E28C0;

extern struct List D_0044EB04;

extern void Control_EnableControllerPak(int arg0);

/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, then reallocates a fresh scoreboard entry via Menu_OpenDialog using arg1's fields
   at 0x1C and 0x20 against the D_44F100 list, and always reports success. Sibling of
   CMenuProfile_OpenTimedPlayerDialog, which also fires func_8025E214_de(-1) and uses the D_44F0B8 list instead. */



extern s32 D_0044E4B0;

void Timer_ClearTimerFlag(void);

extern void Control_DisableControllerPak(s32 arg0);

#include "COMMON/GAME_SESSION.H"


s32 Initial_ToggleMenuRowOption(s32 *arg0) {
    Shared_Game *base;

    switch (arg0[0]) {
        case 2:
            base = &D_801462C8;
            base->unknown28[5] ^= 1;
            break;
        case 3:
            base = &D_801462C8;
            base->unknown28[6] ^= 1;
            break;
        case 4:
            base = &D_801462C8;
            base->unknown28[7] ^= 1;
            break;
        case 5:
            base = &D_801462C8;
            base->unknown28[8] ^= 1;
            break;
        case 6:
            base = &D_801462C8;
            base->unknown28[9] ^= 1;
            break;
        case 7:
            base = &D_801462C8;
            base->unknown28[10] ^= 1;
            break;
        case 8:
            base = &D_801462C8;
            base->unknown28[11] ^= 1;
            break;
        case 9:
            base = &D_801462C8;
            base->unknown28[13] ^= 1;
            break;
    }
    return 0;
}

/** Forwards arg1 through and arg2 as the first parameter, adding the D_450A20 record. */
s32 func_8043E91C_de(void *unused0, void *menuOwner, void *menuContext) {
    Menu_AllocateMenu(menuContext, menuOwner, &D_0044FDF4);
    return 1;
}

void Initial_ProbeMenuControllerPak(struct Shared_PakMenu *arg0)
{
    s32 kind = arg0->owner->unk4;

    Control_EnableControllerPak(kind);
    Note_ProbeStatus(kind);
}

void Initial_EnableMenuControllerPak(void *arg0) {
    Obj8043EB20 *item = arg0;

    Control_EnableControllerPak(item->unk20->unk4);
    D_800E28C0 = 0;
}

struct List;

extern void *Menu_OpenDialog(void *owner, void *list, s32 b, s32 c, s32 d);
extern char D_8014561C[];

/** Marks arg1's inner record's byte tag via func_80264770_de, then hands the record and arg1's fields to Menu_OpenDialog; ignores arg0. */
s32 Initial_OpenDialogWithControllerPak(void *unused0, Obj8043EB20 *arg1) {
    Control_EnableControllerPak(arg1->unk20->unk4);
    Menu_OpenDialog(D_8014561C, &D_0044EB04, arg1->unk1C, (s32) arg1->unk20, 0);
    return 1;
}

s32 Initial_OpenDialogAfterTimerReset(void *unused0, Arg1Struct *arg1) {
    Timer_ClearTimerFlag();
    Menu_OpenDialog(D_8014561C, &D_0044E4B0, arg1->unk1C, arg1->unk20, 0);
    return 1;
}

/** Clears the D_8011FAC0 record and D_80154048, then re-registers the target through func_80264788_de. */
s32 Initial_RequestTransitionWithPakDisabled(void *unused0, Outer8043E56C *arg1) {
    SetN64_SetTransitionTarget(&D_8011FAC0, 8);
    D_80154048 = 0;
    Control_DisableControllerPak(arg1->unk20->unk4);
    return 1;
}

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DD010[8] = {
    0x42F00000, 0x04000000, 0x16524158, 0x5F50555F, 0x437F0000, 0x437F0000, 0x437F0000, 0x65717552,
};
#endif

/* Starts a match from the menu: clears byte 0x1D and sets byte 0x1E of D_801462C8, clears the active byte 0x78 of its eight 150-byte status records, then gives the menu at 0x20 the first of the four 0x224-byte controller profiles of D_8010F328 that func_8026437C_de reports active, marking the settings D_80146302 at 0x78 and recording its index in D_801422C1, before calling func_8025E384_de, resetting D_8011FAC0 through func_8044DE7C_de and setting D_80154048. */

extern struct Part D_80146302;

extern struct ControllerProfile D_8010F328[4];

#include "COMMON/GAME_SESSION.H"


extern s32 Control_IsAButtonPressed(struct ControllerProfile *);


extern void Match_StartMatchTransition(GameSession *, s32);

extern s32 Control_CountConnectedControllers(void);

/* Sets the option bytes at 0x1D and 0x1E of D_801462C8 to 1 and 4, clears the first byte of each
   of the eight 150-byte player records at 0x148, then calls Menu_AllocateMenu with the third argument,
   the second and the resource D_0044FEA8, and returns one. */


struct func_8025E5B0_S1;
struct ParamsPakAllocateMenu;
struct Dialog;

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_451AF0,
   and returns one. */

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_4500F4,
   and returns one. */

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_4503E8,
   and returns one. */

/* Restarts sound: calls func_8025E214_de with -1, records what func_8025E2C4_de returns in D_800E63B0,
   passes D_800E63B8 to func_8025E2D4_de, calls func_8025E29C_de with 1, clears D_800E63B4, calls
   Control_ClearMenuControlFlag and then Menu_AllocateMenu with the third argument, the second and D_451F58.
   Returns one. */




extern void Control_ClearMenuControlFlag();

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_450C18,
   and returns one. */

void Initial_SelectInitialController(void *unused0, struct ObjRecAt20V2 *menu) {
    Shared_Game *globals;
    struct Part *settings;
    struct ControllerProfile *profile;
    s32 i;

    globals = &D_801462C8;
    globals->local = 0;
    globals->mode1E = 1;
    for (i = 7; i >= 0; i--) {
        globals->playerSettings[i].enabled = 0;
    }
    i = 0;
    settings = &D_80146302;
    for (; i < 4; i++) {
        profile = &D_8010F328[i];
        if (Control_IsAButtonPressed(profile) != 0) {
            settings->active = 1;
            D_801462C8.defaults.slot = i;
            menu->unk20 = profile;
            break;
        }
    }
    func_8025E384_de();
    Match_StartMatchTransition(&D_8011FAC0, -1);
    D_80154048 = 1;
}

/** Clears or sets bit 24 of arg1's record's flags depending on how many of func_80264690_de's four slots are active, and demotes arg1->unk0 from state 2 to 1 in the low-count case. */
s32 Initial_UpdateMultiplayerAvailability(void *unused0, Obj8043ECE8 *arg1) {
    if (Control_CountConnectedControllers() < 2) {
        arg1->unkC->unk58 &= 0xFEFFFFFF;
        if (arg1->unk0 == 2) {
            arg1->unk0 = 1;
        }
    } else {
        arg1->unkC->unk58 |= 0x01000000;
    }
    return 0;
}

s32 Initial_OpenLocalPlayerSetup(void *first, void *second, void *third) {
    Shared_Game *options = &D_801462C8;
    s32 i;

    options->local = 1;
    options->mode1E = 4;
    for (i = 0; i < 8; i++) {
        options->playerSettings[i].enabled = 0;
    }
    Menu_AllocateMenu(third, second, D_0044FEA8);
    return 1;
}

s32 func_8043EC40_de(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_00450E9C);
    return 1;
}

s32 func_8043EC6C_de(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_0044F4A4);
    return 1;
}

s32 func_8043EC98_de(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_0044F798);
    return 1;
}

s32 Initial_OpenTrackPreviewMenu(void *first, void *second, void *third) {
    func_8025E214_de(-1);
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E29C_de(1);
    D_800E63B4 = 0;
    Control_ClearMenuControlFlag();
    Menu_AllocateMenu(third, second, D_00451094);
    return 1;
}

/* Returns one. Nothing in the cartridge image calls it or stores its address as a word. */
s32 func_8043ED48_de(void) {
    return 1;
}

s32 Initial_RequestSessionTransition(void) {
    SetN64_SetTransitionTarget(&D_8011FAC0, 8);
    return 1;
}

s32 func_8043ED78_de(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_0044FFEC);
    return 1;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"

typedef struct FlagOwnerMultiResetPlayerGameOverTimer {
    char pad0[0x30];
    u32 flags;
} FlagOwnerMultiResetPlayerGameOverTimer;

typedef struct HolderMultiResetPlayerGameOverTimer {
    char pad0[0xC];
    FlagOwnerMultiResetPlayerGameOverTimer *owner;
} HolderMultiResetPlayerGameOverTimer;

void Initial_ResetPlayerGameOverTimer(HolderMultiResetPlayerGameOverTimer *arg0) {
    D_801462C8.counters.m_GameOverTimer = 120.0f;
    arg0->owner->flags &= 0xFBFFFFFF;
}
#else
INCLUDE_ASM("ovl_80400000", Initial_ResetPlayerGameOverTimer);
#endif
#endif
