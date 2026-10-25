#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern f32 D_800E2390;
typedef struct { char pad0[0x30]; u32 flags; } Func_8043EDB0_Rec;
typedef struct { char pad0[0xC]; Func_8043EDB0_Rec *rec; } Func_8043EDB0_Obj;
/* Resets D_801468B0 to D_800E2390 and clears bit 26 of the flags in the record at 0xC of arg0. */
void func_8043EDB0_de(Func_8043EDB0_Obj *arg0) {
    D_801462C8.counters.m_GameOverTimer = D_800E2390;
    arg0->rec->flags &= 0xFBFFFFFF;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043EDB0_de);
#endif
#endif
