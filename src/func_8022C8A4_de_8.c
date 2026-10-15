#include "span_1000/code_8022C894.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
#include "common/unused.h"

extern u8 D_801462E5;

/* Places a marker in front of an actor: takes the node in *slot or allocates one from pool
   D_8013B1A8, turns the offset (0, 0, distance) into world space by the actor's facing through
   func_8024BC94_de, adds the actor's position and stores it as short coordinates, the height raised by
   the actor's size scaled by D_800C7F08[1], with scale D_800C7F10 and the node marked active. */






extern f32 D_800C7F08[];

extern Marker *func_80268C1C_de(char *, s32);

extern void func_8024BC94_de(Vec3 *, void *, Vec3);

extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

extern f32 func_8024D284_de(void *);

/* Returns whether the entity registered under an id in D_800D052C has flag 1 (mode 0) or flag 2
   (mode 1) set in its word at 0x14; other modes give 0. The interval also holds the empty function
   func_8022E940_de that follows. */


extern func_80204468_S3 *D_800D052C[];

u8 func_8022E758_de(s32 arg0, s32 arg1) {
    u8 *ptr;

    if (arg1 == 0x2DA) {
        ptr = &D_801462E5;
        if (*ptr != 0) {
            return ptr[0xE];
        }
    }
    return 1;
}

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

void func_8022E890_de(void *unused0, s32 *arg1) {
    s32 temp;

    temp = *arg1;
    if (temp != 0) {
        func_80268C7C_de(&D_8013B1A8, temp);
        *arg1 = 0;
    }
}

int func_8022E8D0_de(short id, int mode) {
    switch (mode) {
    case 0:
        if (!(D_800D052C[id]->unk14 & 1)) {
            break;
        }
        return 1;
    case 1:
        if (D_800D052C[id]->unk14 & 2) {
            return 1;
        }
        break;
    }
    return 0;
}

void func_8022E940_de(void) {
}
