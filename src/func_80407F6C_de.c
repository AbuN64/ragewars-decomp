#include "span_16E000/code_80405DC0.h"
#include "types.h"
#include "common/unused.h"

extern s32 D_8015375C;

extern char *D_800D3758;
extern char *D_800D375C;

extern s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, u8 *name, u8 *ext, s32 *size,
                         char *companyCode, char *gameCode);
extern s32 func_804057BC_de(u8 *name, s32 size);
extern void func_802A025C_de(u8 *dst, char *src);
extern void func_802658E4_de(u8 *dst, char *format, s32 value);

s32 func_80407F6C_de(PakNoteTextEntry *entry, PakNotesMenu *menu) {
    u8 name[16];
    u8 ext[8];
    char companyCode[8];
    char gameCode[8];
    s32 exists;
    s32 size;
    s32 ch;
    s32 result;
    s32 more;
    s32 i;
    u8 *dst;
    u8 c;
    s32 index;
    char **placeholder;

    c = ' ';
    index = entry->id - 3;
    if (D_80153784 != 0) {
        return 0;
    }
    if (D_8015375C != 0) {
        ch = D_800E28C8;
    } else {
        ch = menu->owner->unk4;
    }
    result = func_8040458C_de(ch, index, &exists, name, ext, &size, companyCode, gameCode);
    if (exists != 0 && result == 0) {
        if (func_804057BC_de(name, 16) != 0) {
            func_802A025C_de(name, D_800D3758);
        }
    } else {
        placeholder = &D_800D375C;
        func_802A025C_de(name, *placeholder);
        func_802A025C_de(ext, *placeholder);
        size = 0;
    }
    more = 1;
    dst = *entry->text;
    dst += 3;
    for (i = 0; i < 16; i++) {
        if (more) {
            c = name[i];
        }
        if (c == 0) {
            more = 0;
            c = ' ';
        }
        *dst++ = c;
    }
    more = 1;
    dst++;
    for (i = 0; i < 4; i++) {
        if (more) {
            c = ext[i];
        }
        if (c == 0) {
            more = 0;
            c = ' ';
        }
        *dst++ = c;
    }
    *dst += 2;
    func_802658E4_de(dst, D_800E0DA4, size);
    return 0;
}

/* Native resident constant storage; absolute access symbols retain their addresses. */
#if defined(VERSION_US)

#elif defined(VERSION_US_REV1)

#elif defined(VERSION_DE)

#endif
