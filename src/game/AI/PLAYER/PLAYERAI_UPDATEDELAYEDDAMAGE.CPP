#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER/WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA.H"
#include "TYPES.H"

extern void Barrel_FillDamagePacket(void *packet, s32 damageSource, s32 damage, f32 radius, s32 damageFlags, s32 shield);
extern void Playerai_ApplyDamagePacket(void *attacker, void *damageState, void *packet);
extern f32 g_frameElapsedTime;
extern s32 g_gameSettings;






void Playerai_UpdateDelayedDamage(void *player) {
    Slot damage;
    f32 remainingDelay;
    f32 previousDelay;

    previousDelay = ((PlayerWeaponDelayStateView *)(player))->unk_11E4;
    if (previousDelay > 0.0f) {
        remainingDelay = previousDelay - g_frameElapsedTime;
        ((PlayerWeaponDelayStateView *)(player))->unk_11E4 = remainingDelay;
        if ((remainingDelay <= 0.0f) && !(g_gameSettings & 1)) {
            Barrel_FillDamagePacket(&damage,
                          ((PlayerWeaponDelayStateView *)(player))->unk_13E0,
                          ((PlayerWeaponDelayStateView *)(player))->unk_174 + 0x1900,
                          25.599998f, 0x4000, 0);
            Playerai_ApplyDamagePacket(player, &((PlayerWeaponDelayStateView *)(player))->unk_170, &damage);
        }
    }
}
