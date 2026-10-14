#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Tears down the UI resource set: releases eligible entries, closes active
   subsystems, frees each nested chunk allocation and the shared tables, then
   clears the complete state record. */




extern struct State_func_804101BC_de D_801539B0;
extern s16 D_80153C0C, D_80153C20;
extern struct EntryRecAt8V1 *D_80153C10;
extern struct ResourceRecAt6 *D_8014D988;
extern struct ChunkRecAt48C *D_80153C28;
extern void *D_8014D98C[];
extern void func_80411AF0_de(s32), func_8040F580_de(void), func_802A0EB0_de(void *);
extern void func_804118E4_de(s32), func_80410E1C_de(s32), func_80411D18_de(void);
extern void func_802547E4_de(void *), func_802A0748_de(void *, s32, s32);

void func_804101BC_de(void) {
    s32 i;
    s32 invalid;
    s32 i_chunks;
    s32 offset_chunks;
    s32 offset;
    struct ResourceRecAt6 *resource;
    struct ChunkRecAt48C *chunk;
    void **block;
    void **tables;
    void **first;
    void **second;
    struct State_func_804101BC_de *state;
    i = 0;
    if (D_80153C0C > 0) {
        invalid = -1;
        offset = 0;
        do {
            if (((struct EntryRecAt8V1 *)(offset + (s32)D_80153C10))->flags & 1) {
                resource = D_8014D988 + i;
                if (resource->id != invalid && resource->retained == 0) {
                    func_80411AF0_de(i);
                }
            }
            offset += 0x1C;
        } while (++i < D_80153C0C);
    }
    func_8040F580_de();
    state = &D_801539B0;
    if (state->active) func_802A0EB0_de(state->active);
    func_804118E4_de(1);
    func_80410E1C_de(1);
    if (state->resource) func_802547E4_de(state->resource);
    i_chunks = 0;
    func_80411D18_de();
    offset_chunks = 0;
    if (state->count > 0) {
        do {
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional;
            if (block) {
                func_802547E4_de(*block);
                func_802547E4_de(((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional);
            }
            i_chunks++;
            func_802547E4_de(*((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary);
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary;
            offset_chunks += 0x49C;
            func_802547E4_de(block);
        } while (i_chunks < D_80153C20);
    }
    tables = D_8014D98C;
    if (tables[0]) func_802547E4_de(tables[0]);
    first = tables + 3;
    if (tables[3]) func_802547E4_de(tables[3]);
    second = tables + 2;
    if (tables[2]) func_802547E4_de(tables[2]);
    if (tables[13]) func_802547E4_de(tables[13]);
    if (tables[-1]) func_802547E4_de(tables[-1]);
    if (tables[10]) func_802547E4_de(tables[10]);
    if (tables[11]) func_802547E4_de(tables[11]);
    if (tables[-2]) func_802547E4_de(tables[-2]);
    if (tables[12]) func_802547E4_de(tables[12]);
    if (tables[7]) func_802547E4_de(tables[7]);
    if (first[5]) func_802547E4_de(first[5]);
    if (second[3]) func_802547E4_de(second[3]);
    func_802A0748_de((char *)tables - 0x26C, 0, 0x2A8);
}
