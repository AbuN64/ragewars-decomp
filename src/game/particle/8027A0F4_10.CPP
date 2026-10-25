#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"

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



extern s32 Render_PlaySoundAtPosition(s16, CVector3, s32, s32);
extern void func_8022B550_de(void *, f32, f32, void *, s32);
extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

extern void System_DeliverContactEffect(void *, void *, s32, s32, CVector3, struct IntPair);
extern void Render_SpawnChildEffect(void *, s32, s8, s32);
extern void Particle_Release(void *, void *);















void func_80282E98_de(void *particle, void *player) {
    Triple scratch;
    struct IntPair pair;
    s32 temp_a1;
    struct Shared_ParticleEvents *events;
    s32 var_a0;
    s32 temp_a2;
    s32 model;
    s32 temp_s3;
    struct Shared_ParticleDesc *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    Resmgr_FillMemory(&scratch, 0, 0xC);
    if (((Shared_Particle *)particle)->inst.type == 0x40F) {
        Render_PlaySoundAtPosition(0xCDA, ((Shared_ActorView *)player)->position.vector,
                      (s32)&((Shared_ActorView *)player)->position.vector, -1);
        func_8022B550_de(player, 30.0f, 3.0f,
                     ((Shared_Particle *)particle)->owner, 0);
        func_8028CE94_de(&D_8011FE88,
                      (char *)((Shared_ActorView *)player)->controller + 0x140,
                      0x14, scratch, D_800C4E58_de[1], D_800C4E60_de);
        ((Shared_ActorView *)player)->impactTimer = (&D_800C4E60_de)[1];
    }

    temp_s1 = ((Shared_Particle *)particle)->desc;
    if (Particle_HasSurfaceFlag(particle) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    events = temp_s1->events;
    temp_v1 = (char *)events + temp_a1;
    model = events->particles[var_a0];
    temp_a2 = events->effects[var_a0];
    temp_v0_2 = (char *)events + (var_a0 * 8);
    pair = events->parameters[var_a0];
    temp_s3 = temp_s1->events->sounds[var_a0];
    if (temp_a2 != 0xFFFF) {
        System_DeliverContactEffect(particle, particle, temp_a2, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (model != 0xFFFF) {
        Render_SpawnChildEffect(particle, model, ((Shared_Particle *)particle)->space, 1);
    }
    if (temp_s3 != 0xFFFF) {
        Render_PlaySoundAtPosition((s16)temp_s3, ((Shared_Particle *)particle)->inst.pos, 0, -1);
    }
    Particle_Release(&D_8011D8D0, particle);
    Particle_StopSound(particle);
}

extern u8 D_801462E3;




void func_80283064_de(void *actor, s32 *arg1) {
    s32 result;

    result = 0;
    if ((((Shared_Particle *)actor)->desc->flags) & 0x02000000) {
        if (((Shared_Particle *)actor)->flags & 2) {
            result = 2;
        } else if (D_801462E3 == 2) {
            result = 1;
        }
    }
    *arg1 |= result << 0x1E;
}
