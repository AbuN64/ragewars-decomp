#include "include_asm.h"

/* DATA_800D2B10.CPP */
#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int k_SSmackformatEncodedWordsBlock1[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x3C02800D, 0xFFFFFFFF, 0x8C500000, 0x16020007, 0x00000000,
};
#endif
#if defined(VERSION_EU)
unsigned int k_SSmackformatEncodedWordsBlock1[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x00000000, 0xFFFFFFFF, 0x3F3504F3, 0x00000000, 0xBF3504F3,
};
#endif
#if defined(VERSION_EU_X)
unsigned int k_SSmackformatEncodedWordsBlock1[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x6B202573, 0xFFFFFFFF, 0x6F722066, 0x696E6420, 0x506F7765,
};
#endif
#if defined(VERSION_US)
unsigned int k_SSmackformatEncodedWordsBlock1[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x00000016, 0xFFFFFFFF, 0x494E464C, 0x41544F52, 0x5F524543,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* Announce message block shared by the menu handler table: ids 10..18 followed by the kill-message
   text tail "nted", "Embryo Destr". us-rev1 wording; the other cartridges word this block in their
   own language, so only the versions carrying these bytes land here. */
unsigned int k_SSmackformatEncodedWords[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x6E746564, 0xFFFFFFFF, 0x456D6272, 0x796F2044, 0x65737472,
};
#endif

/* DATA_800D2B50.CPP */
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

/* DATA_800D2B60.CPP */
/* ROM-grounded data: rodata/unresolved/800D2B60 */
unsigned int g_SSmackformatEncodedWords[4] = {
    0x00000000, 0x40490FDB, 0x00000000, 0xC0490FDB,
};
