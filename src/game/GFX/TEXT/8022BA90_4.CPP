#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "GFX/TEXT/8022BA90_4.H"


/* Initialises an object: clears the words at 0x8, 0x9C, 0xA4, 0xA8, 0xB4 and 0xB8, sets the words at
   0x0 and 0x4 to -1, writes the two constants at D_800C2D48_de into the floats at 0xAC and 0xB0, the two
   at D_800C2D50_de into the floats at 0x90, 0x94 and 0x98 (the first of them twice) and D_800C2D58_de into
   the float at 0xA0. */


void func_8022C67C_de(void *record) {
    ObjRecAtB8 *obj = record;
    float f1 = D_800C2D48_de;
    float f2 = *(float *)((char *)&D_800C2D48_de + 4);
    float f0 = D_800C2D50_de;
    float f3 = *(float *)((char *)&D_800C2D50_de + 4);
    float f4 = D_800C2D58_de;

    obj->unkB4 = 0;
    obj->unk8 = 0;
    obj->unkB8 = 0;
    obj->unk4 = -1;
    obj->unk0 = -1;
    obj->unkA8 = 0;
    obj->unk9C = 0;
    obj->unkA4 = 0;
    obj->unkAC = f1;
    obj->unkB0 = f2;
    obj->unk90 = f0;
    obj->unk94 = f3;
    obj->unk98 = f0;
    obj->unkA0 = f4;
}

s32 func_8022C6E4_de(void *player, void *bodyActor) {
    s16 state = ((Shared_ActorView *)player)->action;
    s32 blocked;

    if ((state == 0x15) || (state == 0x13) || (state == 0x14)) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    if (blocked == 0) {
        if ((((LevelActor *)bodyActor)->motionState & 0x20000) == 0) {
            return 0;
        }
        if (((Shared_ActorView *)player)->action == 0xD) {
            return 0;
        }
        if (((Shared_ActorView *)player)->action == 0xE) {
            return 0;
        }
        Weapons_SetPlayerState(player, bodyActor, 0xD);
        return 1;
    }
    return 0;
}

s32 func_8022C760_de(void *player, void *bodyActor) {
    s16 state = ((Shared_ActorView *)player)->action;
    s32 blocked;
    s32 flags;

    if ((state == 0x15) || (state == 0x13) || (state == 0x14)) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    if (blocked == 0) {
        if (((MovementDescriptor *)((LevelActor *)bodyActor)->definition)->body.header.flags & 1) {
            if (((Shared_ActorView *)player)->action == 0x26) {
                return 0;
            }
            if (((Shared_ActorView *)player)->unk_0x0664 & 0x8000) {
                return 0;
            }
            flags = ((LevelActor *)bodyActor)->motionState;
            if (flags & 0x80) {
                goto fire;
            }
        }
        return 0;
    }
    return 0;
fire:
    ((LevelActor *)bodyActor)->motionState = flags | 0x100;
    Weapons_SetPlayerState(player, bodyActor, 0xF);
    return 1;
}

s32 func_8022C7F8_de(void *player, LevelActor *actor) {
    f32 field6E4;

    if (((Shared_ActorView *)player)->unk_0x07E8 == 0) {
        field6E4 = ((Shared_ActorView *)player)->unk_0x06E4;
        if (!(D_800C2D5C_de < field6E4)) {
            if (!(actor->motionState & 0xC0000)) {
                if (((MovementDescriptor *)actor->definition)->body.header.flags & 2) {
                    if ((((Shared_ActorView *)player)->unk_0x06B0 & 0x10) && (((Shared_ActorView *)player)->stun <= 0.0f)) {
                        Weapons_SetPlayerState(player, actor, 5);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/** Return zero. */
int func_8022C88C_de(void *unused0, void *unused1, s32 *unused2) {
    return 0;
}

void func_8022C894_de(void *arg0, LevelActor *actor) {
    actor->position1.x = 0;
    actor->position1.y = 0;
    actor->position1.z = 0;
}
