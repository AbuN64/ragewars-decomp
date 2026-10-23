#include "include_asm.h"
#include "COMMON/ENTRYRECAT18V3.H"
#include "TEXTURE/80254CE4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MANAGER.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/EXTERNS.H"
#include "AUDIO_2/80255280_2.H"
#include "sdk/os.h"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern void func_80255FB8_de(void *arg0, s32 arg1);
extern s32 D_80105180[];


/* Obtains a free node, marks it active and moves it to the active list, retrying while processing permits. */


static inline func_8022BC04_S3 *take(s32 active) {
 func_8022BC04_S3 *node=D_801010F8.head;
 if(node) {func_80255ED8_de(&D_801010F8,node); node->unk10=active;func_80255CB8_de(&D_8010110C,node);}
 return node;
}



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
    func_8022BC04_S3 *arg1_record = arg1;
    s32 *p = D_80105180;
    arg1_record->unk10 = *p;
    func_80255FB8_de((char *)p - 0xC10, (s32)arg1);
}

void func_80254DD0_de(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_s0;

    temp_v0 = ((ResourceCacheEntry *)arg1)->owner;
    if (temp_v0 != 0) {
        func_80255488_de(((ResourceLoadRequest *)temp_v0)->key);
        temp_s0 = ((ResourceCacheEntry *)arg1)->owner;
        func_80255ED8_de(&D_8010110C, temp_s0);
        ((ResourceLoadRequest *)temp_s0)->flags = 0;
        func_80255CB8_de(&D_801010F8, temp_s0);
    }
}

void *func_80254E30_de(void) {
    IntrusiveList *p = &D_801010F8;
    void *head = p->head;
    if (head != 0) {
        func_80255ED8_de(p, head);
        ((ResourceLoadRequest *)head)->flags = 1;
        func_80255CB8_de(((char *)p + sizeof(IntrusiveList)), head);
    }
    return head;
}

void func_80254E88_de(s32 arg0, void *arg1) {
    func_80255ED8_de(&D_8010110C, arg1);
    ((Request_func_802524B0_de *)arg1)->flags = 0;
    func_80255CB8_de((char *)&D_8010110C - 0x14, arg1);
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

void func_80254F9C_de(s32 unused, s32 request) {
    s32 mask;
    u32 count;
    s32 new_var;
    u32 new_var2;
    s32 offset;
    u32 limit;

    if (D_801005A0[request] != 0) {
        D_801005A0[request] = 0;
        func_802BB420_de(&D_80101160, 0, 1);
    }
    mask = -0x201;
    if (request != 0) {
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
    do { D_80101134[request] = 0; } while (0);
}

EntryRecAt18V3 *func_80255048_de(s32 unused, EntryList *list, EntryRecAt18V3 **recent)
{
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

#if defined(VERSION_US)
unsigned int func_80255048_de_padding_55C84[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_80255088[8] =
    "\000\015OSMesg";
#endif
