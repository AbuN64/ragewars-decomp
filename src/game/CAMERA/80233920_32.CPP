#include "COMMON/CHANNEL.H"
#include "TYPES.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);
extern void func_80253908_de(s32 unusedHeap);

void func_8023A24C_de(void *arg0) {
    s32 temp_a1;
    func_80253908_de(0);
    temp_a1 = (((struct IntegerStateF24 *) ((s8 *) arg0))->unk_F18);
    if (temp_a1 != 0) {
        Scene_ReleaseResource(0, temp_a1);
        (((struct IntegerStateF24 *) ((s8 *) arg0))->unk_F18) = 0;
        (((struct IntegerStateF24 *) ((s8 *) arg0))->unk_F1C) = 0;
        (((struct IntegerStateF24 *) ((s8 *) arg0))->unk_F20) = 0;
    }
}
