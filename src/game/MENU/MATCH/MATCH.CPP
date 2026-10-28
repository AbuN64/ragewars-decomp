#include "COMMON/CHEATCODE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "MENU/80408AC4_30.H"

#if defined(VERSION_DE)
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4EC0, an actor kind at D_800E4EC4 and a handler at D_800E4EC8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8042931C)(void *, s32, s32, s32, s32);

extern FieldRow D_800E0E70_de[];

extern FieldRow D_800E0E74_de[];

extern Handler8042931C D_800E0E78_de;

s32 Menu_DispatchGermanMatchMenuEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042931C *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E0E78_de != 0) {
        wildcard = 0x7530;
        entry = &D_800E0E78_de;
        index = 0;
        do {
            if (D_800E0E70_de[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E0E74_de[index].value;
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

unsigned char D_auto_func_80435B08_de_padding_19BB08[8] = { 0x24, 0x04, 0x00, 0x14, 0x24, 0x04, 0xFF, 0xFF };
#endif
