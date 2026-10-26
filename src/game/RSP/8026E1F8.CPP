#include "include_asm.h"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT4V7.H"
#include "RSP/8026E1F8.H"
#include "TYPES.H"
#include "abi.h"
#include "gbi.h"
#include "RENDER_4/8028FD2C_6.H"

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

extern void **TextLoad_RequestTextureVariationSync(void *arg0, s32 arg1);





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

extern int g_geometryViewEffect;
void Geometry_SetViewEffect(int viewEffect) {
    g_geometryViewEffect = viewEffect;
}

/** Return the global word at g_geometryViewEffect. */
extern int g_geometryViewEffect;

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

extern unsigned char D_800CC3AC;
extern unsigned char D_800CC3AD;
void Geometry_SetPrimitiveAlphaOverride(int arg0, int arg1) {
    D_800CC3AC = (unsigned char)arg0;
    D_800CC3AD = (unsigned char)arg1;
}

extern Gfx *g_displayListCursor;
extern char D_E0470;
extern char D_DE0A0;
extern char D_800CBCC0;
extern char D_800CBCF0_de;

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

extern Gfx *g_displayListCursor;
extern char D_E0050;
extern char D_DCD10;
extern char D_800CBCC0;
extern char D_800CBCF0_de;

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

extern unsigned int D_8010C56C;
extern unsigned int D_8010C568;
extern unsigned int D_8010C584;
extern unsigned int D_8010C57C;

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
