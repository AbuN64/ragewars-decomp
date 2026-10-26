#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TARGET.H"
#include "TYPES.H"

extern void Events_ApplyDamageEvent(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void Events_ApplyFlag100RadialDamage(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    Events_ApplyDamageEvent(source, target, kind, position, arg6, 1, 0, 0x100);
}

extern void Events_ApplyDamageEvent(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void Events_ApplyFlag100RadialKnockback(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    Events_ApplyDamageEvent(source, target, kind, position, arg6, 1, 1, 0x100);
}

extern void Events_ApplyDamageEvent(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void Events_ApplyFlag200RadialDamage(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    Events_ApplyDamageEvent(source, target, kind, position, arg6, 1, 0, 0x200);
}

extern void Events_ApplyDamageEvent(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void Events_ApplyFlag200RadialKnockback(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    Events_ApplyDamageEvent(source, target, kind, position, arg6, 1, 1, 0x200);
}

extern void Events_ApplyDamageEvent(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void Events_ApplyFlag400RadialDamage(s32 source, s32 target, s32 kind, Triple position, struct IntPair arg6) {
    Events_ApplyDamageEvent(source, target, kind, position, arg6, 1, 0, 0x400);
}
