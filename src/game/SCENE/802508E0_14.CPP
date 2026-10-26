#include "COMMON/MANAGER.H"
#include "COMMON/LONE/D_801051A0.H"
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


extern void func_80254DD0_de(void *arg0, struct IntrusiveList *arg1);

extern void func_80255B2C_de(void *arg0, s32 arg1);

extern void func_80254AD0_de(s32 arg0, s32 arg1);


extern s32 D_80100570;


extern void *func_80255A34_de(void *arg0, s32 arg1);

extern void *func_80255920_de(void *, s32);

extern void func_80255D70_de(void *, s32, s32);

void func_80254990_de(void *unused, struct IntrusiveList *resource) {
    s32 remainingReferences;

    resource->nextOffset = resource->nextOffset & ~2;
    if (resource->prevOffset != 0) {
    loop_1:
        do {
            remainingReferences = resource->prevOffset - 1;
            resource->prevOffset = remainingReferences;
            if (remainingReferences != 0) {
                goto loop_1;
            }
            resource->nextOffset = resource->nextOffset & ~0x100;
        } while (resource->prevOffset != 0);
    }
    if (!(resource->nextOffset & 0x702)) {
        func_80254DD0_de(0, resource);
        func_80255B2C_de(&D_801051A0, *(s32 *) resource);
        func_80254AD0_de(0, resource);
    }
}

void *func_80254A28_de(s32 unused0, s32 requestFlags) {
    extern void **D_80100564;
    struct ResourceCacheEntry *cacheEntry;
    struct Pool *pool = (struct Pool *)&D_8010513C;

    if (pool->count == 0) {
        return 0;
    }
    pool->count -= 1;
    cacheEntry = D_80100564[D_8010513C];
    cacheEntry->flags = 0x800;
    cacheEntry->references = 0;
    cacheEntry->resource = 0;
    cacheEntry->callback = 0;
    cacheEntry->pending = 0;
    cacheEntry->owner = 0;
    cacheEntry->lastUsed = pool->field44;
    func_80255CB8_de((char *)pool - 0xBCC, cacheEntry);
    cacheEntry->flags |= (requestFlags & 0xC);
    return cacheEntry;
}

void func_80254AD0_de(s32 unused0, s32 arg1) {
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

int func_80254B58_de(int unused, int keepRecent, int allocationFlags) {
    int effectiveKeepRecent = keepRecent;
    if (allocationFlags & 0x10) {
        effectiveKeepRecent = 0;
    }
    return func_80251328_de(0, 2, effectiveKeepRecent);
}

void *func_80254B8C_de(s32 arg0, u32 byteCount, s32 allocatorSelection, u32 evictionFlags)
{
  void *result;
  s32 value;
  if (allocatorSelection != 0)
  {
    result = func_80255A34_de(&D_801051A0, byteCount);
  }
  else
    if (value)
  {
    result = func_80255920_de(&D_801051A0, byteCount);
  }
  else
  {
    result = func_80255920_de(&D_801051A0, byteCount);
  }
  if (result == 0)
  {
    evictionFlags &= 0x10;
    do
    {
      value = func_80251328_de(0, 2, evictionFlags == 0);
    }
    while ((value != 0) && (value < byteCount));
    if (value >= byteCount)
    {
      if (allocatorSelection != 0)
      {
        result = func_80255A34_de(&D_801051A0, byteCount);
      }
      else
      {
        result = func_80255920_de(&D_801051A0, byteCount);
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
