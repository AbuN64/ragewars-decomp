#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/EXTERNS_3.H"
#include "FRONTEND/8040B45C_21.H"
#include "sdk/AUDIO_2/802BF7F0.H"

/* Selects the video mode and applies framebuffer and display configuration; the mode-to-word-array cast preserves configuration-store and mode-load scheduling. */
s32 System_GetMemorySize(); /* extern */
                                 /* extern */
void Frontend_SetVideoModeAndViewports(s32, s32, s32, s32, s32, s32); /* extern */
extern s32 D_80000300;
extern s32 D_800CC374;
extern s32 D_800E28D0;
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
        Frontend_SetVideoModeAndViewports(var_s0[0], var_s0[1], var_s0[2], var_s0[3], var_s0[4], var_s0[5]);
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
        if (System_GetMemorySize() != 0x400000) {
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

typedef union VideoInterval {
    u32 packed;
    struct { u16 first, last; } half;
} VideoInterval;

typedef union VideoHorizontal {
    u32 packed;
    struct { s32 first : 16; u32 last : 16; } edge;
} VideoHorizontal;

/* 92/185 aligned edits; remaining: halfword and scale scheduling. */
/* Resize the selected VI mode around its horizontal and field centres. */
void Frontend_SetVideoViewport(s32 width, s32 height, s32 x, s32 y, s32 borderX, s32 borderY) {
    VideoInterval vertical[2];
    VideoInterval originalVertical[2];
    u16 centerY[2];
    Modep *mode = &D_8014D508;
    VideoHorizontal horizontal, originalHorizontal;
    u32 scaleY;
    s32 centerX, scaleX;

    func_802BD3A0_de(mode, &D_800D4530[D_8014D500], 0x50);
    horizontal.packed = mode->comRegs.hStart;
    scaleY = mode->fldRegs[0].yScale;
    vertical[0].packed = mode->fldRegs[0].vStart;
    originalHorizontal = horizontal;
    centerX = ((s16)horizontal.edge.last - horizontal.edge.first) / 2 + horizontal.edge.first - x;
    horizontal.edge.first = centerX - width / 2 + borderX / 2;
    horizontal.edge.last = centerX + width / 2 - borderX * 2;
    centerY[0] = vertical[0].half.first + ((s16)vertical[0].half.last - (s16)vertical[0].half.first) / 2;
    centerY[0] -= y;
    vertical[0].half.first = centerY[0] - height / 2 + borderY / 2;
    vertical[0].half.last = centerY[0] + height / 2 - borderY * 2;
    scaleY &= 0xFFFF0000;
    scaleY |= (((height << 11) /
        ((s16)vertical[0].half.last - (s16)vertical[0].half.first)) & 0xFFFF);
    originalVertical[0].packed = mode->fldRegs[0].vStart;
    vertical[0].half.last -= 3;
    vertical[1].packed = mode->fldRegs[1].vStart;
    centerY[1] = vertical[1].half.first + ((s16)vertical[1].half.last - (s16)vertical[1].half.first) / 2;
    centerY[1] -= y;
    vertical[1].half.first = centerY[1] - height / 2 + borderY / 2;
    vertical[1].half.last = centerY[1] + height / 2 - borderY * 2;
    originalVertical[1].packed = mode->fldRegs[1].vStart;
    vertical[1].half.last -= 3;
    scaleX = (width << 10) / ((s16)horizontal.edge.last - horizontal.edge.first);
    if ((s16)originalVertical[0].half.last < (s16)vertical[0].half.last) vertical[0].half.last = originalVertical[0].half.last;
    if ((s16)originalVertical[1].half.last < (s16)vertical[1].half.last) vertical[1].half.last = originalVertical[1].half.last;
    if ((s16)originalHorizontal.edge.last < (s16)horizontal.edge.last) horizontal.edge.last = originalHorizontal.edge.last;
    mode->fldRegs[0].yScale = scaleY;
    mode->fldRegs[1].yScale = scaleY;
    mode->fldRegs[0].origin = 0;
    mode->fldRegs[1].origin = width * 2;
    mode->comRegs.width = width;
    mode->comRegs.xScale = scaleX;
    mode->comRegs.hStart = horizontal.packed;
    mode->fldRegs[0].vStart = vertical[0].packed;
    mode->fldRegs[1].vStart = vertical[1].packed;
    osViSetMode(mode);
}

#else
INCLUDE_ASM("ovl_80400000", Frontend_SetVideoViewport);
#endif
