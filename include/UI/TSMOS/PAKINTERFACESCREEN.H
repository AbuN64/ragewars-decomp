#ifndef UI_TSMOS_PAKINTERFACESCREEN_H
#define UI_TSMOS_PAKINTERFACESCREEN_H
#include "TYPES.H"
/* The Pak interface screen of the frontend resource image (UI/TSMOS/SCREENS/PAKINTERFACESCREEN.CPP): its callbacks take the
   screen manager's four event words; g_pakInterfaceScreen is the file's static pointer to the screen, 0 while none exists. */
#define PAKINTERFACE_MAX_USERS 4
typedef struct PAKInterfaceScreenPanel {
    char pad0[24];
    s32 state;
    char pad1C[2912 - 28];
    s32 field_B60;
    s32 field_B64;
} PAKInterfaceScreenPanel;
typedef struct PAKInterfaceScreen {
    char pad0[64];
    PAKInterfaceScreenPanel panel[PAKINTERFACE_MAX_USERS + 1];
} PAKInterfaceScreen;
extern PAKInterfaceScreen *g_pakInterfaceScreen;
extern s32 PAKInterface_OnInitialUpdate(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnDestroy(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnButtonUp(s32 a, s32 b, s32 c, s32 d);
#endif
