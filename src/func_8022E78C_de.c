#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
/* Places a marker in front of an actor: takes the node in *slot or allocates one from pool
   D_8013B1A8, turns the offset (0, 0, distance) into world space by the actor's facing through
   func_8024BC94_de, adds the actor's position and stores it as short coordinates, the height raised by
   the actor's size scaled by D_800C7F08[1], with scale D_800C7F10 and the node marked active. */





extern char D_8013B1A8;
extern f32 D_800C7F08[];

extern Marker *func_80268C1C_de(char *, s32);
extern void func_8024BC94_de(Vec3 *, void *, Vec3);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_8024D284_de(void *);




void func_8022E78C_de(void *actor, Marker **slot, s32 kind, f32 distance) {
    Marker *marker;
    Vec3 offset;
    Vec3 pos;

    marker = *slot;
    if (marker == 0) {
        marker = func_80268C1C_de(&D_8013B1A8, kind);
        if (marker == 0) {
            return;
        }
    }
    *slot = marker;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = distance;
    func_8024BC94_de(&pos, actor, offset);
    func_80271F34_de(&pos, &pos, &((Player *)(actor))->pos);
    marker->active = 1;
    marker->x = pos.x;
    marker->y = pos.y + func_8024D284_de(actor) * D_800C7F08[1];
    marker->z = pos.z;
    marker->scale = D_800C7F10;
}
