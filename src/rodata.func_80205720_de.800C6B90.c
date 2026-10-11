/* class: switch jump table (10 entries: 9 default branches + one case offset); feeds landed rw_pool_80205F18/80206080 pool rows
 * semantic proposal: RwSwitchTableFunc80205720_de
 * member=rodata/func_80205720_de/800C6B90 rom=0xC26A0(de)+40B rom=0xC2980(eu-x)+40B rom=0xC7790(us-rev1)+40B vram=0x800C6B90 sect=rodata seg=span_C76B0 status=open symbol=D_auto_rodata_func_80205720_de_800C6B90(legacy-src)
 * cart rows: de 0xC26A0->0xC26C8 = 40 B; eu-x 0xC2980->0xC29A8 = 40 B; us-rev1 0xC7790->0xC77B8 = 40 B. eu/us hold no row; parent withholds. Values verbatim from src/rodata.func_80205720_de.800C6B90.c with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_80205720_de_800C6B90[10] = {
    0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x0020581C,
    0x00205940, 0x00205940,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_80205720_de_800C6B90[10] = {
    0x00205960, 0x00205960, 0x00205960, 0x00205960, 0x00205960, 0x00205960, 0x00205960, 0x0020583C,
    0x00205960, 0x00205960,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_80205720_de_800C6B90[10] = {
    0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x00205940, 0x0020581C,
    0x00205940, 0x00205940,
};
#endif
