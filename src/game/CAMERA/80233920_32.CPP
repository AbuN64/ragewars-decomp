#include "COMMON/CHANNEL.H"
#include "TYPES.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);
extern void func_80253908_de(s32 unusedHeap);

void func_8023A24C_de(void *bufferOwner) {
    s32 allocationHandle;
    func_80253908_de(0);
    allocationHandle = (((struct IntegerStateF24 *) ((s8 *) bufferOwner))->unk_F18);
    if (allocationHandle != 0) {
        Cache_ReleaseResource(0, allocationHandle);
        (((struct IntegerStateF24 *) ((s8 *) bufferOwner))->unk_F18) = 0;
        (((struct IntegerStateF24 *) ((s8 *) bufferOwner))->unk_F1C) = 0;
        (((struct IntegerStateF24 *) ((s8 *) bufferOwner))->unk_F20) = 0;
    }
}
