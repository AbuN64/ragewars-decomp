#include "include_asm.h"
#include "ENGINE/GHOT.H"

/* Attachment event dispatch. Reference logic/order adapted to current symbols and shared types. */
#include "FX/EXTERNS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "FX/ATTACHMENT_EFFECT_ARGS.H"
#include "COMMON/OBJRECAT4V7.H"
#include "ENGINE/GHOT.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "TYPES.H"
#include "particle/80271B18_3.H"

extern char D_8011D8D0;
extern void GraphU64_ScaleVector(void *, void *, f32);
extern void InstHdr_CopyActorPositionAndModel(void *, Triple, Triple *, s32 *, s32, s32);
extern struct Shape_typemap_165 GraphU64_BuildDirectionQuaternion(Triple *);
#include "particle/8027A0F4_8.H"
extern void Events_DeliverContactEffect(void *, void *, s32, s32, Triple, AttachmentEffectArgs);

void Ghot_DispatchAttachmentEffects(func_8026E5E0_S1 *effectAttachments, s32 attachmentsRemaining, struct MatrixF *attachmentMatrices, func_8026E5E0_S3 *actor, AttachmentTable *attachmentNodes) {
    Triple pos;
    Triple mapped;
    Triple zero;
    struct Shape_typemap_165 rotation;
    AttachmentEffectArgs params;
    s32 room;
    f32 actorParticleScale;
    f32 lifetime;
    s32 actorDefinitionKind;
    s32 attachmentEffectFlags;
    s32 particleLifeRange;
    u16 attachmentNodeIndex;
    u32 attachmentMask;
    u8 *node;
    ObjRecAt4V7 *effectBinding;

    attachmentsRemaining = attachmentsRemaining - 1;
    if (attachmentsRemaining != -1) {
        do {
            effectBinding = (void *)&effectAttachments->unkC;
            if (effectBinding->unk0 & actor->unk2E0) {
                attachmentNodeIndex = effectBinding->unk4;
                node = attachmentNodes->bytes + attachmentNodeIndex * attachmentNodes->stride;
                attachmentEffectFlags = (*node == 5) * 2;
                GraphU64_TransformPoint(&attachmentMatrices[attachmentNodeIndex], effectAttachments, &pos);
                GraphU64_ScaleVector(&pos, &pos, 0.000015258789f);
                particleLifeRange = 0;
                attachmentMask = effectBinding->unk0;
                switch (attachmentMask) {                  /* irregular */
#if !defined(VERSION_DE)
                case 0x2:
                    Barrel_SpawnActorEffect(actor, 0x51, pos, attachmentEffectFlags);
                    break;
                case 0x8:
                    Barrel_SpawnActorEffect(actor, 0x5C, pos, attachmentEffectFlags);
                    break;
#endif
                case 0x1:
                case 0x4:
                case 0x10:
                case 0x20:
                    break;
                case 0x40:
                    actor->unk248 = pos;
                    actorDefinitionKind = *actor->unk18;
                    if (((actorDefinitionKind == 1) && (actor->unk1A4 == 0x21)) || ((actorDefinitionKind == 0xB) && (actor->unk1D8->unk650 == 0x26))) {
                        InstHdr_CopyActorPositionAndModel(actor, pos, &mapped, &room, 0, 1);
                        rotation = GraphU64_BuildDirectionQuaternion(&actor->unk254);
                        zero.x = 0;
                        zero.y = 0;
                        zero.z = 0;
                        if (actor->unk1B0 <
#if defined(VERSION_US)
                            D_800C4960_eu
#elif defined(VERSION_EU)
                            D_800C4960_eu
#elif defined(VERSION_EU_X)
                            D_800C4960_eu
#elif defined(VERSION_DE)
                            D_800C46B0
#else
                            D_800C4960_eu
#endif
                        ) {
                            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0xE6, *(CVector3 *)&zero, *(CQuatern *)&rotation, *(CVector3 *)&mapped, 0, -1, attachmentEffectFlags | 1);
                        }
                        func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x8A, *(CVector3 *)&zero, *(CQuatern *)&rotation, *(CVector3 *)&mapped, 0, -1, attachmentEffectFlags | 1);
                    }
                    break;
                case 0x80:
                    Barrel_SpawnActorEffect(actor, 0xAC, pos, attachmentEffectFlags);
                    break;
                case 0x100:
                    Barrel_SpawnActorEffect(actor, 0xAD, pos, attachmentEffectFlags);
                    break;
                case 0x200:
                    Barrel_SpawnActorEffect(actor, 0xAE, pos, attachmentEffectFlags);
                    break;
                case 0x400:
                    Barrel_SpawnActorEffect(actor, 0xAF, pos, attachmentEffectFlags);
                    break;
                case 0x800:
                    Barrel_SpawnActorEffect(actor, 0xB0, pos, attachmentEffectFlags);
                    break;
                case 0x1000:
                    Barrel_SpawnActorEffect(actor, 0xB1, pos, attachmentEffectFlags);
                    break;
                case 0x2000:
                    Barrel_SpawnActorEffect(actor, 0xB2, pos, attachmentEffectFlags);
                    break;
                case 0x4000:
                    Barrel_SpawnActorEffect(actor, 0xB3, pos, attachmentEffectFlags);
                    break;
                case 0x8000:
                    Barrel_SpawnActorEffect(actor, 0xB4, pos, attachmentEffectFlags);
                    break;
                case 0x10000:
                    Barrel_SpawnActorEffect(actor, 0xB5, pos, attachmentEffectFlags);
                    break;
                case 0x20000:
                    Barrel_SpawnActorEffect(actor, 0xB6, pos, attachmentEffectFlags);
                    break;
                case 0x40000:
                    Barrel_SpawnActorEffect(actor, 0xB7, pos, attachmentEffectFlags);
                    break;
                case 0x80000:
                    Barrel_SpawnActorEffect(actor, 0xB8, pos, attachmentEffectFlags);
                    break;
                case 0x100000:
                    Barrel_SpawnActorEffect(actor, 0xB9, pos, attachmentEffectFlags);
                    break;
                case 0x200000:
                    Barrel_SpawnActorEffect(actor, 0xBA, pos, attachmentEffectFlags);
                    break;
                case 0x400000:
                    Barrel_SpawnActorEffect(actor, 0xBB, pos, attachmentEffectFlags);
                    break;
                case 0x20000000:
                    Barrel_SpawnActorEffect(actor, 0x1E9, pos, attachmentEffectFlags);
                    break;
                case 0x40000000:
                    Barrel_SpawnActorEffect(actor, 0x1EA, pos, attachmentEffectFlags);
                    break;
                case 0x80000000:
                    Barrel_SpawnActorEffect(actor, 0x1EB, pos, attachmentEffectFlags);
                    break;
                case 0x8000000:
                    Barrel_SpawnActorEffect(actor, 0x11C, pos, attachmentEffectFlags);
                    break;
                case 0x10000000:
                    actor->unk260 = pos;
                    break;
                case 0x800000:
                    particleLifeRange = 5;
                    break;
                case 0x1000000:
                    particleLifeRange = 0xA;
                    break;
                case 0x2000000:
                    particleLifeRange = 0xF;
                    break;
                case 0x4000000:
                    particleLifeRange = 0x14;
                    break;
                }
                if (particleLifeRange != 0) {
                    actorParticleScale = func_8024BF24_de(actor);
                    params.fields.lifeRange = particleLifeRange << 8;
                    params.fields.countRange = 0;
                    params.fields.countBase = 0;
                    params.fields.modifier = 0;
                    params.fields.chance = 0;
#if defined(VERSION_US)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_EU)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_EU_X)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_DE)
                    lifetime = D_800C46B4;
#else
                    lifetime = D_800C4964_eu;
#endif
                    lifetime /= actorParticleScale;
#if defined(VERSION_US)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_EU)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_EU_X)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_DE)
                    lifetime *= D_800C46B8;
#else
                    lifetime *= D_800C4968_eu;
#endif
                    params.fields.lifeBase = (s16)(s32)lifetime;
                    Events_DeliverContactEffect(actor, actor, 3, -1, pos, params);
                }
            }
            effectAttachments++;
            attachmentsRemaining -= 1;
        } while (attachmentsRemaining != -1);
    }
}

#if !(defined(VERSION_DE) || defined(VERSION_US_REV1))
const unsigned int D_8026E5E0_CA3A0[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C45EC[1] = {
    0x740E6D5F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C49AC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C496C[1] = {
    0x4491A000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8026E5E0_CA3A0_us_rev1.c */
const unsigned int D_blob_66088a10f518a8d8ca1f[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif
