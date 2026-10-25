#include "TYPES.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "sdk/os.h"

extern s32 D_8014EA78;
void func_802B9C80_de(void) {
    osSendMesg(&D_8014EA78, 0, 0);
}
