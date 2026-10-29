#include "include_asm.h"
#include "DATA/OVLTBL/OPTIONS_CREATEOPTIONSPAGE_DATA.H"

/* 800E4504_2.CPP */
/* ROM-grounded data: rodata/writable/800E4510 */
unsigned int g_OptionsCreateoptionspageEncodedWordsBlock1[3] = {
    0x00000000, 0x00000000, 0x00000000,
};

/* 800E451C.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_4b23fe05[57] = {
    0x00000E08, 0x00000004, 0x004232AC, 0x00000E06, 0x00000004, 0x004230D4, 0x00000E03, 0x00000004,
    0x00423274, 0x00000002, 0x00000004, 0x004233E8, 0x00000001, 0x00000004, 0x00423328, 0x00000000,
    0x00000000, 0x00000000, 0x00000E08, 0x0000000B, 0x00423620, 0x00000E06, 0x0000000B, 0x004234CC,
    0x00000E03, 0x0000000B, 0x004235E8, 0x00000002, 0x0000000B, 0x00423720, 0x00000001, 0x0000000B,
    0x00423654, 0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x00000016, 0x00422B94, 0x00000E0A,
    0x00000016, 0x00422960, 0x00000E06, 0x00000016, 0x004224E0, 0x00000E03, 0x00000016, 0x004237E8,
    0x00000002, 0x00000016, 0x00423990, 0x00000001, 0x00000016, 0x00423828, 0x00000000, 0x00000000,
    0x00000000,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_4b23fe05[57] = {
    0x00000E08, 0x00000004, 0x00423B60, 0x00000E06, 0x00000004, 0x004229E0, 0x00000E03, 0x00000004,
    0x00423B30, 0x00000002, 0x00000004, 0x00423C9C, 0x00000001, 0x00000004, 0x00423BDC, 0x00000000,
    0x00000000, 0x00000000, 0x00000E08, 0x0000000B, 0x00423DB8, 0x00000E06, 0x0000000B, 0x00422C58,
    0x00000E03, 0x0000000B, 0x00423D80, 0x00000002, 0x0000000B, 0x00423EB8, 0x00000001, 0x0000000B,
    0x00423DEC, 0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x00000016, 0x004235A8, 0x00000E0A,
    0x00000016, 0x00423374, 0x00000E06, 0x00000016, 0x00422E34, 0x00000E03, 0x00000016, 0x00423F80,
    0x00000002, 0x00000016, 0x00424128, 0x00000001, 0x00000016, 0x00423FC0, 0x00000000, 0x00000000,
    0x00000000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_4b23fe05[65] = {
    0x00000E08, 0x00000004, 0x00423BA8, 0x00000E06, 0x00000004, 0x004229E0, 0x00000E03, 0x00000004,
    0x00423B68, 0x00000002, 0x00000004, 0x00423CE0, 0x00000001, 0x00000004, 0x00423C24, 0x00000008,
    0x0000005D, 0x00423DB0, 0x00000007, 0x0000005D, 0x00423D24, 0x00000000, 0x00000000, 0x00000000,
    0x00000E08, 0x0000000B, 0x00423F0C, 0x00000E06, 0x0000000B, 0x00422C90, 0x00000E03, 0x0000000B,
    0x00423ED4, 0x00000002, 0x0000000B, 0x0042400C, 0x00000001, 0x0000000B, 0x00423F40, 0x00000000,
    0x00000000, 0x00000000, 0x00000E08, 0x00000016, 0x004235E0, 0x00000E0A, 0x00000016, 0x004233AC,
    0x00000E06, 0x00000016, 0x00422E6C, 0x00000E03, 0x00000016, 0x004240D4, 0x00000002, 0x00000016,
    0x0042427C, 0x00000001, 0x00000016, 0x00424114, 0x00000000, 0x00000000, 0x00000000, 0x00000E03,
    0x0000001F,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_OptionsCreateoptionspageEncodedWords[3] = {
    0x00000E08, 0x00000004, (unsigned int)g_frontend_UpdateOptionsPageExitEntry,
};
#endif

#if defined(VERSION_US)
extern char g_Menu_DispatchOptionsTransitionEventAddress[];
extern char g_frontend_UpdateOptionsPageExitEntry[];
extern char g_Frontend_DispatchOptionsPageEventAddress[];
extern char g_Frontend_DispatchCompactOptionsEventAddress[];
unsigned int g_optionsCreateOptionsPageEntryTriples[54] = {
    0xe06, 4, (unsigned int)(g_Menu_DispatchOptionsTransitionEventAddress + 148), 0xe03,
    4, (unsigned int)(g_Menu_DispatchOptionsTransitionEventAddress + 3936), 2, 4,
    (unsigned int)(g_frontend_UpdateOptionsPageExitEntry + 316), 1, 4, (unsigned int)(g_frontend_UpdateOptionsPageExitEntry + 124),
    0, 0, 0, 0xe08,
    11, (unsigned int)(g_Frontend_DispatchOptionsPageEventAddress + 604), 0xe06, 11,
    (unsigned int)(g_Frontend_DispatchOptionsPageEventAddress + 144), 0xe03, 11, (unsigned int)(g_Frontend_DispatchOptionsPageEventAddress + 548),
    2, 11, (unsigned int)(g_Frontend_DispatchOptionsPageEventAddress + 860), 1,
    11, (unsigned int)(g_Frontend_DispatchOptionsPageEventAddress + 656), 0, 0,
    0, 0xe08, 22, (unsigned int)(g_Menu_DispatchOptionsTransitionEventAddress + 2520),
    0xe0a, 22, (unsigned int)(g_Menu_DispatchOptionsTransitionEventAddress + 1956), 0xe06,
    22, (unsigned int)(g_Menu_DispatchOptionsTransitionEventAddress + 684), 0xe03, 22,
    (unsigned int)(g_Frontend_DispatchCompactOptionsEventAddress + 144), 2, 22, (unsigned int)(g_Frontend_DispatchCompactOptionsEventAddress + 568),
    1, 22, (unsigned int)(g_Frontend_DispatchCompactOptionsEventAddress + 208), 0,
    0, 0,
};
#endif
