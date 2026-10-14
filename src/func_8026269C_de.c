#include "span_1000/code_8025E568.h"
#include "span_1000/code_802624A0.h"
#include "types.h"



extern s32 func_8028FE3C_de(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_802624D8_de(void *arg0);
extern void *func_8026049C_de(void *arg0);
extern ResourceEntry *func_8028FDB4_de(void *arg0, s32 arg1);

extern ResourceEntry D_800C41B0_de[];





s32 func_8026269C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    AnimRef *out = arg0;
    void *resource;
    ResourceEntry *entry;
    u16 value;
    s32 key;
    s32 sp28;

    if (arg3 == -1) {
        out->data = 0;
        return 0;
    }

    key = func_8028FE3C_de(arg1, arg2, arg3, &sp28);
    resource = func_8025193C_de(0, key, key, sp28, 4, arg0,
                            &D_0025F56C, D_800C41B0_de, 0);
    out->data = resource;
    if (!func_802624D8_de(arg0)) {
        return 0;
    }

    resource = func_8026049C_de(arg0);
    entry = func_8028FDB4_de(resource, 0);
    value = entry->unk6;
    out->id = arg3;
    out->count = value;
    resource = func_8028FDB4_de(resource, 3);
    out->span = func_8028FDB4_de(resource, 0)->unk2;
    return 1;
}
