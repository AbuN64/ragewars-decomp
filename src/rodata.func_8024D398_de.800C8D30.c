/* Switch jump table for func_8024D398: fifteen code-relative branch addresses 0x8024D3B0 through
   0x8024D490 on the us-rev1 cartridge. eu and the us cartridge branch elsewhere and keep their
   own tables. */
#if defined(VERSION_DE)
unsigned int D_auto_rodata_func_8024D398_de_800C8D30[15] = {
    0x0024D410, 0x0024D420, 0x0024D430, 0x0024D4A0, 0x0024D420, 0x0024D410, 0x0024D4A0, 0x0024D490,
    0x0024D410, 0x0024D4A0, 0x0024D410, 0x0024D3C0, 0x0024D410, 0x0024D410, 0x0024D410,
};
#elif defined(VERSION_EU_X)
unsigned int D_auto_rodata_func_8024D398_de_800C8D30[15] = {
    0x0024D450, 0x0024D460, 0x0024D470, 0x0024D4E0, 0x0024D460, 0x0024D450, 0x0024D4E0, 0x0024D4D0,
    0x0024D450, 0x0024D4E0, 0x0024D450, 0x0024D400, 0x0024D450, 0x0024D450, 0x0024D450,
};
#elif defined(VERSION_US_REV1)
unsigned int D_auto_rodata_func_8024D398_de_800C8D30[15] = {
    0x0024D400, 0x0024D410, 0x0024D420, 0x0024D490, 0x0024D410, 0x0024D400, 0x0024D490, 0x0024D480,
    0x0024D400, 0x0024D490, 0x0024D400, 0x0024D3B0, 0x0024D400, 0x0024D400, 0x0024D400,
};
#endif
