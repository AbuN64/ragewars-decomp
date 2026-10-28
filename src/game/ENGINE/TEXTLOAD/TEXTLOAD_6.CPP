#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/WORLD.H"
#include "ENGINE/SCENE_10.H"
#include "TEXTURE/80294C64_14.H"

/** Store two words into a two-word value. */
void Textload_SetResourceLocation(int *value, int first, int second) {
    value[0] = first;
    value[1] = second;
}

void Textload_LocateTextureResource(s32 *arg0, s32 arg1) {
    Scene_LocateTextureResource(&g_world, arg1, arg0, arg0 + 1);
}
