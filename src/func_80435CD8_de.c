#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_80435CE4.h"
#if defined(VERSION_EU_X)
enum { START_MATCH = 0x43, RETURN_MENU = 0x3E, WAIT_SHORT = 0x42, WAIT_LONG = 0x40 };
#else
enum { START_MATCH = 0x40, RETURN_MENU = 0x3C, WAIT_SHORT = 0x41, WAIT_LONG = 0x3E };
#endif
#include "types.h"

/* Handles the menu message func_80299A08_de reports after func_8029973C_de: 0x40 clears D_80146894 and
   calls func_802A230C_de and func_8025E384_de; 0x3C clears D_80146894 and calls func_80422F9C_de; 0x41 and
   0x3E wait 0x1F and 0x20 through func_80298368_de. Returns zero. */
extern s32 D_80146894;
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_802A230C_de(void);
extern void func_8025E384_de(void);

extern void func_80298368_de(s32);

s32 func_80435CD8_de(void) {
    s32 time;

    func_8029973C_de();
    switch (func_80299A08_de()) {
    case START_MATCH:
        D_80146894 = 0;
        func_802A230C_de();
        func_8025E384_de();
        return 0;
    case RETURN_MENU:
        D_80146894 = 0;
        func_80422F9C_de();
        return 0;
    case WAIT_SHORT:
        time = 0x1F;
        goto wait;
    case WAIT_LONG:
        time = 0x20;
    wait:
        func_80298368_de(time);
        return 0;
    }
    return 0;
}
