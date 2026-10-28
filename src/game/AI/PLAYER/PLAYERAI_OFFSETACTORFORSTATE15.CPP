#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "SOUND/EXTERNS.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"
#include "SOUND/PLAYERAI_OFFSETACTORFORSTATE15.H"

extern void func_8022D57C_de(void *);


extern s32 InstHdr_FindActorModelEntry(void *);

extern void Graphu64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern f32 Graphu64_GetHorizontalAngle(CVector3 *direction);

extern void func_80218464_de();

extern void func_80225F44_de(void *, void *);


void func_8022D60C_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D628_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x32); }

void func_8022D644_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D660_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x1E); }

void func_8022D67C_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D698_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x28); }

void func_8022D6B4_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D6D0_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xB); }

void func_8022D6EC_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D708_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xC); }

void func_8022D724_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D740_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xD); }

void func_8022D75C_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D778_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xE); }

void func_8022D794_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D7B0_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xF); }

void func_8022D7CC_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D7E8_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x14); }

void func_8022D804_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void func_8022D820_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x46); }

void func_8022D83C_de(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void Playerai_StartPlayerSequence60(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x3C); }

void Playerai_UpdateSequence60RunEndPose(void *sequencePlayer) { func_8022D57C_de(sequencePlayer); }

void Playerai_StartPlayerSequence71(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0x47); }

/** Thin wrapper around func_8022D57C_de. */
void Playerai_UpdateSequence71RunEndPose(void *sequencePlayer) {
    func_8022D57C_de(sequencePlayer);
}

/** Thin wrapper around Playerai_TryStartPlayerSequence with a fixed third argument. */
void Playerai_StartPlayerSequence72(void *a, void *b) {
    Playerai_TryStartPlayerSequence(a, b, 0x48);
}

/** Thin wrapper around func_8022D57C_de. */
void Playerai_UpdateSequence72RunEndPose(void *sequencePlayer) {
    func_8022D57C_de(sequencePlayer);
}

/** Thin wrapper around Playerai_TryStartPlayerSequence with a fixed third argument. */
void Playerai_StartPlayerSequence73(void *a, void *b) {
    Playerai_TryStartPlayerSequence(a, b, 0x49);
}

/** Thin wrapper around func_8022D57C_de. */
void Playerai_UpdateSequence73RunEndPose(void *sequencePlayer) {
    func_8022D57C_de(sequencePlayer);
}

/** Thin wrapper around Playerai_TryStartPlayerSequence with a fixed third argument. */
void Playerai_StartPlayerSequence74(void *a, void *b) {
    Playerai_TryStartPlayerSequence(a, b, 0x4A);
}

/** Thin wrapper around func_8022D57C_de. */
void Playerai_UpdateSequence74RunEndPose(void *sequencePlayer) {
    func_8022D57C_de(sequencePlayer);
}

void Playerai_InitializeActorModelEffect(void *effectPlayerState, void *sourceActor) {
    char *o = (char *)effectPlayerState;
    char *a1 = (char *)sourceActor;
    s32 actorModelEntry;
    CVector3 modelEffectOffset;
    CVector3 effectDisplacement;

    actorModelEntry = InstHdr_FindActorModelEntry(sourceActor);
    ((Shared_ActorView *)o)->effectModel = (void *)actorModelEntry;
    if (actorModelEntry != 0) {
        ((Shared_ActorView *)o)->modelState = 0;
        ((Shared_ActorView *)o)->effectPosition.x = ((LevelActor *)a1)->position0.x;
        ((Shared_ActorView *)o)->effectPosition.y = ((LevelActor *)a1)->position0.y;
        ((Shared_ActorView *)o)->effectPosition.z = ((LevelActor *)a1)->position0.z;
        modelEffectOffset.x = ((ModelBlend *)actorModelEntry)->effectOffset.x;
        modelEffectOffset.y = ((ModelBlend *)actorModelEntry)->effectOffset.y;
        modelEffectOffset.z = ((ModelBlend *)actorModelEntry)->effectOffset.z;
        Graphu64_SubtractVectors(&effectDisplacement, &modelEffectOffset, &((Shared_ActorView *)o)->effectPosition);
        effectDisplacement.y = 0.0f;
        ((Shared_ActorView *)o)->modelDistance = Graphu64_GetHorizontalAngle(&effectDisplacement);
    }
}

void Playerai_ClearPlayerWeaponLock(void *lockedPlayerState) {
    struct Player *player = lockedPlayerState;
    func_80218464_de(&player->weaponBusy);
    player->locked = 0;
}

void Playerai_EnterMovingSequenceState(void *player, void *body) {
    struct SharedPlayer *a0 = player;
    void *a1 = body;

    func_80225F44_de(player, body);
    if (a0->views5E8.view6C0_51.unk6C0 != 0.0f) {
        Player_SetPlayerState(a0, a1, 0x25);
    }
}

void Playerai_ResetPlayerWeaponLock(void *lockedPlayerState) {
    struct Player *player = lockedPlayerState;
    func_80218464_de(&player->weaponBusy);
    player->locked = 0;
}

void Playerai_EnterStoppedSequenceState(void *player, void *body) {
    struct SharedPlayer *a0 = player;
    void *a1 = body;

    func_80225F44_de(player, body);
    if (a0->views5E8.view6C0_51.unk6C0 == 0.0f) {
        Player_SetPlayerState(a0, a1, 0x24);
    }
}

void Playerai_OffsetActorForState15(Actor126 *actor, Object126 *positionedObject) {
    Object126 *object;
    f32 angle;
    f32 object_angle;
    f32 sine;
    f32 cosine;

    actor->flags |= 0x800000;
    actor->value1D4 = D_800C2DC8_de;
    if (actor->state652 == 15) {
        object = positionedObject;
        object_angle = object->angle;
        angle = D_800C2DCC_de;
        sine = Gu_Sinf(object_angle + angle);
        cosine = Math_Cosf(object->angle + angle);
        sine *= D_800C7EC0;
        cosine *= D_800C7EC0;
        object->x += sine;
        object->y += cosine;
        object->angle += actor->offset728;
        actor->offset728 = 0.0f;
    }
}
