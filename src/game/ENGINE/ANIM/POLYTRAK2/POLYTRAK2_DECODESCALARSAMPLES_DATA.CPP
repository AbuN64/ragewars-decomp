#include "include_asm.h"
#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/PACKED_BIT_WORDS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "SYSTEM/802609CC.H"

/* 802609CC.CPP */
/* Quantizes a float into a range's bit width and writes the value into the packed bit words at an address. */

inline static void write_bits(u32 arg2, u32 arg0, u32 arg1)
{
  u32 temp_a0;
  s32 temp_v0;
  s32 temp_v0_2;
  u32 temp_a1;
  u32 temp_a2;
  u32 temp_shift;
  u32 var_a2;
  u32 var_a3;
  u32 var_v1;
  PackedBitWords *words;
  temp_a1 = (1 << arg1) - 1;
  var_v1 = temp_a1;
  temp_v0 = arg0 & 0x1F;
  temp_shift = temp_v0;
  temp_a2 = arg2 & temp_a1;
  if (temp_v0 == 0)
  {
    var_a3 = temp_a2;
    temp_a1 = 0;
    var_a2 = 0;
  }
  else
  {
    var_v1 = temp_a1 << temp_shift;
    temp_v0_2 = 0x20 - temp_shift;
    temp_a1 >>= temp_v0_2;
    var_a3 = temp_a2 << temp_shift;
    var_a2 = temp_a2 >> temp_v0_2;
  }
  temp_a0 = (arg0 & 0xF0000000) | (((u32) (arg0 & 0x0FFFFFE0)) >> 3);
  words = (PackedBitWords *) temp_a0;
  words->low = (words->low & (~var_v1)) | var_a3;
  words->high = (words->high & (~temp_a1)) | var_a2;
}

/* Decodes element arg1 of a packed bit-field float array into a float scaled into its range. Adapted from Polytrak2_ReadQuantizedFloatAtAddress, inlined as a helper (with the width held in a local) called with a base plus width-times-index bit address and the record's range. */

static inline f32 decode(s32 bitAddress, Func802608ECResult range) {
    s32 shift;
    u32 *word;
    u32 value;
    u32 next;
    f64 converted;
    f32 result;
    u32 width;

    width = range.value;
    word = (u32 *) ((bitAddress & 0xF0000000) |
                    ((u32) (bitAddress & 0x0FFFFFE0) >> 3));
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
    converted = (s32) value;
    if ((s32) value < 0) {
        converted += D_800C4188_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << width) - 1);
    result *= range.delta;
    result += range.start;
    return result;
}

f32 Polytrak2_ReadQuantizedFloatAtAddress(s32 bitAddress, Func802608ECResult range) {
    s32 shift;
    u32 *word;
    u32 value;
    u32 next;
    f64 converted;
    f32 result;

    word = (u32 *) ((bitAddress & 0xF0000000) |
                    ((u32) (bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (range.value < 0x20U) {
        value &= (1 << range.value) - 1;
    }
    converted = (s32) value;
    if ((s32) value < 0) {
        converted += D_800C4170_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << range.value) - 1);
    result *= range.delta;
    result += range.start;
    return result;
}

void Polytrak2_WriteQuantizedFloatAtAddress(s32 bitAddress, Func802608ECResult range, f32 sourceValue)
{
  f32 arg4_2;
  f32 roundedScaledValue;
  s32 truncatedScaledValue;
  s32 quantizedValue;
  arg4_2 = sourceValue;
  roundedScaledValue = (arg4_2 - range.start) / range.delta * (f32) ((1 << range.value) - 1) + 0.5f;
  if (roundedScaledValue >= 0.0f)
  {
    quantizedValue = (s32) roundedScaledValue;
  }
  else
  {
    truncatedScaledValue = (s32) roundedScaledValue;
    quantizedValue = 1;
    if ((f32) truncatedScaledValue == roundedScaledValue)
    {
      quantizedValue = 0;
    }
    if (range.value)
    {
      quantizedValue = truncatedScaledValue - quantizedValue;
    }
    else
    {
      quantizedValue = truncatedScaledValue - quantizedValue;
    }
  }
  write_bits(quantizedValue, bitAddress, range.value);
}

f32 Polytrak2_ReadQuantizedFloatAndAdvance(u32 *stream, Func802608ECResult range) {
    u32 bitAddress;
    u32 *streamPtr;
    s32 shift;
    u32 *word;
    u32 value;
    u32 next;
    u32 width;
    f64 converted;
    f32 result;
    LocalDecodeRange local;

    streamPtr = stream;
    bitAddress = *streamPtr;
    local.range = range;
    width = local.range.value;
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
    converted = (s32) value;
    if ((s32) value < 0) {
        converted += D_800C4180_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << width) - 1);
    result *= local.range.delta;
    result += local.range.start;
    *streamPtr += range.value;
    return result;
}

/** Initialize a packed array and its decoding range. */
void func_80260C6C_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount) {
    DecodeArray *array = decodeArray;
    array->base = baseBitAddress;
    array->range = t;
    array->count = elementCount;
}

f32 func_80260C9C_de(DecodeArray *packedArray, s32 elementIndex) {
    return decode(packedArray->base + (packedArray->range.value * elementIndex), packedArray->range);
}

/** Initialize a packed array and its decoding range. */
void func_80260D78_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount) {
    DecodeArray *array = decodeArray;
    array->base = baseBitAddress;
    array->range = t;
    array->count = elementCount;
}

int Polytrak2_GetUnsignedArrayElement(BitFieldSource *packedArray, int elementIndex) {
    int bitAddress;
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;
    unsigned int width;

    width = packedArray->width;
    bitAddress = packedArray->base + (width * elementIndex);
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

/** Initialize a packed array and its decoding range. */
void func_80260E1C_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount) {
    DecodeArray *array = decodeArray;
    array->base = baseBitAddress;
    array->range = t;
    array->count = elementCount;
}

int func_80260E4C_de(BitFieldSource *packedArray, int elementIndex) {
    int bitAddress;
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;
    unsigned int width;

    width = packedArray->width;
    bitAddress = packedArray->base + (width * elementIndex);
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
    return value | (-1 << width);
}

/** Store a scalar word plus a three-word record by value. */
void func_80260ECC_de(void *arg0, int arg1, Triple t) {
    ObjRecAt4V4 *arg0_record = arg0;
    arg0_record->unk0 = arg1;
    arg0_record->unk4 = t;
}

/* DATA_800C926C.CPP */

