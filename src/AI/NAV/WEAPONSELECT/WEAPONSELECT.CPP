#include "COMMON/NAVIGATION_ACTOR_SEARCH_VIEWS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S2.H"
#include "GAME/WEAPONSELECT.H"
#include "TYPES.H"
#include "COMMON/SELF.H"

/* Picks a computer player's next weapon: in state 14 defers to Nav_RequestRandomArmedWeapon; otherwise gathers the loaded weapons it carries (slot kinds from 0x4C3, with ammunition and allowed by Nav_IsWeaponAllowed_de), filtering the specials by the record's weapon mode (mode 0 or an unknown mode, reset to 0, skips class-1 weapons and treats kind 6 as 5; modes 0 and 1 skip class-2 weapons; mode 2 allows all), and unless it already holds one of them and should keep it (holding kind 4 in gear 2, Particle_CountOwnerListOneEffects reporting a threat, or a 79 percent roll through Nav_RollRandom_de) chooses one at random into 0x770, clearing the brain's switch timer at 0x2E4 when it changes. */









extern WeaponInfo *g_weaponInfoByType[];

extern char g_actorParticleEffectSystem[];

extern void Nav_RequestRandomArmedWeapon(WeaponSelectBrain *);

extern s32 Playerai_PlayerHasAmmoForWeapon(SharedPlayer *, s32);

extern s32 Particle_CountOwnerListOneEffects(char *, SharedPlayer *);


extern void Nav_SelectAvailableWeapon(WeaponSelectBrain *, s32 *);

void Nav_SelectAvailableWeapon(WeaponSelectBrain *brain, s32 *ammo) {
    s32 choices[8];
    u32 count;
    s32 holding;
    u32 i;
    s32 weapon;
    s32 pick;

    if (brain->player->views1450.view1450_1.computer == 0) {
        return;
    }
    if (brain->player->views5DC.view5E0_9.state == 14) {
        Nav_RequestRandomArmedWeapon(brain);
        return;
    }
    holding = count = 0;
    for (i = count; i < 8; i++) {
        weapon = brain->player->views18.view18_2.model->slots[i];
        weapon -= 1219;
        if (weapon < 0 || ammo[i] == 0 || Playerai_PlayerHasAmmoForWeapon(brain->player, weapon) == 0) {
            continue;
        }
        if ((u32)weapon >= 2) {
            switch (brain->player->views5D8.view5D8_1.record->difficulty) {
            case 1:
                goto second;
            case 0:
                break;
            case 2:
                goto add;
            default:
                brain->player->views5D8.view5D8_1.record->difficulty = 0;
                break;
            }
            if (*g_weaponInfoByType[weapon]->weaponClass == 1) {
                continue;
            }
            if (weapon == 6) {
                weapon = 5;
            }
        second:
            if (*g_weaponInfoByType[weapon]->weaponClass == 2) {
                continue;
            }
        }
    add:
        choices[count++] = weapon;
        if (weapon == brain->player->views5E8.view62E_14.weapon) {
            holding = 1;
        }
    }
    if (holding) {
        if (brain->player->views5E8.view62E_14.weapon == 4 && brain->player->views1C.view594_39.gear == 2) {
            return;
        }
        if (Particle_CountOwnerListOneEffects(g_actorParticleEffectSystem, brain->player) > 0) {
            return;
        }
        if (Graphu64_NextRandom() % 100 >= 21) {
            return;
        }
    }
    if (count == 0) {
        return;
    }
    pick = choices[Graphu64_NextRandom() % count];
    brain->player->views5E8.view770_92.nextWeapon = pick;
    if (pick != brain->player->views5E8.view62E_14.weapon) {
        brain->switchTimer = 0;
    }
}

int Nav_SelectWeaponFromFirstAmmoGroup(void *controller) {
    WeaponSelectBrain *brain = controller;
    char *ammo = brain->player->views18.view18_1.track;
    Nav_SelectAvailableWeapon(brain, ammo + 0x8C);
    return 1;
}

int Nav_SelectWeaponFromSecondAmmoGroup(void *controller) {
    WeaponSelectBrain *brain = controller;
    char *ammo = brain->player->views18.view18_1.track;
    Nav_SelectAvailableWeapon(brain, ammo + 0xAC);
    return 1;
}

int Nav_SelectWeaponFromThirdAmmoGroup(void *controller) {
    WeaponSelectBrain *brain = controller;
    char *ammo = brain->player->views18.view18_1.track;
    Nav_SelectAvailableWeapon(brain, ammo + 0xCC);
    return 1;
}

int Nav_SelectSecondAmmoGroupVariantOne(void *controller) {
    WeaponSelectBrain *brain = controller;
    char *ammo = brain->player->views18.view18_1.track;
    Nav_SelectAvailableWeapon(brain, ammo + 0xAC);
    return 1;
}

int Nav_SelectSecondAmmoGroupVariantTwo(void *controller) {
    WeaponSelectBrain *brain = controller;
    char *ammo = brain->player->views18.view18_1.track;
    Nav_SelectAvailableWeapon(brain, ammo + 0xAC);
    return 1;
}
