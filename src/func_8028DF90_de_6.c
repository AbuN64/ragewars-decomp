#include "types.h"
#include "stddef.h"
#include "common/unused.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "shared/unsigned_quotient.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802BA13C.h"
#include "span_C76B0/data.h"
extern SchedulerFrame D_8011FAC0[3];
void func_8028EDA0_de(void *object) {
 Scheduler *scheduler=object;
 SchedulerTask *nextRsp,*nextRdp;
 SchedulerTask *task;
 SchedulerFrame *frame;
 u64 elapsed;
 f32 duration1,duration2,duration3,duration4;
 s32 flags,taskState;
 task=scheduler->rsp;
 scheduler->rsp=0;
 taskState=task->state;
 nextRsp=0;nextRdp=0;
 if((taskState&0x10)&&func_802BA140_de(&task->list)) {
  task->state|=0x20;
  if((task->flags&7)==3) {
   task->next=scheduler->gfxHead;
   scheduler->gfxHead=task;
   if(!scheduler->gfxTail) scheduler->gfxTail=task;
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
    frame=D_8011FAC0;
    if(task->framebuffer!=frame[0].framebuffer) {
     if(task->framebuffer==frame[1].framebuffer) frame+=1;
     else if(task->framebuffer==frame[2].framebuffer) frame+=2;
    }
    func_80253CEC_de(0,frame->serial==D_8014D464);
    if(func_802BB420_de(task->queue,task->message,1)==-1) *((char *)NULL)=0;
   }
  } else {
   elapsed=((func_802BADC0_de()-D_8011B1D0)<<6)/3;
   duration4=(f32)elapsed;
   D_800CD74C=duration4*D_800C5360_de;
   if(func_802BB420_de(task->queue,task->message,1)==-1) *((char *)NULL)=0;
  }
  func_8028FA0C_de(scheduler,task);
 }
 flags=((scheduler->rsp==0)<<1)|(scheduler->rdp==0);
 if(func_8028F544_de(scheduler,&nextRsp,&nextRdp,flags)!=flags) func_8028FA60_de(scheduler,nextRsp,nextRdp);
}
