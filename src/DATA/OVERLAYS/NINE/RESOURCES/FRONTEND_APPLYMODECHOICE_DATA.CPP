#include "include_asm.h"
#include "DATA/SCENARIO_SETUP/FRONTEND_APPLYMODECHOICE_DATA.H"

/* 800E4600.CPP */
/* ROM-grounded data: rodata/writable/800E4600 */
unsigned int g_FrontendApplymodechoiceWords1[1] = {
    0x00000000,
};

/* 800E4604.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_playerSettingsFirstChoiceText[];
extern char g_playerSettingsSecondChoiceText[];
extern char g_playerSettingsSlotNumberFormat[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x004241BC, 0x00000E06, 0x00000003, 0x00423A40, 0x00000E03, 0x00000003,
    0x0042418C, 0x00000002, 0x00000003, 0x00424328, 0x00000001, 0x00000003, 0x00423F48, 0x0000000A,
    0x00000003, 0x004242D4, 0x00000000, 0x00000000, 0x00000000, (unsigned int)g_playerSettingsSecondChoiceText, (unsigned int)g_playerSettingsFirstChoiceText, (unsigned int)g_playerSettingsSlotNumberFormat + 0x4,
    (unsigned int)g_playerSettingsSlotNumberFormat + 0x10, (unsigned int)g_playerSettingsSlotNumberFormat + 0xC, (unsigned int)g_playerSettingsSlotNumberFormat + 0x8, (unsigned int)g_playerSettingsSlotNumberFormat + 0xC, (unsigned int)g_playerSettingsSlotNumberFormat + 0x8, (unsigned int)g_playerSettingsSlotNumberFormat + 0x10, (unsigned int)g_playerSettingsSlotNumberFormat + 0x4,
};
#endif
#if defined(VERSION_EU)
extern char g_playerSettingsSlotNumberTranslations[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x0042495C, 0x00000E06, 0x00000003, 0x004241E0, 0x00000E03, 0x00000003,
    0x0042492C, 0x00000002, 0x00000003, 0x00424AC8, 0x00000001, 0x00000003, 0x004246E8, 0x0000000A,
    0x00000003, 0x00424A74, 0x00000000, 0x00000000, 0x00000000, 0x97150000, 0x4A19CE6C, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x10,
    (unsigned int)g_playerSettingsSlotNumberTranslations + 0x40, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x30, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x20, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x30, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x20, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x40, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x10,
};
#endif
#if defined(VERSION_EU_X)
extern char g_playerSettingsSlotNumberTranslations[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x00424AAC, 0x00000E06, 0x00000003, 0x00424330, 0x00000E03, 0x00000003,
    0x00424A7C, 0x00000002, 0x00000003, 0x00424C18, 0x00000001, 0x00000003, 0x00424838, 0x0000000A,
    0x00000003, 0x00424BC4, 0x00000000, 0x00000000, 0x00000000, 0x00000E03, 0x00000020, (unsigned int)g_playerSettingsSlotNumberTranslations + 0xC,
    (unsigned int)g_playerSettingsSlotNumberTranslations + 0x30, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x24, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x18, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x24, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x18, (unsigned int)g_playerSettingsSlotNumberTranslations + 0x30, (unsigned int)g_playerSettingsSlotNumberTranslations + 0xC,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_FrontendApplymodechoicePointerWords1[3] = {
    0x00000E08, 0x00000003, (unsigned int)g_Frontend_UpdatePlayModeMenuPackedAddress24_FrontendApplymodechoiceData,
};
#endif

#if defined(VERSION_US)
#if defined(VERSION_US)
extern char g_playerSettingsSlotNumberFormat[];
unsigned int g_frontendApplyModeChoiceEventHandlerRecords[28] = {
    0x00000E06, 0x00000003, 0x00423C20, 0x00000E03, 0x00000003, 0x0042436C, 0x00000002, 0x00000003,
    0x00424508, 0x00000001, 0x00000003, 0x00424128, 0x0000000A, 0x00000003, 0x004244B4, 0x00000000,
    0x00000000, 0x00000000, 0x00660000, 0x00040000, (unsigned int)g_playerSettingsSlotNumberFormat + 0x4, (unsigned int)g_playerSettingsSlotNumberFormat + 0x10, (unsigned int)g_playerSettingsSlotNumberFormat + 0xC, (unsigned int)g_playerSettingsSlotNumberFormat + 0x8,
    (unsigned int)g_playerSettingsSlotNumberFormat + 0xC, (unsigned int)g_playerSettingsSlotNumberFormat + 0x8, (unsigned int)g_playerSettingsSlotNumberFormat + 0x10, (unsigned int)g_playerSettingsSlotNumberFormat + 0x4,
};
#endif
#endif
