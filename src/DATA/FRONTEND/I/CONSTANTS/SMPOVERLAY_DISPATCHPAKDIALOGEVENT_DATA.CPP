#include "include_asm.h"
#include "DATA/OVL1_I/SMPOVERLAY_DISPATCHPAKDIALOGEVENT_DATA.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_pakDialogTextReferenceShared1[];
unsigned int D_src_897c5b16[29] = {
    0x00000E08, 0x0000001D, 0x0041C40C, 0x00000E06, 0x0000001D, 0x0041C2AC, 0x00000E03, 0x0000001D,
    0x0041C3DC, 0x00000001, 0x0000001D, 0x0041C494, 0x00000002, 0x0000001D, 0x0041C474, 0x0000000A,
    0x0000001D, 0x0041C46C, 0x00000000, 0x00000000, 0x00000000, 0x96969600, 0x96969600, 0xC8C8C800,
    0xC8C8C800, 0x00003200, 0x00000000, (unsigned int)g_pakDialogTextReferenceShared1, 0x000001FE,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_897c5b16[29] = {
    0x00000E08, 0x0000001D, 0x0041C85C, 0x00000E06, 0x0000001D, 0x0041C6FC, 0x00000E03, 0x0000001D,
    0x0041C82C, 0x00000001, 0x0000001D, 0x0041C8E4, 0x00000002, 0x0000001D, 0x0041C8C4, 0x0000000A,
    0x0000001D, 0x0041C8BC, 0x00000000, 0x00000000, 0x00000000, 0x96969600, 0x96969600, 0xC8C8C800,
    0xC8C8C800, 0x00003200, 0x00000000, 0x4AE5C74D, 0x21CE0020,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_897c5b16[29] = {
    0x00000E08, 0x0000001D, 0x0041C85C, 0x00000E06, 0x0000001D, 0x0041C6FC, 0x00000E03, 0x0000001D,
    0x0041C82C, 0x00000001, 0x0000001D, 0x0041C8E4, 0x00000002, 0x0000001D, 0x0041C8C4, 0x0000000A,
    0x0000001D, 0x0041C8BC, 0x00000000, 0x00000000, 0x00000000, 0x96969600, 0x96969600, 0xC8C8C800,
    0xC8C8C800, 0x00003200, 0x00000000, 0x00000E06, 0x0000000B,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_pakDialogEventHandlerRecordsUs[21] = {
    0x00000E08, 0x0000001D, (unsigned int)g_SmpOverlay_TickPakDialogAddress, 0x00000E06, 0x0000001D, (unsigned int)g_SmpOverlay_CreatePakDialogAddress, 0x00000E03, 0x0000001D,
    (unsigned int)g_SmpOverlay_DestroyPakDialogAddress, 0x00000001, 0x0000001D, (unsigned int)g_SmpOverlay_HandlePakDialogChoiceAddress, 0x00000002, 0x0000001D, (unsigned int)g_SmpOverlay_ConsumePakDialogEventAddress, 0x0000000A,
    0x0000001D, (unsigned int)g_SmpOverlay_ReturnUnhandledPakDialogEventAddress, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int g_pakDialogStyleAndTextWords_us[8] = {
    0x96969600, 0x96969600, 0xC8C8C800, 0xC8C8C800, 0x00003200, 0x00000000, 0x4F4E5F43, 0x48415247,
};
#endif
