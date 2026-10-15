#include "span_1000/code_80231F5C.h"
#include "common/draft_fields_func_802335EC_de.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_802022E0.h"
#include "span_1000/code_8023330C.h"
#include "span_1000/code_8024BA6C.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_8022C894.h"
#include "span_1000/code_8022E938.h"

extern struct Shape_func_8020AF9C_de_2 D_80140FF8;



extern void func_802227F4_de(void *, void *, s32);


extern s16 func_8022F96C_de(void *arg0);

extern s32 func_8022B184_de(void *arg0);

extern void func_8022B984_de(void *arg0);



extern s32 func_80283228_de(void *, s32);

extern WeaponActionRecord D_800CE8DC[];

extern char D_8011D8D0;





extern f32 func_80274808_de(f32, f32, s32);


void func_802331FC_de(void *arg0, void *arg1) {
    extern void func_8022AF74_de(void *arg0, s32 arg1);
    extern s32 func_80214178_de(void *, void *, s32);
    void *temp_s0;
    void *temp_a0;
    s16 index;

    temp_s0 = ((Shared_ActorView *)arg0)->self;
    if (((WeaponFireState *)arg1)->mode == 2) {
        func_802227F4_de(temp_s0, temp_s0, 2);
    } else {
        ((WeaponFireState *)arg1)->cueTimer = D_800C3048_de[0];
        if ((((Shared_ActorView *)temp_s0)->remote == 0) &&
            (D_80140FF8.field_0 == 1)) {
            func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x3FB);
        } else {
            func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x4CD);
        }
        func_80214178_de(arg0, arg1, 4);
        func_8022AEA0_de(temp_s0, 0x977);
        func_8022AF74_de(temp_s0, 0x974);

        temp_a0 = ((Shared_ActorView *)arg0)->self;
        index = ((Shared_ActorView *)temp_a0)->selectedAction;
        ((WeaponFireState *)arg1)->charge =
            ((WeaponInfo *)D_800D052C[index])->chargeRate *
            D_800C3048_de[1];
        if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) &&
            (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
            func_8022AF74_de(temp_a0, 0xA3C);
        }
    }
}

void func_80233314_de(void) {
}

void func_8023331C_de(void *arg0, struct Shared_Particle *arg1) {
    extern s32 func_80214178_de(void *, void *, s32);
    arg1->unk148 = D_800C3050_de;
    func_80214178_de(arg0, arg1, 8);
}

/** Perform the no-op callback at VRAM 0x80233334. */
void func_80233344_de(void) {
}

