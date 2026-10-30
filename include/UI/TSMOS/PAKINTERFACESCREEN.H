#ifndef UI_TSMOS_PAKINTERFACESCREEN_H
#define UI_TSMOS_PAKINTERFACESCREEN_H
#include "TYPES.H"
/* The Pak interface screen of the frontend resource image (UI/TSMOS/SCREENS/PAKINTERFACESCREEN.CPP): its callbacks take the
   screen manager's four event words; g_pakInterfaceScreen is the file's static pointer to the screen, 0 while none exists. */
extern void *g_pakInterfaceScreen;
extern s32 PAKInterface_OnInitialUpdate(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnDestroy(s32 a, s32 b, s32 c, s32 d);
#endif
