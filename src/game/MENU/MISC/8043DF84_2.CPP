#include "COMMON/SHARED_GAMESLOT.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MENU/MISC/8043DF84_2.H"
#include "SYSTEM_3/80265370.H"

/** Always returns 0. */
s32 func_8043E5D0_de(void) {
    return 0;
}

/* Returns 1 if any of D_801468A0's unk1C, unk20 or unk28 fields is nonzero, otherwise 0. */




s32 func_8043E5D8_de(void) {
    CGameStatus *s = &D_801462C8.counters;
    s32 result;

    result = 0;
    if ((s->round != 0) || (s->elapsed != 0) || (s->state != 0)) {
        result = 1;
    }
    return result;
}

/* Clears arg1->unk1C's unk858 flag and its unk5D8's unk80, then forwards to Pak_OpenDialog. */

extern void Pak_OpenDialog(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4);
extern s32 D_0044FB2C;







s32 func_8043E610_de(void *unused0, Handle8043E788 *arg1) {
    Obj1C *temp_a2;

    temp_a2 = arg1->unk1C;
    temp_a2->unk858 = 0;
    temp_a2->unk5D8->unk80 = 0;
    Pak_OpenDialog(temp_a2->unk5DC + 0x554, &D_0044FB2C, temp_a2, temp_a2->unk698, temp_a2->unk5D4);
    return 1;
}

/* Sets arg1->unk1C's unk858 flag and clears its unk5D8's unk80, then forwards to Pak_OpenDialog. */

extern void Pak_OpenDialog(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4);
extern s32 D_0044FB2C;







s32 func_8043E658_de(void *unused0, Handle8043E788 *arg1) {
    Obj1C *temp_a2;

    temp_a2 = arg1->unk1C;
    temp_a2->unk858 = 1;
    temp_a2->unk5D8->unk80 = 0;
    Pak_OpenDialog(temp_a2->unk5DC + 0x554, &D_0044FB2C, temp_a2, temp_a2->unk698, temp_a2->unk5D4);
    return 1;
}

/* Steps the selection D_800E1DF8_de through Pak_AdjustValue (a second step when Control_IsRightPressed or
   func_8026437C_de reports the object's controller busy), then sets D_80142228 to the chosen entry of the
   float table D_00450854 plus the offset in D_800E2358, clamped between D_800DE330_de and (2.0f). */





extern s32 D_800E1DF8_de;
extern Extra D_800E2358;


extern f32 D_00450854[];

extern s32 Pak_AdjustValue(struct Shape_typemap_114 *, s32, s32, s32, s32, s32);

extern s32 Render_IsAButtonPressed(s32);

s32 func_8043E6A4_de(void *arg0, struct Shape_typemap_114 *obj)
{
    f32 scale;

    D_800E1DF8_de = Pak_AdjustValue(obj, D_800E1DF8_de, 1, 0, 15, 0);
    if (((s32 (*)(s32))Control_IsRightPressed)(obj->field_20) != 0 || Render_IsAButtonPressed(obj->field_20) != 0) {
        Pak_AdjustValue(obj, D_800E1DF8_de, 1, 0, 15, 0);
    }
    scale = D_00450854[D_800E1DF8_de] + D_800E2358.scale;
    if (!(scale < D_800DE330_de)) {
        if (!(scale > (2.0f))) {
            if (scale < D_800DE330_de) {
                scale = D_800DE330_de;
            }
        } else {
            scale = (2.0f);
        }
    } else {
        scale = D_800DE330_de;
    }
    D_801462C8.speedFactor = scale;
    return 0;
}

#include "COMMON/SHARED_DEBUGFIELD.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern f32 D_800DE338;
extern char *D_800D3DD8[], *D_800D3DDC[];
extern char D_800DE2F8[];
extern s32 Pak_CountLineChars(void *);

s32 func_8043E7AC_de(Shared_DebugWidget *widget) {
    char *text;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Shared_Game *game = &D_801462C8;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    if (game->speedFactor == D_800DE338) {
#else
    if (D_801462C8.speedFactor == D_800DE338) {
#endif
        widget->text = D_800D3DDC;
    } else {
        widget->text = D_800D3DD8;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = widget->text[game->language];
#else
        text = *widget->text;
#endif
        func_802658E4_de(text + (Pak_CountLineChars(widget) - 3), D_800DE2F8, D_800E1DF8_de - 5);
    }
    return 0;
}
