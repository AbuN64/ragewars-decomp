#include "MENU/BUILD/DEFINITION_DATA.H"

/* DATA_80153F4C.CPP */
#if defined(VERSION_US_REV1)

unsigned int D_auto_rodata_unresolved_80153F4C[3] = {
    0x00000000, 0x00024050, 0x00080000,
};

struct {
    short type1;
    unsigned short reserved021;
    unsigned int flags1;
} g_menuItemFragment1Part2 = {
    0x0001,
    0x0000,
    0x90000000,
};
#endif

/* DATA_80153F60.CPP */
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
