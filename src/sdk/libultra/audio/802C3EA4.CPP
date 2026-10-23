#include "include_asm.h"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "SDK/AUDIO/802C3EA4.H"

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "COMMON/LLDIVRESULT.H"
extern u16 D_800D5350[];
extern u16 D_800D5374[];
extern u16 D_8014AE00;

u16 func_802BEDB0_de(u16 *arg0, u16 arg1, s32 arg2, s32 arg3, void *arg4) {
    s16 *temp_a3_2;
    s16 temp_a0_3;
    s16 temp_v0_2;
    s16 var_t1;
    s32 temp_a0;
    s32 temp_t0;
    s32 temp_t7;
    s32 var_v0;
    u16 *temp_a3;
    u16 *temp_t4;
    u16 *temp_t6;
    u16 *temp_v0;
    u16 *temp_v0_3;
    u16 temp_a0_2;
    u16 temp_v1_2;
    u16 var_v0_2;
    u32 temp_t5;

    var_v0 = arg2 & 0xFFFF;
    if (D_800D54B8 == 0) {
        temp_v0 = ((u16 **) arg4)[0x14 / sizeof(u16 *)];
        ((u16 **) arg4)[0x14 / sizeof(u16 *)] = temp_v0 + 1;
        D_800D54B8 = 0x10;
        D_8014AE00 = *temp_v0;
        var_v0 = arg2 & 0xFFFF;
    }
    var_t1 = 0;
    if (var_v0 != 0) {
        temp_t7 = (s32) (arg3 << 0x10) >> 0x10;
        temp_t5 = arg1 & 0xFFFF;
        temp_t6 = &D_800D5374[temp_t5];
        temp_t4 = &D_800D5350[temp_t5];
        do {
            if ((u16) D_800D54B8 < temp_t5) {
                temp_t0 = arg1 - D_800D54B8;
                temp_a3 = arg0 + (s16) var_t1;
                temp_a0 = temp_t0 & 0xFFFF;
                *temp_a3 = (D_8014AE00 & D_800D5350[D_800D54B8 & 0xFFFF]) << temp_a0;
                temp_v0_3 = ((u16 **) arg4)[0x14 / sizeof(u16 *)];
                temp_v1_2 = *temp_v0_3;
                ((u16 **) arg4)[0x14 / sizeof(u16 *)] = temp_v0_3 + 1;
                D_8014AE00 = temp_v1_2;
                temp_a0_2 = *temp_a3 | (((s32) (temp_v1_2 & 0xFFFF) >> (0x10 - temp_a0)) & D_800D5350[temp_a0]);
                *temp_a3 = temp_a0_2;
                if (temp_t7 != 0) {
                    if (!((s16) temp_a0_2 & *temp_t6)) {
                        var_v0_2 = 0x10 - temp_t0;
                    } else {
                        *temp_a3 = temp_a0_2 | ~*temp_t4;
                        goto block_10;
                    }
                } else {
block_10:
                    var_v0_2 = 0x10 - temp_t0;
                }
            } else {
                temp_a0_3 = ((s32) D_8014AE00 >> (D_800D54B8 - temp_t5)) & *temp_t4;
                temp_a3_2 = (s16 *) arg0 + (s16) var_t1;
                *temp_a3_2 = temp_a0_3;
                if ((temp_t7 != 0) && (temp_a0_3 & *temp_t6)) {
                    *temp_a3_2 = temp_a0_3 | ~*temp_t4;
                }
                var_v0_2 = D_800D54B8 - arg1;
            }
            D_800D54B8 = var_v0_2;
            temp_v0_2 = var_t1 + 1;
            var_t1 = temp_v0_2;
        } while (temp_v0_2 < (arg2 & 0xFFFF));
    }
    return 1U;
}
#else
#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
INCLUDE_ASM("span_1000", func_802BEDB0_de);
#endif
#if defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_802BF094);
#endif
#if defined(VERSION_US_REV1)
INCLUDE_ASM("span_1000", func_802C3EA4);
#endif
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
                        if (func_802BEDB0_de(bits, table->width, 1, 0, arg4) == 0) {
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
                if (func_802BEDB0_de(&D_800D54BA, 16, 1, 0, arg4) == 0) {
                    return -1;
                }
                *available += 16;
            }
        } while ((s16)output < arg2);
    }
    return (s16)output;
}

