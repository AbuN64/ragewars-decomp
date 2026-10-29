#ifndef RENDER_SETN64_STARTROUND_H
#define RENDER_SETN64_STARTROUND_H
#include "COMMON/OBJRECAT26DD8.H"
struct RoundSessionItemStateView {
    char pad0[0x26DB8];
    s32 reservedWord;
    char pad26DB8[0x1C];
    s32 unk26DD8;
};
extern void SetN64_ResetMode10Items(s32 worldAddress);
extern void SetN64_DrawMode11Session(void *session);
extern void SetN64_DrawMode10Session(void *session);
extern void SetN64_DrawMode12Session(void *session);
extern void SetN64_ResetMode12Items(int sessionAddress);
#endif
