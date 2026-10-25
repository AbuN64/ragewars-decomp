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

/* NON_MATCHING: 28 aligned edits / 117 ROM words; remaining: the refill keeps &D_8014AE00 in a register for its store,
   and the loop word/mask-table pointers swap t3/t4. */
u16 Audio_ReadPackedSamples(u16 *out, u16 width, u16 count, s16 signExtend, DecodeState *stream) {
    s16 i;
    u16 need;
    u16 *bitsLeft = &D_800D54B8;
    if (*bitsLeft == 0) {
        u16 *cursor = stream->cursor;
        u16 v = *cursor;
        stream->cursor = cursor + 1;
        *bitsLeft = 16;
        D_8014AE00 = v;
    }
    for (i = 0; i < count; i++) {
        u16 *left = &D_800D54B8;
        u16 *word = &D_8014AE00;
        u16 *masks = D_800D5350;
        u16 *signs = D_800D5374;
        if (*left < width) {
            need = width - *left;
            out[i] = (*word & masks[*left]) << need;
            {
                u16 *cursor = stream->cursor;
                *word = *cursor;
                stream->cursor = cursor + 1;
            }
            {
                s32 low = (*word >> (16 - need)) & masks[need];
                out[i] |= low;
            }
            if (signExtend && ((s16)out[i] & signs[width])) {
                out[i] |= ~masks[width];
            }
            *left = 16 - need;
        } else {
            s32 low = (*word >> (*left - width)) & masks[width];
            out[i] = low;
            if (signExtend && ((s16)out[i] & signs[width])) {
                out[i] |= ~masks[width];
            }
            *left -= width;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", Audio_ReadPackedSamples);
#endif

s32 Audio_DecodeHuffmanSamples(DecodeBlock *blocks, u16 *samples, s16 sampleCount,
                               s16 *blocksDone, DecodeState *stream) {
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
    DecodePhrase *phrase;
    u16 *dst;

    node = 0;
    block = 0;
    *blocksDone = 0;
    table = blocks->table;
    tree = table->tree;
    output = 0;
    if (sampleCount > 0) {
        do {
            if (D_800D54BC != 0) {
                D_800D54BC--;
                topbit = D_800D54BA & 0x8000;
                D_800D54BA <<= 1;
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
                        samples[(s16)output] = value;
                        output++;
                    } else if ((s16)value == 0x900) {
                        value = D_800D54BA;
                        if (Audio_ReadPackedSamples(&D_800D54BA, table->width, 1, 0, stream) == 0) {
                            return -1;
                        }
                        mask = (s16)output;
                        output++;
                        high = D_800D54BA;
                        next = D_800D54BC;
                        D_800D54BA = high << (16 - next);
                        samples[(s16)mask] = value | (high >> next);
                    } else if (mask == 0xA00) {
                        j = 0;
                        dictOffset = (value & 0xFF) * sizeof(DecodePhrase);
                        dst = (u16 *)((s16)output * sizeof(u16) + (s32)samples);
                        phrase = (DecodePhrase *)(dictOffset + (s32)table->phrases);
                        while ((s16)j < phrase->count) {
                            dst[(s16)j] = phrase->samples[(s16)j].value;
                            j++;
                        }
                        output += (s32)((u32)j << 16) >> 16;
                    } else if (mask == 0xB00) {
                        while ((s16)output < sampleCount) {
                            samples[(s16)output++] = 0;
                        }
                        while (sampleCount >= blocks[(s16)block].start +
                                       blocks[(s16)block].length) {
                            block++;
                            (*blocksDone)++;
                        }
                        return sampleCount;
                    }
                    if ((s16)output >= blocks[(s16)block].start +
                                       blocks[(s16)block].length) {
                        block++;
                        (*blocksDone)++;
                        table = blocks[(s16)block].table;
                        tree = table->tree;
                    }
                } else {
                    node = mask;
                }
            } else {
                if (Audio_ReadPackedSamples(&D_800D54BA, 16, 1, 0, stream) == 0) {
                    return -1;
                }
                D_800D54BC += 16;
            }
        } while ((s16)output < sampleCount);
    }
    return (s16)output;
}

#ifdef NON_MATCHING
/* 4/99 words left: a1/a2 swap between the history-table address and `previous` (local-alloc
   priority tie, see lanes/REV1-ONE-18/RESULT.md). */
extern DecodeBlock D_800D5564[];
extern s16 D_800D54BE;
extern u16 D_8014AE10[16];
s32 Audio_DecodeFrame(DecodeState *stream) {
    DecodeBlock *block = D_800D5564;
    s16 done;
    s16 i;
    s32 count;

    if (D_800D54BE == 0) {
        D_800D54BE = 1;
        if ((s16)Audio_ReadPackedSamples(stream->frame, 6, 16, 0, stream) <= 0) {
            return -1;
        }
        block->offset += 0x60;
        for (i = 0; i < 16; i++) {
            D_8014AE10[i] = stream->frame[i];
        }
        while (block->kind != 0) {
            block++;
        }
    } else {
        count = (s16)Audio_DecodeHuffmanSamples(block, stream->frame, 16, &done, stream);
        if (count != 16) {
            return -1;
        }
        block += done;
        for (i = 0; i < 16; i++) {
            u16 previous = D_8014AE10[i];
            stream->frame[i] += previous;
            D_8014AE10[i] = stream->frame[i];
        }
    }
    count = (s16)Audio_DecodeHuffmanSamples(block, stream->frame + 80, 256, &done, stream);
    if (count == 256) {
        block += done;
        return 1;
    }
    return -1;
}
#else
INCLUDE_ASM("span_1000", Audio_DecodeFrame);
#endif
