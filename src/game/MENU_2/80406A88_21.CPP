#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern u8 D_80142235, D_80142236, D_80142237, D_80142238, D_80142239, D_8014223A, D_8014223B, D_8014223D;
extern char *D_800D3D14[], *D_800D3D18[], *D_800D3D1C[], *D_800D3D20[], *D_800D3D24[], *D_800D3D28[], *D_800D3D2C[], *D_800D3D30[],
    *D_800D3D34[], *D_800D3D38[], *D_800D3D3C[], *D_800D3D40[], *D_800D3D44[], *D_800D3D48[], *D_800D3D4C[], *D_800D3D50[];
/* Picks the label of option row 2..9 from its on/off flag (the eu-x twin of func_8043EA40, without the language table). */
typedef struct { s32 id; u8 pad4[0x10]; char **text; } OptionRowEux;
typedef struct { u8 pad0[0xC]; OptionRowEux *row; } OptionHolderEux;
s32 func_8043EB6C_eu_x(void *unused, OptionHolderEux *holder) {
    OptionRowEux *row = holder->row;
    switch (row->id) {
    case 2: row->text = D_80142235 ? D_800D3D14 : D_800D3D18; break;
    case 3: row->text = D_80142236 ? D_800D3D1C : D_800D3D20; break;
    case 4: row->text = D_80142237 ? D_800D3D24 : D_800D3D28; break;
    case 5: row->text = D_80142238 ? D_800D3D2C : D_800D3D30; break;
    case 6: row->text = D_80142239 ? D_800D3D34 : D_800D3D38; break;
    case 7: row->text = D_8014223A ? D_800D3D3C : D_800D3D40; break;
    case 8: row->text = D_8014223B ? D_800D3D44 : D_800D3D48; break;
    case 9: row->text = D_8014223D ? D_800D3D4C : D_800D3D50; break;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043EB6C_eu_x);
#endif
#endif
