#include "span_1000/code_8026AC38.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"




extern s32 D_80110620;
extern Gfx *D_80110634;

void func_8026D914_de(s32 arg0) {
    if (D_80110620 == 0) gDPSetColorDither(D_80110634++, arg0) else gDPSetColorDither(D_80110634++, G_CD_NOISE);
}
