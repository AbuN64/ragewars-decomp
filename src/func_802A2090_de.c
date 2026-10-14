#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A1264.h"
#include "span_1000/code_802A208C.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
extern f32 D_800D2988;
extern s32 D_800D2C90;
extern s32 D_800D2C98;
extern StatePair D_800CDA30_de;
extern s8 D_8010BBB8;
extern s32 D_8014288C;
extern s32 func_80299958_de(void);
extern s32 func_802995D4_de(s32, s32, s32, s32, s32);
extern void func_8042E5EC_de(void);
extern void func_8042DEA0_de(void);
extern void func_802A2400_de(f32);
void func_802A2090_de(void) {
    s32 mode;
    s32 value;
    s32 active;
    s32 state;
    if (D_800D2C98 == 1) {
        func_802A17C4_de();
        mode = func_80299958_de();
        func_802995D4_de(mode, 0xE08, 0, 0, 0);
        func_80298FE8_de();
        func_80410448_de();
        func_802A1944_de();
        mode = func_80299958_de();
        active = 1;
        value = 0;
        if (mode == 3) {
            goto mode_three;
        }
        if (mode != 0x18) {
            goto mode_inactive;
        }
        value = 20;
        goto mode_done;
mode_three:
        value = 300;
        goto mode_done;
mode_inactive:
        active = 0;
mode_done:
        if ((D_8014288C == 0) && (active == 1) && ((f32)(value * 15) < D_800CDA30_de.value)) {
            func_8042E5EC_de();
            func_8042DEA0_de();
            func_802A2400_de(0.0f);
        }
        D_800CDA30_de.value += D_800D2988;
        state = D_800CDA30_de.state;
        if (state == 1) {
            D_800CBC14--;
            if (D_800CBC14 <= 0) {
                D_800CBC14 = 60;
                D_8010BBB8 = state;
            }
        }
        if (D_800D2C90 == 1) {
            func_802A2434_de();
        }
    }
}
#if defined(VERSION_DE)
s32 func_802A2224_de();
#elif defined(VERSION_EU)
s32 func_802A2344_eu();
#elif defined(VERSION_EU_X)
s32 func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_802A2164_us();
#endif
s32 func_8041EA70_de();
extern s32 D_800D2C98;
void func_802A21F4_de(void) {
    if (D_800D2C98 == 0) {
        func_8041EA70_de();
#if defined(VERSION_DE)
        func_802A2224_de();
#elif defined(VERSION_EU)
        func_802A2344_eu();
#elif defined(VERSION_EU_X)
        func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
        func_802A2164_us();
#endif
    }
}
