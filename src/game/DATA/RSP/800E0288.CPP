
#if defined(VERSION_DE)
extern char D_0041F230[];
extern char D_0041F6C8[];
extern char D_0041FC50[];
extern char D_00420B10[];
extern char D_00420B50[];
extern char D_00420B78[];
extern char D_00420BF0[];
extern char D_00420BF8[];
extern char D_00420C00[];
extern char D_00420C08[];
extern char D_00420C10[];
extern char D_00420CDC[];
/* Widget IDs occupy the second halfword; kind and event fields remain words. */
struct {
    unsigned short firstRowWidgets[8][2];
    struct {
        unsigned int kind;
        unsigned short widgets[8][2];
    } rows[3];
    unsigned int events[39];
} D_auto_data_unresolved_800E0288 = {
    { { 0, 0x007D }, { 0, 0x00C4 }, { 0, 0x00AB }, { 0, 0x00AD }, { 0, 0x00AF }, { 0, 0x00C2 }, { 0, 0x00C1 }, { 0, 0x00C0 } },
    {
        { 0x00000084, { { 0, 0x007C }, { 0, 0x00A7 }, { 0, 0x0092 }, { 0, 0x0094 }, { 0, 0x0096 }, { 0, 0x00A6 }, { 0, 0x00A5 }, { 0, 0x00A4 } } },
        { 0x0000008B, { { 0, 0x007A }, { 0, 0x00C5 }, { 0, 0x00B1 }, { 0, 0x00B3 }, { 0, 0x00B5 }, { 0, 0x00B7 }, { 0, 0x00B8 }, { 0, 0x00B9 } } },
        { 0x0000008A, { { 0, 0x007B }, { 0, 0x00A8 }, { 0, 0x009A }, { 0, 0x0099 }, { 0, 0x0098 }, { 0, 0x009C }, { 0, 0x009D }, { 0, 0x009B } } },
    },
    {
        0x00000E07, 0x00000007, (unsigned int)D_00420B50,
        0x00000E08, 0x00000007, (unsigned int)D_0041F6C8,
        0x0000000A, 0x00000007, (unsigned int)D_00420B78,
        0x00000E0A, 0x00000007, (unsigned int)D_0041FC50,
        0x00000E06, 0x00000007, (unsigned int)D_0041F230,
        0x00000E03, 0x00000007, (unsigned int)D_00420B10,
        0x00000002, 0x00000007, (unsigned int)D_00420C10,
        0x00000001, 0x00000007, (unsigned int)D_00420CDC,
        0x00000008, 0x00000007, (unsigned int)D_00420BF0,
        0x00000007, 0x00000007, (unsigned int)D_00420BF8,
        0x00000005, 0x00000007, (unsigned int)D_00420C00,
        0x00000006, 0x00000007, (unsigned int)D_00420C08,
        0x00000000, 0x00000000, 0x00000000,
    },
};
#endif
