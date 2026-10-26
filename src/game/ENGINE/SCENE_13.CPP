#include "COMMON/COLORENTRY.H"
#include "ENGINE/SCENE_7.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

char *Scene_GetPlatformRoute(void *world, s32 index) {
    return SetN64_GetPackSection(SetN64_GetPackSection((((struct ObjRecAt7C *) ((s8 *) world))->unk7C), index), 0);
}
