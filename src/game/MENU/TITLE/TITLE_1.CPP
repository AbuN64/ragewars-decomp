#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"
#include "MENU_2/EXTERNS.H"
#include "COMMON/CHEATCODE.H"
#include "MENU/80408AC4_36.H"

/* 80406A88_17.CPP */
#if defined(VERSION_EU_X)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E57DC, an actor kind at D_800E57E0 and a handler at D_800E57E4: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from Menu_DispatchOptionsTransitionEvent. */

s32 Menu_DispatchTitleButtonOffsetEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E57E4 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E57E4;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E57DC)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E57E0)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_EU_X)
unsigned int func_804389A8_eu_x_padding_1289A8[2] = {
    0xACA20188, 0x8FBF0020,
};
#endif

/* 80408AC4_36.CPP */
#if defined(VERSION_DE)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E57DC, an actor kind at D_800E57E0 and a handler at D_800E57E4: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler80437B98)(void *, s32, s32, s32, s32);

extern FieldRow D_800E178C_de[];

extern FieldRow D_800E1790_de[];

extern Handler80437B98 D_800E1794_de;

s32 Menu_DispatchTitleButtonColumnEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80437B98 *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E1794_de != 0) {
        wildcard = 0x7530;
        entry = &D_800E1794_de;
        index = 0;
        do {
            if (D_800E178C_de[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E1790_de[index].value;
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

unsigned char D_auto_func_80437A48_de_padding_19DA48[8] = { 0x24, 0x05, 0x00, 0x67, 0x00, 0x00, 0x30, 0x21 };
#endif
