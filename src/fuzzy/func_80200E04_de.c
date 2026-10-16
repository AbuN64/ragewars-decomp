#include "span_1000/code_80200400.h"
#include "span_1000/code_802B8CCC.h"
#include "span_1000/code_802BB15C.h"
extern s32 D_800C8140_de;
extern func_802BDDC0_S1 D_800F2CE0;
extern OSMesgQueue D_800F2CC0;
extern void func_80200CA0_de(u32, u8);
struct OSIoMesg;
struct Opaque_OSMesgQueue;
extern s32 func_802B8CF0_de(struct OSIoMesg *, s32, s32, s32, s32, s32, struct Opaque_OSMesgQueue *);
extern s32 func_802BB2A0_de(OSMesgQueue *, void **, s32);

/* Write an arbitrary byte stream to the device, using DMA when aligned
 * and falling back to byte/word writes if the DMA request is unavailable. */
void func_80200E04_de(u32 address, u8 *source, u32 remaining) {
    s32 dmaResult = -(D_800C8140_de == 0);
    while (remaining != 0 && (address & 3) != 0) {
        func_80200CA0_de(address++, *source++);
        remaining--;
    }
    while (remaining >= 4) {
        if (remaining < 16 || ((u32)source & 15) != 0 || dmaResult == -1) {
            func_80200568_de(address, ((u32)source[0] << 24) |
                ((u32)source[1] << 16) | ((u32)source[2] << 8) | source[3]);
            address += 4;
            source += 4;
            remaining -= 4;
        } else {
            dmaResult = func_802B8CF0_de(&D_800F2CE0, 1, 1, address,
                (s32)source, remaining, &D_800F2CC0);
            if (dmaResult != -1) {
                func_802BB2A0_de(&D_800F2CC0, 0, 1);
                remaining = 0;
            }
        }
    }
    while (remaining != 0) {
        func_80200CA0_de(address++, *source++);
        remaining--;
    }
}
