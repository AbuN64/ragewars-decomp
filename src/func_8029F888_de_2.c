#include "span_1000/code_802A0888.h"
#include "span_1000/code_802BB15C.h"
#include "stddef.h"
#include "types.h"

extern s32 func_802A0470(void);

extern void func_802BAC60_de(void *arg0, void *arg1, s32 arg2);

extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);

void func_802A01D8_de(int arg0) {
    D_800CD900 = arg0;
}

s32 func_802A01E8_de(void) {
    s32 temp_v0;

    temp_v0 = (D_800CD900 * 0x343FD) + 0x269EC3;
    D_800CD900 = temp_v0;
    return (temp_v0 >> 0x10) & 0x7FFF;
}

/** Return strlen(arg0) (byte count not including the terminating NUL). */
s32 func_802A0238_de(u8 *arg0) {
    u8 *var_v1;
    u8 temp;

    var_v1 = arg0 + 1;
    if (*arg0 != 0) {
        do {
            temp = *var_v1;
            var_v1 += 1;
        } while (temp != 0);
    }
    return (var_v1 - arg0) - 1;
}

u8 *func_802A025C_de(u8 *arg0, u8 *arg1) {
    u8 *dst;
    u8 c;

    c = *arg1;
    arg1++;
    *arg0 = c;
    dst = arg0 + 1;
    if (c != 0) {
        do {
            c = *arg1;
            arg1++;
            *dst = c;
            dst++;
        } while (c != 0);
    }
    return arg0;
}

/** strncpy: copy up to arg2 bytes from arg1 to arg0, NUL-padding the remainder. */
u8 *func_802A0294_de(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_a2;
    u8 *temp_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    temp_v1 = var_a0;
    if (var_a2 != 0) {
    loop_1:
        temp_v0 = *var_a1;
        var_a1 += 1;
        *var_a0 = temp_v0;
        var_a0 += 1;
        if (temp_v0 & 0xFF) {
            var_a2 -= 1;
            if (var_a2 != 0) {
                goto loop_1;
            }
        }
        if (var_a2 != 0) {
            var_a2 -= 1;
            if (var_a2 != 0) {
                do {
                    *var_a0 = 0;
                    var_a2 -= 1;
                    var_a0 += 1;
                } while (var_a2 != 0);
            }
        }
    }
    return temp_v1;
}

u8 *func_802A02E8_de(u8 *arg0, u8 *arg1) {
    u8 *var_a1;
    u8 *var_v1;
    u8 temp_v0;
    var_a1 = arg1;
    var_v1 = arg0;
    if (*arg0 != 0) {
        do {
            var_v1 += 1;
        } while (*var_v1 != 0);
    }
    do {
        temp_v0 = *var_a1;
        var_a1 += 1;
        *var_v1 = temp_v0;
        var_v1 += 1;
    } while (temp_v0 & 0xFF);
    return arg0;
}

u8 *func_802A0324_de(u8 *destination, u8 *source, s32 count) {
    u8 *end = destination + 1;
    u8 byte;
    if (*destination != 0) {
        do { } while (*end++ != 0);
    }
    --end;
    while (count-- != 0) {
        byte = *source++;
        *end++ = byte;
        if (!(byte & 0xFF)) return destination;
    }
    *end = 0;
    return destination;
}

s32 func_802A037C_de(const void *arg0, const void *arg1) {
    const u8 *a = arg0;
    const u8 *b = arg1;
    s32 difference;

    while ((difference = *a - *b) == 0) {
        if (*b == 0) {
            break;
        }
        a++;
        b++;
    }
    return difference;
}

s32 func_802A03AC_de(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v1;
    var_a0 = arg0;
    var_a1 = arg1;
    if (arg2 == 0) {
        return 0;
    }
    arg2 -= 1;
    while (arg2 != 0 && (temp_v1 = *var_a0) != 0 && temp_v1 == *var_a1) {
        arg2 -= 1;
        var_a0 += 1;
        var_a1 += 1;
    }
    return *var_a0 - *var_a1;
}

