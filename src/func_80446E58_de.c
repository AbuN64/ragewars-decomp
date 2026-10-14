#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041C67C.h"
#include "types.h"
/* __osPfsRequestOneChannel, drafted from the ultralib io pfsgetstatus source (2.0I branch): fill the pak
   PIF RAM block with one skip byte per preceding channel, a status request for the given channel and
   the end marker. */





extern u8 D_8014D4B0;
extern OSPifRam D_80154110;

void func_80446E58_de(int channel)
{
    u8 *base;
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    int i;

    D_8014D4B0 = 0;
    base = (u8 *)&D_80154110;
    D_80154110.pifstatus = 1;
    ptr = base;

    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = 0;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;

    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }

    *(__OSContRequesFormatShort *)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormatShort);
    *ptr = 0xFE;
}
