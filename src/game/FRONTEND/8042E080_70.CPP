#include "COMMON/S1_6.H"
#include "FRONTEND/8042E080_70.H"

/* Calls InitFrontendMenus and then func_80298368_de with 1. */
#if defined(VERSION_EU)
extern void Tsmos_InitializeEuropeanFrontend();
#elif defined(VERSION_EU_X)
extern void func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
extern void InitFrontendMenus();
#else
extern void func_802A2224_de();
#endif
extern void func_80298368_de(int);

void Frontend_OpenGameplayFrontend(void) {
    
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
InitFrontendMenus
#else
func_802A2224_de
#endif
();
    func_80298368_de(1);
}
