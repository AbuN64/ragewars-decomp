#include "COMMON/EXTERNS_18.H"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/MANAGER.H"
#include "SCENE/802508E0.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/EXTERNS_10.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/S1.H"
#include "sdk/os.h"
#include "TEXTURE/80254CE4.H"
#include "SYSTEM/80255C40_3.H"

extern Manager D_801047E0;
extern s32 D_80100570;
extern u32 D_80101190;
extern ResourceHashEntry *D_80101194;
extern struct CartridgeReadWorker D_801011B8;
extern s32 D_80105180;
extern void func_80255FB8_de(void *, s32);
extern void *Cache_AcquireLoadRequestWithEviction(s32, s32);
extern void *Cache_AcquireResourceNodeWithEviction(s32, s32);
extern void Cache_ReleasePendingResourceEntry(s32 arg0, s32 arg1);
extern void Cache_InsertResourceByAddress(s32 unused, void *object);
extern s32 func_80255170_de(s32 *, ResourceLoadRequest *);
extern ResourceLoadRequest *Cache_FinalizeResourceLoad(s32 unused, ResourceLoadRequest *request, s32 dropReference);
extern void func_8025637C_de(struct CartridgeReadWorker *, u32, s32, void *);
extern void func_80256454_de(struct CartridgeReadWorker *, u32, s32, void *, struct Queue *, s32, s32);

static inline void acquire(void) {
    u32 token = __osDisableInt();
    s32 count = D_8010515C + 1;
    D_8010515C = count;
    if (count != 1) {
        __osRestoreInt(token);
        osRecvMesg(D_801047E0.lock, 0, 1);
    } else __osRestoreInt(token);
}
static inline void release(void) {
    u32 token = __osDisableInt();
    s32 count = D_8010515C - 1;
    D_8010515C = count;
    if (count != 0) {
        __osRestoreInt(token);
        osSendMesg(D_801047E0.lock, 0, 1);
    } else __osRestoreInt(token);
}
static inline void find(u32 key, ResourceLoadRequest **out) {
    ResourceHashEntry *node = D_80101194 + (((key<<5)^(key>>1)^(key>>9)^(key>>17))&D_80101190);
    if (node->key != key) goto not_initial;
    *out=node->value;
    goto done;
loop_found:
    *out=node->value;
    goto done;
not_initial:
    *out=0;
    if (node==0) goto done;
loop:
    if (node->key==key) goto loop_found;
    node=node->next;
    if (node!=0) goto loop;
done:;
}
static inline void addref(CachedResource *node) {
    node->count++;
    node->flags |= 0x100;
}
static inline void stamp(CachedResource *node) {
    node->stamp=D_80105180;
    func_80255FB8_de(&D_80100570,(s32)node);
}
static inline CachedResource *allocate(u32 size, u32 flags) {
    CachedResource *node=Cache_AcquireResourceNodeWithEviction(0,flags);
    if (node!=0) {
        addref(node);
        node->data=Cache_AllocateHeapWithEviction(0,size,(flags>>5)&1,flags);
        if (node->data!=0) {
            node->unk04=size;
            node->flags |= flags;
            Cache_InsertResourceByAddress(0,node);
        } else {
            if (--node->count==0) node->flags &= ~0x100;
            Cache_ReleasePendingResourceEntry(0,(s32)node);
            node=0;
        }
    }
    return node;
}
void *Cache_RequestResource(s32 unused, u32 key, u32 source, u32 size,
                          u32 mode, s32 owner, void *tag, const char *spare, u32 direct) {
    ResourceLoadRequest *request;
    ResourceLoadRequest *scan;
    ResourceLoadRequest *resolved;
    CachedResource *node;
    u32 flags;
    u32 oldFlags;
    s32 busy;
    ResourceLoadRequest *allocated;

    acquire();
    find(key,&request);
    if (request!=0 && (u32)request->priority<=size) {
        addref(request->node);
        stamp(request->node);
        release();
        return request->node;
    }
    direct |= D_801047E0.mask;
    busy=0;
    if(direct!=0) allocated=Cache_AcquireLoadRequestWithEviction(0,mode);
    else {
        scan=D_801047E0.active.head;
        while(scan!=0) {
            if(scan->key==key && size<=(u32)scan->priority) {busy=1;break;}
            scan=scan->next;
        }

        if(direct==0 && busy) goto failed;
        allocated=Cache_AcquireLoadRequestWithEviction(0,mode);
    }
    request=allocated;
    if(request!=0) {
        if(tag!=0) flags=(mode&0x1C)|0x22;
        else flags=mode;
        request->extra=0;
        node=allocate(size,flags);
        request->node=node;
        if(request->node!=0) {
            if(size&1) size++;
            request->key=key;
            request->priority=size;
            request->owner=owner;
            request->tag=tag;
            request->mode=mode;
            func_80255ED8_de(&D_801047E0.pending,request);
            func_80255D14_de(&D_801047E0.active,request);
            if(direct!=0) {
                if(tag!=0) request->flags |= 4;
                release();
                func_8025637C_de(&D_801011B8,source,size,request->node->data);
                if(tag!=0) func_80255170_de(&D_80106248,request);
                acquire();
                if(tag!=0) request->flags &= ~4;
                resolved=Cache_FinalizeResourceLoad(0,request,0);
                if(resolved!=0 && resolved!=request) addref(resolved->node);
                release();
                if(resolved!=0) return resolved->node;
                return 0;
            } else {
                oldFlags=request->flags;
                request->flags=oldFlags|2;
                if(tag!=0) request->flags=oldFlags|0xE;
                release();
                {
                    void *replyQueue = &D_801047E0;
                    func_80256454_de(&D_801011B8,source,size,request->node->data,replyQueue,(s32)request,0);
                }
                return 0;
            }
        }
        Cache_RecycleLoadRequest(0,request);
    }
failed:
    release();
    return 0;
}
