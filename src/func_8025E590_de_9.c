#include "span_1000/code_8025E568.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_C76B0/data.h"
#include "types.h"

extern void func_80271FC8_de(void *arg0, s32 arg1, void *arg2, void *arg3);

extern void func_80270AAC_de(void *arg0, s32 arg1, void *arg2, void *arg3);

/** Return the first word of the object referenced at offset 0x10. */
void *func_8026049C_de(void *object) {
    AnimRef *animation = object;
    return *animation->data;
}

void func_802604AC_de(void *arg0, s32 arg1, void *arg2) {
    extern void *func_8028FDB4_de(void *arg0, s32 arg1);
    ObjectLinks24_2 *o = arg0;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    Rec_func_8024C92C_de *recs;
    void *base;
    Triple *out = arg2;

    idx = indices[arg1].translation;
    if (idx == -1) {
        recs = (void *)o->unk_4;
        __builtin_memcpy(out, &recs[arg1], sizeof(*out));
        return;
    }
    base = func_8028FDB4_de(o->unk_8, (s32) idx);
    func_80271FC8_de(arg2, o->unk_20,
                  (char *)base + (o->unk_18) * 4,
                  (char *)base + (o->unk_1C) * 4);
}

void func_80260550_de(void *arg0, s32 arg1, void *arg2) {
    extern char *func_8028FDB4_de(s32 *, s32);
    ObjectLinks24_2 *o = arg0;
    Vector4f *out = arg2;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    ObjectState14 *rec;
    void *base;
    f32 scale;

    idx = indices[arg1].unk2;
    if (idx == -1) {
        rec = (void *)(o->unk_4 + arg1 * 0x14);
        scale = D_800C416C_de;
        out->x = (f32)(rec->unk_C) * scale;
        out->y = (f32)(rec->unk_E) * scale;
        out->z = (f32)(rec->unk_10) * scale;
        out->w = (f32)(rec->unk_12) * scale;
        return;
    }
    base = func_8028FDB4_de(o->unk_C, (s32) idx);
    func_80270AAC_de(arg2, o->unk_20,
                  (char *)base + (o->unk_10) * 4,
                  (char *)base + (o->unk_14) * 4);
}

/** Scale a value by the maximum integer represented by a bit count. */
float func_80260634_de(float value, int bits) {
    return value / (float)((1 << bits) - 1);
}

f32 func_80260650_de(f32 value, f32 lower, f32 upper) {
    return value * (upper - lower) + lower;
}

s32 func_80260664_de(s32 arg0) {
    return (arg0 & 0xF0000000) | ((arg0 & 0x0FFFFFFF) * 8);
}

/** Preserve the top nibble and shift the lower 28 bits right by three. */
unsigned int func_80260684_de(unsigned int value) {
    return (value & 0xF0000000) | ((value & 0x0FFFFFFF) >> 3);
}

/** Repack the low address bits while retaining the high nibble. */
unsigned int func_802606A4_de(unsigned int arg0) {
    return (arg0 & 0xF0000000) | ((arg0 & 0x0FFFFFE0) >> 3);
}

/* Reads a width-bit field starting at a packed bit address, returning it right-aligned. Adapted from func_80260DA8_de, with the bit address and width passed directly instead of computed from a base/width record. */

int func_802606C4_de(int bitAddress, unsigned int width) {
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;

    word = (int *) ((bitAddress & 0xF0000000) |
                    ((unsigned int) (bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (width < 0x20U) {
        value &= (1 << width) - 1;
    }
    return value;
}

void func_80260724_de(u32 arg0, u32 arg1, u32 arg2) {
    u32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_a1;
    u32 temp_a2;
    u32 temp_shift;
    u32 var_a2;
    u32 var_a3;
    u32 var_v1;

    temp_a1 = (1 << arg1) - 1;
    var_v1 = temp_a1;
    temp_v0 = arg0 & 0x1F;
    temp_shift = temp_v0;
    temp_a2 = arg2 & temp_a1;
    if (temp_v0 == 0) {
        var_a3 = temp_a2;
        temp_a1 = 0;
        var_a2 = 0;
    } else {
        var_v1 = temp_a1 << temp_shift;
        temp_v0_2 = 0x20 - temp_shift;
        temp_a1 >>= temp_v0_2;
        var_a3 = temp_a2 << temp_shift;
        var_a2 = temp_a2 >> temp_v0_2;
    }
    temp_a0 = (arg0 & 0xF0000000) | ((u32)(arg0 & 0x0FFFFFE0) >> 3);
    *(s32 *)temp_a0 = (*(s32 *)temp_a0 & ~var_v1) | var_a3;
    ((struct func_80203E78_S1 *) temp_a0)->unk4 = (((struct func_80203E78_S1 *) temp_a0)->unk4 & ~temp_a1) | var_a2;
}

u32 func_802607B8_de(u32 *stream, u32 width) {
    u32 bitAddress;
    u32 shift;
    u32 *word;
    u32 value;
    u32 next;

    bitAddress = *stream;
    word = (u32 *) ((bitAddress & 0xF0000000) |
                    ((bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (width < 0x20U) {
        value &= (1 << width) - 1;
    }
    *stream = bitAddress + width;
    return value;
}

void func_80260828_de(u32 *arg0, u32 arg1, u32 arg2) {
    u32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_a1;
    u32 temp_a2;
    u32 temp_shift;
    u32 var_a2;
    u32 var_a3;
    u32 var_v1;
    u32 value;

    value = *arg0;
    temp_a1 = (1 << arg1) - 1;
    var_v1 = temp_a1;
    temp_v0 = value & 0x1F;
    temp_shift = temp_v0;
    temp_a2 = arg2 & temp_a1;
    if (temp_v0 == 0) {
        var_a3 = temp_a2;
        temp_a1 = 0;
        var_a2 = 0;
    } else {
        var_v1 = temp_a1 << temp_shift;
        temp_v0_2 = 0x20 - temp_shift;
        temp_a1 >>= temp_v0_2;
        var_a3 = temp_a2 << temp_shift;
        var_a2 = temp_a2 >> temp_v0_2;
    }
    temp_a0 = (value & 0xF0000000) | ((u32)(value & 0x0FFFFFE0) >> 3);
    *(s32 *)temp_a0 = (*(s32 *)temp_a0 & ~var_v1) | var_a3;
    ((struct func_80203E78_S1 *) temp_a0)->unk4 = (((struct func_80203E78_S1 *) temp_a0)->unk4 & ~temp_a1) | var_a2;
    *arg0 += arg1;
}

Func802608ECResult func_802608CC_de(f32 arg0, f32 arg1, f32 arg2) {
    Func802608ECResult result;
    f32 ratio;
    s32 truncated;
    s32 bits;
    u32 count;
    u32 highest;
    u32 bit;
    u32 value;

    result.start = arg0;
    result.delta = arg1 - arg0;
    ratio = result.delta / (arg2 + arg2);
    if (ratio <= 0.0f) {
        bits = (s32)ratio + 1;
    } else {
        truncated = (s32)ratio;
        bits = truncated + 1;
        if ((f32)truncated != ratio) {
            bits = truncated + 2;
        }
    }
    count = 0;
    highest = 0;
    bit = 0;
    do {
        if (bits & (u32)(1 << bit)) {
            count += 1;
            highest = bit;
        }
        bit += 1;
    } while (bit < 0x20U);
    value = highest;
    if (count >= 2U) {
        value += 1;
    }
    result.value = value;
    return result;
}
