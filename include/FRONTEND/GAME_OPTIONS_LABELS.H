#ifndef FRONTEND_GAME_OPTIONS_LABELS_H
#define FRONTEND_GAME_OPTIONS_LABELS_H
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#if defined(VERSION_DE)
enum { OPTIONS_HAS_FIRST_LIST = 0, OPTIONS_RESOURCE_SHIFT = 4 };
extern char *g_optionsSecondListPrimaryLabels, *g_optionsSecondListSecondaryLabels, *g_optionsSecondListTertiaryLabels;
#else
enum { OPTIONS_HAS_FIRST_LIST = 1, OPTIONS_RESOURCE_SHIFT = 0 };
extern char *g_optionsFirstListPrimaryLabel, *g_optionsFirstListSecondaryLabel, *D_800D2134, *D_800D2138, *D_800D213C;
#endif
static inline char *gameOptionsLabel(s32 index) {
#if defined(VERSION_DE)
switch (index) { case 3: return g_optionsSecondListPrimaryLabels; case 4: return g_optionsSecondListSecondaryLabels; case 5: return g_optionsSecondListTertiaryLabels; }
#else
switch (index) { case 0: return D_800D3470_de[0]; case 1: return g_optionsFirstListPrimaryLabel; case 2: return g_optionsFirstListSecondaryLabel; case 3: return D_800D2134; case 4: return D_800D2138; case 5: return D_800D213C; }
#endif
return 0;
}
#endif
