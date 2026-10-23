#include "include_asm.h"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/STREAM.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"


extern f32 func_80273EE4_de(f32, f32, f32);

extern s32 func_8028FE3C_de(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);


extern s32 func_802624D8_de(void *arg0);

extern ResourceEntry D_800C41B0_de[];

void func_802625F0_de(AnimRef *arg0, f32 arg1) {
    s16 *base;
    s32 count;
    s32 temp_f2;
    s32 temp_a0;
    s32 var_v1;
    f32 b_term;
    f32 e_term;

    base = (s16 *)((ResidentDataChunk *)func_8028FDB4_de(func_8026049C_de(arg0), 0))->data;
    count = (s16)arg0->count;
    var_v1 = count - 1;
    temp_f2 = (s32) arg1;
    temp_a0 = temp_f2 + 1;
    if (temp_a0 < var_v1) {
        var_v1 = temp_a0;
    }
    b_term = (f32) base[temp_f2] * D_800C4258_de;
    e_term = (f32) base[var_v1] * D_800C4258_de;
    func_80273EE4_de(arg1 - (f32) temp_f2, b_term, e_term);
}

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
    out->span = ((ResourceEntry *)func_8028FDB4_de(resource, 0))->unk2;
    return 1;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80262734[3] = {
    0x5F4D3230, 0x01000096, 0x08000800,
};
#endif
