#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802A0888.h"
#include "types.h"
/* Fills arg2 bytes at arg0 with the byte arg1, storing single bytes up to word alignment, replicated words through the middle and single bytes at the tail, and returns arg0. Adapted from func_802A001C_de. */
void *func_802A0748_de(void *arg0, int arg1, u32 arg2) {
    u8 *start;
    u8 *end;
    u8 *cur;
    u8 *next;
    u32 byte;
    u32 word;
    start = arg0;
    end = start + arg2;
    byte = arg1 & 0xFF;
    word = (byte << 24) | (byte << 16) | (byte << 8) | byte;
    cur = start;
    if (cur >= end) {
        goto word_test;
    }
align_test:
    if (!((u32)cur & 3)) {
        goto word_test;
    }
    *cur = arg1;
    cur += 1;
    if (cur < end) {
        goto align_test;
    }
    goto word_test;
word_test:
    next = cur + 4;
    while (next < end) {
        *(u32 *)cur = word;
        cur = next;
        next = cur + 4;
    }
    if (cur < end) {
        do {
            *cur++ = arg1;
        } while (cur < end);
    }
    return start;
}
u8 *func_802A07DC_de(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 count;
    p = arg0;
    count = arg2;
    if (count != 0) {
        arg1 = arg1 & 0xFF;
loop:
        if (*p != arg1) {
            count -= 1;
            p += 1;
            if (count != 0) {
                goto loop;
            }
        }
    }
    if (count == 0) {
        return 0;
    }
    return p;
}
s32 func_802A0814_de(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *var_a0;
    u8 *var_a1;
    u8 *var_a3;
    u8 temp_a2;
    u8 temp_v1;
    var_a0 = arg0;
    var_a1 = arg1;
    var_a3 = var_a0 + arg2;
    if (arg2 < 4) {
        goto block_17;
    }
    if ((u32)var_a0 & 3) {
        goto block_17;
    }
    if ((u32)var_a1 & 3) {
        goto block_17;
    }
    var_a3 -= 4;
    if (var_a3 < var_a0) {
        var_a3 += 4;
        goto block_16;
    }
loop_6:
    if (*(u32 *)var_a0 != *(u32 *)var_a1) {
        var_a0 -= 4;
        var_a1 -= 4;
        goto block_11;
    }
    var_a0 += 4;
    var_a1 += 4;
    if (var_a3 >= var_a0) {
        goto loop_6;
    }
block_11:
    var_a3 += 4;
    goto block_16;
block_12:
    temp_v1 = *var_a0;
    temp_a2 = *var_a1;
    if (temp_v1 == temp_a2) {
        var_a0 += 1;
        var_a1 += 1;
        goto block_16;
    }
    if (temp_v1 < temp_a2) {
        return -1;
    }
    return 1;
block_16:
    ;
block_17:
    if (var_a0 < var_a3) {
        goto block_12;
    }
    return 0;
}
/** Compute a CRC-32 over arg1 bytes, continuing from arg2. */
u32 func_802A08B8_de(u8 *arg0, u32 arg1, u32 arg2) {
    u32 table[256];
    u32 i;
    u32 j;
    u32 value;
    u32 shifted;
    u8 *end;
    for (i = 0; i < 256; i++) {
        value = i;
        for (j = 0; j < 8; j++) {
            shifted = value >> 1;
            if (value & 1) {
                shifted ^= 0xEDB88320U;
            }
            value = shifted;
        }
        table[i] = value;
    }
    end = arg0 + arg1;
    arg2 = ~arg2;
    while (arg0 < end) {
        arg2 = table[(arg2 ^ *arg0++) & 0xFF] ^ ((arg2 >> 8) & 0xFFFFFF);
    }
    return ~arg2;
}
/* Builds a path from drive, directory, filename and extension components. */
void func_802A0960_de(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    u8 *extension = arg4;
    u8 *var_a0;
    u8 *var_a2;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 var_v0;
    u8 var_v0_2;
    var_a0 = arg0;
    var_a2 = arg2;
    if (arg1 != 0) {
        temp_a1 = *arg1;
        if (temp_a1 != 0) {
            *var_a0++ = temp_a1;
            *var_a0++ = 0x3A;
        }
    }
    if ((var_a2 != 0) && (*var_a2 != 0)) {
        do {
            temp_v0 = *var_a2;
            var_a2 += 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (var_a2[0] != 0);
        temp_a2 = var_a2[-1];
        if ((temp_a2 != 0x2F) && (temp_a2 != 0x5C)) {
            *var_a0 = 0x5C;
            var_a0 += 1;
        }
    }
    if (arg3 != 0) {
        var_v0 = *arg3;
        var_a2 = arg3;
        if (var_v0 != 0) {
            do {
                var_a2 += 1;
                *var_a0 = var_v0;
                var_v0 = *var_a2;
                var_a0 += 1;
            } while (var_v0 != 0);
        }
    }
    if (extension != 0) {
        var_a2 = extension;
        temp_v0_2 = *var_a2;
        if (temp_v0_2 != 0) {
            if (temp_v0_2 != 0x2E) {
                *var_a0 = 0x2E;
                var_a0 += 1;
            }
            var_v0_2 = *var_a2;
            if (var_v0_2 != 0) {
                do {
                    var_a2 += 1;
                    *var_a0 = var_v0_2;
                    var_v0_2 = *var_a2;
                    var_a0 += 1;
                } while (var_v0_2 != 0);
            }
        }
    }
    *var_a0 = 0;
}
extern void func_802BAC60_de(void *arg0, void *arg1, s32 arg2);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
void func_802A0A48_de(void *arg0) {
    MessageSemaphore *semaphore = arg0;
    func_802BAC60_de(arg0, &semaphore->message, 1);
    func_802BB420_de(arg0, 1, 1);
}
void func_802A0A84_de(s32 arg0) {
    func_802BB2A0_de(arg0, arg0 + 0x18, 1);
}
void func_802A0AA4_de(s32 *arg0) {
    func_802BB420_de(arg0, 1, 1);
}
