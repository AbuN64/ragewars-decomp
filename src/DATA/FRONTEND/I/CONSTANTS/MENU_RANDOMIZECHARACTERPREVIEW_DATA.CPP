#include "include_asm.h"

/* g_joinOptionsInitialWord_MenuRandomizecharacterpreviewData.CPP */
/* ROM-grounded data: rodata/writable/800E39C0 */
unsigned int g_joinOptionsInitialWord[1] = {
    0x00000000,
};

/* g_joinOptionsEventHandlerRecords_MenuRandomizecharacterpreviewData.CPP */
/* Menu event handler registry: eleven 12-byte records of {event id, sub id 0x17, handler address
   in the Join_CreateUsJoinOptionsMenu_MenuRandomizecharacterpreviewData-family menu code}, followed by a three-word tail. The handler addresses sit
   in each cartridge's own menu code, so only the tail words are cartridge-stable in some pairs;
   the tail differs per cartridge and the records keep the ids common to all of them. */
#if defined(VERSION_DE)
extern char g_Menu_CreateGermanCourseOptionsAddress[];
extern char g_Frontend_SelectPreviousJoinModelAddress[];
extern char g_Frontend_SelectNextJoinModelAddress[];
extern char g_Join_DestroyJoinOptionsMenuAddress[];
extern char g_Join_PulseJoinSelectionHighlightAddress[];
extern char g_Join_RequestJoinOptionsExitAddress[];
extern char g_Join_RequestJoinOptionsExitAlternateAddress[];
extern char g_Join_SelectPreviousJoinRowAddress[];
extern char g_Join_SelectNextJoinRowAddress[];
extern char g_Join_CycleJoinRequestRankAddress[];
unsigned int g_joinOptionsEventHandlerRecords[35] = {
    0x00000E06, 0x00000017, (unsigned int)g_Menu_CreateGermanCourseOptionsAddress, 0x00000E03, 0x00000017, (unsigned int)g_Join_DestroyJoinOptionsMenuAddress, 0x00000E08, 0x00000017,
    (unsigned int)g_Join_PulseJoinSelectionHighlightAddress, 0x00000002, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAlternateAddress, 0x00000001, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAddress, 0x00000007,
    0x00000017, (unsigned int)g_Frontend_SelectPreviousJoinModelAddress, 0x00000008, 0x00000017, (unsigned int)g_Frontend_SelectNextJoinModelAddress, 0x00000005, 0x00000017, (unsigned int)g_Join_SelectPreviousJoinRowAddress,
    0x00000006, 0x00000017, (unsigned int)g_Join_SelectNextJoinRowAddress, 0x0000000A, 0x00000017, (unsigned int)g_Join_CycleJoinRequestRankAddress, 0x00000000, 0x00000000,
    0x00000000, 0x00000023, 0x3E0F5C29,
};
#elif defined(VERSION_EU)
extern char g_Menu_CreateEuJoinOptionsCallbackAddressEu[];
extern char g_Frontend_SelectPreviousJoinModelAddressVariant2[];
extern char g_Frontend_SelectNextJoinModelAddressVariant2[];
extern char g_Join_DestroyJoinOptionsMenuAddressVariant3[];
extern char g_Join_PulseJoinSelectionHighlightAddressVariant3[];
extern char g_Join_RequestJoinOptionsExitAddressVariant3[];
extern char g_Join_RequestJoinOptionsExitAlternateAddressVariant3[];
extern char g_Join_SelectPreviousJoinRowAddressVariant3[];
extern char g_Join_SelectNextJoinRowAddressVariant3[];
extern char g_Join_CycleJoinRequestRankAddressVariant3[];
unsigned int g_joinOptionsEventHandlerRecords[35] = {
    0x00000E06, 0x00000017, (unsigned int)g_Menu_CreateEuJoinOptionsCallbackAddressEu, 0x00000E03, 0x00000017, (unsigned int)g_Join_DestroyJoinOptionsMenuAddressVariant3, 0x00000E08, 0x00000017,
    (unsigned int)g_Join_PulseJoinSelectionHighlightAddressVariant3, 0x00000002, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAlternateAddressVariant3, 0x00000001, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAddressVariant3, 0x00000007,
    0x00000017, (unsigned int)g_Frontend_SelectPreviousJoinModelAddressVariant2, 0x00000008, 0x00000017, (unsigned int)g_Frontend_SelectNextJoinModelAddressVariant2, 0x00000005, 0x00000017, (unsigned int)g_Join_SelectPreviousJoinRowAddressVariant3,
    0x00000006, 0x00000017, (unsigned int)g_Join_SelectNextJoinRowAddressVariant3, 0x0000000A, 0x00000017, (unsigned int)g_Join_CycleJoinRequestRankAddressVariant3, 0x00000000, 0x00000000,
    0x00000000, 0x1D800013, 0x4B132F10,
};
#elif defined(VERSION_EU_X)
extern char g_Menu_CreateEuJoinOptionsCallbackAddressEu[];
extern char g_Frontend_SelectPreviousJoinModelAddressVariant2[];
extern char g_Frontend_SelectNextJoinModelAddressVariant2[];
extern char g_Join_DestroyJoinOptionsMenuAddressVariant3[];
extern char g_Join_PulseJoinSelectionHighlightAddressVariant3[];
extern char g_Join_RequestJoinOptionsExitAddressVariant3[];
extern char g_Join_RequestJoinOptionsExitAlternateAddressVariant3[];
extern char g_Join_SelectPreviousJoinRowAddressVariant3[];
extern char g_Join_SelectNextJoinRowAddressVariant3[];
extern char g_Join_CycleJoinRequestRankAddressVariant3[];
unsigned int g_joinOptionsEventHandlerRecords[35] = {
    0x00000E06, 0x00000017, (unsigned int)g_Menu_CreateEuJoinOptionsCallbackAddressEu, 0x00000E03, 0x00000017, (unsigned int)g_Join_DestroyJoinOptionsMenuAddressVariant3, 0x00000E08, 0x00000017,
    (unsigned int)g_Join_PulseJoinSelectionHighlightAddressVariant3, 0x00000002, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAlternateAddressVariant3, 0x00000001, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAddressVariant3, 0x00000007,
    0x00000017, (unsigned int)g_Frontend_SelectPreviousJoinModelAddressVariant2, 0x00000008, 0x00000017, (unsigned int)g_Frontend_SelectNextJoinModelAddressVariant2, 0x00000005, 0x00000017, (unsigned int)g_Join_SelectPreviousJoinRowAddressVariant3,
    0x00000006, 0x00000017, (unsigned int)g_Join_SelectNextJoinRowAddressVariant3, 0x0000000A, 0x00000017, (unsigned int)g_Join_CycleJoinRequestRankAddressVariant3, 0x00000000, 0x00000000,
    0x00000000, 0x00000021, 0x0000001F,
};
#elif defined(VERSION_US)
extern char g_Join_CreateUsJoinOptionsMenuCallbackAddressUs[];
extern char g_Join_SelectPreviousUsJoinModelCallbackAddressUs[];
extern char g_CJoinCharacter_CycleModelSelectionCallbackAddressUs[];
extern char g_Join_DestroyJoinOptionsMenuAddressVariant2[];
extern char g_Join_PulseJoinSelectionHighlightAddressVariant2[];
extern char g_Join_RequestJoinOptionsExitAddressVariant2[];
extern char g_Join_RequestJoinOptionsExitAlternateAddressVariant2[];
extern char g_Join_SelectPreviousJoinRowAddressVariant2[];
extern char g_Join_SelectNextJoinRowAddressVariant2[];
extern char g_Join_CycleJoinRequestRankAddressVariant2[];
unsigned int g_joinOptionsEventHandlerRecords[35] = {
    0x00000E06, 0x00000017, (unsigned int)g_Join_CreateUsJoinOptionsMenuCallbackAddressUs, 0x00000E03, 0x00000017, (unsigned int)g_Join_DestroyJoinOptionsMenuAddressVariant2, 0x00000E08, 0x00000017,
    (unsigned int)g_Join_PulseJoinSelectionHighlightAddressVariant2, 0x00000002, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAlternateAddressVariant2, 0x00000001, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAddressVariant2, 0x00000007,
    0x00000017, (unsigned int)g_Join_SelectPreviousUsJoinModelCallbackAddressUs, 0x00000008, 0x00000017, (unsigned int)g_CJoinCharacter_CycleModelSelectionCallbackAddressUs, 0x00000005, 0x00000017, (unsigned int)g_Join_SelectPreviousJoinRowAddressVariant2,
    0x00000006, 0x00000017, (unsigned int)g_Join_SelectNextJoinRowAddressVariant2, 0x0000000A, 0x00000017, (unsigned int)g_Join_CycleJoinRequestRankAddressVariant2, 0x00000000, 0x00000000,
    0x00000000, 0x54000004, 0x00000066,
};
#elif defined(VERSION_US_REV1)
extern char g_Join_CreateUsJoinOptionsMenuCallbackAddressUs[];
extern char g_Join_SelectPreviousUsJoinModelCallbackAddressUs[];
extern char g_CJoinCharacter_CycleModelSelectionCallbackAddressUs[];
extern char g_Join_DestroyJoinOptionsMenuAddressVariant2[];
extern char g_Join_PulseJoinSelectionHighlightAddressVariant2[];
extern char g_Join_RequestJoinOptionsExitAddressVariant2[];
extern char g_Join_RequestJoinOptionsExitAlternateAddressVariant2[];
extern char g_Join_SelectPreviousJoinRowAddressVariant2[];
extern char g_Join_SelectNextJoinRowAddressVariant2[];
extern char g_Join_CycleJoinRequestRankAddressVariant2[];
unsigned int g_joinOptionsEventHandlerRecords[35] = {
    0x00000E06, 0x00000017, (unsigned int)g_Join_CreateUsJoinOptionsMenuCallbackAddressUs, 0x00000E03, 0x00000017, (unsigned int)g_Join_DestroyJoinOptionsMenuAddressVariant2, 0x00000E08, 0x00000017,
    (unsigned int)g_Join_PulseJoinSelectionHighlightAddressVariant2, 0x00000002, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAlternateAddressVariant2, 0x00000001, 0x00000017, (unsigned int)g_Join_RequestJoinOptionsExitAddressVariant2, 0x00000007,
    0x00000017, (unsigned int)g_Join_SelectPreviousUsJoinModelCallbackAddressUs, 0x00000008, 0x00000017, (unsigned int)g_CJoinCharacter_CycleModelSelectionCallbackAddressUs, 0x00000005, 0x00000017, (unsigned int)g_Join_SelectPreviousJoinRowAddressVariant2,
    0x00000006, 0x00000017, (unsigned int)g_Join_SelectNextJoinRowAddressVariant2, 0x0000000A, 0x00000017, (unsigned int)g_Join_CycleJoinRequestRankAddressVariant2, 0x00000000, 0x00000000,
    0x00000000, 0x00000020, 0x00000193,
};
#endif

#if defined(VERSION_EU) || defined(VERSION_US)
unsigned int g_joinOptionsTrailingWords[7] = {
    0x00000092, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif

#if defined(VERSION_EU_X)
unsigned int g_joinOptionsTrailingWords_eu_x[7] = {
    0x00000096, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif

#if defined(VERSION_DE)
unsigned int g_joinOptionsTrailingWords_de[7] = {
    0x00000090, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif
