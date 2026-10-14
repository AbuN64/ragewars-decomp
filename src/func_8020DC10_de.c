#include "span_1000/code_8020D370.h"
#include "types.h"
#include "span_1000/code_80208000.h"

extern void func_8020DCA0_de(void);
extern void func_8020DC60_de(void *arg0);




s32 func_8020DC10_de(void *arg0) {
    if ((s32)((AiController *)arg0)->target != 0) {
        if ((u32) (((AiController *)arg0)->state - 3) < 3U) {
            func_8020DCA0_de();
            return 1;
        }
        func_8020DC60_de(arg0);
        return 1;
    }
    return 1;
}
