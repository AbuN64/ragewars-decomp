#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MANAGER.H"
#include "TYPES.H"
#include "SCENE/802508E0_7.H"
#include "SCENE/802508E0_9.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "COMMON/AIPROFILE.H"
#include "include_asm.h"
#include "COMMON/STREAM.H"
#include "GAME/8025E520.H"
#include "COMMON/RESULTS.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"

/* GASTATE_3.CPP */
/** Initialize the compact record fields written by the VRAM 0x802624A0 leaf. */
void func_80262480_de(void *record) {
    ObjRecAt10V1 *record_record = record;
    record_record->unk4 = -1;
    record_record->unk6 = 0;
    record_record->unk0 = 0;
    record_record->unk8 = 0;
    record_record->unkA = 0;
    record_record->unkB = 1;
    record_record->unk10 = 0;
}

void func_802624A8_de(void *animationState) {
    Cache_UnlockResource(0, (struct Node80253610 *)(((struct func_8022BC04_S3 *) ((s8 *) animationState))->unk10));
    (((struct func_8022BC04_S3 *) ((s8 *) animationState))->unk10) = 0;
}

s32 func_802624D8_de(void *animationState) {
    func_8020D0CC_S2 *arg0_record = animationState;
    void *temp = arg0_record->unk10;
    if (temp == 0) {
        return 0;
    }
    return Cache_IsResourceRetained(temp) != 0;
}

void func_80262504_de(void *animationState, Six *recordOut) {
    Six *result = (Six *)SetN64_GetPackSection((void *)Polytrak2_GetResidentResource(animationState), 6);

    *recordOut = *result;
}

/* GASTATE_4.CPP */
char *func_80262564_de(void *animationState) {
    return SetN64_GetPackSection(SetN64_GetPackSection(Polytrak2_GetResidentResource(animationState), 3), 0);
}

s32 func_80262598_de(void *animationState) {
    return SetN64_GetPackSection(Polytrak2_GetResidentResource(animationState), 4) + 8;
}

s32 func_802625C4_de(void *animationState) {
    return (((struct func_80203E78_S1 *) ((s8 *) SetN64_GetPackSection(Polytrak2_GetResidentResource(animationState), 4)))->unk4);
}

/* GASTATE_5.CPP */
extern s32 SetN64_LocatePackSection(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

extern ResourceEntry g_animationText[];

void func_802625F0_de(AnimRef *animationState, f32 framePosition) {
    s16 *base;
    s32 count;
    s32 currentAngleFrame;
    s32 followingAngleFrame;
    s32 nextAngleFrame;
    f32 b_term;
    f32 e_term;

    base = (s16 *)((ResidentDataChunk *)SetN64_GetPackSection(Polytrak2_GetResidentResource(animationState), 0))->data;
    count = (s16)animationState->count;
    nextAngleFrame = count - 1;
    currentAngleFrame = (s32) framePosition;
    followingAngleFrame = currentAngleFrame + 1;
    if (followingAngleFrame < nextAngleFrame) {
        nextAngleFrame = followingAngleFrame;
    }
    b_term = (f32) base[currentAngleFrame] * D_800C4258_de;
    e_term = (f32) base[nextAngleFrame] * D_800C4258_de;
    Graphu64_InterpolateWrappedValue(framePosition - (f32) currentAngleFrame, b_term, e_term);
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

    resource = Polytrak2_GetResidentResource(animationState);
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
