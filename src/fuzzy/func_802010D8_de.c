#include "shared/debug_memory.h"
extern void func_80200610_de(void);
extern u8 D_8F0F3130[];
extern void func_80200F98_de(u32, s32, u32);
extern void func_80201064_de(u32, u32, u32);
extern void func_80200D18_de(u32, u32, u32);
extern void func_80200880_de(u32, u32, u32);
extern void func_80200B14_de(u32, u32, u32);

/* Split the debugger's memory transfer at permission boundaries. */
void func_802010D8_de(u32 mode) {
    u32 address, remaining, chunk, flags, port = 0xB1FE0000;
    s32 i;
    func_80200610_de();
    address = func_802005A0_de(0xB1FFFFF4);
    remaining = func_802005A0_de(0xB1FFFFF8);
    if (address > 0xEFFFFFFF) address += (u32)D_8F0F3130;
    while (remaining != 0) {
        for (i = 0; i < 48; i++) {
            if (address >= D_800F2D00[i].first && address <= D_800F2D00[i].last) break;
        }
        if (i < 48) {
            flags = D_800F2D00[i].flags;
            chunk = D_800F2D00[i].last - address + 1;
        } else {
            flags = 0;
            chunk = 0x1000 - (address & 0xFFF);
        }
        if (remaining < chunk) chunk = remaining;
        if ((flags & mode) == 0) {
            if (mode == 1) func_80200F98_de(port, 0, chunk);
        } else if (flags & 4) {
            if (mode == 1) func_80201064_de(port, address, chunk);
            else func_80201064_de(address, port, chunk);
        } else if (mode == 1) {
            func_80200D18_de(port, address, chunk);
        } else if (flags & 8) {
            func_80200B14_de(port, address, chunk);
        } else {
            func_80200880_de(port, address, chunk);
        }
        port += chunk;
        address += chunk;
        remaining -= chunk;
    }
}
