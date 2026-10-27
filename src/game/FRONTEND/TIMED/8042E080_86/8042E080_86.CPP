#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_86.H"
#include "COMMON/LONE/D_800E5558.H"

/* 8042E080_86.CPP */
/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E55C8, an actor kind at D_800E55CC and a handler at D_800E55D0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8043630C)(void *, s32, s32, s32, s32);

extern FieldRow D_800E55C8[];
extern FieldRow D_800E55CC[];
extern Handler8043630C D_800E55D0;

s32 Frontend_DispatchConfirmationEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8043630C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E55D0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E55D0;
        index = 0;
        do {
            if (D_800E55C8[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E55CC[index].value;
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

/* 8042E080_87.CPP */
/* Builds screen state D_800E5558: allocates its 0x1C bytes, resets through Tsmos_ActivateControllerState and opens
   it as page 0x67 through Frontend_InitMenuImage; then places the given window at 0x62, 0x45 in mode 1 of
   func_8040C474_de, or at x 0x69 in mode 2. Returns zero. */

extern void *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void Frontend_InitMenuImage(void *, s32, s32, s32, s32);
extern s32 Frontend_GetScreenMode(void);

s32 Frontend_CreateTimedMenu(struct Pair14 *window) {
    D_800E5558 = Cache_AllocateMemory(0x1C);
    Tsmos_ActivateControllerState();
    Frontend_InitMenuImage(D_800E5558, 0x67, 0, 0, 0);
    if (Frontend_GetScreenMode() == 1) {
        window->first = 0x62;
        window->second = 0x45;
    } else if (Frontend_GetScreenMode() == 2) {
        window->first = 0x69;
    }
    return 0;
}
