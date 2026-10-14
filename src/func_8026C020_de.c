#include "span_1000/code_8026AC38.h"
#include "abi.h"
#include "gbi.h"
/* Emits display lists for visible mesh groups, redraws deferred translucent groups and restores changed texture state. */
#include "types.h"
#include "types.h"
#include "n64sdk.h"



extern Group18 *D_8010C56C,*D_8010C584;
extern Gfx *D_80110634;
extern s32 func_80269A80_de(Material18 *,s8);
extern void func_8026B504_de(u32,u32,Material18 *),func_8026AC38_de(void);
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
