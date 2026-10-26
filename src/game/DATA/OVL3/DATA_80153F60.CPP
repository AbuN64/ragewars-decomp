#include "MENU/BUILD/DEFINITION_DATA.H"

#if defined(VERSION_US_REV1)
extern char rw_menu_paged_func_804402DC_de[];

struct {
    short x1;
    short y1;
    unsigned char red1;
    unsigned char green1;
    unsigned char blue1;
    unsigned char alpha1;
    int resource1;
} g_menuItemFragment2 = {
    0x0000,
    0x0000,
    0x00,
    0x00,
    0xFF,
    0x01,
    0x00000385,
};

struct {
    unsigned int resourceCallback1;
} g_menuItemFragment3 = {
    (unsigned int)rw_menu_paged_func_804402DC_de,
};

struct {
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
} g_menuItemFragment4 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x0000,
    0x0000,
    0x08000041,
    0x0000,
    0x000A,
    0x00,
    0x00,
    0xFF,
    0x01,
};
#endif
