#ifndef RW_GAME_OPTIONS_LABELS_H
#define RW_GAME_OPTIONS_LABELS_H
#include "TYPES.H"
#include "common/unused.h"
#if defined(VERSION_DE)
enum { OPTIONS_HAS_FIRST_LIST = 0, OPTIONS_RESOURCE_SHIFT = 4 };
extern char *D_auto_800D3488, *D_auto_800D348C, *D_auto_800D3490;
#else
enum { OPTIONS_HAS_FIRST_LIST = 1, OPTIONS_RESOURCE_SHIFT = 0 };
extern char *D_800D2124, *D_800D2128, *D_800D2134, *D_800D2138, *D_800D213C;
#endif
static inline char *gameOptionsLabel(s32 index) {
#if defined(VERSION_DE)
switch (index) { case 3: return D_auto_800D3488; case 4: return D_auto_800D348C; case 5: return D_auto_800D3490; }
#else
switch (index) { case 0: return D_800D3470_de[0]; case 1: return D_800D2124; case 2: return D_800D2128; case 3: return D_800D2134; case 4: return D_800D2138; case 5: return D_800D213C; }
#endif
return 0;
}

#endif
