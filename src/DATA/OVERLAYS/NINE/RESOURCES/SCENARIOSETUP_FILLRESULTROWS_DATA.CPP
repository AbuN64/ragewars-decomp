#include "include_asm.h"

/* 800E53C0.CPP */
/* ROM-grounded data: rodata/writable/800E53C0 */
unsigned int g_ScenariosetupFillresultrowsWords1[1] = {
    0x00000000,
};

/* 800E53C4.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_6d0863ff[27] = {
    0x00000E08, 0x00000011, 0x0042D690, 0x00000E06, 0x00000011, 0x0042BB60, 0x00000E03, 0x00000011,
    0x0042D4CC, 0x00000002, 0x00000011, 0x0042D8A4, 0x00000001, 0x00000011, 0x0042D788, 0x00000E0A,
    0x00000011, 0x0042D4FC, 0x00000005, 0x00000011, 0x0042D8C4, 0x00000006, 0x00000011, 0x0042D908,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_6d0863ff[27] = {
    0x00000E08, 0x00000011, 0x0042E2E0, 0x00000E06, 0x00000011, 0x0042C730, 0x00000E03, 0x00000011,
    0x0042E11C, 0x00000002, 0x00000011, 0x0042E4F4, 0x00000001, 0x00000011, 0x0042E3D8, 0x00000E0A,
    0x00000011, 0x0042E14C, 0x00000005, 0x00000011, 0x0042E514, 0x00000006, 0x00000011, 0x0042E558,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_6d0863ff[27] = {
    0x00000E08, 0x00000011, 0x0042E430, 0x00000E06, 0x00000011, 0x0042C880, 0x00000E03, 0x00000011,
    0x0042E26C, 0x00000002, 0x00000011, 0x0042E644, 0x00000001, 0x00000011, 0x0042E528, 0x00000E0A,
    0x00000011, 0x0042E29C, 0x00000005, 0x00000011, 0x0042E664, 0x00000006, 0x00000011, 0x0042E6A8,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char g_ScenarioSetup_OpenResultsScreenPackedAddress242[];
extern char g_Frontend_DestroyMatchResultsPackedAddress242[];
extern char g_Frontend_UpdateMatchResultsTransitionPackedAddress242[];
extern char g_Frontend_HandleResultsConfirmationPackedAddress242[];
extern char g_Frontend_ActivateResultsActionPackedAddress242[];
extern char g_Frontend_ConsumeResultsEventPackedAddress242[];
extern char g_Frontend_ScrollResultsBackwardPackedAddress242[];
extern char g_Frontend_ScrollResultsForwardPackedAddress242[];
unsigned int g_ScenariosetupFillresultrowsPointerWords1[27] = {
    0x00000E08, 0x00000011, (unsigned int)g_Frontend_HandleResultsConfirmationPackedAddress242, 0x00000E06, 0x00000011, (unsigned int)g_ScenarioSetup_OpenResultsScreenPackedAddress242, 0x00000E03, 0x00000011,
    (unsigned int)g_Frontend_DestroyMatchResultsPackedAddress242, 0x00000002, 0x00000011, (unsigned int)g_Frontend_ConsumeResultsEventPackedAddress242, 0x00000001, 0x00000011, (unsigned int)g_Frontend_ActivateResultsActionPackedAddress242, 0x00000E0A,
    0x00000011, (unsigned int)g_Frontend_UpdateMatchResultsTransitionPackedAddress242, 0x00000005, 0x00000011, (unsigned int)g_Frontend_ScrollResultsBackwardPackedAddress242, 0x00000006, 0x00000011, (unsigned int)g_Frontend_ScrollResultsForwardPackedAddress242,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
