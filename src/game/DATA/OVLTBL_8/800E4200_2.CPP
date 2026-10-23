
/* Selection state pointer followed by the first layout row's word-sized kind. */
unsigned int g_selectionStateAndFirstKind[] = {
    0x00000000,
#if defined(VERSION_DE)
    0x0090,
#endif
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    0x0092,
#endif
#if defined(VERSION_EU_X)
    0x0096,
#endif
};
