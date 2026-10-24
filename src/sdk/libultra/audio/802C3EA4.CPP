#include "include_asm.h"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "sdk/AUDIO/802C3EA4.H"

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "COMMON/LLDIVRESULT.H"
extern u16 D_800D5350[];
extern u16 D_800D5374[];
extern u16 D_8014AE00;

typedef struct {
    u8 pad0[0x14];
    u16 *cursor;
} PackedBitStream;
#define STREAM(s) ((PackedBitStream *)(s))
u16 Audio_ReadPackedSamples(u16 *out, u16 width, s32 count, s32 signExtend, void *stream) {
    s16 i;
    u16 *bitsLeft = &D_800D54B8;
    u16 *word = &D_8014AE00;
    u16 *masks = D_800D5350;
    u16 *signs = D_800D5374;
    u16 *p;
    u16 v;
    if (*bitsLeft == 0) {
        p = STREAM(stream)->cursor;
        v = *p;
        STREAM(stream)->cursor = p + 1;
        *bitsLeft = 16;
        *word = v;
    }
    i = 0;
    if (count != 0) {
        do {
            u16 bits = *bitsLeft;
            if (bits < width) {
                u16 need = width - bits;
                out[i] = (*word & masks[bits]) << need;
                p = STREAM(stream)->cursor;
                v = *p;
                STREAM(stream)->cursor = p + 1;
                *word = v;
                out[i] |= ((s32)v >> (16 - need)) & masks[need];
                if ((s16)signExtend != 0 && ((s16)out[i] & signs[width])) {
                    out[i] |= ~masks[width];
                }
                *bitsLeft = 16 - need;
            } else {
                u16 r = (*word >> (bits - width)) & masks[width];
                out[i] = r;
                if ((s16)signExtend != 0 && ((s16)r & signs[width])) {
                    out[i] = r | ~masks[width];
                }
                *bitsLeft = *bitsLeft - width;
            }
            i++;
        } while (i < count);
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", Audio_ReadPackedSamples);
#endif

s32 func_802BEF84_de(DecodeBlock *arg0, u16 *arg1, s16 arg2,
                    u16 *arg3, void *arg4) {
    u16 node;
    s16 block, output;
    DecodeTable *table;
    DecodeNode *tree;
    u16 value;
    s32 mask, high;
    u16 topbit;
    s16 j;
    s32 dictOffset;
    u16 next;
    u16 *bits, *available;
    DecodePhrase *phrase;
    u16 *out;

    node = 0;
    block = 0;
    *arg3 = 0;
    table = arg0->table;
    tree = table->tree;
    output = 0;
    if (arg2 > 0) {
        available = &D_800D54BC;
        bits = &D_800D54BA;
        do {
            if (*available != 0) {
                (*available)--;
                topbit = *bits & 0x8000;
                *bits <<= 1;
                if (topbit) {
                    mask = tree[(s16)node].second;
                } else {
                    mask = tree[(s16)node].first;
                }
                if (tree[(s16)mask].first == 0x800) {
                    value = tree[(s16)mask].second;
                    mask = value & 0xF00;
                    node = 0;
                    if (mask == 0 || mask == 0xF00) {
                        arg1[(s16)output] = value;
                        output++;
                    } else if ((s16)value == 0x900) {
                        value = *bits;
                        if (Audio_ReadPackedSamples(bits, table->width, 1, 0, arg4) == 0) {
                            return -1;
                        }
                        mask = (s16)output;
                        output++;
                        high = *bits;
                        next = D_800D54BC;
                        *bits = high << (16 - next);
                        arg1[(s16)mask] = value | (high >> next);
                    } else if (mask == 0xA00) {
                        j = 0;
                        dictOffset = (value & 0xFF) * sizeof(DecodePhrase);
                        out = (arg1 + ((s16)output + 1)) - 1;
                        phrase = (DecodePhrase *)(dictOffset +
                                   (u8 *)(table->phrases + 1)) - 1;
                        while ((s16)j < phrase->count) {
                            out[(s16)j] = phrase->samples[(s16)j].value;
                            j++;
                        }
                        output += (s32)((u32)j << 16) >> 16;
                    } else if (mask == 0xB00) {
                        while ((s16)output < arg2) {
                            arg1[(s16)output++] = 0;
                        }
                        while (arg2 >= arg0[(s16)block].start +
                                       arg0[(s16)block].length) {
                            block++;
                            (*arg3)++;
                        }
                        return arg2;
                    }
                    if ((s16)output >= arg0[(s16)block].start +
                                       arg0[(s16)block].length) {
                        block++;
                        (*arg3)++;
                        table = arg0[(s16)block].table;
                        tree = table->tree;
                    }
                } else {
                    node = mask;
                }
            } else {
                if (Audio_ReadPackedSamples(&D_800D54BA, 16, 1, 0, arg4) == 0) {
                    return -1;
                }
                *available += 16;
            }
        } while ((s16)output < arg2);
    }
    return (s16)output;
}

#ifdef NON_MATCHING
/* 12/99 aligned word edits remain: early error return and temporary register allocation. */
#include "TYPES.H"
extern DecodeBlock D_800D5564[];
extern s16 D_800D54BE;
extern u16 D_8014AE10[16];
s32 Audio_DecodeFrame(DecodeState *stream) {
    DecodeBlock *block = D_800D5564;
    s16 *flag = &D_800D54BE;
    s16 done[4];
    s16 i;
    s32 result;
    if (*flag == 0) {
        u16 *table;
        *flag = 1;
        if ((s16)Audio_ReadPackedSamples(stream->frame, 6, 16, 0, stream) <= 0) {
            return -1;
        }
        i = 0;
        table = D_8014AE10;
        block->offset += 0x60;
        for (; i < 16; i++) {
            table[i] = stream->frame[i];
        }
        while (block->kind != 0) {
            block++;
        }
    } else {
        u16 *table;
        result = (s16)func_802BEF84_de(block, stream->frame, 16, done, stream);
        if (result != 16) {
            return -1;
        }
        i = 0;
        block += done[0];
        table = D_8014AE10;
        for (; i < 16; i++) {
            u16 *entry = i + table;
            u16 previous = *entry;
            stream->frame[i] += previous;
            *entry = stream->frame[i];
        }
    }
    result = (s16)func_802BEF84_de(block, stream->frame + 80, 256, done, stream);
    if (result == 256) {
        return 1;
    }
    return -1;
}
#else
INCLUDE_ASM("span_1000", Audio_DecodeFrame);
#endif
