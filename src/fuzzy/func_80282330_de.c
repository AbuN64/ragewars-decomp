#include "TYPES.H"
#include "common/unused.h"
#include "span_1000/code_8027A0F4.h"
#include "gbi.h"

typedef struct DrawParticle {
    Shared_Particle particle;
    char reserved1DC[0x18];
    struct DrawParticle *next;
} DrawParticle;
typedef struct ParticleDrawList {
    char reserved[0xFC14];
    DrawParticle *head;
} ParticleDrawList;
struct Shared_ParticleView;
extern Gfx *D_80110634;
extern Globals_func_804220A8_de D_80140FE8_de;
extern s32 D_80140FF8, D_800D297C;
extern float D_800C4E54_de;
extern void func_8026D914_de(s32 arg0);
extern void func_80272898_de(void *arg0, void *arg1, void *arg2);
extern void func_8027DD48_de(Shared_Particle *particle, void *matrix, void *camera, f32 depth);
extern s32 func_80296B74_de(f32 (*arg0)[4], f32 *arg1);
extern void func_8027EB2C_de(void *arg0, struct Shared_ParticleView *arg1);
extern void func_8027ED6C_de(Shared_Particle *particle, struct Shared_ParticleView *view);
extern void func_802A58B0_de(ObjRecAt7528 *arg0, Shared_Particle *arg1, PackedMatrixWords *matrix);

void func_80282330_de(ParticleDrawList *list, struct Shared_ParticleView *view) {
    f32 bounds[6];
    Vec3 transformed;
    DrawParticle *node;
    s32 visible, updated;
    f32 zScale, xyScale, xScale, maximum, height, radius;
    f32 minX, maxX, minY, maxY, minZ, maxZ;
    f32 depth;
    ParticleView *camera;
    u32 special;
    if (list->head != 0) {
        gDPPipeSync(D_80110634++);
        gDPSetAlphaDither(D_80110634++, G_AD_NOISE);
        func_8026D914_de(0x80);
        gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
        gSPGeometryMode(D_80110634++, 0x60400, 0);
        node = list->head;
        if (node != 0) {
            do {
                visible = 0;
                updated = node->particle.flags & 0x100000;
                if (node->particle.inst.unk14 == 0) {
                    if (!(node->particle.flags & 0x400000) && node->particle.desc->renderModel == 0) {
                        zScale = node->particle.size.z;
                        xyScale = node->particle.size.y * zScale;
                        xScale = node->particle.size.x * zScale;
                        if (!(xScale <= xyScale)) xyScale = xScale;
                        maximum = zScale;
                        if (!(xyScale <= maximum)) maximum = xyScale;
                        height = maximum * D_800C4E54_de;
                        radius = height * D_800C4E58_de[0];
                        minX = node->particle.inst.pos.x - radius;
                        bounds[0] = minX;
                        maxX = node->particle.inst.pos.x + radius;
                        bounds[3] = maxX;
                        minY = node->particle.inst.pos.y - radius;
                        bounds[1] = minY;
                        maxY = node->particle.inst.pos.y + height;
                        bounds[4] = maxY;
                        minZ = node->particle.inst.pos.z - radius;
                        bounds[2] = minZ;
                        maxZ = node->particle.inst.pos.z + radius;
                        bounds[5] = maxZ;
                        if (minX < view->clipMax.x && view->clipMin.x < maxX &&
                            minZ < view->clipMax.z && view->clipMin.z < maxZ &&
                            minY < view->clipMax.y && view->clipMin.y < maxY &&
                            func_80296B74_de(view->clipMatrix, bounds)) {
                            visible = 1;
                        }
                    } else visible = 1;
                }
                if (visible) {
                    if (!updated) {
                        if (D_80140FF8 == 1) {
                            camera = D_80140FE8_de.object;
                            func_80272898_de(&camera->particleViewMatrix, &node->particle.inst.pos, &transformed);
                            depth = transformed.z;
                            if (depth < 0.0f) depth = -depth;
                        func_8027DD48_de(&node->particle, &node->particle.mtx[D_800D297C], camera, depth);
                        } else {
                            func_8027DD48_de(&node->particle, &node->particle.mtx[D_800D297C], 0, 0.0f);
                        }
                        node->particle.flags |= 0x100000;
                    }
                    if (node->particle.desc->renderModel != 0) func_8027EB2C_de(node, view);
                    else func_8027ED6C_de(&node->particle, view);
                    if (node->particle.desc->flags & 0x100000) {
                        /* This call site passes the particle and view; the published callee has one named parameter. */
                        func_8027E784_de(&node->particle);
                    }
                    if (node->particle.drawWhenHidden && !updated) {
                        special = node->particle.desc->flags & 0x10000;
                        goto special_draw;
                    }
                } else if (node->particle.drawWhenHidden && !updated) {
                    if (D_80140FF8 == 1) {
                        camera = D_80140FE8_de.object;
                        func_80272898_de(&camera->particleViewMatrix, &node->particle.inst.pos, &transformed);
                        depth = transformed.z;
                        if (depth < 0.0f) depth = -depth;
                        func_8027DD48_de(&node->particle, &node->particle.mtx[D_800D297C], camera, depth);
                    } else {
                        func_8027DD48_de(&node->particle, &node->particle.mtx[D_800D297C], 0, 0.0f);
                    }
                    node->particle.flags |= 0x100000;
                    updated = node->particle.desc->flags;
                        special = updated & 0x10000;
                special_draw:
                    if (!special) {
                        func_802A58B0_de(&D_801379C0, &node->particle, &node->particle.mtx[D_800D297C]);
                    }
                }
                node = node->next;
            } while (node != 0);
        }
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
        func_8026D914_de(0);
        gDPSetAlphaDither(D_80110634++, G_AD_NOTPATTERN);
    }
}
