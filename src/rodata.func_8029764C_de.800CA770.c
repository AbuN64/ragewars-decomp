/* Switch jump table for func_8029764C: sixteen code-relative branch addresses 0x80298930 through
   0x802989DC on the us-rev1 cartridge. eu and the two us cartridges branch elsewhere and keep
   their own tables. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8029764C_de_800CA770[16] = {
    0x00297950, 0x00297988, 0x002979DC, 0x002979DC, 0x00297930, 0x00297930, 0x00297930, 0x00297930,
    0x002979DC, 0x002979DC, 0x002979DC, 0x002979DC, 0x002979DC, 0x002979DC, 0x002979AC, 0x002979C4,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8029764C_de_800CA770[16] = {
    0x00297AA0, 0x00297AD8, 0x00297B2C, 0x00297B2C, 0x00297A80, 0x00297A80, 0x00297A80, 0x00297A80,
    0x00297B2C, 0x00297B2C, 0x00297B2C, 0x00297B2C, 0x00297B2C, 0x00297B2C, 0x00297AFC, 0x00297B14,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_8029764C_de_800CA770[16] = {
    0x00298950, 0x00298988, 0x002989DC, 0x002989DC, 0x00298930, 0x00298930, 0x00298930, 0x00298930,
    0x002989DC, 0x002989DC, 0x002989DC, 0x002989DC, 0x002989DC, 0x002989DC, 0x002989AC, 0x002989C4,
};
#endif
