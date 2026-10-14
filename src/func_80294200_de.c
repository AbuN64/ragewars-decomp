#include "gfx.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80293A04.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"


/* Clears the map-view-active flag, emits a set-color-image display list command for the current frame
 * buffer, then draws image 0x389 scaled to fill the screen dimensions over the image's returned width
 * and height, when both are nonzero. */




extern void func_802A9234_de(s32);

extern void func_802AAC28_de(s32 image, s32 frame, s32 x, s32 y, f32 scaleX, f32 scaleY, s32 flags);
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800CC380;

void func_80294200_de(void) {
    s32 width;
    s32 height;
    Gfx *cmd;

    D_800CC380 = 0;
    width = 0;
    height = 0;
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)D_8011BDC0->colorImage);
    func_802AA950_de(0x389, 0, &width, &height);
    if ((width != 0) && (height != 0)) {
        func_802A9234_de(0xFA);
        func_802AAC28_de(0x389, 0, 0, 0, (f32)D_800E28D0 / (f32)width, (f32)D_800E28D4 / (f32)height, 1);
    }
}
