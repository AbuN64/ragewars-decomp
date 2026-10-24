#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "sdk/SCHED/8028DF6C_2.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"

/* Collects platform actors, records the special actor and selects one of three random states. */



extern LevelActor *D_800F3CD0[],*D_800F3D0C;
extern s32 D_80142850;
extern s32 func_802A01E8_de(void);
void func_8028E284_de(SceneRecAt140 *scene) {
 s32 count=0,i=9,offset=36;LevelActor *actor=scene->actors;
 D_800F3D0C=0;
 do {*(LevelActor **)((char *)D_800F3CD0+offset)=0;i--;offset-=4;} while(i>=0);
 i=0;
 if(scene->count>0)do {
  if(((struct Def *)actor->definition)->type==3) {if(((struct Def *)actor->definition)->id==0xBD6){if(scene->count)D_800F3D0C=actor;else D_800F3D0C=actor;}}
  else if(((struct Def *)actor->definition)->type==10) {if(actor->type==0x64E)D_800F3CD0[count++]=actor;}
  if(count>=10)return;
  actor++;

 }while(++i<scene->count);
 D_80142850=func_802A01E8_de()%3;
}
