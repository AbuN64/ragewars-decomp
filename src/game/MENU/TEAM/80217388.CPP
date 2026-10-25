#include "include_asm.h"
#include "COMMON/PROBE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "particle/8024D018_4.H"
#include "MENU/TEAM/80217388.H"
#include "FX_2/80271B18.H"

extern void *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);






void func_80217388_de(void *arg0, void *arg1) {
    void *owner = 0;
    u8 type = *(u8 *)arg0;

    switch (type) {
    case 1:
    case 2:
        owner = arg0;
        break;
    case 0:
        owner = (void *)((LevelActor *)arg0)->resourceFlags;
        break;
    }

    if (((Dest *)arg1)->sound != 0) {
        func_8025E1C4_de(owner);
        if (((Dest *)arg1)->sound != 0) {
            func_8025CA24_de(func_8025CC6C_de(), ((Dest *)arg1)->sound);
            ((Dest *)arg1)->sound = 0;
        }
    }
}

extern void Particle_SubtractVectors(CVector3 *result, CVector3 *left, CVector3 *right);
extern f32 Particle_GetActorRadius(void *arg0);
extern void Particle_ScaleVector(void *result, void *vector, f32 scale);
extern void Particle_AddVec3(CVector3 *result, CVector3 *left, CVector3 *right);
extern void func_8024E79C_de(void *arg0, CVector3 value, void *arg4, s32 *arg5,
                          s32 arg6, s32 arg7);







void func_8021740C_de(void *arg0, s32 unused, void *arg2, Player *arg3,
                   void *arg4, s32 *arg5) {
    CVector3 offset;
    CVector3 position;
    f32 distance;

    if (arg3 != 0) {
        Particle_SubtractVectors(&offset, &((Player *)(arg2))->pos,
                       &arg3->pos);
        offset.y = 0.0f;
        Particle_NormalizeVec3(&offset.x);
    } else {
        offset.x = 0.0f;
        offset.y = 0.0f;
        offset.z = 0.0f;
    }

    distance = Particle_GetActorRadius(arg2) + Particle_GetActorRadius(arg0) + D_800C21E8_de;
    Particle_ScaleVector(&offset, &offset, distance);
    Particle_AddVec3(&position, &((Player *)(arg2))->pos, &offset);
    func_8024E79C_de(arg2, position, arg4, arg5, 0, 0);
}

void func_802174E4_de(Shared_ActorView *arg0, void *unused1, Output80216D3C *arg2) {
    Triple local1;
    Triple local2;

    local1 = arg0->position.words;
    local2.x = 0;
    local2.y = 0;
    local2.z = 0;
    arg2->type = 3;
    arg2->unk4 = 0;
    arg2->unk8 = 0;
    arg2->first = local1;
    arg2->second = local2;
    arg2->unk24 = 0;
    local2.y = 0;
    local1.y = 0;
    arg2->third = local1;
    arg2->fourth = local2;
    arg2->unk40 = 0;
}








void func_80217594_de(Player *arg0, s32 unused1, s32 arg2, s32 *entry) {
    if (entry[0] != 0) {
        do {
            if ((arg2 & entry[0]) != 0) {
                func_8024DBC0_de(arg0,
                              arg0->pos,
                              entry[1],
                              Nav_RandomBetween(D_800C21EC_de, D_800C21F0_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8021762C[1] = {
    0x43524541,
};
#endif
