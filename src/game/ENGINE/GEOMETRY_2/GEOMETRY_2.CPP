#include "COMMON/MODEL_RENDER.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/OBJECTSTATE18.H"
#include "RENDER_4/8026AC38.H"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8026AC38_5.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/DISPLAY.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/LONE/D_800CC384.H"
#include "COMMON/UNUSED.H"
#include "abi.h"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT4V7.H"
#include "RENDER_4/8026AC38_2.H"
#include "RENDER_4/8026AC38_3.H"
#include "SCENE/802508E0_9.H"
#include "include_asm.h"
#include "COMMON/GFX.H"
#include "RSP/8026E1F8.H"

/* 8026AC38_5.CPP */
/* Draws the parts of a model resource tinted by an RGBA colour through the shared material D_8013B2D8: sets the tint mode D_800D15E0 to 3, clears the material's fog colour and sets its flags, records the colour as floats and its alpha on the material, advances the pass modulo 18, and when the frame's command buffer still has 3000 commands free and Geometry_SetupMaterial accepts the material sets the render mode, selects blend 1, registers the resource, loads the matrix (or sets it as segment 1), sets segment 2 to the given texture base or the model's own, sets the lighting on the first part and emits each part whose material blend bits are all set and accepted for the pass, clearing the tint mode afterwards. Adapted from Geometry_DrawBlendParts with the tint setup, the render mode and blend commands and the trailing clear added. */

extern Gfx *g_displayListCursor;
#if defined(VERSION_DE)
extern u32 D_800DE854;
#elif defined(VERSION_EU)
extern u32 D_800EEEC4;
#elif defined(VERSION_EU_X)
extern u32 D_800EA084;
#elif defined(VERSION_US)
extern u32 D_800DD504;
#elif defined(VERSION_US_REV1)
extern u32 D_800E28A4;
#endif
extern ObjectState18 D_8013B2D8;

extern s32 Geometry_ApplyMaterialLighting(void *matrix, void *lights, void *material);
extern s32 Geometry_SetupMaterial(void *material, s32 pass);
extern void Geometry_SetCombineMode(s32 mode);

void func_8026D4F0_de(void **resource, void *unused, void *matrix, s32 segment, void *lights, void *textures, s32 pass, u8 r, u8 g, u8 b, u8 a) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    ObjectState18 *shared;
    f32 *tint;

    shared = &D_8013B2D8;
    D_800D15E0 = 3;
    shared->fog[0] = 0;
    shared->fog[1] = 0;
    shared->fog[2] = 0;
    shared->flags |= 0x1402;
    tint = D_800D15E4;
    tint[0] = r;
    tint[1] = g;
    tint[2] = b;
    tint[3] = a;
    shared->fog[3] = a;
    pass = (pass + 1) % 18;
#if defined(VERSION_DE)
    if (D_800DE854 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU)
    if (D_800EEEC4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU_X)
    if (D_800EA084 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US)
    if (D_800DD504 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US_REV1)
    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#endif
        return;
    }
    if (Geometry_SetupMaterial(shared, pass) != 0) {
        gDPSetRenderMode(g_displayListCursor++, 0x0C184DD8, 0);
        Geometry_SetCombineMode(1);
        header = *resource;
        Cache_MarkResourceInUse(0, resource);
        if (segment != 0) gSPSegment(g_displayListCursor++, 1, matrix) else gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD);
        base = textures;
        if (base == 0) {
            base = SetN64_GetPackSection(header, 0);
        }
        gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
        parts = SetN64_GetPackSection(header, 2);
        count = *(s32 *)parts;
        for (i = 0; i < count; i++) {
            part = SetN64_GetPackSection(parts, i);
            material = SetN64_GetPackSection(part, 0);
            if (i == 0) {
                Geometry_ApplyMaterialLighting(matrix, lights, material);
            }
            if ((((unsigned char *)material)[6] & 0x38) == 0x38 && Geometry_SetupMaterial(material, pass) != 0) {
                Gfx *cmd;
                void *list = SetN64_GetPackSection(part, 1);

                cmd = g_displayListCursor++;
                gSPDisplayList(cmd, (unsigned int)list);
            }
        }
    }
    D_800D15E0 = 0;
}

