#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
/* Forwards the actor, event value and three-component input with a zero final flag. */

extern void func_80216288_de(void *,int,Triple,int);
void func_8026740C_de(void *actor,int unused1,int unused2,Triple input,int event) {
 func_80216288_de(actor,event,input,0);
}
