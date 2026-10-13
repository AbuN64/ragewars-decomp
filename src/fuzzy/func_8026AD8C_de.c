#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802609CC.h"
extern s32 func_80285180_de(void *, s32);
extern void *func_8028FDC8_de(void *, s32, s32 *);
extern void *func_8028FDB4_de(void *, s32);
extern struct Shape_typemap_165 *func_80254480_de(s32, void *, s32);
extern void func_80253D10_de(s32, void *, void *);
extern void func_80285570_de(void *, void *);
extern void *func_802BD3A0_de(void *, const void *, s32);
/* Expand packed geometry commands into display lists while rebuilding resource offsets. */
void func_8026AD8C_de(s32 unused, struct Shape_typemap_165 **res, s32 extra, s32 sentinel) {
    s32 len0, len1, len3, len4, len5;
    struct Shape_typemap_165 *allocation;
    struct Pack *old;
    struct Pack *oldList;
    struct Pack *newList;
    u8 *vertices;
    u8 *vertexData;
    s32 vertexCount;
    s32 parts, size, count, i, commandSize, offset, total;
    struct Pack *dst;
    struct Pack *srcEntry, *dstEntry;
    u8 *input;
    Gfx *output;
    s32 tag;
    u32 value, a, b, c, n, block, address;
    s32 a2, b2, c2;
    s32 kind;
    s32 h, l, q, r;
    void *srcData, *dstData;
    if (func_80285180_de(res, 1) != 0) {
        parts = 6;
        if (extra == 0) {
            parts = 3;
            if (sentinel != 0) parts = 4;
        }
        size = (parts * 4 + 15) & ~7;
        old = (*res)->pack;
        func_8028FDC8_de(old, 0, &len0);
        size += len0;
        func_8028FDC8_de(old, 1, &len1);
        size += len1;
        oldList = func_8028FDB4_de(old, 2);
        count = oldList->count;
        i = 0;
        size += (count * 4 + 15) & ~7;
        if (count > 0) do {
            srcEntry = func_8028FDB4_de(oldList, i);
            size += 16;
            size += 32;
            input = func_8028FDB4_de(srcEntry, 1);
            commandSize = 0;
            while ((tag = *input) != 0) {
                
                if (tag & 0x80) {
                    input += 2;
                    commandSize += 8;
                    if (*input & 0x80) input += 2;
                } else {
                    tag &= 0x60;
                    switch (tag) {
                    case 0x20: input += 2; commandSize += 8; break;
                    case 0x40: input += 2; commandSize += 8; break;
                    case 0x60: input += 5; commandSize += 8; break;
                    }
                }
            }
            size += (commandSize + 15) & ~7;
            i++;
        } while (i < count);
        if (extra != 0) {
            func_8028FDC8_de(old, 3, &len3); size += len3;
            func_8028FDC8_de(old, 4, &len4); size += len4;
            func_8028FDC8_de(old, 5, &len5); size += len5;
        }
        if (sentinel != 0) size += 8;
        allocation = func_80254480_de(0, res, size);
        if (allocation != 0) {
            offset = (parts * 4 + 15) & ~7;
            old = (*res)->pack;
            dst = allocation->pack;
            vertexCount = 0;
            dst->count = parts;
            dst->offsets[0] = offset;
            srcData = func_8028FDC8_de(old, 0, &len0);
            vertices = func_8028FDB4_de(dst, 0);
            func_802BD3A0_de(vertices, srcData, len0);
            offset += len0;
            dst->offsets[1] = offset;
            srcData = func_8028FDC8_de(old, 1, &len1);
            dstData = func_8028FDB4_de(dst, 1);
            func_802BD3A0_de(dstData, srcData, len1);
            offset += len1;
            dst->offsets[2] = offset;
            oldList = func_8028FDB4_de(old, 2);
            newList = func_8028FDB4_de(dst, 2);
            count = oldList->count;
            i = 0;
            newList->count = count;
            total = (count * 4 + 15) & ~7;
            newList->offsets[0] = total;
            if (count > 0) {
                vertexData = vertices + 8;
                do {
                    srcEntry = func_8028FDB4_de(oldList, i);
                    dstEntry = func_8028FDB4_de(newList, i);
                    block = (srcEntry->count * 4 + 15) & ~7;
                    dstEntry->count = srcEntry->count;
                    dstEntry->offsets[0] = block;
                    srcData = func_8028FDB4_de(srcEntry, 0);
                    dstData = func_8028FDB4_de(dstEntry, 0);
                    func_80285570_de(dstData, srcData);
                    block += 32;
                    dstEntry->offsets[1] = block;
                    input = func_8028FDB4_de(srcEntry, 1);
                    output = func_8028FDB4_de(dstEntry, 1);
                    if ((tag = *input) != 0) {
                        do {
                            kind = tag & 0x60;
                            if (tag & 0x80) {
                                h = *input++;
                                l = *input++;
                                value = (h << 8) | l;
                                a = (s32)value >> 10 & 0x1F;
                                b = (s32)value >> 5 & 0x1F;
                                c = value & 0x1F;
                                if (*input & 0x80) {
                                    h = *input++;
                                    l = *input++;
                                    value = (h << 8) | l;
                                    a2 = (s32)value >> 10 & 31;
                                    b2 = (s32)value >> 5 & 31;
                                    c2 = value & 31;
                                    gSP2Triangles(output++, a, b, c, 0, a2, b2, c2, 0);
                                } else {
                                    gSP1Triangle(output++, a, b, c, 0);
                                }
                            } else {
                                switch (kind) {
                                case 0x20:
                                    h = *input++; l = *input++;
                                    value = (h << 8) | l;
                                    kind = (s32)value >> 5 & 31;
                                    n = value & 0x1F;
                                    if (n == 0) n = 32;
                                    a = vertexCount * 16;
                                    vertexCount += n;
                                    /* Segment 2 holds vertex data, following its eight-byte header. */
                                    address = (vertexData + a - vertices) + 0x02000000;
                                    gSPVertex(output++, address, n, kind);
                                    break;
                                case 0x40:
                                    h = *input++; l = *input++;
                                    /* Segment 1 holds 64-byte matrices. */
                                    address = l * 64 + 0x01000000;
                                    gSPMatrix(output++, address, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_PUSH);
                                    break;
                                case 0x60:
                                    h = *input++; l = *input++; q = *input++; r = *input++;
                                    value = *input++;
                                    gSPModifyVertex(output++, tag & 31, G_MWO_POINT_ST,
                                                    (l << 24) | (q << 16) | (r << 8) | value);
                                    break;
                                }
                            }
                            tag = *input;
                        } while (tag != 0);
                    }
                    gSPEndDisplayList(output);
                    dstData = func_8028FDB4_de(dstEntry, 1);
                    commandSize = (u8 *)output - (u8 *)dstData;
                    block += (commandSize + 15) & ~7;
                    total += block;
                    dstEntry->offsets[2] = block;
                    newList->offsets[i + 1] = total;
                    i++;
                } while (i < count);
            }
            offset += total;
            dst->offsets[3] = offset;
            if (extra != 0) {
                srcData = func_8028FDC8_de(old, 3, &len3); dstData = func_8028FDB4_de(dst, 3);
                func_802BD3A0_de(dstData, srcData, len3);
                dst->offsets[4] = offset + len3;
                srcData = func_8028FDC8_de(old, 4, &len4); dstData = func_8028FDB4_de(dst, 4);
                func_802BD3A0_de(dstData, srcData, len4);
                offset += len3 + len4;
                dst->offsets[5] = offset;
                srcData = func_8028FDC8_de(old, 5, &len5); dstData = func_8028FDB4_de(dst, 5);
                func_802BD3A0_de(dstData, srcData, len5);
                offset += len5;
                dst->offsets[6] = offset;
            }
            if (sentinel != 0) {
                output = func_8028FDB4_de(dst, 3);
                output->words.w0 = -1; output->words.w1 = 0;
                dst->offsets[4] = offset + 8;
            }
        }
        func_80253D10_de(0, res, allocation);
    }
}
