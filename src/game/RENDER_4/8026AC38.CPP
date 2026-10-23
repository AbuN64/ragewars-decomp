#include "include_asm.h"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/LOCALDECODERANGE.H"
#include "COMMON/FRUSTUM.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "RENDER/8028469C_11.H"
#include "SYSTEM/80296FF8_6.H"
#include "FX_2/80271B18.H"
#include "RENDER_4/8028FD2C_6.H"

extern Gfx *D_80110634;

extern char D_0044B180;

extern u32 D_800CC384;

extern s32 func_8026925C_de(s32);

s32 func_8028FDC8_de(s32 arg0, s32 arg1, s32 *arg2);

extern struct Shape_typemap_165 *func_80254480_de(s32, void *, s32);

void func_80253D10_de(s32 unused, struct Shape_typemap_165 **arg1, struct Shape_typemap_165 *arg2);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 D_80110620;

extern signed char D_800D1610[3];

extern char D_80145040;

extern void func_80270700_de(f32 *matrix, void *model);

extern void func_802732D0_de(f32 *matrix, CVector3 *position);

extern char *func_8022A414_de(void *players);

extern void func_80271F68_de(CVector3 *out, void *a, CVector3 *b);


void func_8026AC38_de(void) {
    Gfx *cmd;

    func_80295FF4_de();

    cmd = D_80110634++;
    gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_0044B180);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0);
    cmd = D_80110634++;
    gDPLoadSync(cmd);
    cmd = D_80110634++;
    gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 255, 1024);
    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0);
    cmd = D_80110634++;
    gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 124, 124);
    cmd = D_80110634++;
    gSPTexture(cmd, 2048, 2048, 0, 0, G_ON);
    cmd = D_80110634++;
    gDPSetTextureLUT(cmd, G_TT_NONE);
    cmd = D_80110634++;
    gSPGeometryMode(cmd, 0, D_800CC384 | 0x00260404);

    func_8026925C_de(0x1D);
}

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
    u32 value, a, b, c, n, block;
    s32 b2, c2;
    s32 vertexSlot, vertexOffset;
    const u32 vertexSegment = 0x02000000;
    const u32 matrixSegment = 0x01000000;
    s32 l, q, r;
    /* Expanded material records have the same size in both passes. */
    s32 materialBytes = 32;
    void *dstData;
    void *copySource4, *copySource5, *copySource3, *copySource2, *copySource1, *copySource0;
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
            size += materialBytes;
            input = func_8028FDB4_de(srcEntry, 1);
            {
                s32 countTag;
                commandSize = 0;
                while ((countTag = *input) != 0) {

                    if (countTag & 0x80) {
                        input += 2;
                        commandSize += 8;
                        if (*input & 0x80) input += 2;
                    } else {
                        countTag &= 0x60;
                        switch (countTag) {
                        case 0x20: input += 2; commandSize += 8; break;
                        case 0x40: input += 2; commandSize += 8; break;
                        case 0x60: input += 5; commandSize += 8; break;
                        }
                    }
                }
                size += (commandSize + 15) & ~7;
            }
            i++;
        } while (i < count);
        if (extra != 0) {
            func_8028FDC8_de(old, 3, &len3);
            size += len3;
            func_8028FDC8_de(old, 4, &len4);
            size += len4;
            func_8028FDC8_de(old, 5, &len5);
            size += len5;
        }
        if (sentinel != 0) size += 8;
        allocation = func_80254480_de(0, res, size);
        if (allocation != 0) {
            offset = (parts * 4 + 15) & ~7;
            old = (*res)->pack;
            dst = allocation->pack;
            dst->count = parts;
            dst->offsets[0] = offset;
            copySource0 = func_8028FDC8_de(old, 0, &len0);
            vertexCount = 0;
            vertices = func_8028FDB4_de(dst, 0);
            func_802BD3A0_de(vertices, copySource0, len0);
            offset += len0;
            dst->offsets[1] = offset;
            copySource1 = func_8028FDC8_de(old, 1, &len1);
            dstData = func_8028FDB4_de(dst, 1);
            func_802BD3A0_de(dstData, copySource1, len1);
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
                    copySource2 = func_8028FDB4_de(srcEntry, 0);
                    dstData = func_8028FDB4_de(dstEntry, 0);
                    func_80285570_de(dstData, copySource2);
                    block += materialBytes;
                    dstEntry->offsets[1] = block;
                    input = func_8028FDB4_de(srcEntry, 1);
                    output = func_8028FDB4_de(dstEntry, 1);
                    if ((tag = *input) != 0) {
                        do {
                            commandSize = tag & 0x60;
                            if (tag & 0x80) {
                                value = *input++ << 8;
                                value |= *input++;
                                a = (s32)value >> 10 & 0x1F;
                                b = (s32)value >> 5 & 0x1F;
                                c = value & 0x1F;
                                if (*input & 0x80) {
                                    {
                                        s32 hi = *input++;
                                        s32 lo = *input++;
                                        value = hi << 8;
                                        value |= lo;
                                        commandSize = (s32)value >> 10 & 31;
                                        b2 = (s32)value >> 5 & 31;
                                        c2 = value & 31;
                                        gSP2Triangles(output++, a, b, c, 0, commandSize, b2, c2, 0);
                                    }
                                } else {
                                    gSP1Triangle(output++, a, b, c, 0);
                                }
                            } else {
                                switch (commandSize) {
                                case 0x20:
                                    value = *input++ << 8;
                                    value |= *input++;
                                    vertexSlot = (s32)value >> 5 & 31;
                                    n = value & 0x1F;
                                    if (n == 0) n = 32;
                                    vertexOffset = vertexCount;
                                    /* Segment 2 holds vertex data, following its eight-byte header. */
                                    gSPVertex(output++, (vertexData + vertexOffset * 16 - vertices) + vertexSegment, n, vertexSlot);
                                    vertexCount += n;
                                    break;
                                case 0x40:
                                    input++;
                                    {
                                        s32 matrixIndex = *input++;
                                        /* Segment 1 holds 64-byte matrices. */
                                        gSPMatrix(output++, matrixSegment + matrixIndex * 64,
                                                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                                    }
                                    break;
                                case 0x60:
                                    vertexSlot = tag & 31;
                                    input++;
                                    value = *input++;
                                    l = *input++;
                                    q = *input++;
                                    r = *input++;
                                    value <<= 24;
                                    value |= l << 16;
                                    value |= q << 8;
                                    value |= r;
                                    gSPModifyVertex(output++, vertexSlot, G_MWO_POINT_ST, value);
                                    break;
                                }
                            }
                            tag = *input;
                        } while (tag != 0);
                    }
                    gSPEndDisplayList(output++);
                    dstData = func_8028FDB4_de(dstEntry, 1);
                    commandSize = (u8 *)output - (u8 *)dstData;
                    block += (commandSize + 7) & ~7;
                    total += block;
                    dstEntry->offsets[2] = block;
                    newList->offsets[i + 1] = total;
                    i++;
                } while (i < count);
            }
            offset += total;
            dst->offsets[3] = offset;
            if (extra != 0) {
                copySource3 = func_8028FDC8_de(old, 3, &len3);
                dstData = func_8028FDB4_de(dst, 3);
                func_802BD3A0_de(dstData, copySource3, len3);
                offset += len3;
                dst->offsets[4] = offset;
                copySource4 = func_8028FDC8_de(old, 4, &len4);
                dstData = func_8028FDB4_de(dst, 4);
                func_802BD3A0_de(dstData, copySource4, len4);
                offset += len4;
                dst->offsets[5] = offset;
                copySource5 = func_8028FDC8_de(old, 5, &len5);
                dstData = func_8028FDB4_de(dst, 5);
                func_802BD3A0_de(dstData, copySource5, len5);
                offset += len5;
                dst->offsets[6] = offset;
            }
            if (sentinel != 0) {
                Gfx *sentinelData = func_8028FDB4_de(dst, 3);
                offset += 8;
                sentinelData->words.w0 = -1;
                sentinelData->words.w1 = 0;
                dst->offsets[4] = offset;
            }
        }
        func_80253D10_de(0, res, allocation);
    }
}

