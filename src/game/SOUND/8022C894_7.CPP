#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"
#include "RENDER_2/802192C0_3.H"

extern s32 Sound_FindActorModelEntry(void *);
extern s32 func_8024E62C_de(void *arg0);
extern f32 D_800C7F08;











void func_8022E6A4_de(Shared_ActorView *player, LevelActor *actor) {
    void *temp_v0;

    temp_v0 = Sound_FindActorModelEntry(actor);
    if ((temp_v0 != 0) && (((Shared_Surface *)temp_v0)->flags & 0x4000)) {
        actor->position1.y = 0;
    } else if (actor->position0.y < (D_801370C4 - D_800C7F08)) {
        Render_PlacePlayerAtSpawnPoint(player, player->spawn, 0, 0);
    }
    if (func_8024E62C_de(actor) != 0) {
        player->contactPosition = actor->position0;
    }
}
