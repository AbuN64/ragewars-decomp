#include "include_asm.h"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "sdk/AUDIO/802C3EA4.H"

extern u16 D_800D5350[17];
extern u16 D_800D5374[17];
extern u16 D_8014AE00;

static inline void Audio_SignExtend(u16 *value, u16 width, s16 signExtend) {
    if (signExtend && ((s16)*value & D_800D5374[width])) {
        *value |= ~D_800D5350[width];
    }
}

/* Reads count packed width-bit samples from the 16-bit word stream into out (the bit reader keeps the
   current word in D_8014AE00 and its unread bit count in D_800D54B8); signExtend widens negative samples. */
u16 Audio_ReadPackedSamples(u16 *out, u16 width, u16 count, s16 signExtend, DecodeState *stream) {
    s16 i;
    u16 need;

    if (D_800D54B8 == 0) {
        u16 *cursor = stream->cursor;
        *(volatile u16 *)&D_8014AE00 = *cursor;
        stream->cursor = cursor + 1;
        D_800D54B8 = 16;
    }
    for (i = 0; i < count; i++) {
        if (D_800D54B8 >> 16) D_8014AE00 = 0;
        if (D_800D54B8 < width) {
            need = width - D_800D54B8;
            {
                u16 high = D_8014AE00 & D_800D5350[D_800D54B8];
                out[i] = high << need;
            }
            {
                u16 *cursor = stream->cursor;
                D_8014AE00 = *cursor;
                stream->cursor = cursor + 1;
            }
            {
                s32 low = (D_8014AE00 >> (16 - need)) & D_800D5350[need];
                out[i] |= low;
            }
            Audio_SignExtend(&out[i], width, signExtend);
            D_800D54B8 = 16 - need;
        } else {
            {
                s32 low = (D_8014AE00 >> (D_800D54B8 - width)) & D_800D5350[width];
                out[i] = low;
            }
            Audio_SignExtend(&out[i], width, signExtend);
            D_800D54B8 -= width;
        }
    }
    return 1;
}

/* Copies a dictionary phrase's samples to out; returns how many. */
static inline s16 Audio_CopyPhrase(DecodePhrase *phrase, u16 *out) {
    s16 j;
    for (j = 0; j < phrase->count; j++) {
        out[j] = phrase->samples[j].value;
    }
    return j;
}
s32 Audio_DecodeHuffmanSamples(DecodeBlock *blocks, u16 *samples, s16 sampleCount,
                               s16 *blocksDone, DecodeState *stream) {
    u16 node;
    s16 block, output;
    DecodeTable *table;
    DecodeNode *tree;
    u16 value;
    s32 mask, high;
    u16 topbit;
    s32 dictOffset;
    u16 next;

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
                        dictOffset = (value & 0xFF) * sizeof(DecodePhrase);
                        output += Audio_CopyPhrase((DecodePhrase *)(dictOffset + (s32)table->phrases),
                                                   &samples[output]);
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
        s16 value;
        count = (s16)Audio_DecodeHuffmanSamples(block, stream->frame, 16, &done, stream);
        if (count != 16) {
            return -1;
        }
        value = done;
        block += value;
        for (i = 0; i < 16; i++) {
            value = D_8014AE10[i];
            stream->frame[i] += value;
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
