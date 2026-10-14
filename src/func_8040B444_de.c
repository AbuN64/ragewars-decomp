#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8043F69C.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_16E000/code_80405DC0.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "common/data.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern char D_800ED41C[];
#else
#endif
/* Takes D_800E28C8 when D_8015375C is set and otherwise the signed byte at offset 4 of the second argument's record at 0x20, then shows D_800D394C in a field when D_80153734 is set and otherwise points the field at D_800D3958 and formats one more than that value into it with D_800DCD9C two bytes before the length func_80441FE8_de reports, returning zero.
   Adapted from func_8040A300_de with the value source chosen by D_8015375C, the text chosen by D_80153734, the offset two bytes, and the texts and format changed. */

extern s32 D_8015375C;

extern u8 *D_800D394C[];

extern char D_800DCD9C[];
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040B444_de(Item_func_80441FE8_de *field, struct Record_func_80409BDC_de *holder) {
    char *text;
    s32 value;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    u8 **table;

#else
#endif
    if (D_8015375C != 0) {
        value = D_800E28C8;
    } else {
        value = holder->inner->unk4;
    }
    if (D_80153734 != 0) {
        field->text = D_800D394C;
    } else {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        table = ((u8 **)(void *)D_800E2FB4);
        field->text = table;
        text = (char *)table[D_80152789];
#else
        field->text = ((u8 **)(void *)&D_800D3958);
        text = ((char **)(void *)&D_800D3958)[0];
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800ED41C, value + 1);
#else
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DCD9C, value + 1);
#endif
    }
    return 0;
}

#endif
