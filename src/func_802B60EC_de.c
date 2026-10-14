#include "span_1000/code_802B53FC.h"
#include "acmd.h"
#include "types.h"
#include "abi.h"




















/* _loadBuffer, drafted from ultralib src/audio/reverb.c: load count samples of the delay line at
   curr_ptr into the DMEM buffer buff, wrapping the read back to r->base when it would run past
   the end of the line. The wrapped arm emits its two loads as a pair of set-buffer and load-buffer
   commands against this function's own cartridge command words. */











extern u32 func_802BBBC0_de(void *); /* osVirtualToPhysical */







Acmd *func_802B60EC_de(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd *ptr = p;
    s32 after_end, before_end;
    s16 *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];

    if (curr_ptr < r->base)
        curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, buff, 0, before_end << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(curr_ptr));
        aSetBuffer(ptr++, 0, buff + (before_end << 1), 0, after_end << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(r->base));
    } else {
        aSetBuffer(ptr++, 0, buff, 0, count << 1);
        aLoadBuffer(ptr++, func_802BBBC0_de(curr_ptr));
    }

    aSetBuffer(ptr++, 0, 0, 0, count << 1);

    return ptr;
}
