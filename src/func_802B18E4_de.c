#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B0388.h"
#include "types.h"

extern void func_802B1A40_de(void *arg0, s32 arg1);
extern void func_802B1AC0_de(void *arg0, void *arg1, s32 arg2);








void func_802B18E4_de(void *arg0, void *arg1) {
    s32 i;
    ALBank_s *p;
    void *found;

    p = arg1;
    i = 0;
    do {
        found = p->instArray[i];
        i++;
    } while (found == 0);
    i = 0;
    if (((ALSeqPlayer_func_802B0C94_de *)arg0)->maxChannels != 0) {
        do {
            func_802B1A40_de(arg0, i);
            func_802B1AC0_de(arg0, found, i);
            i += 1;
        } while (i < ((ALSeqPlayer_func_802B0C94_de *)arg0)->maxChannels);
    }
    if (((ALBank_s *)arg1)->percussion != 0) {
        func_802B1A40_de(arg0, i);
        func_802B1AC0_de(arg0, ((ALBank_s *)arg1)->percussion, 9);
    }
}
