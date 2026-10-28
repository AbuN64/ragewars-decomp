#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RENDER/SETN64_ADVANCEDISPLAYFRAME.H"
#include "RESMGR/X_PLUS.H"


extern void osCreateThread(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void osStartThread(s32 arg0);




extern s32 Scene_SetThreadPriority(s32 *, s32);





/* Advances the frame ring and alternates the color and depth buffer pointers for the next frame. */


extern unsigned int D_800D2978;

extern int D_800CD730;


void SetN64_StartBootstrapThread(void) {
    XPlus_FillMemory((s32)D_800E7C00, 0, 0x80);
    osCreateThread((s32)D_8011B590, 0, D_0029350C, 0, (s32)(D_800E7C00 + 0x80), D_800CD8A4_de);
    osStartThread((s32)D_8011B590);
}

void SetN64_StartGameThreadAndIdle(s32 *gameSession, s32 threadArgument) {
    XPlus_FillMemory((s32)D_800E7C80_de, 1, 0x8000);
    osCreateThread((s32)D_8011B7C0, 1, D_00293534, threadArgument, (s32)D_800EFC80_de, D_800CD8B4);
    osStartThread((s32)D_8011B7C0);
    {
        s32 temp = D_800CD8A0_de;
        ((GameSession *)gameSession)->enabled = 0;
        Scene_SetThreadPriority(0, temp);
    }
loop_1:
    goto loop_1;
}

void SetN64_AdvanceDisplayFrame(Display *display) {
 unsigned int index; Frame *frame;
 index=++D_800D2978%D_800DE850;
 D_800CD730++;
 D_800D297C^=1;
 display->current=&display->frames[index];
 display->current->commands = D_800D297C ? D_8014D464 : D_8014D460;
 frame = display->current;
 frame->secondCommands = D_800D297C ? D_8014D42C : D_8014D430_de;
}
