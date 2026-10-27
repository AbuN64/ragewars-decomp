#ifndef AI_ENEMIES_TURRETAI_H
#define AI_ENEMIES_TURRETAI_H
#include "COMMON/OBJ.H"
extern int Turret_Anim_ACTIVATE(struct Owner *owner);
extern void Turret_Construct(struct OwnerRecAtE4 *owner, struct RecordRecAt13C *record);
extern void Turret_SpecialEffects(void *arg0, ObjRecAt8V1 *event);
extern CQuatern CVector3_GetDirectionRotation2(CVector3*dir);
extern f32 D_800C6B30;
extern s32 Turret_BuildPlaneRot(s32 out, s32 actor, struct RotationObject*rotation);
#endif
