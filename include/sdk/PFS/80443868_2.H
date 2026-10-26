#ifndef SDK_PFS_80443868_2_H
#define SDK_PFS_80443868_2_H
#include "COMMON/ACTORRECAT260.H"
extern s32 Items_RespawnItemPlayer(void *arg0, StateRecAt1C *arg1);
extern int Items_ResumePlayerFromMenu(int unused, PlayerRecAt1C *player);
extern void Items_DrawPulsingMenuSprite(ObjRecAt1CV1 *arg0, CaptionEntry *arg1, s32 arg2, MenuStyle *arg3);
extern s32 Items_SetNestedItemFlag(void *unused, struct RootRecAt1C *root);
extern s32 Items_UpdatePlayerRespawnDelay(StateRecAt1C *arg0);
#endif
