#include "include_asm.h"

/* DATA_800E3590.CPP */
/* ROM-grounded data: rodata/writable/800E3590 */
unsigned int g_slotSelectionMenuInitialWord[1] = {
    0x00000000,
};

/* DATA_800E3594.CPP */
#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_slotSelectionTextReferenceShared1[];
extern char g_slotSelectionTextReferenceShared2[];
extern char g_slotSelectionTextReferenceShared3[];
extern char g_slotSelectionTextReferenceShared4[];
extern char g_slotSelectionTextReferenceShared5[];
unsigned int k_FrontendAnimateslotselectionmenuEncodedWords[267] = {
    0x000001FD, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x4, 0x000001FE, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x8, 0x000001FF, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xC, 0x00000200, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x10,
    0x00000201, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x14, 0x00000202, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x18, 0x00000203, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x1C, 0x00000204, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x20,
    0x00000205, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x24, 0x00000206, (unsigned int)g_slotSelectionTextReferenceShared5, 0x00000207, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x4, 0x00000208, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x8,
    0x00000209, (unsigned int)g_slotSelectionTextReferenceShared5 + 0xC, 0x0000020A, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x10, 0x0000020B, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x14, 0x0000020C, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x18,
    0x0000020D, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x1C, 0x0000020E, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x20, 0x0000020F, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x24, 0x00000210, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x28,
    0x00000211, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x2C, 0x00000212, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x30, 0x00000213, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x34, 0x00000214, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x38,
    0x00000215, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x3C, 0x00000216, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x40, 0x00000217, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x44, 0x00000218, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x48,
    0x00000219, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x4C, 0x0000021A, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x50, 0x0000021B, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x54, 0x0000021C, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x58,
    0x0000021D, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x5C, 0x0000021E, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x60, 0x0000021F, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x64, 0x00000220, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x68,
    0x00000221, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x6C, 0x00000222, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x70, 0x00000223, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x74, 0x00000224, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x78,
    0x00000225, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x7C, 0x00000226, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x80, 0x00000227, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x84, 0x00000228, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x88,
    0x00000229, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x8C, 0x0000022A, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x90, 0x0000022B, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x94, 0x0000022C, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x98,
    0x0000022D, (unsigned int)g_slotSelectionTextReferenceShared5 + 0x9C, 0x0000022E, (unsigned int)g_slotSelectionTextReferenceShared5 + 0xA0, 0x00000E08, 0x00000010, 0x0041D134, 0x00000E07,
    0x00000010, 0x0041DBCC, 0x0000000A, 0x00000010, 0x0041DDF4, 0x00000E0A, 0x00000010, 0x0041DCC0,
    0x00000E06, 0x00000010, 0x0041CE40, 0x00000E03, 0x00000010, 0x0041DB9C, 0x00000002, 0x00000010,
    0x0041DE5C, 0x00000001, 0x00000010, 0x0041DE94, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x8, 0x00000001, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x50, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x20,
    0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x2C, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x4, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x14, 0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x10,
    0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x1C, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x4, 0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x44, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x28,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x10, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x18, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared3, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x14,
    0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x34, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x38, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0xC, 0x00000001, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x54,
    0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x24, 0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x30, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x8, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x18,
    0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x14, 0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x20, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x8, 0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x48,
    0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x2C, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x10, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x18, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared3,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x14, 0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x38, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x3C, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x10,
    0x00000001, (unsigned int)g_slotSelectionTextReferenceShared2, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x28, 0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x34, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared2 + 0xC,
    0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x1C, 0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x18, 0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x24, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0xC,
    0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x4C, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x30, 0x0000000B, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x10, 0x0000000C, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x18,
    0x0000000D, (unsigned int)g_slotSelectionTextReferenceShared3, 0x0000000E, (unsigned int)g_slotSelectionTextReferenceShared2 + 0x14, 0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x3C, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x40,
    (unsigned int)g_slotSelectionTextReferenceShared5 + 0xA4, (unsigned int)g_slotSelectionTextReferenceShared5 + 0xA8, (unsigned int)g_slotSelectionTextReferenceShared5 + 0xAC,
};
#endif
#if defined(VERSION_EU)
extern char g_slotSelectionTextReferenceShared7[];
extern char g_slotSelectionTextReferenceEu1[];
extern char g_slotSelectionTextReferenceEu2[];
extern char g_slotSelectionTextReferenceEu3[];
extern char g_slotSelectionTextReferenceEu4[];
extern char g_slotSelectionTextReferenceEu5[];
extern char g_slotSelectionTextReferenceEu6[];
extern char g_slotSelectionTextReferenceEu7[];
extern char g_slotSelectionTextReferenceEu8[];
extern char g_slotSelectionTextReferenceEu9[];
extern char g_slotSelectionTextReferenceEu10[];
extern char g_slotSelectionTextReferenceEu11[];
extern char g_slotSelectionTextReferenceEu12[];
extern char g_slotSelectionTextReferenceEu13[];
extern char g_slotSelectionTextReferenceEu14[];
extern char g_slotSelectionTextReferenceEu15[];
extern char g_slotSelectionTextReferenceEu16[];
unsigned int k_FrontendAnimateslotselectionmenuEncodedWords[267] = {
    0x00000201, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x10, 0x00000202, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x20, 0x00000203, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x30, 0x00000204, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x40,
    0x00000205, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x50, 0x00000206, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x60, 0x00000207, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x70, 0x00000208, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x80,
    0x00000209, (unsigned int)g_slotSelectionTextReferenceEu7 + 0x90, 0x0000020A, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xA0, 0x0000020B, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xB0, 0x0000020C, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xC0,
    0x0000020D, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xD0, 0x0000020E, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xE0, 0x0000020F, (unsigned int)g_slotSelectionTextReferenceEu8 + 0xA, 0x00000210, (unsigned int)g_slotSelectionTextReferenceEu9 + 0x2,
    0x00000211, (unsigned int)g_slotSelectionTextReferenceEu9 + 0x12, 0x00000212, (unsigned int)g_slotSelectionTextReferenceEu9 + 0x22, 0x00000213, (unsigned int)g_slotSelectionTextReferenceEu10 + 0x6, 0x00000214, (unsigned int)g_slotSelectionTextReferenceEu11 + 0xC,
    0x00000215, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x1C, 0x00000216, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x2C, 0x00000217, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x3C, 0x00000218, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x4C,
    0x00000219, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x5C, 0x0000021A, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x6C, 0x0000021B, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x7C, 0x0000021C, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x8C,
    0x0000021D, (unsigned int)g_slotSelectionTextReferenceEu11 + 0x9C, 0x0000021E, (unsigned int)g_slotSelectionTextReferenceEu11 + 0xAC, 0x0000021F, (unsigned int)g_slotSelectionTextReferenceEu12, 0x00000220, (unsigned int)g_slotSelectionTextReferenceEu13,
    0x00000221, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x4, 0x00000222, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x14, 0x00000223, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x24, 0x00000224, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x34,
    0x00000225, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x44, 0x00000226, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x54, 0x00000227, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x64, 0x00000228, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x74,
    0x00000229, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x84, 0x0000022A, (unsigned int)g_slotSelectionTextReferenceEu14 + 0x94, 0x0000022B, (unsigned int)g_slotSelectionTextReferenceEu15 + 0x4, 0x0000022C, (unsigned int)g_slotSelectionTextReferenceEu15 + 0x14,
    0x0000022D, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x8, 0x0000022E, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x18, 0x0000022F, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x28, 0x00000230, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x38,
    0x00000231, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x48, 0x00000232, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x58, 0x00000E08, 0x00000010, 0x0041D574, 0x00000E07,
    0x00000010, 0x0041E01C, 0x0000000A, 0x00000010, 0x0041E244, 0x00000E0A, 0x00000010, 0x0041E110,
    0x00000E06, 0x00000010, 0x0041D280, 0x00000E03, 0x00000010, 0x0041DFEC, 0x00000002, 0x00000010,
    0x0041E2AC, 0x00000001, 0x00000010, 0x0041E2E4, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x20, 0x00000001, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x60, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x80,
    0x00000003, (unsigned int)g_slotSelectionTextReferenceShared7 + 0xB0, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x90, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x50, 0x00000006, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x34,
    0x00000007, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x64, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x4, 0x00000009, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x30, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x94,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xC0, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xE0, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu4, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xD0,
    0x00000011, (unsigned int)g_slotSelectionTextReferenceEu5 + 0xC4, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEu3, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x30, 0x00000001, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x70,
    0x00000002, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x90, 0x00000003, (unsigned int)g_slotSelectionTextReferenceEu1, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xA0, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x60,
    0x00000006, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x44, 0x00000007, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x74, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x14, 0x00000009, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x40,
    0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu5 + 0xA4, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xC0, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xE0, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu4,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xD0, 0x00000011, (unsigned int)g_slotSelectionTextReferenceEu5 + 0xD4, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x10, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x40,
    0x00000001, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x80, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared7 + 0xA0, 0x00000003, (unsigned int)g_slotSelectionTextReferenceEu2 + 0x4, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xB0,
    0x00000005, (unsigned int)g_slotSelectionTextReferenceShared7 + 0x70, 0x00000006, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x54, 0x00000007, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x84, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu5 + 0x24,
    0x00000009, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x50, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu5 + 0xB4, 0x0000000B, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xC0, 0x0000000C, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xE0,
    0x0000000D, (unsigned int)g_slotSelectionTextReferenceEu4, 0x0000000E, (unsigned int)g_slotSelectionTextReferenceEu3 + 0xD0, 0x00000011, (unsigned int)g_slotSelectionTextReferenceEu6 + 0xC, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEu3 + 0x20,
    (unsigned int)g_slotSelectionTextReferenceEu16 + 0x68, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x78, (unsigned int)g_slotSelectionTextReferenceEu16 + 0x88,
};
#endif
#if defined(VERSION_EU_X)
extern char g_slotSelectionTextReferenceShared6[];
extern char g_slotSelectionTextReferenceEuX1[];
extern char g_slotSelectionTextReferenceEuX2[];
extern char g_slotSelectionTextReferenceEuX3[];
extern char g_slotSelectionTextReferenceEuX4[];
extern char g_slotSelectionTextReferenceEuX5[];
extern char g_slotSelectionTextReferenceEuX6[];
extern char g_slotSelectionTextReferenceEuX7[];
extern char g_slotSelectionTextReferenceEuX8[];
extern char g_slotSelectionTextReferenceEuX9[];
extern char g_slotSelectionTextReferenceEuX10[];
extern char g_slotSelectionTextReferenceEuX11[];
extern char g_slotSelectionTextReferenceEuX12[];
extern char g_slotSelectionTextReferenceEuX13[];
extern char g_slotSelectionTextReferenceEuX14[];
extern char g_slotSelectionTextReferenceEuX15[];
extern char g_slotSelectionTextReferenceEu4[];
extern char g_slotSelectionTextReferenceEu7[];
unsigned int k_FrontendAnimateslotselectionmenuEncodedWords[267] = {
    0x00000205, (unsigned int)g_slotSelectionTextReferenceEu7 + 0xC, 0x00000206, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x8, 0x00000207, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x14, 0x00000208, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x20,
    0x00000209, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x2C, 0x0000020A, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x38, 0x0000020B, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x44, 0x0000020C, (unsigned int)g_slotSelectionTextReferenceEuX7 + 0x50,
    0x0000020D, (unsigned int)g_slotSelectionTextReferenceEuX8, 0x0000020E, (unsigned int)g_slotSelectionTextReferenceEuX9 + 0x4, 0x0000020F, (unsigned int)g_slotSelectionTextReferenceEuX10, 0x00000210, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x4,
    0x00000211, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x10, 0x00000212, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x1C, 0x00000213, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x28, 0x00000214, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x34,
    0x00000215, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x40, 0x00000216, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x4C, 0x00000217, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x58, 0x00000218, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x64,
    0x00000219, (unsigned int)g_slotSelectionTextReferenceEuX11 + 0x70, 0x0000021A, (unsigned int)g_slotSelectionTextReferenceEuX12 + 0x4, 0x0000021B, (unsigned int)g_slotSelectionTextReferenceEuX13, 0x0000021C, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0xC,
    0x0000021D, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x18, 0x0000021E, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x24, 0x0000021F, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x30, 0x00000220, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x3C,
    0x00000221, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x48, 0x00000222, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x54, 0x00000223, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x60, 0x00000224, (unsigned int)g_slotSelectionTextReferenceEuX13 + 0x6C,
    0x00000225, (unsigned int)g_slotSelectionTextReferenceEuX14, 0x00000226, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x4, 0x00000227, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x10, 0x00000228, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x1C,
    0x00000229, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x28, 0x0000022A, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x34, 0x0000022B, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x40, 0x0000022C, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x4C,
    0x0000022D, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x58, 0x0000022E, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x64, 0x0000022F, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x70, 0x00000230, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x7C,
    0x00000231, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x88, 0x00000232, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0x94, 0x00000233, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xA0, 0x00000234, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xAC,
    0x00000235, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xB8, 0x00000236, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xC4, 0x00000E08, 0x00000010, 0x0041D574, 0x00000E07,
    0x00000010, 0x0041E01C, 0x0000000A, 0x00000010, 0x0041E244, 0x00000E0A, 0x00000010, 0x0041E110,
    0x00000E06, 0x00000010, 0x0041D280, 0x00000E03, 0x00000010, 0x0041DFEC, 0x00000002, 0x00000010,
    0x0041E2AC, 0x00000001, 0x00000010, 0x0041E2E4, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x18, 0x00000001, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x24, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x60,
    0x00000003, (unsigned int)g_slotSelectionTextReferenceEuX1 + 0x8, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x48, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x3C, 0x00000006, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x30,
    0x00000007, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x54, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu4 + 0xC, 0x00000009, (unsigned int)g_slotSelectionTextReferenceEuX6, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x78,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x6C, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x84, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu4, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x78,
    0x00000011, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x9C, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEuX4 + 0x4, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x24, 0x00000001, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x30,
    0x00000002, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x6C, 0x00000003, (unsigned int)g_slotSelectionTextReferenceEuX2 + 0x4, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x54, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x48,
    0x00000006, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x3C, 0x00000007, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x60, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x18, 0x00000009, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0xC,
    0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x84, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x6C, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x84, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEu4,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x78, 0x00000011, (unsigned int)g_slotSelectionTextReferenceEu4 + 0xA8, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEuX4 + 0x10, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x30,
    0x00000001, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x3C, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x78, 0x00000003, (unsigned int)g_slotSelectionTextReferenceEuX3 + 0x8, 0x00000004, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x60,
    0x00000005, (unsigned int)g_slotSelectionTextReferenceShared6 + 0x54, 0x00000006, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x48, 0x00000007, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x6C, 0x00000008, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x24,
    0x00000009, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x18, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceEu4 + 0x90, 0x0000000B, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x6C, 0x0000000C, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x84,
    0x0000000D, (unsigned int)g_slotSelectionTextReferenceEu4, 0x0000000E, (unsigned int)g_slotSelectionTextReferenceEuX6 + 0x78, 0x00000011, (unsigned int)g_slotSelectionTextReferenceEu4 + 0xB4, 0x00000012, (unsigned int)g_slotSelectionTextReferenceEuX5 + 0x8,
    (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xD0, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xDC, (unsigned int)g_slotSelectionTextReferenceEuX15 + 0xE8,
};
#endif
#if defined(VERSION_US)
extern char g_slotSelectionTextReferenceShared1[];
extern char g_slotSelectionTextReferenceShared3[];
extern char g_slotSelectionTextReferenceShared4[];
unsigned int k_FrontendAnimateslotselectionmenuEncodedWords[267] = {
    0x00000201, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x4, 0x00000202, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x8, 0x00000203, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xC, 0x00000204, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x10,
    0x00000205, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x14, 0x00000206, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x18, 0x00000207, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x1C, 0x00000208, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x20,
    0x00000209, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x24, 0x0000020A, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x28, 0x0000020B, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x2C, 0x0000020C, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x30,
    0x0000020D, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x34, 0x0000020E, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x38, 0x0000020F, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x3C, 0x00000210, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x40,
    0x00000211, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x44, 0x00000212, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x48, 0x00000213, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x4C, 0x00000214, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x50,
    0x00000215, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x54, 0x00000216, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x58, 0x00000217, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x5C, 0x00000218, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x60,
    0x00000219, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x64, 0x0000021A, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x68, 0x0000021B, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x6C, 0x0000021C, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x70,
    0x0000021D, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x74, 0x0000021E, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x78, 0x0000021F, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x7C, 0x00000220, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x80,
    0x00000221, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x84, 0x00000222, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x88, 0x00000223, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x8C, 0x00000224, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x90,
    0x00000225, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x94, 0x00000226, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x98, 0x00000227, (unsigned int)g_slotSelectionTextReferenceShared4 + 0x9C, 0x00000228, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xA0,
    0x00000229, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xA4, 0x0000022A, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xA8, 0x0000022B, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xAC, 0x0000022C, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xB0,
    0x0000022D, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xB4, 0x0000022E, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xB8, 0x0000022F, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xBC, 0x00000230, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xC0,
    0x00000231, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xC4, 0x00000232, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xC8, 0x00000E08, 0x00000010, 0x0041D1A4, 0x00000E07,
    0x00000010, 0x0041DC3C, 0x0000000A, 0x00000010, 0x0041DE64, 0x00000E0A, 0x00000010, 0x0041DD30,
    0x00000E06, 0x00000010, 0x0041CEB0, 0x00000E03, 0x00000010, 0x0041DC0C, 0x00000002, 0x00000010,
    0x0041DECC, 0x00000001, 0x00000010, 0x0041DF04, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x8, 0x00000001, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x50, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x20,
    0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x2C, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x5C, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x14, 0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x10,
    0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x1C, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x4, 0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x44, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x28,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x68, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x70, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared3, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x6C,
    0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x34, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x38, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0xC, 0x00000001, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x54,
    0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x24, 0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x30, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x60, 0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x18,
    0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x14, 0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x20, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x8, 0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x48,
    0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x2C, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x68, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x70, 0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared3,
    0xFFFFFFFF, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x6C, 0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x38, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x3C, 0x00000000, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x10,
    0x00000001, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x58, 0x00000002, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x28, 0x00000003, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x34, 0x00000004, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x64,
    0x00000005, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x1C, 0x00000006, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x18, 0x00000007, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x24, 0x00000008, (unsigned int)g_slotSelectionTextReferenceShared3 + 0xC,
    0x00000009, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x4C, 0x0000000A, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x30, 0x0000000B, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x68, 0x0000000C, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x70,
    0x0000000D, (unsigned int)g_slotSelectionTextReferenceShared3, 0x0000000E, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x6C, 0x00000011, (unsigned int)g_slotSelectionTextReferenceShared3 + 0x3C, 0x00000012, (unsigned int)g_slotSelectionTextReferenceShared1 + 0x40,
    (unsigned int)g_slotSelectionTextReferenceShared4 + 0xCC, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xD0, (unsigned int)g_slotSelectionTextReferenceShared4 + 0xD4,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_slotSelectionLabelIdPointerPairsUsRev1[100] = {
    0x00000201, 0x800D73C8, 0x00000202, 0x800D73CC, 0x00000203, 0x800D73D0, 0x00000204, 0x800D73D4,
    0x00000205, 0x800D73D8, 0x00000206, 0x800D73DC, 0x00000207, 0x800D73E0, 0x00000208, 0x800D73E4,
    0x00000209, 0x800D73E8, 0x0000020A, 0x800D73EC, 0x0000020B, 0x800D73F0, 0x0000020C, 0x800D73F4,
    0x0000020D, 0x800D73F8, 0x0000020E, 0x800D73FC, 0x0000020F, 0x800D7400, 0x00000210, 0x800D7404,
    0x00000211, 0x800D7408, 0x00000212, 0x800D740C, 0x00000213, 0x800D7410, 0x00000214, 0x800D7414,
    0x00000215, 0x800D7418, 0x00000216, 0x800D741C, 0x00000217, 0x800D7420, 0x00000218, 0x800D7424,
    0x00000219, 0x800D7428, 0x0000021A, 0x800D742C, 0x0000021B, 0x800D7430, 0x0000021C, 0x800D7434,
    0x0000021D, 0x800D7438, 0x0000021E, 0x800D743C, 0x0000021F, 0x800D7440, 0x00000220, 0x800D7444,
    0x00000221, 0x800D7448, 0x00000222, 0x800D744C, 0x00000223, 0x800D7450, 0x00000224, 0x800D7454,
    0x00000225, 0x800D7458, 0x00000226, 0x800D745C, 0x00000227, 0x800D7460, 0x00000228, 0x800D7464,
    0x00000229, 0x800D7468, 0x0000022A, 0x800D746C, 0x0000022B, 0x800D7470, 0x0000022C, 0x800D7474,
    0x0000022D, 0x800D7478, 0x0000022E, 0x800D747C, 0x0000022F, 0x800D7480, 0x00000230, 0x800D7484,
    0x00000231, 0x800D7488, 0x00000232, 0x800D748C,
};
#endif
