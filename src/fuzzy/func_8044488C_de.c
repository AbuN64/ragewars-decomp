#include "types.h"

/* Shows D_800D35EC in a field when the top twelve bits of D_801462DC are zero, D_800D35F0 when they are sixteen, and otherwise points the field at D_800D35F4 and formats their value into it with D_800DE750_de two bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_80445494_de with the value taken from the top twelve bits of the halfword D_801462DC, a second fixed text for sixteen, and the texts and format changed. */
struct Field {
    char pad[0x14];
    char **text;
};

extern u16 D_801462DC;
extern char *D_800D35EC[];
extern char *D_800D35F0[];
extern char *D_800D35F4;
extern char D_800DE750_de[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8044488C_de(struct Field *field) {
    char *text;
    s32 value = D_801462DC >> 4;

    if (value == 0) {
        field->text = D_800D35EC;
    } else if (value == 16) {
        field->text = D_800D35F0;
    } else {
        field->text = &D_800D35F4;
        text = D_800D35F4;
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DE750_de, value);
    }
    return 0;
}

