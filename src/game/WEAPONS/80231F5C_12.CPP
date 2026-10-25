#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "WEAPONS/MEASUREDRECAT1D8V3.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJ.H"
#include "COMMON/STATERECAT10.H"
#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/MTX.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"
extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);
extern s32 func_802301F4_de(void *, void *);
#include "COMMON/EXTERNS_6.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "GAME/CODE_8027302C.H"
#include "RENDER_2/8022AE90_2.H"
#include "WEAPONS/80231F5C_12.H"
#include "WEAPONS/80213ED4.H"

extern struct Shape_func_8020AF9C_de_2 D_80140FF8;



extern void func_802227F4_de(void *, void *, s32);


extern s16 func_8022F96C_de(void *arg0);

extern s32 func_8022B184_de(void *arg0);

extern void func_8022B984_de(void *arg0);



extern s32 func_80283228_de(void *, s32);

extern WeaponActionRecord D_800CE8DC[];

extern char D_8011D8D0;





extern f32 func_80274808_de(f32, f32, s32);


void func_802331FC_de(Shared_ActorView *arg0, WeaponFireState *fireState) {
    void *player;
    void *temp_a0;
    s16 index;

    player = arg0->self;
    if (fireState->mode == 2) {
        func_802227F4_de(player, player, 2);
    } else {
        fireState->cueTimer = D_800C3048_de[0];
        if ((((Shared_ActorView *)player)->remote == 0) &&
            (D_80140FF8.field_0 == 1)) {
            func_8021A9A4_de(arg0->self, 0x3FB);
        } else {
            func_8021A9A4_de(arg0->self, 0x4CD);
        }
        func_80214178_de(arg0, fireState, 4);
        func_8022AEA0_de(player, 0x977);
        func_8022AF74_de(player, 0x974);

        temp_a0 = arg0->self;
        index = ((Shared_ActorView *)temp_a0)->selectedAction;
        fireState->charge =
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

void func_8023331C_de(void *arg0, struct Shared_Particle *particle) {
    particle->unk148 = D_800C3050_de;
    func_80214178_de(arg0, particle, 8);
}

/** Perform the no-op callback at VRAM 0x80233334. */
void func_80233344_de(void) {
}

void func_8023334C_de(void *arg0, void *attack) {
    void *actor;

    actor = ((LevelActor *)arg0)->controller;
    ((WeaponFireState *)attack)->mode = 2;
    if (Weapons_HasAmmoForMode(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
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
        func_80214178_de(arg0, attack, 2);
        func_8022B9C4_de(actor);
        ((WeaponFireState *)attack)->mode = 1;
    }

    if (func_802301F4_de(arg0, attack) != 0) {
        func_8022B9C4_de(actor);
    }
}

void func_80233438_de(void *arg0, void *attack) {
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

    if (Weapons_HasAmmoForMode(actor, ((ObjectLinks11DC *)(actor))->unk_62E) == 0) {
        if (func_80283228_de(&D_8011D8D0, actor) == 0) {
            ((ObjectLinks11DC *)(actor))->unk_770 = func_8022F96C_de(actor);
        }
    } else if (func_802301F4_de(arg0, attack) == 0 &&
               !(((ObjectLinks1DC_3 *)arg0)->unk_100 & 0x400)) {
        func_80214178_de(arg0, attack, value);
    }
}

void func_80233544_de(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        func_80214178_de(a, b, 2);
    }
}

void func_8023356C_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8);
    if ((((struct IntegerState11C4 *) ((s8 *) temp_a0))->unk_11C0) == 0) {
        func_8022AF74_de(temp_a0, 0x80C);
    }
}

void func_80233598_de(LevelActor *actor, WeaponFireState *fireState) {
    void *controller;

    controller = actor->controller;
    if (fireState->triggerMode != 0) {
        fireState->mode = 2;
        if (func_802301F4_de(actor, fireState) != 0) {
            fireState->mode = 1;
            func_8022B00C_de(controller);
        }
    }
}

void func_802335EC_de(struct MeasuredRecAt1D8V3 *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    void *value;
    void *temp_v0;

    value = arg0->value;
    if (((struct MeasuredRecAt34 *)(arg1))->value == 5) {
        Nav_EaseValueToward(arg1 + 0x128, (f32) D_800CA2D8_de * D_800C3058_de, 0.4f);
    } else {
        Nav_EaseValueToward(arg1 + 0x128, 0.0f, 0.4f);
    }
    temp_f1 = ((struct MeasuredRecAt128 *)(arg1))->value;
    temp_v0 = ((struct MeasuredRecAt698V1 *)(value))->value;
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

void func_8023371C_de(void *arg0, struct WeaponFireState *fireState) {
    f32 temp_f0;
    f32 target;

    target = D_800C3078_de;
    temp_f0 = func_80274808_de(fireState->spinStep, target, D_800CA7A0_de);
    fireState->spinStep = temp_f0;
    if (target <= temp_f0) {
        func_80214178_de(arg0, fireState, 2);
    }
}

void func_8023378C_de(void *matrix, void *arg1) {
    ObjRecAt8V1 *event = arg1;
    if (event->unk4 == 6) {
        LevelActor *actor = event->unk8;
        func_802733B4_de(matrix, 0.0f, actor->pitch, 0.0f);
    }
}
