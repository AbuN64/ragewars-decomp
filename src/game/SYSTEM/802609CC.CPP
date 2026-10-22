#include "include_asm.h"
#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/PACKED_BIT_WORDS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "SYSTEM/802609CC.H"

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

/* Decodes element arg1 of a packed bit-field float array into a float scaled into its range. Adapted from func_802609AC_de, inlined as a helper (with the width held in a local) called with a base plus width-times-index bit address and the record's range. */







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

f32 func_802609AC_de(s32 bitAddress, Func802608ECResult range) {
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

void func_80260A5C_de(s32 arg0, Func802608ECResult range, f32 arg4)
{
  f32 arg4_2;
  f32 temp_f1;
  s32 temp_f2;
  s32 var_a0;
  arg4_2 = arg4;
  temp_f1 = (arg4_2 - range.start) / range.delta * (f32) ((1 << range.value) - 1) + 0.5f;
  if (temp_f1 >= 0.0f)
  {
    var_a0 = (s32) temp_f1;
  }
  else
  {
    temp_f2 = (s32) temp_f1;
    var_a0 = 1;
    if ((f32) temp_f2 == temp_f1)
    {
      var_a0 = 0;
    }
    if (range.value)
    {
      var_a0 = temp_f2 - var_a0;
    }
    else
    {
      var_a0 = temp_f2 - var_a0;
    }
  }
  write_bits(var_a0, arg0, range.value);
}

f32 func_80260B80_de(u32 *stream, Func802608ECResult range) {
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
void func_80260C6C_de(void *arg0, int arg1, Func802608ECResult t, int arg5) {
    DecodeArray *array = arg0;
    array->base = arg1;
    array->range = t;
    array->count = arg5;
}

f32 func_80260C9C_de(DecodeArray *arg0, s32 arg1) {
    return decode(arg0->base + (arg0->range.value * arg1), arg0->range);
}

/** Initialize a packed array and its decoding range. */
void func_80260D78_de(void *arg0, int arg1, Func802608ECResult t, int arg5) {
    DecodeArray *array = arg0;
    array->base = arg1;
    array->range = t;
    array->count = arg5;
}

int func_80260DA8_de(BitFieldSource *arg0, int arg1) {
    int bitAddress;
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;
    unsigned int width;

    width = arg0->width;
    bitAddress = arg0->base + (width * arg1);
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
void func_80260E1C_de(void *arg0, int arg1, Func802608ECResult t, int arg5) {
    DecodeArray *array = arg0;
    array->base = arg1;
    array->range = t;
    array->count = arg5;
}

int func_80260E4C_de(BitFieldSource *arg0, int arg1) {
    int bitAddress;
    int shift;
    int *word;
    unsigned int value;
    unsigned int next;
    unsigned int width;

    width = arg0->width;
    bitAddress = arg0->base + (width * arg1);
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

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C40AC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C446C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C442C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C417C);
#endif
