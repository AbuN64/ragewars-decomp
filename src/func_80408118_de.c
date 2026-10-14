#include "span_16E000/code_80405DC0.h"
/* Fills the pak menu header by choosing its text from the save, single-pak or other mode and printing the selected pak's free space and the blocks the save needs as three digits at offsets 14 and 31. */
#include "types.h"
#include "common/unused.h"

extern s32 D_8015375C;

extern s32 D_8011FECC;
extern Digits D_800DCD78;
extern u8 *D_800D3754;
extern u8 *D_800D376C;
extern u8 *D_800D7E14;

extern s32 func_80405160_de(s32 ch, s32 *freeSpace);
extern s32 func_804057EC_de(s32 size);
extern void func_802658E4_de(Digits *dst, char *format, s32 value);

static inline int space_required(int size) {size += 0x610; return func_804057EC_de(size);}
s32 func_80408118_de(PakNoteTextEntry *entry, PakStatusPakSaveMenu *menu) {
    Digits digits;
    s32 freeSpace;
    s32 ch;
    s32 need;
    s32 result;
    u8 *text;
    u8 **header;
    char *format;
    Digits *buffer;

    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->slot->unk4;
    }
    digits = D_800DCD78;
    buffer = &digits;
    if (D_8014D4C0_de != 0) {
        entry->text = &D_800D3754;
        if (func_80405160_de(ch, &freeSpace) == 0) {
            if (D_8014D4EC_de) need=func_804057EC_de(0x18); else need=space_required(D_8011FECC);
            text = *entry->text;
            func_802658E4_de(&digits, D_800E0DA4, freeSpace);
            text += 14;
            *text++ = digits.c[0];
            *text++ = digits.c[1];
            *text = digits.c[2];
            func_802658E4_de(&digits, D_800E0DA4, need);
            text += 15;
            *text++ = digits.c[0];
            *text = digits.c[1];
            text[1] = digits.c[2];
        }
    } else if (D_8015375C != 0) {
        header = &D_800D376C;
        goto fill;
    } else if (D_80153760 != 0) {
        header = &D_800D3754;
    fill:
        entry->text = header;
        result = func_80405160_de(ch, &freeSpace);
        need = func_804057EC_de(D_8011FECC + 0x610);
        text = *entry->text;
        if (result == 0) {
            text += 14;
            format = D_800E0DA4;
            func_802658E4_de(buffer, format, freeSpace);
            *text++ = digits.c[0];
            *text++ = digits.c[1];
            *text = digits.c[2];
            func_802658E4_de(buffer, format, need);
            text += 15;
            *text++ = digits.c[0];
            *text = digits.c[1];
            text[1] = digits.c[2];
        }
    } else {
        entry->text = &D_800D7E14;
    }
    return 0;
}
