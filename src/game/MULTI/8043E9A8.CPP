#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "MULTI/8043E9A8.H"

extern void Pak_AllocateMenu(void *arg0, void *arg1, void *arg2);


/* Reads an object's sub-record kind byte and forwards it to two per-kind setup routines. */





extern void Render_EnableControllerPak(s32 kind);

extern void Pak_ProbeStatus(s32 kind);

/* Marks the selected record's byte tag and clears the active menu state. */
extern void Render_EnableControllerPak(int);

extern s32 D_800E28C0;

extern struct List D_0044EB04;

extern void Render_EnableControllerPak(int arg0);

/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, then reallocates a fresh scoreboard entry via Pak_OpenDialog using arg1's fields
   at 0x1C and 0x20 against the D_44F100 list, and always reports success. Sibling of
   func_8043E568_de, which also fires func_8025E214_de(-1) and uses the D_44F0B8 list instead. */



extern s32 D_0044E4B0;

void Pak_ClearTimerFlag(void);

extern void Render_DisableControllerPak(s32 arg0);

#include "COMMON/GAME_SESSION.H"


s32 func_8043E830_de(s32 *arg0) {
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
s32 func_8043E91C_de(void *unused0, void *arg1, void *arg2) {
    Pak_AllocateMenu(arg2, arg1, &D_0044FDF4);
    return 1;
}

void func_8043E948_de(struct Shared_PakMenu *arg0)
{
    s32 kind = arg0->owner->unk4;

    Render_EnableControllerPak(kind);
    Pak_ProbeStatus(kind);
}

void func_8043E97C_de(void *arg0) {
    Obj8043EB20 *item = arg0;

    Render_EnableControllerPak(item->unk20->unk4);
    D_800E28C0 = 0;
}

struct List;

struct Owner;
extern void *Pak_OpenDialog(void *owner, void *list, s32 b, s32 c, s32 d);
extern char D_8014561C[];

/** Marks arg1's inner record's byte tag via func_80264770_de, then hands the record and arg1's fields to Pak_OpenDialog; ignores arg0. */
s32 func_8043E9A8_de(void *unused0, Obj8043EB20 *arg1) {
    Render_EnableControllerPak(arg1->unk20->unk4);
    Pak_OpenDialog(D_8014561C, &D_0044EB04, arg1->unk1C, (s32) arg1->unk20, 0);
    return 1;
}

s32 func_8043EA00_de(void *unused0, Arg1Struct *arg1) {
    Pak_ClearTimerFlag();
    Pak_OpenDialog(D_8014561C, &D_0044E4B0, arg1->unk1C, arg1->unk20, 0);
    return 1;
}

/** Clears the D_8011FAC0 record and D_80154048, then re-registers the target through func_80264788_de. */
s32 func_8043EA4C_de(void *unused0, Outer8043E56C *arg1) {
    Render_SetTransitionTarget(&D_8011FAC0, 8);
    D_80154048 = 0;
    Render_DisableControllerPak(arg1->unk20->unk4);
    return 1;
}

#if defined(VERSION_US)
const unsigned int rodata_unresolved_800DD010[8] = {
    0x42F00000, 0x04000000, 0x16524158, 0x5F50555F, 0x437F0000, 0x437F0000, 0x437F0000, 0x65717552,
};
#endif