#ifdef NON_MATCHING
/* 72/99 words; remaining: ref saves the s16 sign-extended call result in a second register, schedules i = 0 ahead of the header load, and keeps &table[i] in a1 across load and store */
#include "TYPES.H"
typedef struct { char pad[0x18]; u16 header[16]; char gap[0x80]; u16 output[256]; } DraftStream;
extern DecodeBlock D_800D5564[];
extern s16 D_800D54BE;
extern u16 D_8014AE10[16];
s32 func_802BF388_de(DraftStream *stream) {
    DecodeBlock *block = D_800D5564;
    s16 *flag = &D_800D54BE;
    s16 done[4];
    s16 i;
    s16 result;
    if (*flag == 0) {
        u16 *table;
        *flag = 1;
        if ((s16)func_802BEDB0_de(stream->header, 6, 16, 0, stream) <= 0) {
            return -1;
        }
        table = D_8014AE10;
        block->offset += 0x60;
        for (i = 0; i < 16; i++) {
            table[i] = stream->header[i];
        }
        while (block->kind != 0) {
            block++;
        }
    } else {
        u16 *table;
        result = func_802BEF84_de(D_800D5564, stream->header, 16, done, stream);
        if (result != 16) {
            return -1;
        }
        block = &D_800D5564[done[0]];
        table = D_8014AE10;
        for (i = 0; i < 16; i++) {
            u16 value = stream->header[i] + table[i];
            stream->header[i] = value;
            table[i] = value;
        }
    }
    result = func_802BEF84_de(block, stream->output, 256, done, stream);
    if (result == 256) {
        return 1;
    }
    return -1;
}
#else
INCLUDE_ASM("span_1000", func_802BF388_de);
#endif
#if defined(VERSION_US_REV1) && defined(NON_MATCHING)
/* structure matches; remaining: register allocation (const 16 in s0, table bases in regs) */
extern u16 D_800D5350[];
extern u16 D_800D5374[];
extern u16 D_8014AE00;
u16 func_802C3EA4(u16 *dst, u16 bits, u16 count, s32 sign, void **stream) {
    s16 i;
    s32 sg;
    u16 *left = &D_800D54B8;
    u16 *cur = &D_8014AE00;
    u16 *tab = D_800D5350;
    u16 *mask = &tab[bits];
    u16 *sbit = &D_800D5374[bits];
    u16 *out;
    s32 rem;
    u16 v;
    if (*left == 0) {
        u16 *p = (u16 *)stream[5];
        stream[5] = p + 1;
        *left = 16;
        *cur = *p;
    }
    i = 0;
    if (count != 0) {
    sg = (s16)sign;
    do {
        out = dst + i;
        if (*left < bits) {
            rem = bits - *left;
            *out = (*cur & tab[*left]) << rem;
            {
                u16 *p = (u16 *)stream[5];
                stream[5] = p + 1;
                *cur = *p;
            }
            v = *out | ((*cur >> (16 - rem)) & tab[rem]);
            *out = v;
            if (sg != 0 && ((s16)v & *sbit)) {
                *out = v | ~*mask;
            }
            *left = 16 - rem;
        } else {
            v = (*cur >> (*left - bits)) & *mask;
            *out = v;
            if (sg != 0 && ((s16)v & *sbit)) {
                *out = v | ~*mask;
            }
            *left -= bits;
        }
        i++;
    } while (i < count);
    }
    return 1;
}
#endif
