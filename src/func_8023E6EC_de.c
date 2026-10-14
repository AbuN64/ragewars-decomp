#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Clips a segment against a query: measures the heights of its two ends through func_80241728_de,
   raises the far end by D_800D0640[1] scaled to 10.24, and when the squared flat length plus the
   squared height difference is not zero, moves the far end to the fraction func_802B72B0_de returns
   for the flat share of that length, writing the interpolated height at 0x54 and position at 0x50
   and 0x58. The node at 0x74 is then faded by what is left of one after the limit at 0x10 of the
   record at 0x40, and not at all once that limit passes one. */

struct Query;





extern f32 D_800D0640[];
extern f32 func_80241728_de(struct Query *, f32, f32);
extern f32 func_802B72B0_de(f32);
extern void func_80271F9C_de(void *, void *, f32);

void func_8023E6EC_de(Segment_func_8023E6EC_de *arg0, struct Query *arg1) {
    f32 start;
    f32 span;
    f32 flat;
    f32 total;
    f32 dx;
    f32 dy;
    f32 share;
    f32 limit;
    f32 nx;
    void *target;
    f32 fade;
    void *node;

    start = func_80241728_de(arg1, arg0->x0, arg0->y0);
    span = (func_80241728_de(arg1, arg0->x1, arg0->y1) + (D_800D0640[1] * 10.24f)) - start;
    dx = arg0->x1 - arg0->x0;
    dy = arg0->y1 - arg0->y0;
    flat = (dx * dx) + (dy * dy);
    total = flat + (span * span);
    if (total == 0.0f) {
        arg0->height = start;
        return;
    }
    share = func_802B72B0_de(flat / total);
    node = arg0->node;
    nx = arg0->x0 + (share * (arg0->x1 - arg0->x0));
    arg0->height = start + (share * span);
    arg0->x1 = nx;
    arg0->y1 = arg0->y0 + (share * (arg0->y1 - arg0->y0));
    limit = arg0->limits->value;
    target = node;
    if (1.0f < limit) {
        fade = 0.0f;
    } else {
        fade = 1.0f - limit;
    }
    func_80271F9C_de(target, node, fade);
}
