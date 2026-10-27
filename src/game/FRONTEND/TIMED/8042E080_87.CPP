#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LONE/D_800E5558.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Builds screen state D_800E5558: allocates its 0x1C bytes, resets through Tsmos_ActivateControllerState and opens
   it as page 0x67 through Frontend_InitMenuImage; then places the given window at 0x62, 0x45 in mode 1 of
   func_8040C474_de, or at x 0x69 in mode 2. Returns zero. */


extern void *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void Frontend_InitMenuImage(void *, s32, s32, s32, s32);
extern s32 Frontend_GetScreenMode(void);

s32 Frontend_CreateTimedMenu(struct Pair14 *window) {
    D_800E5558 = Cache_AllocateMemory(0x1C);
    Tsmos_ActivateControllerState();
    Frontend_InitMenuImage(D_800E5558, 0x67, 0, 0, 0);
    if (Frontend_GetScreenMode() == 1) {
        window->first = 0x62;
        window->second = 0x45;
    } else if (Frontend_GetScreenMode() == 2) {
        window->first = 0x69;
    }
    return 0;
}
