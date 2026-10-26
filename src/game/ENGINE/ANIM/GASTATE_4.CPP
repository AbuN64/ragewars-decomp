#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"

char *func_80262564_de(void *animationState) {
    return Render_GetPackSection(Render_GetPackSection(func_8026049C_de(animationState), 3), 0);
}

s32 func_80262598_de(void *animationState) {
    return Render_GetPackSection(func_8026049C_de(animationState), 4) + 8;
}

s32 func_802625C4_de(void *animationState) {
    return (((struct func_80203E78_S1 *) ((s8 *) Render_GetPackSection(func_8026049C_de(animationState), 4)))->unk4);
}
