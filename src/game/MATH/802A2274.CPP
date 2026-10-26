#include "COMMON/UNUSED.H"
#include "COMMON/RECORD.H"
#include "TYPES.H"
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
