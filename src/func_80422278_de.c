#include "span_16E000/code_804221A0.h"
#include "types.h"

/* Releases the object D_800E44A0 holds through func_802547E4_de, clears D_800E44A0 and returns zero. */
extern void *D_800E44A0;
extern void func_802547E4_de(void *);

s32 func_80422278_de(void) {
    func_802547E4_de(D_800E44A0);
    D_800E44A0 = 0;
    return 0;
}
