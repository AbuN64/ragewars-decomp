#include "span_1000/code_80208000.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

typedef s32 (*Handler)(void *arg0);

extern Handler *D_800C8DB0_de[];




void func_80211020_de(void *arg0) {
    s32 origIdx;
    s32 idx;
    s32 idx2;
    Handler *table;
    Handler fn;
    s32 result;

    origIdx = ((AiController *)arg0)->state;
    if ((u32)origIdx >= 0xE) {
        ((AiController *)arg0)->state = 0;
    }
    idx = ((AiController *)arg0)->state;
    table = D_800C8DB0_de[idx];
    if (table != 0) {
        idx2 = ((AiController *)arg0)->handlerIndex;
        fn = table[idx2];
        if (fn == 0) {
            ((AiController *)arg0)->handlerIndex = 0;
            fn = table[0];
        }
        if (fn != 0) {
            result = fn(arg0);
            if (result != 0) {
                ((AiController *)arg0)->handlerIndex = ((AiController *)arg0)->handlerIndex + 1;
            }
            if (((AiController *)arg0)->state != origIdx) {
                ((AiController *)arg0)->handlerIndex = 0;
            }
        }
    }
}
