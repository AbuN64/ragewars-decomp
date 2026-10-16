#include "span_1000/code_802BA23C.h"

extern s16 D_8014D500;
extern Modep D_8014D508;
extern Modep D_800D4530[];
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern void func_802BA6B0_de(void *);

/* Resize the selected VI mode around its original horizontal and field
 * centres, retaining the original lower screen limits. */
void func_8040BDB8_de(s32 width, s32 height, s32 x, s32 y, s32 borderX, s32 borderY) {
    Modep *mode = &D_8014D508;
    s32 centerX, centerY0, centerY1;
    s32 left, right, top0, bottom0, top1, bottom1;
    s32 oldRight, oldBottom0, oldBottom1;
    u32 scaleY;

    func_802BD3A0_de(mode, &D_800D4530[D_8014D500], 0x50);
    oldRight = (s16)mode->comRegs.hStart;
    oldBottom0 = (s16)mode->fldRegs[0].vStart;
    oldBottom1 = (s16)mode->fldRegs[1].vStart;
    centerX = ((oldRight - ((s32)mode->comRegs.hStart >> 16)) / 2 +
               ((s32)mode->comRegs.hStart >> 16)) - x;
    centerY0 = (mode->fldRegs[0].vStart >> 16) +
        (oldBottom0 - (s16)(mode->fldRegs[0].vStart >> 16)) / 2 - y;
    centerY1 = (mode->fldRegs[1].vStart >> 16) +
        (oldBottom1 - (s16)(mode->fldRegs[1].vStart >> 16)) / 2 - y;
    left = (s16)(centerX - width / 2 + borderX / 2);
    right = (s16)(centerX + width / 2 - borderX * 2);
    top0 = (s16)(centerY0 - height / 2 + borderY / 2);
    bottom0 = (s16)(centerY0 + height / 2 - borderY * 2);
    top1 = (s16)(centerY1 - height / 2 + borderY / 2);
    bottom1 = (s16)(centerY1 + height / 2 - borderY * 2 - 3);
    mode->comRegs.xScale = (width << 10) / (right - left);
    scaleY = (mode->fldRegs[0].yScale & 0xFFFF0000) |
        (((height << 11) / (bottom0 - top0)) & 0xFFFF);
    bottom0 = (s16)(bottom0 - 3);
    if (oldBottom0 < bottom0) bottom0 = oldBottom0;
    if (oldBottom1 < bottom1) bottom1 = oldBottom1;
    if (oldRight < right) right = oldRight;
    mode->fldRegs[0].yScale = scaleY;
    mode->fldRegs[1].yScale = scaleY;
    mode->fldRegs[0].origin = 0;
    mode->fldRegs[1].origin = width * 2;
    mode->comRegs.width = width;
    mode->comRegs.hStart = ((u32)left << 16) | (u16)right;
    mode->fldRegs[0].vStart = ((u32)top0 << 16) | (u16)bottom0;
    mode->fldRegs[1].vStart = ((u32)top1 << 16) | (u16)bottom1;
    func_802BA6B0_de(mode);
}
