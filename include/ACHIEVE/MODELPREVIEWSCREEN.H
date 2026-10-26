#ifndef ACHIEVE_MODELPREVIEWSCREEN_H
#define ACHIEVE_MODELPREVIEWSCREEN_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/MENU_SCREEN_SETUP.H"



extern ModelPreviewScreen *D_800E5830;

extern s32 Frontend_SetPreviewModel(void *,s32);


#if defined(VERSION_DE)
enum { MENU_804387F4_642 = 638, PREVIEW_ID_SHIFT = 0 };
#elif defined(VERSION_EU_X)
enum { MENU_804387F4_642 = 647, PREVIEW_ID_SHIFT = 9 };
#else
enum { MENU_804387F4_642 = 642, PREVIEW_ID_SHIFT = 4 };
#endif
#endif
