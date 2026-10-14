#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"
/* Draws each selected entry in the object range with shared position and scale. */



extern s32 func_80265550_de(void *,s32,s32,s32 *,s32 *);


extern void func_80285B64_de(s32,void *,Triple,f32,f32,s32);

void func_8028CE94_de(Object_func_8028CE94_de *arg0,s32 arg1,s32 arg2,Triple pos,D_800C7470_Pair scale) {
 s32 sp20,sp24; void *data; s32 count; StridedTable *temp_v1; s32 var_s0; StridedTable *temp_v0;
 f32 arg6,arg7;
 temp_v0=arg0->unkA8;
 arg6=scale.first;arg7=scale.second;
 data=temp_v0->data;count=temp_v0->count;
 if(func_80265550_de(data,count,arg2,&sp20,&sp24)) {
  for(var_s0=sp20;var_s0<=sp24;var_s0++) {
   temp_v1=arg0->unkAC;
   func_80285B64_de(arg1,(char *)temp_v1+(var_s0*temp_v1->stride+8),pos,arg6,arg7,0);
  }
 }
}
