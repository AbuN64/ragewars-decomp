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

extern Gfx *D_80110634;

extern s32 func_80269A80_de(Material18 *,s8);

extern void func_8026B504_de(u32,u32,Material18 *),func_8026AC38_de(void);

void Scene_LockResource(void *, void *);

void Scene_UnlockResource(void *, void *);

void **func_802540F4_de(s32, void **, s32, void *, s32);

void func_8026BC60_de(void);


int func_8028FE28_de(int *, int, int);

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
  if(mesh && func_80269A80_de(group->material,group->mode)) {
   scaleT=0;scaleS=0;
   do {
    func_8026B504_de(mesh->matrix,mesh->aux,group->material);
    if(mesh->segmented){gSPSegment(D_80110634++, 1, ((mesh->matrix)));}else{gSPMatrix(D_80110634++, ((mesh->matrix)), G_MTX_LOAD);}
    gSPSegment(D_80110634++, 2, ((mesh->vertices)));
    if(mesh->scaleS) {
     if(scaleS!=mesh->scaleS || scaleT!=mesh->scaleT) {
      if(group->material->flags&0x2000){gSPTexture(D_80110634++, mesh->scaleS, mesh->scaleT, 5, 0, 1);}else{gSPTexture(D_80110634++, mesh->scaleS, mesh->scaleT, 0, 0, 1);}
     }
     scaleS=mesh->scaleS;scaleT=mesh->scaleT;
    }
    gSPDisplayList(D_80110634++, ((mesh->list)));
    mesh=mesh->next;
   }while(mesh);
   if(group->material->flags&0x2000) {gDPSetTextureLOD(D_80110634++, G_TL_TILE);}
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
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, group->material->alpha);
    do {
     func_8026B504_de(mesh->matrix,mesh->aux,group->material);
     if(mesh->segmented){gSPSegment(D_80110634++, 1, ((mesh->matrix)));}else{gSPMatrix(D_80110634++, ((mesh->matrix)), G_MTX_LOAD);}
     gSPSegment(D_80110634++, 2, ((mesh->vertices)));
     gSPDisplayList(D_80110634++, ((mesh->list)));
     mesh=mesh->next;
    }while(mesh);
   }
   group=group->next;
  }while(group);
 }
 group=D_8010C584;
 if(group)do {
  mesh=group->meshes;
  if(mesh && func_80269A80_de(group->material,group->mode)) {
   scaleT=0;scaleS=0;
   do {
    func_8026B504_de(mesh->matrix,mesh->aux,group->material);
    if(mesh->segmented){gSPSegment(D_80110634++, 1, ((mesh->matrix)));}else{gSPMatrix(D_80110634++, ((mesh->matrix)), G_MTX_LOAD);}
    gSPSegment(D_80110634++, 2, ((mesh->vertices)));
    if(mesh->scaleS) {
     if(scaleS!=mesh->scaleS || scaleT!=mesh->scaleT) {
      if(group->material->flags&0x2000){gSPTexture(D_80110634++, mesh->scaleS, mesh->scaleT, 5, 0, 1);}else{gSPTexture(D_80110634++, mesh->scaleS, mesh->scaleT, 0, 0, 1);}
     }
     scaleS=mesh->scaleS;scaleT=mesh->scaleT;
    }
    gSPDisplayList(D_80110634++, ((mesh->list)));
    mesh=mesh->next;
   }while(mesh);
   if(group->material->flags&0x2000){gDPSetTextureLOD(D_80110634++, G_TL_TILE);}
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
                temp_s1 = func_8028FE28_de(*temp_v0, arg0, 1);
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

#ifdef NON_MATCHING
#include "abi.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTSTATE18.H"
#include "gbi.h"

#include "COMMON/DISPLAY.H"
extern Gfx *D_80110634;
extern u32 D_800E28A4;

extern s32 D_800CC364;
extern u32 D_800CC384[]; /* read as an aggregate element: the ROM keeps its load ahead of the display-list stores */
extern void func_80253BBC_de(s32, void **);

/* 19/168 aligned words differ: geometry-mode register (a2/a3) and display-list store scheduling.
 * The sixth argument overrides the texture segment; the fifth is unused. */
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

    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) >> 3) < 3000U) {
        return;
    }
    resourceHeader = *(void **)resource;
    func_80253BBC_de(0, (void **)resource);
    if (segment != 0) {
        gSPSegment(D_80110634++, 1, matrix);
    } else {
        gSPMatrix(D_80110634++, matrix, G_MTX_LOAD);
    }
    textures = (void *)textureAddress;
    if (textures == 0) {
        textures = Render_GetPackSection(resourceHeader, 0);
    }
    gSPSegment(D_80110634++, 2, (u32)textures);
    partTable = Render_GetPackSection(resourceHeader, 2);
    geometryMode = D_800CC384[0];
    D_800CC360 = -1;
    D_800CC364 = -1;
    syncCommand = D_80110634++;
    partCount = *(s32 *)partTable;
    gDPPipeSync(syncCommand);
    gDPSetTextureLUT(D_80110634++, G_TT_NONE);
    gSPTextureL(D_80110634++, 0x8000, 0x8000, 0, 0xFF, G_TX_RENDERTILE, G_ON);
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, opacity & 0xFF);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                     0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, (*(u32 *)&D_800CC38C), G_RM_ZB_XLU_DECAL2);
    gSPGeometryMode(D_80110634++, G_SHADE | G_CULL_BACK | G_FOG |
                    G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH, 0);
    gSPGeometryMode(D_80110634++, 0, geometryMode | G_CULL_BACK);
    for (partIndex = 0; partIndex < partCount; partIndex++) {
        partHeader = Render_GetPackSection(partTable, partIndex);
        Render_GetPackSection(partHeader, 0);
        displayList = Render_GetPackSection(partHeader, 1);
        gSPDisplayList(D_80110634++, (u32)displayList);
    }
    D_800CC364 = -1;
    D_800CC360 = -1;
}
#else
INCLUDE_ASM("span_1000", Render_DrawResourceModel);
#endif
