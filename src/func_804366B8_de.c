#include "span_16E000/code_804366C4.h"
#include "types.h"

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5690 holds through func_8041AD10_de and func_8041A6EC_de. */


extern struct State_func_804366B8_de *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146417[];
extern void func_8041AD10_de(void *, s32);
extern void func_8041A6EC_de(void *, s32);

void func_804366B8_de(s32 arg0) {
    u8 *slot = &D_80146417[arg0 * 0x96];

    *slot = arg0;
    func_8041AD10_de(D_800E5690->a, D_80102C89[arg0 * 0x190]);
    func_8041AD10_de(D_800E5690->b, D_800FEC8A[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5690->c, D_800FEC8B[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5690->d, D_800FEC8C[arg0 * 0x190]);
    func_8041AD10_de(D_800E5690->e, D_800FEC8D[arg0 * 0x190]);
}

/* Reads five settings from the objects D_800E5690 holds through func_8041AD04_de and func_8041A6E0_de into slot arg0 of the D_80102C89 table and copies them into the matching bytes of the arg0 entry of D_80146398. */


extern struct State_func_804366B8_de *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146398[];
extern s32 func_8041AD04_de(void *);
extern s32 func_8041A6E0_de(void *);

void func_804367A8_de(s32 arg0) {
    u8 *config;

    config = D_80146398 + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = func_8041AD04_de(D_800E5690->a);
    do {
        D_800FEC8A[arg0 * 0x190] = func_8041AD04_de(D_800E5690->b);
        D_800FEC8B[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->c);
        D_800FEC8C[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->d);
        D_800FEC8D[arg0 * 0x190] = func_8041AD04_de(D_800E5690->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}
