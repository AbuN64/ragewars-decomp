#include "span_16E000/code_804366C4.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "menu_text.h"
#include "types.h"

/* Calls func_8029973C_de, then sets the word at offset 0x20 of the object D_800E5690 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */




extern void func_8029973C_de();

extern void func_8041A430_de(void *, s32);

s32 func_8025DF34_de(s32);

                                 /* extern */
void func_8029973C_de();

                                  /* extern */
s32 func_802A0C08_de(void *, s32, ...);

                  /* extern */

                               /* extern */

                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
extern u8 D_80152789;
#else
#endif

/* Native resident constant storage; absolute access symbols retain their addresses. */
#if defined(VERSION_US)

#elif defined(VERSION_US_REV1)

#elif defined(VERSION_DE)

#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5698, an actor kind at D_800E569C and a handler at D_800E56A0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80436FE4)(void *, s32, s32, s32, s32);



extern Handler80436FE4 D_800E56A0;

s32 func_80436C58_de(void) {
    extern struct State_func_804232AC_de *D_800E5690;
    struct State_func_804232AC_de *state;

    func_8029973C_de();
    state = D_800E5690;
    state->value = -1;
    func_8041A430_de(state->menu, 2);
    return 0;
}

s32 func_80436C94_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern CharacterNextState *D_800E5690;
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804367A8_de(D_800E5690->unk_28);
        temp_v0 = D_800E5690->unk_28 + 1;
        D_800E5690->unk_28 = temp_v0;
        if (temp_v0 >= 4) {
            D_800E5690->unk_28 = 0;
        }
        func_804366B8_de(D_800E5690->unk_28);
        func_802A0C08_de(D_800E5690->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5690->unk_28 + 1);
        D_800E5690->unk_2C->text = (void *) (D_800E5690->text);
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}

s32 func_80436D4C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern CharacterNextState *D_800E5690;
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804367A8_de(D_800E5690->unk_28);
        temp_v0 = D_800E5690->unk_28 - 1;
        D_800E5690->unk_28 = temp_v0;
        if (temp_v0 < 0) {
            D_800E5690->unk_28 = 3;
        }
        func_804366B8_de(D_800E5690->unk_28);
        func_802A0C08_de(D_800E5690->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5690->unk_28 + 1);
        D_800E5690->unk_2C->text = (void *) (D_800E5690->text);
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}

s32 func_80436E04_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80436FE4 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E56A0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E56A0;
        index = 0;
        do {
            if (D_800E5698[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E569C[index].value;
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
