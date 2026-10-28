#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 1 whose id matches the given object's id. */







extern RecordRecAt2C *D_800D052C[];

s32 Particle_HasKindOneEntry(ObjRecAt4V5 *obj) {
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








s32 Particle_HasKindZeroEntry(ObjRecAt4V5 *obj) {
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

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 2 whose id matches the given object's id. Adapted from Particle_HasKindOneEntry with the entry kind changed from 1 to 2. */








s32 Particle_HasKindTwoEntry(ObjRecAt4V5 *obj) {
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



extern s32 SoundElement_PlaySoundAtPosition(s16, CVector3, s32, s32);
extern void func_8022B550_de(void *, f32, f32, void *, s32);
extern void CScene_StartEventClips(void *, void *, s32, Triple, f32, f32);

extern void Events_DeliverContactEffect(void *, void *, s32, s32, CVector3, struct IntPair);
extern void Particle_SpawnChildEffect(void *, s32, s8, s32);
extern void Particle_Release(void *, void *);















void func_80282E98_de(void *particle, void *player) {
    Triple scratch;
    struct IntPair pair;
    s32 eventHalfwordOffset;
    struct Shared_ParticleEvents *events;
    s32 contactEventIndex;
    s32 contactEffectId;
    s32 model;
    s32 contactSoundId;
    struct Shared_ParticleDesc *particleDescription;
    void *eventParameterAddress;
    void *eventHalfwordAddress;

    XPlus_FillMemory(&scratch, 0, 0xC);
    if (((Shared_Particle *)particle)->inst.type == 0x40F) {
        SoundElement_PlaySoundAtPosition(0xCDA, ((Shared_ActorView *)player)->position.vector,
                      (s32)&((Shared_ActorView *)player)->position.vector, -1);
        func_8022B550_de(player, 30.0f, 3.0f,
                     ((Shared_Particle *)particle)->owner, 0);
        CScene_StartEventClips(&g_world,
                      (char *)((Shared_ActorView *)player)->controller + 0x140,
                      0x14, scratch, D_800C4E58_de[1], D_800C4E60_de);
        ((Shared_ActorView *)player)->impactTimer = (&D_800C4E60_de)[1];
    }

    particleDescription = ((Shared_Particle *)particle)->desc;
    if (Particle_HasSurfaceFlag(particle) != 0) {
        contactEventIndex = 0xC;
    } else {
        contactEventIndex = 0xA;
    }
    eventHalfwordOffset = contactEventIndex * 2;
    events = particleDescription->events;
    eventHalfwordAddress = (char *)events + eventHalfwordOffset;
    model = events->particles[contactEventIndex];
    contactEffectId = events->effects[contactEventIndex];
    eventParameterAddress = (char *)events + (contactEventIndex * 8);
    pair = events->parameters[contactEventIndex];
    contactSoundId = particleDescription->events->sounds[contactEventIndex];
    if (contactEffectId != 0xFFFF) {
        Events_DeliverContactEffect(particle, particle, contactEffectId, -1,
                     ((Shared_Particle *)particle)->inst.pos, pair);
    }
    if (model != 0xFFFF) {
        Particle_SpawnChildEffect(particle, model, ((Shared_Particle *)particle)->space, 1);
    }
    if (contactSoundId != 0xFFFF) {
        SoundElement_PlaySoundAtPosition((s16)contactSoundId, ((Shared_Particle *)particle)->inst.pos, 0, -1);
    }
    Particle_Release(&D_8011D8D0, particle);
    Particle_StopSound(particle);
}





void Particle_EncodeRenderLayer(void *actor, s32 *arg1) {
    s32 result;

    result = 0;
    if ((((Shared_Particle *)actor)->desc->flags) & 0x02000000) {
        if (((Shared_Particle *)actor)->flags & 2) {
            result = 2;
        } else if (D_801462C8.firstListMode == 2) {
            result = 1;
        }
    }
    *arg1 |= result << 0x1E;
}
