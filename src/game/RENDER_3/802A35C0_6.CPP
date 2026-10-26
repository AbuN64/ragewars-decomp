#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/GAME_SESSION.H"
#include "RENDER_3/802A35C0.H"
#include "abi.h"
#include "RENDER_3/DRAW_MATRIX_SCRATCH.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/S1.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "SYSTEM/80296FF8_6.H"
#include "LISTS/80279520.H"
#include "SYSTEM/80255C40_7.H"

extern f32 D_80115DEC;

extern void GraphU64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern f32 Math_Sqrtf(f32);

extern void GraphU64_ScaleVector(CVector3 *out, CVector3 *in, f32 scale);

/* Draws the scene's ten particle lists unless the free list holds exactly 100 particles: sets the render state and the shared particle texture D_800D14B0 (a 16x16 texture drawn in grey at alpha 200 through D_800D2E60), then for every particle inside the view box ending at D_801031F8 + 4 loads its matrix and draws the shared quad g_particleQuadVertices, while particles outside it are unlinked (func_80255ED8_de) and returned to the free list (func_80255D14_de); finally restores the render state through Geometry_InvalidateMaterialKeys and TextLoad_ResetTextureCache. */











extern f32 D_801031F8;

extern char D_800D14B0;

extern char D_800D2E60;




extern char D_800CDCA8;

void func_802A5E08_de(void *);

s32 func_802A5EE0_de(s32);

extern s32 D_800CDBE8;


extern u32 D_800D297C;

extern void CopyMatrix(f32 *arg0, f32 *arg1);

extern void ScaleMatrixLocal(void *arg0, f32 sx, f32 sy, f32 sz);

extern void GraphU64_ClampMatrixToFixedRange(f32 *arg0);

extern void func_802A25D0_de(void *arg0, void *arg1, f32 *arg2);

extern void GraphU64_ConvertMatrixToFloat(f32 *, PackedMatrixWords *);

extern f32 D_800C5EA0_de;

CQuatern *func_802A5020_de(CQuatern *out, u32 bx, u32 by, u32 bz) {
    CVector3 axis;
    CVector3 cross;
    CQuatern result;
    f32 one;
    f32 magnitude;
    f32 angle;
    f32 trig;

    one = D_800C5E88_de;
    axis.x = 0.0f;
    axis.y = one;
    axis.z = 0.0f;
    GraphU64_CrossVectors(&cross, &axis, (CVector3 *)&bx);

    magnitude = Math_Sqrtf((cross.x * cross.x) +
                              (cross.y * cross.y) +
                              (cross.z * cross.z));
    if (magnitude == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        GraphU64_ScaleVector(&cross, &cross, one / magnitude);
        angle = GraphU64_ArcCos((axis.x * *(f32 *)&bx) +
                              (axis.y * *(f32 *)&by) +
                              (axis.z * *(f32 *)&bz));
        angle *= ((struct func_802077F4_S2 *) ((f32 *) (&D_800C5E88_de)))->unk4;
        trig = Math_Sinf(angle);
        result.x = cross.x * trig;
        result.y = cross.y * trig;
        result.z = cross.z * trig;
        D_80115DEC = trig;
        result.w = Math_Cosf(angle);
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
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)&D_800D14B0);
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPLoadSync(g_displayListCursor++);
    gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, 127, 1024);
    gDPPipeSync(g_displayListCursor++);
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, 60, 60);
    gDPSetPrimColor(g_displayListCursor++, 0, 0, 255, 255, 255, 200);
    gSPDisplayList(g_displayListCursor++, (u32)&D_800D2E60);
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
                gSPMatrix(g_displayListCursor++, (u32)transform, G_MTX_LOAD);
                gSPVertex(g_displayListCursor++, (u32)&g_particleQuadVertices, 4, 0);
                gSP2Triangles(g_displayListCursor++, 0, 1, 2, 0, 2, 3, 0, 0);
            }
            particle = next;
        }
    }
    Geometry_InvalidateMaterialKeys();
    TextLoad_ResetTextureCache();
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

    cmd = g_displayListCursor++;
    gDPPipeSync(cmd);
    cmd = g_displayListCursor++;
    gDPSetCycleType(cmd, G_CYC_2CYCLE);
    cmd = g_displayListCursor++;
    gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_800D14B0);
    cmd = g_displayListCursor++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = g_displayListCursor++;
    gDPLoadSync(cmd);
    cmd = g_displayListCursor++;
    gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 127, 1024);
    cmd = g_displayListCursor++;
    gDPPipeSync(cmd);
    cmd = g_displayListCursor++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = g_displayListCursor++;
    gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 60, 60);
    cmd = g_displayListCursor++;
    gDPSetPrimColor(cmd, 255, 255, 200, 0, 0, 150);
    cmd = g_displayListCursor++;
    gSPDisplayList(cmd, &D_800CDCA8);
    cmd = g_displayListCursor++;
    gSPMatrix(cmd, arg0, G_MTX_LOAD);
    cmd = g_displayListCursor++;
    gSPVertex(cmd, &g_particleQuadVertices, 4, 0);
    cmd = g_displayListCursor++;
    gSP2Triangles(cmd, 0, 1, 2, 0, 2, 3, 0, 0);

    Geometry_InvalidateMaterialKeys();
    TextLoad_ResetTextureCache();
}

