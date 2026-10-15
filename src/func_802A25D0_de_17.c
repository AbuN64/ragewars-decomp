#include "span_1000/code_802A25C4.h"
#include "abi.h"
#include "common/draw_matrix_scratch.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "gbi.h"
#include "n64sdk.h"
#include "span_1000/code_80255BEC.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027A0F4.h"
#include "span_1000/code_80296014.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"
#include "span_1000/code_80291054.h"

extern f32 D_80115DEC;

extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);

extern f32 func_802B72B0_de(f32);

extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);

/* Draws the scene's ten particle lists unless the free list holds exactly 100 particles: sets the render state and the shared particle texture D_800D14B0 (a 16x16 texture drawn in grey at alpha 200 through D_800D2E60), then for every particle inside the view box ending at D_801031F8 + 4 loads its matrix and draws the shared quad D_801469A0, while particles outside it are unlinked (func_80255ED8_de) and returned to the free list (func_80255D14_de); finally restores the render state through func_8026D8F8_de and func_80295FF4_de. */











extern f32 D_801031F8;

extern char D_800D14B0;

extern char D_800D2E60;

extern char D_801469A0;

extern void func_80255ED8_de(void *list, Particle *particle);

extern char D_800CDCA8;

s32 func_802A5E08_de();

s32 func_802A5EE0_de(s32);

extern s32 D_800CDBE8;

extern s32 D_80146894;

extern u32 D_800D297C;

extern void func_8027302C(f32 *arg0, f32 *arg1);

extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

extern void func_80272828_de(f32 *arg0);

extern void func_802A25D0_de(void *arg0, void *arg1, f32 *arg2);

extern void func_80270910_de(f32 *, PackedMatrixWords *);

extern f32 D_800C5EA0_de;

Vector4f *func_802A5020_de(Vector4f *out, u32 bx, u32 by, u32 bz) {
    Vec3 axis;
    Vec3 cross;
    Vector4f result;
    f32 one;
    f32 magnitude;
    f32 angle;
    f32 trig;

    one = D_800C5E88_de;
    axis.x = 0.0f;
    axis.y = one;
    axis.z = 0.0f;
    func_80272018_de(&cross, &axis, (Vec3 *)&bx);

    magnitude = func_802B72B0_de((cross.x * cross.x) +
                              (cross.y * cross.y) +
                              (cross.z * cross.z));
    if (magnitude == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        func_80271F9C_de(&cross, &cross, one / magnitude);
        angle = func_802745D0_de((axis.x * *(f32 *)&bx) +
                              (axis.y * *(f32 *)&by) +
                              (axis.z * *(f32 *)&bz));
        angle *= ((struct func_802077F4_S2 *) ((f32 *) (&D_800C5E88_de)))->unk4;
        trig = func_802B7130_de(angle);
        result.x = cross.x * trig;
        result.y = cross.y * trig;
        result.z = cross.z * trig;
        D_80115DEC = trig;
        result.w = func_802B6560_de(angle);
    }
    *out = result;
    return out;
}

void func_802A5180_de(SceneRecAt95A8 *scene) {
    Particle *particle;
    Particle *next;
    f32 *max;
    IntrusiveList *list;
    f32 pos[3];
    s32 i;

    if (scene->free.count == 100) {
        return;
    }
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)&D_800D14B0);
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPLoadSync(D_80110634++);
    gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, 127, 1024);
    gDPPipeSync(D_80110634++);
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, 60, 60);
    gDPSetPrimColor(D_80110634++, 0, 0, 255, 255, 255, 200);
    gSPDisplayList(D_80110634++, (u32)&D_800D2E60);
    for (i = 0; i < 10; i++) {
        max = (&D_801031F8 + 1);
        list = &scene->lists[i];
        particle = list->head;
        while (particle != 0) {
            Transform *transform = &particle->transform;

            next = particle->next;
            pos[0] = transform->position[0];
            pos[1] = transform->position[1];
            pos[2] = transform->position[2];
            if (!(pos[0] < max[0] && pos[1] < max[1] && pos[2] < max[2] && max[-3] <= pos[0] &&
                  max[-2] <= pos[1] && max[-1] <= pos[2])) {
                func_80255ED8_de(list, particle);
                func_80255D14_de(&scene->free, particle);
            } else {
                gSPMatrix(D_80110634++, (u32)transform, G_MTX_LOAD);
                gSPVertex(D_80110634++, (u32)&D_801469A0, 4, 0);
                gSP2Triangles(D_80110634++, 0, 1, 2, 0, 2, 3, 0, 0);
            }
            particle = next;
        }
    }
    func_8026D8F8_de();
    func_80295FF4_de();
}

