#include "common/unused.h"
#include "span_1000/code_80293A04.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "video_dimensions.h"

extern s32 D_800E28D0;
extern s32 D_800E28D4;

extern void func_8029311C_de(void *arg0, s8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

void func_80293394_de(void *arg0) {
    s8 color[4];
    f32 value;
    s32 alpha;

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    value = ((struct Session_func_80293A20_de *)arg0)->timer;
    alpha = 0xFF;
    if (!(value < 0)) {
        alpha = 0;
        if (!((&D_800CA560)[1] < value)) {
            alpha = 0xFF;
            if (!(value < 0)) {
                alpha = ~(s32)(value * D_800C547C);
            }
        }
    }
    color[3] = alpha;
    func_8029311C_de(arg0, color, 0, 0, SCREEN_WD, SCREEN_HT);
}
