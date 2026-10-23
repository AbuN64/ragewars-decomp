#include "RENDER_3/RANGENODE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"



void *func_80268C1C_de(void *intrusiveList, void *arg1) {
    void *temp_s0;

    temp_s0 = ((IntrusiveList *)intrusiveList)[1].head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&((IntrusiveList *)intrusiveList)[1], temp_s0);
        func_80255CB8_de(intrusiveList, temp_s0);
        ((RangeNode *)temp_s0)->radius = arg1;
        ((RangeNode *)temp_s0)->active = 0;
    }
    return temp_s0;
}

void func_80268C7C_de(void *a, s32 b) {
    (((struct Limit *) ((s8 *) b))->limit) = 0;
    func_80255ED8_de(a, b);
    func_80255CB8_de(a + 0x14, b);
}
