#include "span_1000/code_8028469C.h"
#include "types.h"

/* Sorts num elements of the given width with a comparator and a swap routine using an iterative quicksort: partitions around the middle element, pushes the larger side onto a 30-entry stack and continues with the smaller, and hands ranges of eight or fewer elements to func_802854B4_de. Written from the classic iterative quicksort structure. */

extern void func_802854B4_de(char *lo, char *hi, u32 width, s32 (*compare)(char *, char *), void (*swap)(char *, char *));

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
        func_802854B4_de(lo, hi, width, compare, swap);
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
