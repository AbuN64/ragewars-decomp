#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Releases the object g_optionsPage holds through func_802547E4_de, clears g_optionsPage and returns zero. */
extern void *g_optionsPage;

s32 func_80423B30_eu(void) {
    func_802547E4_de(g_optionsPage);
    g_optionsPage = 0;
    return 0;
}
#endif
