
/* ROM-grounded data: rodata/writable/800E2AB0 */
#ifdef VERSION_DE
extern char g_node_SelectPreviousGridRowEntry[];
unsigned int g_NodeSetdisplayclipboundsPointerWords1[8] = {
    0x00000001, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, (unsigned int)g_node_SelectPreviousGridRowEntry, 0x00000006,
};
#endif
#ifdef VERSION_EU
unsigned int g_NodeSetdisplayclipboundsPointerWords1[8] = {
    0x00000001, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned int g_NodeSetdisplayclipboundsPointerWords1[8] = {
    0x00000001, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000016, 0x3DE147AE,
};
#endif
#ifdef VERSION_US
unsigned int g_NodeSetdisplayclipboundsPointerWords1[8] = {
    0x00000001, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x4E545F53, 0x4D414C4C,
};
#endif
