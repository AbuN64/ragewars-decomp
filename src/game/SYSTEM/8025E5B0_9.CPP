#include "COMMON/STREAM.H"
#include "GAME_2/8025E520.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_80271FC8_de(CVector3 *arg0, s32 arg1, void *arg2, void *arg3);

extern void func_80270AAC_de(void *arg0, s32 arg1, void *arg2, void *arg3);

/** Return the first word of the object referenced at offset 0x10. */
void *func_8026049C_de(void *object) {
    AnimRef *animation = object;
    return *animation->data;
}

void func_802604AC_de(void *animationLinks, s32 jointIndex, void *translationOut) {
    ObjectLinks24_2 *o = animationLinks;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    Rec_func_8024C92C_de *recs;
    void *base;
    Triple *out = translationOut;

    idx = indices[jointIndex].translation;
    if (idx == -1) {
        recs = (void *)o->unk_4;
        __builtin_memcpy(out, &recs[jointIndex], sizeof(*out));
        return;
    }
    base = Render_GetPackSection(o->unk_8, (s32) idx);
    func_80271FC8_de(translationOut, o->unk_20,
                  (char *)base + (o->unk_18) * 4,
                  (char *)base + (o->unk_1C) * 4);
}

void func_80260550_de(void *animationLinks, s32 jointIndex, void *cQuatern) {
    ObjectLinks24_2 *o = animationLinks;
    CQuatern *out = cQuatern;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    CROMInitialOrientation_t *rec;
    void *base;
    f32 scale;

    idx = indices[jointIndex].unk2;
    if (idx == -1) {
        rec = (void *)(o->unk_4 + jointIndex * 0x14);
        scale = D_800C416C_de;
        out->x = (f32)(rec->unk_C) * scale;
        out->y = (f32)(rec->m_RotY) * scale;
        out->z = (f32)(rec->unk_10) * scale;
        out->w = (f32)(rec->unk_12) * scale;
        return;
    }
    base = Render_GetPackSection(o->unk_C, (s32) idx);
    func_80270AAC_de(cQuatern, o->unk_20,
                  (char *)base + (o->unk_10) * 4,
                  (char *)base + (o->unk_14) * 4);
}

/** Scale a value by the maximum integer represented by a bit count. */
float System_UnpackUnitValue(float value, int bits) {
    return value / (float)((1 << bits) - 1);
}

f32 System_ScaleToRange(f32 value, f32 lower, f32 upper) {
    return value * (upper - lower) + lower;
}

s32 func_80260664_de(s32 byteAddress) {
    return (byteAddress & 0xF0000000) | ((byteAddress & 0x0FFFFFFF) * 8);
}

/** Preserve the top nibble and shift the lower 28 bits right by three. */
unsigned int func_80260684_de(unsigned int value) {
    return (value & 0xF0000000) | ((value & 0x0FFFFFFF) >> 3);
}

/** Repack the low address bits while retaining the high nibble. */
unsigned int func_802606A4_de(unsigned int bitAddress) {
    return (bitAddress & 0xF0000000) | ((bitAddress & 0x0FFFFFE0) >> 3);
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

void func_80260724_de(u32 bitAddress, u32 bitCount, u32 fieldValue) {
    u32 wordAddress;
    s32 bitOffset;
    s32 remainingWordBits;
    u32 overflowMask;
    u32 maskedValue;
    u32 writeShift;
    u32 overflowValue;
    u32 firstWordValue;
    u32 firstWordMask;

    overflowMask = (1 << bitCount) - 1;
    firstWordMask = overflowMask;
    bitOffset = bitAddress & 0x1F;
    writeShift = bitOffset;
    maskedValue = fieldValue & overflowMask;
    if (bitOffset == 0) {
        firstWordValue = maskedValue;
        overflowMask = 0;
        overflowValue = 0;
    } else {
        firstWordMask = overflowMask << writeShift;
        remainingWordBits = 0x20 - writeShift;
        overflowMask >>= remainingWordBits;
        firstWordValue = maskedValue << writeShift;
        overflowValue = maskedValue >> remainingWordBits;
    }
    wordAddress = (bitAddress & 0xF0000000) | ((u32)(bitAddress & 0x0FFFFFE0) >> 3);
    *(s32 *)wordAddress = (*(s32 *)wordAddress & ~firstWordMask) | firstWordValue;
    ((struct func_80203E78_S1 *) wordAddress)->unk4 = (((struct func_80203E78_S1 *) wordAddress)->unk4 & ~overflowMask) | overflowValue;
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

void func_80260828_de(u32 *bitCursor, u32 bitCount, u32 fieldValue) {
    u32 wordAddress;
    s32 bitOffset;
    s32 remainingWordBits;
    u32 overflowMask;
    u32 maskedValue;
    u32 writeShift;
    u32 overflowValue;
    u32 firstWordValue;
    u32 firstWordMask;
    u32 value;

    value = *bitCursor;
    overflowMask = (1 << bitCount) - 1;
    firstWordMask = overflowMask;
    bitOffset = value & 0x1F;
    writeShift = bitOffset;
    maskedValue = fieldValue & overflowMask;
    if (bitOffset == 0) {
        firstWordValue = maskedValue;
        overflowMask = 0;
        overflowValue = 0;
    } else {
        firstWordMask = overflowMask << writeShift;
        remainingWordBits = 0x20 - writeShift;
        overflowMask >>= remainingWordBits;
        firstWordValue = maskedValue << writeShift;
        overflowValue = maskedValue >> remainingWordBits;
    }
    wordAddress = (value & 0xF0000000) | ((u32)(value & 0x0FFFFFE0) >> 3);
    *(s32 *)wordAddress = (*(s32 *)wordAddress & ~firstWordMask) | firstWordValue;
    ((struct func_80203E78_S1 *) wordAddress)->unk4 = (((struct func_80203E78_S1 *) wordAddress)->unk4 & ~overflowMask) | overflowValue;
    *bitCursor += bitCount;
}

Func802608ECResult func_802608CC_de(f32 minimumValue, f32 maximumValue, f32 maximumError) {
    Func802608ECResult result;
    f32 ratio;
    s32 truncated;
    s32 bits;
    u32 count;
    u32 highest;
    u32 bit;
    u32 value;

    result.start = minimumValue;
    result.delta = maximumValue - minimumValue;
    ratio = result.delta / (maximumError + maximumError);
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
