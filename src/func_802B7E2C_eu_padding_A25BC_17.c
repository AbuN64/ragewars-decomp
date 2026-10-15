#include "span_1000/code_802B7488.h"
/* Points the RDP command DMA at a new display-list buffer, returning -1 if the RDP is busy, otherwise clearing the XBUS flag, waiting for it to drop and writing the physical start and end addresses (libultra osDpSetNextBuffer). */
#include "shared/rdp_dma_io.h"


extern u32 func_802BBBC0_de(void *arg0);

s32 func_802B7B90_de(void *bufPtr, u64 size) {
    if (func_802B7C30_de()) {
        return -1;
    }
    IO_WRITE_WORD(RDP_DMA_STATUS_REG, 1);
    do {
    } while (IO_READ_WORD(RDP_DMA_STATUS_REG) & 1);
    IO_WRITE_WORD(RDP_DMA_START_REG, func_802BBBC0_de(bufPtr));
    IO_WRITE_WORD(RDP_DMA_END_REG, func_802BBBC0_de(bufPtr) + size);
    return 0;
}
