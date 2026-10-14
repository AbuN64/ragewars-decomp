#include "common/types_1dc8418c21db.h"
#include "types.h"

/* Select the PFS active bank. Existing PFS consumers supply the canonical
 * queue/channel/activebank fields at offsets 4, 8 and 0x65. The cartridge
 * returns the controller write result directly (v0 survives the epilogue). */
extern u32 func_802B8880_de(void *queue, s32 channel, u16 address,
                           u8 *buffer, s32 force);

s32 func_80448CC4_de(OSPfs_func_80445F80_de *pfs)
{
    u8 name[32];
    s32 i;

    for (i = 0; i < 32; i++) {
        name[i] = pfs->activebank;
    }
    return func_802B8880_de(pfs->queue, pfs->channel, 0x400, name, 0);
}
