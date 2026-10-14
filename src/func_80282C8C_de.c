#include "span_1000/code_8027A0F4.h"
#include "shared/gameplay_transition.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 1 whose id matches the given object's id. */







extern RecordRecAt2C *D_800D052C[];

s32 func_80282C8C_de(ObjRecAt4V5 *obj) {
    s32 i;
    s32 j;
    EntryRecAt4V4 *entry;

    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 1) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 1) {
                return 1;
            }
        }
    }
    return 0;
}

/* Accepts special id 0x427 or an id found in either record list with entry kind zero. */







extern RecordRecAt2C *D_800D052C[];

s32 func_80282D38_de(ObjRecAt4V5 *obj) {
    s32 i;
    s32 j;
    EntryRecAt4V4 *entry;

    if (obj->unk4 == 0x427) return 1;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 0) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 0) {
                return 1;
            }
        }
    }
    return 0;
}

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 2 whose id matches the given object's id. Adapted from func_80282C8C_de with the entry kind changed from 1 to 2. */







extern RecordRecAt2C *D_800D052C[];

s32 func_80282DEC_de(ObjRecAt4V5 *obj) {
    s32 i;
    s32 j;
    EntryRecAt4V4 *entry;

    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 2) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 2) {
                return 1;
            }
        }
    }
    return 0;
}


extern char D_8011D8D0;
extern f32 D_800C4E58_de[];



extern void *func_802A001C_de(void *, s32, u32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_8022B550_de(void *, f32, f32, void *, s32);
extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

extern void func_80265E10_de(void *, void *, s32, s32, Vec3, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern void func_80284570_de(void *, void *);















void func_80282E98_de(void *arg0, void *arg1) {
    Triple scratch;
    struct Shape_func_802764D4_de_2 pair;
    s32 temp_a1;
    struct Shared_ParticleEvents *temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    struct Shared_ParticleDesc *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    func_802A001C_de(&scratch, 0, 0xC);
    if (((Shared_Particle *)arg0)->inst.type == 0x40F) {
        func_8025DE54_de(0xCDA, ((Shared_ActorView *)arg1)->position.vector,
                      (s32)&((Shared_ActorView *)arg1)->position.vector, -1);
        func_8022B550_de(arg1, 30.0f, 3.0f,
                     ((Shared_Particle *)arg0)->owner, 0);
        func_8028CE94_de(&D_8011FE88,
                      (char *)((Shared_ActorView *)arg1)->controller + 0x140,
                      0x14, scratch, D_800C4E58_de[1], D_800C4E60_de);
        ((Shared_ActorView *)arg1)->impactTimer = (&D_800C4E60_de)[1];
    }

    temp_s1 = ((Shared_Particle *)arg0)->desc;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    temp_v0 = temp_s1->events;
    temp_v1 = (char *)temp_v0 + temp_a1;
    temp_s2 = temp_v0->particles[var_a0];
    temp_a2 = temp_v0->effects[var_a0];
    temp_v0_2 = (char *)temp_v0 + (var_a0 * 8);
    pair = temp_v0->parameters[var_a0];
    temp_s3 = temp_s1->events->sounds[var_a0];
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1,
                     ((Shared_Particle *)arg0)->inst.pos, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(arg0, temp_s2, ((Shared_Particle *)arg0)->unk1D0, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3, ((Shared_Particle *)arg0)->inst.pos, 0, -1);
    }
    func_80284570_de(&D_8011D8D0, arg0);
    func_80284434_de(arg0);
}

extern u8 D_801462E3;




void func_80283064_de(void *arg0, s32 *arg1) {
    s32 result;

    result = 0;
    if ((((Shared_Particle *)arg0)->desc->flags) & 0x02000000) {
        if (((Shared_Particle *)arg0)->flags & 2) {
            result = 2;
        } else if (D_801462E3 == 2) {
            result = 1;
        }
    }
    *arg1 |= result << 0x1E;
}
