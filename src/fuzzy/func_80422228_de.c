#include "TYPES.H"

extern void *func_8025305C_de(s32 size);
extern s32 *D_800E44A0;
extern void func_8043C210_de(s32 *, s32, s32, s32, s32);

s32 func_80422228_de(void) {
    s32 *record = func_8025305C_de(0x24);
    D_800E44A0 = record;
    record[7] = 0;
    record[8] = 0;
    func_8043C210_de(record, 0x67, 0, 0, 0);
    return 0;
}
