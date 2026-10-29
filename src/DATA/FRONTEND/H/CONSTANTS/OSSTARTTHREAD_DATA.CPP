
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#ifdef VERSION_DE
unsigned int k_OsstartthreadEncodedWords[6] = {
    0x800D5260, 0x800D5260, 0x00000000, 0x00000000, 0x3F733333, 0x41800000,
};
#endif
#ifdef VERSION_EU_X
extern char g_emptyThreadQueue[];
void *k_OsstartthreadEncodedWords[6] = {
    g_emptyThreadQueue, g_emptyThreadQueue, 0, 0,
    0, 0,
};
#endif
#ifdef VERSION_EU
unsigned int k_OsstartthreadEncodedWords[6] = {
    0x800E58E0, 0x800E58E0, 0x00000000, 0x00000000, 0x800C6C5C, 0x800C65A0,
};
#endif
#endif
