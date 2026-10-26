#include "include_asm.h"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern s32 D_80153774;
extern char D_auto_800D37CC[];
extern char D_auto_800D37D4[];
extern u8 D_8014D49B_de[];
extern u8 D_8014D494_de[];
typedef struct { char pad0[0x14]; char **text; } Func_8040A810_Obj;
/* Shows the eight-character name D_8014D494_de in the field 0xC bytes into the text (right aligned, blank padded after trimming trailing blanks), or points the text at D_auto_800D37CC when D_80153774 is set; returns zero. */
s32 Menu_FormatRightAlignedName(Func_8040A810_Obj *arg0) {
    u8 *last;
    char *dst;
    s32 n;
    s32 i;
    n = 8;
    if (D_80153774 != 0) {
        arg0->text = (char **)D_auto_800D37CC;
    } else {
        last = D_8014D49B_de;
        arg0->text = (char **)D_auto_800D37D4;
        if (*last == 0x20) {
            last--;
            while (n != 0) {
                n--;
                if (*last-- != 0x20) {
                    break;
                }
            }
        }
        dst = *arg0->text + 0xC;
        for (i = 7; i >= 0; i--) {
            dst[i] = 0x20;
        }
        dst = dst + 8 - n;
        for (i = 0; i < n; i++) {
            *dst++ = D_8014D494_de[i];
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_FormatRightAlignedName);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern s32 D_80153774;
extern char D_800D37D0[];
extern char D_auto_800D37D8[];
extern char *D_auto_800D39F8, *D_auto_800D39FC, *D_auto_800D3A10, *D_auto_800D3A18, *D_auto_800D3A1C;
extern s8 D_8014D490;
typedef struct { char pad0[0x14]; char **text; } Func_8040A8D0_Obj;
/* Copies the 14-byte label chosen by D_8014D490 (default D_auto_800D39F8) into the text 6 bytes in, or points the text at D_800D37D0 when D_80153774 is set; returns zero. */
s32 Menu_FormatNoteTypeLabel(Func_8040A8D0_Obj *arg0) {
    char *src;
    char *dst;
    s32 i;
    if (D_80153774 != 0) {
        arg0->text = (char **)D_800D37D0;
    } else {
        arg0->text = (char **)D_auto_800D37D8;
        switch (D_8014D490) {
        case 0:
        case 1:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        default:
            src = D_auto_800D39F8;
            break;
        case 5:
            src = D_auto_800D39FC;
            break;
        case 3:
            src = D_auto_800D3A10;
            break;
        case 2:
            src = D_auto_800D3A18;
            break;
        case 14:
            src = D_auto_800D3A1C;
            break;
        }
        dst = *arg0->text + 6;
        for (i = 0; i < 14; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_FormatNoteTypeLabel);
#endif
#endif

#if defined(VERSION_DE)
const unsigned int D_auto_rodata_func_8040A8D0_de_800DCDD8[15] = {
    0x0040A924, 0x0040A924, 0x0040A954, 0x0040A944, 0x0040A924, 0x0040A934, 0x0040A924, 0x0040A924,
    0x0040A924, 0x0040A924, 0x0040A924, 0x0040A924, 0x0040A924, 0x0040A924, 0x0040A964,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DCE14[1] = {
    0x00000000,
};
#endif
