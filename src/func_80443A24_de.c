#include "common/unused.h"
#include "span_16E000/code_8043F69C.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804453C4.h"

/* Formats the halfword D_801422DC holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length func_80441FE8_de reports. Returns zero. */

extern char D_80145040[];
extern s16 D_801422DC[];
extern char D_800DE700[];
extern s32 func_8022A5A0_de(void *, unsigned int);
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_80443A24_de(Item_func_80441FE8_de *field, struct Holder *holder) {
    s32 player = func_8022A5A0_de(D_80145040, (u32)holder->owner);
    s32 value = D_801422DC[player * 75];
    char *text = (char *)*field->text;

    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE700, value);
    return 0;
}
