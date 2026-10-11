/* Switch jump table for func_80297A34: sixteen code-relative branch addresses in that function's
   span. The table follows the function's code, so its offsets differ per cartridge. */
#if defined(VERSION_EU)
unsigned int D_auto_rodata_func_80297A34_de_800CA7B0[16] = {
    0x00297E14, 0x00297E4C, 0x00297EA0, 0x00297EA0, 0x00297DF8, 0x00297DF8, 0x00297DF8, 0x00297DF8,
    0x00297EA0, 0x00297EA0, 0x00297EA0, 0x00297EA0, 0x00297EA0, 0x00297EA0, 0x00297E70, 0x00297E88,
};
#elif defined(VERSION_US)
unsigned int D_auto_rodata_func_80297A34_de_800CA7B0[16] = {
    0x00297C34, 0x00297C6C, 0x00297CC0, 0x00297CC0, 0x00297C18, 0x00297C18, 0x00297C18, 0x00297C18,
    0x00297CC0, 0x00297CC0, 0x00297CC0, 0x00297CC0, 0x00297CC0, 0x00297CC0, 0x00297C90, 0x00297CA8,
};
#elif defined(VERSION_US_REV1)
unsigned int D_auto_rodata_func_80297A34_de_800CA7B0[16] = {
    0x00298CF4, 0x00298D2C, 0x00298D80, 0x00298D80, 0x00298CD8, 0x00298CD8, 0x00298CD8, 0x00298CD8,
    0x00298D80, 0x00298D80, 0x00298D80, 0x00298D80, 0x00298D80, 0x00298D80, 0x00298D50, 0x00298D68,
};
#endif
