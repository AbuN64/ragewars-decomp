#include "include_asm.h"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/OBJECTSTATE18.H"
#include "abi.h"
#include "COMMON/UNUSED.H"
#include "RENDER_4/8026AC38.H"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8026AC38_2.H"
#include "RENDER_4/8026AC38_3.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

extern Group18 *D_8010C56C,*D_8010C584;

extern Gfx *g_displayListCursor;

extern s32 Render_SetupMaterial(Material18 *,s8);

extern void Render_ApplyMaterialLighting(u32,u32,Material18 *),func_8026AC38_de(void);

void Scene_LockResource(void *, void *);

void Scene_UnlockResource(void *, void *);

void **func_802540F4_de(s32, void **, s32, void *, s32);

void func_8026BC60_de(void);


int Render_GetDirectoryEntry(int *, int, int);

s32 Render_LocatePackSection(s32, s32, s32, s32 *);


 /* extern */

extern s32 **D_8011064C;

extern ObjRecAtCV2 D_801157D8[];

extern s32 D_800C466C_de;

                          /* unable to generate initializer: unknown type */
extern s32 D_800C4680_de;

                          /* unable to generate initializer: unknown type */
extern s32 D_800C4694_de;

void func_8026C020_de(void) {
 Group18 *group=D_8010C56C,*deferred=0;
 Mesh *mesh;u16 scaleS,scaleT;u32 cmd;
 if(group)do {
  mesh=group->meshes;
  if(mesh && Render_SetupMaterial(group->material,group->mode)) {
   scaleT=0;scaleS=0;
   do {
    Render_ApplyMaterialLighting(mesh->matrix,mesh->aux,group->material);
    if(mesh->segmented){gSPSegment(g_displayListCursor++, 1, ((mesh->matrix)));}else{gSPMatrix(g_displayListCursor++, ((mesh->matrix)), G_MTX_LOAD);}
    gSPSegment(g_displayListCursor++, 2, ((mesh->vertices)));
    if(mesh->scaleS) {
     if(scaleS!=mesh->scaleS || scaleT!=mesh->scaleT) {
      if(group->material->flags&0x2000){gSPTexture(g_displayListCursor++, mesh->scaleS, mesh->scaleT, 5, 0, 1);}else{gSPTexture(g_displayListCursor++, mesh->scaleS, mesh->scaleT, 0, 0, 1);}
     }
     scaleS=mesh->scaleS;scaleT=mesh->scaleT;
    }
    gSPDisplayList(g_displayListCursor++, ((mesh->list)));
    mesh=mesh->next;
   }while(mesh);
   if(group->material->flags&0x2000) {gDPSetTextureLOD(g_displayListCursor++, G_TL_TILE);}
   if(group->material->flags&0x4000) {
    Group18 *next=group->next;group->next=deferred;deferred=group;group=next;
   } else group=group->next;
  } else group=group->next;
 }while(group);
 if(deferred) {
  group=deferred;func_8026AC38_de();
  do {
   mesh=group->meshes;
   if(mesh) {
    gDPSetPrimColor(g_displayListCursor++, 0, 0, 0, 0, 0, group->material->alpha);
    do {
     Render_ApplyMaterialLighting(mesh->matrix,mesh->aux,group->material);
     if(mesh->segmented){gSPSegment(g_displayListCursor++, 1, ((mesh->matrix)));}else{gSPMatrix(g_displayListCursor++, ((mesh->matrix)), G_MTX_LOAD);}
     gSPSegment(g_displayListCursor++, 2, ((mesh->vertices)));
     gSPDisplayList(g_displayListCursor++, ((mesh->list)));
     mesh=mesh->next;
    }while(mesh);
   }
   group=group->next;
  }while(group);
 }
 group=D_8010C584;
 if(group)do {
  mesh=group->meshes;
  if(mesh && Render_SetupMaterial(group->material,group->mode)) {
   scaleT=0;scaleS=0;
   do {
    Render_ApplyMaterialLighting(mesh->matrix,mesh->aux,group->material);
    if(mesh->segmented){gSPSegment(g_displayListCursor++, 1, ((mesh->matrix)));}else{gSPMatrix(g_displayListCursor++, ((mesh->matrix)), G_MTX_LOAD);}
    gSPSegment(g_displayListCursor++, 2, ((mesh->vertices)));
    if(mesh->scaleS) {
     if(scaleS!=mesh->scaleS || scaleT!=mesh->scaleT) {
      if(group->material->flags&0x2000){gSPTexture(g_displayListCursor++, mesh->scaleS, mesh->scaleT, 5, 0, 1);}else{gSPTexture(g_displayListCursor++, mesh->scaleS, mesh->scaleT, 0, 0, 1);}
     }
     scaleS=mesh->scaleS;scaleT=mesh->scaleT;
    }
    gSPDisplayList(g_displayListCursor++, ((mesh->list)));
    mesh=mesh->next;
   }while(mesh);
   if(group->material->flags&0x2000){gDPSetTextureLOD(g_displayListCursor++, G_TL_TILE);}
  }
  group=group->next;
 }while(group);
}

                          
void func_8026C484_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 direct) {
        s32 *sp28;
        s32 sp2C;
        s32 **temp_v0;
        s32 **resource;
        s32 temp_s0;
        s32 temp_s1;
        s32 temp_v0_2;
        s32 temp_v0_3;
        s32 temp_v1;
        s8 *temp_s1_2;
        ObjRecAtCV2 *temp_v1_2;
        temp_v0 = Scene_RequestResource(0, arg0, arg0, 0x18, 0, 0, 0, &D_800C466C_de, 1);
        if (temp_v0 != 0) {
                temp_s1 = Render_GetDirectoryEntry(*temp_v0, arg0, 1);
                Scene_UnlockResource(0, temp_v0);
                temp_v0_2 = func_802540F4_de(0, (void **) &sp28, temp_s1, &D_800C4680_de, 1);
                if (temp_v0_2 != 0) {
                        temp_v0_3 = *sp28;
                        temp_s0 = Render_LocatePackSection((s32) sp28, temp_s1, arg3 % temp_v0_3, &sp2C);
                        Scene_UnlockResource(0, (void *) temp_v0_2);
                        resource = Scene_RequestResource(0, temp_s0, temp_s0, sp2C, 0, 0, &D_0026D7F4, &D_800C4694_de, direct);
                        if (resource != 0) {
                                temp_s1_2 = Render_GetPackSection(*resource, 0);
                                if (D_8011064C != resource || D_8010C564 != arg4 || D_80110640 == 0x20) {
                                        func_8026BC60_de();
                                        if (D_80111310 != 0x100) {
                                                Scene_LockResource(0, resource);
                                                D_80111318[D_80111310] = resource;
                                                D_80111310 += 1;
                                                goto block_11;
                                        }
                                } else {
                                        block_11:
                                        D_8011064C = resource;

                                        D_8010C564 = arg4;
                                        temp_v1 = D_80110640;
                                        temp_v1_2 = &D_801157D8[temp_v1++];
                                        D_80110640 = temp_v1;
                                        temp_v1_2->unk0 = arg1;
                                        temp_v1_2->unkC = 0;
                                        temp_v1_2->unk4 = arg2;
                                        temp_v1_2->unk8 = temp_s1_2;
                                }
                                Scene_UnlockResource(0, resource);
                        }
                }
        }
}

