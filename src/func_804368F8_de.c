#include "span_16E000/code_804366C4.h"
#include "types.h"

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5694 holds through func_8041AD10_de and func_8041A6EC_de. Adapted from func_804366B8_de with D_800E5690 changed to D_800E5694 and the object fields moved down by eight bytes. */


extern struct State_func_804368F8_de *D_800E5694;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146417[];
extern void func_8041AD10_de(void *, s32);
extern void func_8041A6EC_de(void *, s32);

void func_804368F8_de(s32 arg0) {
    u8 *slot = &D_80146417[arg0 * 0x96];

    *slot = arg0;
    func_8041AD10_de(D_800E5694->a, D_80102C89[arg0 * 0x190]);
    func_8041AD10_de(D_800E5694->b, D_800FEC8A[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5694->c, D_800FEC8B[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5694->d, D_800FEC8C[arg0 * 0x190]);
    func_8041AD10_de(D_800E5694->e, D_800FEC8D[arg0 * 0x190]);
}
