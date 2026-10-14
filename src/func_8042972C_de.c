#include "span_16E000/code_804290E8.h"
/* For network-connection-mode 3 events with subcode 2, calls func_8029973C_de and dispatches on
   func_80299A08_de's report to activate one of screen D_800E4EF0's option widgets (default value
   zero), or its player-count widget with the screen's default count. Returns zero. */
#include "types.h"
#include "common/unused.h"

extern struct Screen_func_8042972C_de *D_800E4EF0;
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_802A1B24_de(void *arg0, s32 arg1);

s32 func_8042972C_de(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    u32 kind;
    void *widget;
    s32 value;

    kind = arg2 >> 0x10;
    if ((kind == 3) && (arg3 == 2)) {
        func_8029973C_de();
        switch (func_80299A08_de()) {
#if defined(VERSION_DE)
        case 0x35F:
#elif defined(VERSION_EU_X)
        case 0x367:
#else
        case 0x363:
#endif
            widget = D_800E4EF0->widget24;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x35D:
#elif defined(VERSION_EU_X)
        case 0x365:
#else
        case 0x361:
#endif
            widget = D_800E4EF0->widget28;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x35B:
#elif defined(VERSION_EU_X)
        case 0x363:
#else
        case 0x35F:
#endif
            widget = D_800E4EF0->widget2C;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x361:
#elif defined(VERSION_EU_X)
        case 0x369:
#else
        case 0x365:
#endif
            widget = D_800E4EF0->widget30;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x368:
#elif defined(VERSION_EU_X)
        case 0x370:
#else
        case 0x36C:
#endif
            widget = D_800E4EF0->widget34;
            value = D_800E4EF0->countDefault;
            func_802A1B24_de(widget, value);
            break;
        }
    }
    return 0;
}
