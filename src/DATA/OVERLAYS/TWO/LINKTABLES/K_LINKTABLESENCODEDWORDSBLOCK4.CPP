#include "COMMON/GFX.H"
#include "gbi.h"
extern char g_particleQuadVertices[];
extern char g_playerModelLighting[];
#include "DATA_OVERLAY_LAYOUTS.H"


#if defined(VERSION_US)
#if defined(VERSION_US)
struct {
    struct { u8 color[3], pad0, colorCopy[3], pad1; s8 direction[3]; u8 pad2[5]; } light;
    Gfx commands[6];
} k_LinktablesEncodedWordsBlock4 = {
    { { 0xFF, 0xFF, 0xFF }, 0, { 0xFF, 0xFF, 0xFF }, 0, { 0, 0, 127 }, { 0, 0, 0, 0, 0 } },
    {
    gsSPGeometryMode(0xFFFFFF, 0x00000000),
    gsSPGeometryMode(0x000000, 0x00000001),
    gsSPMoveWord(2, 0x0000, 0x00000018),
    gsSPMoveMem(10, 48, 16, g_playerModelLighting + 8),
    gsSPMoveMem(10, 72, 16, g_playerModelLighting),
    gsSPEndDisplayList(),
    }
};
#endif
#endif
