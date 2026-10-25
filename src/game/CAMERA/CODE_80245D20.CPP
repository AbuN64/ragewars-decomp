#include "include_asm.h"
#include "COMMON/GROUP.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "CAMERA/CODE_80245D20.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
extern void func_8024DD10_de(signed char *arg0);

extern f32 D_800CB430_de[],D_800D2988[];

extern s32 func_8024E62C_de(Actor_func_80245D30_de *);

extern f32 Particle_GetHorizontalAngle(CVector3 *);

extern void Particle_ScaleVector(CVector3 *, CVector3 *, f32);

 extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);

static inline s32 currentEnabled(Actor_func_80245D30_de *actor) {
    if (actor->flags & 0x3000) return 1;
    if (actor->flags & 0x4000) return func_8024E62C_de(actor);
    return 0;
}

void func_80245D30_de(Actor_func_80245D30_de *actor, Material_func_80245D30_de *arg1, CVector3 *arg2, s32 arg3) {
    Actor_func_80245D30_de *rider;
    f32 speed;
    CVector3 v10,v20;
    f32 sp30;
    f32 sp34;
    f32 strength;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    f32 var_f20;
    f32 var_f3;
    f32 targetAngle,oldAngle;
    s32 temp_v1;
    s32 var_condition_bit;
    s32 var_v0;
    s32 var_v1;
    u16 flags;
    CVector3 *var_a0;

    if (actor->kind == 1) {
        rider=actor;
        var_v1=currentEnabled(actor);
        var_v0 = rider->flags & 3;
    } else {
        var_v1 = 0;
        var_v0 = 0;
    }
    if ((var_v0 != 0) || ((var_v1 == 0) && !(arg1->flags & 0x8000))) {
        actor->current.x = 0.0f;
        actor->current.y = 0.0f;
        actor->current.z = 0.0f;
        return;
    }
    if ((arg1->flags & 0x100) && (arg3 != 0)) {
        v10.x = (f32) arg1->x * 0.007874016f;
        v10.y = (f32) arg1->y * 0.007874016f;
        v10.z = (f32) arg1->z * 0.007874016f;
        strength = (f32) arg1->strength;
        speed=strength * 3.0f;
        var_f20 = (strength + 1.0f) * 0.00872664712369442f;
        Particle_ScaleVector(&v10,&v10,speed);
        flags = arg1->flags;
        if (flags & 0x600) {
            if (flags & 0x400) {
                var_f20 = -var_f20;
            }
            if (actor->kind == 1) {
                actor->yaw = (f32) (actor->yaw + var_f20);
            }
        }
        if ((arg1->flags & 0x2000) && (actor->kind == 1)) {
            rider=actor;
            v20=v10;
            v20.y = 0.0f;
            temp_f0_2 = Particle_GetHorizontalAngle(&v20);
            temp_f1 = actor->yaw;
            sp34 = temp_f0_2;
            sp30 = temp_f1;
            if (temp_f0_2 != temp_f1) {
                func_80274020_de(&sp30);
                func_80274020_de(&sp34);
                if (sp30 > sp34) {
                    var_f3=sp34+6.2831855f;
                    if ((var_f3-sp30)<(sp30-sp34)) sp34=var_f3;
                } else {
                    var_f3=sp34-6.2831855f;
                    if ((sp30-var_f3)<(sp34-sp30)) sp34=var_f3;
                }
                targetAngle=sp34; oldAngle=sp30;
                if (oldAngle < targetAngle) {
                    sp30=oldAngle+((f32)arg1->strength*D_800CB430_de[1]*D_800D2988[0]*0.017453294f);
                    if (targetAngle<sp30) sp30=targetAngle;
                } else {
                    sp30=oldAngle-((f32)arg1->strength*D_800CB430_de[1]*D_800D2988[0]*0.017453294f);
                    if (sp30<targetAngle) sp30=targetAngle;
                }
                func_80274020_de(&sp30);
            }
            rider->yaw = sp30;
        }
    } else {
        v10.x = 0.0f;
        v10.y = 0.0f;
        v10.z = 0.0f;
    }
    var_f0_2 = (f32) arg1->strength * D_800CB430_de[0] * D_800D2988[0];
    var_f0_2 = ((var_f0_2 < 0.0f ? 0.0f : var_f0_2) > 1.0f ? 1.0f : (var_f0_2 < 0.0f ? 0.0f : var_f0_2));
    var_a0=&actor->current;
    func_80271FC8_de(var_a0, var_f0_2, var_a0, &v10);
    arg2->x = (f32) (arg2->x + actor->current.x);
    arg2->z = (f32) (arg2->z + actor->current.z);
    if (arg1->flags & 0x100) {
        if (v10.y != 0.0f) {
            actor->vertical = 0.0f;
        } else {
            temp_f0_5 = actor->current.y;
            actor->current.y = (f32) (temp_f0_5 + ((v10.y - temp_f0_5) * 0.2f));
        }
        actor->vertical = (f32) (actor->vertical + ((2.0f * (actor->current.y * 10.24f)) + 4.0f));
        return;
    }
    actor->current.y += (v10.y-actor->current.y)*0.2f;
}

/* Resets an object through func_8024DD10_de, then clears its words from 0x1C to 0x38 and at 0x40, 0x44
   and 0x4C, sets the word at 0x3C to -1 and stores D_800C8914 in the float at 0x48. */




void Camera_ResetActorMotion(void *levelActor) {
    float k;

    func_8024DD10_de(levelActor);
    k = D_800C8914;
    ((LevelActor *)levelActor)->position1.x = 0;
    ((LevelActor *)levelActor)->position1.y = 0;
    ((LevelActor *)levelActor)->position1.z = 0;
    ((LevelActor *)levelActor)->motionAngles.x = 0;
    ((LevelActor *)levelActor)->motionAngles.y = 0;
    ((LevelActor *)levelActor)->motionAngles.z = 0;
    ((LevelActor *)levelActor)->attached = 0;
    ((LevelActor *)levelActor)->motionState = 0;
    ((LevelActor *)levelActor)->motionIndex = -1;
    ((LevelActor *)levelActor)->floorHeight = 0;
    ((LevelActor *)levelActor)->floorDirection.x = 0;
    ((LevelActor *)levelActor)->floorDirection.z = 0;
    ((LevelActor *)levelActor)->floorDirection.y = k;
}


extern CollisionInfo8020CD74 D_801040D0;
extern f32 Anim_GetPolygonHeight(s32, f32, f32);
extern s32 Camera_MoveActorWithCollision(Shared_ParticleInstance *, CVector3, s32 *);

void Camera_MoveToXZKeepHeight(Shared_ParticleInstance *actor, f32 x, f32 z) {
    CVector3 saved;
    CVector3 position;
    s32 keep;
    f32 height;

    height = actor->pos.y - Anim_GetPolygonHeight(actor->unk14, actor->pos.x, actor->pos.z);
    saved = actor->velocity;
    actor->velocity.x = actor->velocity.y = actor->velocity.z = 0.0f;
    position.x = x;
    position.y = actor->pos.y;
    position.z = z;
    keep = D_801040D0.w[0];
    Camera_MoveActorWithCollision(actor, position, D_801040D0.w);
    D_801040D0.w[0] = keep;
    actor->velocity = saved;
    actor->pos.y = Anim_GetPolygonHeight(actor->unk14, actor->pos.x, actor->pos.z) + height;
}
