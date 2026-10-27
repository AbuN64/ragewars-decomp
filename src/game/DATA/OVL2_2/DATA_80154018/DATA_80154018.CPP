#include "MENU/BUILD/DEFINITION_DATA.H"

#if defined(VERSION_US_REV1)
extern char rw_menu_paged_func_80407748_de[];
extern char rw_menu_paged_func_80407F6C_de[];
extern char rw_menu_paged_func_80442064_de[];

struct {
    unsigned char red1;
    unsigned char green1;
    unsigned char blue1;
    unsigned char alpha1;
    int resource1;
} g_menuItemFragment8 = {
    0x00,
    0x00,
    0xFF,
    0x01,
    0x800D771C,
};

struct {
    unsigned int resourceCallback1;
    unsigned int callback1;
    unsigned int initializeCallback1;
    unsigned int parameter1;
    short type1;
    unsigned short reserved021;
    unsigned int flags1;
    short x1;
    short y1;
    unsigned char red1;
    unsigned char green1;
    unsigned char blue1;
    unsigned char alpha1;
    int resource1;
    unsigned int resourceCallback2;
    unsigned int callback2;
    unsigned int initializeCallback2;
} g_menuItemFragment9 = {
    (unsigned int)rw_menu_paged_func_80442064_de,
    (unsigned int)rw_menu_paged_func_80407F6C_de,
    (unsigned int)rw_menu_paged_func_80407748_de,
    0x00000000,
    0x0000,
    0x0000,
    0x00011001,
    0x0000,
    0x0000,
    0x00,
    0x00,
    0xFF,
    0x01,
    0x800D7720,
    (unsigned int)rw_menu_paged_func_80442064_de,
    (unsigned int)rw_menu_paged_func_80407F6C_de,
    (unsigned int)rw_menu_paged_func_80407748_de,
};
#endif