typedef struct { s32 flagWord; char pad4[2]; u8 flags; } ModelMaterial;

s32 func_8026B504_de(void *model, void *lights, ModelMaterial *material) {
    CVector3 direction;
    CVector3 position;
    f32 matrix[4][4];

    if (D_80110620 != 0 && (material->flagWord & 0x8000)) {
        func_80270700_de((f32 *)matrix, model);
        func_802732D0_de((f32 *)matrix, &position);
        func_80271F68_de(&direction, func_8022A414_de(&D_80145040) + 0x6E8, &position);
        func_8027207C_de(&direction);
        {
            Gfx *cmd;
            Gfx *light;
            Gfx *ambient;

            D_800D1610[0] = direction.x * D_800C4668_de;
            D_800D1610[1] = direction.y * D_800C4668_de;
            D_800D1610[2] = direction.z * D_800C4668_de;
            cmd = D_80110634++;
            gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
            gSPMoveMem(D_80110634++, G_MV_LIGHT, 48, 16, (unsigned int)(D_800D1610 - 8));
            gSPMoveMem(D_80110634++, G_MV_LIGHT, 72, 16, (unsigned int)(D_800D1610 - 0x10));
        }
        return 1;
    }
    if (lights != 0) {
        gSPMoveWord(D_80110634++, G_MW_NUMLIGHT, 0, 0x18);
        gSPMoveMem(D_80110634++, G_MV_LIGHT, 48, 16, (unsigned int)((char *)lights + 8));
        gSPMoveMem(D_80110634++, G_MV_LIGHT, 72, 16, (unsigned int)lights);
    }
    return 0;
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"

typedef struct { char pad0[0x80]; s8 kind; u8 variant; char pad82[13]; u8 bonus; char pad90[4]; u8 enabled; } ModelState;
typedef struct { char pad0[0x5D8]; ModelState *state; char pad5DC[0xC10]; f32 glow; char pad11F0[0x3C]; u32 flags; } ModelActor;
extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;
extern s32 D_80146918, D_801468F4;
extern void func_80253BBC_de(s32, void **);
extern s32 func_80269A80_de(ModelMaterial *, s32);

void Render_DrawActorModelParts(void **resource, ModelActor *actor, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    s32 special = 0, bonus = 0, glow = 0, count, i;
    s32 *parts;
    void *header, *part;
    ModelMaterial *material;
    u8 mask, wanted;
    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011BDC0->commands) >> 3) < 3000) return;
    if (D_801462C8.counters.enabled && actor->state->kind == 11 && actor->state->enabled)
        special = D_801462C8.counters.timer > 0;
    if (actor->flags & 0x8000) special = 1;
    if (actor->glow > 0.0f) glow = 1;
    if (D_80146918 && actor->state->bonus == 1) bonus = 1;
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment) { gSPSegment(D_80110634++, 1, matrix); }
    else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (textures == 0) textures = func_8028FDB4_de(header, 0);
    gSPSegment(D_80110634++, 2, textures);
    parts = func_8028FDB4_de(header, 2);
    count = *parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) func_8026B504_de(matrix, lights, material);
        if (actor->state->kind == 18 && (!D_801468F4 || actor->state->bonus == 0)) {
            wanted = 0x28;
            if (actor->state->variant != 0) {
                wanted = 0x18;
                if (actor->state->variant == 1) wanted = 0x20;
            }
            mask = material->flags & 0x38;
            if (!(mask == wanted || (mask == 0x38 && special) || (mask == 0x30 && bonus))) {
                continue;
            }
        } else {
            mask = material->flags & 0x38;
            if (!((mask != 0x38 || special) && (mask != 0x30 || bonus) && (mask != 0x10 || glow))) {
                continue;
            }
        }
        if (func_80269A80_de(material, pass)) {
            header = func_8028FDB4_de(part, 1);
            gSPDisplayList(D_80110634++, header);
        }
    }
}
#else
INCLUDE_ASM("span_1000", Render_DrawActorModelParts);
#endif
