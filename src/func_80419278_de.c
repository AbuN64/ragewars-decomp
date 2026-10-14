#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "abi.h"
#include "gbi.h"
/* Draws the current texture D_800DF254 over the screen rectangle (left, top)-(right, bottom) mapping
   the normalised texture window (u0, v0)-(u1, v1): skips an empty texture or rectangle, scales the
   window by the texture size into 5.10 fixed point to get the start coordinates and per-pixel
   steps, and emits the texture rectangle command with its two half commands. */
#include "types.h"

#include "types.h"
#include "n64sdk.h"



extern Gfx *D_80110634;
extern Texture *D_800DF254;

void func_80419278_de(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1) {
    f32 scaleU;
    f32 scaleV;
    s32 dsdx;
    s32 dtdy;
    s32 startS;
    s32 startT;

    if (D_800DF254->width == 0 || D_800DF254->height == 0 || left == right || top == bottom) {
        return;
    }
    scaleU = D_800DF254->width << 10;
    dsdx = (s32)((u1 - u0) * scaleU) / (right - left + 1);
    scaleV = D_800DF254->height << 10;
    dtdy = (s32)((v1 - v0) * scaleV) / (bottom - top + 1);
    {
        Gfx *cmd = D_80110634++;
        gDPTexRect(cmd, left * 4, top * 4, (right + 1) * 4, (bottom + 1) * 4, 0);
    }
    startS = u0 * scaleU;
    startT = v0 * scaleV;
    gDPHalf1(D_80110634++, ((startS >> 5) << 16) | ((startT >> 5) & 0xFFFF));
    gDPHalf2(D_80110634++, (dsdx << 16) | (dtdy & 0xFFFF));
}
