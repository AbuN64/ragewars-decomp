#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef void (*Shared_ContextCallback)(void *);
typedef void (*Shared_MenuVoidCallback)(void);
struct SharedTrackObject;
typedef struct Shared_MenuContext Shared_MenuContext;
struct Shared_MenuContext {
    void *owner;
    s32 resource;
    u32 unknown08;
    Shared_MenuVoidCallback onClose;
    Shared_MenuVoidCallback callback10;
    u32 unknown14;
    struct SharedTrackObject *target;
    f32 time;
    u32 unknown20[4];
    f32 start;
    f32 end;
    s32 active;
    s32 state3C;
    u32 unknown40;
    s32 initialized44;
    s32 closed;
    u32 unknown4C[5];
    u32 unknown60;
    u32 unknown64[4];
    u32 flags;
    u32 unknown78[26];
    s32 requestE0;
    Shared_ContextCallback callbackE4;
    Shared_MenuVoidCallback callbackE8;
    u32 unknownEC;
    Vec3 position;
    f32 yaw;
    u32 unknown100[6];
    char messages[5][0x28];
    s32 messageCount;
};


/* The copied prefix is exactly 0x50 bytes. */
typedef struct SharedTrackObjectPrefix {
    u32 unknown0[2];
    Vec3 position;
    u8 unknown14[0x3C];
} SharedTrackObjectPrefix;

typedef struct SharedTrackObject {
    SharedTrackObjectPrefix prefix;
    u8 unknown50[0x1C];
    f32 yaw;
} SharedTrackObject;

typedef struct SharedTrackCamera {
    u8 unknown0[0x28];
    f32 distance;
    f32 pitch;
    u8 unknown30[8];
    Vec3 position;
} SharedTrackCamera;

/* The two adjacent track constants are consumed at base and base+4. */
struct SharedTrackConstants { f32 amplitude; f32 unit; };
union SharedVectorBits { Triple words; Vec3 vector; };

#include "common/unused.h"
#include "span_16E000/code_80400000.h"

extern Shared_MenuContext *D_800E2830;
extern f32 D_800E2848;
extern struct SharedTrackConstants D_800DCB28;

extern s32 *func_8028FDB4_de(s32 resource, s32 index);

f32 func_8040170C_de(f32 t) {
    s32 *track;
    KeyRecAt10 *key;
    s32 count;
    f32 u;
    f32 v;

    track = func_8028FDB4_de(D_800E2830->resource, 1);
    count = track[1];
    key = (KeyRecAt10 *)(track + 2);
    if (count == 0) {
        v = 0.0f;
    } else if (t <= key[0].time) {
        v = key[0].value;
    } else if (key[count - 1].time <= t) {
        v = key[count - 1].value;
    } else {
        while (key->time < t) {
            key++;
        }
        u = (t - key[-1].time) / (key->time - key[-1].time);
        v = key[-1].value * (D_800DCB28.unit - u) + key->value * u;
    }
    v *= 2.0f * D_800E2848 + D_800E0B60[0];
    v -= D_800E2848;
    if (D_800E0B60[0] < v) {
        v = D_800E0B60[0];
    }
    if (v < 0.0f) {
        v = 0.0f;
    }
    return v;
}
