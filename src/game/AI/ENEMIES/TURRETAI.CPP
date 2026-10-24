/* SN debug stream left in us-rev1 (src/ragewars_debug_stream_us_rev1.c, ROM 0xE7092..0xF6880): function records at the retail vram */
#include "COMMON/EXTERNS_15.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJ.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

extern CQuatern CVector3_GetDirectionRotation2(CVector3 *dir);

CQuatern CVector3_GetDirectionRotation2(CVector3 *dir);

void func_80274098_de(void *, void *, void *);

void func_8027347C_de(void *, f32, f32, f32);

s32 func_8027254C_de(f32 *, f32);

void func_80273448_de(char *, f32, f32, f32);

void func_8026F620_de(f32 *, f32 *, f32 *);

void func_80273D6C_de(struct Mtx *);

static inline void alignment_from_rider(f32 *matrix, RiderRecAt130V1 *rider) {
    CQuatern q;
    CVector3 aim;
    aim.x = rider->aim.x;
    aim.y = rider->aim.y;
    aim.z = rider->aim.z;
    q = CVector3_GetDirectionRotation2(&aim);
    func_80274244_de(&q, matrix);
}


CQuatern CVector3_GetDirectionRotation2(CVector3 *dir) {
    CQuatern q;
    CVector3 up;
    CVector3 axis;
    f32 angle;
    f32 turn;

    up = D_800C19F0;
    func_8027207C_de(dir);
    if (dir->y > D_800C19FC_de) {
        q.x = q.y = q.z = 0.0f;
        q.w = D_800C1A00_de;
    } else if (dir->y < D_800C1A04_de) {
        angle = D_800C1A08_de;
        q.x = D_80115DEC = func_802B7130_de(angle);
        q.y = 0.0f;
        q.z = 0.0f;
        q.w = func_802B6560_de(angle);
    } else {
        turn = func_802745D0_de(dir->x * up.x + dir->y * up.y + dir->z * up.z);
        func_80272018_de(&axis, &up, dir);
        func_8027207C_de(&axis);
        angle = turn * D_800C1A0C;
        D_80115DEC = func_802B7130_de(angle);
        q.x = axis.x * D_80115DEC;
        q.y = axis.y * D_80115DEC;
        q.z = axis.z * D_80115DEC;
        q.w = func_802B6560_de(angle);
    }
    return q;
}

void Turret_CalcOrientMtx(struct Owner *owner, RiderRecAt130V1 *rider) {
    CQuatern rotation;
    CQuatern combined;
    f32 model[16];
    f32 alignment[16];
    CTurretIntelligence *segment;
    f32 angleScale;
    f32 angle;
    f32 sine;

    segment = &owner->navigationTrack->segment;
    alignment_from_rider(alignment, rider);
    if (segment->m_RotNode == -1) {
        angle = owner->heading;
        angleScale = D_800C1A10_de;
        sine = func_802B7130_de(angle * angleScale);
        rotation.x = 0.0f;
        rotation.y = sine;
        D_80115DEC = sine;
        rotation.z = 0.0f;
        rotation.w = func_802B6560_de(owner->heading * angleScale);
    } else {
        D_80115DEC = func_802B7130_de(rider->heading * D_800C1A14_de);
    }
    rotation.x = 0.0f;
    rotation.z = 0.0f;
    rotation.y = D_80115DEC;
    rotation.w = func_802B6560_de(rider->heading * D_800C1A18);
    func_80274098_de(&combined, &rotation, &owner->orientation);
    func_80274244_de(&combined, model);
    func_8027347C_de(model, owner->scale.x, owner->scale.y, owner->scale.z);
    func_8027254C_de(&owner->position.x, 20000.0f);
    func_80273448_de((char *)model, owner->position.x, owner->position.y, owner->position.z);
    func_8026F620_de(&owner->transform.right.x, alignment, model);
    func_80273D6C_de(&owner->transform);
}
