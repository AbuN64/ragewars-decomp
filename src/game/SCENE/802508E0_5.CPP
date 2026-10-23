#include "COMMON/MANAGER.H"
#include "SCENE/802508E0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/802508E0_5.H"
#include "sdk/os.h"
#include "TEXTURE/80254CE4.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

/* Looks a key up in the request hash table under the manager lock: an existing request bumps its
   node's reference count and flags, stamps it and hands the node to func_80255FB8_de; otherwise, unless
   a request for the key is already active, a fresh request is taken, filled in from the arguments,
   given a reference on each of the two nodes and moved to the active list. Outside the lock the
   request is then either started asynchronously through func_80255170_de and func_80252774_de, or run
   synchronously through func_802551FC_de, whose failure gives the two references back and finishes the
   request. The lock, the hash lookup and the reference bump are the inline forms of func_802524B0_de,
   func_802517B4_de and func_80252774_de. The eighth argument is never read.

   Manager is one object, which is what lets the compiler reach its lock queue from whichever of its
   members is already in a base register; D_8010515C is a separate symbol although it lies past the
   members named here, because every reference to it materialises its own address. */











extern s32 D_80100570;

extern s32 D_80105180;

extern s32 D_80101190;

extern s32 D_80101194;

extern u32 func_802BCF30_de(void);



extern ResourceLoadRequest *func_80254ED0_de(s32, s32);

extern void func_80255170_de(s32 *, ResourceLoadRequest *);

extern void func_80255FB8_de(void *, CachedResource *);

extern ResourceLoadRequest *func_80252774_de(s32 unused, ResourceLoadRequest *request, s32 dropReference);

static inline void addref(CachedResource *node) {
    node->count += 1;
    node->flags |= 0x100;
}

static inline void stamp(CachedResource *node) {
    node->stamp = D_80105180;
    func_80255FB8_de(&D_80100570, node);
}

static inline void unref(CachedResource *node) {
    if (--node->count == 0) {
        node->flags &= ~0x100;
    }
}

static inline void acquire(void) {
    extern Manager D_801047E0;
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C + 1;

    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        func_802BB2A0_de(D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(token);
    }
}

static inline void release(void) {
    extern Manager D_801047E0;
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C - 1;

    D_8010515C = counter;
    if (counter != 0) {
        __osRestoreInt(token);
        func_802BB420_de(D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(token);
    }
}

/* Runs the resource manager thread: waits for messages on its queue D_801047E0 and, under the manager lock, frees the heap for messages 0 and 1, retries or completes a pending load request (flag 8) by unlinking it, draining its node's reference count, releasing an unused node's data and handle, and finishing the request, or otherwise (flag 4) starts it through func_80252774_de. The flag 8 path clears its reference loop with an inner do-while, and each branch unlocks itself. */









extern char D_801051A0;

extern void func_80254F9C_de(s32, Request_func_802524B0_de *);
extern s32 func_802551FC_de(void *, void *, Manager *);
extern s32 D_80106248;

extern void func_80254DD0_de(s32, Node_func_802524B0_de *);

extern void func_80255B2C_de(void *, void *);

extern void func_80254AD0_de(s32 arg0, s32 arg1);

static inline void lock(void) {
    extern Manager D_801047E0;
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C + 1;

    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        func_802BB2A0_de(D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(token);
    }
}

static inline void unlock(void) {
    extern Manager D_801047E0;
    u32 token = func_802BCF30_de();
    s32 counter = D_8010515C - 1;

    D_8010515C = counter;
    if (counter != 0) {
        __osRestoreInt(token);
        func_802BB420_de(D_801047E0.lock, 0, 1);
    } else {
        __osRestoreInt(token);
    }
}

CachedResource *func_80251F6C_de(s32 unused, s32 key, CachedResource *first, CachedResource *second, s32 mode, void *owner,
                    void *tag, void *spare, s32 async) {
    extern Manager D_801047E0;
    ResourceHashEntry *node;
    ResourceLoadRequest *found;
    ResourceLoadRequest **out;
    ResourceLoadRequest *scan;
    s32 busy;

    acquire();

    out = &found;
    node = (ResourceHashEntry *)((s32)D_80101194 +
        ((((key << 5) ^ ((u32)key >> 1) ^ ((u32)key >> 9) ^
           ((u32)key >> 17)) & D_80101190) * 0x10));
    if (node->key != key) {
        goto not_initial;
    }
    found = node->value;
    goto done;
loop_found:
    *out = node->value;
    goto done;
not_initial:
    found = 0;
    if (node == 0) {
        goto done;
    }
loop:
    if (node->key == key) {
        goto loop_found;
    }
    node = node->next;
    if (node != 0) {
        goto loop;
    }
done:

    busy = 0;
    if (found != 0) {
        addref(found->node);
        stamp(found->node);
        release();
        return found->node;
    }

    async |= D_801047E0.mask;
    scan = D_801047E0.active.head;
    while (scan != 0) {
        if (scan->key == key) {
            busy = 1;
            break;
        }
        scan = scan->next;
    }
    if (busy == 0) {
        found = func_80254ED0_de(0, mode);
        if (found != 0) {
            found->key = key;
            found->priority = 0;
            found->owner = (s32)owner;
            found->tag = tag;
            found->mode = mode;
            found->node = first;
            found->extra = second;

            if (first != 0) {
                addref(first);
            }
            if (second != 0) {
                addref(second);
            }

            func_80255ED8_de(&D_801047E0.pending, found);
            func_80255D14_de(&D_801047E0.active, found);
            release();

            if (async != 0) {
                found->flags &= ~0xE;
                func_80255170_de(&D_80106248, found);
                acquire();
                found = func_80252774_de(0, found, 0);
                release();
                if (found != 0) {
                    return found->node;
                }
                return 0;
            }

            if (func_802551FC_de(&D_80106248, found, &D_801047E0) == 0) {
                acquire();
                if (first != 0) {
                    unref(first);
                }
                if (second != 0) {
                    unref(second);
                }
                func_80255ED8_de(&D_801047E0.active, found);
                func_80255CB8_de(&D_801047E0.pending, found);
                func_80254E88_de(0, found);
                release();
            }
            return 0;
        }
    }
    release();
    return 0;
}

void func_802524B0_de(void *arg) {
    extern Manager D_801047E0;
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
