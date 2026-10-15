#include "span_16E000/code_80405454.h"
#include "span_1000/code_802636D0.h"
extern u8 D_8010FBE3[], D_8010BBB8;
extern char D_8010FC00[];
extern PakRecord D_80153330[];
extern s32 func_802B7FD8_de(void *, void *, s32);
extern s32 func_80404018_de(s32);
extern void func_80263740_de(void);

void func_804041E8_de(void) {
    s32 channel;
    s32 present;
    PakRecord *record;
    func_802644FC_de(1);
    func_80263740_de();
    D_8010BBB8 = 2;
    for (channel = 0; channel < 4; channel++) {
        record = &D_80153330[channel];
        present = 0;
        if (D_8010FBE3[channel * 4] == 0) {
            present = func_802B7FD8_de(D_8010FC00, record->pak, channel) == 0;
            record->present = present;
        } else {
            record->present = 0;
        }
        if (present) D_801534F0[channel] = 2;
        else if (func_80404018_de(channel) == 0) D_801534F0[channel] = 1;
        else D_801534F0[channel] = 3;
    }
    func_8026454C_de();
}
