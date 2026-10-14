#include "gfx.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80291054.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Clears the depth buffer over a rectangle: switches the colour image to the depth buffer D_801536E8 in fill mode after setting render mode 0x14 through func_8026925C_de, fills the rectangle with the far depth value (or, for interlaced output, alternate lines with the far value and the remaining lines with 0, by single lines or by line pairs as D_800E28D8 selects), then restores the frame's colour image and one-cycle mode. Written with libultra-style display-list macros. */




extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern s32 D_800E28D0;
extern s32 D_800E28D8;
extern void *D_801536E8;
extern void func_8026925C_de(s32 mode);










void func_80291BE8_de(s32 unused, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced) {
    s32 y;

    gDPPipeSync(D_80110634++);
    func_8026925C_de(0x14);
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_801536E8)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    if (!interlaced) {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        gDPFillRectangle(D_80110634++, (ulx), (uly), (lrx), (lry));
    } else if (D_800E28D8 == 0) {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y += 2) {
            gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
        }
        gDPSetFillColor(D_80110634++, ((0)));
        for (y = uly + 1; y < lry; y += 2) {
            gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
        }
    } else {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) < 2) {
                gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
            }
        }
        gDPSetFillColor(D_80110634++, ((0)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) >= 2) {
                gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
            }
        }
    }
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_8011BDC0->colorImage)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
}
