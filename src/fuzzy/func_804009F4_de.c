#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct SharedTrackObject {u32 header[2];Vec3 position;u8 pad14[0x58];f32 yaw;}SharedTrackObject;
typedef struct TrackKey {u8 pad0[0x1C];f32 time;u8 pad20[4];}TrackKey;
typedef struct TrackClip {s32 stride,count;TrackKey keys[1];}TrackClip;
typedef struct TrackCue {u8 data[0x10];f32 time;}TrackCue;
typedef struct TrackCues {s32 stride,count;TrackCue cues[1];}TrackCues;
typedef struct TrackSpec {u32 prefix[2];s32 id;u32 flags;u8 data[0x3C];}TrackSpec;
typedef struct TrackTable {s32 stride,count;TrackSpec entries[1];}TrackTable;
typedef struct TrackOwner {void *resource;}TrackOwner;
typedef void (*TrackCallback)(void);
typedef struct Shared_MenuContext {TrackOwner *owner;void *resource;u32 field8;TrackCallback callbackC,callback10;u32 field14;SharedTrackObject *target;f32 time,time20,time24,start,end,elapsed,total;s32 active,field3C,field40,field44,field48,field4C,field50,pending,field58;u8 pad5C[0xC];TrackSpec spec;s32 fieldB4,mode;u8 padBC[0x24];s32 request;TrackCallback callbackE4,callbackE8;s32 fieldEC;Vec3 position;f32 yaw;}Shared_MenuContext;
typedef struct TrackResources {u8 pad0[0x34];void *lookup;u8 pad38[0x3C];void *bundle;}TrackResources;
extern Shared_MenuContext *D_800E2830;
extern SharedTrackObject *D_80145060;
extern TrackResources D_8011FE88;
extern void *D_8011FEFC,*D_8011BDFC;
extern char D_0040067C[],D_800DCB10[],D_800E0B2C;
extern f32 D_800DCB18_de;
extern void func_80245B28_de(void);
extern s32 func_8028FE3C_de(void *,void *,s32,s32 *);
extern TrackOwner *func_8025193C_de(s32,s32,s32,s32,s32,s32,void *,char *,s32);
extern TrackCues *func_80403ADC_de(void);
extern s32 func_80403A64_de(void);
extern TrackClip *func_80403A90_de(s32);
extern void func_80253754_de(s32,TrackOwner *);
static inline void minTime(f32 *dest,f32 *src){if(*dest>*src)*dest=*src;}
static inline void maxTime(f32 *dest,f32 *src){if(*dest<*src)*dest=*src;}
s32 func_804009F4_de(s32 index) {
 s32 size,size2,i,count,previous,pending,loaded;SharedTrackObject *captured;TrackResources *resources;TrackOwner *owner,*table;TrackCues *cues;TrackCue *cue;TrackClip *clip;Shared_MenuContext *context,*scanContext;TrackSpec *entry;u8 *data;f32 total;
 captured=D_80145060;pending=D_800E2830->field58;resources=&D_8011FE88;
 if(resources->lookup==0 || resources->bundle==0){failed:return 0;}else{
 if(D_800E2830->active!=0)func_80245B28_de();
 loaded=func_8028FE3C_de(resources->bundle,resources->lookup,index+1,&size);
 owner=func_8025193C_de(0,loaded,loaded,size,0x33,0,D_0040067C,D_800DCB10,1);
 if(owner==0)goto failed;
 D_800E2830->owner=owner;D_800E2830->resource=owner->resource;
 cues=func_80403ADC_de();cue=cues->cues;count=cues->count;
 total=0.0f;
 for(i=0;i<func_80403A64_de();i++){clip=func_80403A90_de(i);{s32 n=clip->count;TrackKey *base=clip->keys;if(n>0){TrackKey *last=base+n;total+=last[-1].time;}}}
 D_800E2830->elapsed=0.0f;D_800E2830->total=total;D_800E2830->start=0.0f;D_800E2830->end=total;
 i=0;if(count>0){scanContext=D_800E2830;do{TrackCue *c=&cue[i];minTime(&scanContext->start,&c->time);maxTime(&scanContext->end,&c->time);i++;}while(i<count);}
 D_800E2830->time=D_800E2830->start;D_800E2830->time20=D_800E2830->start;D_800E2830->time24=D_800E2830->start;
 previous=D_800E2830->spec.id;
 loaded=func_8028FE3C_de(D_8011FEFC,D_8011BDFC,0,&size2);
 if(loaded==0)table=0;else table=func_8025193C_de(0,loaded,loaded,size2,0x33,0,0,&D_800E0B2C,1);
 {TrackTable *entries=table->resource;entry=&entries->entries[index];}D_800E2830->pending=pending;D_800E2830->active=1;D_800E2830->spec=*entry;
 D_800E2830->field50=0;D_800E2830->field40=0;D_800E2830->field44=0;D_800E2830->field48=0;D_800E2830->request=D_800E2830->spec.id;
 if((D_800E2830->spec.flags&1) && D_800E2830->target!=0){D_800E2830->position=D_800E2830->target->position;D_800E2830->yaw=D_800E2830->target->yaw+D_800DCB18_de;}
 if(D_800E2830->spec.flags&2){if(captured!=0){D_800E2830->position=captured->position;D_800E2830->yaw=captured->yaw;}else{D_800E2830->position.x=0.0f;D_800E2830->position.y=0.0f;D_800E2830->position.z=0.0f;D_800E2830->yaw=0.0f;}}
 func_80253754_de(0,table);
 if(pending){TrackCallback first,second;context=D_800E2830;first=context->callbackE4;second=context->callbackE8;context->pending=1;context->field4C=0;context->callbackE4=0;context->callbackE8=0;context->mode=context->spec.flags&8;context->callbackC=first;context->callback10=second;if(context->request-10U<0x47U)context->mode=0;if(D_800E2830->request-400U<4U)D_800E2830->mode=0;
 }else{if(D_800E2830->spec.id<3)D_800E2830->request=previous;D_800E2830->pending=0;D_800E2830->time=D_800E2830->elapsed;}
 if(D_800E2830->spec.id==0x9F)D_800E2830->mode=0;
 return 1;
}
}
