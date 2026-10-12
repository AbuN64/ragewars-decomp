#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802609CC.h"

s32 func_80285180_de(void **, s32);
char *func_8028FDB4_de(s32 *, s32);
struct Shape_typemap_165 *func_80254480_de(s32, void *, s32);
void *func_802BD3A0_de(void *, const void *, s32);
void func_80285570_de(void *, void *);
void func_80253D10_de(s32, struct Shape_typemap_165 **, struct Shape_typemap_165 *);

static void *model_section(struct Pack *pack, s32 index, s32 *bytes) {
    *bytes = pack->offsets[index + 1] - pack->offsets[index];
    return func_8028FDB4_de(&pack->count, index);
}

/* Expand packed mesh commands and install the new resource handle. */
void func_8026AD8C_de(s32 unused, struct Shape_typemap_165 **handle,
                     s32 includeExtra, s32 includeSentinel) {
    struct Pack *source, *sourceMeshes, *destination, *destinationMeshes;
    struct Pack *sourceMesh, *destinationMesh;
    struct Shape_typemap_165 *allocation;
    void *raw;
    s32 sections, bytes[6], total, i, j, commandBytes;
    s32 offset, meshOffset, meshHeader, meshBytes, vertexIndex;
    u8 *input;
    Gfx *output, *firstCommand;
    u32 tag, value, value2, count, a, b, c, address;

    raw = handle;
    if (!func_80285180_de(raw, 1)) return;
    sections = includeExtra ? 6 : (includeSentinel ? 4 : 3);
    source = (*handle)->pack;
    model_section(source, 0, &bytes[0]);
    model_section(source, 1, &bytes[1]);
    raw = func_8028FDB4_de(&source->count, 2);
    sourceMeshes = raw;
    total = ((sections * 4 + 15) & ~7) + bytes[0] + bytes[1]
            + ((sourceMeshes->count * 4 + 15) & ~7);
    for (i = 0; i < sourceMeshes->count; i++) {
        raw = func_8028FDB4_de(&sourceMeshes->count, i);
        sourceMesh = raw;
        raw = func_8028FDB4_de(&sourceMesh->count, 1);
        input = raw;
        commandBytes = 0;
        while (*input) {
            tag = *input;
            if (tag & 0x80) {
                input += 2;
                if (*input & 0x80) input += 2;
            } else if ((tag & 0x60) == 0x60) input += 5;
            else if ((tag & 0x60) == 0x40 || (tag & 0x60) == 0x20) input += 2;
            commandBytes += 8;
        }
        total += 0x30 + ((commandBytes + 15) & ~7);
    }
    if (includeExtra) {
        for (j = 3; j < 6; j++) {
            model_section(source, j, &bytes[j]);
            total += bytes[j];
        }
    }
    if (includeSentinel) total += 8;
    allocation = func_80254480_de(0, handle, total);
    if (allocation) {
        source = (*handle)->pack;
        raw = func_8028FDB4_de(&source->count, 2);
        sourceMeshes = raw;
        destination = allocation->pack;
        destination->count = sections;
        offset = (sections * 4 + 15) & ~7;
        destination->offsets[0] = offset;
        raw = model_section(source, 0, &bytes[0]);
        func_802BD3A0_de(func_8028FDB4_de(&destination->count, 0), raw, bytes[0]);
        offset += bytes[0];
        destination->offsets[1] = offset;
        raw = model_section(source, 1, &bytes[1]);
        func_802BD3A0_de(func_8028FDB4_de(&destination->count, 1), raw, bytes[1]);
        offset += bytes[1];
        destination->offsets[2] = offset;
        raw = func_8028FDB4_de(&destination->count, 2);
        destinationMeshes = raw;
        destinationMeshes->count = sourceMeshes->count;
        meshOffset = (sourceMeshes->count * 4 + 15) & ~7;
        destinationMeshes->offsets[0] = meshOffset;
        vertexIndex = 0;
        for (i = 0; i < sourceMeshes->count; i++) {
            raw = func_8028FDB4_de(&sourceMeshes->count, i);
            sourceMesh = raw;
            raw = func_8028FDB4_de(&destinationMeshes->count, i);
            destinationMesh = raw;
            destinationMesh->count = sourceMesh->count;
            meshHeader = (sourceMesh->count * 4 + 15) & ~7;
            destinationMesh->offsets[0] = meshHeader;
            func_80285570_de(func_8028FDB4_de(&destinationMesh->count, 0),
                            func_8028FDB4_de(&sourceMesh->count, 0));
            destinationMesh->offsets[1] = meshHeader + 0x20;
            raw = func_8028FDB4_de(&sourceMesh->count, 1);
            input = raw;
            raw = func_8028FDB4_de(&destinationMesh->count, 1);
            firstCommand = output = raw;
            while (*input) {
                tag = *input;
                if (tag & 0x80) {
                    value = (input[0] << 8) | input[1]; input += 2;
                    a = (value >> 10) & 31; b = (value >> 5) & 31; c = value & 31;
                    if (*input & 0x80) {
                        value2 = (input[0] << 8) | input[1]; input += 2;
                        gSP2Triangles(output, a, b, c, 0,
                                      (value2 >> 10) & 31, (value2 >> 5) & 31, value2 & 31, 0);
                    } else {
                        gSP1Triangle(output, a, b, c, 0);
                    }
                } else switch (tag & 0x60) {
                case 0x20:
                    value = (input[0] << 8) | input[1]; input += 2;
                    count = value & 31; if (!count) count = 32;
                    /* Vertex segment 2 begins with an eight-byte resource prefix. */
                    address = 0x02000008 + vertexIndex * 16;
                    gSPVertex(output, address, count, (value >> 5) & 31);
                    vertexIndex += count;
                    break;
                case 0x40:
                    /* Matrix segment 1 stores 64-byte matrices. */
                    address = 0x01000000 + (input[1] << 6);
                    gSPMatrix(output, address,
                              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_PUSH);
                    input += 2; break;
                case 0x60:
                    gSPModifyVertex(output, tag & 31, G_MWO_POINT_ST,
                                    (input[1] << 24) | (input[2] << 16) | (input[3] << 8) | input[4]);
                    input += 5; break;
                }
                output++;
            }
            gSPEndDisplayList(output);
            commandBytes = (output + 1 - firstCommand) * sizeof(Gfx);
            meshBytes = meshHeader + 0x20 + ((commandBytes + 7) & ~7);
            destinationMesh->offsets[2] = meshBytes;
            meshOffset += meshBytes;
            destinationMeshes->offsets[i + 1] = meshOffset;
        }
        offset += meshOffset;
        destination->offsets[3] = offset;
        if (includeExtra) {
            for (j = 3; j < 6; j++) {
                raw = model_section(source, j, &bytes[j]);
                func_802BD3A0_de(func_8028FDB4_de(&destination->count, j), raw, bytes[j]);
                offset += bytes[j]; destination->offsets[j + 1] = offset;
            }
        }
        if (includeSentinel) {
            raw = func_8028FDB4_de(&destination->count, 3);
            output = raw;
            output->words.w0 = -1; output->words.w1 = 0;
            destination->offsets[4] = offset + 8;
        }
    }
    func_80253D10_de(0, handle, allocation);
}
