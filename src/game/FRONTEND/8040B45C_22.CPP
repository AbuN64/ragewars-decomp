#include "COMMON/NODERECAT2A8.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "TYPES.H"
#include "stddef.h"
#include "FRONTEND/8040B45C_21.H"
#include "FRONTEND/8040B45C_22.H"

/* Cycles the video mode within the memory budget and chooses dimensions large enough for both active buffers. */
extern int D_80000300;
extern int D_800E28D8;
extern int D_800E28DC;
extern int D_800E28E4;
extern ModeRecAt8 D_800DE8A8[2][5];
extern int D_800E28D0;
extern int System_GetMemorySize(void);
void func_8040C09C_de(void)
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
  memory = System_GetMemorySize();
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
/* Stores its argument in D_800E28D8, which func_8040C474_de returns, and calls func_8040BBB0_de. */
extern s32 D_800E28D8;
void Frontend_ApplyScreenModeValue(s32 value) {
    D_800E28D8 = value;
    func_8040BBB0_de();
}
/* Gives D_800E28E0 the value 0x14 when it is still zero. */
extern s32 D_800E28E0;
void Frontend_StartScreenModeFade(void) {
    if (D_800E28E0 == 0) {
        D_800E28E0 = 0x14;
    }
}
/* Detects the storage configuration and updates the cached selection. */
s32 System_GetMemorySize(); /* extern */
                                  /* extern */
extern s32 D_800E28D8;
extern s32 D_800E28DC;
extern s32 D_800E28E0;
extern u8 D_80146848;
void Frontend_UpdateScreenMode(void) {
    if (D_800E28D8 == -1) {
        if (System_GetMemorySize() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = (u8)D_800E28D8;
    }
    if ((D_800E28E0 < 5) && (D_800E28DC != D_800E28D8)) {
        func_8040BBB0_de();
        D_800E28DC = D_800E28D8;
    }
}
/* Returns the palette for the current screen mode D_800E28D8: modes 1, 2 and 3 have their own, mode 0
   and anything else use the first. */
extern int D_800E28D8;
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
extern s32 D_800E28D8;
extern s32 D_800E28DC;
extern s32 D_800E28E0;
extern s32 D_800E28E4;
void Frontend_RequestScreenMode(s32 value) {
    if (D_800E28E0 == 0 && value != D_800E28D8) {
        D_800E28E4 = 1;
        D_800E28DC = D_800E28D8;
        D_800E28D8 = value;
        D_800E28E0 = 0x14;
    }
}
/* Returns the word held in D_800E28D8. */
extern s32 D_800E28D8;
s32 Frontend_GetScreenMode(void) {
    return D_800E28D8;
}
/* Selects the video mode and resets viewport dimensions on the linked views. */
extern int D_80000300, D_800CC374;
extern unsigned int VideoModeIds[3][8];
extern unsigned short D_8014D500;
struct VideoViewList {
    NodeRecAt2A8 *head;
    char reserved[0x1C];
    NodeRecAt2A8 defaultView;
};
extern struct VideoViewList D_80140FE8_de;
extern int D_800E28D0;
extern void Frontend_SetVideoViewport(unsigned, int, int, int, int, int);

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
    D_8014D500 = VideoModeIds[region][flags];
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
