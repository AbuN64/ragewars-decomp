#ifndef SDK_PFS_PLAYER_DRAWPULSINGMENUSPRITE_H
#define SDK_PFS_PLAYER_DRAWPULSINGMENUSPRITE_H
#include "COMMON/ACTORRECAT260.H"
extern s32 Player_RespawnItemPlayer(void *unused0, StateRecAt1C *arg1);
extern int Player_ResumePlayerFromMenu(int unused, PlayerRecAt1C *player);
extern void Player_DrawPulsingMenuSprite(ObjRecAt1CV1 *arg0, CaptionEntry *arg1, s32 arg2, MenuStyle *arg3);
extern s32 Player_SetNestedItemFlag(void *unused, struct RootRecAt1C *root);
extern s32 Player_UpdatePlayerRespawnDelay(StateRecAt1C *arg0);
#endif
