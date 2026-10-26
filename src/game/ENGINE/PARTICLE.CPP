#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "RSP/8026E1F8_5.H"
#include "abi.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "TYPES.H"
#include "ENGINE/PARTICLE.H"
#include "particle/8027A0F4_4.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "SCENE/802508E0_4.H"
#include "particle/80271B18_3.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Draws an actor's ground shadow: probes the ground under the actor through func_80243A90_de into D_801041F0, and when ground is found tilts the shadow model from D_8011FFB0 to the ground normal, scales it by the actor's size shrinking with height above the ground, fades it with height (and with lost health for actors flagged 1), places it on the ground and draws it through func_8026992C_de between render-mode commands. */
extern char D_8011FFB0;

extern char D_80100030;

extern Ground D_801041F0;


extern Gfx *g_displayListCursor;

extern s32 Unicol_MoveActorWithCollision(Shared_ParticleInstance *, CVector3, void *);

extern CQuatern func_80271818_de(CVector3 *);

extern void MultiplyQuaternions(CQuatern *out, CQuatern *a, CQuatern *b);

extern s32 GraphU64_LimitVectorLength(CVector3 *, f32);

extern void MatrixFromQuaternion(CQuatern *, f32 *);

extern void ScaleMatrixLocal(f32 *, f32, f32, f32);

extern void TranslateMatrix(f32 *, f32, f32, f32);

extern void GraphU64_ConvertMatrixToFixed(f32 *, void *);

extern void func_8026992C_de(void *model, s32 pass, u8 alpha);

extern s32 D_80140FF8;


extern char D_800C4D38_de;

extern char D_800C4D50_de;

extern char s_simpPartModelText;

extern char D_0026D7F4;




extern s32 SetN64_GetDirectoryEntry(s32 *, s32, s32);


extern s32 func_802540F4_de(s32, void **, s32, void *, s32);

extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);

extern void Geometry_QueueModelInstance(void **, void *, s32, void *, void *, s32);

extern void Cache_UnlockResource(s32, void *);
extern void *func_802799C0_de(void *, s32);

void func_8027E784_de(Shared_Particle *actor, GameplayCamera *view) {
    f32 matrix[16];
    CVector3 point;
    CQuatern rotation;
    CQuatern tilt;
    CQuatern roll;
    Shared_ParticleInstance probe;
    void *model;
    Ground *ground;
    f32 angle;
    f32 height;
    f32 alpha;
    f32 size;
    f32 health;
    f32 floor;
    f32 shrink;

    model = func_802799C0_de(&D_8011FFB0, 1);
    if (model == 0) {
        return;
    }
    probe = actor->inst;
    probe.velocity.x = 0.0f;
    probe.velocity.y = 0.0f;
    probe.velocity.z = 0.0f;
    probe.pos.y += 10.24f;
    point.x = probe.pos.x;
    point.y = probe.pos.y - 102400.0f;
    point.z = probe.pos.z;
    Unicol_MoveActorWithCollision(&probe, point, &D_80100030);
    ground = &D_801041F0;
    if (ground->found == 0) {
        return;
    }
    angle = 0.78539824f;
    tilt = func_80271818_de(&ground->normal);
    roll.x = D_80115DEC = Math_Sinf(angle);
    roll.y = 0.0f;
    roll.z = 0.0f;
    roll.w = Math_Cosf(angle);
    MultiplyQuaternions(&rotation, &roll, &tilt);
    floor = ground->height;
    height = actor->inst.pos.y - floor;
    alpha = ((RW_MIN(200.0f - height * 0.30517578f, 255.0f)) < (0.0f) ? (0.0f) : (RW_MIN(200.0f - height * 0.30517578f, 255.0f)));
    size = actor->size.z * 7.68f;
    if (actor->desc->renderModel != 0) {
        size *= 8.0f;
    }
    size *= actor->desc->scaling->shadowScale;
    shrink = height * 0.1f;
    size = ((({ f32 _m = (size - shrink); if (!(_m <= (size))) _m = (size); _m; })) < (0.0f) ? (0.0f) : (({ f32 _m = (size - shrink); if (!(_m <= (size))) _m = (size); _m; })));
    if (actor->desc->flags & 1) {
        health = actor->life;
        if (0.0f < health) {
            alpha *= (health - actor->time) / health;
        }
    }
    point.x = actor->inst.pos.x;
    point.z = actor->inst.pos.z;
    point.y = floor;
    GraphU64_LimitVectorLength(&point, 20000.0f);
    MatrixFromQuaternion(&rotation, matrix);
    ScaleMatrixLocal(matrix, size, 1.0f, size);
    TranslateMatrix(matrix, point.x, point.y, point.z);
    GraphU64_ConvertMatrixToFixed(matrix, model);
    {
        Gfx *cmd = g_displayListCursor++;
        gDPPipeSync(cmd);
        cmd = g_displayListCursor++;
        gDPSetCycleType(cmd, G_CYC_2CYCLE);
    }
    func_8026992C_de(model, 1, (u32)alpha);
    {
        Gfx *cmd = g_displayListCursor++;
        gDPPipeSync(cmd);
        cmd = g_displayListCursor++;
        gDPSetCycleType(cmd, G_CYC_1CYCLE);
    }
}

void Particle_DrawModel(Shared_Particle *particle, GameplayCamera *view) {
    CVector3 delta;
    void *modelTable;
    PackedMatrixWords *matrix;
    void **resource;
    s32 key;
    s32 found;
    s32 index;
    f32 amount;

    index = 0;
    if (D_80140FF8 == 1) {
        matrix = &particle->mtx[D_800D297C];
    } else {
        matrix = func_802799C0_de(&D_8011FFB0, 1);
        if (matrix == 0) {
            return;
        }
        GraphU64_TransformPoint(view->worldToView, &particle->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        Particle_BuildMatrix(particle, matrix, view, amount);
    }

    if (particle->resource == 0) {
        resource = Cache_RequestResource(0, particle->desc->renderModel,
                                particle->desc->renderModel, 0x18,
                                0, 0, 0, &D_800C4D38_de, 1);
        if (resource != 0) {
            key = SetN64_GetDirectoryEntry(*resource,
                                particle->desc->renderModel, 1);
            Cache_ReleaseResource(0, resource);
            found = func_802540F4_de(0, &modelTable, key, &D_800C4D50_de, 1);
            if (found != 0) {
                particle->resource = SetN64_LocatePackSection(
                    (s32)modelTable, key, index % *(s32 *)modelTable,
                    &particle->resourceSize);
                Cache_ReleaseResource(0, (void *)found);
            }
        }
        if (particle->resource == 0) {
            return;
        }
    }

    resource = Cache_RequestResource(0, particle->resource,
                            particle->resource, particle->resourceSize,
                            0, 0, &D_0026D7F4, &s_simpPartModelText, 1);
    if (resource != 0) {
        Geometry_QueueModelInstance(resource, matrix, 0,
                      (char *)particle + (((D_800D297C * 3) << 3) + 0xE0), 0, -1);
        Cache_UnlockResource(0, resource);
    }
}
