#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
/* Points the output record's table at 0x14 at the variant for the display depth at 0x90 of
   D_800E28BC: 16 and 32 have their own, 8 and anything else use the default; returns 0. */




extern Display_func_8040A4D4_de *D_800E28BC;
extern int D_800D37A8;
extern int D_800D37AC;
extern int D_800D37B0;

int func_8040A4D4_de(ObjRecAt14V1 *out) {
    switch (D_800E28BC->depth) {
    case 8:
    default:
        out->unk14 = &D_800D37A8;
        break;
    case 16:
        out->unk14 = &D_800D37AC;
        break;
    case 32:
        out->unk14 = &D_800D37B0;
        break;
    }
    return 0;
}
