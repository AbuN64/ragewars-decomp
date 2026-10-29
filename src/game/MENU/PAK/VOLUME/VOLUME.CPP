#include "COMMON/VOLUME_MENU_RESOURCES.H"
#include "TYPES.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/PLAYERRECAT64E.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
s32 Volume_AllocateMenuOne_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, g_volumeMenuOneList);
    return 1;
}

s32 Volume_AllocateMenuTwo_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, g_pakAllocateMenuSecondResource_eu);
    return 1;
}

s32 Volume_AllocateMenuThree_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_00450E9C);
    return 1;
}

s32 Volume_AllocateMenuFour_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_0044F4A4);
    return 1;
}

s32 Volume_AllocateMenuFive_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_0044F798);
    return 1;
}

s32 Volume_AllocateMenuSix_eu(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, g_volumeMenuSixList);
    return 1;
}
#endif
