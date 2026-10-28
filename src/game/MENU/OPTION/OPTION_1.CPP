#include "TYPES.H"
#include "COMMON/RG.H"

extern s32 D_801462C8;
extern s32 D_801462CC;
s32 Menu_UpdateUnlockedOptionLabel(struct Func8043D458Arg *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    if (D_801462CC & arg1) arg0->flags |= 0x01000000;
    else arg0->flags &= 0xFEFFFFFF;
    if (D_801462C8 & arg1) arg0->text = arg2;
    else arg0->text = arg3;
    return 0;
}
