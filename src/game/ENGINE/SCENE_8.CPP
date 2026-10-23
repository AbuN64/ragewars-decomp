#include "COMMON/ITEMRECAT20V1.H"
#include "ENGINE/SCENE_7.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

void func_8028BD4C_de(void *arg0, s32 arg1) {
    u8 *temp_v0_2;
    void *temp_v0;
    temp_v0 = func_8028FDB4_de((((struct Field_void_80 *) ((s8 *) arg0))->value), 1);
    func_8028FDB4_de(temp_v0, 0);
    temp_v0_2 = func_8028FDB4_de(temp_v0, 1) + arg1;
    *temp_v0_2 -= 1;
}
