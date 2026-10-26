#include "IO/80200568.H"
#include "include_asm.h"

#include "TYPES.H"

#include "IO/DEBUG_MEMORY.H"
extern u8 D_800F3452;
extern s32 Libsn_DisableInterrupts(void);
extern void func_802022E0_de(void);

void Libsn_InitializeHostMemoryAccess(void) {
    s32 saved;
    u32 size;
    saved = Libsn_DisableInterrupts();
    func_802022E0_de();
    Libsn_WritePortWord(0xB1FFFFF0, 0);
    Libsn_WritePortWord(0xB1FFFFFC, 0);
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
    Libsn_RestoreInterruptEnable(saved);
}

extern int Libgultra_TrwGetSr(void);
extern void Libgultra_TrwSetSr(int);
extern void Libsn_SpinDelay(s32);
extern void Libsn_TransferHostMemoryRanges(u32);
extern void Libsn_CopyHostBlockToCart(void);
extern u32 D_800F32A8;

/* Host-command service loop: poll the command word at 0xB1FFFFF0, acknowledge it and run it. */
void Libsn_ServiceHostCommands(void) {
    s32 keepRunning;
    s32 command;
    do {
        keepRunning = 1;
        while ((command = Libsn_ReadPortWord(0xB1FFFFF0)) == 0) {
            Libsn_SpinDelay(1000);
        }
        if (command == 2) {
            Libsn_WritePortWord(0xB1FFFFFC, 0);
            Libsn_SpinDelay(1000);
            continue;
        }
        Libsn_WritePortWord(0xB1FFFFFC, 0x101);
        while (Libsn_ReadPortWord(0xB1FFFFF0) == command) {
            Libsn_SpinDelay(500);
        }
        if (Libsn_ReadPortWord(0xB1FFFFF0) == 2) {
            Libsn_WritePortWord(0xB1FFFFFC, 0);
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
            Libsn_WritePortWord(0xB1FE0000, (D_800F3452 << 24) | ((u8)D_800F3450 << 16));
            break;
        case 0x17:
            Libsn_TransferHostMemoryRanges(2);
            break;
        case 0x18:
            Libsn_TransferHostMemoryRanges(1);
            break;
        case 0x19:
            Libsn_CopyHostBlockToCart();
            break;
        }
        Libsn_WritePortWord(0xB1FFFFFC, 0);
        while (Libsn_ReadPortWord(0xB1FFFFF0) == 1) {
            Libsn_SpinDelay(500);
        }
    } while (keepRunning != 0 || D_800F3452 == 0);
    Libsn_WritePortWord(0xB1FFFFF0, 0);
}
