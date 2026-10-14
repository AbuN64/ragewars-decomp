#include "span_1000/code_8027A0F4.h"
#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028308C.h"
#include "types.h"

/** Return arg0, but treat the sentinel value 0xA as 0. */
s32 func_80283D38_de(s32 arg0) {
    if (arg0 == 0xA) {
        return 0;
    }
    return arg0;
}






extern void func_80265E10_de(void *, void *, s32, s32, Vec3, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);











void func_80283D50_de(void *arg0) {
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
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)arg0)->inst.pos, 0, -1);
    }
}







extern void func_80265E10_de(void *, void *, s32, s32, Vec3, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);











void func_80283E58_de(void *arg0) {
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

    temp_s1 = ((Shared_Particle *)arg0)->desc;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xD;
    } else {
        var_a0 = 0xB;
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
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)arg0)->inst.pos,
                      (s32)&((Shared_Particle *)arg0)->inst.pos, (s32)arg0);
    }
}






extern void func_80265E10_de(void *, void *, s32, s32, Vec3, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);











void func_80283F60_de(void *arg0) {
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
        func_8025DE54_de((s16)temp_s3,
                      ((Shared_Particle *)arg0)->inst.pos, 0, -1);
    }
}

int func_80284068_de(void *arg0) {
    char pad[0x10];
    return ((u32)((Shared_Particle *)arg0)->flags >> 2) & 1;
}

int func_80284080_de(void) {
    char pad[0x10];
    return 0;
}
