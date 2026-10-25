#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RENDER/80291054_7.H"
#include "RESMGR/802A0888.H"


extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_802BB750_de(s32 arg0);




extern s32 func_802BB5F0_de(s32 *, s32);





/* Advances the frame ring and alternates the color and depth buffer pointers for the next frame. */


extern unsigned int D_800D2978;

extern int D_800CD730,D_800D297C;


void func_80292F48_de(void) {
    Resmgr_FillMemory((s32)D_800E7C00, 0, 0x80);
    func_802BAC90_de((s32)D_8011B590, 0, D_0029350C, 0, (s32)(D_800E7C00 + 0x80), D_800CD8A4_de);
    func_802BB750_de((s32)D_8011B590);
}

void func_80292FC0_de(s32 *gameSession, s32 arg1) {
    Resmgr_FillMemory((s32)D_800E7C80_de, 1, 0x8000);
    func_802BAC90_de((s32)D_8011B7C0, 1, D_00293534, arg1, (s32)D_800EFC80_de, D_800CD8B4);
    func_802BB750_de((s32)D_8011B7C0);
    {
        s32 temp = D_800CD8A0_de;
        ((GameSession *)gameSession)->enabled = 0;
        func_802BB5F0_de(0, temp);
    }
loop_1:
    goto loop_1;
}

void func_80293054_de(Display *display) {
 unsigned int index; Frame *frame;
 index=++D_800D2978%D_800DE850;
 D_800CD730++;
 D_800D297C^=1;
 display->current=&display->frames[index];
 display->current->commands = D_800D297C ? D_8014D464 : D_8014D460;
 frame = display->current;
 frame->secondCommands = D_800D297C ? D_8014D42C : D_8014D430_de;
}
