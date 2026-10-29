#ifndef COMMON_SHARED_MENUREPLY_H
#define COMMON_SHARED_MENUREPLY_H
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SCREEN.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/ANIMATION.H"

int Cinema_IsSequenceInWindow(void);
void Cache_SetResourceActivityState(unsigned int);
void Menu_SetFocusedElement(s32);
void Tsmos_ActivateControllerState(void);
void SmpFlicker_StartFlicker(void *, int);
s32 Frontend_GetMenuImageState(Shared_OptionsScreen *);
void Player_InitializePlayerPool(void *, s32, s32);
void Pools_ResetActorPools(void *, s32);
void Scene_LoadLevelResources(void *, s32, s32);
void SmXlate_SwitchScreen(s32);

extern Shared_MenuReply g_selectionMessageReply;

extern Shared_OptionsScreen *g_optionsShortcutScreen;

/* Advances the menu transition and dispatches the selected level once its animations finish. */
#endif
