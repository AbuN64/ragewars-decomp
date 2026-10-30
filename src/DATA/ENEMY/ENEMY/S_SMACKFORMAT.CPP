#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* k_SSmackformatEncodedWordsBlock1_SSmackformat.CPP */
#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
RestSSmackformatEncodedWordsBlock1Layout339 k_SSmackformatEncodedWordsBlock1 = {
    { 0, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18 },
    0.0079651f,
    -1,
    0x8C500000,
    0x16020007,
    0,
};
#endif
#if defined(VERSION_EU)
RestSSmackformatEncodedWordsBlock1Layout340 k_SSmackformatEncodedWordsBlock1 = {
    { 0, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18, 0, -1 },
    { 0.70710677f, 0.0f, -0.70710677f },
};
#endif
#if defined(VERSION_EU_X)
RestSSmackformatEncodedWordsBlock1Layout341 k_SSmackformatEncodedWordsBlock1 = {
    { 0, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18 },
    "k %s",
    -1,
    "or find Powe",
};
#endif
#if defined(VERSION_US)
RestSSmackformatEncodedWordsBlock1Layout342 k_SSmackformatEncodedWordsBlock1 = {
    { 0, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18, 22, -1 },
    "INFLATOR_REC",
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* Announce message block shared by the menu handler table: ids 10..18 followed by the kill-message
   text tail "nted", "Embryo Destr". us-rev1 wording; the other cartridges word this block in their
   own language, so only the versions carrying these bytes land here. */
RestSSmackformatEncodedWordsLayout343 k_SSmackformatEncodedWords = {
    { 0, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18 },
    "nted",
    -1,
    "Embryo Destr",
};
#endif

/* s_smackFormat_SSmackformat.CPP */
/* ROM-grounded data: rodata/writable/800D2B50 */
#ifdef VERSION_DE
float s_smackFormat[4] = {
    0.0f, 3.1415927f, 0.0f, -3.1415927f,
};
#endif
#ifdef VERSION_EU
RestsmackFormatLayout345 s_smackFormat = {
    { 0, 0 },
    { -1.0f, -0.70710677f },
};
#endif
#ifdef VERSION_EU_X
char s_smackFormat[16] = "\000\000\000\000re\000\000Energy r";
#endif
#ifdef VERSION_US
RestsmackFormatLayout347 s_smackFormat = {
    0,
    "quR\000",
    { 14223616, 1048587 },
};
#endif
#ifdef VERSION_US_REV1
char s_smackFormat[16] = "\000\000\000\000\000\000\000\000Smack %s";
#endif

/* g_SSmackformatEncodedWords_SSmackformat.CPP */
/* ROM-grounded data: rodata/unresolved/800D2B60 */
float g_SSmackformatEncodedWords[4] = {
    0.0f, 3.1415927f, 0.0f, -3.1415927f,
};
