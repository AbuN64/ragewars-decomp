#include "include_asm.h"
#include "DATA/COMMON/FX_SPAWNIMPACTMARK_DATA.H"

/* DATA_800D2E40.CPP */
#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char D_800CDA34_de[];
unsigned int k_FxSpawnimpactmarkEncodedWords[6] = {
    (unsigned int)D_800CDA34_de + 0xC, (unsigned int)D_800CDA34_de + 0x34, (unsigned int)D_800CDA34_de + 0x5C, (unsigned int)D_800CDA34_de + 0xD4, (unsigned int)D_800CDA34_de + 0x14C, (unsigned int)D_800CDA34_de + 0x174,
};
#endif
#if defined(VERSION_EU)
extern char D_800CDA34_de[];
unsigned int k_FxSpawnimpactmarkEncodedWords[6] = {
    (unsigned int)D_800CDA34_de + 0xC, (unsigned int)D_800CDA34_de + 0x34, (unsigned int)D_800CDA34_de + 0x5C, (unsigned int)D_800CDA34_de + 0xD4, (unsigned int)D_800CDA34_de + 0x14C, (unsigned int)D_800CDA34_de + 0x174,
};
#endif
#if defined(VERSION_EU_X)
extern char D_800CDA34_de[];
unsigned int k_FxSpawnimpactmarkEncodedWords[6] = {
    (unsigned int)D_800CDA34_de + 0xC, (unsigned int)D_800CDA34_de + 0x34, (unsigned int)D_800CDA34_de + 0x5C, (unsigned int)D_800CDA34_de + 0xD4, (unsigned int)D_800CDA34_de + 0x14C, (unsigned int)D_800CDA34_de + 0x174,
};
#endif
#if defined(VERSION_US)
extern char D_800CDA34_de[];
unsigned int k_FxSpawnimpactmarkEncodedWords[6] = {
    (unsigned int)D_800CDA34_de + 0xC, (unsigned int)D_800CD978_us, (unsigned int)D_800CD9A0_us, (unsigned int)D_800CD9B8_us + 0x60, (unsigned int)D_800CDA2C_us + 0x64, (unsigned int)D_800CDA2C_us + 0x8C,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int g_ribbonBlendResourceTable_StorageWords[6] = {
    0x800D2CB0, 0x800D2CD8, 0x800D2D00, 0x800D2D78, 0x800D2DF0, 0x800D2E18,
};
#endif

/* DATA_800D2E58.CPP */
/* ROM-grounded data: rodata/writable/800D2E58 */
unsigned int g_FxSpawnimpactmarkEncodedWords[2] = {
    0x00000000, 0x00000000,
};
