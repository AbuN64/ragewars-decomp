#include "span_16E000/code_80405DC0.h"
/* Writes the 11-character rank title for the score D_8014D48C into the end of the item's text:
   the title comes from the band the score falls in (below 50, 150, 300, 500, 800, 1300, 2000,
   3000, 4500, 6500 and 9999 and above), and the text position is the text length from
   func_80441FE8_de minus 11; returns 0. */
#include "types.h"



extern u16 D_8014D48C;

























extern s32 func_80441FE8_de(void);

s32 func_80408AC4_us(PakNoteTextEntry *item) {
    char *title;
    u8 *dest;
    s32 i;
    s32 score;

    title = 0;
    score = D_8014D48C;
    if (D_8014D48C < 50) {
        title = D_800D241C;
    } else if (score >= 50 && score < 150) {
        title = D_800D2420;
    } else if (score >= 150 && score < 300) {
        title = D_800D2424;
    } else if (score >= 300 && score < 500) {
        title = D_800D2428;
    } else if (score >= 500 && score < 800) {
        title = D_800D242C;
    } else if (score >= 800 && score < 1300) {
        title = D_800D2430;
    } else if (score >= 1300 && score < 2000) {
        title = D_800D2434;
    } else if (score >= 2000 && score < 3000) {
        title = D_800D2438;
    } else if (score >= 3000 && score < 4500) {
        title = D_800D243C;
    } else if (score >= 4500 && score < 6500) {
        title = D_800D2440;
    } else if (score >= 6500 && score < 9999) {
        title = D_800D2444;
    } else if (score >= 9999) {
        title = D_800D2448;
    }
    dest = *item->text;
    dest += func_80441FE8_de() - 11;
    if (title != 0) {
        for (i = 0; i < 11; i++) {
            *dest++ = *title++;
        }
    }
    return 0;
}

