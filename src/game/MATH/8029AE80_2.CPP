#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"

void Smos_ClearControllerFlags(void) {
    s32 idx;
    s32 i;
    s32 j;
    Callback *context;

    j = 0;
    do {
        i = 0;
        do {
            idx = i + j * 4;
            i += 1;
            context = D_8014D0B0;
            context->flags[idx] = 0;
        } while (i < 4);
        j += 1;
    } while (j < 0x10);
}
