/* Switch jump table for func_80297310: sixteen code-relative branch addresses in that function's
   span. The table follows the function's code, so its offsets differ per cartridge. eu and the two
   us cartridges branch elsewhere and keep their own tables. */
#if defined(VERSION_DE)
unsigned int D_auto_rodata_func_80297310_de_800CA730[16] = {
    0x00297588, 0x002975C0, 0x00297614, 0x00297614, 0x00297568, 0x00297568, 0x00297568, 0x00297568,
    0x00297614, 0x00297614, 0x00297614, 0x00297614, 0x00297614, 0x00297614, 0x002975E4, 0x002975FC,
};
#elif defined(VERSION_EU_X)
unsigned int D_auto_rodata_func_80297310_de_800CA730[16] = {
    0x002976D8, 0x00297710, 0x00297764, 0x00297764, 0x002976B8, 0x002976B8, 0x002976B8, 0x002976B8,
    0x00297764, 0x00297764, 0x00297764, 0x00297764, 0x00297764, 0x00297764, 0x00297734, 0x0029774C,
};
#elif defined(VERSION_US_REV1)
unsigned int D_auto_rodata_func_80297310_de_800CA730[16] = {
    0x00298588, 0x002985C0, 0x00298614, 0x00298614, 0x00298568, 0x00298568, 0x00298568, 0x00298568,
    0x00298614, 0x00298614, 0x00298614, 0x00298614, 0x00298614, 0x00298614, 0x002985E4, 0x002985FC,
};
#endif
