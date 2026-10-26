#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/80212C90_9.H"

void func_802131AC_de(void *actor) {
    void *brain;
    brain = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) actor))->unk1D8))->unk1454);
    (((struct IntegerState23C *) ((s8 *) brain))->unk_68) = 0;
    (((struct IntegerState23C *) ((s8 *) brain))->unk_238) = 0;
    (((struct IntegerState23C *) ((s8 *) brain))->unk_220) = 0;
    Nav_ResetBehaviorState(brain);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int func_802131D8_de_padding_13DF8[2] = {
    0x8E020030, 0x460005C6,
};
#endif
#if defined(VERSION_EU_X)
unsigned int func_802131D8_de_padding_13DF8[2] = {
    0x8E220030, 0x10400006,
};
#endif
#endif
