#include "gfx.h"
#include "abi.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80290980.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"
#include "video_dimensions.h"
/* Clears the screen: clears the depth buffer over the whole screen through func_80291BE8_de, emits a full-screen scissor, the frame's colour image, fill cycle, combiner, no-op render mode, fill colour 0x10001 and a full-screen fill rectangle, then, when image 0x386 has a size, draws it stretched across the screen through func_802AAC28_de after func_802A9234_de(255). Written with libultra-style display-list macros and the screen size read from D_800E28D0 and D_800E28D4. */
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern void func_80291BE8_de(s32 arg0, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced);

extern void func_802A9234_de(s32 alpha);
extern void func_802AAC28_de(s32 image, s32 frame, s32 x, s32 y, f32 scaleX, f32 scaleY, s32 flags);
void func_80290C24_de(s32 arg0) {
    Frame *frame = D_8011BDC0;
    s32 width;
    s32 height;
    func_80291BE8_de(arg0, 0, SCREEN_WD, 0, SCREEN_HT, 0);
    width = 0;
    height = 0;
    gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, (int)((float)((0)) * 4.0F), (int)((float)((0)) * 4.0F), (int)((float)((SCREEN_WD - 1)) * 4.0F), (int)((float)((SCREEN_HT - 1)) * 4.0F));
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((frame->colorImage)));
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, ((0)), 0);
    gDPSetFillColor(D_80110634++, ((0x10001)));
    gDPFillRectangle(D_80110634++, 0, 0, (SCREEN_WD), (SCREEN_HT));
    func_802AA950_de(0x386, 0, &width, &height);
    if (width != 0 && height != 0) {
        func_802A9234_de(0xFF);
        func_802AAC28_de(0x386, 0, 0, 0, (f32)SCREEN_WD / (f32)width, (f32)SCREEN_HT / (f32)height, 1);
    }
}
