#include "span_1000/code_80277444.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80279208.h"
#include "types.h"

extern s32 func_80279204_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern s32 func_8028C26C_de(s8 *arg0, void *arg1, s32 *arg2, s32 *arg3);

extern s32 func_8028C1D4_de(s8 *arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern s32 func_8028BB1C_de(void *arg0, void *arg1, s32 arg2);


extern void func_8028D90C_de(void);

extern void func_80402FB4_de(s32, s32);

extern void func_80217388_de(void);

extern void func_80262C88_de(struct Shared_Actor *arg0);

extern int func_8025DF34_de(short arg0);

s32 func_8025DF34_de(s16);

void func_80278D78_de(struct Shared_Actor *arg0, s32 arg1, void *arg2) {
    s32 sp20;
    s32 sp24;

    if (!(arg0->weaponFlags & 0x80000)) {
        func_8028C26C_de(&D_8011FE88, arg0, &sp20, &sp24);
        if (sp24 != 0) {
            func_80279204_de(sp20, sp24, 0, arg1 & 0x3FC1FF, arg1 & 0x400000, 0x400000, arg2);
        }
    }
}

void func_80278E04_de(s32 arg0, s32 arg1, void *arg2) {
    s32 sp20;
    s32 sp24;

    if (arg0 != 0) {
        func_8028C1D4_de(&D_8011FE88, arg0, &sp20, &sp24);
        if (sp24 != 0) {
            func_80279204_de(sp20, sp24, 0, arg1 & 0x7FF, arg1 & 0x3800, 0x3800, arg2);
        }
    }
}

void func_80278E7C_de(void *arg0) {
    extern s32 func_80278C10_de(void *arg0);
    func_80278EEC_S1 *object = arg0;

    object->unkE |= 0x10;
    func_8028BB1C_de(&D_8011FE88, arg0, 1);
    if ((D_8011FE88.mode == 4) && (object->unkE & 2)) {
        func_8028C568_de(&D_8011FE88, arg0);
        return;
    }
    func_80278C10_de(arg0);
}

void func_80278F00_de(Record14 *arg0) {
    extern void func_80278C10_de(void *);
    Record14 copy;
    u8 *bytes = (u8 *)arg0;

    bytes[0xE] |= 0x20;
    if (bytes[0x11] == 1) {
        copy = *arg0;
        ((u8 *)&copy)[0x12] = 2;
        ((u8 *)&copy)[0x10] = 0;
        func_80278C10_de(&copy);
    }
}

/* Clears bits 0x2000 and 0x100 of the flag word at offset 0x100 of an object. */


void func_80278F68_de(struct LevelActor *object) {
    object->flags &= ~0x2000;
    object->flags &= ~0x100;
}

void func_80278F84_de(LevelActor *arg0) {
    func_802472F0_de(arg0);
    arg0->flags = (s32) (arg0->flags | 0x2100);
}

void func_80278FB4_de(s32 arg0, s32 arg1, s32 arg2) {
    if (D_8011FE88.mode == 4) {
        func_8028D90C_de();
        func_80402FB4_de(arg0, arg2);
    }
}

void func_80279004_de(s32 arg0) {
    if (D_8011FE88.mode == 4) {
        func_8028D90C_de();
        func_80402FB4_de(0, arg0);
    }
}

void func_80279048_de(void *arg0, void *arg1) {
    (((struct ObjectState104 *) ((s8 *) arg0))->unk_100) = (s32) ((((struct ObjectState104 *) ((s8 *) arg0))->unk_100) | 0x40000000);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_48) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_8);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_4C) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_C);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_50) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_10);
    (((struct FloatState64 *) ((s8 *) arg1))->unk_60) = (f32) (((struct ObjectState104 *) ((s8 *) arg0))->unk_6C);
}

void func_8027907C_de(s32 arg0, s32 arg1, Trigger *arg2) {
    if ((u16)arg2->unk4 >= 0x100) {
        func_8025E11C_de((u16)arg2->unk4);
        return;
    }
    func_8025E2D4_de((u16)arg2->unk4);
}

void func_802790C0_de(struct Shared_Actor *arg0, s32 *arg1) {
    s32 temp_v0;

    func_80217388_de();
    *arg1 |= 0x20;
    temp_v0 = arg0->weaponFlags & 0xFFFEFFFF;
    temp_v0 = temp_v0 & ~0x2000;
    temp_v0 = temp_v0 & ~0x100;
    arg0->weaponFlags = temp_v0;
    if (temp_v0 & 0x80000) {
        func_80262C88_de(arg0);
    }
}

void func_80279138_de(int arg0, int arg1, void *arg2) {
    ObjRecAt6V2 *arg2_record = arg2;
    func_8025DF34_de(arg2_record->unk6);
}

void func_80279158_de(void *arg0) {
    func_8025E2D4_de((s32) (((struct ObjRecAt6V1 *) ((s8 *) arg0))->unk6));
}

void func_80279178_de(void *arg0) {
    func_8025DF34_de((((struct ObjRecAt6V2 *) ((s8 *) arg0))->unk6));
}
