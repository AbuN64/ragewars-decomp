#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MENU/80442BC8.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "include_asm.h"
#include "RENDER_4/8026AC38.H"
#include "COMMON/OBJECTLINKS14C.H"

f32 Items_ReadBoundValue(ItemRecAt14 *arg0) {
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

/* Writes a numeric menu value through its bound storage callback using the selected scalar type. */

void Items_WriteBoundValue(ItemRecAt14 *item,float value) {
 float *storage;
 struct Binding *binding;
 unsigned int *word;
 binding=item->binding;
 storage=binding->storage();

 switch(binding->type) {
 case 0:*(float *)storage=value;return;
 case 3:*(signed char *)storage=(int)value;return;
 case 4:*(short *)storage=(int)value;return;
 case 1:case 2:case 5:*(int *)storage=(int)value;return;
 case 6:*(unsigned char *)storage=(unsigned int)value;return;
 case 7:*(unsigned short *)storage=(unsigned int)value;return;
 case 8:word=(unsigned int *)storage;*word=(unsigned int)value;return;
 }
}

/* Calls func_8024B990_de with its three arguments and the table D_800D0EF8 as the fourth. */
extern void func_8024B990_de(void *, void *, void *, void *);

void func_80443104_de(void *first, void *second, void *third) {
    func_8024B990_de(first, second, third, &D_800D0EF8);
}

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

#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E26C4 */
unsigned int D_blob_eedd474d2adb89afde8e[1] = {
    0x00000000,
};
#endif
