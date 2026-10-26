#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/S1_2.H"
#include "COMMON/OBJB.H"
#include "MENU/8044ACCC.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/RESULTS.H"
#include "SYSTEM_2/8025E280.H"
#include "SYSTEM/80255C40_7.H"
#include "SCENE/802508E0_13.H"
#include "RENDER_4/8028FD2C_6.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Loads a scene's light into the global light D_800CBC90: copies the ambient and directional colours from the scene's light settings (bytes 0xD and 0xA) into both colour copies and the direction bytes from 0x11, then scales the direction to D_800CA1F0 in length through func_802B72B0_de and GraphU64_ScaleVector and stores it as shorts at 0x1B2B4 of the scene. */
extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern u8 D_800CBC9C[];
extern u8 D_800CBCA0[];
extern f32 Math_Sqrtf(f32);
extern void GraphU64_ScaleVector(f32 *, f32 *, f32);
void OvlScene_LoadSceneLight(SceneRecAt1B2B4 *scene) {
    s32 i;
    u8 c;
    f32 v[3];
    f32 length;
    u8 *light;
    for (i = 0; i < 3; i++) {
        c = scene->light->m_AmbientLight[i];
        light = D_800CBC90;
        light[i] = c;
        D_800CBC94[i] = c;
        c = scene->light->m_DirectionalLight[i];
        light[i + 8] = c;
        D_800CBC9C[i] = c;
        D_800CBCA0[i] = scene->light->m_Direction[i];
    }
    v[0] = scene->light->m_Direction[0];
    v[1] = scene->light->m_Direction[1];
    v[2] = scene->light->m_Direction[2];
    length = Math_Sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (length != 0.0f) {
        GraphU64_ScaleVector(v, v, g_lightDirectionLength / length);
        scene->dir[0] = v[0];
        scene->dir[1] = v[1];
        scene->dir[2] = v[2];
    }
}
int Weapons_GetFirstPlayer(void *);
void func_8025CBEC_de(void *);
s32 * func_8025CC6C_de(void);
void func_8028D59C_de(void *);
void Ovlgame_ReleaseObjectHandles(void *);
/* Shut down the subsystem, free its owned resources, and unlink its list. */
void OvlScene_FreeSceneResources(func_8044CBE0_S1 *arg0) {
    s32 temp_v0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s1;
    func_8020D0CC_S2 *var_a1;
    temp_v0 = Weapons_GetFirstPlayer(&D_80145040);
    if (temp_v0 != 0) {
        Ovlgame_ReleaseObjectHandles((void *) temp_v0);
    }
    func_8025CBEC_de(func_8025CC6C_de());
    func_8025E468_de();
    func_8025E1EC_de(0x1000);
    Cache_ReleaseResource(NULL, arg0->unk100);
    Cache_ReleaseResource(NULL, arg0->unkB8);
    Cache_ReleaseResource(NULL, arg0->unkBC);
    Cache_ReleaseResource(NULL, arg0->unkC0);
    Cache_ReleaseResource(NULL, arg0->unkC4);
    Cache_ReleaseResource(NULL, arg0->unkC8);
    Cache_ReleaseResource(NULL, arg0->unkD0);
    Cache_ReleaseResource(NULL, arg0->unkD4);
    Cache_ReleaseResource(NULL, arg0->unkEC);
    Cache_ReleaseResource(NULL, arg0->unkCC);
    Cache_ReleaseResource(NULL, arg0->unkE8);
    temp_a1 = arg0->unkF0;
    if (temp_a1 != NULL) {
        Cache_ReleaseResource(NULL, temp_a1);
    }
    temp_a1_2 = arg0->unkF4;
    if (temp_a1_2 != NULL) {
        Cache_ReleaseResource(NULL, temp_a1_2);
    }
    temp_a1_3 = arg0->unkFC;
    if (temp_a1_3 != NULL) {
        Cache_ReleaseResource(NULL, temp_a1_3);
    }
    func_8028D59C_de(arg0);
    temp_s1 = arg0->unk1B500.head;
    var_a1 = temp_s1;
    if (temp_s1 != NULL) {
        do {
            temp_s0 = var_a1->unk10;
            func_80255ED8_de(&arg0->unk1B500, var_a1);
            var_a1 = temp_s0;
        } while (var_a1 != NULL);
    }
    Cache_FreeMemory(temp_s1);
}
/* Binds a loaded collision mesh to the world: records the vertex, face and edge lists from the
   node's four chunks with their counts, resets the two bucket lists and files the 48 buckets into
   the second, then for every face of both lists clears the solid bit when it is hidden and marks it
   0xF0 when its group bit is set in the current group's bitmap. */
extern s32 PpDecom_UnpackResource(void ***handle, s32 arg1);
extern void func_8028FDF8_de(void *node, s32 arg1);
static inline s32 groupHas(WorldRecAt1B40C *world, s32 n) {
    s32 index;
    void *g;
    u8 *bits;
    s32 mask;
    index = world->group;
    g = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(world->tree, 0), index), 2);
    SetN64_GetPackSection(g, 0);
    func_8028FDF8_de(g, 1);
    bits = SetN64_GetPackSection(g, 1);
    mask = 1 << (n & 7);
    return bits[n / 8] & mask;
}
void func_8044C108_de(WorldRecAt1B40C *world, void ***handle) {
    void *node;
    struct IntPair *l0;
    struct IntPair *l1;
    struct IntPair *l2;
    struct IntPair *l3;
    s32 k;
    s32 i;
    s32 n;
    s32 count;
    Face *face;
    if (PpDecom_UnpackResource(handle, 0) != 0) {
        node = **handle;
        l0 = SetN64_GetPackSection(node, 0);
        l1 = SetN64_GetPackSection(node, 1);
        l2 = SetN64_GetPackSection(node, 2);
        l3 = SetN64_GetPackSection(node, 3);
        count = l0->field_4;
        world->verts = &((ResidentDataChunk *)(l0))->data[0];
        world->faces = (Face *)&((ResidentDataChunk *)(l1))->data[0];
        world->nfaces = count;
        count = l2->field_4;
        world->edgeData = &((ResidentDataChunk *)(l2))->data[0];
        world->edges = (Face *)&((ResidentDataChunk *)(l3))->data[0];
        world->nedges = count;
        func_80255CA0_de(&world->listA, 0, 4);
        func_80255CA0_de(&world->listB, 0, 4);
        for (k = 0; k < 0x30; k++) {
            func_80255D14_de(&world->listB, &world->buckets[k]);
        }
        n = world->nfaces;
        for (i = 0; i < n; i++) {
            face = &world->faces[i];
            if (face->hidden != 0) {
                face->flags &= 0xFE;
            }
            if (groupHas(world, face->group)) {
                face->flags |= 0xF0;
            }
        }
        n = world->nedges;
        for (i = 0; i < n; i++) {
            face = &world->edges[i];
            if (face->hidden != 0) {
                face->flags &= 0xFE;
            }
            if (groupHas(world, face->group)) {
                face->flags |= 0xF0;
            }
        }
    }
}
