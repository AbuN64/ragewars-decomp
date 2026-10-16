#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80254CE4.h"
#include "TYPES.H"
#include "MAIN/80255280.H"
/* Activates a load request: moves it from the pending to the active list and, when its node is set, looks its key up in the request hash table; an existing request with lower priority is removed from the table and finished, releasing its node's data and node when nothing else holds them, while an existing request with at least the same priority wins and this request's node is released and the request finished, returning the existing one; otherwise, or after replacing, the request is inserted, owns its node and optionally drops the node's pending reference. The hash lookup and node release are the inline forms of func_802517B4_de's lookup and func_80254AD0_de. */







extern char D_80101120;
extern char D_801051A0;
extern s32 D_80100570;
extern struct { CachedResource **value; } D_80100564;
extern CachedResource *D_80100568;
extern struct { s32 value; } D_8010513C;
extern u32 D_80101190;
extern ResourceHashEntry *D_80101194;

extern void func_80255ED8_de(void *, void *);
extern void func_80255CB8_de(void *, void *);
extern void func_80254E88_de(s32, ResourceLoadRequest *);

extern void func_80255B2C_de(void *, void *);
extern void func_802553B4_de(s32, ResourceLoadRequest *);

static inline void find(s32 key, ResourceLoadRequest **out) {
    ResourceHashEntry *node = D_80101194 + (((key << 5) ^ ((u32)key >> 1) ^ ((u32)key >> 9) ^ ((u32)key >> 17)) & D_80101190);

    if (node->key == key) {
        *out = node->value;
        return;
    }
    *out = 0;
    while (node != 0) {
        if (node->key == key) {
            *out = node->value;
            return;
        }
        node = node->next;
    }
}




static inline void release(s32 node) {
    func_80255ED8_de(&D_80100570, (void *)node);
    if (((CachedResource *)node)->flags & 0x1000) {
        func_80255ED8_de(&((IntrusiveList *)&D_80100570)[1], (void *)node);
    }
    if (*(&D_80100570 - 2) == node) {
        *(&D_80100570 - 2) = 0;
    }
    ((CachedResource *)node)->flags = 0;
    D_80100564.value[D_8010513C.value] = (CachedResource *)node;
    *(&D_80100570 + 0x2F3) += 1;
}

ResourceLoadRequest *func_80252774_de(s32 unused, ResourceLoadRequest *request, s32 dropReference) {
    ResourceLoadRequest *existing;
    CachedResource *node;

    func_80255ED8_de(&D_80101120, request);
    func_80255CB8_de((char *)&D_80101120 - 0x14, request);
    if (request->node != 0) {
        find(request->key, &existing);
        if (existing != 0) {
            if (existing->priority < request->priority) {
                func_80255488_de(existing->key);
                existing->node->owner = 0;
                if (!(existing->node->flags & 0x702)) {
                    func_80255B2C_de(&D_801051A0, existing->node->data);
                    release((s32)existing->node);
                }
                func_80254E88_de(0, existing);
            } else {
                func_80255B2C_de(&D_801051A0, request->node->data);
                release((s32)request->node);
                func_80254E88_de(0, request);
                return existing;
            }
        }
        func_802553B4_de(request->key, request);
        request->node->owner = request;
        if (dropReference != 0) {
            node = request->node;
            if (--node->count == 0) {
                node->flags &= ~0x100;
            }
        }
        return request;
    }
    func_80254E88_de(0, request);
    return 0;
}
