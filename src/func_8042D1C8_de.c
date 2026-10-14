#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Refreshes each of 8 configured participants: for each slot, reads the participant id at offset
   0xF0 + slot*4 of D_800E53C0; when it is not -1 and the id's 150-byte record in D_80146398 has
   its byte at 0x91 clear, stores func_80425DFC_de(id) at offset 0x32C of D_800E53C0, calls
   func_80425EE4_de(id, &D_800E53C0[0x110 + id*8]), and calls func_804259E0_de(id). */
extern u8 *D_800E53C0;
extern u8 D_80146398[];

extern s32 func_80425DFC_de(s32);
extern void func_80425EE4_de(s32, s32 *);
extern void func_804259E0_de(s32);




void func_8042D1C8_de(void) {
    s32 id;
    s32 i;
    s32 idx;
    u8 *record;

    for (i = 0; i < 8; i += 1) {
        idx = i * 4;
        id = ((struct IntegerStateF4 *) (D_800E53C0 + idx))->unk_F0;
        if (id == -1) {
            continue;
        }
        record = &D_80146398[id * 0x96];
        if (record[0x91] != 0) {
            continue;
        }
        ((IntegerState330 *)(D_800E53C0))->unk_32C = func_80425DFC_de(id);
        func_80425EE4_de(id, (s32 *)((id * 8 + 0x110) + D_800E53C0));
        func_804259E0_de(id);
    }
}