void func_802A5498_de(u32 arg0) {
    DrawMatrixScratch local;
    Gfx *cmd;

    local.matrix[0] = 0.0f;
    local.matrix[1] = 0.0f;
    local.matrix[2] = 0.0f;
    local.matrix[4] = 0.0f;
    local.matrix[6] = 0.0f;
    local.matrix[5] = D_800C5E90_de;

    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetCycleType(cmd, G_CYC_2CYCLE);
    cmd = D_80110634++;
    gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_800D14B0);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = D_80110634++;
    gDPLoadSync(cmd);
    cmd = D_80110634++;
    gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 127, 1024);
    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = D_80110634++;
    gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 60, 60);
    cmd = D_80110634++;
    gDPSetPrimColor(cmd, 255, 255, 200, 0, 0, 150);
    cmd = D_80110634++;
    gSPDisplayList(cmd, &D_800CDCA8);
    cmd = D_80110634++;
    gSPMatrix(cmd, arg0, G_MTX_LOAD);
    cmd = D_80110634++;
    gSPVertex(cmd, &D_801469A0, 4, 0);
    cmd = D_80110634++;
    gSP2Triangles(cmd, 0, 1, 2, 0, 2, 3, 0, 0);

    func_8026D8F8_de();
    func_80295FF4_de();
}

void func_802A5680_de(s32 arg0) {
    D_800CDBE8 = 0;
    if (D_80146894 == 0) {
        func_802A5E08_de();
        func_802A5EE0_de(arg0);
    }
}

s32 func_802A56C4_de(void *arg0, s32 arg1)
{
    struct RibbonVertexPool *pool = arg0;
    s32 avail;
    s32 head;

    avail = pool->remaining;
    if (avail < arg1) {
        return 0;
    }
    head = (s32)pool->next;
    pool->remaining = avail - arg1;
    pool->next += arg1;
    return head;
}

/** Reset the object and compute its trailing-data end pointer. */
void func_802A56FC_de(void *object) {
    struct RibbonVertexPool *pool = object;
    u32 index = D_800D297C;
    pool->state = 0;
    pool->remaining = 0x12C;
    pool->next = pool->vertices[index];
}

s32 func_802A5734_de(void *arg0, s32 arg1) {
    s32 func_80279550_de(void *, s32);
    s32 func_80279508_de(s32, s32);
    s32 temp_s0;
    temp_s0 = (((struct IntegerState6A94 *) ((s8 *) arg0))->unk_6A90);
    if (temp_s0 != 0) {
        func_80279550_de(arg0 + 0x6A90, temp_s0);
        func_80279508_de(arg1 + 0x40, temp_s0);
    }
    return temp_s0;
}

void func_802A5780_de(s32 arg0, void *arg1, void *arg2) {
    s32 func_80279550_de(void *, void *);
    s32 func_80279508_de(s32, void *);
    (((struct FloatState50 *) ((s8 *) arg1))->unk_4C) = (f32) ((((struct FloatState50 *) ((s8 *) arg1))->unk_4C) - (((struct FloatStateB0 *) ((s8 *) arg2))->unk_AC));
    func_80279550_de(arg1 + 0x40, arg2);
    func_80279508_de(arg0 + 0x6A90, arg2);
}

