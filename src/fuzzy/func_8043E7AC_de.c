#include "types.h"

/* Sets a field's text to D_800D3DDC when D_80142228 equals D_800DE338, and otherwise to D_800D3DD8, into which D_800E1DF8_de less five is formatted with D_800DE2F8 three bytes before the length func_80441FE8_de reports. Returns zero. */
struct Field {
    char pad[0x14];
    char **text;
};

extern f32 D_80142228;
extern f32 D_800DE338;
extern char *D_800D3DD8[];
extern char *D_800D3DDC[];
extern char D_800DE2F8[];
extern s32 D_800E1DF8_de;
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8043E7AC_de(struct Field *field) {
    char *text;

    if (D_80142228 == D_800DE338) {
        field->text = D_800D3DDC;
    } else {
        field->text = D_800D3DD8;
        text = *field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 3), D_800DE2F8, D_800E1DF8_de - 5);
    }
    return 0;
}

