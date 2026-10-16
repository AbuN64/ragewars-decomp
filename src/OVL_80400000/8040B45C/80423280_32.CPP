#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_16E000/code_8041B020.h"
#include "span_176000/code_80405DC4.h"
#include "TYPES.H"
/* Marks two loading-screen hint slots (0x1D9 and 0x1DA) unused. */



s32 func_80429178_us_rev1(void) {
    func_8041B110_de(0x1D9);
    func_8041B110_de(0x1DA);
    return 0;
}
