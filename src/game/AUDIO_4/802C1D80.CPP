#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CTX.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "AUDIO_4/802C1D80.H"

void func_802BCC90_de(void) {
    DiskTransferInfo *temp_a2;
    u32 status;

    status = *(volatile u32 *)0xA4600010;
    temp_a2 = (DiskTransferInfo *)(D_801487B4 + 0x14);
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *(volatile u32 *)0xA5000510 = temp_a2->bmControl | 0x10000000;
    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *(volatile u32 *)0xA5000510 = temp_a2->bmControl;
    func_802BCD64_de();
    {
        volatile u32 *statusAddr = (volatile u32 *)0xA4600010;
        s32 mask = 0x100401;
        s32 *flagsAddr = &D_800D5258;
        s32 flags = *flagsAddr;

        *statusAddr = 2;
        *flagsAddr = flags | mask;
    }
}

extern s32 D_800D5268_de;
extern void *__osPopThread(OSMesgQueue *arg0, OSMesgQueue *arg1, Ctx *arg2);
extern void __osEnqueueThread(void *arg0, void *arg1);

void func_802BCD64_de(void) {
    OSMesgQueue *node;
    s32 a0;
    s32 v1;
    s32 v0;
    s32 rem;

    node = D_80149B50.cur;
    if (node != 0) {
        a0 = node->validCount;
        v1 = node->msgCount;
        if (a0 < v1) {
            v0 = node->first + a0;
            rem = v0 % v1;
            node->msg[rem] = D_80149B50.f4;
            node->validCount = node->validCount + 1;
            if (*node->mtqueue != 0) {
                __osEnqueueThread(&D_800D5268_de, __osPopThread(node, node, &D_80149B50));
            }
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BCD4C[1] = {
    0x42697473,
};
#endif
