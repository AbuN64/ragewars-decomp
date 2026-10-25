#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "sdk/OS_2/802BECB0.H"
#include "sdk/os.h"

void func_802B9BC0_de(void) {
    extern s32 D_8014EA78;
    extern s32 D_8014EA70;
    extern s32 D_800D83D0;
    D_800D83D0 = 1;
    osCreateMesgQueue(&D_8014EA78, &D_8014EA70, 1);
    osSendMesg(&D_8014EA78, 0, 0);
}
