#include "types.h"

extern void func_802BD320_de(void *a, void *b, void *c, void *d);
extern s32 func_802BCF10_de(void);
extern void func_802BD160_de(s32 arg0);
extern void func_80291404(void *arg0);

extern int D_80146CE8;
extern int D_800C5400_de;
extern int D_800C5408_de;
extern int D_800C5414_de;
extern int D_8011FAC0;

void func_80291404_us_rev1(void) {
    func_802BD320_de(&D_80146CE8, &D_800C5400_de, &D_800C5408_de, &D_800C5414_de);
    func_802BD160_de(func_802BCF10_de() | 0x400);
    func_80291404(&D_8011FAC0);
}
