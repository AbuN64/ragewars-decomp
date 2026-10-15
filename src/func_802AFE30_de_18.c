#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFF30_de(s32 arg0, s32 arg1) {
    Buf16 sp10;

    sp10.value = arg1;
    sp10.count = 0xD;
    func_802B00D4_de(arg0 + 0x48, &sp10, 0);
}

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFF60_de(s32 arg0, s16 arg1) {
    Buf16b sp10;

    sp10.value = arg1;
    sp10.count = 0xA;
    func_802B00D4_de(arg0 + 0x48, &sp10, 0);
}

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFF90_de(s32 arg0) {
    s16 sp10[8];

    sp10[0] = 0x11;
    func_802B00D4_de(arg0 + 0x48, sp10, 0);
}
