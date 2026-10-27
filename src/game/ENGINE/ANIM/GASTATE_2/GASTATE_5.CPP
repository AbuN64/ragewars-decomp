#include "include_asm.h"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/STREAM.H"
#include "GAME_2/8025E520.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"



extern s32 SetN64_LocatePackSection(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);


extern s32 func_802624D8_de(void *arg0);

extern ResourceEntry g_animationText[];

void func_802625F0_de(AnimRef *animationState, f32 framePosition) {
    s16 *base;
    s32 count;
    s32 currentAngleFrame;
    s32 followingAngleFrame;
    s32 nextAngleFrame;
    f32 b_term;
    f32 e_term;

    base = (s16 *)((ResidentDataChunk *)SetN64_GetPackSection(func_8026049C_de(animationState), 0))->data;
    count = (s16)animationState->count;
    nextAngleFrame = count - 1;
    currentAngleFrame = (s32) framePosition;
    followingAngleFrame = currentAngleFrame + 1;
    if (followingAngleFrame < nextAngleFrame) {
        nextAngleFrame = followingAngleFrame;
    }
    b_term = (f32) base[currentAngleFrame] * D_800C4258_de;
    e_term = (f32) base[nextAngleFrame] * D_800C4258_de;
    GraphU64_InterpolateWrappedValue(framePosition - (f32) currentAngleFrame, b_term, e_term);
}

s32 func_8026269C_de(void *animationState, s32 resourceTable, s32 resourceGroup, s32 animationId) {
    AnimRef *out = animationState;
    void *resource;
    ResourceEntry *entry;
    u16 value;
    s32 key;
    s32 resourceBytes;

    if (animationId == -1) {
        out->data = 0;
        return 0;
    }

    key = SetN64_LocatePackSection(resourceTable, resourceGroup, animationId, &resourceBytes);
    resource = Cache_RequestResource(0, key, key, resourceBytes, 4, animationState,
                            &D_0025F56C, g_animationText, 0);
    out->data = resource;
    if (!func_802624D8_de(animationState)) {
        return 0;
    }

    resource = func_8026049C_de(animationState);
    entry = SetN64_GetPackSection(resource, 0);
    value = entry->unk6;
    out->id = animationId;
    out->count = value;
    resource = SetN64_GetPackSection(resource, 3);
    out->span = ((ResourceEntry *)SetN64_GetPackSection(resource, 0))->unk2;
    return 1;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80262734[3] = {
    0x5F4D3230, 0x01000096, 0x08000800,
};
#endif
