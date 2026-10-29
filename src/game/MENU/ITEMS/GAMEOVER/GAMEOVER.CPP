#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
typedef struct { char pad0[0x30]; u32 flags; } GameOverMenuFlagsView;
typedef struct { char pad0[0xC]; GameOverMenuFlagsView *rec; } GameOverMenuContext;
/* Resets the game-over timer to 120.0f and clears bit 26 of the flags in the record at 0xC of arg0. */
void Items_ResetGameOverTimer(GameOverMenuContext *menuContext) {
    g_gameSettings.counters.m_GameOverTimer = 120.0f;
    menuContext->rec->flags &= 0xFBFFFFFF;
}
#else
INCLUDE_ASM("ovl_80400000", Items_ResetGameOverTimer);
#endif
#endif