#include "COMMON/GFX.H"

#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;

extern s32 D_800CC364;
#include "COMMON/LONE/D_800CC384.H"
extern void Scene_MarkResourceInUse(s32, void **);

/* Draws a pack resource model as a translucent decal: skips when fewer than 3000 display-list commands are
 * left, loads the matrix (or segment 1), points segment 2 at the textures (the sixth argument overrides the
 * texture section of the pack), sets a primitive-alpha combine with the fog render mode bits and the global
 * geometry mode, then emits the display list of each part; the cached texture and combine states are
 * invalidated before and after. The fifth and seventh arguments are unused. */
void Render_DrawResourceModel(s32 alpha, s32 resource, void *matrix,
                     s32 segment, void *unusedLighting, s32 textureAddress, s32 unusedMode) {
    void *resourceHeader;
    void *textures;
    void *partTable;
    void *partHeader;
    void *displayList;
    Gfx *syncCommand;
    u32 geometryMode;
    s32 partCount;
    s32 partIndex;
    s32 opacity = alpha;

    if (D_800E28A4 - (((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) >> 3) < 3000U) {
        return;
    }
    resourceHeader = *(void **)resource;
    Scene_MarkResourceInUse(0, (void **)resource);
    if (segment != 0) {
        gSPSegment(g_displayListCursor++, 1, matrix);
    } else {
        gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD);
    }
    textures = (void *)textureAddress;
    if (textures == 0) {
        textures = Render_GetPackSection(resourceHeader, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (u32)textures);
    partTable = Render_GetPackSection(resourceHeader, 2);
    D_800CC360 = -1;
    D_800CC364 = -1;
    syncCommand = g_displayListCursor++;
    geometryMode = D_800CC384;
    partCount = *(s32 *)partTable;
    gDPPipeSync(syncCommand);
    gDPSetTextureLUT(g_displayListCursor++, G_TT_NONE);
    gSPTextureL(g_displayListCursor++, 0x8000, 0x8000, 0, 0xFF, G_TX_RENDERTILE, G_ON);
    gDPSetPrimColor(g_displayListCursor++, 0, 0, 0, 0, 0, opacity & 0xFF);
    gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                     0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(g_displayListCursor++, D_800CC38C, G_RM_ZB_XLU_DECAL2);
    gSPGeometryMode(g_displayListCursor++, G_SHADE | G_CULL_BACK | G_FOG |
                    G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH, 0);
    geometryMode |= G_CULL_BACK;
    gSPGeometryMode(g_displayListCursor++, 0, geometryMode);
    for (partIndex = 0; partIndex < partCount; partIndex++) {
        partHeader = Render_GetPackSection(partTable, partIndex);
        Render_GetPackSection(partHeader, 0);
        displayList = Render_GetPackSection(partHeader, 1);
        gSPDisplayList(g_displayListCursor++, (u32)displayList);
    }
    D_800CC364 = -1;
    D_800CC360 = -1;
}
