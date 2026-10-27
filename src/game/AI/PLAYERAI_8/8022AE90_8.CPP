#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "TYPES.H"

extern void Barrel_FillDamagePacket(void *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);
extern void func_80219A40_de(void *arg0, void *arg1, void *arg2);
extern f32 D_800D2988;
extern s32 D_801462C8;






void func_8022B8E0_de(void *player) {
    Slot damage;
    f32 remainingDelay;
    f32 previousDelay;

    previousDelay = ((ObjectState13E4 *)(player))->unk_11E4;
    if (previousDelay > 0.0f) {
        remainingDelay = previousDelay - D_800D2988;
        ((ObjectState13E4 *)(player))->unk_11E4 = remainingDelay;
        if ((remainingDelay <= 0.0f) && !(D_801462C8 & 1)) {
            Barrel_FillDamagePacket(&damage,
                          ((ObjectState13E4 *)(player))->unk_13E0,
                          ((ObjectState13E4 *)(player))->unk_174 + 0x1900,
                          25.599998f, 0x4000, 0);
            func_80219A40_de(player, &((ObjectState13E4 *)(player))->unk_170, &damage);
        }
    }
}
