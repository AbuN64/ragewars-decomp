#include "COMMON/UNUSED.H"
#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "RESMGR/E_SMEM.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "RESMGR/FRAME_HEAP_LIFETIME.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "RESMGR/FRAME_HEAP_MARKS.H"
#include "include_asm.h"

/* Sets one heap usage stat {current, lowest, highest}: current = value clamped to +-1e8, then widens the range. */
#define FRAMEHEAP_SET_STAT(stat, value) (stat)[0] = (value); if ((stat)[0] < -100000000.0f) (stat)[0] = -100000000.0f; if ((stat)[0] > 100000000.0f) (stat)[0] = 100000000.0f; if ((stat)[0] < (stat)[1]) (stat)[1] = (stat)[0]; if ((stat)[2] < (stat)[0]) (stat)[2] = (stat)[0];
/* Points the frame heap at buffer D_800CD964[D_80147050_de]: low end = base, high end = base + size, mark stack
 * [0] = base at depth 0; free space = size, low and high usage = 0. Called after the buffers are allocated and on
 * each buffer swap. */
void ESmem_ResetFrameHeap(void) {
    f32 size;
    size = (f32)D_80147054;
    D_801470A8 = D_800CD964[D_80147050_de];
    D_801470A4 = D_800CD964[D_80147050_de] + D_80147054;
    D_80147060[0] = D_801470A8;
    D_801470A0 = 0;
    FRAMEHEAP_SET_STAT(D_800CD96C, size);
    FRAMEHEAP_SET_STAT(D_800CD978, 0.0f);
    FRAMEHEAP_SET_STAT(D_800CD984, 0.0f);
}

s32 ESmem_AllocateFrameHeapLow(s32 arg0) {
    s32 amount;
    s32 result;
    f32 value;

    amount = (arg0 + 7) & -8;
    value = D_800CD978[0] + (f32)amount;
    result = D_801470A8;
    D_801470A8 = result + amount;
    D_800CD978[0] = value;
    if (value < D_800C5D78_de) {
        D_800CD978[0] = D_800C5D78_de;
    }
    if (D_800CD978[0] > *(&D_800C5D78_de + 1)) {
        D_800CD978[0] = *(&D_800C5D78_de + 1);
    }
    if (D_800CD978[0] < D_800CD978[1]) {
        D_800CD978[1] = D_800CD978[0];
    }
    if (D_800CD978[2] < D_800CD978[0]) {
        D_800CD978[2] = D_800CD978[0];
    }

    D_800CD96C[0] += (f32)-amount;
    value = D_800CD96C[0];
    if (value < D_800C5D78_de) {
        D_800CD96C[0] = D_800C5D78_de;
    }
    if (*(&D_800C5D78_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D78_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
    return result;
}

void ESmem_RestoreFrameHeapMark(void) {
    s32 index;
    s32 value;
    s32 amount;
    f32 fvalue;

    index = D_801470A0;
    value = D_80147060[index];
    amount = value - D_801470A8;
    fvalue = D_800CD978[0] + (f32)-amount;
    D_801470A0 = index - 1;
    D_801470A8 = value;
    D_800CD978[0] = fvalue;
    if (fvalue < D_800C5D80_de) {
        D_800CD978[0] = D_800C5D80_de;
    }
    if (D_800CD978[0] > *(&D_800C5D80_de + 1)) {
        D_800CD978[0] = *(&D_800C5D80_de + 1);
    }
    if (D_800CD978[0] < D_800CD978[1]) {
        D_800CD978[1] = D_800CD978[0];
    }
    if (D_800CD978[2] < D_800CD978[0]) {
        D_800CD978[2] = D_800CD978[0];
    }

    D_800CD96C[0] += (f32)amount;
    if (D_800CD96C[0] < D_800C5D80_de) {
        D_800CD96C[0] = D_800C5D80_de;
    }
    if (*(&D_800C5D80_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D80_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
}

s32 ESmem_AllocateFrameHeapHigh(s32 arg0) {
    s32 amount;
    s32 result;

    amount = (arg0 + 7) & -8;
    D_800CD984[0] += (f32)amount;
    result = D_801470A4 - amount;
    D_801470A4 = result;
    if (D_800CD984[0] < D_800C5D88_de) {
        D_800CD984[0] = D_800C5D88_de;
    }
    if (D_800CD984[0] > *(&D_800C5D88_de + 1)) {
        D_800CD984[0] = *(&D_800C5D88_de + 1);
    }
    if (D_800CD984[0] < D_800CD984[1]) {
        D_800CD984[1] = D_800CD984[0];
    }
    if (D_800CD984[2] < D_800CD984[0]) {
        D_800CD984[2] = D_800CD984[0];
    }

    D_800CD96C[0] += (f32)-amount;
    if (D_800CD96C[0] < D_800C5D88_de) {
        D_800CD96C[0] = D_800C5D88_de;
    }
    if (*(&D_800C5D88_de + 1) < D_800CD96C[0]) {
        D_800CD96C[0] = *(&D_800C5D88_de + 1);
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
    return result;
}

extern s32 Cache_AllocateMemory(s32 size);


void ESmem_InitializeFrameHeaps(s32 arg0) {
    extern void ESmem_ResetFrameHeap(void);
    s32 size;

    size = (arg0 + 7) & ~7;
    D_800CD964[0] = Cache_AllocateMemory(size);
    D_800CD964[1] = Cache_AllocateMemory(size);
    D_80147054 = size;
    D_80147050_de = 0;
    ESmem_ResetFrameHeap();
    D_800CD960_de = 1;
}

void ESmem_FreeFrameHeaps(void) {
    if (D_800CD960_de != 0) {
        Cache_FreeMemory(D_800CD964[0]);
        Cache_FreeMemory(D_800CD964[1]);
        D_800CD964[0] = 0;
        D_800CD964[1] = 0;
        D_800CD960_de = 0;
    }
}

void ESmem_SwapFrameHeap(void) {
    void ESmem_ResetFrameHeap(void);
    D_80147050_de = 1 - D_80147050_de;
    ESmem_ResetFrameHeap();
}

void ESmem_PushFrameHeapMark(void) {
    D_80147060[++D_801470A0] = D_801470A8;
}

/** Propagate each array's boundary sample into its two wrap-around slots. */
void ESmem_ResetFrameHeapUsageRanges(void) {
    float *p0 = &D_800CD96C[1];
    float *p1 = &D_800CD978[1];
    float *p2 = &D_800CD984[1];
    float a = p0[-1];
    float b = p1[-1];
    float c = p2[-1];
    p0[0] = a;
    p0[1] = a;
    p1[0] = b;
    p1[1] = b;
    p2[0] = c;
    p2[1] = c;
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A13A4_CBB08[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A13A4_CBB08_us_rev1.c */
const unsigned int D_blob_971722aeb5cf02e05938[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A14B8_CBB10[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A14B8_CBB10_us_rev1.c */
const unsigned int D_blob_4fdfcd07c5175879cca8[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A15E4_CBB18[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A15E4_CBB18_us_rev1.c */
const unsigned int D_blob_fb62923fd7fd34d01190[2] = {
    0xCCBEBC20, 0x4CBEBC20,
};
#endif
