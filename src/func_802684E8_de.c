#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80268160.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_802624A0.h"
#include "resident_event_handler.h"




void func_802684E8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 temp = *(u8 *)arg0;
    if (temp == 1) {
        s32 *p = &arg3;
        ((Field_s32_2E0 *)(arg0))->value = ((Field_s32_2E0 *)(arg0))->value & ~(temp << p[3]);
    }
}

/* Spawns an effect of the given kind for an object through func_802627A0_de at the object's position with its velocity (none when the object is inactive) and a uniform scale; kind 0x40C instead starts at the camera with no velocity and, once spawned, follows the camera's target through func_802833D0_de, and kinds 0x474 to 0x477 attach to the host's partner effect for active flagged hosts, otherwise the effect is started through func_80262C88_de. */

extern Camera_func_8026851C_de *D_80103FCC;
extern s32 func_802833D0_de(void *host);
extern s32 func_80262C88_de(void *effect);

void func_8026851C_de(Source_func_8026851C_de *source, Host_func_8026851C_de *host, s32 unused, Spawn spawn) {
    Vec3f scale;
    Vec3f velocity;
    Effect_func_8026851C_de *effect;
    void *storage;
    Effect_func_8026851C_de *partner;

    if (source->active == 0) {
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
    } else {
        velocity = source->velocity;
    }
    spawn.position = source->position;
    scale.x = spawn.size;
    scale.y = spawn.size;
    scale.z = spawn.size;
    if (spawn.kind == 0x40C) {
        spawn.position = D_80103FCC->position;
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
    }
    storage = func_802627A0_de(&D_80131150, spawn.kind, source->id, spawn.position, 0.0f, velocity, scale, 0);
    effect = storage;
    if (effect == 0) {
        return;
    }
    if (spawn.kind == 0x40C) {
        effect->target = func_802833D0_de(host);
        effect->offset.x = D_80103FCC->offset.x;
        effect->offset.y = D_80103FCC->offset.y;
        effect->offset.z = D_80103FCC->offset.z;
    } else if ((unsigned)(spawn.kind - 0x474) < 4) {
        if (host->type == 1 && (host->flags & 0x300000)) {
            partner = host->partner;
            if (partner != 0) {
                partner->child = effect;
                effect->scale = partner->scale;
            }
        } else {
            func_80262C88_de(effect);
        }
    }
}
