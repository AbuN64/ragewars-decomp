#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "RENDER/SETN64_GETPACKSECTION.H"





void Textload_ReadTextureAnimationInfo(s32 **arg0, Shared_AnimInfo *animInfo) {
    s32 *temp_s0;
    s32 *tmp;

    temp_s0 = *arg0;
    if (*temp_s0 != 0) {
        animInfo->frame = SetN64_GetPackSection(temp_s0, 0);
        tmp = SetN64_GetPackSection(temp_s0, 1);
        animInfo->count = *tmp;
        tmp = SetN64_GetPackSection(temp_s0, 2);
        animInfo->unk4 = *tmp;
        return;
    }
    animInfo->frame = 0;
    animInfo->count = 0;
    animInfo->unk4 = 0;
}
