#include "include_asm.h"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* class: switch jump table (13 branch offsets 0x8024D1C8..0x8024D2B8 eu-x / 0x8024D178..0x8024D268 us-rev1), sibling of landed 800C8CE8/800C8D30 pair
 * semantic proposal: RwSwitchTableFunc8024D160_de
 * member=rodata/func_8024D160_de/800C8CB0 rom=0xC4AB0(eu-x)+52B rom=0xC98B0(us-rev1)+52B vram=0x800C8CB0 sect=rodata seg=span_C76B0 status=open symbol=D_auto_rodata_func_8024D160_de_800C8CB0(legacy-src)
 * cart rows: eu-x 0xC4AB0->0xC4AE4 = 52 B; us-rev1 0xC98B0->0xC98E4 = 52 B. de/eu/us hold no row (guard branches omitted); parent withholds them. Values verbatim from src/rodata.func_8024D160_de.800C8CB0.c with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_EU_X)
const unsigned int D_auto_rodata_func_8024D160_de_800C8CB0[13] = {
    0x0024D210, 0x0024D23C, 0x0024D220, 0x0024D2B8, 0x0024D278, 0x0024D278, 0x0024D2B8, 0x0024D278,
    0x0024D208, 0x0024D2B8, 0x0024D278, 0x0024D1C8, 0x0024D2A8,
};
#elif defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_8024D160_de_800C8CB0[13] = {
    0x0024D1C0, 0x0024D1EC, 0x0024D1D0, 0x0024D268, 0x0024D228, 0x0024D228, 0x0024D268, 0x0024D228,
    0x0024D1B8, 0x0024D268, 0x0024D228, 0x0024D178, 0x0024D258,
};
#endif
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EE4);
#endif
