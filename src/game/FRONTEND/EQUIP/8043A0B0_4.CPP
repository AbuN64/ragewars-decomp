/* ROM-grounded data: rodata/Frontend_ShowEquipChoice/800E2028 (the function's own switch table now
   comes from its C; what follows it in eu and us stays here) */
#ifdef VERSION_EU
const unsigned int g_equipmentSelectionRetainedData[8] = {
    0x0043C7BC, 0x0043C7BC, 0x0043C7DC, 0x0043C7DC, 0x0043C7CC, 0x4B6A5B31, 0x4B005B72, 0x4A0A6744,
};
#endif
#ifdef VERSION_US
const unsigned int g_equipmentSelectionRetainedData[8] = {
    0x0043BABC, 0x0043BABC, 0x0043BADC, 0x0043BADC, 0x0043BACC, 0x73520000, 0x00000000, 0x0F000A00,
};
#endif
