#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/EXTERNS_3.H"
#include "FRONTEND/SCREEN.H"
#include "sdk/AUDIO_2/802BF7F0.H"
#include "FRONTEND/8040B45C_22.H"

/* 8040B45C_21.CPP */
/* Selects the video mode and applies framebuffer and display configuration; the mode-to-word-array cast preserves configuration-store and mode-load scheduling. */
s32 Defs_GetMemorySize(); /* extern */
                                 /* extern */
void Frontend_SetVideoModeAndViewports(unsigned, int, int, int, int, int);
extern s32 D_800CC374;
extern s32 D_800E28D0;
extern s32 D_800E28D8;
extern ModeRecAt8 D_800DE8A8[2][5];
extern struct ShapeRecAt18V2 D_800DE934[];
extern RecGobjinstSampleBoneTranslation D_800DE9C0[];
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
void Frontend_ApplyVideoMode(void) {
    char *var_v0;
    s32 featureCommands;
    s32 temp_v0;
    s32 var_v1;
    struct ShapeRecAt18V2 *var_s0;
    var_s0 = NULL;
    g_frontendStartupState = 2;
    if (D_800E28D8 == -1) {
        if (Defs_GetMemorySize() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = (u8)D_800E28D8;
    }
    switch(D_80000300) {
    case 1: var_s0=&((struct ShapeRecAt18V2 *)D_800DE8A8)[D_800E28D8];break;
    case 0:case 2:var_s0=&D_800DE934[D_800E28D8];break;
    }
    if (var_s0 != NULL) {
        RecGobjinstSampleBoneTranslation config=D_800DE9C0[D_800E28D8];
        set_config(config.x,config.y,config.z,config.pad0,config.pad1);
        set_mode((s32 *)var_s0);
        featureCommands = 0x80;
        if (D_800DE898 != 0) {
            featureCommands = 0x40;
        }
        osViSetSpecialFeatures(featureCommands);
        osViSetSpecialFeatures(0x20);
        osViSetSpecialFeatures(2);
    }
}

extern unsigned short g_frontendVideoModeId;
extern Modep g_frontendVideoMode;
extern Modep D_800D4530[];
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern void osViSetMode(void *);
/* VI start registers (hStart, vStart) hold the first pixel/line in the high half and the last in the low half. The
   ROM reads the halves through a stack copy, so a little-endian host keeps the low half at the first address. */
typedef union VideoInterval {
    u32 packed;
    struct {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        u16 last, first;
#else
        u16 first, last;
#endif
    } half;
} VideoInterval;
typedef union VideoHorizontal {
    u32 packed;
    struct {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        u32 last : 16; s32 first : 16;
#else
        s32 first : 16; u32 last : 16;
#endif
    } edge;
} VideoHorizontal;
/* Resizes the selected VI mode (table D_800D4530[g_frontendVideoModeId], copied to g_frontendVideoMode) to width x height around its
 * horizontal and field centres moved by (x, y), shrinks the active area by the borders, rescales X and Y, clamps the
 * last pixel and lines to the original mode and applies it. */
void Frontend_SetVideoViewport(s32 width, s32 height, s32 x, s32 y, s32 borderX, s32 borderY) {
    VideoInterval vertical[2];
    VideoInterval originalVertical[2];
    u16 centerY[2];
    Modep *mode = &g_frontendVideoMode;
    VideoHorizontal horizontal, originalHorizontal;
    u32 scaleY;
    s32 centerX, scaleX;

    func_802BD3A0_de(mode, &D_800D4530[(s16)g_frontendVideoModeId], 0x50);
    horizontal.packed = mode->comRegs.hStart;
    vertical[0].packed = mode->fldRegs[0].vStart;
    originalHorizontal = horizontal;
    centerX = ((s16)horizontal.edge.last - horizontal.edge.first) / 2 + horizontal.edge.first - x;
    centerY[0] = vertical[0].half.first + ((s16)vertical[0].half.last - (s16)vertical[0].half.first) / 2;
    scaleY = mode->fldRegs[0].yScale;
    horizontal.edge.first = centerX - width / 2 + borderX / 2;
    horizontal.edge.last = centerX + width / 2 - borderX * 2;
    vertical[1].packed = mode->fldRegs[1].vStart;
    centerY[1] = vertical[1].half.first + ((s16)vertical[1].half.last - (s16)vertical[1].half.first) / 2;
    centerY[0] -= y;
    vertical[0].half.first = centerY[0] - height / 2 + borderY / 2;
    vertical[0].half.last = centerY[0] + height / 2 - borderY * 2;
    scaleY &= 0xFFFF0000;
    scaleY |= (((height << 11) /
        ((s16)vertical[0].half.last - (s16)vertical[0].half.first)) & 0xFFFF);
    originalVertical[0].packed = mode->fldRegs[0].vStart;
    centerY[1] -= y;
    vertical[1].half.first = centerY[1] - height / 2 + borderY / 2;
    vertical[0].half.last -= 3;
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

/* 8040B45C_22.CPP */
/* Cycles the video mode within the memory budget and chooses dimensions large enough for both active buffers. */
extern int D_800E28DC;
extern int D_800E28E4;
void Frontend_AdvanceVideoMode(void)
{
  int region = 0;
  int budget;
  int memory;
  int w;
  int h;
  int *mode;
  switch (D_80000300)
  {
    case 0:
    case 2:
      region = 1;
      break;
    case 1:
      break;
  }
  mode = (int *) (&D_800DE8A8[region][D_800E28D8]);
  memory = Defs_GetMemorySize();
  budget = 0xF660;
  if (memory != 0x400000)
  {
    budget = 0x2A300;
  }
  if (!D_800E28E4)
  {
    D_800E28D8 = (D_800E28D8 + 1) % D_800DE8A0[region];
    while ((mode[0] * mode[1]) > budget)
    {
      D_800E28D8 = (D_800E28D8 + 1) % D_800DE8A0[region];
    }
  }
  else
  {
    D_800E28E4 = 0;
  }
  memory = D_800DE8A8[region][D_800E28DC].width;
  w = D_800DE8A8[region][D_800E28D8].width;
  if (w < memory)
  {
    w = D_800DE8A8[region][D_800E28DC].width;
  }
  D_800E28D0 = w;
  h = D_800DE8A8[region][D_800E28D8].height;
  if (h < D_800DE8A8[region][D_800E28DC].height)
  {
    h = D_800DE8A8[region][D_800E28DC].height;
  }
  D_800E28D4 = h;
}
/* Stores its argument in D_800E28D8, which func_8040C474_de returns, and calls Frontend_ApplyVideoMode. */
void Frontend_ApplyScreenModeValue(s32 value) {
    D_800E28D8 = value;
    Frontend_ApplyVideoMode();
}
/* Gives D_800E28E0 the value 0x14 when it is still zero. */
extern s32 D_800E28E0;
void Frontend_StartScreenModeFade(void) {
    if (D_800E28E0 == 0) {
        D_800E28E0 = 0x14;
    }
}
/* Detects the storage configuration and updates the cached selection. */
 /* extern */
                                  /* extern */
void Frontend_UpdateScreenMode(void) {
    if (D_800E28D8 == -1) {
        if (Defs_GetMemorySize() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = (u8)D_800E28D8;
    }
    if ((D_800E28E0 < 5) && (D_800E28DC != D_800E28D8)) {
        Frontend_ApplyVideoMode();
        D_800E28DC = D_800E28D8;
    }
}
/* Returns the palette for the current screen mode D_800E28D8: modes 1, 2 and 3 have their own, mode 0
   and anything else use the first. */
extern int D_800D3610;
extern int D_800D3614;
extern int D_800D3618;
extern int D_800D3620;
int *Frontend_GetScreenModePalette(void) {
    switch (D_800E28D8) {
    case 0:
    default:
        return &D_800D3610;
    case 1:
        return &D_800D3614;
    case 2:
        return &D_800D3618;
    case 3:
        return &D_800D3620;
    }
}
/* Requests a new value when no change is pending: if D_800E28E0 is zero and the value differs from
   D_800E28D8, remembers the old value in D_800E28DC, stores the new one, sets D_800E28E4 and starts
   the 0x14-tick countdown D_800E28E0. */
void Frontend_RequestScreenMode(s32 value) {
    if (D_800E28E0 == 0 && value != D_800E28D8) {
        D_800E28E4 = 1;
        D_800E28DC = D_800E28D8;
        D_800E28D8 = value;
        D_800E28E0 = 0x14;
    }
}
/* Returns the word held in D_800E28D8. */
s32 Frontend_GetScreenMode(void) {
    return D_800E28D8;
}
/* Selects the video mode and resets viewport dimensions on the linked views. */
extern int D_80000300, D_800CC374;
extern unsigned int VideoModeIds[3][8];
struct VideoViewList {
    NodeRecAt2A8 *head;
    char reserved[0x1C];
    NodeRecAt2A8 defaultView;
};
extern struct VideoViewList D_80140FE8_de;

void Frontend_SetVideoModeAndViewports(unsigned width, int a1, int a2, int a3, int a4, int a5) {
    int flags = 0;
    int region = 0;
    NodeRecAt2A8 *node;
    float height;

    switch (D_80000300) {
    case 0: region = 1; break;
    case 1: break;
    case 2: region = 2; break;
    }
    if (width > 320) flags |= 4;
    if (D_800CC374) flags |= 2;
    if (width > 320) flags |= 1;
    g_frontendVideoModeId = VideoModeIds[region][flags];
    Frontend_SetVideoViewport(width, a1, a2, a3, a4, a5);
    node = &D_80140FE8_de.defaultView;
    if (node) {
        node->width = D_800E28D0;
        height = D_800E28D4;
        node->x = 0;
        node->y = 0;
        node->height = height;
    }
    node = D_80140FE8_de.head;
    while (node) {
        node->x = 0;
        node->y = 0;
        node->width = D_800E28D0;
        node->height = D_800E28D4;
        node = node->next;
    }
}
