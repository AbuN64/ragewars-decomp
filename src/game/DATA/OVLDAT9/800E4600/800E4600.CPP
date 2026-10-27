#include "include_asm.h"
#include "DATA/OVLDAT9/800E4604.H"

/* 800E4600.CPP */
/* ROM-grounded data: rodata/writable/800E4600 */
unsigned int D_blob_phase2_d8bb1fe655b30610c415[1] = {
    0x00000000,
};

/* 800E4604.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char D_800D34B8[];
extern char D_800D34BC[];
extern char D_800D34C0_de[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x004241BC, 0x00000E06, 0x00000003, 0x00423A40, 0x00000E03, 0x00000003,
    0x0042418C, 0x00000002, 0x00000003, 0x00424328, 0x00000001, 0x00000003, 0x00423F48, 0x0000000A,
    0x00000003, 0x004242D4, 0x00000000, 0x00000000, 0x00000000, (unsigned int)D_800D34BC, (unsigned int)D_800D34B8, (unsigned int)D_800D34C0_de + 0x4,
    (unsigned int)D_800D34C0_de + 0x10, (unsigned int)D_800D34C0_de + 0xC, (unsigned int)D_800D34C0_de + 0x8, (unsigned int)D_800D34C0_de + 0xC, (unsigned int)D_800D34C0_de + 0x8, (unsigned int)D_800D34C0_de + 0x10, (unsigned int)D_800D34C0_de + 0x4,
};
#endif
#if defined(VERSION_EU)
extern char D_800E1D54[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x0042495C, 0x00000E06, 0x00000003, 0x004241E0, 0x00000E03, 0x00000003,
    0x0042492C, 0x00000002, 0x00000003, 0x00424AC8, 0x00000001, 0x00000003, 0x004246E8, 0x0000000A,
    0x00000003, 0x00424A74, 0x00000000, 0x00000000, 0x00000000, 0x97150000, 0x4A19CE6C, (unsigned int)D_800E1D54 + 0x10,
    (unsigned int)D_800E1D54 + 0x40, (unsigned int)D_800E1D54 + 0x30, (unsigned int)D_800E1D54 + 0x20, (unsigned int)D_800E1D54 + 0x30, (unsigned int)D_800E1D54 + 0x20, (unsigned int)D_800E1D54 + 0x40, (unsigned int)D_800E1D54 + 0x10,
};
#endif
#if defined(VERSION_EU_X)
extern char D_800E1D54[];
unsigned int D_src_6bb6ec48[31] = {
    0x00000E08, 0x00000003, 0x00424AAC, 0x00000E06, 0x00000003, 0x00424330, 0x00000E03, 0x00000003,
    0x00424A7C, 0x00000002, 0x00000003, 0x00424C18, 0x00000001, 0x00000003, 0x00424838, 0x0000000A,
    0x00000003, 0x00424BC4, 0x00000000, 0x00000000, 0x00000000, 0x00000E03, 0x00000020, (unsigned int)D_800E1D54 + 0xC,
    (unsigned int)D_800E1D54 + 0x30, (unsigned int)D_800E1D54 + 0x24, (unsigned int)D_800E1D54 + 0x18, (unsigned int)D_800E1D54 + 0x24, (unsigned int)D_800E1D54 + 0x18, (unsigned int)D_800E1D54 + 0x30, (unsigned int)D_800E1D54 + 0xC,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_867707feeb8d8b03c71b[3] = {
    0x00000E08, 0x00000003, (unsigned int)D_0042439C,
};
#endif

#if defined(VERSION_US)
#if defined(VERSION_US)
extern char D_800D34C0_de[];
unsigned int data_unresolved_800DF270[28] = {
    0x00000E06, 0x00000003, 0x00423C20, 0x00000E03, 0x00000003, 0x0042436C, 0x00000002, 0x00000003,
    0x00424508, 0x00000001, 0x00000003, 0x00424128, 0x0000000A, 0x00000003, 0x004244B4, 0x00000000,
    0x00000000, 0x00000000, 0x00660000, 0x00040000, (unsigned int)D_800D34C0_de + 0x4, (unsigned int)D_800D34C0_de + 0x10, (unsigned int)D_800D34C0_de + 0xC, (unsigned int)D_800D34C0_de + 0x8,
    (unsigned int)D_800D34C0_de + 0xC, (unsigned int)D_800D34C0_de + 0x8, (unsigned int)D_800D34C0_de + 0x10, (unsigned int)D_800D34C0_de + 0x4,
};
#endif
#endif
