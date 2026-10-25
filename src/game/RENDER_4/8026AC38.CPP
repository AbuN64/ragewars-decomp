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

extern s32 Render_SetModePreset(s32);

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

extern void Particle_SubtractVectors(CVector3 *out, void *a, CVector3 *b);


void func_8026AC38_de(void) {
    Gfx *cmd;

    System_ResetTextureCache();

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

    Render_SetModePreset(0x1D);
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
        oldList = Render_GetPackSection(old, 2);
        count = oldList->count;
        i = 0;
        size += (count * 4 + 15) & ~7;
        if (count > 0) do {
            srcEntry = Render_GetPackSection(oldList, i);
            size += 16;
            size += materialBytes;
            input = Render_GetPackSection(srcEntry, 1);
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
            vertices = Render_GetPackSection(dst, 0);
            func_802BD3A0_de(vertices, copySource0, len0);
            offset += len0;
            dst->offsets[1] = offset;
            copySource1 = func_8028FDC8_de(old, 1, &len1);
            dstData = Render_GetPackSection(dst, 1);
            func_802BD3A0_de(dstData, copySource1, len1);
            offset += len1;
            dst->offsets[2] = offset;
            oldList = Render_GetPackSection(old, 2);
            newList = Render_GetPackSection(dst, 2);
            count = oldList->count;
            i = 0;
            newList->count = count;
            total = (count * 4 + 15) & ~7;
            newList->offsets[0] = total;
            if (count > 0) {
                vertexData = vertices + 8;
                do {
                    srcEntry = Render_GetPackSection(oldList, i);
                    dstEntry = Render_GetPackSection(newList, i);
                    block = (srcEntry->count * 4 + 15) & ~7;
                    dstEntry->count = srcEntry->count;
                    dstEntry->offsets[0] = block;
                    copySource2 = Render_GetPackSection(srcEntry, 0);
                    dstData = Render_GetPackSection(dstEntry, 0);
                    func_80285570_de(dstData, copySource2);
                    block += materialBytes;
                    dstEntry->offsets[1] = block;
                    input = Render_GetPackSection(srcEntry, 1);
                    output = Render_GetPackSection(dstEntry, 1);
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
                    dstData = Render_GetPackSection(dstEntry, 1);
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
                dstData = Render_GetPackSection(dst, 3);
                func_802BD3A0_de(dstData, copySource3, len3);
                offset += len3;
                dst->offsets[4] = offset;
                copySource4 = func_8028FDC8_de(old, 4, &len4);
                dstData = Render_GetPackSection(dst, 4);
                func_802BD3A0_de(dstData, copySource4, len4);
                offset += len4;
                dst->offsets[5] = offset;
                copySource5 = func_8028FDC8_de(old, 5, &len5);
                dstData = Render_GetPackSection(dst, 5);
                func_802BD3A0_de(dstData, copySource5, len5);
                offset += len5;
                dst->offsets[6] = offset;
            }
            if (sentinel != 0) {
                Gfx *sentinelData = Render_GetPackSection(dst, 3);
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
        Particle_SubtractVectors(&direction, func_8022A414_de(&D_80145040) + 0x6E8, &position);
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
/* 56/211 aligned edits; remaining: callee-saved register order (segment/i, hide, count/parts) and the 0xDE000000 constant kept in fp. */
#include "COMMON/GAME_SESSION.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;
extern CGameStatus D_801468A0;
extern void func_80253BBC_de(s32 heap, void **resource);
extern s32 func_80269A80_de(void *material, s32 pass);
/* Draws an actor model's parts, choosing each part by the 0x38 bits of its material byte 6: on the special
 * character 0x12 the part must equal the bits for its variant (or be a fade/bonus part whose flag is set),
 * otherwise the 0x38/0x30/0x10 groups are drawn only when the matching flag (fade, bonus, glow) is set. */
void Render_DrawActorModelParts(void **resource, struct Player *owner, void *matrix, s32 segment, Shared_ParticleLighting *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    MeshMaterial *material;
    s32 count;
    s32 i;
    s32 hide = 0;
    s32 bonus = 0;
    s32 glow = 0;
    CGameStatus *settings;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    settings = &D_801468A0;
    if (settings->enabled != 0) {
        AiProfile *state = owner->profile;
        if (state->character == 0xB && state->enabled != 0) {
            hide = 0 < settings->timer;
        }
    }
    if (owner->reactionFlags & 0x8000) {
        hide = 1;
    }
    if (0.0f < owner->glow) {
        glow = 1;
    }
    if (D_801468A0.m_bCTFOn != 0 && owner->profile->bonus == 1) {
        bonus = 1;
    }
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment != 0) {
        gSPSegment(D_80110634++, 1, matrix);
    } else {
        gSPMatrix(D_80110634++, matrix, G_MTX_LOAD);
    }
    base = textures;
    if (base == 0) {
        base = Render_GetPackSection(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = Render_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        AiProfile *state;
        u32 bits;
        part = Render_GetPackSection(parts, i);
        material = Render_GetPackSection(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        state = owner->profile;
        if (state->character == 0x12 && (D_801468A0.m_bFragTagOn == 0 || state->bonus == 0)) {
            u32 wanted = 0x28;
            if (state->variant != 0) {
                wanted = 0x18;
                if (state->variant == 1) {
                    wanted = 0x20;
                }
            }
            bits = material->mode & 0x38;
            if (bits != wanted && !(bits == 0x38 && hide != 0) && !(bits == 0x30 && bonus != 0)) {
                continue;
            }
        } else {
            bits = material->mode & 0x38;
            if (bits == 0x38 && hide == 0) continue;
            if (bits == 0x30 && bonus == 0) continue;
            if (bits == 0x10 && glow == 0) continue;
        }
        if (func_80269A80_de(material, pass) != 0) {
            void *list = Render_GetPackSection(part, 1);
            Gfx *cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
#else
INCLUDE_ASM("span_1000", Render_DrawActorModelParts);
#endif
