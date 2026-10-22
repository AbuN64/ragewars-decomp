#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJ.H"
#include "COMMON/REC.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4.H"

extern s32 D_801462C8;

extern int func_80285F58_de(char *a, int b);

extern void func_80285DB0_de(Shared_World *a, void *b, int c);

void func_80206080_de(void *arg0, void *arg1) {
    LevelActor *actor = arg0;
    ActorMotionState *motion = arg1;
    AnimationTriggerResource *resource;
    AnimationTriggerDefinition *base;
    char *ctx;
    f32 result;
    s32 count;
    s32 temp_v1;
    f64 var_f1;
    f32 scaled;

    resource = (void *)actor->definition;
    base = &resource->trigger;
    result = func_80274A90_de(base->delayMinimum, base->delayMaximum);
    motion->speed = result;
    ctx = (char *) &D_801462C8;
    if (((ObjectState1E_2 *)(ctx))->unk_1D != 0) {
        count = *(s32 *) (ctx - 0x1258);
        if ((u32) count >= 3) {
            count -= 2;
            scaled = result * D_800C1AD0_de;
            temp_v1 = 0x64 - count * 25;
            var_f1 = (f64) temp_v1;
            if (temp_v1 < 0) {
                var_f1 += (4294967296.0);
            }
            motion->speed = scaled * (f32) var_f1;
        }
    }
}

void func_8020612C_de(LevelActor *arg0, ActorMotionState *arg1) {
    AnimationTriggerResource *temp_v0;
    AnimationTriggerDefinition *temp_a2;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = (void *)arg0->definition;
    temp_a2 = &temp_v0->trigger;
    if (temp_a2->enabled == 0) {
        if (temp_a2->firstAnimation == -1) {
            arg1->timer = 0.0f;
            return;
        }
        if (temp_a2->secondAnimation == -1) {
            arg1->timer = 0.0f;
            return;
        }
    }
    if (arg1->unk124 == temp_a2->animation) {
        arg1->timer = 0.0f;
        return;
    }
    temp_v1 = temp_a2->flags;
    if (!(temp_v1 & 1)) {
        if (arg1->unk128 <= 0) {
            return;
        }
    }
    var_v0 = temp_v1 & 2;
    if (var_v0 != 0) {
        if (arg0->flags & 0x200) {
            arg1->timer = 0.0f;
            return;
        }
    }
    if (arg1->timer >= arg1->speed) {
        func_80214178_de(arg0, arg1, 1);
    }
}

void func_802061D8_de(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        func_80214178_de(a, b, 0x0);
    }
}

int func_80206200_de(int arg0) {
    return func_80285F58_de(&D_8011FE88, arg0) == 1;
}

void func_80206230_de(void *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}
