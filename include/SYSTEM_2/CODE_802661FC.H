#ifndef SYSTEM_2_802661FC_H
#define SYSTEM_2_802661FC_H
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
struct CallbackEntryRecAt4V1 {
    func_80267198_de_Callback callback;
    s32 unused;
};
struct ObjectRecAtD0 {
    u8 type;
    u8 pad1[0x17];
    s32 *kind;
    u8 pad1C[0xB4];
    s32 value;
};
extern void func_80267198_de(void *actor, void *source, s32 event, CVector3 position, struct ResourceManagerState state);
extern void func_802671FC_de(void *arg0, void *arg1, s32 arg2, CVector3 arg3, ResourceManagerState arg6);
#endif
