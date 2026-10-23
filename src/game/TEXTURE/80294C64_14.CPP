#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/WORLD.H"
#include "ENGINE/SCENE_10.H"
#include "TEXTURE/80294C64_14.H"

/** Store two words into a two-word value. */
void func_80295E78_de(int *value, int first, int second) {
    value[0] = first;
    value[1] = second;
}

void func_80295E84_de(s32 *arg0, s32 arg1) {
    func_8028C15C_de(&D_8011FE88, arg1, arg0, arg0 + 1);
}
