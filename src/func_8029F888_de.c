#include "span_1000/code_802A0888.h"
#include "types.h"

/* Splits a path into drive, directory, file name and extension like _splitpath: a leading "X:" goes to the drive, everything through the last '/' or '\\' to the directory, the rest up to the last '.' at or after that point to the name and from the '.' on to the extension (or all of it to the name when there is none), each copied with a bounded strncpy and terminated, and any missing part cleared. */

static inline s32 path_length(u8 *s) {
    u8 *p = s;

    while (*p++) {
    }
    return p - s - 1;
}

static inline void copy_part(u8 *d, u8 *s, s32 n) {
    if (n != 0) {
    copy:
        if ((*d++ = *s++) != 0) {
            if (--n != 0) {
                goto copy;
            }
        }
        if (n != 0) {
            while (--n != 0) {
                *d++ = 0;
            }
        }
    }
}

void func_8029F888_de(u8 *path, u8 *drive, u8 *dir, u8 *name, u8 *ext) {
    u8 *dot;
    u8 *slash;
    u8 *p;
    s32 n;

    slash = 0;
    dot = 0;
    if (path_length(path) > 0 && path[1] == ':') {
        if (drive != 0) {
            copy_part(drive, path, 2);
            drive[2] = 0;
        }
        path += 2;
    } else if (drive != 0) {
        *drive = 0;
    }
    for (p = path; *p != 0; p++) {
        if (*p == '/' || *p == '\\') {
            slash = p + 1;
        } else if (*p == '.') {
            dot = p;
        }
    }
    if (slash != 0) {
        if (dir != 0) {
            n = slash - path;
            if (n >= 0x100) {
                n = 0xFF;
            }
            copy_part(dir, path, n);
            dir[n] = 0;
        }
        path = slash;
    } else if (dir != 0) {
        *dir = 0;
    }
    if (dot != 0 && dot >= path) {
        if (name != 0) {
            n = dot - path;
            if (n >= 0x100) {
                n = 0xFF;
            }
            copy_part(name, path, n);
            name[n] = 0;
        }
        if (ext != 0) {
            n = p - dot;
            if (n >= 0x100) {
                n = 0xFF;
            }
            copy_part(ext, dot, n);
            ext[n] = 0;
        }
    } else {
        if (name != 0) {
            n = p - path;
            if (n >= 0x101) {
                n = 0x100;
            }
            copy_part(name, path, n);
            name[n] = 0;
        }
        if (ext != 0) {
            *ext = 0;
        }
    }
}

/* Quick-sorts the elements between base and max for func_8029FE38_de (the qsort helper qst): picks the median of the first, middle and last elements as the pivot when the span reaches the six-element threshold D_8014D0C8, partitions around it with the comparator D_8014D0CC swapping D_8014D0C0 bytes at a time, then recurses into the smaller side and loops on the larger while it spans at least D_8014D0C4 bytes. Written from the BSD qsort qst structure with the halving shift unsigned. */






void func_8029FB74_de(char *base, char *max) {
    char c;
    char *i;
    char *j;
    char *jj;
    s32 ii;
    char *mid;
    char *tmp;
    s32 lo;
    s32 hi;

    lo = max - base;
    do {
        mid = i = base + D_8014D0C0 * ((unsigned)(lo / D_8014D0C0) >> 1);
        if (lo >= D_8014D0C8) {
            j = (D_8014D0CC((jj = base), i) > 0 ? jj : i);
            if (D_8014D0CC(j, (tmp = max - D_8014D0C0)) > 0) {
                j = (j == jj ? i : jj);
                if (D_8014D0CC(j, tmp) < 0) {
                    j = tmp;
                }
            }
            if (j != i) {
                ii = D_8014D0C0;
                do {
                    c = *i;
                    *i++ = *j;
                    *j++ = c;
                } while (--ii);
            }
        }
        for (i = base, j = max - D_8014D0C0;;) {
            while (i < mid && D_8014D0CC(i, mid) <= 0) {
                i += D_8014D0C0;
            }
            while (j > mid) {
                if (D_8014D0CC(mid, j) <= 0) {
                    j -= D_8014D0C0;
                    continue;
                }
                tmp = i + D_8014D0C0;
                if (i == mid) {
                    mid = jj = j;
                } else {
                    jj = j;
                    j -= D_8014D0C0;
                }
                goto swap;
            }
            if (i == mid) {
                break;
            } else {
                jj = mid;
                tmp = mid = i;
                j -= D_8014D0C0;
            }
swap:
            ii = D_8014D0C0;
            do {
                c = *i;
                *i++ = *jj;
                *jj++ = c;
            } while (--ii);
            i = tmp;
        }
        i = (j = mid) + D_8014D0C0;
        if ((lo = j - base) <= (hi = max - i)) {
            if (lo >= D_8014D0C4) {
                func_8029FB74_de(base, j);
            }
            base = i;
            lo = hi;
        } else {
            if (hi >= D_8014D0C4) {
                func_8029FB74_de(i, max);
            }
            max = j;
        }
    } while (lo >= D_8014D0C4);
}

/* Sorts n elements of the given size with a comparator (qsort): records the element size, the four- and six-element thresholds and the comparator in D_8014D0C0 to D_8014D0CC, quick-sorts arrays of four or more through func_8029FB74_de, swaps the smallest of the first elements into place as a sentinel, and finishes with an insertion sort that shifts bytes. Written from the BSD qsort driver structure. */







void func_8029FE38_de(char *base, s32 n, s32 size, s32 (*compare)(char *a, char *b)) {
    char c;
    char *i;
    char *j;
    char *lo;
    char *hi;
    char *min;
    char *max;

    if (n <= 1) {
        return;
    }
    D_8014D0C4 = size * 4;
    D_8014D0C8 = size * 6;
    D_8014D0C0 = size;
    D_8014D0CC = compare;
    max = base + n * size;
    if (n >= 4) {
        func_8029FB74_de(base, max);
        hi = base + D_8014D0C4;
    } else {
        hi = max;
    }
    for (j = lo = base; (lo += D_8014D0C0) < hi;) {
        if (D_8014D0CC(j, lo) > 0) {
            j = lo;
        }
    }
    if (j != base) {
        for (i = base, hi = base + D_8014D0C0; i < hi;) {
            c = *j;
            *j++ = *i;
            *i++ = c;
        }
    }
    for (min = base; (hi = min += D_8014D0C0) < max;) {
        while (D_8014D0CC(hi -= D_8014D0C0, min) > 0) {
        }
        if ((hi += D_8014D0C0) != min) {
            for (lo = min + D_8014D0C0; --lo >= min;) {
                c = *lo;
                for (i = j = lo; (j -= D_8014D0C0) >= hi; i = j) {
                    *i = *j;
                }
                *i = c;
            }
        }
    }
}

void *func_802A001C_de(void *arg0, int arg1, u32 arg2) {
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
