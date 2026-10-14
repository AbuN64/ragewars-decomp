#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804379C8.h"
/* Updates the two menu options and plays their change sounds. */

extern struct IntPair *D_800E58A4;
extern unsigned char D_801462E1[];
extern int func_8041A6E0_de(int);
extern void func_8025DF34_de(int);
extern int func_8025E2C4_de(void);
int func_80439308_de(void) {
 int value;
 unsigned char *options;
 int sound;
 value=func_8041A6E0_de(D_800E58A4->field_4);
 options=D_801462E1;
 if(value!=options[0]){options[0]=value;func_8025DF34_de(0x460);}
 value=func_8041A6E0_de(D_800E58A4->field_0);
 if(value!=options[-1]){
  options[-1]=value;
  if((unsigned char)value<5) sound=0;
  else {if(func_8025E2C4_de()!=0)goto end; sound=0x34;}
  func_8025E2D4_de(sound);
 }
 end: return 0;
}
