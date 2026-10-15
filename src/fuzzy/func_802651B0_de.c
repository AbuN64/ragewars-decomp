#include "types.h"
#include "common/data.h"
#include "span_1000/code_802646F4.h"

extern u32 D_8010C070;
extern u32 D_8010C07C;
extern void func_80264F60_de(s32 samples, s32 count);

/* Initializes the packed control and sample bit streams, then decodes each output channel. */
s32 func_802651B0_de(s32 destinations, void *encoded, s32 channel_count) {
    s32 *channels = (s32 *)destinations;
    u8 *packed = (u8 *)encoded;
    s32 sample_count;
    s32 control_bits;
    s32 shift;
    u8 *sample_bytes;
    s32 i;
    u32 last_byte;

    sample_count = *packed++ << 8;
    sample_count |= *packed++;
    control_bits = ((sample_count + 3) / 4) * 6;
    sample_bytes = packed + control_bits / 8;
    D_8010C07C = sample_bytes[0];
    D_8010C07C |= sample_bytes[1] << 8;
    D_8010C07C |= sample_bytes[2] << 16;
    shift = control_bits & 7;
    last_byte = sample_bytes[3];
    D_8010C080_de = 32 - shift;
    D_8010C084 = sample_bytes + 4;
    D_8010C07C = (D_8010C07C | (last_byte << 24)) >> shift;

    for (i = 0; i < channel_count; i++) {
        D_8010C070 = packed[0];
        D_8010C070 |= packed[1] << 8;
        D_8010C070 |= packed[2] << 16;
        last_byte = packed[3];
        D_8010C074 = 32;
        D_8010C078 = packed + 4;
        D_8010C070 |= last_byte << 24;
        func_80264F60_de(channels[i], sample_count);
    }
    return sample_count;
}
