#include "span_16E000/code_804379C8.h"
#include "common/types_1dc8418c21db.h"
#include "stddef.h"
#include "TYPES.H"

/* Advances a menu selection on its countdown and dispatches the exit action. */
void func_80298368_de(s32);

 /* extern */
void func_8029973C_de();

 /* extern */
void func_802998A8_de(void);

 /* extern */
s32 func_8041A470_de(void *);

 /* extern */


/* Calls func_8029973C_de, then sets the word at offset 0x10 of the object D_800E5784 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */




extern void func_8029973C_de();

extern void func_8041A430_de(void *, s32);

/* Calls func_8029973C_de; when func_80299A08_de reports 0x3D0 it sets the word at 0x10 of the menu block
   D_800E5784 points to to 7 and clears five bytes at D_80102B7E through func_802A001C_de, for 0x3D1 it
   sets that word to -1; then it calls func_8041A430_de on the block's first word with 2. Returns
   zero. */


extern char D_80102B7E[];

extern s32 func_80299A08_de();

extern void func_802A001C_de(void *, s32, s32);

#if defined(VERSION_DE)
enum { MENU_80437B10_976 = 970, MENU_80437B10_977 = 971 };
#elif defined(VERSION_EU_X)
enum { MENU_80437B10_976 = 980, MENU_80437B10_977 = 981 };
#else
enum { MENU_80437B10_976 = 976, MENU_80437B10_977 = 977 };
#endif

 /* const */
s32 func_80437810_de(void) {
    extern StateCode80420E90 *D_800E5784;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    CellRecAt1A *temp_a0;
    CellRecAt1A *temp_v1;
    temp_v0 = func_8041A470_de(D_800E5784->unk0);
    switch (temp_v0) { /* irregular */
    case 3:
        temp_v0_2 = D_800E5784->unkC - 1;
        D_800E5784->unkC = temp_v0_2;
        if (temp_v0_2 <= 0) {
            temp_v1 = D_800E5784->unk8;
            temp_v1->unk16 = (u16) (temp_v1->unk16 - 1);
            temp_a0 = D_800E5784->unk8;
            if (((s16) temp_a0->unk16 + temp_a0->unk1A) < 0) {
                temp_a0->unk16 = (u16) D_800E5784->unk0->unk44->unk1A;
            }
            D_800E5784->unkC = temp_v0;
        }
block_10:
        return 0;
    case 4:
        func_8029973C_de();
        temp_a0_2 = D_800E5784->unk10;
        if (temp_a0_2 == -1) {
            func_802998A8_de();
            return 0;
        }
        func_80298368_de(temp_a0_2);
        goto block_10;
    default:
        return 0;
    }
}

s32 func_804378F4_de(void) {
    extern struct State_func_80421D94_de *D_800E5784;
    struct State_func_80421D94_de *state;

    func_8029973C_de();
    state = D_800E5784;
    state->value = -1;
    func_8041A430_de(state->first, 2);
    return 0;
}

s32 func_80437930_de(void) {
    extern MenuSelectionMessage *D_800E5784;
    s32 choice;

    func_8029973C_de();
    choice = func_80299A08_de();
    switch (choice) {
    case MENU_80437B10_977:
        D_800E5784->value = -1;
        break;
    case MENU_80437B10_976:
        D_800E5784->value = 7;
        func_802A001C_de(D_80102B7E, 0, 5);
        break;
    }
    func_8041A430_de(D_800E5784->first, 2);
    return 0;
}
