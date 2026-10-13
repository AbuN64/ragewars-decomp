#include "shared/pak_menu.h"

extern s32 D_800E28C8, D_800DE874;
extern char *D_800D36D4, *D_800D36D8, *D_800D36DC;

extern s32 D_8015375C;

extern char *D_800D36E0;

extern s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, char *name, char *ext, s32 *size,
                         char *company, char *code);
extern s32 func_802A0238_de(char *);
extern s32 func_802A037C_de(char *a, char *b);

void func_80405F48_de(Shared_PakMenu *menu) {
    s32 ch;
    s32 i;
    s32 other;
    s32 result;
    s32 match;
    char *title;
    char ext[8];
    char company[8];
    char code[8];
    char name[16];
    s32 exists;
    s32 size;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->owner->unk4;
    }
    for (i = 0; i < 16; i++) {
        result = func_8040458C_de(ch, i, &exists, name, ext, &size, company, code);
        other = 1;
        if (result == 0 && exists != 0) {
            switch (D_800DE874) {
                case 1:
                    if (func_802A0238_de(code) == 4 && func_802A0238_de(company) == 2 &&
                        func_802A037C_de(code, D_800D36E0) == 0 && func_802A037C_de(company, D_800D36DC) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = D_800D36D4;
                    break;
                case 2:
                    if (func_802A0238_de(code) == 4 && func_802A0238_de(company) == 2 &&
                        func_802A037C_de(code, D_800D36E0) == 0 && func_802A037C_de(company, D_800D36DC) == 0) {
                        match = 1;
                    } else {
                        match = 0;
                    }
                    title = D_800D36D8;
                    break;
                case 0:
                default:
                    other = 0;
                    goto done;
            }
            if (func_802A037C_de(name, title) == 0 && match != 0) {
                other = 0;
            }
        }
    done:
        if (other) {
            menu->items[i + 3].flags &= ~0x1000000;
        } else {
            menu->items[i + 3].flags |= 0x1000000;
        }
    }
}
