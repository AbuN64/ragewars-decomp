#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BE0D0.h"
extern void func_802BF388_de(void *arg0);
extern void func_802BFAAC_de(void *arg0, void *arg1);
extern unsigned short D_800D54C2;
extern DecodeState D_8014BA38_de;
extern char D_8014BCF0_de;




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
