#include "types.h"

typedef struct MemoryBoundaryInit {
    u32 last;
    u32 flags;
} MemoryBoundaryInit;
extern MemoryBoundaryInit D_800CB3A0[];
extern u32 D_80000318;
extern s8 D_800F3450;
extern u8 D_800F3452;
extern s32 func_80200500_de(void);
extern void func_802022E0_de(void);
extern void func_80200568_de(s32, s32);
extern void func_80200538_de(s32);

void func_802013D8_de(void) {
    s32 saved;
    u32 size;
    saved = func_80200500_de();
    func_802022E0_de();
    func_80200568_de(0xB1FFFFF0, 0);
    func_80200568_de(0xB1FFFFFC, 0);
    size = D_80000318;
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
