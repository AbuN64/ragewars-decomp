
#if defined(VERSION_EU)
extern char D_0041F6E0[];
extern char D_0041FB78[];
extern char D_00420100[];
extern char D_00420FC0[];
extern char D_00421000[];
extern char D_00421028[];
extern char D_004210A0[];
extern char D_004210A8[];
extern char D_004210B0[];
extern char D_004210B8[];
extern char D_004210C0[];
extern char D_0042118C[];
/* Widget IDs occupy the second halfword; kind and event fields remain words. */
struct {
    unsigned short firstRowWidgets[8][2];
    struct {
        unsigned int kind;
        unsigned short widgets[8][2];
    } rows[3];
    unsigned int events[39];
} D_auto_data_unresolved_800F08F8 = {
    { { 0, 0x007F }, { 0, 0x00C6 }, { 0, 0x00AD }, { 0, 0x00AF }, { 0, 0x00B1 }, { 0, 0x00C4 }, { 0, 0x00C3 }, { 0, 0x00C2 } },
    {
        { 0x00000086, { { 0, 0x007E }, { 0, 0x00A9 }, { 0, 0x0094 }, { 0, 0x0096 }, { 0, 0x0098 }, { 0, 0x00A8 }, { 0, 0x00A7 }, { 0, 0x00A6 } } },
        { 0x0000008D, { { 0, 0x007C }, { 0, 0x00C7 }, { 0, 0x00B3 }, { 0, 0x00B5 }, { 0, 0x00B7 }, { 0, 0x00B9 }, { 0, 0x00BA }, { 0, 0x00BB } } },
        { 0x0000008C, { { 0, 0x007D }, { 0, 0x00AA }, { 0, 0x009C }, { 0, 0x009B }, { 0, 0x009A }, { 0, 0x009E }, { 0, 0x009F }, { 0, 0x009D } } },
    },
    {
        0x00000E07, 0x00000007, (unsigned int)D_00421000,
        0x00000E08, 0x00000007, (unsigned int)D_0041FB78,
        0x0000000A, 0x00000007, (unsigned int)D_00421028,
        0x00000E0A, 0x00000007, (unsigned int)D_00420100,
        0x00000E06, 0x00000007, (unsigned int)D_0041F6E0,
        0x00000E03, 0x00000007, (unsigned int)D_00420FC0,
        0x00000002, 0x00000007, (unsigned int)D_004210C0,
        0x00000001, 0x00000007, (unsigned int)D_0042118C,
        0x00000008, 0x00000007, (unsigned int)D_004210A0,
        0x00000007, 0x00000007, (unsigned int)D_004210A8,
        0x00000005, 0x00000007, (unsigned int)D_004210B0,
        0x00000006, 0x00000007, (unsigned int)D_004210B8,
        0x00000000, 0x00000000, 0x00000000,
    },
};
#endif
