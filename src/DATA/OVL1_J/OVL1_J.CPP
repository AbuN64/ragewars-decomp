

/* 80408CB0_16.CPP */
#if defined(VERSION_EU)
unsigned char g_Ovl1JTrailingBytes[8] = { 0x27, 0xA5, 0x00, 0x48, 0x27, 0xA6, 0x00, 0x44 };
#endif

/* g_frontendLoadoutResourceHalfwords_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
/* Resource IDs are read with lhu at +2 within each four-byte slot.
 * Keep the intervening halfwords: native u32 storage moves IDs to +0.
 * Player_CreateFourPlayerResults: 8043A198..8043A1E8, stride 0x4C. */
unsigned short g_frontendLoadoutResourceHalfwords[150] = {
    0x0000, 0x0132, 0x0000, 0x00EA, 0x0000, 0x00EB, 0x0000, 0x00EC, 0x0000, 0x00ED, 0x0000, 0x00EE,
    0x0000, 0x00EF, 0x0000, 0x0122, 0x0000, 0x0121, 0x0000, 0x0120, 0x0000, 0x011F, 0x0000, 0x011E,
    0x0000, 0x00DE, 0x0000, 0x00E0, 0x0000, 0x00E2, 0x0000, 0x00E4, 0x0000, 0x00E6, 0x0000, 0x00E8,
    0x0000, 0x00F7, 0x0000, 0x0133, 0x0000, 0x0111, 0x0000, 0x0112, 0x0000, 0x0113, 0x0000, 0x0114,
    0x0000, 0x0115, 0x0000, 0x0116, 0x0000, 0x0128, 0x0000, 0x0129, 0x0000, 0x012A, 0x0000, 0x012B,
    0x0000, 0x012C, 0x0000, 0x00FB, 0x0000, 0x00FD, 0x0000, 0x00FF, 0x0000, 0x0101, 0x0000, 0x0103,
    0x0000, 0x0105, 0x0000, 0x00CF, 0x0000, 0x0134, 0x0000, 0x00F0, 0x0000, 0x00F1, 0x0000, 0x00F2,
    0x0000, 0x00F3, 0x0000, 0x00F4, 0x0000, 0x00F5, 0x0000, 0x0131, 0x0000, 0x0130, 0x0000, 0x012F,
    0x0000, 0x012E, 0x0000, 0x012D, 0x0000, 0x00D3, 0x0000, 0x00D5, 0x0000, 0x00D7, 0x0000, 0x00D9,
    0x0000, 0x00DB, 0x0000, 0x00DD, 0x0000, 0x00F9, 0x0000, 0x0135, 0x0000, 0x0117, 0x0000, 0x0118,
    0x0000, 0x0119, 0x0000, 0x011A, 0x0000, 0x011B, 0x0000, 0x011C, 0x0000, 0x0123, 0x0000, 0x0124,
    0x0000, 0x0125, 0x0000, 0x0126, 0x0000, 0x0127, 0x0000, 0x0106, 0x0000, 0x0108, 0x0000, 0x010A,
    0x0000, 0x010C, 0x0000, 0x010E, 0x0000, 0x0110,
};
#endif

/* g_LoadoutEquipmentItemsUsRev1_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_LoadoutEquipmentItemsUsRev1[12] = {
    0x00000098, 0x00001397, 0x0000000A, 0x800D711C, 0x000000AD, 0x00001396, 0x0000000C, 0x800D7124,
    0x000000AF, 0x000013AD, 0x0000000B, 0x800D7120,
};
#endif

/* g_loadoutWeaponItems_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_loadoutWeaponItems[32] = {
    0x000000B3, 0x000013A9, 0x00000001, 0x800D70F8, 0x000000A2, 0x0000139B, 0x0000000F, 0x800D7130,
    0x0000009A, 0x000013A1, 0x0000000D, 0x800D7128, 0x0000009B, 0x000013A2, 0x00000009, 0x800D7118,
    0x00000099, 0x0000139A, 0x00000008, 0x800D7114, 0x000000AA, 0x0000138D, 0x0000000E, 0x800D712C,
    0x000000AE, 0x0000138F, 0x00000007, 0x800D7110, 0x000000B0, 0x0000138C, 0x00000002, 0x800D70FC,
};
#endif

/* g_LoadoutAbilitiesItemsUsRev1_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_LoadoutAbilitiesItemsUsRev1[16] = {
    0x000000A9, 0x000013A7, 0x00000005, 0x800D7108, 0x000000AB, 0x0000139E, 0x00000003, 0x800D7100,
    0x000000AC, 0x00001393, 0x00000006, 0x800D710C, 0x000000B1, 0x0000138B, 0x00000004, 0x800D7104,
};
#endif

/* g_MenuEventHandlersE6804UsRev1_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
extern char addrLow_Player_StartFourPlayerResults[];
extern char addrLow_Player_UpdateFourPlayerResults[];
extern char addrLow_Player_DrawFourPlayerResults[];
unsigned int g_MenuEventHandlersE6804UsRev1[9] = {
    0x00000E07, 0x00000008, (unsigned int)addrLow_Player_StartFourPlayerResults, 0x00000E08, 0x00000008, (unsigned int)addrLow_Player_UpdateFourPlayerResults, 0x00000E0A, 0x00000008,
    (unsigned int)addrLow_Player_DrawFourPlayerResults,
};
#endif

/* g_MenuEventHandlersE6834UsRev1_Ovl1J.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E59E6_unclaimed_E6828 */
extern char addrLow_Player_CreateFourPlayerResults[];
unsigned int g_Ovl1JEncodedWords[3] = {
    0x00000E06, 0x00000008, (unsigned int)addrLow_Player_CreateFourPlayerResults,
};

extern char addrLow_Frontend_ConfirmEquipmentSelection[];
extern char addrLow_Frontend_FreeEquipmentScreen[];
extern char addrLow_Frontend_RestoreEquipmentSelections[];
extern char addrLow_Frontend_SelectPreviousEquipmentColumn[];
extern char addrLow_Frontend_SelectNextEquipmentColumn[];
extern char addrLow_Frontend_SelectPreviousEquipmentChoice[];
extern char addrLow_Frontend_SelectNextEquipmentChoice[];
extern char addrLow_Frontend_CancelEquipmentSelection[];
unsigned int g_MenuEventHandlersE6834UsRev1[27] = {
    0x00000E03, 0x00000008, (unsigned int)addrLow_Frontend_FreeEquipmentScreen, 0x0000000A, 0x00000008, (unsigned int)addrLow_Frontend_RestoreEquipmentSelections, 0x00000002, 0x00000008,
    (unsigned int)addrLow_Frontend_CancelEquipmentSelection, 0x00000001, 0x00000008, (unsigned int)addrLow_Frontend_ConfirmEquipmentSelection, 0x00000007, 0x00007530, (unsigned int)addrLow_Frontend_SelectPreviousEquipmentChoice, 0x00000005,
    0x00007530, (unsigned int)addrLow_Frontend_SelectPreviousEquipmentColumn, 0x00000008, 0x00007530, (unsigned int)addrLow_Frontend_SelectNextEquipmentChoice, 0x00000006, 0x00007530, (unsigned int)addrLow_Frontend_SelectNextEquipmentColumn,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
