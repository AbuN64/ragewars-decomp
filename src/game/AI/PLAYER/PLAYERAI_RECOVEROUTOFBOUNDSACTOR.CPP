#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"
#include "RENDER/PLAYER_SPAWN_PLACEMENT.H"

extern s32 InstHdr_FindActorModelEntry(void *);
extern s32 InstHdr_GetActorMotionState(void *levelActor);
extern f32 D_800C7F08;











void Playerai_RecoverOutOfBoundsActor(Shared_ActorView *player, LevelActor *actor) {
    void *actorModelEntryResult;

    actorModelEntryResult = InstHdr_FindActorModelEntry(actor);
    if ((actorModelEntryResult != 0) && (((Shared_Surface *)actorModelEntryResult)->flags & 0x4000)) {
        actor->position1.y = 0;
    } else if (actor->position0.y < (D_801370C4 - D_800C7F08)) {
        Player_PlacePlayerAtSpawnPoint(player, player->spawn, 0, 0);
    }
    if (InstHdr_GetActorMotionState(actor) != 0) {
        player->contactPosition = actor->position0;
    }
}
