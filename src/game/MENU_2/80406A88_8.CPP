#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "SCENE/802508E0_13.H"

#if defined(VERSION_EU_X)
extern void Frontend_LoadLanguageStringsIfAny(int);
extern void *g_optionsPage;

int func_80423B70_eu_x(void *arg0) {
    Scene_FreeMemory(arg0);
    g_optionsPage = 0;
    Frontend_LoadLanguageStringsIfAny(D_80152789);
    return 0;
}
#endif
