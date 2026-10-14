#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_804366C4.h"
#include "types.h"


/* Builds screen state D_800E5694 under a parent window: allocates its 0x50 bytes, opens lists 0x1C9, 0x1D1 and 0x1CB filled with the entries in D_800D74xx at 0x0C, 0x08 and 0x10, opens panels 0x1CF and 0x1CD at 0x0 and 0x4, opens window 0x1C7 at 0x18, clears the word at 0x14, resets through func_804368F8_de(0) and returns zero.
   Adapted from func_8041C2AC_de with the window openings changed to the list, panel and window calls of this screen and the list entry words declared as arrays. */

extern MenuListScreen *D_800E5694;
extern s32 D_800D3470_de[];
extern s32 D_800D3474[];
extern s32 D_800D34A4[];
extern s32 D_800D34B0[];
extern s32 D_800D34B4[];
extern s32 D_800D34B8[];
extern s32 D_800D34BC[];
extern MenuListScreen *func_8025305C_de(s32);

extern void *func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(void *, s32);
extern void *func_8041A580_de(s32, s32, s32);
extern void *func_8040EC30_de(void *, s32);
extern void func_804368F8_de(s32);

#if defined(VERSION_DE)
enum { MENU_80437074_454 = 450, MENU_80437074_455 = 451, MENU_80437074_456 = 452, MENU_80437074_457 = 453, MENU_80437074_458 = 454, MENU_80437074_459 = 455, MENU_80437074_460 = 456, MENU_80437074_461 = 457, MENU_80437074_462 = 458, MENU_80437074_463 = 459, MENU_80437074_464 = 460, MENU_80437074_465 = 461, MENU_80437074_466 = 462 };
#else
enum { MENU_80437074_454 = 454, MENU_80437074_455 = 455, MENU_80437074_456 = 456, MENU_80437074_457 = 457, MENU_80437074_458 = 458, MENU_80437074_459 = 459, MENU_80437074_460 = 460, MENU_80437074_461 = 461, MENU_80437074_462 = 462, MENU_80437074_463 = 463, MENU_80437074_464 = 464, MENU_80437074_465 = 465, MENU_80437074_466 = 466 };
#endif

s32 func_80436E94_de(void *parent) {
    void *list;

    D_800E5694 = func_8025305C_de(0x50);
    func_8041B110_de(MENU_80437074_454);
    list = func_8041ABC0_de(MENU_80437074_457, MENU_80437074_458);
    D_800E5694->listA = list;
    func_8041AD34_de(list, D_800D34A4[0]);
    func_8041AD34_de(D_800E5694->listA, D_800D34B0[0]);
    list = func_8041ABC0_de(MENU_80437074_465, MENU_80437074_466);
    D_800E5694->listB = list;
    func_8041AD34_de(list, D_800D3470_de[0]);
    func_8041AD34_de(D_800E5694->listB, D_800D3474[0]);
    D_800E5694->panels[0] = func_8041A580_de(MENU_80437074_463, MENU_80437074_464, 0xFF);
    D_800E5694->panels[1] = func_8041A580_de(MENU_80437074_461, MENU_80437074_462, 0xFF);
    list = func_8041ABC0_de(MENU_80437074_459, MENU_80437074_460);
    D_800E5694->listC = list;
    func_8041AD34_de(list, D_800D34B4[0]);
    func_8041AD34_de(D_800E5694->listC, D_800D34B8[0]);
    func_8041AD34_de(D_800E5694->listC, D_800D34BC[0]);
    func_8041B110_de(MENU_80437074_456);
    D_800E5694->window = func_8040EC30_de(parent, MENU_80437074_455);
    D_800E5694->selection = 0;
    func_804368F8_de(0);
    return 0;
}
