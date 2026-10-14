#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"
/* Runs the resource manager thread: waits for messages on its queue D_801047E0 and, under the manager lock, frees the heap for messages 0 and 1, retries or completes a pending load request (flag 8) by unlinking it, draining its node's reference count, releasing an unused node's data and handle, and finishing the request, or otherwise (flag 4) starts it through func_80252774_de. The flag 8 path clears its reference loop with an inner do-while, and each branch unlocks itself. */







extern Manager_func_802524B0_de D_801047E0;

extern char D_80106248;
extern char D_801051A0;

extern void func_802BB2A0_de(void *, void *, s32);
extern s32 func_802BB420_de(void *, s32, s32);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_80254F9C_de(s32, Request_func_802524B0_de *);
extern s32 func_802551FC_de(void *, Request_func_802524B0_de *, Manager_func_802524B0_de *);
extern void func_80255ED8_de(void *, Request_func_802524B0_de *);
extern void func_80255CB8_de(void *, Request_func_802524B0_de *);
extern void func_80254DD0_de(s32, Node_func_802524B0_de *);
extern void func_80255B2C_de(void *, void *);
extern void func_80254AD0_de(s32, Node_func_802524B0_de *);
extern void func_80254E88_de(s32, Request_func_802524B0_de *);
extern void func_80252774_de(s32, Request_func_802524B0_de *, s32);

static inline void lock(void) {
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C + 1;

    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de(D_801047E0.lock, 0, 1);
    } else {
        func_802BCF50_de(token);
    }
}

static inline void unlock(void) {
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C - 1;

    D_8010515C = counter;
    if (counter != 0) {
        func_802BCF50_de(token);
        func_802BB420_de(D_801047E0.lock, 0, 1);
    } else {
        func_802BCF50_de(token);
    }
}

void func_802524B0_de(void *arg) {
    Request_func_802524B0_de *request;
    Node_func_802524B0_de *node;
    s32 flags;

    for (;;) {
        func_802BB2A0_de(&D_801047E0, &request, 1);
        if ((u32)request < 2) {
            lock();
            func_80254F9C_de(0, request);
            unlock();
        } else {
            request->flags &= ~2;
            flags = request->flags;
            if (flags & 8) {
                request->flags = flags & ~8;
                if (func_802551FC_de(&D_80106248, request, &D_801047E0) == 0) {
                    lock();
                    func_80255ED8_de(&D_801047E0.active, request);
                    func_80255CB8_de(&D_801047E0.pending, request);
                    node = request->node;
                    node->flags &= ~2;
                    while (node->count != 0) {
                        do {
                        } while (--node->count != 0);
                        node->flags &= ~0x100;
                    }
                    if (!(node->flags & 0x702)) {
                        func_80254DD0_de(0, node);
                        func_80255B2C_de(&D_801051A0, node->data);
                        func_80254AD0_de(0, node);
                    }
                    func_80254E88_de(0, request);
                    unlock();
                }
            } else {
                request->flags = flags & ~4;
                lock();
                func_80252774_de(0, request, 1);
                unlock();
            }
        }
    }
}
