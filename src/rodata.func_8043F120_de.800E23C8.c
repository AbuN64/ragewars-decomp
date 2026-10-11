/* class: switch jump table (9 entries: 2 low cases + shared default 0x8043F1A8 x3 + 4 high cases) of the 8043F120 jump switch; feeds landed rw_pool_8043F120_E2FF0 row
 * semantic proposal: RwSwitchTableFunc8043F120_de
 * member=rodata/func_8043F120_de/800E23C8 rom=0xDEF98(de)+36B rom=0xEA7D8(eu-x)+36B rom=0xE2FC8(us-rev1)+36B vram=0x800E23C8 sect=rodata seg=span_E1720 status=open symbol=D_auto_rodata_func_8043F120_de_800E23C8(legacy-src)
 * cart rows: de 0xDEF98->0xDEFBC = 36 B; eu-x 0xEA7D8->0xEA7FC = 36 B; us-rev1 0xE2FC8->0xE2FEC = 36 B. eu/us hold no row; parent withholds. Values verbatim from src/rodata.func_8043F120_de.800E23C8.c with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8043F120_de_800E23C8[9] = {
    0x0043F174, 0x0043F1A8, 0x0043F1A8, 0x0043F180, 0x0043F194, 0x0043F1A8, 0x0043F1B8, 0x0043F1CC,
    0x0043F1E0,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8043F120_de_800E23C8[9] = {
    0x00440144, 0x00440178, 0x00440178, 0x00440150, 0x00440164, 0x00440178, 0x00440188, 0x0044019C,
    0x004401B0,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_8043F120_de_800E23C8[9] = {
    0x0043F2E4, 0x0043F318, 0x0043F318, 0x0043F2F0, 0x0043F304, 0x0043F318, 0x0043F328, 0x0043F33C,
    0x0043F350,
};
#endif
