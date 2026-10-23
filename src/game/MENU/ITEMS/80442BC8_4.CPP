#include "include_asm.h"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTLINKS14C.H"

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

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DD3AC[1] = {
    0x71755200,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E9F3C[1] = {
    0x0041D280,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EED7C[1] = {
    0x4BBE0F47,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DE6FC[1] = {
    0x00443518,
};
#endif
