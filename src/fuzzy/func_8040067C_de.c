#include "types.h"

typedef struct { s32 stride, count; char data[1]; } SplineSource;
typedef struct { s32 count; } SplineTable;
typedef struct { void *data; } SplineResource;
extern s32 func_80285180_de(void *, s32);
extern void *func_8028FDB4_de(void *, s32);
extern s32 func_8028FEB8_de(void *);
extern SplineResource *func_80254480_de(s32, void *, s32);
extern void func_802610A8_de(void *, s32);
extern void *func_802610F0_de(void *, void *, s32);
extern void func_804002D8_de(s32, void *, void *, void *);
extern void func_80253D10_de(s32, void *, void *);

void func_8040067C_de(s32 unused, SplineResource **handle) {
    void *source, *a, *b, *c, *part, *pack, *table, *dest, *extra;
    SplineTable *parts;
    SplineSource *p, *q, *r, *s;
    SplineResource *output;
    s32 count, i, size, sa, sb, sc, np, nr;
    void *dp, *dr;
    if (!func_80285180_de(handle, 1)) return;
    source = (*handle)->data;
    parts = func_8028FDB4_de(source, 0);
    a = func_8028FDB4_de(source, 1);
    b = func_8028FDB4_de(source, 2);
    c = func_8028FDB4_de(source, 3);
    count = parts->count;
    size = (count * 4 + 15) & ~7;
    for (i = 0; i < parts->count; i++) {
        part = func_8028FDB4_de(parts, i);
        p = func_8028FDB4_de(part, 0);
        r = func_8028FDB4_de(part, 2);
        size += (r->count + p->count) * 36 + 48;
    }
    sc = func_8028FEB8_de(c);
    sa = func_8028FEB8_de(a);
    sb = func_8028FEB8_de(b);
    output = func_80254480_de(0, handle, size + sa + sb + sc + 24);
    if (output == 0) return;
    pack = output->data;
    func_802610A8_de(pack, 4);
    table = func_802610F0_de(pack, 0, size);
    func_802610F0_de(pack, a, sa);
    func_802610F0_de(pack, b, sb);
    func_802610F0_de(pack, c, sc);
    func_802610A8_de(table, count);
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        p = func_8028FDB4_de(part, 0);
        r = func_8028FDB4_de(part, 2);
        dest = func_802610F0_de(table, 0, (r->count + p->count) * 36 + 48);
        func_802610A8_de(dest, 3);
        p = func_8028FDB4_de(part, 0);
        q = func_8028FDB4_de(part, 1);
        r = func_8028FDB4_de(part, 2);
        s = func_8028FDB4_de(part, 3);
        extra = func_8028FDB4_de(part, 4);
        np = p->count;
        nr = r->count;
        dp = func_802610F0_de(dest, 0, np * 36 + 8);
        dr = func_802610F0_de(dest, 0, nr * 36 + 8);
        func_802610F0_de(dest, extra, 8);
        func_804002D8_de(np, p->data, q->data, dp);
        func_804002D8_de(nr, r->data, s->data, dr);
    }
    func_80253D10_de(0, handle, output);
}
