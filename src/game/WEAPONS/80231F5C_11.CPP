#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "WEAPONS/MEASUREDRECAT1D8V2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);
extern s32 func_802301F4_de();
#include "COMMON/EXTERNS_6.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "WEAPONS/80231F5C_11.H"
#include "WEAPONS/80213ED4.H"
#include "COMMON/OBJB.H"
extern void func_8044A07C_de(ResourceHandleOwner *object);
extern s32 Weapons_SetPlayerState(SharedPlayer *player, void *target, s32 state);

extern s32 func_802301F4_de(void *, void *);

/* Applies the negated, scaled speed of the event's source (float at 0x294, scaled by D_800C8130) to an
   object through func_802739C4_de when the event side at 0x4 matches the mode: side 2 in mode 1, side 0
   otherwise. */





extern int D_80140FF8;


extern s16 func_8022F96C_de(void *arg0);


extern WeaponActionRecord D_800CE8DC[];

extern s32 D_80140FF8;




void func_80232DF4_de(void *arg0) {
    s32 temp_s0;
    temp_s0 = (((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link);
    func_8044A07C_de(temp_s0);
    if ((((struct ObjRecAt650 *) ((s8 *) temp_s0))->unk650) == 0x27) {
        Weapons_SetPlayerState((void *) temp_s0, (void *) temp_s0, 2);
    }
}

void func_80232E38_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8);
    if ((((struct IntegerState11C4 *) ((s8 *) temp_a0))->unk_11C0) == 0) {
        func_8022AF74_de(temp_a0, 0x9E2);
    }
}

void func_80232E64_de(struct MeasuredRecAt1D8V2 *actor, void *attack) {
    f32 temp_f1;
    f32 temp_f2;
    void *value;
    void *temp_v0;

    value = actor->value;
    ((struct MeasuredRecAt124 *)(attack))->value += (((struct MeasuredRecAt128 *)(attack))->value * D_800D2988) * 2.0f;
    temp_f1 = ((struct MeasuredRecAt128 *)(attack))->value;
    temp_v0 = ((struct MeasuredRecAt698V2 *)(value))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3028_de < (-temp_f1 * *(&D_800C3020_de + 1))
              : D_800C3030_de[0] < (temp_f1 * D_800C302C_de))) {
        temp_f2 = ((struct MeasuredRecAt128 *)(attack))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3030_de[1]);
        } else {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3038_de);
        }
    } else {
        ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) D_800C303C_de;
    }

    if (((struct MeasuredRecAtCB *)(attack))->value != 0) {
        ((struct MeasuredRecAt13CV1 *)(attack))->value = 2;
        if (func_802301F4_de(actor, attack) != 0) {
            ((struct MeasuredRecAt13CV1 *)(attack))->value = 1;
            func_8022B00C_de(value);
        }
    }
}

void func_80232F8C_de(void *obj, Event *event) {
    float v = event->source->speed * D_800C8130;

    if (D_80140FF8 == 1) {
        if (event->side == 2) {
            func_802739C4_de(obj, -v);
        }
    } else if (event->side == 0) {
        func_802739C4_de(obj, -v);
    }
}

void func_80232FF8_de(void *actor, ObjectState140 *attack) {
    char *o = (char *) actor;
    void *temp_s0;
    s16 idx;
    s32 action;

    temp_s0 = (void *)((Actor_func_8022D290_de *)o)->self;
    idx = ((Actor_func_8022D290_de *)temp_s0)->unk_0x0650;
    action = D_800CE8DC[idx].action;

    if (Weapons_HasAmmoForMode(temp_s0, ((Actor_func_8022D290_de *)temp_s0)->unk_0x062E) == 0) {
        ((Actor_func_8022D290_de *)temp_s0)->unk_0x0770 = func_8022F96C_de(temp_s0);
    } else {
        attack->unk_13C = 1;
        if (func_802301F4_de(actor, attack) == 0 && !(((Actor_func_8022D290_de *)o)->flags & 0x400)) {
            Weapons_RequestActorState(actor, attack, action);
        }
    }
}

void func_802330AC_de(Shared_ActorView *arg0, WeaponFireState *fireState) {
    Shared_ActorView *temp_s0;
    Shared_ActorView *temp_a0;
    s16 index;

    temp_s0 = arg0->self;
    fireState->cueTimer = 0;
    if ((temp_s0->remote == 0) &&
        (D_80140FF8 == 1)) {
        func_8021A9A4_de(arg0->self, 0x3F9);
    } else {
        func_8021A9A4_de(arg0->self, 0x4CB);
    }
    func_8022AEA0_de(temp_s0, 0x78A);
    func_8022AF74_de(temp_s0, 0x780);

    temp_a0 = arg0->self;
    index = temp_a0->selectedAction;
    fireState->charge =
        ((WeaponInfo *)D_800D052C[index])->chargeRate *
        D_800C3044_de;
    if ((temp_a0->selectedAction == 8) &&
        (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}

void func_80233188_de(void *object, Event *event) {
    f32 speed;
    s32 mode;

    speed = event->source->speed;
    mode = D_80140FF8;
    if (mode == 1) {
        switch (event->side) {
        case 1:
            func_802739C4_de(object, -speed);
            break;
        case 2:
            func_802739C4_de(object, speed * 2.0f);
            break;
        }
    } else if (event->side == 0) {
        func_802739C4_de(object, -speed * 2.0f);
    }
}
