#include "TYPES.H"
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32, s32, s32, s32);
extern s32 D_800C8144_de;
/* Issue the monitor command with interrupts disabled, then restore them. */
s32 func_80201A74_de(void)
{
    s32 previous;
    s32 result;
    previous = func_80200500_de();
    D_800C8144_de = 1;
    result = func_802017E8_de(0x101, 0, 0, 0);
    func_80200538_de(previous);
    return result;
}
