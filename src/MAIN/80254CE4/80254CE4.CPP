#include "span_1000/code_80254CE4.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_802508E0.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "TYPES.H"
#include "MAIN/80255280.H"

extern void func_80255FB8_de(void *arg0);


/* Obtains a free node, marks it active and moves it to the active list, retrying while processing permits. */


static inline func_8022BC04_S3 *take(s32 active) {
    extern void func_80255ED8_de(func_8022BC04_S3 **,func_8022BC04_S3 *);
    extern void func_80255CB8_de(void *,func_8022BC04_S3 *);
    extern func_8022BC04_S3 *D_801010F8;
 func_8022BC04_S3 *node=D_801010F8;
 if(node) {func_80255ED8_de(&D_801010F8,node); node->unk10=active;func_80255CB8_de(&D_8010110C,node);}
 return node;
}


extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);

/* Finds an evictable entry of a list: skips entries flagged 0x702 and returns the first one untouched for at least five ticks of D_80105180, remembering the first recently used candidate in *recent when that slot is still empty; returns null when none qualifies. */







void func_80254D44_de(s32 arg0, s32 arg1)
{
  s32 mask;
  u32 count;
  int new_var;
  u32 new_var2;
  s32 offset;
  u32 limit;
  mask = -0x201;
  if (arg1 != 0)
  {
    mask = -0x401;
  }
 do { count = 0; limit = D_800CB6E0; } while (0);
  new_var2 = limit;
  if (limit != 0)
  {
    offset = count;
    do
    {
      new_var = offset + D_80100560;
      count += 1;
      *((s32 *) (new_var + 0xC)) &= mask;
      offset += 0x28;
    }
    while (count < new_var2);
  }
  D_80101134[arg1] = 0;
}

void func_80254DA4_de(void *arg0, void *arg1) {
    extern int D_80105180;
    func_8022BC04_S3 *arg1_record = arg1;
    int *p = &D_80105180;
    arg1_record->unk10 = *p;
    func_80255FB8_de((char *)p - 0xC10);
}

void func_80254DD0_de(void *arg0, void *arg1) {
    extern void func_80255ED8_de(void *, s32);
    extern s32 func_80255CB8_de(void *, s32);
    extern s32 D_801010F8;
    void *temp_v0;
    void *temp_s0;

    temp_v0 = ((ResourceCacheEntry *)arg1)->owner;
    if (temp_v0 != 0) {
        func_80255488_de(((ResourceLoadRequest *)temp_v0)->key);
        temp_s0 = ((ResourceCacheEntry *)arg1)->owner;
        func_80255ED8_de(&D_8010110C, temp_s0);
        ((ResourceLoadRequest *)temp_s0)->flags = 0;
        func_80255CB8_de(&D_801010F8, (s32) temp_s0);
    }
}

void *func_80254E30_de(void) {
    extern void func_80255ED8_de(void *, s32);
    extern s32 func_80255CB8_de(void *, s32);
    extern s32 D_801010F8;
    void **p = &D_801010F8;
    void *temp_s0 = *p;
    if (temp_s0 != 0) {
        func_80255ED8_de(p, (s32) temp_s0);
        ((ResourceLoadRequest *)temp_s0)->flags = 1;
        func_80255CB8_de(((char *)p + sizeof(IntrusiveList)), (s32) temp_s0);
    }
    return temp_s0;
}

void func_80254E88_de(s32 arg0, void *arg1) {
    extern void func_80255ED8_de(void *, s32);
    extern s32 func_80255CB8_de(void *, s32);
    func_80255ED8_de(&D_8010110C, arg1);
    ((Request_func_802524B0_de *)arg1)->flags = 0;
    func_80255CB8_de((char *)&D_8010110C - 0x14, (s32) arg1);
}

void *func_80254ED0_de(s32 unused,s32 flags) {
 func_8022BC04_S3 *node=take(1);
 if (!node) {
  s32 active=1;
  flags &= 0x10;
  while(func_80251328_de(0,2,flags==0)) {node=take(active);if(node)break;}
 }
 return node;
}

void func_80254F9C_de(s32 unused, s32 arg1) {
    s32 mask;
    u32 count;
    s32 new_var;
    u32 new_var2;
    s32 offset;
    u32 limit;

    if (D_801005A0[arg1] != 0) {
        D_801005A0[arg1] = 0;
        func_802BB420_de(&D_80101160, 0, 1);
    }
    mask = -0x201;
    if (arg1 != 0) {
        mask = -0x401;
    }
    do { count = 0; limit = D_800CB6E0; } while (0);
    new_var2 = limit;
    if (limit != 0) {
        offset = count;
        do {
            new_var = offset + D_80100560;
            count += 1;
            *(s32 *)&((Node80254C10 *)new_var)->flags &= mask;
            offset += 0x28;
        } while (count < new_var2);
    }
    do { D_80101134[arg1] = 0; } while (0);
}

EntryRecAt18V3 *func_80255048_de(s32 unused, EntryList *list, EntryRecAt18V3 **recent)
{
    extern s32 D_80105180[];
    EntryRecAt18V3 *e = list->first;

    if (*recent == 0) {
        for (; e != 0; e = e->next) {
            if (!(e->flags & 0x702)) {
                if ((u32)(D_80105180[0] - e->stamp) >= 5) {
                    return e;
                }
                *recent = e;
                break;
            }
        }
    }
    for (; e != 0; e = e->next) {
        if (!(e->flags & 0x702) && (u32)(D_80105180[0] - e->stamp) >= 5) {
            return e;
        }
    }
    return 0;
}
