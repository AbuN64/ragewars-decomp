#ifndef SYSTEM_EVENT_DAMAGE_AND_IMPACT_VIEWS_H
#define SYSTEM_EVENT_DAMAGE_AND_IMPACT_VIEWS_H
#include "TYPES.H"
#include "COMMON/TARGET.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ActorEventsSpawnRiderImpactEffect {
    char pad0[0x1D8];
    SharedPlayer *player;
};
struct Carrier {
    struct ActorEventsComputeDamageScale *owner;
    char pad4[0x10];
    s32 slot;
    Shield shield;
};
struct Vec4s {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
};
struct s_CEventValueFormat7a {
    u8 a;
    u8 b;
    u8 c;
    u8 m_u8_Value4;
    u8 m_u8_Value5;
    u8 f;
    u8 m_u8_Value7;
};
#endif
