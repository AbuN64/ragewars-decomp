#include "COMMON/MANAGER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SCENE/802508E0_14.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern char D_801051A0;

extern void func_80254DD0_de(void *arg0, struct IntrusiveList *arg1);

extern void func_80255B2C_de(void *arg0, s32 arg1);

extern void func_80254AD0_de(s32 arg0, s32 arg1);


extern s32 D_80100570;


extern void *func_80255A34_de(void *arg0, s32 arg1);

extern void *func_80255920_de(void *, s32);

extern void func_80255D70_de(void *, s32, s32);

void func_80254990_de(void *unused, struct IntrusiveList *arg1) {
    s32 temp_v0;

    arg1->nextOffset = arg1->nextOffset & ~2;
    if (arg1->prevOffset != 0) {
    loop_1:
        do {
            temp_v0 = arg1->prevOffset - 1;
            arg1->prevOffset = temp_v0;
            if (temp_v0 != 0) {
                goto loop_1;
            }
            arg1->nextOffset = arg1->nextOffset & ~0x100;
        } while (arg1->prevOffset != 0);
    }
    if (!(arg1->nextOffset & 0x702)) {
        func_80254DD0_de(0, arg1);
        func_80255B2C_de(&D_801051A0, *(s32 *) arg1);
        func_80254AD0_de(0, arg1);
    }
}

void *func_80254A28_de(s32 unused0, s32 arg1) {
    extern void **D_80100564;
    struct ResourceCacheEntry *temp_s0;
    struct Pool *pool = (struct Pool *)&D_8010513C;

    if (pool->count == 0) {
        return 0;
    }
    pool->count -= 1;
    temp_s0 = D_80100564[D_8010513C];
    temp_s0->flags = 0x800;
    temp_s0->references = 0;
    temp_s0->resource = 0;
    temp_s0->callback = 0;
    temp_s0->pending = 0;
    temp_s0->owner = 0;
    temp_s0->lastUsed = pool->field44;
    func_80255CB8_de((char *)pool - 0xBCC, temp_s0);
    temp_s0->flags |= (arg1 & 0xC);
    return temp_s0;
}

void func_80254AD0_de(s32 arg0, s32 arg1) {
    extern void **D_80100564;
    func_80255ED8_de((void *)&D_80100570, arg1);
    if (((CachedResource *)arg1)->flags & 0x1000) {
        func_80255ED8_de(&((IntrusiveList *)&D_80100570)[1], arg1);
    }
    if (*(&D_80100570 - 2) == arg1) {
        *(&D_80100570 - 2) = 0;
    }
    ((CachedResource *)arg1)->flags = 0;
    D_80100564[((struct Pool *)&D_8010513C)->count] = (void *)arg1;
    *(&D_80100570 + 0x2F3) += 1;
}

int func_80254B58_de(int unused, int arg1, int arg2) {
    int var_v0 = arg1;
    if (arg2 & 0x10) {
        var_v0 = 0;
    }
    return func_80251328_de(0, 2, var_v0);
}

void *func_80254B8C_de(s32 arg0, u32 arg1, s32 arg2, u32 arg3)
{
  void *result;
  s32 value;
  if (arg2 != 0)
  {
    result = func_80255A34_de(&D_801051A0, arg1);
  }
  else
    if (value)
  {
    result = func_80255920_de(&D_801051A0, arg1);
  }
  else
  {
    result = func_80255920_de(&D_801051A0, arg1);
  }
  if (result == 0)
  {
    arg3 &= 0x10;
    do
    {
      value = func_80251328_de(0, 2, arg3 == 0);
    }
    while ((value != 0) && (value < arg1));
    if (value >= arg1)
    {
      if (arg2 != 0)
      {
        result = func_80255A34_de(&D_801051A0, arg1);
      }
      else
      {
        result = func_80255920_de(&D_801051A0, arg1);
      }
    }
  }
  return result;
}

void func_80254C70_de(s32 unused, void *object) {
    Node80254C10 *node = object;
    Node80254C10 *scan;

    scan = D_80100584.head;
    while (scan != 0) {
        if (scan->start > node->start) {
            func_80255D70_de(&D_80100584, (s32)scan, (s32)node);
            break;
        }
        scan = scan->next;
    }
    if (scan == 0) {
        func_80255D14_de(&D_80100584, node);
    }
    node->flags |= 0x1000;
}

void func_80254D00_de(void) {
    s32 *p = &D_801005A8;
    func_80254D44_de(0, *p);
    D_80100598[*p] = 0;
}
