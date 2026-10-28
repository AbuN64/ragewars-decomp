#include "COMMON/EXTERNS_15.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJ.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "FX/80271B18.H"
#include "AI/ENEMIES/TURRETAI.H"
#include "include_asm.h"

/* TURRETAI.CPP */
/* SN debug stream left in us-rev1 (src/ragewars_debug_stream_us_rev1.c, ROM 0xE7092..0xF6880): function records at the retail vram */

extern void Graphu64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

void MultiplyQuaternions(void *, void *, void *);

void ScaleMatrixLocal(void *, f32, f32, f32);

s32 Graphu64_LimitVectorLength(f32 *, f32);

void TranslateMatrix(char *, f32, f32, f32);

void Graphu64_MultiplyAffineMatrices(f32 *, f32 *, f32 *);

void SwapMatrixUpForward(struct Mtx *);

static inline void alignment_from_rider(f32 *matrix, RiderRecAt130V1 *rider) {
    CQuatern q;
    CVector3 aim;
    aim.x = rider->aim.x;
    aim.y = rider->aim.y;
    aim.z = rider->aim.z;
    q = CVector3_GetDirectionRotation2(&aim);
    MatrixFromQuaternion(&q, matrix);
}

CQuatern CVector3_GetDirectionRotation2(CVector3 *dir) {
    CQuatern q;
    CVector3 up;
    CVector3 axis;
    f32 angle;
    f32 turn;

    up = D_800C19F0;
    GraphU64_NormalizeVec3(dir);
    if (dir->y > D_800C19FC_de) {
        q.x = q.y = q.z = 0.0f;
        q.w = D_800C1A00_de;
    } else if (dir->y < D_800C1A04_de) {
        angle = D_800C1A08_de;
        q.x = D_80115DEC = Gu_Sinf(angle);
        q.y = 0.0f;
        q.z = 0.0f;
        q.w = Math_Cosf(angle);
    } else {
        turn = Graphu64_ArcCos(dir->x * up.x + dir->y * up.y + dir->z * up.z);
        Graphu64_CrossVectors(&axis, &up, dir);
        GraphU64_NormalizeVec3(&axis);
        angle = turn * D_800C1A0C;
        D_80115DEC = Gu_Sinf(angle);
        q.x = axis.x * D_80115DEC;
        q.y = axis.y * D_80115DEC;
        q.z = axis.z * D_80115DEC;
        q.w = Math_Cosf(angle);
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
        sine = Gu_Sinf(angle * angleScale);
        rotation.x = 0.0f;
        rotation.y = sine;
        D_80115DEC = sine;
        rotation.z = 0.0f;
        rotation.w = Math_Cosf(owner->heading * angleScale);
    } else {
        D_80115DEC = Gu_Sinf(rider->heading * D_800C1A14_de);
    }
    rotation.x = 0.0f;
    rotation.z = 0.0f;
    rotation.y = D_80115DEC;
    rotation.w = Math_Cosf(rider->heading * D_800C1A18);
    MultiplyQuaternions(&combined, &rotation, &owner->orientation);
    MatrixFromQuaternion(&combined, model);
    ScaleMatrixLocal(model, owner->scale.x, owner->scale.y, owner->scale.z);
    Graphu64_LimitVectorLength(&owner->position.x, 20000.0f);
    TranslateMatrix((char *)model, owner->position.x, owner->position.y, owner->position.z);
    Graphu64_MultiplyAffineMatrices(&owner->transform.right.x, alignment, model);
    SwapMatrixUpForward(&owner->transform);
}

/* 800C6B18.CPP */
const unsigned int D_auto_src_rw_pool_802034A4_C7718_us_rev1[5] = {
    0x3F000000, 0x40C90FDC, 0x3F000000, 0x3C23D70A, 0x3C23D70A,
};

/* 800C6B2C.CPP */
/* ROM-grounded data: src/rw_pool_8020388C_C772C_us_rev1.c */
const unsigned int D_blob_f9c773ad0f04affb460a[2] = {
    0x3F800000, 0xBFC90FDC,
};
