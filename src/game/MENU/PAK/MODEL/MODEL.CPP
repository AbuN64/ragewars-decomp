#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"
#include "sdk/AUDIO/802BD1A8_19.H"
#include "RENDER/8028FD2C_6.H"
#include "COMMON/S1_2.H"
#include "MENU/PAK/80444EC0_5.H"
#include "SYSTEM/8025E280.H"

#if defined(VERSION_US_REV1)
/* Edits a byte, integer, or float option and propagates it to the active resource records. */
 /* extern */
s32 Scene_GetModelRecordByIndexPointer(Shared_World *, s32); /* extern */
s32 Menu_CountLineChars(void *); /* extern */
s32 Menu_TryCreateMenu(void *, void *, s32); /* extern */
s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32); /* extern */

s32 Pak_AdjustModelField(OptionEditState *arg0, OptionEditState *arg1, s32 arg2, s32 wrap, s32 arg4, s32 step, s32 maximum, f32 arg7) {
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_s0_2;
    s32 var_v1;
    s32 length;
    u8 *temp_s0;
    s32 var_s1;
    OptionEditState *temp_a1;
    OptionEditState *temp_v0;
    ResourceManagerState *temp_v0_2;
    char *var_a0;
    var_s1 = 0;
    if (Control_IsStartPressed(arg1->unk_20) != 0) {
        return Menu_TryCreateMenu(arg0, arg1, arg2);
    }
    temp_v0 = arg1->unk_1C;
    if (temp_v0 != NULL) {
        temp_a1 = temp_v0->unk_5DC;
        if (temp_a1 != NULL) {
            temp_a1_2 = temp_a1->unk_58;
            if (temp_a1_2 != 0) {
                temp_s0 = Scene_GetModelRecordByIndexPointer(&g_world, temp_a1_2) + arg4;
                switch (wrap) { /* irregular */
                case 0:
                    var_s1 = *temp_s0;
                    var_s1 = Menu_AdjustValue(arg1, var_s1, step, 0, maximum, 1);
                    *temp_s0 = var_s1;
                    break;
                case 1:
                    var_s1 = *(s32 *)temp_s0;
                    var_s1 = Menu_AdjustValue(arg1, var_s1, step, 0, maximum, wrap);
                    *(s32 *)temp_s0 = var_s1;
                    break;
                case 2:
                    var_s1 = (s32)*(f32 *)temp_s0;
                    var_v1 = maximum;
                    var_s1 = Menu_AdjustValue(arg1, var_s1, step, 0, var_v1, 1);
                    *(f32 *)temp_s0 = var_s1;
                    break;
                }
                temp_s0_2 = *arg0->unk_14;
                length=Menu_CountLineChars(arg0);
                length-=6;
                func_802BD320_de(temp_s0_2 + length, &g_pakFormatInt06, (s32) ((f32) var_s1 / arg7));
                if (D_800E63AC != 0) {
                    temp_v0_2 = SetN64_GetPackSection(g_modelEditPack, 0);
                    var_v1 = 0;
                    temp_a1_3 = temp_v0_2->count;
                    temp_v0_2=&((OptionEditContext *)(temp_v0_2))->unk_8;
                    if (temp_a1_3 > 0) {
                        do {
                            var_a0 = (char *)temp_v0_2 + var_v1 * 100;
                            temp_s0 = var_a0 + arg4;
                            switch(wrap) {
                            case 0: *temp_s0=var_s1;break;
                            case 1: *(s32 *)temp_s0=var_s1;break;
                            case 2: *(f32 *)temp_s0=var_s1;break;
                            }
                            var_v1 += 1;
                        } while (var_v1 < temp_a1_3);
                    }
                }
            }
        }
    }
    return 0;
}
#endif

#if !(defined(VERSION_US))
/* Calls func_8025E2D4_de with -1, func_8025E384_de, func_8025E33C_de and Match_ResetMatchControllerState on D_8011FAC0, and
   returns one. */
#include "COMMON/GAME_SESSION.H"

extern void Match_ResetMatchControllerState(void *);

s32 Pak_StopMusicAndResetMatch(void) {
    func_8025E2D4_de(-1);
    func_8025E384_de();
    func_8025E33C_de();
    Match_ResetMatchControllerState(&D_8011FAC0);
    return 1;
}

/* Stores 4 into the first halfword of a record. */
void Pak_SetRecordTypeFour(s16 *record) {
    record[0] = 4;
}
#endif

#if defined(VERSION_US_REV1)
/* Forwards its three arguments to Pak_AdjustModelField with 0, 0, 1, 0xFF and the pooled constant (1.0f). */
extern s32 Pak_AdjustModelField(OptionEditState *, OptionEditState *, s32, s32, s32, s32, s32, f32);

void Pak_AdjustModelByteZero(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 0, 0, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to Pak_AdjustModelField with 0, 1, 1, 0xFF and the pooled constant (1.0f). */

void Pak_AdjustModelByteOne(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 0, 1, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to Pak_AdjustModelField with 0, 2, 1, 0xFF and the pooled constant (1.0f). */

void Pak_AdjustModelByteTwo(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 0, 2, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to Pak_AdjustModelField with 1, 8, 0xA, 0x7D0 and the pooled constant (1.0f). */

void Pak_AdjustModelWordAt08(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 1, 8, 0xA, 0x7D0, (1.0f));
}

/* Forwards its three arguments to Pak_AdjustModelField with 2, 0x10, 0x66, 0xA000 and the pooled constant (10.239999771118164f). */

void Pak_AdjustModelFloatAt10(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 2, 0x10, 0x66, 0xA000, (10.239999771118164f));
}

/* Forwards its three arguments to Pak_AdjustModelField with 2, 0x14, 1, 0xB4 and the pooled constant
   (1.0f). */

void Pak_AdjustModelFloatAt14(void *first, void *second, void *third) {
    Pak_AdjustModelField(first, second, third, 2, 0x14, 1, 0xB4, (1.0f));
}
#endif
