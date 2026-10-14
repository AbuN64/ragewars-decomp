#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Resets a 0x1208-byte actor: clears it through func_802A001C_de, initialises its three lists at 0xC,
   0x20 and 0xF24 through func_80255CA0_de, sets its words at 0x1200 and 0x38 to 1 and 2, clears those at
   0 to 8 and 0xF18 to 0xF20, and resets the parts at offset 0x40 through func_8044A170_de and
   func_80234FEC_de. */
extern void func_802A001C_de(void *, s32, s32);
extern void func_8044A170_de(void *);
extern void func_80234FEC_de(void *);




void func_8044A62C_de(func_8044B27C_S1 *actor) {
    char *parts;

    func_802A001C_de(actor, 0, 0x1208);
    func_80255CA0_de(&actor->unkC, 0, 4);
    func_80255CA0_de(&actor->unk20, 0, 4);
    func_80255CA0_de(&actor->unkF24, 0, 4);
    parts = &actor->unk40;
    actor->unk1200 = 1;
    actor->unk0 = 0;
    actor->unk4 = 0;
    actor->unk8 = 0;
    actor->unkF18 = 0;
    actor->unkF1C = 0;
    actor->unkF20 = 0;
    actor->unk38 = 2;
    func_8044A170_de(parts);
    func_80234FEC_de(parts);
}
