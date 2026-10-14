#include "span_16E000/code_80447BB0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Resets a 0x44-byte record: clears it through func_802A001C_de, initialises the two lists at offsets
   0xC and 0x20 through func_80255CA0_de with 0x16DC and 0x16E0, and clears the words at 0 to 8 and
   0x34 to 0x40. */
extern void func_802A001C_de(void *, s32, s32);

void func_80449DB0_de(struct Record_func_80449DB0_de *record) {
    func_802A001C_de(record, 0, 0x44);
    func_80255CA0_de(&record->listC, 0x16DC, 0x16E0);
    func_80255CA0_de(&record->list20, 0x16DC, 0x16E0);
    record->word0 = 0;
    record->word4 = 0;
    record->word8 = 0;
    record->word34 = 0;
    record->word38 = 0;
    record->word3C = 0;
    record->word40 = 0;
}
