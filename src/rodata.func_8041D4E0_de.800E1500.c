/* class: monotonic jump table (14 branch offsets, stride 8: 0x8041D5AC..0x8041D614 de / 0x8041D9EC..0x8041DA54 eu-x / 0x8041D61C..0x8041D684 us-rev1) — case table of the 8041D4E0 jump switch; feeds landed rw_text_8041D6A8 pool row
 * semantic proposal: RwJumpTableFunc8041D4E0_de
 * member=rodata/func_8041D4E0_de/800E1500 rom=0xDE0D0(de)+56B rom=0xE9910(eu-x)+56B rom=0xE2100(us-rev1)+56B vram=0x800E1500 sect=rodata seg=span_E1720 status=open symbol=D_auto_rodata_func_8041D4E0_de_800E1500(legacy-src)
 * cart rows: de 0xDE0D0->0xDE108 = 56 B; eu-x 0xE9910->0xE9948 = 56 B; us-rev1 0xE2100->0xE2138 = 56 B. eu/us hold no row; parent withholds. Values verbatim from src/rodata.func_8041D4E0_de.800E1500.c with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8041D4E0_de_800E1500[14] = {
    0x0041D5AC, 0x0041D5B4, 0x0041D5BC, 0x0041D5C4, 0x0041D5CC, 0x0041D5D4, 0x0041D5DC, 0x0041D5E4,
    0x0041D5EC, 0x0041D5F4, 0x0041D5FC, 0x0041D604, 0x0041D60C, 0x0041D614,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8041D4E0_de_800E1500[14] = {
    0x0041D9EC, 0x0041D9F4, 0x0041D9FC, 0x0041DA04, 0x0041DA0C, 0x0041DA14, 0x0041DA1C, 0x0041DA24,
    0x0041DA2C, 0x0041DA34, 0x0041DA3C, 0x0041DA44, 0x0041DA4C, 0x0041DA54,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_8041D4E0_de_800E1500[14] = {
    0x0041D61C, 0x0041D624, 0x0041D62C, 0x0041D634, 0x0041D63C, 0x0041D644, 0x0041D64C, 0x0041D654,
    0x0041D65C, 0x0041D664, 0x0041D66C, 0x0041D674, 0x0041D67C, 0x0041D684,
};
#endif
