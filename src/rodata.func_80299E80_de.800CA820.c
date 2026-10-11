/* class: switch jump table (9 entries: 5 monotonic cases + 3 shared default + 2 early cases)
 * semantic proposal: RwSwitchTableFunc80299E80_de
 * member=rodata/func_80299E80_de/800CA820 rom=0xC6290(de)+36B rom=0xC6570(eu-x)+36B rom=0xCB420(us-rev1)+36B vram=0x800CA820 sect=rodata seg=span_C76B0 status=open symbol=D_auto_rodata_func_80299E80_de_800CA820(legacy-src)
 * cart rows: de 0xC6290->0xC62B4 = 36 B; eu-x 0xC6570->0xC6594 = 36 B; us-rev1 0xCB420->0xCB444 = 36 B. eu/us hold no row; parent withholds. Branch targets lie inside landed sibling funcs 0x80299EF8..0x8029A1F4 (de), 0x8029A048..0x8029A344 (eu-x), 0x8029AEF8..0x8029B1F4 (us-rev1). Values verbatim from src/rodata.func_80299E80_de.800CA820.c with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_80299E80_de_800CA820[9] = {
    0x00299FD8, 0x0029A05C, 0x0029A0E0, 0x0029A164, 0x0029A1F4, 0x0029A1F4, 0x0029A1F4, 0x00299EF8,
    0x00299F68,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_80299E80_de_800CA820[9] = {
    0x0029A128, 0x0029A1AC, 0x0029A230, 0x0029A2B4, 0x0029A344, 0x0029A344, 0x0029A344, 0x0029A048,
    0x0029A0B8,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_80299E80_de_800CA820[9] = {
    0x0029AFD8, 0x0029B05C, 0x0029B0E0, 0x0029B164, 0x0029B1F4, 0x0029B1F4, 0x0029B1F4, 0x0029AEF8,
    0x0029AF68,
};
#endif
