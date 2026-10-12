#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802609CC.h"
#include "span_16E000/code_80400000.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8044DA54_de_closed.h"
extern struct Shape_typemap_165 *func_80254480_de(s32,void *,s32);
extern void func_804002D8_de(s32,Vec3 *,f32 *,Spline *);
extern void func_80253D10_de(s32,struct Shape_typemap_165 **,struct Shape_typemap_165 *);
/* The pack append API tests the second ABI word for a nonzero preparation flag. */
static inline char *packAppend(Pack *pack,void *prepare,s32 size) { return func_802610F0_de(pack,(s32)prepare,size); }
static inline s32 splineRecordSize(s32 left,s32 right) { s32 a=left*9,b=right*9; return (b+a)*4+48; }
void func_8040067C_de(s32 unused, struct Shape_typemap_165 **handle) {
    struct Shape_typemap_165 *output;
    void *source, *a, *b, *c, *part, *extra;
    Pack *pack, *dest;
    SplineTable *parts;
    Pack *table;
    SplineSourceCursor p,q,r,s;
    s32 count, i, size, sa, sb, sc, np, nr, byteP, byteR;
    void *dp, *dr;
    if (!func_80285180_de((void **)handle, 1)) return;
    source = (*handle)->pack;
    parts = func_8028FDB4_de(source, 0);
    a = func_8028FDB4_de(source, 1);
    b = func_8028FDB4_de(source, 2);
    c = func_8028FDB4_de(source, 3);
    count = parts->count;
    size = (count * 4 + 15) & ~7;
    for (i = 0; i < parts->count; i++) {
        SplineSource *firstP,*firstR;
        void *firstPart;
        s32 byteP,byteR;
        firstPart = func_8028FDB4_de(parts, i);
        firstP = func_8028FDB4_de(firstPart, 0);
        firstR = func_8028FDB4_de(firstPart, 2);
        size += splineRecordSize(firstP->count,firstR->count);
    }
    sc = func_8028FEB8_de(c);
    sa = func_8028FEB8_de(a);
    sb = func_8028FEB8_de(b);
    output = func_80254480_de(0, handle, size + sa + sb + sc + 24);
    if (output == 0) return;
    pack = output->pack;
    func_802610A8_de(pack, 4);
    table = (void *)packAppend(pack, 0, size);
    packAppend(pack, a, sa);
    packAppend(pack, b, sb);
    packAppend(pack, c, sc);
    func_802610A8_de(table, count);
    for (i = 0; i < count; i++) {
        s32 byteP,byteR;
        SplineSource *sizeP,*sizeR;
        part = func_8028FDB4_de(parts, i);
        sizeP = func_8028FDB4_de(part, 0);
        sizeR = func_8028FDB4_de(part, 2);
        byteP = sizeP->count * 9;
        byteR = sizeR->count * 9;
        dest = (void *)packAppend(table, 0, (byteR + byteP)*4 + 48);
        func_802610A8_de(dest, 3);
        p.header = func_8028FDB4_de(part, 0);
        q.header = func_8028FDB4_de(part, 1);
        r.header = func_8028FDB4_de(part, 2);
        s.header = func_8028FDB4_de(part, 3);
        extra = func_8028FDB4_de(part, 4);
        np = p.header->count;
        nr = r.header->count;
        { s32 pointBytes,otherBytes;
        pointBytes = np * 36 + 8;
        otherBytes = nr * 36 + 8;
        dp = packAppend(dest, 0, pointBytes);
        dr = packAppend(dest, 0, otherBytes);
        }
        p.points = p.header->points;
        q.weights = q.header->weights;
        r.points = r.header->points;
        s.weights = s.header->weights;
        packAppend(dest, extra, 8);
        func_804002D8_de(np, p.points, q.weights, dp);
        func_804002D8_de(nr, r.points, s.weights, dr);
    }
    func_80253D10_de(0, handle, output);
}
