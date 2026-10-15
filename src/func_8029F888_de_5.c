#include "span_1000/code_802A0888.h"
#include "span_1000/code_802A0AC4.h"
#include "types.h"

typedef void (*FuncPtr)(void);

typedef s32 (*ReadByteFn_802A0FCC)(s32, u8 *, s32);

s32 func_80414CCC_de(s32 *, s32, s32);

extern s32 D_8014D0D0;

extern s32 D_800CD924_de;

extern s32 D_800CD928_de;

/* Allocates the resource once and marks its five-word state ready. */
extern s32 D_801011B8;

extern s32 func_8025305C_de(s32 arg0);

extern s32 func_8025637C_de(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 func_802A0724_de(s32, s32, s32);

/** Return the constant false result used by callers at VRAM 0x802A1F50. */
int func_802A0F50_de(void) {
    return 0;
}

/** Return the zero status used by callers. */
int func_802A0F58_de(void) {
    return 0;
}

void func_802A0F60_de(void) {
    extern FuncPtr D_800CD934_de;
    D_800CD934_de();
}

void func_802A0F84_de(void) {
    extern FuncPtr D_800CD938_de;
    D_800CD938_de();
}

void func_802A0FA8_de(void) {
    extern FuncPtr D_800CD93C_de;
    D_800CD93C_de();
}

s32 func_802A0FCC_de(s32 arg0) {
    extern ReadByteFn_802A0FCC D_800CD92C_de;
    u8 sp10;
    s32 result;

    if (D_800CD92C_de(arg0, &sp10, 1) != 0) {
        result = sp10;
    } else {
        result = -1;
    }
    return result;
}

int func_802A1004_de(void) {
    return 0;
}

s32 *func_802A100C_de(s32 arg0, s32 arg1) {
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, arg1);
    return &D_8014D0D0;
}

void func_802A1050_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    extern s32 D_800CD93C_de;
    extern s32 D_800CD938_de;
    extern s32 D_800CD934_de;
    extern s32 D_800CD92C_de;
    D_800CD924_de = arg0;
    D_800CD928_de = arg1;
    D_800CD92C_de = arg2;
    D_800CD930_de = arg3;
    D_800CD934_de = arg4;
    D_800CD938_de = arg5;
    D_800CD93C_de = arg6;
}

void func_802A109C_de(void) {
    s32 temp_v0;
    s32 *p2;
    if (D_800CD940_de[4] != 1) {
#if defined(VERSION_DE)
        D_800CD940_de[2] = 0x8BB01;
        temp_v0 = func_8025305C_de(0x8BB01);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        D_800CD940_de[2] = 0x8B245;
        temp_v0 = func_8025305C_de(0x8B245);
#elif defined(VERSION_EU_X)
        D_800CD940_de[2] = 0x90385;
        temp_v0 = func_8025305C_de(0x90385);
#endif
        D_800CD940_de[0] = temp_v0;
        func_8025637C_de(&D_801011B8, 0x200000, D_800CD940_de[2], temp_v0);
        p2 = &D_800CD940_de[0];
        p2[3] = 0;
        D_800CD940_de[4] = 1;
    }
}

void func_802A1114_de(void) {
    if (D_800CD940_de[0] != 0) {
        func_802547E4_de(D_800CD940_de[0]);
    }
    D_800CD940_de[0] = 0;
    D_800CD940_de[3] = 0;
    D_800CD940_de[4] = 0;
}

void func_802A1158_de(void *arg0, u8 *arg1) {
    extern s32 D_800CD944_de[3];
    while (*arg1 != 0) {
        arg1++;
    }
    arg1++;
    D_800CD944_de[0] = 0;
    D_800CD944_de[2] = 1;
}

/** Clear the global word at VRAM 0x800D2BBC. */

void func_802A1188_de(void) {
    D_800CD940_de[3] = 0;
}

s32 func_802A1198_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 *p;

    p = D_800CD940_de;
    func_802A0724_de(arg1, p[0] + p[1], arg2);
    p[1] = p[1] + arg2;
    return 1;
}

/** Return the false result used by callers at VRAM 0x802A21EC. */
int func_802A11EC_de(void) {
    return 0;
}

s32 func_802A11F4_de(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_800CD944_de;
    s32 *p;

    if (arg2 == 0) {
        D_800CD944_de = 0;
    }
    p = &D_800CD944_de;
    *p = *p + arg1;
    return 0;
}

/** Return the first global state word. */
unsigned int func_802A1220_de(void) {
    extern unsigned int D_800CD944_de;
    return D_800CD944_de;
}
