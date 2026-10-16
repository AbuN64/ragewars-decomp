#include "shared/particle_lighting.h"
#include "span_16E000/code_80442BC8.h"
#include "TYPES.H"
#include "common/unused.h"
#include "span_1000/code_8022F3E8.h"

extern int D_800D15E0;
extern f32 D_800D15E4[5];
extern void func_8024A1D0_de(Object_func_80443128_de *, void *, void *);
void func_80443128_de(Object_func_80443128_de *object, void *context, void *lookup) {
 D_800D15E0=3;
 object->view[D_800D297C]=D_800D0EF8;
 D_800D15E4[0]=(255.0f);
 D_800D15E4[1]=0;
 D_800D15E4[2]=0;
 D_800D15E4[4]=0;
 D_800D15E4[3]=(float)(D_8014DE50/2);
 func_8024A1D0_de(object,context,lookup);
 D_800D15E0=0;
}
