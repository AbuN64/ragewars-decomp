#include "span_1000/code_8022BA90.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/gameplay_round_rules.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80208000.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8024BA6C.h"
#include "span_1000/code_8026AC38.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_8022E938.h"

extern unsigned int D_80146894;

extern void *func_8028CFA0_de(Shared_World *arg0, s32 arg1, s32 arg2);

extern s32 D_801468F4;

extern s32 D_80140FF8;




extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern void *func_8028FDB4_de(void *arg0, s32 arg1);


extern void func_8024ADD0_de(void *arg0, Vec3 *arg1, s32 arg2);

extern void func_80253754_de(s32 arg0, s32 arg1);


extern void func_8022BEFC_de(void *arg0, void *arg1);

extern void func_8022C060_de(void *arg0, void *arg1);

/** Report whether the nested pointer's word at 0x564 is nonzero. */
int func_8022BAA0_de(void *object) {
    func_80228774_S5 *object_record = object;
    ObjRecAt564 *nested = object_record->unk5DC;
    if (nested != 0) {
        return nested->unk564 != 0;
    }
    return 0;
}

/** Report whether the global state word is nonzero. */
int func_8022BAC0_de(void) {
    return D_80146894 != 0;
}

void func_8022BAD0_de(void *arg0) {
    s32 var_a2;
    void *result;

    var_a2 = ((Shared_ActorView *)arg0)->state;
    if (D_801468F4 != 0 && ((Shared_ActorView *)arg0)->controls->transientFlag == 1) {
        var_a2 = 0x13;
    }
    result = func_8028CFA0_de(&D_8011FE88, 0xB, var_a2);
    if (result != 0) {
        ((Shared_ActorView *)arg0)->model = result;
    } else {
        result = func_8028CFA0_de(&D_8011FE88, 0xB, -1);
        if (result != 0) {
            ((Shared_ActorView *)arg0)->model = result;
        } else {
            result = func_8028CFA0_de(&D_8011FE88, -1, -1);
            ((Shared_ActorView *)arg0)->model = result;
        }
    }
    ((LevelActor *)arg0)->scale.x = ((ObjectState108 *)result)->unk_FC;
    ((LevelActor *)arg0)->scale.y = ((ObjectState108 *)result)->unk_100;
    ((LevelActor *)arg0)->scale.z = ((ObjectState108 *)result)->unk_104;
}

void func_8022BB80_de(void *arg0) {
    s32 var_a2;
    Shared_Game *base;

    base = &D_801462C8;
    if (base->local == 0) {
        var_a2 = 0x66;
    } else if (base->unk62C != 0 && ((Shared_ActorView *)arg0)->controls->transientFlag != 0) {
        var_a2 = D_800CE47C;
    } else {
        var_a2 = D_800CE430[(s16)(((LevelActor *)arg0)->definition[3] >> 16)];
        ((Shared_ActorView *)arg0)->id = ((Shared_ActorView *)arg0)->controls->playerId;
    }
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, arg0, var_a2, ((Shared_ActorView *)arg0)->effectId);
}

void func_8022BC14_de(Player *arg0) {
    s32 var_t0;

    if (arg0->computer != 0) {
        if (D_8014288C == 0) {
            var_t0 = 0x17;
            goto after;
        }
    }
    var_t0 = (D_80140FF8 == 1) ? 0 : 0x17;
after:
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, &arg0->weaponModel,
        ((WeaponInfo *)D_800D052C[arg0->selectedAction])->model + var_t0,
        arg0->weaponAnimationTable->defaultAnimation);
}

void func_8022BC94_de(void *arg0, s32 arg1) {
    Vec3 sp28;
    void *temp_s1;
    Shared_ActorView *temp_s2;
    SharedRecAt564V1 *temp_v0;
    ObjectLinks1DC_3 *object = arg0;

    if (object->unk_100 & 0x40000) {
        temp_s1 = func_8025193C_de(0, object->resource, object->resource, object->resourceFlags, 4, 0, 0, &D_800C2BC0_de, 1);
        if (temp_s1 != 0) {
            temp_s2 = object->unk_1D8;
            func_8024B4F4_de(arg0, (s32)func_8028FDB4_de(*(void **)temp_s1, 0));
            if (arg1 != 0) {
                temp_v0 = temp_s2->message;
                if (temp_v0 != 0) {
                    sp28.x = temp_v0->position.x - object->unk_8.x;
                    sp28.y = 0.0f;
                    sp28.z = ((SharedRecAt564V1 *)temp_s2->message)->position.z - object->unk_8.z;
                    func_8024ADD0_de(arg0, &sp28, arg1);
                }
            }
            func_80253754_de(0, (s32)temp_s1);
        }
    }
}

void func_8022BD94_de(void *arg0, void *arg1, s32 arg2) {
    func_8022BD84_S2 *object = arg0;
    func_8020D1FC_S1 *argument = arg1;
    s32 flags;
    s32 flag_1000;
    s32 flag_8000;
    s32 flag_10000;

    if (arg2 != 0) {
        flags = argument->unk38;
        flag_1000 = flags & 0x1000;
        flag_8000 = flags & 0x8000;
        flag_10000 = flags & 0x10000;
        if (flag_1000 == 0) {
            object->unk840 = 0;
        } else {
            func_8022BE20_de(arg0, arg1);
        }
        if (flag_8000) {
            func_8022BEFC_de(arg0, arg1);
        }
        if (flag_10000) {
            func_8022C060_de(arg0, arg1);
        }
    }
}
