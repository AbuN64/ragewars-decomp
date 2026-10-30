#ifndef UI_TSMOS_PAKINTERFACESCREEN_H
#define UI_TSMOS_PAKINTERFACESCREEN_H
#include "TYPES.H"
/* The Pak interface screen of the frontend resource image (UI/TSMOS/SCREENS/PAKINTERFACESCREEN.CPP): its callbacks take the
   screen manager's four event words; g_pakInterfaceScreen is the file's static pointer to the screen, 0 while none exists. */
#define PAKINTERFACE_MAX_USERS 4
typedef struct PAKInterfaceScreenPanel {
    char pad0[24];
    s32 state;
    s32 field_1C;
    s32 field_20;
    s32 field_24;
    char pad28[4];
    s32 field_2C;
    char pad30[0xAF0 - 0x30];
    s32 field_AF0;
    char pad_AF4[0xB04 - 0xAF4];
    s32 field_B04;
    char pad_B08[0xB40 - 0xB08];
    s32 field_B40;
    s32 field_B44;
    s32 field_B48;
    char pad_B4C[0xB5C - 0xB4C];
    s32 field_B5C;
    s32 field_B60;
    s32 field_B64;
} PAKInterfaceScreenPanel;
typedef struct PAKInterfaceScreen {
    s32 field_0;
    s32 field_4;
    char pad8[0x24 - 0x8];
    s32 field_24;
    s32 field_28;
    s32 field_2C;
    char pad30[0x3C - 0x30];
    s32 field_3C;
    PAKInterfaceScreenPanel panel[PAKINTERFACE_MAX_USERS + 1];
} PAKInterfaceScreen;
extern PAKInterfaceScreen *g_pakInterfaceScreen;
extern s32 PAKInterface_OnInitialUpdate(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnDestroy(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnButtonUp(s32 a, s32 b, s32 c, s32 d);
#endif
