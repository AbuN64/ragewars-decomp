#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MENU/PLAYER_STOREALTERNATEPLAYERSETTINGSENTRY.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Builds screen state D_800E5694 under a parent window: allocates its 0x50 bytes, opens lists 0x1C9, 0x1D1 and 0x1CB filled with the entries in D_800D74xx at 0x0C, 0x08 and 0x10, opens panels 0x1CF and 0x1CD at 0x0 and 0x4, opens window 0x1C7 at 0x18, clears the word at 0x14, resets through Player_SelectAlternatePlayerSettingsEntry(0) and returns zero.
   Adapted from SmpOverlay_CreatePakDialog with the window openings changed to the list, panel and window calls of this screen and the list entry words declared as arrays. */

extern MenuListScreen *D_800E5694;
extern MenuListScreen *Cache_AllocateMemory(s32);

extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, s32);
extern void *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void *Node_FindWidgetByResourceId(void *, s32);

#if defined(VERSION_DE)
enum { MENU_80437074_454 = 450, MENU_80437074_455 = 451, MENU_80437074_456 = 452, MENU_80437074_457 = 453, MENU_80437074_458 = 454, MENU_80437074_459 = 455, MENU_80437074_460 = 456, MENU_80437074_461 = 457, MENU_80437074_462 = 458, MENU_80437074_463 = 459, MENU_80437074_464 = 460, MENU_80437074_465 = 461, MENU_80437074_466 = 462 };
#else
enum { MENU_80437074_454 = 454, MENU_80437074_455 = 455, MENU_80437074_456 = 456, MENU_80437074_457 = 457, MENU_80437074_458 = 458, MENU_80437074_459 = 459, MENU_80437074_460 = 460, MENU_80437074_461 = 461, MENU_80437074_462 = 462, MENU_80437074_463 = 463, MENU_80437074_464 = 464, MENU_80437074_465 = 465, MENU_80437074_466 = 466 };
#endif

s32 Player_BuildItemLabelList(void *parent) {
    void *list;

    D_800E5694 = Cache_AllocateMemory(0x50);
    SmpButton_WrapButtonWidget(MENU_80437074_454);
    list = SmpButton_CreateListWidget(MENU_80437074_457, MENU_80437074_458);
    D_800E5694->listA = list;
    SmpButton_AppendListText(list, D_800D34A4[0]);
    SmpButton_AppendListText(D_800E5694->listA, D_800D34B0[0]);
    list = SmpButton_CreateListWidget(MENU_80437074_465, MENU_80437074_466);
    D_800E5694->listB = list;
    SmpButton_AppendListText(list, D_800D3470_de[0]);
    SmpButton_AppendListText(D_800E5694->listB, D_800D3474[0]);
    D_800E5694->panels[0] = SmpSlider_CreateSliderWidget(MENU_80437074_463, MENU_80437074_464, 0xFF);
    D_800E5694->panels[1] = SmpSlider_CreateSliderWidget(MENU_80437074_461, MENU_80437074_462, 0xFF);
    list = SmpButton_CreateListWidget(MENU_80437074_459, MENU_80437074_460);
    D_800E5694->listC = list;
    SmpButton_AppendListText(list, D_800D34B4[0]);
    SmpButton_AppendListText(D_800E5694->listC, D_800D34B8[0]);
    SmpButton_AppendListText(D_800E5694->listC, D_800D34BC[0]);
    SmpButton_WrapButtonWidget(MENU_80437074_456);
    D_800E5694->window = Node_FindWidgetByResourceId(parent, MENU_80437074_455);
    D_800E5694->selection = 0;
    Player_SelectAlternatePlayerSettingsEntry(0);
    return 0;
}
#endif
