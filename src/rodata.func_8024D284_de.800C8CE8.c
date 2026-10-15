/* Switch jump table for func_8024D284: fifteen code-relative branch addresses in that function's
   span. The table follows the function's code, so its offsets differ per cartridge. eu and the us
   cartridge branch elsewhere and keep their own tables. */
#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8024D284_de_800C8CE8[15] = {
    0x0024D378, 0x0024D320, 0x0024D388, 0x0024D388, 0x0024D320, 0x0024D378, 0x0024D368, 0x0024D358,
    0x0024D330, 0x0024D388, 0x0024D378, 0x0024D2E0, 0x0024D378, 0x0024D378, 0x0024D378,
};
#elif defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8024D284_de_800C8CE8[15] = {
    0x0024D3B8, 0x0024D360, 0x0024D3C8, 0x0024D3C8, 0x0024D360, 0x0024D3B8, 0x0024D3A8, 0x0024D398,
    0x0024D370, 0x0024D3C8, 0x0024D3B8, 0x0024D320, 0x0024D3B8, 0x0024D3B8, 0x0024D3B8,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_8024D284_de_800C8CE8[15] = {
    0x0024D368, 0x0024D310, 0x0024D378, 0x0024D378, 0x0024D310, 0x0024D368, 0x0024D358, 0x0024D348,
    0x0024D320, 0x0024D378, 0x0024D368, 0x0024D2D0, 0x0024D368, 0x0024D368, 0x0024D368,
};
#endif
