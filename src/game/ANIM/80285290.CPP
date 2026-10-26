#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"
#include "ANIM/80285290_2.H"
#include "stddef.h"

/* Sorts num elements of the given width with a comparator and a swap routine using an iterative quicksort: partitions around the middle element, pushes the larger side onto a 30-entry stack and continues with the smaller, and hands ranges of eight or fewer elements to func_802854B4_de. Written from the classic iterative quicksort structure. */

void func_802852C0_de(char *base, u32 num, u32 width, s32 (*compare)(char *, char *), void (*swap)(char *, char *)) {
    char *lo;
    char *hi;
    char *loguy;
    char *higuy;
    u32 size;
    char *lostk[30];
    char *histk[30];
    s32 stkptr;

    if (num < 2 || width == 0) {
        return;
    }
    stkptr = 0;
    lo = base;
    hi = base + width * (num - 1);
recurse:
    size = (hi - lo) / width + 1;
    if (size <= 8) {
        func_802854B4_de((u32)lo, (u32)hi, width, (s32 (*)(u32, u32))compare, (void (*)(u32, u32))swap);
    } else {
        swap(lo + (size / 2) * width, lo);
        loguy = lo;
        higuy = hi + width;
        for (;;) {
            do {
                loguy += width;
            } while (loguy <= hi && compare(loguy, lo) <= 0);
            do {
                higuy -= width;
            } while (higuy > lo && compare(higuy, lo) >= 0);
            if (higuy < loguy) {
                break;
            }
            swap(loguy, higuy);
        }
        swap(lo, higuy);
        if (higuy - 1 - lo >= hi - loguy) {
            if (lo + width < higuy) {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy - width;
                ++stkptr;
            }
            if (loguy < hi) {
                lo = loguy;
                goto recurse;
            }
        } else {
            if (loguy < hi) {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;
            }
            if (lo + width < higuy) {
                hi = higuy - width;
                goto recurse;
            }
        }
    }
    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;
    }
}

/* Sorts fixed-stride records by selecting a maximum and swapping it to the end. */
void func_802854B4_de(u32 arg0, u32 arg1, s32 width, s32 (*arg3)(u32, u32), void (*arg4)(u32, u32)) {
    u32 var_a0;
    u32 var_s0;
    u32 var_s1;
    u32 var_s2;
    var_s2 = arg1;
    if (arg0 < var_s2) {
        var_s0 = arg0 + width;
        do {
            do { var_s1 = arg0; } while (0);
            if (var_s2 >= var_s0) {
                var_a0 = var_s0;
                do {
                    if (arg3(var_a0, var_s1) > 0) {
                        var_s1 = var_s0;
                    }
                    var_s0 += width;
                    var_a0 = var_s0;
                } while (var_s2 >= var_s0);
            }
            arg4(var_s1, var_s2);
            var_s2 -= width;
            var_s0 = arg0 + width;
        } while (arg0 < var_s2);
    }
}
