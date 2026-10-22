#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "abi.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "TYPES.H"
#include "particle/8027A0F4_5.H"
#include "SCENE/802508E0_4.H"
#include "particle/80271B18_3.H"

/* Draws an actor's ground shadow: probes the ground under the actor through func_80243A90_de into D_801041F0, and when ground is found tilts the shadow model from D_8011FFB0 to the ground normal, scales it by the actor's size shrinking with height above the ground, fades it with height (and with lost health for actors flagged 1), places it on the ground and draws it through func_8026992C_de between render-mode commands. */
extern char D_8011FFB0;

extern char D_80100030;

extern Ground D_801041F0;

extern f32 D_80115DEC;

extern Gfx *D_80110634;

extern s32 func_80243A90_de(Shared_ParticleInstance *, CVector3, void *);

extern void func_80271818_de(CQuatern *, CVector3 *);

extern void func_80274098_de(CQuatern *out, CQuatern *a, CQuatern *b);

extern s32 func_8027254C_de(CVector3 *, f32);

extern void func_80274244_de(CQuatern *, f32 *);

extern void func_8027347C_de(f32 *, f32, f32, f32);

extern void func_80273448_de(f32 *, f32, f32, f32);

extern void func_8027027C_de(f32 *, void *);

extern void func_8026992C_de(void *model, s32 pass, u8 alpha);

extern s32 D_80140FF8;

extern s32 D_800D297C;

extern char D_800C4D38_de;

extern char D_800C4D50_de;

extern char D_800C4D68_de;

extern char D_0026D7F4;


extern void Particle_BuildMatrix(void *, s32, s32, f32);


extern s32 func_8028FE28_de(s32 *, s32, s32);

extern void func_80253838_de(void *arg0, void *arg1);

extern s32 func_802540F4_de(s32, void **, s32, void *, s32);

extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern void Render_QueueModelInstance(void **, void *, s32, void *, void *, s32);

extern void func_80253754_de(s32, void *);
extern void *func_802799C0_de(void *, s32);

void func_8027E784_de(Shared_Particle *actor, struct Shared_ParticleView *view) {
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
    func_80243A90_de(&probe, point, &D_80100030);
    ground = &D_801041F0;
    if (ground->found == 0) {
        return;
    }
    angle = 0.78539824f;
    func_80271818_de(&tilt, &ground->normal);
    roll.x = D_80115DEC = func_802B7130_de(angle);
    roll.y = 0.0f;
    roll.z = 0.0f;
    roll.w = func_802B6560_de(angle);
    func_80274098_de(&rotation, &roll, &tilt);
    floor = ground->height;
    height = actor->inst.pos.y - floor;
    alpha = ((RW_MIN(200.0f - height * 0.30517578f, 255.0f)) < (0.0f) ? (0.0f) : (RW_MIN(200.0f - height * 0.30517578f, 255.0f)));
    size = actor->size.z * 7.68f;
    if (actor->desc->renderModel != 0) {
        size *= 8.0f;
    }
    size *= actor->desc->distanceRange->shadowSize;
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
    func_8027254C_de(&point, 20000.0f);
    func_80274244_de(&rotation, matrix);
    func_8027347C_de(matrix, size, 1.0f, size);
    func_80273448_de(matrix, point.x, point.y, point.z);
    func_8027027C_de(matrix, model);
    {
        Gfx *cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetCycleType(cmd, G_CYC_2CYCLE);
    }
    func_8026992C_de(model, 1, (u32)alpha);
    {
        Gfx *cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetCycleType(cmd, G_CYC_1CYCLE);
    }
}

void Particle_DrawModel(void *arg0, struct Shared_ParticleView *arg1) {
    CVector3 delta;
    void *sp38;
    void *lookup;
    void **resource;
    s32 key;
    s32 found;
    s32 index;
    f32 amount;

    index = 0;
    if (D_80140FF8 == 1) {
        lookup = (char *)arg0 + ((D_800D297C << 6) + 0x60);
    } else {
        lookup = func_802799C0_de(&D_8011FFB0, 1);
        if (lookup == 0) {
            return;
        }
        func_80272898_de(&arg1->viewMtx, &((Shared_Particle *)arg0)->inst.pos, &delta);
        amount = delta.z;
        if (amount < 0.0f) {
            amount = -amount;
        }
        Particle_BuildMatrix(arg0, (s32)lookup, (s32)arg1, amount);
    }

    if (((Shared_Particle *)arg0)->resource == 0) {
        resource = func_8025193C_de(0, ((Shared_Particle *)arg0)->desc->renderModel,
                                ((Shared_Particle *)arg0)->desc->renderModel, 0x18,
                                0, 0, 0, &D_800C4D38_de, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource,
                                ((Shared_Particle *)arg0)->desc->renderModel, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp38, key, &D_800C4D50_de, 1);
            if (found != 0) {
                ((Shared_Particle *)arg0)->resource = func_8028FE3C_de(
                    (s32)sp38, key, index % *(s32 *)sp38,
                    &((Shared_Particle *)arg0)->resourceSize);
                func_80253838_de(0, (void *)found);
            }
        }
        if (((Shared_Particle *)arg0)->resource == 0) {
            return;
        }
    }

    resource = func_8025193C_de(0, ((Shared_Particle *)arg0)->resource,
                            ((Shared_Particle *)arg0)->resource, ((Shared_Particle *)arg0)->resourceSize,
                            0, 0, &D_0026D7F4, &D_800C4D68_de, 1);
    if (resource != 0) {
        Render_QueueModelInstance(resource, lookup, 0,
                      (char *)arg0 + (((D_800D297C * 3) << 3) + 0xE0), 0, -1);
        func_80253754_de(0, resource);
    }
}
