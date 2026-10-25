#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"


/* Places a marker in front of an actor: takes the node in *slot or allocates one from pool
   D_8013B1A8, turns the offset (0, 0, distance) into world space by the actor's facing through
   func_8024BC94_de, adds the actor's position and stores it as short coordinates, the height raised by
   the actor's size scaled by D_800C7F08[1], with scale D_800C7F10 and the node marked active. */






extern f32 D_800C7F08[];

extern Marker *func_80268C1C_de(char *, s32);

extern void func_8024BC94_de(CVector3 *, void *, CVector3);

extern void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);

extern f32 Particle_GetActorHeight(void *);

/* Returns whether the entity registered under an id in D_800D052C has flag 1 (mode 0) or flag 2
   (mode 1) set in its word at 0x14; other modes give 0. The interval also holds the empty function
   func_8022E940_de that follows. */


extern func_80204468_S3 *D_800D052C[];

u8 func_8022E758_de(s32 unused0, s32 arg1) {
    u8 *ptr;

    if (arg1 == 0x2DA) {
        ptr = &D_801462C8.local;
        if (*ptr != 0) {
            return ptr[0xE];
        }
    }
    return 1;
}

void func_8022E78C_de(Player *actor, Marker **slot, s32 kind, f32 distance) {
    Marker *marker;
    CVector3 offset;
    CVector3 pos;

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
    Particle_AddVec3(&pos, &pos, &actor->pos);
    marker->active = 1;
    marker->x = pos.x;
    marker->y = pos.y + Particle_GetActorHeight(actor) * D_800C7F08[1];
    marker->z = pos.z;
    marker->scale = D_800C7F10;
}

void func_8022E890_de(void *unused0, s32 *arg1) {
    s32 temp;

    temp = *arg1;
    if (temp != 0) {
        Render_ReleaseLight(&D_8013B1A8, temp);
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
