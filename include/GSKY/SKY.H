#ifndef GSKY_SKY_H
#define GSKY_SKY_H
#include "COMMON/DESCRIPTORRECAT29.H"
#include "SCHED/SKY_POSTSCREENMESSAGE.H"
extern void func_8023A4E0_de(ObjectRecAt220 *object, ClipView *view);
extern void func_8023B694_de(Effect *effect, s16 *definition, s16 mask, f32 scale, f32 offset0, f32 offset1, f32 offset2);
extern s32 func_8023B718_de(Rotor *rotor, s32 mask, f32 fallback, s32 boosting, f32 boost, Host *host);
extern void *func_8023B8AC_de(struct IntegerState8A4 *sceneOwner);
extern void func_8023B8F8_de(s32 sceneAddress, s32 effectNode);
extern void Sky_SwapEntries(int *leftEntry, int *rightEntry);
extern s32 func_8023B94C_de(void * *, void * *);
extern int Sky_CompareRotorSpeeds(void *first, void *second);
#endif
