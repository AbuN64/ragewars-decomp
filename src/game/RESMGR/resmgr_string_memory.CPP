#include "include_asm.h"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/EXTERNS_18.H"
#include "stddef.h"
#include "TYPES.H"
#include "RESMGR/resmgr_string_memory.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

#include "MATH/802A0470.H"



void func_802A01D8_de(int seed) {
    D_800CD900 = seed;
}

s32 func_802A01E8_de(void) {
    s32 temp_v0;

    temp_v0 = (D_800CD900 * 0x343FD) + 0x269EC3;
    D_800CD900 = temp_v0;
    return (temp_v0 >> 0x10) & 0x7FFF;
}

/** Return strlen(arg0) (byte count not including the terminating NUL). */
s32 func_802A0238_de(u8 *string) {
    u8 *cursor;
    u8 c;

    cursor = string + 1;
    if (*string != 0) {
        do {
            c = *cursor;
            cursor += 1;
        } while (c != 0);
    }
    return (cursor - string) - 1;
}

u8 *Resmgr_CopyString(u8 *destination, u8 *source) {
    u8 *destCursor;
    u8 c;

    c = *source;
    source++;
    *destination = c;
    destCursor = destination + 1;
    if (c != 0) {
        do {
            c = *source;
            source++;
            *destCursor = c;
            destCursor++;
        } while (c != 0);
    }
    return destination;
}

/** strncpy: copy up to arg2 bytes from arg1 to arg0, NUL-padding the remainder. */
u8 *func_802A0294_de(u8 *destination, u8 *source, s32 count) {
    s32 remaining;
    u8 *start;
    u8 *destCursor;
    u8 *sourceCursor;
    u8 c;

    destCursor = destination;
    sourceCursor = source;
    remaining = count;
    start = destCursor;
    if (remaining != 0) {
    loop_1:
        c = *sourceCursor;
        sourceCursor += 1;
        *destCursor = c;
        destCursor += 1;
        if (c & 0xFF) {
            remaining -= 1;
            if (remaining != 0) {
                goto loop_1;
            }
        }
        if (remaining != 0) {
            remaining -= 1;
            if (remaining != 0) {
                do {
                    *destCursor = 0;
                    remaining -= 1;
                    destCursor += 1;
                } while (remaining != 0);
            }
        }
    }
    return start;
}

