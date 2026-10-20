#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/80212C90_9.H"

void func_802131AC_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1454V2 *) ((s8 *) ((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8))->unk1454);
    (((struct IntegerState23C *) ((s8 *) temp_a0))->unk_68) = 0;
    (((struct IntegerState23C *) ((s8 *) temp_a0))->unk_238) = 0;
    (((struct IntegerState23C *) ((s8 *) temp_a0))->unk_220) = 0;
    func_80209988_de(temp_a0);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802131D8_de_padding_13DF8);
#endif
