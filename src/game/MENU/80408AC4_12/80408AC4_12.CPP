#include "include_asm.h"
#include "COMMON/EXTERNS_20.H"

#if defined(VERSION_DE)
extern char D_800D7A0C[];
extern char D_800DE7BC[];
typedef struct { char pad0[0x14]; char *text; } Func_8040BB40_Obj;
s32 Menu_SelectPakOperationActionLabel(Func_8040BB40_Obj *arg0) {
    switch (D_80153778) {
    case 0:
    default:
        arg0->text = D_800D7A0C;
        break;
    case 3:
        arg0->text = D_800D7A0C;
        break;
    case 4:
        arg0->text = D_800D7A0C;
        break;
    case 1:
    case 2:
        arg0->text = D_800DE7BC;
        break;
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_8040BBAC_de_padding_171BAC[4] = { 0xD3, 0x1F, 0xFF, 0x0D };
#endif
