#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "include_asm.h"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "particle/80271B18_3.H"



extern void GraphU64_GetMatrixTranslation(char *, f32 *);

extern char D_8011D8D0;

extern void Particle_ReleaseOwnerEmitters(void *arg0, s32 arg1);

void Player_SetPlayerResetPosition(void *actorObject, CVector3 *newResetPosition)
{
  Shared_ActorView *player = actorObject;
  void *new_var;
  player->resetPosition = *newResetPosition;
  new_var = actorObject;
  Player_SetPlayerState(new_var, new_var, 0x11);
}

extern void Player_BuildPlayerViewTransform(void *, MatrixF *);
void func_8022B09C_de(void *player, CVector3 *point) {
    CVector3 input;
    MatrixF matrix;
    CVector3 *input_ptr;
    MatrixF *matrix_ptr;

    func_8022B08C_S1 *object = player;
    func_8022B08C_S2 *owner;

    input = *point;
    input_ptr = &input;
    matrix_ptr = object->unk5DC;

    if (matrix_ptr != 0) {
        owner = (void *)matrix_ptr;
        matrix_ptr = &owner->unk160;
    } else {
        Player_BuildPlayerViewTransform(player, &matrix);
        matrix_ptr = &matrix;
    }
    GraphU64_TransformPoint(matrix_ptr, input_ptr, point);
}

void func_8022B11C_de(void *player, s32 increment) {
    u16 wrappedSum;
    u16 cappedCounter;
    wrappedSum = (((struct ObjectState16DA *) ((s8 *) player))->unk_16D8) + increment;
    cappedCounter = wrappedSum;
    (((struct ObjectState16DA *) ((s8 *) player))->unk_16D8) = wrappedSum;
    if ((u32) (cappedCounter & 0xFFFF) >= 0x65U) {
        cappedCounter = 0x64;
    }
    (((struct ObjectState16DA *) ((s8 *) player))->unk_16D8) = cappedCounter;
}

void func_8022B144_de(void *player, f32 *origin) {
    MatrixF viewTransform;
    Player_BuildPlayerViewTransform(player, &viewTransform);
    GraphU64_GetMatrixTranslation((char *)&viewTransform, origin);
}

/** Report whether the word at offset 0x5E4 is zero. */
int func_8022B178_de(struct SharedPlayer *player) {
    return player->views5E4.view5E4_0.unk5E4 == 0;
}

/** Return the word at offset 0x1210. */
int func_8022B184_de(struct SharedPlayer *object) {
    return object->views5E8.view1210_152.unk1210;
}

void func_8022B190_de(s32 actor) {
    Particle_ReleaseOwnerEmitters(&D_8011D8D0, actor);
}

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"
extern u8 *D_800D311C, *D_800D3120, *D_800D3124;
extern void BuildDirectionMatrix(Matrix *, CVector3 *);
extern void GraphU64_ScaleVector(CVector3 *out, CVector3 *in, f32 scale);
extern void GraphU64_AddVec3(CVector3 *result, CVector3 *left, CVector3 *right);
extern void TranslateMatrix(Matrix *, f32 x, f32 y, f32 z);
extern void SwapMatrixUpForward(Matrix *);
extern void GraphU64_ConvertMatrixToFixed(Matrix *src, void *dst);
/* Copy of Playerai_BuildForceMarkerTransform: orients the marker matrix along the aim normal, moves it to the marker origin
 * pushed 5.12 units off the surface and packs it into the player's marker transform. */
static inline void buildForceMarkerTransform(Shared_ActorView *player, s32 attract, CVector3 *normal) {
    Matrix matrix;
    CVector3 offset;
    BuildDirectionMatrix(&matrix, normal);
    GraphU64_ScaleVector(&offset, normal, 5.12f);
    GraphU64_AddVec3(&offset, &offset, &player->targetPosition);
    TranslateMatrix(&matrix, offset.x, offset.y, offset.z);
    SwapMatrixUpForward(&matrix);
    GraphU64_ConvertMatrixToFixed(&matrix, player->transform1600);
}
/* Toggles the player's attract/repulse marker while the aim ray hits something: a live marker is removed
 * ("ATTRACT REMOVED"); otherwise a new one is placed at the aim point for 150 frames, pulling when
 * attract is set ("ATTRACT MARKED") and pushing otherwise ("REPULSE MARKED"). */
void Playerai_ToggleForceMarker(Shared_ActorView *player, s32 attract) {
    void *screen;
    u8 *text;
    if (player->aimTarget != 0) {
        if (player->marker.time > 0.0f) {
            player->marker.time = 0;
            SoundElement_PlayFlatSound(0x578);
            screen = player->message;
            if (screen == 0) return;
            text = D_800D311C;
        } else {
            player->targetPosition = player->aimPoint;
            player->attract = attract;
            player->marker.time = 150.0f;
            buildForceMarkerTransform(player, attract, &player->aimNormal);
            SoundElement_PlayFlatSound(0x578);
            screen = player->message;
            if (screen == 0) return;
            if (attract != 0) text = D_800D3120;
            else text = D_800D3124;
        }
        Camera_PostScreenMessage((void *)&D_80145088, screen, text);
    }
}
#endif
