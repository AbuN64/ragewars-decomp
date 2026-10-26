#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "SCENE/802508E0_13.H"

#if defined(VERSION_EU_X)
extern void Frontend_LoadLanguageStringsIfAny(int);
extern void *g_optionsPage;

int Menu_DestroyEuxOptionsAndReloadLanguage(void *arg0) {
    Cache_FreeMemory(arg0);
    g_optionsPage = 0;
    Frontend_LoadLanguageStringsIfAny(g_languageIndex);
    return 0;
}
#endif
