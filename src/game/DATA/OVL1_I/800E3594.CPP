#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char D_800D3250[];
extern char D_800D32A8_de[];
extern char D_800D32C4[];
extern char D_800D3398[];
extern char D_800D33C0_de[];
unsigned int rodata_unresolved_800E3594[267] = {
    0x000001FD, (unsigned int)D_800D3398 + 0x4, 0x000001FE, (unsigned int)D_800D3398 + 0x8, 0x000001FF, (unsigned int)D_800D3398 + 0xC, 0x00000200, (unsigned int)D_800D3398 + 0x10,
    0x00000201, (unsigned int)D_800D3398 + 0x14, 0x00000202, (unsigned int)D_800D3398 + 0x18, 0x00000203, (unsigned int)D_800D3398 + 0x1C, 0x00000204, (unsigned int)D_800D3398 + 0x20,
    0x00000205, (unsigned int)D_800D3398 + 0x24, 0x00000206, (unsigned int)D_800D33C0_de, 0x00000207, (unsigned int)D_800D33C0_de + 0x4, 0x00000208, (unsigned int)D_800D33C0_de + 0x8,
    0x00000209, (unsigned int)D_800D33C0_de + 0xC, 0x0000020A, (unsigned int)D_800D33C0_de + 0x10, 0x0000020B, (unsigned int)D_800D33C0_de + 0x14, 0x0000020C, (unsigned int)D_800D33C0_de + 0x18,
    0x0000020D, (unsigned int)D_800D33C0_de + 0x1C, 0x0000020E, (unsigned int)D_800D33C0_de + 0x20, 0x0000020F, (unsigned int)D_800D33C0_de + 0x24, 0x00000210, (unsigned int)D_800D33C0_de + 0x28,
    0x00000211, (unsigned int)D_800D33C0_de + 0x2C, 0x00000212, (unsigned int)D_800D33C0_de + 0x30, 0x00000213, (unsigned int)D_800D33C0_de + 0x34, 0x00000214, (unsigned int)D_800D33C0_de + 0x38,
    0x00000215, (unsigned int)D_800D33C0_de + 0x3C, 0x00000216, (unsigned int)D_800D33C0_de + 0x40, 0x00000217, (unsigned int)D_800D33C0_de + 0x44, 0x00000218, (unsigned int)D_800D33C0_de + 0x48,
    0x00000219, (unsigned int)D_800D33C0_de + 0x4C, 0x0000021A, (unsigned int)D_800D33C0_de + 0x50, 0x0000021B, (unsigned int)D_800D33C0_de + 0x54, 0x0000021C, (unsigned int)D_800D33C0_de + 0x58,
    0x0000021D, (unsigned int)D_800D33C0_de + 0x5C, 0x0000021E, (unsigned int)D_800D33C0_de + 0x60, 0x0000021F, (unsigned int)D_800D33C0_de + 0x64, 0x00000220, (unsigned int)D_800D33C0_de + 0x68,
    0x00000221, (unsigned int)D_800D33C0_de + 0x6C, 0x00000222, (unsigned int)D_800D33C0_de + 0x70, 0x00000223, (unsigned int)D_800D33C0_de + 0x74, 0x00000224, (unsigned int)D_800D33C0_de + 0x78,
    0x00000225, (unsigned int)D_800D33C0_de + 0x7C, 0x00000226, (unsigned int)D_800D33C0_de + 0x80, 0x00000227, (unsigned int)D_800D33C0_de + 0x84, 0x00000228, (unsigned int)D_800D33C0_de + 0x88,
    0x00000229, (unsigned int)D_800D33C0_de + 0x8C, 0x0000022A, (unsigned int)D_800D33C0_de + 0x90, 0x0000022B, (unsigned int)D_800D33C0_de + 0x94, 0x0000022C, (unsigned int)D_800D33C0_de + 0x98,
    0x0000022D, (unsigned int)D_800D33C0_de + 0x9C, 0x0000022E, (unsigned int)D_800D33C0_de + 0xA0, 0x00000E08, 0x00000010, 0x0041D134, 0x00000E07,
    0x00000010, 0x0041DBCC, 0x0000000A, 0x00000010, 0x0041DDF4, 0x00000E0A, 0x00000010, 0x0041DCC0,
    0x00000E06, 0x00000010, 0x0041CE40, 0x00000E03, 0x00000010, 0x0041DB9C, 0x00000002, 0x00000010,
    0x0041DE5C, 0x00000001, 0x00000010, 0x0041DE94, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)D_800D3250 + 0x8, 0x00000001, (unsigned int)D_800D3250 + 0x50, 0x00000002, (unsigned int)D_800D3250 + 0x20,
    0x00000003, (unsigned int)D_800D3250 + 0x2C, 0x00000004, (unsigned int)D_800D32A8_de + 0x4, 0x00000005, (unsigned int)D_800D3250 + 0x14, 0x00000006, (unsigned int)D_800D32C4 + 0x10,
    0x00000007, (unsigned int)D_800D32C4 + 0x1C, 0x00000008, (unsigned int)D_800D32C4 + 0x4, 0x00000009, (unsigned int)D_800D3250 + 0x44, 0x0000000A, (unsigned int)D_800D32C4 + 0x28,
    0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x10, 0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x18, 0xFFFFFFFF, (unsigned int)D_800D32C4, 0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x14,
    0x00000011, (unsigned int)D_800D32C4 + 0x34, 0x00000012, (unsigned int)D_800D3250 + 0x38, 0x00000000, (unsigned int)D_800D3250 + 0xC, 0x00000001, (unsigned int)D_800D3250 + 0x54,
    0x00000002, (unsigned int)D_800D3250 + 0x24, 0x00000003, (unsigned int)D_800D3250 + 0x30, 0x00000004, (unsigned int)D_800D32A8_de + 0x8, 0x00000005, (unsigned int)D_800D3250 + 0x18,
    0x00000006, (unsigned int)D_800D32C4 + 0x14, 0x00000007, (unsigned int)D_800D32C4 + 0x20, 0x00000008, (unsigned int)D_800D32C4 + 0x8, 0x00000009, (unsigned int)D_800D3250 + 0x48,
    0x0000000A, (unsigned int)D_800D32C4 + 0x2C, 0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x10, 0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x18, 0xFFFFFFFF, (unsigned int)D_800D32C4,
    0xFFFFFFFF, (unsigned int)D_800D32A8_de + 0x14, 0x00000011, (unsigned int)D_800D32C4 + 0x38, 0x00000012, (unsigned int)D_800D3250 + 0x3C, 0x00000000, (unsigned int)D_800D3250 + 0x10,
    0x00000001, (unsigned int)D_800D32A8_de, 0x00000002, (unsigned int)D_800D3250 + 0x28, 0x00000003, (unsigned int)D_800D3250 + 0x34, 0x00000004, (unsigned int)D_800D32A8_de + 0xC,
    0x00000005, (unsigned int)D_800D3250 + 0x1C, 0x00000006, (unsigned int)D_800D32C4 + 0x18, 0x00000007, (unsigned int)D_800D32C4 + 0x24, 0x00000008, (unsigned int)D_800D32C4 + 0xC,
    0x00000009, (unsigned int)D_800D3250 + 0x4C, 0x0000000A, (unsigned int)D_800D32C4 + 0x30, 0x0000000B, (unsigned int)D_800D32A8_de + 0x10, 0x0000000C, (unsigned int)D_800D32A8_de + 0x18,
    0x0000000D, (unsigned int)D_800D32C4, 0x0000000E, (unsigned int)D_800D32A8_de + 0x14, 0x00000011, (unsigned int)D_800D32C4 + 0x3C, 0x00000012, (unsigned int)D_800D3250 + 0x40,
    (unsigned int)D_800D33C0_de + 0xA4, (unsigned int)D_800D33C0_de + 0xA8, (unsigned int)D_800D33C0_de + 0xAC,
};
#endif
#if defined(VERSION_EU)
extern char D_800E1394[];
extern char D_800E1454_eu[];
extern char D_800E1460_eu[];
extern char D_800E1474_eu[];
extern char D_800E1564_eu[];
extern char D_800E1570_eu[];
extern char D_800E1648_eu[];
extern char D_800E18B4_eu[];
extern char D_800E199A_eu[];
extern char D_800E19B2_eu[];
extern char D_800E19DE_eu[];
extern char D_800E19E8_eu[];
extern char D_800E1AA4_eu[];
extern char D_800E1AB4_eu[];
extern char D_800E1AC0_eu[];
extern char D_800E1B60_eu[];
extern char D_800E1B7C_eu[];
unsigned int rodata_unresolved_800E3594[267] = {
    0x00000201, (unsigned int)D_800E18B4_eu + 0x10, 0x00000202, (unsigned int)D_800E18B4_eu + 0x20, 0x00000203, (unsigned int)D_800E18B4_eu + 0x30, 0x00000204, (unsigned int)D_800E18B4_eu + 0x40,
    0x00000205, (unsigned int)D_800E18B4_eu + 0x50, 0x00000206, (unsigned int)D_800E18B4_eu + 0x60, 0x00000207, (unsigned int)D_800E18B4_eu + 0x70, 0x00000208, (unsigned int)D_800E18B4_eu + 0x80,
    0x00000209, (unsigned int)D_800E18B4_eu + 0x90, 0x0000020A, (unsigned int)D_800E18B4_eu + 0xA0, 0x0000020B, (unsigned int)D_800E18B4_eu + 0xB0, 0x0000020C, (unsigned int)D_800E18B4_eu + 0xC0,
    0x0000020D, (unsigned int)D_800E18B4_eu + 0xD0, 0x0000020E, (unsigned int)D_800E18B4_eu + 0xE0, 0x0000020F, (unsigned int)D_800E199A_eu + 0xA, 0x00000210, (unsigned int)D_800E19B2_eu + 0x2,
    0x00000211, (unsigned int)D_800E19B2_eu + 0x12, 0x00000212, (unsigned int)D_800E19B2_eu + 0x22, 0x00000213, (unsigned int)D_800E19DE_eu + 0x6, 0x00000214, (unsigned int)D_800E19E8_eu + 0xC,
    0x00000215, (unsigned int)D_800E19E8_eu + 0x1C, 0x00000216, (unsigned int)D_800E19E8_eu + 0x2C, 0x00000217, (unsigned int)D_800E19E8_eu + 0x3C, 0x00000218, (unsigned int)D_800E19E8_eu + 0x4C,
    0x00000219, (unsigned int)D_800E19E8_eu + 0x5C, 0x0000021A, (unsigned int)D_800E19E8_eu + 0x6C, 0x0000021B, (unsigned int)D_800E19E8_eu + 0x7C, 0x0000021C, (unsigned int)D_800E19E8_eu + 0x8C,
    0x0000021D, (unsigned int)D_800E19E8_eu + 0x9C, 0x0000021E, (unsigned int)D_800E19E8_eu + 0xAC, 0x0000021F, (unsigned int)D_800E1AA4_eu, 0x00000220, (unsigned int)D_800E1AB4_eu,
    0x00000221, (unsigned int)D_800E1AC0_eu + 0x4, 0x00000222, (unsigned int)D_800E1AC0_eu + 0x14, 0x00000223, (unsigned int)D_800E1AC0_eu + 0x24, 0x00000224, (unsigned int)D_800E1AC0_eu + 0x34,
    0x00000225, (unsigned int)D_800E1AC0_eu + 0x44, 0x00000226, (unsigned int)D_800E1AC0_eu + 0x54, 0x00000227, (unsigned int)D_800E1AC0_eu + 0x64, 0x00000228, (unsigned int)D_800E1AC0_eu + 0x74,
    0x00000229, (unsigned int)D_800E1AC0_eu + 0x84, 0x0000022A, (unsigned int)D_800E1AC0_eu + 0x94, 0x0000022B, (unsigned int)D_800E1B60_eu + 0x4, 0x0000022C, (unsigned int)D_800E1B60_eu + 0x14,
    0x0000022D, (unsigned int)D_800E1B7C_eu + 0x8, 0x0000022E, (unsigned int)D_800E1B7C_eu + 0x18, 0x0000022F, (unsigned int)D_800E1B7C_eu + 0x28, 0x00000230, (unsigned int)D_800E1B7C_eu + 0x38,
    0x00000231, (unsigned int)D_800E1B7C_eu + 0x48, 0x00000232, (unsigned int)D_800E1B7C_eu + 0x58, 0x00000E08, 0x00000010, 0x0041D574, 0x00000E07,
    0x00000010, 0x0041E01C, 0x0000000A, 0x00000010, 0x0041E244, 0x00000E0A, 0x00000010, 0x0041E110,
    0x00000E06, 0x00000010, 0x0041D280, 0x00000E03, 0x00000010, 0x0041DFEC, 0x00000002, 0x00000010,
    0x0041E2AC, 0x00000001, 0x00000010, 0x0041E2E4, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)D_800E1394 + 0x20, 0x00000001, (unsigned int)D_800E1474_eu + 0x60, 0x00000002, (unsigned int)D_800E1394 + 0x80,
    0x00000003, (unsigned int)D_800E1394 + 0xB0, 0x00000004, (unsigned int)D_800E1474_eu + 0x90, 0x00000005, (unsigned int)D_800E1394 + 0x50, 0x00000006, (unsigned int)D_800E1570_eu + 0x34,
    0x00000007, (unsigned int)D_800E1570_eu + 0x64, 0x00000008, (unsigned int)D_800E1570_eu + 0x4, 0x00000009, (unsigned int)D_800E1474_eu + 0x30, 0x0000000A, (unsigned int)D_800E1570_eu + 0x94,
    0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xC0, 0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xE0, 0xFFFFFFFF, (unsigned int)D_800E1564_eu, 0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xD0,
    0x00000011, (unsigned int)D_800E1570_eu + 0xC4, 0x00000012, (unsigned int)D_800E1474_eu, 0x00000000, (unsigned int)D_800E1394 + 0x30, 0x00000001, (unsigned int)D_800E1474_eu + 0x70,
    0x00000002, (unsigned int)D_800E1394 + 0x90, 0x00000003, (unsigned int)D_800E1454_eu, 0x00000004, (unsigned int)D_800E1474_eu + 0xA0, 0x00000005, (unsigned int)D_800E1394 + 0x60,
    0x00000006, (unsigned int)D_800E1570_eu + 0x44, 0x00000007, (unsigned int)D_800E1570_eu + 0x74, 0x00000008, (unsigned int)D_800E1570_eu + 0x14, 0x00000009, (unsigned int)D_800E1474_eu + 0x40,
    0x0000000A, (unsigned int)D_800E1570_eu + 0xA4, 0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xC0, 0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xE0, 0xFFFFFFFF, (unsigned int)D_800E1564_eu,
    0xFFFFFFFF, (unsigned int)D_800E1474_eu + 0xD0, 0x00000011, (unsigned int)D_800E1570_eu + 0xD4, 0x00000012, (unsigned int)D_800E1474_eu + 0x10, 0x00000000, (unsigned int)D_800E1394 + 0x40,
    0x00000001, (unsigned int)D_800E1474_eu + 0x80, 0x00000002, (unsigned int)D_800E1394 + 0xA0, 0x00000003, (unsigned int)D_800E1460_eu + 0x4, 0x00000004, (unsigned int)D_800E1474_eu + 0xB0,
    0x00000005, (unsigned int)D_800E1394 + 0x70, 0x00000006, (unsigned int)D_800E1570_eu + 0x54, 0x00000007, (unsigned int)D_800E1570_eu + 0x84, 0x00000008, (unsigned int)D_800E1570_eu + 0x24,
    0x00000009, (unsigned int)D_800E1474_eu + 0x50, 0x0000000A, (unsigned int)D_800E1570_eu + 0xB4, 0x0000000B, (unsigned int)D_800E1474_eu + 0xC0, 0x0000000C, (unsigned int)D_800E1474_eu + 0xE0,
    0x0000000D, (unsigned int)D_800E1564_eu, 0x0000000E, (unsigned int)D_800E1474_eu + 0xD0, 0x00000011, (unsigned int)D_800E1648_eu + 0xC, 0x00000012, (unsigned int)D_800E1474_eu + 0x20,
    (unsigned int)D_800E1B7C_eu + 0x68, (unsigned int)D_800E1B7C_eu + 0x78, (unsigned int)D_800E1B7C_eu + 0x88,
};
#endif
#if defined(VERSION_EU_X)
extern char D_800DD124[];
extern char D_800DD1A0_eu_x[];
extern char D_800DD1B0_eu_x[];
extern char D_800DD1B8_eu_x[];
extern char D_800DD1C8_eu_x[];
extern char D_800DD1DC_eu_x[];
extern char D_800DD1F0_eu_x[];
extern char D_800DD50C_eu_x[];
extern char D_800DD568_eu_x[];
extern char D_800DD570_eu_x[];
extern char D_800DD580_eu_x[];
extern char D_800DD588_eu_x[];
extern char D_800DD600_eu_x[];
extern char D_800DD610_eu_x[];
extern char D_800DD688_eu_x[];
extern char D_800DD690_eu_x[];
extern char D_800E1564_eu[];
extern char D_800E18B4_eu[];
unsigned int rodata_unresolved_800E3594[267] = {
    0x00000205, (unsigned int)D_800E18B4_eu + 0xC, 0x00000206, (unsigned int)D_800DD50C_eu_x + 0x8, 0x00000207, (unsigned int)D_800DD50C_eu_x + 0x14, 0x00000208, (unsigned int)D_800DD50C_eu_x + 0x20,
    0x00000209, (unsigned int)D_800DD50C_eu_x + 0x2C, 0x0000020A, (unsigned int)D_800DD50C_eu_x + 0x38, 0x0000020B, (unsigned int)D_800DD50C_eu_x + 0x44, 0x0000020C, (unsigned int)D_800DD50C_eu_x + 0x50,
    0x0000020D, (unsigned int)D_800DD568_eu_x, 0x0000020E, (unsigned int)D_800DD570_eu_x + 0x4, 0x0000020F, (unsigned int)D_800DD580_eu_x, 0x00000210, (unsigned int)D_800DD588_eu_x + 0x4,
    0x00000211, (unsigned int)D_800DD588_eu_x + 0x10, 0x00000212, (unsigned int)D_800DD588_eu_x + 0x1C, 0x00000213, (unsigned int)D_800DD588_eu_x + 0x28, 0x00000214, (unsigned int)D_800DD588_eu_x + 0x34,
    0x00000215, (unsigned int)D_800DD588_eu_x + 0x40, 0x00000216, (unsigned int)D_800DD588_eu_x + 0x4C, 0x00000217, (unsigned int)D_800DD588_eu_x + 0x58, 0x00000218, (unsigned int)D_800DD588_eu_x + 0x64,
    0x00000219, (unsigned int)D_800DD588_eu_x + 0x70, 0x0000021A, (unsigned int)D_800DD600_eu_x + 0x4, 0x0000021B, (unsigned int)D_800DD610_eu_x, 0x0000021C, (unsigned int)D_800DD610_eu_x + 0xC,
    0x0000021D, (unsigned int)D_800DD610_eu_x + 0x18, 0x0000021E, (unsigned int)D_800DD610_eu_x + 0x24, 0x0000021F, (unsigned int)D_800DD610_eu_x + 0x30, 0x00000220, (unsigned int)D_800DD610_eu_x + 0x3C,
    0x00000221, (unsigned int)D_800DD610_eu_x + 0x48, 0x00000222, (unsigned int)D_800DD610_eu_x + 0x54, 0x00000223, (unsigned int)D_800DD610_eu_x + 0x60, 0x00000224, (unsigned int)D_800DD610_eu_x + 0x6C,
    0x00000225, (unsigned int)D_800DD688_eu_x, 0x00000226, (unsigned int)D_800DD690_eu_x + 0x4, 0x00000227, (unsigned int)D_800DD690_eu_x + 0x10, 0x00000228, (unsigned int)D_800DD690_eu_x + 0x1C,
    0x00000229, (unsigned int)D_800DD690_eu_x + 0x28, 0x0000022A, (unsigned int)D_800DD690_eu_x + 0x34, 0x0000022B, (unsigned int)D_800DD690_eu_x + 0x40, 0x0000022C, (unsigned int)D_800DD690_eu_x + 0x4C,
    0x0000022D, (unsigned int)D_800DD690_eu_x + 0x58, 0x0000022E, (unsigned int)D_800DD690_eu_x + 0x64, 0x0000022F, (unsigned int)D_800DD690_eu_x + 0x70, 0x00000230, (unsigned int)D_800DD690_eu_x + 0x7C,
    0x00000231, (unsigned int)D_800DD690_eu_x + 0x88, 0x00000232, (unsigned int)D_800DD690_eu_x + 0x94, 0x00000233, (unsigned int)D_800DD690_eu_x + 0xA0, 0x00000234, (unsigned int)D_800DD690_eu_x + 0xAC,
    0x00000235, (unsigned int)D_800DD690_eu_x + 0xB8, 0x00000236, (unsigned int)D_800DD690_eu_x + 0xC4, 0x00000E08, 0x00000010, 0x0041D574, 0x00000E07,
    0x00000010, 0x0041E01C, 0x0000000A, 0x00000010, 0x0041E244, 0x00000E0A, 0x00000010, 0x0041E110,
    0x00000E06, 0x00000010, 0x0041D280, 0x00000E03, 0x00000010, 0x0041DFEC, 0x00000002, 0x00000010,
    0x0041E2AC, 0x00000001, 0x00000010, 0x0041E2E4, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)D_800DD124 + 0x18, 0x00000001, (unsigned int)D_800DD1F0_eu_x + 0x24, 0x00000002, (unsigned int)D_800DD124 + 0x60,
    0x00000003, (unsigned int)D_800DD1A0_eu_x + 0x8, 0x00000004, (unsigned int)D_800DD1F0_eu_x + 0x48, 0x00000005, (unsigned int)D_800DD124 + 0x3C, 0x00000006, (unsigned int)D_800E1564_eu + 0x30,
    0x00000007, (unsigned int)D_800E1564_eu + 0x54, 0x00000008, (unsigned int)D_800E1564_eu + 0xC, 0x00000009, (unsigned int)D_800DD1F0_eu_x, 0x0000000A, (unsigned int)D_800E1564_eu + 0x78,
    0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x6C, 0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x84, 0xFFFFFFFF, (unsigned int)D_800E1564_eu, 0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x78,
    0x00000011, (unsigned int)D_800E1564_eu + 0x9C, 0x00000012, (unsigned int)D_800DD1C8_eu_x + 0x4, 0x00000000, (unsigned int)D_800DD124 + 0x24, 0x00000001, (unsigned int)D_800DD1F0_eu_x + 0x30,
    0x00000002, (unsigned int)D_800DD124 + 0x6C, 0x00000003, (unsigned int)D_800DD1B0_eu_x + 0x4, 0x00000004, (unsigned int)D_800DD1F0_eu_x + 0x54, 0x00000005, (unsigned int)D_800DD124 + 0x48,
    0x00000006, (unsigned int)D_800E1564_eu + 0x3C, 0x00000007, (unsigned int)D_800E1564_eu + 0x60, 0x00000008, (unsigned int)D_800E1564_eu + 0x18, 0x00000009, (unsigned int)D_800DD1F0_eu_x + 0xC,
    0x0000000A, (unsigned int)D_800E1564_eu + 0x84, 0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x6C, 0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x84, 0xFFFFFFFF, (unsigned int)D_800E1564_eu,
    0xFFFFFFFF, (unsigned int)D_800DD1F0_eu_x + 0x78, 0x00000011, (unsigned int)D_800E1564_eu + 0xA8, 0x00000012, (unsigned int)D_800DD1C8_eu_x + 0x10, 0x00000000, (unsigned int)D_800DD124 + 0x30,
    0x00000001, (unsigned int)D_800DD1F0_eu_x + 0x3C, 0x00000002, (unsigned int)D_800DD124 + 0x78, 0x00000003, (unsigned int)D_800DD1B8_eu_x + 0x8, 0x00000004, (unsigned int)D_800DD1F0_eu_x + 0x60,
    0x00000005, (unsigned int)D_800DD124 + 0x54, 0x00000006, (unsigned int)D_800E1564_eu + 0x48, 0x00000007, (unsigned int)D_800E1564_eu + 0x6C, 0x00000008, (unsigned int)D_800E1564_eu + 0x24,
    0x00000009, (unsigned int)D_800DD1F0_eu_x + 0x18, 0x0000000A, (unsigned int)D_800E1564_eu + 0x90, 0x0000000B, (unsigned int)D_800DD1F0_eu_x + 0x6C, 0x0000000C, (unsigned int)D_800DD1F0_eu_x + 0x84,
    0x0000000D, (unsigned int)D_800E1564_eu, 0x0000000E, (unsigned int)D_800DD1F0_eu_x + 0x78, 0x00000011, (unsigned int)D_800E1564_eu + 0xB4, 0x00000012, (unsigned int)D_800DD1DC_eu_x + 0x8,
    (unsigned int)D_800DD690_eu_x + 0xD0, (unsigned int)D_800DD690_eu_x + 0xDC, (unsigned int)D_800DD690_eu_x + 0xE8,
};
#endif
#if defined(VERSION_US)
extern char D_800D3250[];
extern char D_800D32C4[];
extern char D_800D3398[];
unsigned int rodata_unresolved_800E3594[267] = {
    0x00000201, (unsigned int)D_800D3398 + 0x4, 0x00000202, (unsigned int)D_800D3398 + 0x8, 0x00000203, (unsigned int)D_800D3398 + 0xC, 0x00000204, (unsigned int)D_800D3398 + 0x10,
    0x00000205, (unsigned int)D_800D3398 + 0x14, 0x00000206, (unsigned int)D_800D3398 + 0x18, 0x00000207, (unsigned int)D_800D3398 + 0x1C, 0x00000208, (unsigned int)D_800D3398 + 0x20,
    0x00000209, (unsigned int)D_800D3398 + 0x24, 0x0000020A, (unsigned int)D_800D3398 + 0x28, 0x0000020B, (unsigned int)D_800D3398 + 0x2C, 0x0000020C, (unsigned int)D_800D3398 + 0x30,
    0x0000020D, (unsigned int)D_800D3398 + 0x34, 0x0000020E, (unsigned int)D_800D3398 + 0x38, 0x0000020F, (unsigned int)D_800D3398 + 0x3C, 0x00000210, (unsigned int)D_800D3398 + 0x40,
    0x00000211, (unsigned int)D_800D3398 + 0x44, 0x00000212, (unsigned int)D_800D3398 + 0x48, 0x00000213, (unsigned int)D_800D3398 + 0x4C, 0x00000214, (unsigned int)D_800D3398 + 0x50,
    0x00000215, (unsigned int)D_800D3398 + 0x54, 0x00000216, (unsigned int)D_800D3398 + 0x58, 0x00000217, (unsigned int)D_800D3398 + 0x5C, 0x00000218, (unsigned int)D_800D3398 + 0x60,
    0x00000219, (unsigned int)D_800D3398 + 0x64, 0x0000021A, (unsigned int)D_800D3398 + 0x68, 0x0000021B, (unsigned int)D_800D3398 + 0x6C, 0x0000021C, (unsigned int)D_800D3398 + 0x70,
    0x0000021D, (unsigned int)D_800D3398 + 0x74, 0x0000021E, (unsigned int)D_800D3398 + 0x78, 0x0000021F, (unsigned int)D_800D3398 + 0x7C, 0x00000220, (unsigned int)D_800D3398 + 0x80,
    0x00000221, (unsigned int)D_800D3398 + 0x84, 0x00000222, (unsigned int)D_800D3398 + 0x88, 0x00000223, (unsigned int)D_800D3398 + 0x8C, 0x00000224, (unsigned int)D_800D3398 + 0x90,
    0x00000225, (unsigned int)D_800D3398 + 0x94, 0x00000226, (unsigned int)D_800D3398 + 0x98, 0x00000227, (unsigned int)D_800D3398 + 0x9C, 0x00000228, (unsigned int)D_800D3398 + 0xA0,
    0x00000229, (unsigned int)D_800D3398 + 0xA4, 0x0000022A, (unsigned int)D_800D3398 + 0xA8, 0x0000022B, (unsigned int)D_800D3398 + 0xAC, 0x0000022C, (unsigned int)D_800D3398 + 0xB0,
    0x0000022D, (unsigned int)D_800D3398 + 0xB4, 0x0000022E, (unsigned int)D_800D3398 + 0xB8, 0x0000022F, (unsigned int)D_800D3398 + 0xBC, 0x00000230, (unsigned int)D_800D3398 + 0xC0,
    0x00000231, (unsigned int)D_800D3398 + 0xC4, 0x00000232, (unsigned int)D_800D3398 + 0xC8, 0x00000E08, 0x00000010, 0x0041D1A4, 0x00000E07,
    0x00000010, 0x0041DC3C, 0x0000000A, 0x00000010, 0x0041DE64, 0x00000E0A, 0x00000010, 0x0041DD30,
    0x00000E06, 0x00000010, 0x0041CEB0, 0x00000E03, 0x00000010, 0x0041DC0C, 0x00000002, 0x00000010,
    0x0041DECC, 0x00000001, 0x00000010, 0x0041DF04, 0x00000000, 0x00000000, 0x00000000, 0x00000063,
    0x0000002E, 0x00000062, 0x0000002F, 0x00000061, 0x00000029, 0x0000005F, 0x0000002A, 0x00000060,
    0x00000030, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x00000005, 0x0000000F,
    0x00000014, 0x0000001E, 0x00000023, 0x0000000A, 0x00000014, 0x0000001E, 0x00000028, 0x00000032,
    0x0000000A, 0x0000001E, 0x0000002D, 0x0000003C, 0x0000004B, 0x00000014, 0x00000028, 0x0000003C,
    0x00000050, 0x00000064, 0x00000000, (unsigned int)D_800D3250 + 0x8, 0x00000001, (unsigned int)D_800D3250 + 0x50, 0x00000002, (unsigned int)D_800D3250 + 0x20,
    0x00000003, (unsigned int)D_800D3250 + 0x2C, 0x00000004, (unsigned int)D_800D3250 + 0x5C, 0x00000005, (unsigned int)D_800D3250 + 0x14, 0x00000006, (unsigned int)D_800D32C4 + 0x10,
    0x00000007, (unsigned int)D_800D32C4 + 0x1C, 0x00000008, (unsigned int)D_800D32C4 + 0x4, 0x00000009, (unsigned int)D_800D3250 + 0x44, 0x0000000A, (unsigned int)D_800D32C4 + 0x28,
    0xFFFFFFFF, (unsigned int)D_800D3250 + 0x68, 0xFFFFFFFF, (unsigned int)D_800D3250 + 0x70, 0xFFFFFFFF, (unsigned int)D_800D32C4, 0xFFFFFFFF, (unsigned int)D_800D3250 + 0x6C,
    0x00000011, (unsigned int)D_800D32C4 + 0x34, 0x00000012, (unsigned int)D_800D3250 + 0x38, 0x00000000, (unsigned int)D_800D3250 + 0xC, 0x00000001, (unsigned int)D_800D3250 + 0x54,
    0x00000002, (unsigned int)D_800D3250 + 0x24, 0x00000003, (unsigned int)D_800D3250 + 0x30, 0x00000004, (unsigned int)D_800D3250 + 0x60, 0x00000005, (unsigned int)D_800D3250 + 0x18,
    0x00000006, (unsigned int)D_800D32C4 + 0x14, 0x00000007, (unsigned int)D_800D32C4 + 0x20, 0x00000008, (unsigned int)D_800D32C4 + 0x8, 0x00000009, (unsigned int)D_800D3250 + 0x48,
    0x0000000A, (unsigned int)D_800D32C4 + 0x2C, 0xFFFFFFFF, (unsigned int)D_800D3250 + 0x68, 0xFFFFFFFF, (unsigned int)D_800D3250 + 0x70, 0xFFFFFFFF, (unsigned int)D_800D32C4,
    0xFFFFFFFF, (unsigned int)D_800D3250 + 0x6C, 0x00000011, (unsigned int)D_800D32C4 + 0x38, 0x00000012, (unsigned int)D_800D3250 + 0x3C, 0x00000000, (unsigned int)D_800D3250 + 0x10,
    0x00000001, (unsigned int)D_800D3250 + 0x58, 0x00000002, (unsigned int)D_800D3250 + 0x28, 0x00000003, (unsigned int)D_800D3250 + 0x34, 0x00000004, (unsigned int)D_800D3250 + 0x64,
    0x00000005, (unsigned int)D_800D3250 + 0x1C, 0x00000006, (unsigned int)D_800D32C4 + 0x18, 0x00000007, (unsigned int)D_800D32C4 + 0x24, 0x00000008, (unsigned int)D_800D32C4 + 0xC,
    0x00000009, (unsigned int)D_800D3250 + 0x4C, 0x0000000A, (unsigned int)D_800D32C4 + 0x30, 0x0000000B, (unsigned int)D_800D3250 + 0x68, 0x0000000C, (unsigned int)D_800D3250 + 0x70,
    0x0000000D, (unsigned int)D_800D32C4, 0x0000000E, (unsigned int)D_800D3250 + 0x6C, 0x00000011, (unsigned int)D_800D32C4 + 0x3C, 0x00000012, (unsigned int)D_800D3250 + 0x40,
    (unsigned int)D_800D3398 + 0xCC, (unsigned int)D_800D3398 + 0xD0, (unsigned int)D_800D3398 + 0xD4,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_d80c6f4f8673eac5ccd3[100] = {
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
