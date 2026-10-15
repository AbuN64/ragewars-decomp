#include "span_1000/code_802944E8.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/world.h"
#include "span_1000/code_80293A04.h"
#include "types.h"

extern s32 func_8044D220_de(s8 *, s32, s32, void *, s32);

extern s32 D_800CD780;

extern s32 D_8011B9F0;

extern s32 D_80142898;

extern s32 D_800CD784_de;

extern s8 D_80145040;

extern int func_8022A414_de(void *arg0);

extern void func_8028D90C_de(void);

extern void func_80293A20_de(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_8010B194_de;

s32 func_80290E6C_de(s32);

s32 func_80291074_de(s32);

extern s32 D_801462C8;

void func_802947C8_de(void *arg0, s32 arg1) {
    GameSession *object = arg0;
    s32 sp18[6];
    s32 var_s0;

    var_s0 = arg1;
    if (func_8044D220_de(&D_8011FE88, -1, var_s0, sp18, 1) == 0) {
        var_s0 = 0;
    }
    object->phase = 2;
    object->selector = var_s0;
    object->target = 0xE;
}

/* Initializes the game state for a new game phase with arg0 as the phase identifier. */
void func_80294848_de(s32 arg0) {
    extern func_80203E78_S1 D_800E28D0;
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(D_800E28D0.unk4);
    D_80142898 = 0;
    func_8022A414_de(&D_80145040);
    D_800CD784_de = 0;
    func_8028D90C_de();
    func_80293998_de(arg0, 0x82);
}

void func_802948C0_de(s32 arg0) {
    s32 *p;

    if (D_800CD780 != 0) {
        func_80293A20_de(arg0, 1, 1);
        return;
    }
    p = &D_8010B194_de;
    if ((*p & 0x1000) && (D_80142898 == 0)) {
        D_80142898 = 1;
        *p = 0;
        D_80142CB4 = D_800C54DC_de;
    }
}

void func_80294938_de(s32 arg0) {
    func_80293B28_de();
    func_80290E6C_de(arg0);
    func_80291074_de(arg0);
}

/* Initializes the game state for a new game phase with arg0 and updates the game state flag. */
void func_8029496C_de(s32 arg0) {
    extern struct Shape_func_8027ABF4_de_2 D_800E28D0;
    s8 *base = &D_801462C8;

    ((ObjectState1E *)(base))->unk_1D = 0;
    D_800CD780 = 0;
    D_8011B9F0 = 0;
    D_80146CB8 = (f32)(D_800E28D0.field_4);
    D_80142898 = 0;
    func_8022A414_de(base - 0x1288);
    D_800CD784_de = 0;
    func_8028D90C_de();
    func_80293998_de(arg0, 0x82);
    D_800CD780 = 1;
    D_800CD784_de = 0;
}

void func_802949FC_de(s32 arg0) {
    if (D_800CD780 != 0) {
        func_80293A20_de(arg0, 1, 1);
        return;
    }
    if ((D_8010B194_de & 0x1000) && (D_80142898 == 0)) {
        D_80142898 = 1;
        D_8010B194_de = 0;
        D_80142CB4 = (15.0f);
    }
}

void func_80294A74_de(s32 arg0) {
    func_80293B28_de();
    func_80290E6C_de(arg0);
    func_80291074_de(arg0);
}
