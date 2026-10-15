#include "span_16E000/code_80420E90.h"
#include "common/types_1dc8418c21db.h"
#include "stddef.h"
#include "types.h"

/* Calls func_8040E8D8_de with zero on the object at offset 0x20 of the structure D_800E4400 points
   to, and with one on the entry 0x3AB that func_8040EC30_de finds in the list at offset 8, then sets
   the word at offset 0x34. */


extern void func_8040E8D8_de(void *, s32);

/* Advances the animation frame countdown and wraps exhausted frames. */


 /* extern */
void func_80421568_de(void *, void *);

 /* extern */


/* Releases the object D_800E4400 holds through func_802547E4_de, clears D_800E4400 and returns zero. */


extern void func_802547E4_de(void *);

/* Polls the dialog of screen D_800E4400 through func_8041A470_de: state 3 opens the screen through
   func_804217D4_de while its word at 0x34 is zero, and otherwise, when D_8010F190 is 0x433, marks the
   screen confirmed at 0x38 and calls func_80421234_de; state 4 calls func_8029973C_de and waits 3
   through func_80298368_de. Returns zero. */




extern s32 D_8010F190;

extern s32 func_8041A470_de(s32);

extern void func_8029973C_de(void);

extern void func_80298368_de(s32);

void func_8042177C_de(void) {
    extern void *func_8040EC30_de(void *, s32);
    extern struct State_func_8042177C_de *D_800E4400;
    func_8040E8D8_de(D_800E4400->object, 0);
#if defined(VERSION_DE)
    func_8040E8D8_de(func_8040EC30_de(D_800E4400->list, 0x3A5), 1);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8040E8D8_de(func_8040EC30_de(D_800E4400->list, 0x3AB), 1);
#elif defined(VERSION_EU_X)
    func_8040E8D8_de(func_8040EC30_de(D_800E4400->list, 0x3AF), 1);
#endif
    D_800E4400->ready = 1;
}

void func_804217D4_de(void) {
    Frame_func_804217D4_de *func_8040EC30_de(s32, s32);
    extern State_func_804217D4_de *D_800E4400;
    s32 temp_v0;
    Frame_func_804217D4_de *temp_a0;
    Frame_func_804217D4_de *temp_a0_2;
    Frame_func_804217D4_de *temp_v0_2;
    temp_v0 = D_800E4400->unk2C - 1;
    D_800E4400->unk2C = temp_v0;
    if (temp_v0 <= 0) {
#if defined(VERSION_DE)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3B2);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3B8);
#elif defined(VERSION_EU_X)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3BC);
#endif
        temp_a0 = D_800E4400->unk20;
        temp_a0->unk16 = (u16) (temp_a0->unk16 - 1);
        temp_a0_2 = D_800E4400->unk20;
        if (((s16) temp_a0_2->unk16 + temp_v0_2->unk1A) < 0) {
            temp_a0_2->unk16 = 2U;
            func_80421568_de(temp_a0_2, D_800E4400);
        }
        D_800E4400->unk2C = 1;
    }
}

s32 func_80421854_de(void) {
    extern void *D_800E4400;
    func_802547E4_de(D_800E4400);
    D_800E4400 = 0;
    return 0;
}

s32 func_80421884_de(void) {
    extern struct Screen_func_80421884_de *D_800E4400;
    switch (func_8041A470_de(D_800E4400->dialog)) {
    case 3:
        if (D_800E4400->open == 0) {
            func_804217D4_de();
            return 0;
        }
        if (D_8010F190 != 0x433) {
            return 0;
        }
        D_800E4400->confirmed = 1;
        func_80421234_de();
        return 0;
    case 4:
        func_8029973C_de();
        func_80298368_de(3);
        return 0;
    }
    return 0;
}
