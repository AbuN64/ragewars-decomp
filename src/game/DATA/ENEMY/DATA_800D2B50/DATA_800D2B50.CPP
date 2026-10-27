
/* ROM-grounded data: rodata/writable/800D2B50 */
#ifdef VERSION_DE
unsigned int s_smackFormat[4] = {
    0x00000000, 0x40490FDB, 0x00000000, 0xC0490FDB,
};
#endif
#ifdef VERSION_EU
unsigned int s_smackFormat[4] = {
    0x00000000, 0x00000000, 0xBF800000, 0xBF3504F3,
};
#endif
#ifdef VERSION_EU_X
unsigned int s_smackFormat[4] = {
    0x00000000, 0x72650000, 0x456E6572, 0x67792072,
};
#endif
#ifdef VERSION_US
unsigned int s_smackFormat[4] = {
    0x00000000, 0x71755200, 0x00D90900, 0x0010000B,
};
#endif
#ifdef VERSION_US_REV1
unsigned int s_smackFormat[4] = {
    0x00000000, 0x00000000, 0x536D6163, 0x6B202573,
};
#endif
