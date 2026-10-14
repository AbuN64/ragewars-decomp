#include "span_16E000/code_80442BC8.h"
#include "types.h"
#include "common/unused.h"

f32 func_80442EC0_de(ItemRecAt14 *arg0) {
 Binding *v = arg0->binding;
 void *p = v->storage();
 switch(v->type) {
 default: return 0.0f;
 case 0: return *(f32 *)p;
 case 3: return *(s8 *)p;
 case 4: return *(s16 *)p;
 case 1: case 2: case 5: return *(s32 *)p;
 case 6: return *(u8 *)p;
 case 7: return *(u16 *)p;
 case 8: return *(u32 *)p;
 }
}
