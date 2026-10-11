/* class: monotonic jump table (10 branch offsets, stride 20: 0x804215EC..0x804216A0 de+us pairs / 0x80421B24..0x80421BD8 eu+eu-x / 0x8042165C..0x80421710 us+us-rev1) — jump switch of func_80421568; sits between landed neighbors func_804213DC_de/800E15C0 and func_80421CE8_de/800E1610 rows
 * semantic proposal: RwJumpTableFunc80421568_de
 * member=rodata/func_80421568_de/800E15E8 rom=0xDE1B8(de)+40B rom=0xEE838(eu)+40B rom=0xE99F8(eu-x)+40B rom=0xDCE68(us)+40B rom=0xE21E8(us-rev1)+40B vram=0x800E15E8 sect=rodata seg=span_E1720 status=open symbol=D_auto_rodata_func_80421568_de_800E15E8(legacy-src)
 * cart rows: de 0xDE1B8->0xDE1E0 = 40 B; eu 0xEE838->0xEE860 = 40 B; eu-x 0xE99F8->0xE9A20 = 40 B; us 0xDCE68->0xDCE90 = 40 B; us-rev1 0xE21E8->0xE2210 = 40 B. Exact candidate in all five (eu==eu-x and us==us-rev1 values are identical in the legacy draft). Values verbatim from src/rodata.func_80421568_de.800E15E8.c with VERSION_US_REV -> VERSION_US_REV1 fixed and guard order normalized to DE/EU/EU_X/US/US_REV1. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_80421568_de_800E15E8[10] = {
    0x004215EC, 0x00421600, 0x00421614, 0x00421628, 0x0042163C, 0x00421650, 0x00421664, 0x00421678,
    0x0042168C, 0x004216A0,
};
#elif defined(VERSION_EU)
const unsigned int D_auto_rodata_func_80421568_de_800E15E8[10] = {
    0x00421B24, 0x00421B38, 0x00421B4C, 0x00421B60, 0x00421B74, 0x00421B88, 0x00421B9C, 0x00421BB0,
    0x00421BC4, 0x00421BD8,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_80421568_de_800E15E8[10] = {
    0x00421B24, 0x00421B38, 0x00421B4C, 0x00421B60, 0x00421B74, 0x00421B88, 0x00421B9C, 0x00421BB0,
    0x00421BC4, 0x00421BD8,
};
#elif defined(VERSION_US)
const unsigned int D_auto_rodata_func_80421568_de_800E15E8[10] = {
    0x0042165C, 0x00421670, 0x00421684, 0x00421698, 0x004216AC, 0x004216C0, 0x004216D4, 0x004216E8,
    0x004216FC, 0x00421710,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_80421568_de_800E15E8[10] = {
    0x0042165C, 0x00421670, 0x00421684, 0x00421698, 0x004216AC, 0x004216C0, 0x004216D4, 0x004216E8,
    0x004216FC, 0x00421710,
};
#endif
