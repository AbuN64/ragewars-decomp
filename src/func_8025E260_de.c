#include "span_1000/code_8025E280.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "common/unused.h"

extern s32 D_8010C080;

/** Read the global word at VRAM 0x8010DE0C. */


s32 func_80258E5C_de(s32 *, f32);

s32 func_80258740_de(s32 *);

void func_8025E260_de(int arg0)
{
  int new_var;
  new_var = arg0 != 0;
  D_801081B4 = (s32) arg0;
  if (new_var)
  {
    if (1)
    {
      func_8025E3CC_de();
    }
    return;
  }
  func_8025E3A8_de();
}

void func_8025E29C_de(s32 arg0) {
    func_80258D08_de(&D_8010C080, arg0);
}

int func_8025E2C4_de(void) {
    return D_80109E0C;
}

void func_8025E2D4_de(s32 a) {
    if (D_801427D0 == 0) {
        s32 *p = &D_80109E0C;
        if (*p != a) {
            *p = a;
            if (a == 0) {
                func_8025E318_de();
            }
        }
    }
}

void func_8025E318_de(void) {
    func_80258CEC_de((s32) &D_8010C080);
}

void func_8025E33C_de(void) {
    func_80258E40_de((s32) &D_8010C080);
}

void func_8025E360_de(void) {
    func_80258EBC_de((s32) &D_8010C080);
}

void func_8025E384_de(void) {
    func_80258ED8_de((s32) &D_8010C080);
}

void func_8025E3A8_de(void) {
    func_80258D1C_de(&D_8010C080, 0);
}

void func_8025E3CC_de(void) {
    func_80258D1C_de(&D_8010C080, 1);
}

void func_8025E3F0_de(s32 arg0) {
    func_80258D24_de(&D_8010C080, arg0);
}

void func_8025E418_de(s32 arg0) {
    func_80258D48_de(&D_8010C080, arg0);
}

void func_8025E440_de(f32 arg0) {
    func_80258E5C_de(&D_8010C080, arg0);
}

void func_8025E468_de(void) {
    func_80258EF4_de((s32) &D_8010C080);
}

void func_8025E48C_de(void) {
    func_80258740_de(&D_8010C080);
}
