#include "COMMON/S1_6.H"
#include "COMMON/GAME_SESSION.H"
#include "TYPES.H"

/* On event 3 with value 0xD, clears D_80146894 and calls Tsmos_RequestFrontendShutdown and func_8025E384_de. Returns
   zero. */
extern void Tsmos_RequestFrontendShutdown();
extern void func_8025E384_de();

s32 func_80435C70_de(void *first, void *second, u32 event, s32 value) {
    if ((event >> 16) == 3) {
        if (value != 0xD) {
            return 0;
        }
        D_8011FAC0.clockPaused = 0;
        Tsmos_RequestFrontendShutdown();
        func_8025E384_de();
    }
    return 0;
}
