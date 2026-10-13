#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "shared/func_8028C568_de_closed.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "span_1000/code_80255BEC.h"

extern Manager D_801047E0;
extern s32 D_80100570;
extern u32 D_80101190;
extern HashNode_func_80252774_de *D_80101194;
extern struct CartridgeReadWorker D_801011B8;
extern s32 D_80105180;
extern s32 D_80106248;
extern void func_80255FB8_de(void *, s32);
extern void *func_80254ED0_de(s32, s32);
extern void *func_802514A8_de(s32, s32);
extern void func_80254AD0_de(s32, s32);
extern void func_80254C70_de(s32, void *);
extern s32 func_80255170_de(s32 *, void *);
extern Request_func_80252774_de *func_80252774_de(s32, Request_func_80252774_de *, s32);
extern void func_80254E88_de(s32, void *);
extern void func_8025637C_de(struct CartridgeReadWorker *, u32, s32, void *);
extern void func_80256454_de(struct CartridgeReadWorker *, u32, s32, void *, struct Queue *, s32, s32);

static inline void acquire(void) {
    u32 token = func_802BCF30_de();
    s32 count = D_8010515C + 1;
    D_8010515C = count;
    if (count != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de(D_801047E0.lock, 0, 1);
    } else func_802BCF50_de(token);
}
static inline void release(void) {
    u32 token = func_802BCF30_de();
    s32 count = D_8010515C - 1;
    D_8010515C = count;
    if (count != 0) {
        func_802BCF50_de(token);
        func_802BB420_de(D_801047E0.lock, 0, 1);
    } else func_802BCF50_de(token);
}
static inline void find(u32 key, Request_func_80252774_de **out) {
    HashNode_func_80252774_de *node = D_80101194 + (((key<<5)^(key>>1)^(key>>9)^(key>>17))&D_80101190);
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
static inline void addref(Node_func_80252774_de *node) {
    node->count++;
    node->flags |= 0x100;
}
static inline void stamp(Node_func_80252774_de *node) {
    node->pad10=D_80105180;
    func_80255FB8_de(&D_80100570,(s32)node);
}
static inline Node_func_80252774_de *allocate(u32 size, u32 flags) {
    Node_func_80252774_de *node=func_802514A8_de(0,flags);
    if (node!=0) {
        addref(node);
        node->data=func_80254B8C_de(0,size,(flags>>5)&1,flags);
        if (node->data!=0) {
            node->pad4=size;
            node->flags |= flags;
            func_80254C70_de(0,node);
        } else {
            if (--node->count==0) node->flags &= ~0x100;
            func_80254AD0_de(0,(s32)node);
            node=0;
        }
    }
    return node;
}
void *func_8025193C_de(s32 unused, u32 key, u32 source, u32 size,
                          u32 mode, s32 owner, void *tag, const char *spare, u32 direct) {
    Request_func_80252774_de *request;
    Request_func_80252774_de *scan;
    Request_func_80252774_de *resolved;
    Node_func_80252774_de *node;
    u32 flags;
    u32 oldFlags;
    s32 busy;
    Request_func_80252774_de *allocated;

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
    if(direct!=0) allocated=func_80254ED0_de(0,mode);
    else {
        scan=D_801047E0.active.head;
        while(scan!=0) {
            if(scan->key==key && size<=(u32)scan->priority) {busy=1;break;}
            scan=scan->next;
        }

        if(direct==0 && busy) goto failed;
        allocated=func_80254ED0_de(0,mode);
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
                resolved=func_80252774_de(0,request,0);
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
        func_80254E88_de(0,request);
    }
failed:
    release();
    return 0;
}
