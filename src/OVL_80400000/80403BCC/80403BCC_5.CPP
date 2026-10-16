#include "span_1000/code_802636D0.h"
#include "span_16E000/code_80405454.h"
#include "common/unused.h"
#include "TYPES.H"
extern u8 D_8010BBB8;
extern char D_8010FC00[];
extern PakRecord D_80153330[];
s32 func_802B7FD8_de(OSMesgQueue *mq, OSPfs *pfs, int channel);
extern s32 func_80404018_de(s32);

void func_804041F0_de(void) {
    s32 channel;
    s32 present;
    PakRecord *record;
    func_802644FC_de(1);
    func_80263740_de();
    D_8010BBB8 = 2;
    for (channel = 0; channel < 4; channel++) {
        record = &D_80153330[channel];
        if (D_8010FBE3[channel * 4] != 0) {
            present = 0;
            record->present = 0;
        } else {
            record->present = func_802B7FD8_de(D_8010FC00, record->pak, channel) == 0;
            present = record->present;
        }
        if (present) D_801534F0[channel] = 2;
        else if (func_80404018_de(channel) != 0) D_801534F0[channel] = 3;
        else D_801534F0[channel] = 1;
    }
    func_8026454C_de();
}
