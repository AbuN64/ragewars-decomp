#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RESMGR/802A23A4_6.H"
#include "SCENE/802508E0_13.H"

extern s32 Cache_AllocateMemory(s32 arg0);


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
