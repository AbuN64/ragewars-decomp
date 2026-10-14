#include "gfx.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"
#include "n64sdk.h"
#include "gbi.h"
#include "n64sdk.h"
extern struct Screen_func_8041FC50_de *D_800E42D0;
extern s32 D_800D15E0;
extern f32 D_800D15E4[5];
extern struct Shape_typemap_165 D_800E41C0[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern Gfx *D_80110634;
extern void func_8041C7F4_de(void *);
/* Draw callback of the four-player screen D_800E42D0: on draw event 1 in state 3 it clips the display list to each joined or ready player's viewport in D_800E41C0 and draws that panel through func_8041C7F4_de, in the flash fill (mode 3) while the panel's flash counter runs down and in opaque white otherwise, then restores the full-screen clip and the white fill; returns zero. */
s32 func_8041FC50_de(void *arg0, void *arg1, s32 event)
{
    s32 i;
    if (event == 1 && D_800E42D0->state == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E42D0->panels[i].state == 1 || D_800E42D0->panels[i].state == 3) {
                if (D_800E42D0->panels[i].player != -1) {
                    gDPSetScissorFrac(D_80110634++, 0, (s32)((f32)((D_800E41C0[i].field_0)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_4)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_8)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_C)) * 4.0f));
                    if (D_800E42D0->panels[i].flash > 0) {
                        D_800D15E4[0] = 150.0f;
                        D_800D15E4[1] = 0.0f;
                        D_800D15E4[2] = 0.0f;
                        D_800D15E4[3] = 100.0f;
                        D_800D15E4[4] = 100.0f;
                        D_800D15E0 = 3;
                        D_800E42D0->panels[i].flash--;
                    } else {
                        D_800D15E0 = 0;
                        D_800D15E4[0] = 255.0f;
                        D_800D15E4[1] = 255.0f;
                        D_800D15E4[2] = 255.0f;
                        D_800D15E4[3] = 255.0f;
                    }
                    func_8041C7F4_de(D_800E42D0->panels[i].body);
                }
            }
        }
        D_800D15E0 = 0;
        gDPSetScissorFrac(D_80110634++, 0, (s32)((f32)((0)) * 4.0f), (s32)((f32)((0)) * 4.0f), (s32)((f32)((D_800E28D0 - 1)) * 4.0f), (s32)((f32)((D_800E28D4 - 1)) * 4.0f));
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
    }
    return 0;
}
