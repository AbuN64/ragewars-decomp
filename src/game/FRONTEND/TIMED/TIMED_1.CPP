#include "SYSTEM/8025E280.H"
#include "COMMON/S1_6.H"
#include "COMMON/GAME_SESSION.H"
#include "TYPES.H"

/* 8042E080_76.CPP */
/* On event 3 with value 0xD, clears D_80146894 and calls Tsmos_RequestFrontendShutdown and func_8025E384_de. Returns
   zero. */
extern void Tsmos_RequestFrontendShutdown();

s32 Frontend_ResumeMatchOnInput(void *first, void *second, u32 event, s32 value) {
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

/* 8042E080_77.CPP */
/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 Frontend_ConsumePauseMenuEvent(void) {
    MarkMenuEventHandled();
    return 0;
}
