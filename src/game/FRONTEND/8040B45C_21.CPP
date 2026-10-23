#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/EXTERNS_3.H"
#include "FRONTEND/8040B45C_21.H"
#include "SDK/AUDIO_2/802BF7F0.H"

/* Selects the video mode and applies framebuffer and display configuration; the mode-to-word-array cast preserves configuration-store and mode-load scheduling. */
s32 func_80265350_de(); /* extern */
                                 /* extern */
void func_8040C484_de(s32, s32, s32, s32, s32, s32); /* extern */
extern s32 D_80000300;
extern s32 D_800CC374;
extern s32 D_800E28D0,D_800E28D4;
extern s32 D_800E28D8;
extern struct ShapeRecAt18V2 D_800DE8A8[];
extern struct ShapeRecAt18V2 D_800DE934[];
extern Rec_func_8024C92C_de D_800DE9C0[];
extern char D_800E2A14;
extern char D_800E2A18;
extern char D_800E2A1C;
extern char D_800E2A20;
extern u8 D_80146848;
static inline void set_config(int a,int b,int c,int d,int e) {
        D_800DE898 = a;
        D_800CC370 = b;
        D_800CC374 = c;
        D_800CC378 = d;
        D_800CC37C = e;
}
static inline void set_mode(s32 *var_s0) {
        D_800E28D0 = (s32) var_s0[0];
        D_800E28D4 = (s32) var_s0[1];
        func_8040C484_de(var_s0[0], var_s0[1], var_s0[2], var_s0[3], var_s0[4], var_s0[5]);
}
void func_8040BBB0_de(void) {
    char *var_v0;
    s32 var_a0;
    s32 temp_v0;
    s32 var_v1;
    struct ShapeRecAt18V2 *var_s0;
    var_s0 = NULL;
    D_80141000 = 2;
    if (D_800E28D8 == -1) {
        if (func_80265350_de() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = (u8)D_800E28D8;
    }
    switch(D_80000300) {
    case 1: var_s0=&D_800DE8A8[D_800E28D8];break;
    case 0:case 2:var_s0=&D_800DE934[D_800E28D8];break;
    }
    if (var_s0 != NULL) {
        Rec_func_8024C92C_de config=D_800DE9C0[D_800E28D8];
        set_config(config.x,config.y,config.z,config.pad0,config.pad1);
        set_mode((s32 *)var_s0);
        var_a0 = 0x80;
        if (D_800DE898 != 0) {
            var_a0 = 0x40;
        }
        func_802BA700_de(var_a0);
        func_802BA700_de(0x20);
        func_802BA700_de(2);
    }
}

#ifdef NON_MATCHING
#include "COMMON/OSVISCALE.H"

extern s16 D_8014D500;
extern Modep D_8014D508;
extern Modep D_800D4530[];
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern void osViSetMode(void *);

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
    osViSetMode(mode);
}
#else
INCLUDE_ASM("ovl_80400000", func_8040BDB8_de);
#endif
