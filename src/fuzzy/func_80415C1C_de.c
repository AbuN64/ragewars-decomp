#include "TYPES.H"
extern void osViBlack(s32 enabled);
/* Blink the diagnostic indicator forever except for reason five. */
void func_80415C1C_de(s32 reason)
{
    u32 counter = 0;
    while (reason != 5) {
        u32 bit = counter & 0x100000;
        counter++;
        osViBlack(bit != 0);
    }
}
