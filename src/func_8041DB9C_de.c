#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* Releases the object D_800E3590 holds through func_802547E4_de, clears D_800E3590 and returns zero.
 * The hub names D_800E3590 as the menu block it points at; the release helper takes a plain pointer
 * and the clear stores a null word. */
extern void func_802547E4_de(void *);

s32 func_8041DB9C_de(void) {
    func_802547E4_de(D_800E3590);
    D_800E3590 = 0;
    return 0;
}
