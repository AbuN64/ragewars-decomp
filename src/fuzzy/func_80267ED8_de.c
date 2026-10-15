#include "shared/gameplay_sound_table.h"
#include "types.h"

/* Effect callback that plays a sound and runs its hook: the sound of entry arg6.value in D_800D3F58 is started through func_80237E80_de on the emitter of a mirrored player's parent (skipped when it has none) or on the default emitter at D_80145088 + 0x40, and the entry's hook is then run through func_8025E11C_de when present. */

typedef struct Triple {
    s32 x;
    s32 y;
    s32 z;
} Triple;

typedef struct Params {
    s32 value;
    s16 angle;
    u8 scale;
    u8 pad;
} Params;

typedef struct Inner {
    char pad[0x5DC];
    char *parent;
} Inner;

typedef struct Context {
    u8 type;
    char pad1[0xFF];
    s32 flags;
    char pad104[0x1D8 - 0x104];
    Inner *inner;
} Context;




#include "shared/menu_match_globals.h"
extern void func_80237E80_de(char *system, char *emitter, s32 sound);

void func_80267ED8_de(s32 arg0, Context *arg1, s32 arg2, Triple arg3, Params arg6)
{
    if (arg1->type == 1 && (arg1->flags & 0x300000)) {
        char *parent = arg1->inner->parent;

        if (parent != 0) {
            func_80237E80_de(&D_80145088, parent, gameplaySoundValue(arg6.value));
        }
    } else {
        func_80237E80_de(&D_80145088, &D_80145088.fallbackCamera, gameplaySoundValue(arg6.value));
    }
    if (gameplaySoundHook(arg6.value) != 0) {
        func_8025E11C_de(gameplaySoundHook(arg6.value));
    }
}

