#include "types.h"
#include "span_1000/code_80217388.h"
/* Returns the cardinal team-menu slot, or -1 inside the deadzone/diagonals. */
s32 func_80218988_de(void *object) {
    StickPlayer *player = object;
    StickInput *input = player->input;
    s8 x = input->x;
    s8 y = input->y;
    if (x*x + y*y < 3600) return -1;
    if (((f32)(((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y)) < 0.0f ? -(((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y)) : (((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y))) < 46 && x && y) goto diagonal;

    if (((f32)x < 0.0f ? -x : x) > ((f32)y < 0.0f ? -y : y)) { s32 r = 1; if (x <= 0) r = 3; return r; }
    return (y <= 0) << 1;

diagonal:
    return -1;
}
