#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"





void func_80295F78_de(s32 **arg0, Shared_AnimInfo *animInfo) {
    s32 *temp_s0;
    s32 *tmp;

    temp_s0 = *arg0;
    if (*temp_s0 != 0) {
        animInfo->frame = Render_GetPackSection(temp_s0, 0);
        tmp = Render_GetPackSection(temp_s0, 1);
        animInfo->count = *tmp;
        tmp = Render_GetPackSection(temp_s0, 2);
        animInfo->unk4 = *tmp;
        return;
    }
    animInfo->frame = 0;
    animInfo->count = 0;
    animInfo->unk4 = 0;
}
