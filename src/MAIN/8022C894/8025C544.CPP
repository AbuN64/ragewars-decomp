#include "span_1000/code_8025A3EC.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025C544.h"
#include "TYPES.H"

void func_8025C524_de(SlotRecAtB4V2 *arg0, s32 arg1)
{
  s32 *new_var;
  int new_var2;
  s32 temp_s0;
  void *temp_s0_2;
  temp_s0 = (s32)arg0->owner;
  temp_s0_2 = temp_s0 + 0x84;
  new_var2 = 2;
  new_var = &arg0->index;
  func_802B2F00_de(temp_s0_2, ((OwnerCode8025A3EC8025B5F0 *)temp_s0)->samples[*new_var]);
  alSndpSetPan(temp_s0_2, arg1 & 0xFF);
}

void func_8025C578_de(SlotRecAtB4V2 *arg0)
{
  s16 *new_var;
  s32 temp_v1;
  void *temp_s0;
  temp_v1 = (s32)arg0->owner;
  temp_s0 = temp_v1 + 0x84;
  func_802B2F00_de(temp_s0, ((OwnerCode8025A3EC8025B5F0 *)temp_v1)->samples[arg0->index]);
  func_802B2620_de(temp_s0);
}

void func_8025C5BC_de(SlotRecAtB4V2 *arg0) {
    func_802B2D80_de(arg0->owner->sound);
}

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern s32 func_802B2620_de(void *arg0);
extern void alSndpStop(void *arg0);

void func_8025C5DC_de(SlotRecAtB4V2 *arg0) {
    s32 a0;
    void *s1;

    a0 = arg0->owner;
    arg0->active = 1;
    arg0->flag = 0;
    s1 = (void *)(a0 + 0x84);
    if (arg0->key != ((OwnerCode8025A3EC8025B5F0 *)a0)->key) {
        s32 idx = arg0->index;
        s32 addr = a0 + idx * 2;
        func_802B2F00_de(s1, ((OwnerCode8025A3EC8025B5F0 *)a0)->samples[idx]);
        if (func_802B2620_de(s1) != 0) {
            alSndpStop(s1);
        }
        arg0->state = -1;
    }
}

void func_802B25D0_de(void *a, short b);

void func_8025C65C_de(SlotRecAtB4V2 *arg0) {
    void *base;
    Slots *arrayBase;
    short *slot;
    base = arg0->owner;
    arrayBase = &((ContextCode8025A3EC *)base)->slots;
    func_802B25D0_de(((OwnerCode8025A3EC8025B5F0 *)base)->sound, arrayBase->ids[arg0->index]);
    arrayBase->ids[arg0->index] = -1;
    arg0->priority = 0;
    arg0->fieldC = -1;
    arg0->used = -1;
    arg0->value = -1;
    arg0->channel = -1;
    arg0->fieldB4 = -1;
}
