#include "common/types_8a8189af7b05.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_80405DC0.h"
#include "types.h"
#include "common/unused.h"

extern SlotDialog *D_800E3518;

/* The slot-error scalar is real external storage in every ROM version. */
#if defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_US)
#elif defined(VERSION_EU_X)
extern s32 D_800EACF4;
#else
extern s32 D_800E3514;
#endif

#if defined(VERSION_EU)
extern s32 D_800EFB34;
#elif defined(VERSION_DE)
extern s32 D_800DF4C4;
#elif defined(VERSION_US)
extern s32 D_800DE174;
#else
#endif
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_8041BE90_de(void);
extern void func_8041C244_de(void);
extern void func_80434FB4_de(s32);
extern void func_80298368_de(s32);

/* The dialog-event codes func_80299A08_de reports differ per cartridge family: the European
   eu-x cart numbers them 0x3C9..0x3CF, the de cart 0x3C1..0x3C5, and eu/us/us-rev1 0x3C6..0x3CB.
   Each case below carries the same work in every family, only its label changes. */
s32 func_8041C494_de(void) {
    func_8029973C_de();
    switch (func_80299A08_de()) {
#if defined(VERSION_EU_X)
    case 0x3CF:
#elif defined(VERSION_DE)
    case 0x3C4:
#else
    case 0x3CB:
#endif
        func_8040E8D8_de((void *)D_800E3518->absent, 0);
        func_8041BE90_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3CE:
#elif defined(VERSION_DE)
    case 0x3C5:
#else
    case 0x3CA:
#endif
        func_8041C164_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3CA:
#elif defined(VERSION_DE)
    case 0x3C2:
#else
    case 0x3C7:
#endif
        func_8041C244_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3C9:
#elif defined(VERSION_DE)
    case 0x3C1:
#else
    case 0x3C6:
#endif
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
#if defined(VERSION_EU)
        D_800EFB34 = 1;
#elif defined(VERSION_EU_X)
        D_800EACF4 = 1;
#elif defined(VERSION_DE)
        D_800DF4C4 = 1;
#elif defined(VERSION_US)
        D_800DE174 = 1;
#else
        D_800E3514 = 1;
#endif
        func_80434FB4_de(6);
        func_80298368_de(0x13);
        break;
    }
    return 0;
}
