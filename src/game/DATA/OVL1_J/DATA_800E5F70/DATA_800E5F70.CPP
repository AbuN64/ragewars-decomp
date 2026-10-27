#include "MENU/MENU_BOX.H"

#if defined(VERSION_US_REV1)
MenuBoxCorner g_menuBoxCorners[8] = {
    { -1, -1, 0, 0, 0, 0 },
    { 1, -1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0 },
    { -1, 1, 0, 0, 0, 0 },
    { -1, -1, -2, 0, 0, 0 },
    { 1, -1, -2, 0, 0, 0 },
    { 1, 1, -2, 0, 0, 0 },
    { -1, 1, -2, 0, 0, 0 },
};
unsigned int D_auto_rodata_unresolved_800E6030[3] = {
    0x00000000, 0x00000000, 0xC4098000,
};
#endif
