#include "COMMON/COLORENTRY.H"
#include "ENGINE/SCENE_7.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

char *func_8028D218_de(void *arg0, s32 index) {
    return Render_GetPackSection(Render_GetPackSection((((struct ObjRecAt7C *) ((s8 *) arg0))->unk7C), index), 0);
}
