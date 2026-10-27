#include "MENU/BUILD/DEFINITION_DATA.H"

#if defined(VERSION_US_REV1)
extern char D_0040A3A8[];
extern char D_0040A32C[];
extern char rw_menu_paged_func_80407748_de[];
extern char rw_menu_paged_func_80407F6C_de[];
extern char rw_menu_paged_func_80442064_de[];

struct {
    unsigned int resourceCallback1;
    unsigned int callback1;
    unsigned int initializeCallback1;
    unsigned int parameter1;
    struct MenuBuildItemData items1[3];
    short type1;
    unsigned short reserved021;
} g_menuItemFragment6 = {
    (unsigned int)rw_menu_paged_func_80442064_de,
    (unsigned int)D_0040A32C,
    0x00000000,
    0x00000000,
    {
        { 0x0000, 0x0000, 0x00010041, 0x0000, 0xFFF8, 0x00, 0x00, 0xFF, 0x01, 0x800D7768, (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)D_0040A3A8, 0x00000000, 0x00000000 },
        { 0x0000, 0x0000, 0x00011001, 0x0000, 0x0006, 0x00, 0x00, 0xFF, 0x01, 0x800D7714, (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)rw_menu_paged_func_80407F6C_de, (unsigned int)rw_menu_paged_func_80407748_de, 0x00000000 },
        { 0x0000, 0x0000, 0x00011001, 0x0000, 0x0000, 0x00, 0x00, 0xFF, 0x01, 0x800D7718, (unsigned int)rw_menu_paged_func_80442064_de, (unsigned int)rw_menu_paged_func_80407F6C_de, (unsigned int)rw_menu_paged_func_80407748_de, 0x00000000 },
    },
    0x0000,
    0x0000,
};
#endif
