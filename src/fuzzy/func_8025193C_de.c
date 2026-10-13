#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"

extern Manager D_801047E0;
extern s32 D_80100570;
extern u32 D_80101190;
extern HashNode_func_80251F6C_de *D_80101194;
extern struct CartridgeReadWorker D_801011B8;
extern s32 D_80105180;
extern char D_80106248[];
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(void *, s32, s32);
extern s32 func_802BB420_de(void *, s32, s32);
extern void func_80255FB8_de(void *, Node_func_80251F6C_de *);
extern Request_func_80251F6C_de *func_80254ED0_de(s32, u32);
extern Node_func_80251F6C_de *func_802514A8_de(s32, u32);
extern void func_80254AD0_de(s32, Node_func_80251F6C_de *);
extern void func_80254C70_de(s32, Node_func_80251F6C_de *);
extern void func_80255ED8_de(void *, void *);
extern s32 func_80255D14_de(IntrusiveList *, void *);
extern void func_80255170_de(void *, Request_func_80251F6C_de *);
extern Request_func_80251F6C_de *func_80252774_de(s32, Request_func_80251F6C_de *, s32);
extern void func_80254E88_de(s32, Request_func_80251F6C_de *);
extern void func_8025637C_de(struct CartridgeReadWorker *, void *, s32, void *);
extern void func_80256454_de(struct CartridgeReadWorker *, void *, s32, void *, void *, void *, s32);

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
static inline void find(u32 key, Request_func_80251F6C_de **out) {
    HashNode_func_80251F6C_de *node = D_80101194 + (((key<<5)^(key>>1)^(key>>9)^(key>>17))&D_80101190);
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
static inline void addref(Node_func_80251F6C_de *node) {
    node->count++;
    node->flags |= 0x100;
}
static inline void stamp(Node_func_80251F6C_de *node) {
    node->stamp=D_80105180;
    func_80255FB8_de(&D_80100570,node);
}
static inline Node_func_80251F6C_de *allocate(u32 size, u32 flags) {
    Node_func_80251F6C_de *node=func_802514A8_de(0,flags);
    if (node!=0) {
        addref(node);
        node->data=func_80254B8C_de(0,size,(flags>>5)&1,flags);
        if (node->data!=0) {
            node->unk04=size;
            node->flags |= flags;
            func_80254C70_de(0,node);
        } else {
            if (--node->count==0) node->flags &= ~0x100;
            func_80254AD0_de(0,node);
            node=0;
        }
    }
    return node;
}
Node_func_80251F6C_de *func_8025193C_de(s32 unused, u32 key, void *source, u32 size,
                          u32 mode, void *owner, void *tag, void *spare, u32 direct) {
    Request_func_80251F6C_de *request;
    Request_func_80251F6C_de *scan;
    Request_func_80251F6C_de *resolved;
    Node_func_80251F6C_de *node;
    u32 flags;
    u32 oldFlags;
    s32 busy;

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
    if (direct==0) {
        scan=D_801047E0.active.head;
        while(scan!=0) {
            if(scan->key==key && size<=(u32)scan->priority) {busy=1;break;}
            scan=scan->next;
        }
    }
    if(direct==0) { if(busy) goto failed; }
    else busy=0;
    request=func_80254ED0_de(busy,mode);
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
            request->unk14=tag;
            request->mode=mode;
            func_80255ED8_de(&D_801047E0.pending,request);
            func_80255D14_de(&D_801047E0.active,request);
            if(direct!=0) {
                if(tag!=0) request->flags |= 4;
                release();
                func_8025637C_de(&D_801011B8,source,size,request->node->data);
                if(tag!=0) func_80255170_de(D_80106248,request);
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
                func_80256454_de(&D_801011B8,source,size,request->node->data,&D_801047E0,request,0);
                return 0;
            }
        }
        func_80254E88_de(0,request);
    }
failed:
    release();
    return 0;
}
