#include "COMMON/EXTERNS_6.H"
#include "RENDER/OBJECTSTATE8E.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/OBJECTSTATE18.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "ENGINE/SCENE_DRAWOPAQUEACTORS.H"




extern f32 Gobjinst_GetActorHeight(void *arg0);

extern void Scene_SampleWorldLighting(void *arg0, void *arg1, void *arg2);

extern void Gobjinst_DrawVisibleCachedActor(void *arg0, void *arg1);

extern void Player_DrawRedMarkerPrism(void *arg0, void *arg1);


#include "COMMON/GAME_SESSION.H"

extern void SetN64_ClearDepthRect(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

void Player_DrawPlayerModel(void *player, void *camera) {
    CVector3 pos;
    s32 value;
    Gfx *cmd;

    pos = ((LevelActor *)player)->position0;
    pos.y += ((LevelActor *)player)->eyeHeight;
    pos.y += Gobjinst_GetActorHeight(player) * ((D_800C7470_Pair *)&D_800C22B0_us)->second;
    Scene_SampleWorldLighting(&g_world, &pos,
                  &((LevelActor *)player)->lighting[D_800D297C]);

    value = 0x66;
    if (D_801462C8.local != 0) {
        if ((D_801468F4 != 0) &&
            (((Shared_ActorView *)player)->controls->transientFlag != 0)) {
            value = D_800CE47C;
        } else {
            value = D_800CE430[((MovementDescriptor *)((LevelActor *)player)->definition)->body.header.character];
            ((LevelActor *)player)->field3 =
                ((Shared_ActorView *)player)->controls->playerId;
        }
    }
    ((void (*)(void *, void *, s32, s32))Scene_ChangeInstanceModel)(&g_world, player, value,
                  ((Shared_ActorView *)player)->effectId);

    cmd = g_displayListCursor++;
    gDPPipeSync(cmd);
    cmd = g_displayListCursor++;
    gDPSetCycleType(cmd, G_CYC_2CYCLE);
    cmd = g_displayListCursor++;
    gSPGeometryMode(cmd, 0, G_FOG);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 4, 2);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 12, 2);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 20, 0xFFFE);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 28, 0xFFFE);

    Gobjinst_DrawVisibleCachedActor(player, camera);
    if (((Shared_ActorView *)player)->targeting != 0) {
        Player_DrawRedMarkerPrism(player, camera);
    }
}

void Player_DrawHeldWeapon(void *player, WeaponMenuView *camera) {
    WeaponInfo *entry;
    f32 *rect;
    f32 x;
    f32 y;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    if ((((Shared_ActorView *)player)->selectedAction != -1) &&
        (((Shared_ActorView *)player)->lives != 0)) {
        gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
        gDPSetTexturePersp(g_displayListCursor++, G_TP_PERSP);
        Geometry_InvalidateMaterialKeys();

        entry = D_800D052C[((Shared_ActorView *)player)->selectedAction];
        rect = camera->viewport;
        x = rect[0];
        y = rect[1];
        left = entry->scopeBounds[0] * x + rect[2];
        right = entry->scopeBounds[2] * x + rect[2];
        top = entry->scopeBounds[1] * y + rect[3];
        bottom = entry->scopeBounds[3] * y + rect[3];
        SetN64_ClearDepthRect(&D_8011FAC0, (s32)left, (s32)right, (s32)top,
                      (s32)bottom, camera->clipMode);

        gSPGeometryMode(g_displayListCursor++, 0, G_FOG);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 4, 1);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 12, 1);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 20, 0xFFFF);
        gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 28, 0xFFFF);
        Geometry_BeginModelBatch();
        Gobjinst_DrawVisibleCachedActor(&((Shared_ActorView *)player)->weapon, camera);
        Geometry_FlushModelBatch();
    }
}
