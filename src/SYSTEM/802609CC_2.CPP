#include "COMMON/LOCALDECODERANGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "SYSTEM/802609CC_2.H"

/* Decodes the next packed bit-field float from a stream record into its range and advances the record's bit address by the field width. Adapted from func_80260B80_de, inlined as a helper called with the record and a copy of the record's own range. */









static inline f32 decode(u32 *stream, Func802608ECResult range) {
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
        converted += D_800C4190_de;
    }
    result = (f32) converted;
    result /= (f32) ((1 << width) - 1);
    result *= local.range.delta;
    result += local.range.start;
    *streamPtr += range.value;
    return result;
}

extern void func_80260138_de(void);

/* Opens the next entry of a packed file: finds the last filled slot before the 0xDEADBEEF end marker in the offset table, records the following slot's offset as that slot's offset plus the given size, optionally hands the slot's data to func_802BD3A0_de, and returns a pointer to it. */



extern void func_802BD3A0_de(char *data);

f32 func_80260EF8_de(LocalDecodeRange *arg0) {
    return decode(&arg0->unused, arg0->range);
}

/** Advance a record pointer by an indexed number of strides. */
void func_80260FF0_de(unsigned int *record, int index) {
    record[0] += index * record[1];
}

unsigned int func_8026100C_de(unsigned int *arg0, unsigned int arg1) {
    unsigned int bitAddress;
    unsigned int shift;
    unsigned int *word;
    unsigned int value;
    unsigned int next;

    bitAddress = *arg0;
    word = (unsigned int *) ((bitAddress & 0xF0000000) |
                             ((bitAddress & 0x0FFFFFE0) >> 3));
    shift = bitAddress & 0x1F;
    value = word[0];
    next = word[1];
    if (shift != 0) {
        value >>= shift;
        next <<= 0x20 - shift;
        value |= next;
    }
    if (arg1 < 0x20U) {
        value &= (1 << arg1) - 1;
    }
    *arg0 = bitAddress + arg1;
    return value;
}

void func_8026107C_de(int *arg0, int arg1) {
    *arg0 = *arg0 + arg1;
}

/** Thin wrapper around func_80260138_de. */
void func_8026108C_de(void) {
    func_80260138_de();
}

void func_802610A8_de(void *arg0, s32 arg1) {
    s32 count;
    s32 *ptr;
    Pack *pack = arg0;
    s32 magic;

    count = 1;
    pack->count = arg1;
    pack->offsets[0] = ((arg1 * 4) + 0xF) & ~7;
    if (arg1 > 0) {
        magic = 0xDEADBEEF;
        ptr = pack->offsets;
        do {
            ptr[1] = magic;
            count += 1;
            ptr += 1;
        } while (arg1 >= count);
    }
}

char *func_802610F0_de(Pack *pack, s32 prepare, s32 size)
{
    s32 i;
    char *data;

    for (i = 0; i <= pack->count; i++) {
        if (pack->offsets[i] == 0xDEADBEEF) {
            break;
        }
    }
    i--;
    pack->offsets[i + 1] = pack->offsets[i] + size;
    data = (char *)pack + pack->offsets[i];
    if (prepare) {
        func_802BD3A0_de(data);
    }
    return data;
}
