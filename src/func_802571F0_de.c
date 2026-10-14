#include "span_1000/code_80256220.h"
#include "types.h"
/* Returns the physical address of a ROM offset through the 0x300-byte ROM window cache: a cached window
 * covering the offset and length is stamped with the current frame; otherwise a free window node is
 * linked in address order (or at the head), aligned to an even start, stamped, counted, filled from ROM
 * through func_80256454_de and its buffer address returned with the odd byte added back. */




extern Window *D_80107DF4;
extern Window *D_80107DF8;
extern s32 D_800CB700_de;
extern s32 D_800CB704_de;
extern char D_801011B8;
extern char D_80107DD8;
extern void func_802B2450_de(Window *);
extern void func_802B2480_de(Window *, Window *);
extern void func_80256454_de(void *, u32, s32, s32, void *, s32, s32);
extern u32 func_802BBBC0_de(s32);

u32 func_802571F0_de(s32 offset, s32 length) {
    Window *window;
    Window *after;
    Window **pool;
    u32 address;
    s32 end;
    s32 top;
    s32 odd;
    s32 word;

    after = 0;
    address = offset + D_801076A0;
    end = address + length;
    for (window = D_80107DF4; window != 0; window = window->next) {
        top = window->base + 0x300;
        word = window->base;
        if (address < word) {
            break;
        }
        after = window;
        if (top >= end) {
            window->frame = D_800CB700_de;
            return func_802BBBC0_de(window->buffer + address - window->base);
        }
    }
    pool = &D_80107DF8;
    window = *pool;
    *pool = window->next;
    func_802B2450_de(window);
    if (after != 0) {
        func_802B2480_de(window, after);
    } else if (pool[-1] != 0) {
        after = pool[-1];
        pool[-1] = window;
        window->next = after;
        window->prev = 0;
        after->prev = window;
    } else {
        pool[-1] = window;
        window->next = 0;
        window->prev = 0;
    }
    odd = address & 1;
    address -= odd;
    window->base = address;
    window->frame = D_800CB700_de;
    word = window->buffer;
    D_800CB704_de++;
    func_80256454_de(&D_801011B8, address, 0x300, word, &D_80107DD8, 0, 1);
    return func_802BBBC0_de(word) + odd;
}
