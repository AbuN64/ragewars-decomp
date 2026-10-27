#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "MULTI/SETUP.H"

/* 80406A88_26.CPP */
#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#define EUW(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern u8 D_80145040[];
extern char D_800E20AC[];
extern s32 D_800E63C0[];
extern char *D_800E3B64[];
extern s32 Player_GetPlayerIndex();
/* Name-entry slot update: marks the slot's flag word (offsets 0x30/0x58/0x80/0xA8 of the record at 0xC, one per slot) with bits
   0x1800000 and clears them in the others, then copies the slot's 8-character name from D_8015235C_eu (150-byte records) into the
   24-byte slot entry at D_800E20AC, trimming trailing blanks (all blank when it equals the language's default name). */
void func_80446A50_eu_x(void *obj) {
    u8 *rec = *(u8 **)((u8 *)obj + 0xC);
    s32 slot = Player_GetPlayerIndex(D_80145040, *(s32 *)((u8 *)obj + 0x1C));
    static const u8 flagOff[4] = { 0x30, 0x58, 0x80, 0xA8 };
    char *src, *dst, *def;
    s32 i, blanks, n, k;

    for (i = 0; i < 4; i++) {
        if (i == (slot >= 0 && slot < 4 ? slot : 0)) {
            EUW(rec, flagOff[i]) |= 0x1800000;
        } else {
            EUW(rec, flagOff[i]) &= 0xFE7FFFFF;
        }
    }
    D_800E20A4_de[slot * 6] = 0;
    dst = D_800E20AC + slot * 24;
    src = D_8015235C_eu + slot * 150;
    blanks = 0;
    for (i = 8; i > 0 && src[i - 1] == ' '; i--) {
        blanks++;
    }
    def = D_800E3B64[g_languageIndex];
    for (k = 0, n = 6; n > 0; k++, n--) {
        if (src[k] != def[k] || src[k] == 0) {
            break;
        }
    }
    if (n == 0) {
        blanks = 8;
    }
    for (i = 0; i < 8 - blanks; i++) {
        *dst++ = src[i];
    }
    *dst = 0;
    D_800E20A8[slot * 6] = D_800E63C0[slot * 6] = 8 - blanks;
}
#else
INCLUDE_ASM("ovl_80400000", func_80446A50_eu_x);
#endif
#endif

/* 8042FBEC_27.CPP */
#if defined(VERSION_EU)
#ifdef NON_MATCHING
#include "TYPES.H"
#define EUW(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern u8 D_80145040[];
extern char D_800E20AC[];
extern s32 D_800E63C0[];
extern char *D_800E3B64[];
extern s32 Player_GetPlayerIndex();
/* Name-entry slot update: marks the slot's flag word (offsets 0x30/0x58/0x80/0xA8 of the record at 0xC, one per slot) with bits
   0x1800000 and clears them in the others, then copies the slot's 8-character name from D_8015235C_eu (150-byte records) into the
   24-byte slot entry at D_800E20AC, trimming trailing blanks (all blank when it equals the language's default name). */
void func_80446920_eu(void *obj) {
    u8 *rec = *(u8 **)((u8 *)obj + 0xC);
    s32 slot = Player_GetPlayerIndex(D_80145040, *(s32 *)((u8 *)obj + 0x1C));
    static const u8 flagOff[4] = { 0x30, 0x58, 0x80, 0xA8 };
    char *src, *dst, *def;
    s32 i, blanks, n, k;

    for (i = 0; i < 4; i++) {
        if (i == (slot >= 0 && slot < 4 ? slot : 0)) {
            EUW(rec, flagOff[i]) |= 0x1800000;
        } else {
            EUW(rec, flagOff[i]) &= 0xFE7FFFFF;
        }
    }
    D_800E20A4_de[slot * 6] = 0;
    dst = D_800E20AC + slot * 24;
    src = D_8015235C_eu + slot * 150;
    blanks = 0;
    for (i = 8; i > 0 && src[i - 1] == ' '; i--) {
        blanks++;
    }
    def = D_800E3B64[g_languageIndex];
    for (k = 0, n = 6; n > 0; k++, n--) {
        if (src[k] != def[k] || src[k] == 0) {
            break;
        }
    }
    if (n == 0) {
        blanks = 8;
    }
    for (i = 0; i < 8 - blanks; i++) {
        *dst++ = src[i];
    }
    *dst = 0;
    D_800E20A8[slot * 6] = D_800E63C0[slot * 6] = 8 - blanks;
}
#else
INCLUDE_ASM("ovl_80400000", func_80446920_eu);
#endif
#endif
