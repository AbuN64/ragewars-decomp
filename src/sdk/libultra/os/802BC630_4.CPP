#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"

/* Clears the controller PIF RAM block, sets its status word to execute, and packs one request-status command with the given command byte per controller followed by the end marker (libultra __osPackRequestData). Adapted from func_802B768C_de with the request format and command argument changed, the clearing loop counting up and the status word written through a local pointer to the PIF RAM block. */







void func_802B7A20_de(u8 cmd) {
    extern OSPifRam D_8014D470;
    extern u8 D_8014D46C;
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

void func_802B7AD8_de(u8 *valid, EntryRecAt3 *data) {
    extern char D_8014D470;
    extern u8 D_8014D46C[];
    u8 *ptr;
    __OSContRequesFormat readformat;
    s32 i;
    u8 mask = 0;

    ptr = (u8 *)&D_8014D470;
    for (i = 0; i < D_8014D46C[0]; i++, ptr += sizeof(readformat), data++) {
        readformat = *(__OSContRequesFormat *)ptr;
        data->slot = (readformat.rxsize & 0xC0) >> 4;
        if (data->slot != 0) {
            continue;
        }
        data->id = (readformat.typel << 8) | readformat.typeh;
        data->team = readformat.status;
        mask |= 1 << i;
    }
    *valid = mask;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_802B7AD8_de_padding_B86BC);
#endif
