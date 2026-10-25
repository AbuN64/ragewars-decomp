#include "include_asm.h"
#include "COMMON/PLAYERRECAT64E.H"
#include "MULTI/8043E9A8.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "MULTI/8043E9A8_4.H"
#include "SYSTEM_2/8025E280.H"

/* Starts a match from the menu: clears byte 0x1D and sets byte 0x1E of D_801462C8, clears the active byte 0x78 of its eight 150-byte status records, then gives the menu at 0x20 the first of the four 0x224-byte controller profiles of D_8010F328 that func_8026437C_de reports active, marking the settings D_80146302 at 0x78 and recording its index in D_801422C1, before calling func_8025E384_de, resetting D_8011FAC0 through func_8044DE7C_de and setting D_80154048. */

extern struct Part D_80146302;

extern struct ControllerProfile D_8010F328[4];

#include "COMMON/GAME_SESSION.H"

extern s32 D_80154048;

extern s32 func_8026437C_de(struct ControllerProfile *);

extern void func_8025E384_de(void);

extern void func_8044DE7C_de(char *, s32);

extern s32 func_80264690_de(void);

/* Sets the option bytes at 0x1D and 0x1E of D_801462C8 to 1 and 4, clears the first byte of each
   of the eight 150-byte player records at 0x148, then calls func_804427C4_de with the third argument,
   the second and the resource D_0044FEA8, and returns one. */

extern char D_0044FEA8[];

extern void func_804427C4_de(void *, void *, void *);

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451AF0,
   and returns one. */
extern char D_00450E9C[];

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4500F4,
   and returns one. */
extern char D_0044F4A4[];

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4503E8,
   and returns one. */
extern char D_0044F798[];

/* Restarts sound: calls func_8025E214_de with -1, records what func_8025E2C4_de returns in D_800E63B0,
   passes D_800E63B8 to func_8025E2D4_de, calls func_8025E29C_de with 1, clears D_800E63B4, calls
   func_802649FC_de and then func_804427C4_de with the third argument, the second and D_451F58.
   Returns one. */
extern s32 D_800E63B0;

extern s32 D_800E63B4;

extern s32 D_800E63B8;

extern char D_00451094[];

extern void func_802649FC_de();

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_450C18,
   and returns one. */
extern char D_0044FFEC[];
extern Shared_Game D_801462C8;

void Multi_SelectInitialController(void *unused0, struct ObjRecAt20V2 *menu) {
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
        if (func_8026437C_de(profile) != 0) {
            settings->active = 1;
            D_801462C8.defaults.slot = i;
            menu->unk20 = profile;
            break;
        }
    }
    func_8025E384_de();
    func_8044DE7C_de(&D_8011FAC0, -1);
    D_80154048 = 1;
}

/** Clears or sets bit 24 of arg1's record's flags depending on how many of func_80264690_de's four slots are active, and demotes arg1->unk0 from state 2 to 1 in the low-count case. */
s32 func_8043EB70_de(void *unused0, Obj8043ECE8 *arg1) {
    if (func_80264690_de() < 2) {
        arg1->unkC->unk58 &= 0xFEFFFFFF;
        if (arg1->unk0 == 2) {
            arg1->unk0 = 1;
        }
    } else {
        arg1->unkC->unk58 |= 0x01000000;
    }
    return 0;
}

s32 func_8043EBE4_de(void *first, void *second, void *third) {
    Shared_Game *options = &D_801462C8;
    s32 i;

    options->local = 1;
    options->mode1E = 4;
    for (i = 0; i < 8; i++) {
        options->playerSettings[i].enabled = 0;
    }
    func_804427C4_de(third, second, D_0044FEA8);
    return 1;
}

s32 func_8043EC40_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_00450E9C);
    return 1;
}

s32 func_8043EC6C_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044F4A4);
    return 1;
}

s32 func_8043EC98_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044F798);
    return 1;
}

s32 func_8043ECC4_de(void *first, void *second, void *third) {
    func_8025E214_de(-1);
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E29C_de(1);
    D_800E63B4 = 0;
    func_802649FC_de();
    func_804427C4_de(third, second, D_00451094);
    return 1;
}

/* Returns one. Nothing in the cartridge image calls it or stores its address as a word. */
s32 func_8043ED48_de(void) {
    return 1;
}

s32 func_8043ED50_de(void) {
    Render_SetTransitionTarget(&D_8011FAC0, 8);
    return 1;
}

s32 func_8043ED78_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_0044FFEC);
    return 1;
}
