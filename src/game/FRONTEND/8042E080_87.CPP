#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LONE/D_800E5558.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Builds screen state D_800E5558: allocates its 0x1C bytes, resets through func_802A2360_de and opens
   it as page 0x67 through func_8043C210_de; then places the given window at 0x62, 0x45 in mode 1 of
   func_8040C474_de, or at x 0x69 in mode 2. Returns zero. */


extern void *Scene_AllocateMemory(s32);
extern void func_802A2360_de(void);
extern void func_8043C210_de(void *, s32, s32, s32, s32);
extern s32 func_8040C474_de(void);

s32 func_804361BC_de(struct Pair14 *window) {
    D_800E5558 = Scene_AllocateMemory(0x1C);
    func_802A2360_de();
    func_8043C210_de(D_800E5558, 0x67, 0, 0, 0);
    if (func_8040C474_de() == 1) {
        window->first = 0x62;
        window->second = 0x45;
    } else if (func_8040C474_de() == 2) {
        window->first = 0x69;
    }
    return 0;
}
