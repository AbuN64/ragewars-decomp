#ifndef SYSTEM_EVENTS_APPLYDAMAGEEVENT_H
#define SYSTEM_EVENTS_APPLYDAMAGEEVENT_H
#include "COMMON/TARGET.H"
/* Damage packet passed by value to the area-hit callbacks. */
typedef struct Shared_DamageParameters {
    u16 radius;
    u16 damage;
    union {
        s32 control;
        struct { s8 impulse; u8 reserved[3]; };
    };
} Shared_DamageParameters;
struct EventCallbackEntry {
    EventsDispatchCallbackCallback callback;
    s32 unused;
};
struct ClipEventTargetView {
    u8 type;
    u8 pad1[0x17];
    s32 *kind;
    u8 pad1C[0xB4];
    s32 value;
};
extern void Events_DispatchCallback(void *actor, void *source, s32 event, CVector3 position, struct ResourceManagerState state);
extern void Events_ForwardCallback(void *sourceActor, void *targetActor, s32 eventKind, CVector3 eventPosition, ResourceManagerState eventParams);
#endif
