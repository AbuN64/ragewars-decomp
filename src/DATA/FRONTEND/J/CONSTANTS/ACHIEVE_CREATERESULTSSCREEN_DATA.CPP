#include "include_asm.h"
#include "DATA/OVL1_J/ACHIEVE_CREATERESULTSSCREEN_DATA.H"

/* g_AchieveCreateresultsscreenWords1_AchieveCreateresultsscreenData.CPP */
/* ROM-grounded data: rodata/writable/800E5830 */
unsigned int g_AchieveCreateresultsscreenWords1[1] = {
    0x00000000,
};

/* g_AchieveCreateresultsscreenPointerWords1_AchieveCreateresultsscreenData.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_Menu_DispatchTitleButtonEventAddress[];
unsigned int D_src_e3e7c440[27] = {
    0xe08, 18, (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 4812), 0xe07,
    18, (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 4380), 0xe06, 18,
    (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 152), 0xe03, 18, (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 4332),
    2, 18, (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 5284), 1,
    18, (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 5084), 0xe0a, 18,
    (unsigned int)(g_Menu_DispatchTitleButtonEventAddress + 4388), 0, 0, 0,
    0, 0xe07, 6,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_e3e7c440[27] = {
    0x00000E08, 0x00000012, 0x00439B58, 0x00000E07, 0x00000012, 0x004399A8, 0x00000E06, 0x00000012,
    0x00438880, 0x00000E03, 0x00000012, 0x00439978, 0x00000002, 0x00000012, 0x00439D30, 0x00000001,
    0x00000012, 0x00439C68, 0x00000E0A, 0x00000012, 0x004399B0, 0x00000000, 0x00000000, 0x00000000,
    0x0002FFFF, 0x00200800, 0x7FFF4000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_e3e7c440[27] = {
    0x00000E08, 0x00000012, 0x00439C88, 0x00000E07, 0x00000012, 0x00439AD8, 0x00000E06, 0x00000012,
    0x004389B0, 0x00000E03, 0x00000012, 0x00439AA8, 0x00000002, 0x00000012, 0x00439E60, 0x00000001,
    0x00000012, 0x00439D98, 0x00000E0A, 0x00000012, 0x00439AE0, 0x00000000, 0x00000000, 0x00000000,
    0x8C6A0008, 0xACC80000, 0xACC90004,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int g_AchieveCreateresultsscreenPointerWords1[6] = {
    0x00000E08, 0x00000012, (unsigned int)g_Achieve_UpdateResultSelectionMessagePackedAddress24_AchieveCreateresultsscreenData, 0x00000E07, 0x00000012, (unsigned int)g_Achieve_ResultScreenReturnZeroPackedAddress24_AchieveCreateresultsscreenData,
};
#endif

#if defined(VERSION_US)
unsigned int g_AchieveCreateresultsscreenPointerWordsTailUs[21] = {
    0x00000E06, 0x00000012, 0x00437C30, 0x00000E03, 0x00000012, 0x00438C84, 0x00000002, 0x00000012,
    0x0043903C, 0x00000001, 0x00000012, 0x00438F74, 0x00000E0A, 0x00000012, 0x00438CBC, 0x00000000,
    0x00000000, 0x00000000, 0x4E452E48, 0x1CE8002B, 0x433A5C50,
};
#endif
