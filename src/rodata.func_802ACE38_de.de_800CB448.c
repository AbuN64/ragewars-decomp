/* class: switch jump table (8 entries: 4 low branches + 3 shared default + 1 tail) of the us-rev1 copy of the 802ACE38 switch
 * semantic proposal: RwSwitchTableFunc802ACE38_us_rev1
 * member=rodata/func_802ACE38_de/800CB448 rom=0xCC048(us-rev1)+32B vram=0x800CB448 sect=rodata seg=span_C76B0 status=open symbol=D_auto_rodata_func_802ACE38_de_800CB448(legacy-src)
 * cart rows: us-rev1 0xCC048->0xCC068 = 32 B (8 words) — drafted. de row 0xC6EB8->0xC6EE0 = 40 B needs 10 words but the legacy draft (src/rodata.func_802ACE38_de.800CB448.c) supplies only 8 de entries — do NOT pad; withhold de honestly. eu/eu-x/us hold no row. Branch targets 0x802ADE80..0x802ADEB4 sit inside func_802ACE38 us-rev1 span (0xCC068 tail row follows). Values verbatim with VERSION_US_REV -> VERSION_US_REV1 fixed. */
#if defined(VERSION_US_REV1)
const unsigned int D_auto_rodata_func_802ACE38_de_800CB448[8] = {
    0x002ADE80, 0x002ADE90, 0x002ADEA0, 0x002ADEA0, 0x002ADEEC, 0x002ADEEC, 0x002ADEEC, 0x002ADEB4,
};
#endif
