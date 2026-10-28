#ifndef RENDER_802944E8_H
#define RENDER_802944E8_H
#include "COMMON/OBJRECAT26DD8.H"
struct ObjRecAt26DD8 {
    char pad0[0x26DB8];
    s32 unk26DB8;
    char pad26DB8[0x1C];
    s32 unk26DD8;
};
extern void SetN64_ResetMode10Items(s32 arg0);
extern void SetN64_DrawMode11Session(void *session);
extern void SetN64_DrawMode10Session(void *session);
extern void SetN64_DrawMode12Session(void *session);
extern void SetN64_ResetMode12Items(int sessionAddress);
#endif
