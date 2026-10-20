#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "SDK/AUDIO/802C3EA4_4.H"

extern void func_802BF388_de(void *arg0);


extern unsigned short D_800D54C2;

extern DecodeState D_8014BA38_de;

extern char D_8014BCF0_de;
extern unsigned int D_8014BA48_de;

void *func_802C016C_de(void) {
    struct DecodeState *base = &D_8014BA38_de;
    unsigned short *counter;
    char *slots;
    unsigned short temp;

    if (base->count == 0) {
        return 0;
    }
    func_802BF388_de(base);
    counter = &D_800D54C2;
    temp = *counter + 1;
    *counter = temp;
    if ((unsigned int)(temp & 0xFFFF) >= 6) {
        *counter = 0;
    }
    slots = &D_8014BCF0_de;
    func_802BFAAC_de(slots + (*counter << 9), base);
    base->count = base->count - 1;
    return slots + (*counter << 9);
}

/** Return the global state word. */
unsigned int func_802C020C_de(void) {
    return D_8014BA48_de;
}

/** Clear the global word at VRAM 0x80151CD8. */
void func_802C021C_de(void) {
    D_8014BA48_de = 0;
}
