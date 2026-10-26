#include "include_asm.h"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/UNSIGNED_QUOTIENT.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/EXTERNS_17.H"
#include "COMMON/TRIPLE.H"
#include "AUDIO_4/802BF230.H"
#include "SCENE/802508E0_10.H"
#include "sdk/SCHED/8028DF6C_7.H"
#include "sdk/os.h"

#include "COMMON/GAME_SESSION.H"
void Sched_HandleRspCompletion(void *object) {
 OSSched *scheduler=object;
 OSScTask_s *nextRsp,*nextRdp;
 OSScTask_s *task;
 Frame *frame;
 u64 elapsed;
 f32 duration1,duration2,duration3,duration4;
 s32 flags,taskState;
 task=scheduler->curRSPTask;
 scheduler->curRSPTask=0;
 taskState=task->state;
 nextRsp=0;nextRdp=0;
 if((taskState&0x10)&&func_802BA140_de(&task->list)) {
  task->state|=0x20;
  if((task->flags&7)==3) {
   task->next=scheduler->gfxListHead;
   scheduler->gfxListHead=task;
   if(!scheduler->gfxListTail) scheduler->gfxListTail=task;
  }
  if(task->flags&0x20) {
   elapsed=((func_802BADC0_de()-D_8011B1E0)<<6)/3;
   duration1=(f32)elapsed;
   D_8011B1D8+=duration1*D_800C5354_de;
  }
 } else {
  task->state&=~2;
  if(task->list.type==1) {
   D_800CD700=0;
   if(task->flags&0x20) {
    elapsed=((func_802BADC0_de()-D_8011B1E0)<<6)/3;
    duration2=(f32)elapsed;
    D_8011B1D8=D_8011B1D8+duration2*D_800C5358_de;
    D_800CD750=D_8011B1D8;
    elapsed=((func_802BADC0_de()-D_8011B1D0)<<6)/3;
    duration3=(f32)elapsed;
    D_800CD74C=duration3*D_800C535C_de;
    frame=D_8011FAC0.ring.frames;
    if(task->framebuffer!=frame[0].colorImage) {
     if(task->framebuffer==frame[1].colorImage) frame+=1;
     else if(task->framebuffer==frame[2].colorImage) frame+=2;
    }
    func_80253CEC_de(0,frame->commands==D_8014D464);
    if(osSendMesg(task->msgQ,task->msg,1)==-1) *((char *)NULL)=0;
   }
  } else {
   elapsed=((func_802BADC0_de()-D_8011B1D0)<<6)/3;
   duration4=(f32)elapsed;
   D_800CD74C=duration4*D_800C5360_de;
   if(osSendMesg(task->msgQ,task->msg,1)==-1) *((char *)NULL)=0;
  }
  Sched_CompleteTaskAndSwapBuffer(scheduler,task);
 }
 flags=((scheduler->curRSPTask==0)<<1)|(scheduler->curRDPTask==0);
 if(Sched_SelectRunnableTasks(scheduler,&nextRsp,&nextRdp,flags)!=flags) Sched_StartSelectedTasks(scheduler,nextRsp,nextRdp);
}

/* Mechanically ported from github/legacy:src/func_8028F258.c by address. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/OBJRECAT20V1.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"


extern u32 D_80142920;

extern s32 D_80142C30;

extern s32 D_80146CC8;

extern s32 D_80146CD0;

extern u32 D_80146CCC;

void Sched_HandleRdpCompletion(OSSched *sc)
{
    s32 value1 = 0;
    s32 value2 = 0;
    OSScTask_s *task = sc->curRDPTask;
    void *framebuffer;
    Frame *schedule;
    Frame *schedules;
    s32 flags;
    task->state &= ~1;
    if (task->list.type == 1) {
        if ((task->flags & 0x20) != 0) {
            D_800CD754 = (f32)(((func_802BADC0_de() - D_8011B1E8) << 6) / 3) * D_800C5364_de;
        }
        sc->curRDPTask = 0;
        if ((task->flags & 0x20) != 0) {
            schedules = D_8011FAC0.ring.frames;
            framebuffer = task->framebuffer;
            if (framebuffer == schedules[0].colorImage) {
                schedule = &schedules[0];
            } else if (framebuffer == schedules[1].colorImage) {
                schedule = &schedules[1];
            } else if (framebuffer == schedules[2].colorImage) {
                schedule = &schedules[2];
            } else {
                schedule = &schedules[0];
            }
            D_80142C34 = D_801428AC;
            D_801428AC = D_8011B9F8;
            D_8011B9F8 = D_80142CA4;
            D_80142CA4 = D_80142920 + 1;
            if (D_80142CA4 >= schedule->ticks && D_80146CD0 == 0 && D_80146CC8 == 0) {
                D_80142C30 = (s32)schedule->colorImage;
                osViSwapBuffer((s32)schedule->colorImage);
                D_80146CC8++;
            } else {
                D_80146CD0++;
                D_801428B0[D_80146CCC] = schedule;
                D_80146CCC++;
                if (D_80146CCC >= D_800DE850) {
                    D_80146CCC = 0;
                }
            }
            SetN64_OnFrameComplete(schedule);
        }
    }
    Sched_CompleteTaskAndSwapBuffer(sc, task);
    flags = (sc->curRSPTask == 0) * 2 | (sc->curRDPTask == 0);
    if (Sched_SelectRunnableTasks(sc, &value1, &value2, flags) != flags) {
        Sched_StartSelectedTasks(sc, value1, value2);
    }
}
