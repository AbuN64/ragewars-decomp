#include "span_16E000/code_804196C0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80297CD0.h"
#include "stddef.h"
#include "TYPES.H"

s32 func_802744D4_de(void);

/* Allocates and initializes an object, attaches its resource and owner value, then registers it with the resource. */



extern Object_func_80419E54_de *func_8025305C_de(int);

extern int func_80299958_de(void);

extern void func_802A0748_de(void *, int, int);

extern Resource_func_80419E54_de *func_8040EC30_de(int, int);

extern void func_8040EDE4_de(Resource_func_80419E54_de *, Object_func_80419E54_de *);

extern void *func_80411DCC_de(s32 index);

extern void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1);

extern void func_80419F18_de(Object_func_80419E54_de *);

/* Initializes a flicker effect and randomizes each element's intensity. */
void func_80419C84_de(func_80419D04_S1 *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_v1;
    s32 offset;
    int temp;
    arg0->unk44 = 0;
    arg0->unk74 = 0;
    if (arg1 > 0) {
        arg0->unk48 = arg1;
    } else {
        arg0->unk48 = (s32) (func_802744D4_de() % 5 + 1);
    }
    for (var_s1 = 0; var_s1 < arg0->unk48; var_s1++) {
        arg0->unk60[var_s1] = (s32) (func_802744D4_de() % 3 + 1);
        var_v1 = (offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) < 0 ? 0 : ((offset = func_802744D4_de() % 40 + 30, arg0->unk80 - offset) >= 0x100 ? 0xFF : (offset = temp = func_802744D4_de() % 40 + 30, arg0->unk80 - offset));
        arg0->unk4C[var_s1] = var_v1;
    }
}

void func_80419E24_de(void) {
    func_802982C4_de(0xB62, D_00419F9C, D_0041A02C, 3);
}

Object_func_80419E54_de *func_80419E54_de(int arg0, int arg1)
{
  Resource_func_80419E54_de *r;
  Object_func_80419E54_de *p;
  int kind;
  r = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 65535);
  func_80411DCC_de(func_80299958_de());
  p = func_8025305C_de(0x88);
  func_802A0748_de(p, 0, 0x88);
  p->b = (kind = 0xB62);
  p->resource = r;
  p->owner.value = arg1;
  p->c = 8;
  p->a = kind;
  p->resource->value = p->owner.bytes[3];
  func_80419C84_de(p, -1);
  func_80419F18_de(p);
  func_8040EDE4_de(r, p);
  return p;
}