void func_8023334C_de(void *arg0, void *arg1) {
    extern s32 func_802301F4_de(void *, void *);
    extern s32 func_80214178_de(void *, void *, s32);
    void *actor;

    actor = ((LevelActor *)arg0)->controller;
    ((WeaponFireState *)arg1)->mode = 2;
    if (func_80222AA4_de(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
        ((Shared_ActorView *)actor)->nextWeapon = func_8022F96C_de(actor);
        return;
    }

    if (((LevelActor *)arg0)->animationTime >= D_800C3054_de) {
        if (func_8022B184_de(actor) == 0) {
            func_8022B984_de(actor);
        }
    }

    if (!((((Shared_ActorView *)actor)->actionFlags & 0x4000) &&
          (((Shared_ActorView *)actor)->health != 0))) {
        func_80214178_de(arg0, arg1, 2);
        func_8022B9C4_de(actor);
        ((WeaponFireState *)arg1)->mode = 1;
    }

    if (func_802301F4_de(arg0, arg1) != 0) {
        func_8022B9C4_de(actor);
    }
}

void func_80233438_de(void *arg0, void *arg1) {
    extern s32 func_802301F4_de(void *, void *);
    extern s32 func_80214178_de(void *, void *, s32);
    void *actor;
    s16 idx;
    s32 value;

    actor = ((ObjectLinks1DC_3 *)arg0)->unk_1D8;
    idx = ((ObjectLinks11DC *)(actor))->unk_650;
    value = D_800CE8DC[idx].action;

    if (((ObjectLinks11DC *)(actor))->unk_11D8 <= 0.0f) {
        if ((((struct Ctrl *) ((ObjectLinks11DC *) actor)->unk_5D8)->flag == 0 ||
             D_801468F4 == 0) &&
            (((ObjectLinks11DC *)(actor))->unk_6AC & 0x4000)) {
            func_8022B190_de(actor);
        }
    }

    if (func_80222AA4_de(actor, ((ObjectLinks11DC *)(actor))->unk_62E) == 0) {
        if (func_80283228_de(&D_8011D8D0, actor) == 0) {
            ((ObjectLinks11DC *)(actor))->unk_770 = func_8022F96C_de(actor);
        }
    } else if (func_802301F4_de(arg0, arg1) == 0 &&
               !(((ObjectLinks1DC_3 *)arg0)->unk_100 & 0x400)) {
        func_80214178_de(arg0, arg1, value);
    }
}

void func_80233544_de(void *a, struct WeaponEventSource *b) {
    extern void func_80214178_de(void *a, void *b, int c);
    if (b->eventEnabled != 0) {
        func_80214178_de(a, b, 2);
    }
}

void func_8023356C_de(void *arg0) {
    s32 func_8022AF74_de(void *, s32);
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8);
    if ((((struct IntegerState11C4 *) ((s8 *) temp_a0))->unk_11C0) == 0) {
        func_8022AF74_de(temp_a0, 0x80C);
    }
}

void func_80233598_de(void *arg0, void *arg1) {
    extern s32 func_802301F4_de(void);
    void *temp_s1;

    temp_s1 = ((LevelActor *)arg0)->controller;
    if (((WeaponFireState *)arg1)->triggerMode != 0) {
        ((WeaponFireState *)arg1)->mode = 2;
        if (func_802301F4_de() != 0) {
            ((WeaponFireState *)arg1)->mode = 1;
            func_8022B00C_de(temp_s1);
        }
    }
}

void func_802335EC_de(void *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    void *temp_s1;
    void *temp_v0;

    temp_s1 = ((struct MeasuredRecAt1D8V3 *)(arg0))->value;
    if (((struct MeasuredRecAt34 *)(arg1))->value == 5) {
        func_80274870_de(arg1 + 0x128, (f32) D_800CA2D8_de * D_800C3058_de, 0.4f);
    } else {
        func_80274870_de(arg1 + 0x128, 0.0f, 0.4f);
    }
    temp_f1 = ((struct MeasuredRecAt128 *)(arg1))->value;
    temp_v0 = ((struct MeasuredRecAt698V1 *)(temp_s1))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3060_de < (-temp_f1 * D_800C305C_de)
              : D_800C3068_de[0] < (temp_f1 * D_800C3064_de))) {
        temp_f2 = ((struct MeasuredRecAt128 *)(arg1))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3068_de[1]);
            return;
        }
        ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3070_de);
        return;
    }
    ((struct MeasuredRecAt168V2 *)(temp_v0))->value = (f32) D_800C3074_de;
}

void func_8023371C_de(void *arg0, struct WeaponFireState *arg1) {
    extern s32 func_80214178_de(void *, void *, s32);
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = D_800C3078_de;
    temp_f0 = func_80274808_de(arg1->spinStep, temp_f20, D_800CA7A0_de);
    arg1->spinStep = temp_f0;
    if (temp_f20 <= temp_f0) {
        func_80214178_de(arg0, arg1, 2);
    }
}

void func_8023378C_de(void *arg0, void *arg1) {
    ObjRecAt8V1 *event = arg1;
    if (event->unk4 == 6) {
        LevelActor *actor = event->unk8;
        func_802733B4_de(arg0, 0.0f, actor->pitch, 0.0f);
    }
}
