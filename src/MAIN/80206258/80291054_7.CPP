#include "span_1000/code_80291054.h"
#include "gbi.h"
#include "gfx.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80293A04.h"
#include "TYPES.H"
#include "common/unused.h"

extern void func_802A001C_de(s32 arg0, s32 arg1, s32 arg2);

extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_802BB750_de(s32 arg0);




extern s32 func_802BB5F0_de(s32 *, s32);





/* Advances the frame ring and alternates the color and depth buffer pointers for the next frame. */


extern unsigned int D_800D2978;

extern int D_800CD730,D_800D297C;

extern int D_8014D464;

void func_80292F48_de(void) {
    func_802A001C_de((s32)D_800E7C00, 0, 0x80);
    func_802BAC90_de((s32)D_8011B590, 0, D_0029350C, 0, (s32)(D_800E7C00 + 0x80), D_800CD8A4_de);
    func_802BB750_de((s32)D_8011B590);
}

void func_80292FC0_de(s32 *arg0, s32 arg1) {
    func_802A001C_de((s32)D_800E7C80_de, 1, 0x8000);
    func_802BAC90_de((s32)D_8011B7C0, 1, D_00293534, arg1, (s32)D_800EFC80_de, D_800CD8B4);
    func_802BB750_de((s32)D_8011B7C0);
    {
        s32 temp = D_800CD8A0_de;
        ((GameSession *)arg0)->enabled = 0;
        func_802BB5F0_de(0, temp);
    }
loop_1:
    goto loop_1;
}

void func_80293054_de(Display *display) {
 unsigned int index; FrameRecAt11C *frame;
 index=++D_800D2978%D_800DE850;
 D_800CD730++;
 D_800D297C^=1;
 display->current=&display->frames[index];
 ((FrameRecAt11C *)display->current)->color = D_800D297C ? D_8014D464 : D_8014D460;
 frame = display->current;
 frame->depth = D_800D297C ? D_8014D42C : D_8014D430_de;
}
