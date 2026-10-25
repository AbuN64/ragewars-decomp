#include "IO/80200568.H"
#include "include_asm.h"

#include "TYPES.H"

#include "IO/DEBUG_MEMORY.H"
extern u8 D_800F3452;
extern s32 func_80200500_de(void);
extern void func_802022E0_de(void);
extern void func_80200568_de(s32, s32);

void func_802013E0_de(void) {
    s32 saved;
    u32 size;
    saved = func_80200500_de();
    func_802022E0_de();
    func_80200568_de(0xB1FFFFF0, 0);
    func_80200568_de(0xB1FFFFFC, 0);
    size = *(u32 *)0x80000318;
    D_800F3450 = 1;
    D_800F3452 = 0xFF;
    if (size > 0x3FFFFFU) {
        if (((size & 0x1FFFF) == 0) & (size <= 0x02000000U)) {
            size--;
            D_800CB3A0[1].last = size - 0x80000000;
            D_800CB3A0[3].last = size + 0xA0000000;
        }
    }
    func_80200538_de(saved);
}

extern int Libgultra_TrwGetSr(void);
extern void Libgultra_TrwSetSr(int);
extern s32 func_802005A0_de(s32);
extern void func_802005DC_de(s32);
extern void func_802010D8_de(u32);
extern void Io_CopyHostBlockToCart(void);
extern u32 D_800F32A8;

/* Host-command service loop: poll the command word at 0xB1FFFFF0, acknowledge it and run it. */
void Libsn_ServiceHostCommands(void) {
    s32 keepRunning;
    s32 command;
    do {
        keepRunning = 1;
        while ((command = func_802005A0_de(0xB1FFFFF0)) == 0) {
            func_802005DC_de(1000);
        }
        if (command == 2) {
            func_80200568_de(0xB1FFFFFC, 0);
            func_802005DC_de(1000);
            continue;
        }
        func_80200568_de(0xB1FFFFFC, 0x101);
        while (func_802005A0_de(0xB1FFFFF0) == command) {
            func_802005DC_de(500);
        }
        if (func_802005A0_de(0xB1FFFFF0) == 2) {
            func_80200568_de(0xB1FFFFFC, 0);
            continue;
        }
        switch (command) {
        case 0x10:
            break;
        case 0x11:
            keepRunning = 0;
            break;
        case 0x12:
            D_800F32A8 &= ~1U;
            D_800F3450 = 0;
            D_800F3452 = 0;
            Libgultra_TrwSetSr(Libgultra_TrwGetSr() & ~1);
            break;
        case 0x13:
            D_800F3452 = 0;
            D_800F3450 = 0;
            break;
        case 0x14:
            D_800F3452 = 0xFF;
            break;
        case 0x15:
            D_800F3452 = 0;
            break;
        case 0x16:
            func_80200568_de(0xB1FE0000, (D_800F3452 << 24) | ((u8)D_800F3450 << 16));
            break;
        case 0x17:
            func_802010D8_de(2);
            break;
        case 0x18:
            func_802010D8_de(1);
            break;
        case 0x19:
            Io_CopyHostBlockToCart();
            break;
        }
        func_80200568_de(0xB1FFFFFC, 0);
        while (func_802005A0_de(0xB1FFFFF0) == 1) {
            func_802005DC_de(500);
        }
    } while (keepRunning != 0 || D_800F3452 == 0);
    func_80200568_de(0xB1FFFFF0, 0);
}