s32 func_802A03F4_de(u8 *arg0, u8 *arg1)
{
  s32 c2;
  int new_var;
  s32 c1;
  c2 = *arg1;
  arg1 += 1;
  new_var = 0x41;
  if (c2 >= new_var)
  {
    if (c2 < 0x5B)
    {
      c2 += 0x20;
    }
  }
  c1 = *arg0;
  arg0 += 1;
  if (c1 >= new_var)
  {
    if (c1 < 0x5B)
    {
      c1 += 0x20;
    }
  }
  if (c2 != 0)
  {
    if (c2 == c1)
    {
      return func_802A03F4_de(arg0, arg1);
    }
  }
  return c1 - c2;
}

/* Returns a pointer to the last occurrence of a character in a string, or 0 when it does not occur
   (strrchr). */
u8 *func_802A0444_de(u8 *s, int c) {
    u8 *start = s;
    while (*s++ != 0) {
    }
    s--;
    for (; s != start; s--) {
        if (*s == (u8)c) {
            break;
        }
    }
    if (*s == (u8)c) {
        return s;
    }
    return 0;
}

/** In-place ASCII-uppercase a NUL-terminated string; NULL-safe. */
u8 *func_802A0494_de(u8 *arg0) {
    u8 *var_v1;
    u8 temp_a1;
    var_v1 = arg0;
    if (arg0 == 0) {
        return 0;
    }
    if (*arg0 != 0) {
        do {
            temp_a1 = *var_v1;
            if ((u32)(temp_a1 - 0x61) < 0x1AU) {
                *var_v1 = temp_a1 - 0x20;
            }
            var_v1 += 1;
        } while (*var_v1 != 0);
    }
    return arg0;
}

/** In-place ASCII-lowercase a NUL-terminated string; NULL-safe. */
u8 *func_802A04E0_de(u8 *arg0) {
    u8 *var_v1;
    u8 temp_a1;
    var_v1 = arg0;
    if (arg0 == 0) {
        return 0;
    }
    if (*arg0 != 0) {
        do {
            temp_a1 = *var_v1;
            if ((u32)(temp_a1 - 0x41) < 0x1AU) {
                *var_v1 = temp_a1 + 0x20;
            }
            var_v1 += 1;
        } while (*var_v1 != 0);
    }
    return arg0;
}

/* Searches a zero-terminated byte string for a pattern and returns the position just past the first match, or zero when there is none. */
u8 *func_802A052C_de(u8 *s, u8 *pattern) {
    u8 *p;
    while (*s != 0) {
        while (*s != 0 && *s != *pattern) {
            s++;
        }
        p = pattern;
        while (*p != 0 && *s == *p) {
            p++;
            s++;
        }
        if (*p == 0) {
            return s;
        }
    }
    return 0;
}

/** Convert a lowercase ASCII letter to uppercase. */
int func_802A05A0_de(int arg0) {
    if ((unsigned int)(arg0 - 'a') < 26) {
        arg0 -= 'a' - 'A';
    }
    return arg0;
}

/** Convert an uppercase ASCII letter to lowercase. */
int func_802A05B8_de(int arg0) {
    if ((unsigned int)(arg0 - 'A') < 26) {
        arg0 += 'a' - 'A';
    }
    return arg0;
}

/* Parses a signed decimal integer from a string, skipping leading spaces and one optional sign (atoi). */
s32 func_802A05D0_de(u8 *s) {
    s32 n;
    s32 c;
    u8 sign;
    while (*s == ' ') {
        s++;
    }
    c = *s;
    sign = c;
    s++;
    if (sign == '-' || sign == '+') {
        c = *s;
        s++;
    }
    n = 0;
    while (c >= '0' && c <= '9') {
        n = (c - '0') + n * 10;
        c = *s;
        s++;
    }
    if (sign == '-') {
        return -n;
    }
    return n;
}

/* Formats a signed integer as a NUL-terminated decimal string (K&R itoa with the reverse inlined). */
void func_802A066C_de(s32 n, char *s) {
    s32 i;
    s32 j;
    s32 sign;
    s32 len;
    char c;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    len = i;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    s[len] = '\0';
}

s32 func_802A0724_de(s32 arg0, s32 unused1, s32 arg2) {
    s32 result;

    result = arg0;
    if (arg2 != 0) {
        result = func_802A0470();
    }
    return result;
}

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
