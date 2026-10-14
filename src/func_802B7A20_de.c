#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B7488.h"
#include "types.h"
/* Clears the controller PIF RAM block, sets its status word to execute, and packs one request-status command with the given command byte per controller followed by the end marker (libultra __osPackRequestData). Adapted from func_802B768C_de with the request format and command argument changed, the clearing loop counting up and the status word written through a local pointer to the PIF RAM block. */





extern u8 D_8014D46C;
extern OSPifRam D_8014D470;

void func_802B7A20_de(u8 cmd) {
    u8 *ptr;
    __OSContRequesFormat requestformat;
    s32 i;
    u8 *count;
    OSPifRam *pifram;

    for (i = 0; i < 15; i++) {
        ((u32 *)&D_8014D470)[i] = 0;
    }
    pifram = &D_8014D470;
    pifram->pifstatus = 1;
    ptr = (u8 *)pifram->ramarray;
    requestformat.dummy = 0xFF;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;
    requestformat.dummy1 = 0xFF;

    count = &D_8014D46C;
    for (i = 0; i < *count; i++) {
        *(__OSContRequesFormat *)ptr = requestformat;
        ptr += sizeof(requestformat);
    }
    *ptr = 0xFE;
}
