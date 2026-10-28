#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

/* 800DE794.CPP */
#if defined(VERSION_DE)
unsigned int D_d1_bda5e45e593b64d3[3] = {
    0x64000000, 0x20253364, 0x00000000,
};
#endif

/* 8043EA40.CPP */
#if defined(VERSION_EU)
#ifdef NON_MATCHING
extern u8 D_80152235_eu;
extern u8 D_80152236_eu;
extern u8 D_80152237_eu;
extern u8 D_80152238_eu;
extern u8 D_80152239_eu;
extern u8 D_8015223A_eu;
extern u8 D_8015223B_eu;
extern u8 D_8015223D_eu;
extern char *D_auto_800E3EA4[];
extern char *D_auto_800E3EB4[];
extern char *D_auto_800E3EC4[];
extern char *D_auto_800E3ED4[];
extern char *D_auto_800E3EE4[];
extern char *D_auto_800E3EF4[];
extern char *D_auto_800E3F04[];
extern char *D_auto_800E3F14[];
extern char *D_auto_800E3F24[];
extern char *D_auto_800E3F34[];
extern char *D_auto_800E3F44[];
extern char *D_auto_800E3F54[];
extern char *D_auto_800E3F64[];
extern char *D_auto_800E3F74[];
extern char *D_auto_800E3F84[];
extern char *D_auto_800E3F94[];
/* Picks the label for each of the eight option rows (ids 2..9): the first text when the row's flag is set, else the second. */
typedef struct { s32 id; u8 pad4[0x10]; char ***text; } OptionRowEu;
s32 Items_SelectOptionRowLabel(OptionRowEu *row) {
    switch (row->id) {
    case 2: row->text = D_80152235_eu ? D_auto_800E3EA4 : D_auto_800E3EB4; break;
    case 3: row->text = D_80152236_eu ? D_auto_800E3EC4 : D_auto_800E3ED4; break;
    case 4: row->text = D_80152237_eu ? D_auto_800E3EE4 : D_auto_800E3EF4; break;
    case 5: row->text = D_80152238_eu ? D_auto_800E3F04 : D_auto_800E3F14; break;
    case 6: row->text = D_80152239_eu ? D_auto_800E3F24 : D_auto_800E3F34; break;
    case 7: row->text = D_8015223A_eu ? D_auto_800E3F44 : D_auto_800E3F54; break;
    case 8: row->text = D_8015223B_eu ? D_auto_800E3F64 : D_auto_800E3F74; break;
    case 9: row->text = D_8015223D_eu ? D_auto_800E3F84 : D_auto_800E3F94; break;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Items_SelectOptionRowLabel);
#endif
#endif

/* 80443530.CPP */
#if defined(VERSION_EU_X)
#include "TYPES.H"
extern s32 D_8013B2BC;
extern s32 Menu_ClassifyResourceRange(s32);

void Items_PrepareMenuReturnEuX(void) {
    D_801540F4 = Menu_ClassifyResourceRange(D_8013B2BC);
    D_801540F0 = 1;
}
#endif
