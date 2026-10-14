#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024D018.h"
#include "types.h"
/* Plays a sound effect for an actor at a position: snaps the position to the nearest registered emitter
 * in D_8013B364 when there is one, draws a random direction and (except for sound 0xBD7) scales it to a
 * velocity of 409.6, then starts the sound through func_8028FFD0_de on D_80131600 with the actor's id and
 * the given volume. */







extern char D_80131600;
extern char D_8013B364;
extern f32 D_800C3CD0_de[];
extern s32 func_8020CB3C_de(void *, void *);
extern Vec3 *func_8020C994_de(void *, s32);
extern void func_8027207C_de(Vec3 *);
extern void func_80271F9C_de(void *, void *, f32);
extern s32 func_8028FFD0_de(s32, s32, s32, Vec3, Vec3, s32, f32);




void func_8024DBC0_de(void *actor, Vec3 pos, s32 sound, f32 volume) {
    Vec3 up;
    Vec3 dir;
    Vec3 velocity;
    Vec3 at;
    SoundRequest request;
    Vec3 *emitter;

    emitter = func_8020C994_de(&D_8013B364, func_8020CB3C_de(&D_8013B364, &pos));
    request.position = pos;
    at = request.position;
    request.owner = ((struct Actor_func_80214DD4_de *)actor)->room;
    if (emitter != 0) {
        at = *emitter;
    }
    up.x = 0.0f;
    up.y = D_800C3CD0_de[1];
    up.z = 0.0f;
    dir.x = dir.y = dir.z = up.x;
    func_8027207C_de(&dir);
    if (sound != 0xBD7) {
        func_80271F9C_de(&velocity, &dir, 409.59998f);
    }
    func_8028FFD0_de((s32)&D_80131600, 0, sound, velocity, at, request.owner, volume);
}
