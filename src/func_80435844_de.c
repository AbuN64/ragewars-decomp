#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* When slot i of the 12-byte records at offset 0x2DF8 of the table D_800E54A4 points to is set,
   passes the 400-byte record i of D_80102B00 to func_8022EF30_de, marks the slot done with 2 and calls
   func_80433BCC_de with -1. */






extern struct Table_func_804352C8_de *D_800E54A4;
extern struct PlayerRecord D_80102B00[];
extern void func_8022EF30_de(struct PlayerRecord *);
extern void func_80433BCC_de(s32);

void func_80435844_de(s32 index) {
    if (D_800E54A4->slots[index].z == 1) {
        func_8022EF30_de(&D_80102B00[index]);
        D_800E54A4->slots[index].z = 2;
        func_80433BCC_de(-1);
    }
}