void func_802A57D8_de(void) {
}

void func_802A57E0_de(void *arg0, s32 arg1, char *arg2) {
    f32 sp10[16];
    f32 temp;
    f32 zero;
    State802A6DF8 *node;

    node = ((Owner802A6DF8 *)arg0)->lists.inactive.head;
    if (node != 0) {
        zero = 0.0f;
        temp = D_800C5E94_de;
        do {
            if ((s32)node->object == arg1 && node->value > zero) {
                func_8027302C(sp10, (f32 *)(arg2 + (node->node->matrixIndex << 6)));
                func_8027347C_de(sp10, temp, temp, temp);
                func_80272828_de(sp10);
                func_802A25D0_de(arg0, node, sp10);
            }
            node = node->next;
        } while (node != 0);
    }
}

void func_802A58B0_de(ObjRecAt7528 *arg0, Shared_Particle *arg1, PackedMatrixWords *arg2) {
    f32 local[16];
    f32 scale;
    f32 zero;
    func_802A68A0_S2 *node;

    node = arg0->unk7528;
    if (node != 0) {
        zero = 0.0f;
        do {
            if (node->unk1C == arg1 &&
                node->unk24 > zero &&
                node->unk24 > zero) {
                func_80270910_de(local, arg2);
                scale = D_800C5E98_de;
                if (arg1->desc->renderModel != 0) {
                    scale = D_800C5E9C_de;
                }
                func_8027347C_de(local, scale, scale, scale);
                func_80272828_de(local);
                func_802A25D0_de(arg0, node, local);
            }
            node = node->unk4;
        } while (node != 0);
    }
}

void func_802A598C_de(Owner802A697C *owner, int object) {
    float temp_f1;
    u8 temp_v0;
    u8 temp_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    void *var_v1;

    var_v1 = owner->head;
    if (var_v1 != 0) {
        do {
            temp_a0 = ((struct State802A697C *)var_v1)->object;
            if ((int)temp_a0 == object) {
                if (temp_a0 != 0) {
                    if (((struct State802A697C *)var_v1)->flags & 1) {
                        temp_v0 = ((Entity1DC *)temp_a0)->unk_13B;
                        if (temp_v0 != 0) {
                            ((Entity1DC *)temp_a0)->unk_13B = (u8)(temp_v0 - 1);
                        }
                    }
                    if (((struct State802A697C *)var_v1)->flags & 2) {
                        temp_a0_2 = ((struct State802A697C *)var_v1)->object;
                        temp_v0_2 = ((Entity1DC *)temp_a0_2)->unk_1D9;
                        if (temp_v0_2 != 0) {
                            ((Entity1DC *)temp_a0_2)->unk_1D9 = (u8)(temp_v0_2 - 1);
                        }
                    }
                }
                ((struct State802A697C *)var_v1)->object = 0;
                temp_f1 = ((struct State802A697C *)var_v1)->node->value;
                if (((struct State802A697C *)var_v1)->value < temp_f1) {
                    ((struct State802A697C *)var_v1)->value = temp_f1;
                }
            }
            var_v1 = ((struct State802A697C *)var_v1)->next;
        } while (var_v1 != 0);
    }
}

void func_802A5A24_de(void *arg0, s32 arg1)
{
  ((EffectContribution *)arg0)->scale = (f32) D_800C5EA0_de;
  ((EffectContribution *)arg0)->id = arg1;
  ((EffectContribution *)arg0)->state = 0;
  ((EffectContribution *)arg0)->stateC = 0;
  ((EffectContribution *)arg0)->state10 = 0;
  ((EffectContribution *)arg0)->weight = 0;
  ((EffectContribution *)arg0)->x = 0;
  ((EffectContribution *)arg0)->y = 0;
  ((EffectContribution *)arg0)->z = 0;
}
