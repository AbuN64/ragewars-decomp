#include "shared/gameplay_sound_table.h"
#include "types.h"
typedef struct SoundDescriptor { char pad0[0x2A]; s16 enabled, index; } SoundDescriptor;
typedef struct SoundObject { char pad0[0x18]; SoundDescriptor *descriptor; } SoundObject;
typedef struct SoundGuard { char pad0[0x34]; s8 disabled; } SoundGuard;
typedef struct SoundParent { char pad0[0x5DC]; void *emitter; } SoundParent;
typedef struct SoundActor {
    u8 kind; char pad1[0xFF]; s32 flags;
    char pad104[0x1D8 - 0x104]; SoundParent *parent;
} SoundActor;


#include "shared/menu_match_globals.h"
extern char D_80141008;

extern void func_80239908_de(void *, void *, s32, void *, f32);
s32 func_80204308_de(SoundObject *object, SoundGuard *guard, SoundActor *actor) {
    SoundDescriptor *record;
    SoundParent *parent;
    void *emitter, *fallback;
    s16 index;
    s32 callback;
    record = object->descriptor;
    if (record->enabled == 0) return 1;
    if (guard->disabled != 0) return 1;
    if (actor->kind != 1) return 1;
    if ((actor->flags & 0x300000) == 0) return 1;
    index = record->index;
    parent = actor->parent;
    if (index == 0) return 0;
    emitter = parent->emitter;
    fallback = &D_80141008;
    if (emitter != 0) fallback = emitter;
    func_80239908_de(&D_80145088, fallback, gameplaySoundValue(index), object, gameplaySoundWeight());
    index = record->index;
    callback = gameplaySoundHook(index);
    if (callback != 0) func_8025E11C_de(callback);
    return 0;
}
