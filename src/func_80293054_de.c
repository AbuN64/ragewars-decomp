#include "span_1000/code_80291054.h"
#include "gfx.h"
#include "gbi.h"
#include "span_1000/code_8022F3E8.h"
/* Advances the frame ring and alternates the color and depth buffer pointers for the next frame. */


extern unsigned int D_800D2978,D_800DE850;
extern int D_800CD730,D_800D297C;
extern int D_8014D464,D_8014D460,D_8014D42C,D_8014D430_de;
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

void func_8029311C_de(void *unused, u8 *color, s32 left, s32 top, s32 right, s32 bottom) {
    if (color[3] != 0) {
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
        func_8026925C_de(0x13);
        func_80268CE0_de(0x19);
        gDPSetPrimColor(D_80110634++, 255, 255, color[0], color[1], color[2], color[3]);
        {
            Gfx *cmd = D_80110634++;
            s32 x, y, x0, y0;
            u32 high, low, high0;
            x = right;
            if (x < 0) x = 0;
            y = bottom;
            high = _SHIFTL(x,14,10);
            if (y < 0) y = 0;
            low = _SHIFTL(y,2,10) | _SHIFTL(G_FILLRECT,24,8);
            cmd->words.w0 = high | low;
            x0 = left;
            if (x0 < 0) x0 = 0;
            y0 = top;
            high0 = _SHIFTL(x0,14,10);
            if (y0 < 0) y0 = 0;
            cmd->words.w1 = high0 | _SHIFTL(y0,2,10);
        }
    }
}
