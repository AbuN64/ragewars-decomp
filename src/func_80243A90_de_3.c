#include "span_1000/code_80243A80.h"
#include "span_1000/code_80245980.h"
#include "types.h"
/* Zeroes the resident game-state block, sets its four persistent-slot markers to -1, then runs the two state-machine resets that depend on it. */

extern s32 *D_800E2830;




void func_80244D70_de(void)
{
    s32 *p = D_800E2830;

    p[0x0 / 4] = 0;
    p[0x4 / 4] = 0;
    p[0x8 / 4] = 0;
    p[0xc / 4] = 0;
    p[0x10 / 4] = 0;
    p[0x14 / 4] = 0;
    p[0x18 / 4] = 0;
    p[0x1c / 4] = 0;
    p[0x20 / 4] = 0;
    p[0x24 / 4] = 0;
    p[0x28 / 4] = 0;
    p[0x2c / 4] = 0;
    p[0x30 / 4] = 0;
    p[0x34 / 4] = 0;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    p[0x40 / 4] = 0;
    p[0x44 / 4] = 0;
    p[0x48 / 4] = 0;
    p[0x4c / 4] = 0;
    p[0x50 / 4] = 0;
    p[0x54 / 4] = 0;
    p[0x58 / 4] = 0;
    p[0x5c / 4] = 0;
    p[0x60 / 4] = 0;
    p[0x64 / 4] = 0;
    p[0xb4 / 4] = 0;
    p[0xb8 / 4] = 0;
    p[0xbc / 4] = -1;
    p[0xc0 / 4] = -1;
    p[0xc4 / 4] = 0;
    p[0xc8 / 4] = 0;
    p[0xcc / 4] = 0;
    p[0xd0 / 4] = 0;
    p[0xd4 / 4] = 0;
    p[0xd8 / 4] = -1;
    p[0xdc / 4] = -1;
    p[0xe0 / 4] = -1;
    p[0xe4 / 4] = 0;
    p[0xe8 / 4] = 0;
    p[0xec / 4] = 0;
    p[0xf0 / 4] = 0;
    p[0xf4 / 4] = 0;
    p[0xf8 / 4] = 0;
    p[0xfc / 4] = 0;
    p[0x100 / 4] = 0;
    p[0x104 / 4] = 0;

    func_80245A30_de();
    func_80245AC8_de();
}