extern void Geometry_ExpandModelCommands(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void Geometry_ExpandBasicModel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 0, 0);
}

void Geometry_ExpandModelWithSentinel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 0, 1);
}

void Geometry_ExpandExtendedModel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 1, 0);
}

void func_8026D834_de(void) {
}
/* An empty function. */
void Geometry_NoOperation(void) {
}

/* CODE_8026D844.CPP */
extern void GraphU64_BuildScaleMatrix(void *, float, float, float);

extern void GraphU64_PackFixedMatrix(void *, void *);

extern s32 D_8010C568;

extern s32 D_8010C56C;

extern s32 D_8010C57C;

extern s32 D_8010C584;

extern s32 D_8011064C;

extern ObjRecAtCV2 D_801157D8[];

extern void Cache_LockResource(s32, s32);

extern void Geometry_QueueModelById(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void Geometry_SetModePreset(s32 mode);

extern void **TextLoad_RequestTextureVariationSync(void *arg0, s32 arg1);

void Geometry_InitializeModelRenderState(void) {
    char local[64];

    Geometry_InvalidateMaterialKeys();
    GraphU64_BuildScaleMatrix(local, D_800C46AC_de, D_800C46AC_de, D_800C46AC_de);
    GraphU64_PackFixedMatrix(local, &D_8010C520);
}

void Geometry_SelectEffectModes(void) {
    if (D_800CC380 != 0 || g_geometryViewEffect != 0) {
        D_800CC384 = 0x10000;
        D_800CC388 = 0xC4000000;
        D_800CC38C = 0xC8000000;
        return;
    }
    D_800CC384 = 0;
    D_800CC388 = 0x0C080000;
    D_800CC38C = 0x0C080000;
}

/** Reset two global indices to minus one. */
void Geometry_InvalidateMaterialKeys(void) {
    D_800CC364 = -1;
    D_800CC360 = -1;
}

void Geometry_SetColorDither(s32 ditherMode) {
    if (g_geometryViewEffect == 0) gDPSetColorDither(g_displayListCursor++, ditherMode) else gDPSetColorDither(g_displayListCursor++, G_CD_NOISE);
}

void Geometry_BeginModelBatch(void) {
    D_8011064C = 0;
    D_80110640 = 0;
    D_8010C578 = 0;
    D_8010C570 = 0;
    D_80111310 = 0;
    D_8010C56C = 0;
    D_8010C568 = 0;
    D_8010C584 = 0;
    D_8010C57C = 0;
}

void Geometry_FlushModelBatch(void) {
    s32 resourceHandle;
    s32 i;

    Geometry_GroupModelInstances();
    i = 0;
    Geometry_DrawMaterialGroups();
    if (D_80111310 > 0) {
        do {
            resourceHandle = D_80111318[i];
            Cache_MarkResourceInUse(0, resourceHandle);
            Cache_UnlockResource(0, resourceHandle);
            i += 1;
        } while (i < D_80111310);
    }
}

void Geometry_DrawModelResource(void **resource, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    Cache_MarkResourceInUse(0, resource);
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        if (Geometry_SetupMaterial(material, pass) != 0) {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void Geometry_QueueModelInstance(void **a, void *b, s32 c, void *d, void *e, s32 f) {
    s32 instanceCount;
    void *vertexBase;
    ObjRecAtCV2 *queuedInstance;
    void *modelHeader;
    s32 *countp;
    s32 count;
    s32 *queue_countp;

    modelHeader = *a;
    vertexBase = e;
    if (vertexBase == 0) {
        vertexBase = SetN64_GetPackSection(modelHeader, 0);
    }
    if ((D_8011064C != (s32)a) || (D_8010C564 != f) || (D_80110640 == 0x20)) {
        Geometry_GroupModelInstances();
        if (D_80111310 != 0x100) {
            Cache_LockResource(0, (s32)a);
            countp = &D_80111310;
            count = *countp;
            D_80111318[count] = (s32)a;
            *countp = count + 1;
            goto block_7;
        }
    } else {
block_7:
        D_8011064C = (s32)a;
        D_8010C564 = f;
        queue_countp = &D_80110640;
        instanceCount = *queue_countp;
        queuedInstance = &D_801157D8[instanceCount];
        instanceCount += 1;
        *queue_countp = instanceCount;
        queuedInstance->unk0 = b;
        queuedInstance->unkC = c;
        queuedInstance->unk4 = d;
        queuedInstance->unk8 = vertexBase;
    }
}

void Geometry_DrawBlendParts(void **resource, s32 unused, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    Cache_MarkResourceInUse(0, resource);
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        if ((((unsigned char *)material)[6] & 0x38) == 0x38 && Geometry_SetupMaterial(material, pass) != 0) {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void Geometry_QueueDirectModel(s32 model, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    Geometry_QueueModelById(model, arg1, arg2, arg3, arg4, 1);
}

void Geometry_QueueDeferredModel(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    Geometry_QueueModelById(arg0, arg1, arg2, arg3, arg4, 0);
}

void Geometry_DrawWithMaterialOverride(void *shared, s32 mode, void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (Geometry_SetupMaterial(shared, pass) == 0) {
        return;
    }
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    if (mode != -1) {
        Geometry_SetModePreset(mode);
    }
    Cache_MarkResourceInUse(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void Geometry_UnlockMaterialResources(void **arg0) {
    void *temp_v0;
    s32 count;
    s32 i;
    void *rec;
    s32 result;

    temp_v0 = SetN64_GetPackSection(*arg0, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = SetN64_GetPackSection(SetN64_GetPackSection(temp_v0, i), 0);
        if (((ResourceSectionReference *)rec)->resource == 0) {
            continue;
        }
        result = TextLoad_RequestTextureVariationSync(&((ResourceSectionReference *)rec)->resource, -1);
        if (result == 0) {
            continue;
        }
        Cache_UnlockResource(0, result);
    }
}

/* 8026AC38_6.CPP */


/* 8026E1F8.CPP */
extern void func_80253F8C_de(s32 arg0, s32 arg1);

void Geometry_RefreshMaterialResources(void **resource) {
    void *temp_v0;
    s32 count;
    s32 i;
    void *rec;

    temp_v0 = SetN64_GetPackSection(*resource, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = SetN64_GetPackSection(SetN64_GetPackSection(temp_v0, i), 0);
        if (((struct ResourceSectionReference *)(rec))->resource == 0) {
            continue;
        }
        func_80253F8C_de(0, ((struct ResourceSectionReference *)(rec))->resource);
    }
}

s32 *Geometry_CollectMaterialResources(void **arg0, s32 variation, s32 *arg2) {
    void *temp_v0;
    s32 count;
    s32 i;
    s32 *out;
    void *rec;
    s32 result;

    out = arg2;
    temp_v0 = SetN64_GetPackSection(*arg0, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = SetN64_GetPackSection(SetN64_GetPackSection(temp_v0, i), 0);
        if (((struct ResourceSectionReference *)(rec))->resource == 0) {
            continue;
        }
        result = TextLoad_RequestTextureVariationSync(&((struct ResourceSectionReference *)(rec))->resource, variation);
        if (result != 0) {
            *out = result;
            out += 1;
        }
    }
    return out;
}

void Geometry_SetViewEffect(int viewEffect) {
    g_geometryViewEffect = viewEffect;
}

/** Return the global word at g_geometryViewEffect. */

int Geometry_GetViewEffect(void) {
    return g_geometryViewEffect;
}

/** Store four bytes in the global color-like value. */

void Geometry_SetPrimitiveColorOverride(unsigned char first, unsigned char second,
                   unsigned char third, unsigned char fourth) {
    D_800CC3A8 = first;
    D_800CC3A9 = second;
    D_800CC3AA = fourth;
    D_800CC3AB = third;
}

void Geometry_SetPrimitiveAlphaOverride(int arg0, int arg1) {
    D_800CC3AC = (unsigned char)arg0;
    D_800CC3AD = (unsigned char)arg1;
}

void Geometry_LoadRenderMicrocode(void) {
    Gfx *cmd;

    cmd = g_displayListCursor++;
    gDPFullSync(cmd);
    cmd = g_displayListCursor++;
    gDPHalf1(cmd, (u32) &D_E0470);
    cmd = g_displayListCursor++;
    gLoadUcode(cmd, &D_DE0A0, 0x800);
    cmd = g_displayListCursor++;
    gSPDisplayList(cmd, (u32) &D_800CBCC0);
    cmd = g_displayListCursor++;
    gSPDisplayList(cmd, (u32) &D_800CBCF0_de);
}

void Geometry_SwitchRenderMicrocode(void) {
    Gfx *cmd;

    cmd = g_displayListCursor++;
    gDPFullSync(cmd);
    cmd = g_displayListCursor++;
    gDPHalf1(cmd, (u32) &D_E0050);
    cmd = g_displayListCursor++;
    gLoadUcode(cmd, &D_DCD10, 0x800);
    cmd = g_displayListCursor++;
    gSPDisplayList(cmd, (u32) &D_800CBCC0);
    cmd = g_displayListCursor++;
    gSPDisplayList(cmd, (u32) &D_800CBCF0_de);
}

/** Initialize the two-word state to minus one and zero. */
void Geometry_ResetDisplayListState(int *state) {
    state[0] = -1;
    state[1] = 0;
}






/** Clear four related global state words. */
void Geometry_ClearMaterialGroups(void) {
    D_8010C56C = 0;
    D_8010C568 = 0;
    D_8010C584 = 0;
    D_8010C57C = 0;
}

void *Geometry_FindMaterialNodeOrParent(Node8026E4F8 **arg0, u32 arg1)
{
  u32 temp_v1;
  Node8026E4F8 *var_a0;
  Node8026E4F8 *var_v0;
  var_v0 = *arg0;
  var_a0 = 0;
  if (var_v0 != 0)
  {
    loop_1:
    temp_v1 = var_v0->key;

    if (var_v0->key)
    {
      var_a0 = var_v0;
    }
    else
    {
      var_a0 = var_v0;
    }
    if (temp_v1 != arg1)
    {
      if (arg1 < temp_v1)
      {
        var_v0 = var_a0->left;
      }
      else
      {
        var_v0 = var_a0->right;
      }
      if (var_v0 == 0)
      {
        goto block_6;
      }
      goto loop_1;
    }
  }
  else
  {
    block_6:
    var_v0 = var_a0;

  }
  return var_v0;
}

/** Insert a node adjacent to the supplied node in an intrusive ordered tree. */
void Geometry_InsertMaterialNode(TreeNode **root, TreeNode **empty_root, TreeNode *node, TreeNode *current) {
    if (current != 0) {
        if (node->key < current->key) {
            current->link18 = node;
            node->link1c = 0;
            node->link18 = 0;
            node->link14 = current;
            node->link10 = current->link10;
            if (current->link10 != 0)
                current->link10->link14 = node;
            current->link10 = node;
            if (*root == current)
                *root = node;
        } else {
            current->link1c = node;
            node->link1c = 0;
            node->link18 = 0;
            node->link14 = current->link14;
            if (current->link14 != 0)
                current->link14->link10 = node;
            node->link10 = current;
            current->link14 = node;
        }
    } else {
        *empty_root = node;
        *root = node;
        node->link1c = 0;
        node->link18 = 0;
        node->link14 = 0;
        node->link10 = 0;
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8026E55C[1] = {
    0x41594552,
};
#endif

/* 800C979C.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8026D844_CA39C[1] = {
    0x40000000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_func_8026E5E0_de_800C46B0[3] = {
    0x41700000, 0x40A00000, 0x43800000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C46BC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8026D844_CA39C_us_rev1.c */
const unsigned int D_blob_f1a5eff7b48ee6b5ab6b[1] = {
    0x40000000,
};
#endif
