#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "RESMGR/802A23A4_7.H"

void func_802A17C4_de(void) {
    void ESmem_ResetFrameHeap(void);
    D_80147050_de = 1 - D_80147050_de;
    ESmem_ResetFrameHeap();
}

void func_802A17F8_de(void) {
    D_80147060[++D_801470A0] = D_801470A8;
}

/** Propagate each array's boundary sample into its two wrap-around slots. */
void func_802A182C_de(void) {
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
