#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Builds screen state D_800E5554 as func_804361BC_de builds D_800E5558: allocates its 0x20 bytes,
   resets through Tsmos_ActivateControllerState, sets its selection at 0x1C to -1 and opens it as page 0x67 through
   func_8043C210_de; then places the given window at 0x62, 0x45 in mode 1 of func_8040C474_de, or at x
   0x69 in mode 2. Returns zero. */




extern struct MenuRules *D_800E5554;
extern struct MenuRules *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void func_8043C210_de(struct MenuRules *, s32, s32, s32, s32);
extern s32 Frontend_GetScreenMode(void);

s32 func_80435E20_de(struct Pair14 *window) {
    D_800E5554 = Cache_AllocateMemory(0x20);
    Tsmos_ActivateControllerState();
    D_800E5554->locked = -1;
    func_8043C210_de(D_800E5554, 0x67, 0, 0, 0);
    if (Frontend_GetScreenMode() == 1) {
        window->first = 0x62;
        window->second = 0x45;
    } else if (Frontend_GetScreenMode() == 2) {
        window->first = 0x69;
    }
    return 0;
}