void func_802A5680_de(s32 owner) {
    D_800CDBE8 = 0;
    if (D_8011FAC0.clockPaused == 0) {
        func_802A5E08_de((void *)owner);
        func_802A5EE0_de(owner);
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
    s32 actors;
    actors = (((struct IntegerState6A94 *) ((s8 *) arg0))->unk_6A90);
    if (actors != 0) {
        Lists_Remove(arg0 + 0x6A90, (ListLink *)actors);
        Lists_Append(arg1 + 0x40, actors);
    }
    return actors;
}

void func_802A5780_de(s32 arg0, void *arg1, void *actors) {
    (((struct FloatState50 *) ((s8 *) arg1))->unk_4C) = (f32) ((((struct FloatState50 *) ((s8 *) arg1))->unk_4C) - (((struct FloatStateB0 *) ((s8 *) actors))->unk_AC));
    Lists_Remove(arg1 + 0x40, actors);
    Lists_Append(arg0 + 0x6A90, actors);
}

void func_802A57D8_de(void) {
}

void func_802A57E0_de(Owner802A6DF8 *arg0, s32 actor, char *arg2) {
    f32 sp10[16];
    f32 temp;
    f32 zero;
    State802A6DF8 *node;

    node = arg0->lists.inactive.head;
    if (node != 0) {
        zero = 0.0f;
        temp = D_800C5E94_de;
        do {
            if ((s32)node->object == actor && node->value > zero) {
                CopyMatrix(sp10, (f32 *)(arg2 + (node->node->matrixIndex << 6)));
                ScaleMatrixLocal(sp10, temp, temp, temp);
                GraphU64_ClampMatrixToFixedRange(sp10);
                func_802A25D0_de(arg0, node, sp10);
            }
            node = node->next;
        } while (node != 0);
    }
}

void func_802A58B0_de(ObjRecAt7528 *arg0, Shared_Particle *particle, PackedMatrixWords *packedMatrixWords) {
    f32 local[16];
    f32 scale;
    f32 zero;
    func_802A68A0_S2 *node;

    node = arg0->unk7528;
    if (node != 0) {
        zero = 0.0f;
        do {
            if (node->unk1C == particle &&
                node->unk24 > zero &&
                node->unk24 > zero) {
                GraphU64_ConvertMatrixToFloat(local, packedMatrixWords);
                scale = D_800C5E98_de;
                if (particle->desc->renderModel != 0) {
                    scale = D_800C5E9C_de;
                }
                ScaleMatrixLocal(local, scale, scale, scale);
                GraphU64_ClampMatrixToFixedRange(local);
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

void func_802A5A24_de(EffectContribution *arg0, s32 arg1)
{
  arg0->scale = (f32) D_800C5EA0_de;
  arg0->id = arg1;
  arg0->state = 0;
  arg0->stateC = 0;
  arg0->state10 = 0;
  arg0->weight = 0;
  arg0->x = 0;
  arg0->y = 0;
  arg0->z = 0;
}
