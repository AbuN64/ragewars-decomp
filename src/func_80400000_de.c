#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Computes the second derivatives of a natural cubic spline through n points (ys over xs) into out: builds the tridiagonal diagonal, interval widths and right-hand side in three scratch arrays from func_8025305C_de, eliminates forward, zeroes out and back-substitutes unless a zero diagonal or width was replaced by one, then frees the arrays through func_802547E4_de. */

extern f32 *func_8025305C_de(s32 size);
extern void func_802547E4_de(f32 *block);

void func_80400000_de(s32 n, f32 *ys, f32 *xs, f32 *out) {
    f32 *diagonal;
    f32 *rhs;
    f32 *width;
    s32 singular;
    s32 i;

    singular = 0;
    if (n == 1) {
        out[0] = 0;
        return;
    }
    diagonal = func_8025305C_de(n * 4);
    rhs = func_8025305C_de(n * 4);
    width = func_8025305C_de(n * 4);
    for (i = 1; i < n - 1; i++) {
        diagonal[i] = 2.0f * (xs[i + 1] - xs[i - 1]);
        if (diagonal[i] == 0.0f) {
            diagonal[i] = 1.0f;
            singular = 1;
        }
    }
    for (i = 0; i < n - 1; i++) {
        width[i] = xs[i + 1] - xs[i];
        if (width[i] == 0.0f) {
            width[i] = 1.0f;
            singular = 1;
        }
    }
    for (i = 1; i < n - 1; i++) {
        rhs[i] = ((ys[i + 1] - ys[i]) / width[i] - (ys[i] - ys[i - 1]) / width[i - 1]) * 6.0f;
    }
    for (i = 1; i < n - 2; i++) {
        rhs[i + 1] -= rhs[i] * width[i] / diagonal[i];
        diagonal[i + 1] -= width[i] * width[i] / diagonal[i];
    }
    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    if (!singular) {
        for (i = n - 2; i > 0; i--) {
            out[i] = (rhs[i] - width[i] * out[i + 1]) / diagonal[i];
        }
    }
    func_802547E4_de(diagonal);
    func_802547E4_de(rhs);
    func_802547E4_de(width);
}

/* Builds a spline record of count nodes from points and weights: stores the node size 0x24 and the count, copies each point and weight into its node, accumulates the arc length at each node with func_80271F68_de and func_802B72B0_de (square root), and solves through func_80400000_de the second derivatives of x, y and z over arc length and of arc length over weight into scratch arrays from func_8025305C_de before freeing them; a single point gets zero derivatives. */







extern f32 *func_8025305C_de(s32 size);
extern void func_802547E4_de(f32 *block);
extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern f32 func_802B72B0_de(f32 value);
extern void func_80400000_de(s32 n, f32 *ys, f32 *xs, f32 *out);

void func_804002D8_de(s32 count, Vec3 *points, f32 *weights, Spline *spline) {
    Vec3 delta;
    f32 *ys;
    f32 *xs;
    f32 *d2;
    SplineNode *nodes;
    f32 length;
    s32 i;

    ys = func_8025305C_de(count * 4);
    xs = func_8025305C_de(count * 4);
    d2 = func_8025305C_de(count * 4);
    nodes = spline->nodes;
    length = 0.0f;
    spline->nodeSize = 0x24;
    spline->count = count;
    if (count == 1) {
        spline->nodes[0].p.x = points->x;
        nodes->p.y = points->y;
        nodes->p.z = points->z;
        nodes->d2p.x = 0.0f;
        nodes->d2p.y = 0.0f;
        nodes->d2p.z = 0.0f;
        nodes->d2s = 0.0f;
        nodes->w = 0.0f;
        return;
    }
    for (i = 0; i < count; i++) {
        nodes[i].p.x = points[i].x;
        nodes[i].p.y = points[i].y;
        nodes[i].p.z = points[i].z;
        nodes[i].w = weights[i];
    }
    for (i = 0; i < count; i++) {
        nodes[i].s = length;
        if (i == count - 1) {
            break;
        }
        func_80271F68_de(&delta, &nodes[i].p, &nodes[i + 1].p);
        length += func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    }
    for (i = 0; i < count; i++) {
        ys[i] = nodes[i].p.x;
        xs[i] = nodes[i].s;
    }
    func_80400000_de(count, ys, xs, d2);
    for (i = 0; i < count; i++) {
        nodes[i].d2p.x = d2[i];
    }
    for (i = 0; i < count; i++) {
        ys[i] = nodes[i].p.y;
        xs[i] = nodes[i].s;
    }
    func_80400000_de(count, ys, xs, d2);
    for (i = 0; i < count; i++) {
        nodes[i].d2p.y = d2[i];
    }
    for (i = 0; i < count; i++) {
        ys[i] = nodes[i].p.z;
        xs[i] = nodes[i].s;
    }
    func_80400000_de(count, ys, xs, d2);
    for (i = 0; i < count; i++) {
        nodes[i].d2p.z = d2[i];
    }
    for (i = 0; i < count; i++) {
        ys[i] = nodes[i].s;
        xs[i] = nodes[i].w;
    }
    func_80400000_de(count, ys, xs, d2);
    for (i = 0; i < count; i++) {
        nodes[i].d2s = d2[i];
    }
    func_802547E4_de(ys);
    func_802547E4_de(xs);
    func_802547E4_de(d2);
}