u8 *func_802A02E8_de(u8 *destination, u8 *source) {
    u8 *sourceCursor;
    u8 *destCursor;
    u8 c;
    sourceCursor = source;
    destCursor = destination;
    if (*destination != 0) {
        do {
            destCursor += 1;
        } while (*destCursor != 0);
    }
    do {
        c = *sourceCursor;
        sourceCursor += 1;
        *destCursor = c;
        destCursor += 1;
    } while (c & 0xFF);
    return destination;
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

s32 Resmgr_CompareStrings(const void *arg0, const void *arg1) {
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

s32 func_802A03AC_de(u8 *a, u8 *b, s32 count) {
    u8 *aCursor;
    u8 *bCursor;
    u8 c;
    aCursor = a;
    bCursor = b;
    if (count == 0) {
        return 0;
    }
    count -= 1;
    while (count != 0 && (c = *aCursor) != 0 && c == *bCursor) {
        count -= 1;
        aCursor += 1;
        bCursor += 1;
    }
    return *aCursor - *bCursor;
}

s32 func_802A03F4_de(u8 *a, u8 *b)
{
  s32 c2;
  int letterA;
  s32 c1;
  c2 = *b;
  b += 1;
  letterA = 0x41;
  if (c2 >= letterA)
  {
    if (c2 < 0x5B)
    {
      c2 += 0x20;
    }
  }
  c1 = *a;
  a += 1;
  if (c1 >= letterA)
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
      return func_802A03F4_de(a, b);
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
u8 *func_802A0494_de(u8 *string) {
    u8 *cursor;
    u8 c;
    cursor = string;
    if (string == 0) {
        return 0;
    }
    if (*string != 0) {
        do {
            c = *cursor;
            if ((u32)(c - 0x61) < 0x1AU) {
                *cursor = c - 0x20;
            }
            cursor += 1;
        } while (*cursor != 0);
    }
    return string;
}

/** In-place ASCII-lowercase a NUL-terminated string; NULL-safe. */
u8 *func_802A04E0_de(u8 *string) {
    u8 *cursor;
    u8 c;
    cursor = string;
    if (string == 0) {
        return 0;
    }
    if (*string != 0) {
        do {
            c = *cursor;
            if ((u32)(c - 0x41) < 0x1AU) {
                *cursor = c + 0x20;
            }
            cursor += 1;
        } while (*cursor != 0);
    }
    return string;
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
int func_802A05A0_de(int c) {
    if ((unsigned int)(c - 'a') < 26) {
        c -= 'a' - 'A';
    }
    return c;
}

/** Convert an uppercase ASCII letter to lowercase. */
int func_802A05B8_de(int c) {
    if ((unsigned int)(c - 'A') < 26) {
        c += 'a' - 'A';
    }
    return c;
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

void *Resmgr_CopyBytes(void *destination, const void *source, s32 bytes) {
    void *result = destination;
    if (bytes != 0) {
        result = func_8029F470_de(destination, source, bytes);
    }
    return result;
}

/* Fills arg2 bytes at arg0 with the byte arg1, storing single bytes up to word alignment, replicated words through the middle and single bytes at the tail, and returns arg0. Adapted from Resmgr_FillMemory. */
void *Resmgr_FillBytes(void *destination, int value, u32 count) {
    u8 *start;
    u8 *end;
    u8 *cur;
    u8 *next;
    u32 fillByte;
    u32 fillWord;
    start = destination;
    end = start + count;
    fillByte = value & 0xFF;
    fillWord = (fillByte << 24) | (fillByte << 16) | (fillByte << 8) | fillByte;
    cur = start;
    if (cur >= end) {
        goto word_test;
    }
align_test:
    if (!((u32)cur & 3)) {
        goto word_test;
    }
    *cur = value;
    cur += 1;
    if (cur < end) {
        goto align_test;
    }
    goto word_test;
word_test:
    next = cur + 4;
    while (next < end) {
        *(u32 *)cur = fillWord;
        cur = next;
        next = cur + 4;
    }
    if (cur < end) {
        do {
            *cur++ = value;
        } while (cur < end);
    }
    return start;
}

u8 *func_802A07DC_de(u8 *buffer, s32 value, s32 length) {
    u8 *p;
    s32 count;
    p = buffer;
    count = length;
    if (count != 0) {
        value = value & 0xFF;
loop:
        if (*p != value) {
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

s32 func_802A0814_de(u8 *a, u8 *b, s32 count) {
    u8 *aCursor;
    u8 *bCursor;
    u8 *end;
    u8 bByte;
    u8 aByte;
    aCursor = a;
    bCursor = b;
    end = aCursor + count;
    if (count < 4) {
        goto block_17;
    }
    if ((u32)aCursor & 3) {
        goto block_17;
    }
    if ((u32)bCursor & 3) {
        goto block_17;
    }
    end -= 4;
    if (end < aCursor) {
        end += 4;
        goto block_16;
    }
loop_6:
    if (*(u32 *)aCursor != *(u32 *)bCursor) {
        aCursor -= 4;
        bCursor -= 4;
        goto block_11;
    }
    aCursor += 4;
    bCursor += 4;
    if (end >= aCursor) {
        goto loop_6;
    }
block_11:
    end += 4;
    goto block_16;
block_12:
    aByte = *aCursor;
    bByte = *bCursor;
    if (aByte == bByte) {
        aCursor += 1;
        bCursor += 1;
        goto block_16;
    }
    if (aByte < bByte) {
        return -1;
    }
    return 1;
block_16:
    ;
block_17:
    if (aCursor < end) {
        goto block_12;
    }
    return 0;
}

/** Compute a CRC-32 over arg1 bytes, continuing from arg2. */
u32 func_802A08B8_de(u8 *data, u32 length, u32 crc) {
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
    end = data + length;
    crc = ~crc;
    while (data < end) {
        crc = table[(crc ^ *data++) & 0xFF] ^ ((crc >> 8) & 0xFFFFFF);
    }
    return ~crc;
}

/* Builds a path from drive, directory, filename and extension components. */
void func_802A0960_de(u8 *path, u8 *drive, u8 *directory, u8 *name, u8 *extensionArg) {
    u8 *extension = extensionArg;
    u8 *out;
    u8 *cursor;
    u8 driveLetter;
    u8 lastDirChar;
    u8 dirChar;
    u8 extFirst;
    u8 nameChar;
    u8 extChar;
    out = path;
    cursor = directory;
    if (drive != 0) {
        driveLetter = *drive;
        if (driveLetter != 0) {
            *out++ = driveLetter;
            *out++ = 0x3A;
        }
    }
    if ((cursor != 0) && (*cursor != 0)) {
        do {
            dirChar = *cursor;
            cursor += 1;
            *out = dirChar;
            out += 1;
        } while (cursor[0] != 0);
        lastDirChar = cursor[-1];
        if ((lastDirChar != 0x2F) && (lastDirChar != 0x5C)) {
            *out = 0x5C;
            out += 1;
        }
    }
    if (name != 0) {
        nameChar = *name;
        cursor = name;
        if (nameChar != 0) {
            do {
                cursor += 1;
                *out = nameChar;
                nameChar = *cursor;
                out += 1;
            } while (nameChar != 0);
        }
    }
    if (extension != 0) {
        cursor = extension;
        extFirst = *cursor;
        if (extFirst != 0) {
            if (extFirst != 0x2E) {
                *out = 0x2E;
                out += 1;
            }
            extChar = *cursor;
            if (extChar != 0) {
                do {
                    cursor += 1;
                    *out = extChar;
                    extChar = *cursor;
                    out += 1;
                } while (extChar != 0);
            }
        }
    }
    *out = 0;
}

void func_802A0A48_de(void *messageSemaphore) {
    MessageSemaphore *semaphore = messageSemaphore;
    osCreateMesgQueue(messageSemaphore, &semaphore->message, 1);
    osSendMesg(messageSemaphore, 1, 1);
}

void func_802A0A84_de(s32 arg0) {
    osRecvMesg(arg0, arg0 + 0x18, 1);
}

void func_802A0AA4_de(s32 *arg0) {
    osSendMesg(arg0, 1, 1);
}

#if defined(VERSION_US)
unsigned int func_802A0AA4_de_padding_A1604[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int func_802A0AA4_de_padding_A17E4[1] = {
    0x00000000,
};
#endif
