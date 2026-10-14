#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
/* FAKEMATCH: version selection preserves distinct original same-start bodies mapped to this live identity; only one original body is compiled for each owning version. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#include "types.h"
/* Shows D_800D3728 in a field when both D_8014D4EC_de and D_8014D4C0_de are set, D_800D372C when only D_8014D4C0_de is, and otherwise, when D_8015375C is set, points the field at D_800D3764 and formats D_800E28C8 plus one into it with D_800DCD7C one byte before the length func_80441FE8_de reports, returning zero.
   Adapted from func_8044488C_de with the three flag tests, the texts, the format, the offset and the incremented value changed. */


extern s32 D_8014D4EC_de;
extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern char *D_800D3728[];
extern char *D_800D372C[];
extern char *D_800D3764[];
extern char D_800DCD7C[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A244_de(struct Field *field) {
    char *text;
    s32 value;

    if (D_8014D4EC_de != 0 && D_8014D4C0_de != 0) {
        field->text = D_800D3728;
    } else if (D_8014D4EC_de == 0 && D_8014D4C0_de != 0) {
        field->text = D_800D372C;
    } else if (D_8015375C != 0) {
        value = D_800E28C8;
        field->text = D_800D3764;
        text = D_800D3764[0];
        func_802658E4_de(text + (func_80441FE8_de(field) - 1), D_800DCD7C, value + 1);
    }
    return 0;
}

#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "types.h"
/* Points an option field at its text: when D_8014D4C0_de is set, D_800D3728 if D_8014D4EC_de is set and D_800D372C if not; otherwise, when D_8015375C is set, the table D_800E27E4, formatting its entry for the byte D_80152789 with D_800ED3FC and D_800E28C8 plus one from one byte before the length func_80441FE8_de reports; returns zero. */



extern s32 D_8014D4EC_de;
extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern char *D_800D3728[];
extern char *D_800D372C[];
extern char *D_800E27E4[];
extern u8 D_80152789;
extern s32 D_800E28C8;
extern char D_800ED3FC[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A244_de(struct Field *field) {
    char **table;
    char *text;
    s32 value;

    if (D_8014D4EC_de != 0) {
        if (D_8014D4C0_de != 0) {
            field->text = D_800D3728;
            goto done;
        }
    } else if (D_8014D4C0_de != 0) {
        field->text = D_800D372C;
        goto done;
    }
    if (D_8015375C != 0) {
        do {
            table = D_800E27E4;
        } while (0);
        field->text = table;
        value = D_800E28C8;
        text = table[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 1), D_800ED3FC, value + 1);
    }
done:
    return 0;
}

#endif
