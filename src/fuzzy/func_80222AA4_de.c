#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "TYPES.H"

extern void *D_800D052C[];

/* Check the ammo required by the selected primary or alternate weapon mode. */
s32 func_80222AA4_de(void *object, s32 weaponNumber)
{
    Player *player = object;
    s32 weapon = weaponNumber;
    s32 slot;
    WeaponInfo *definition;
    s16 *condition;

    definition = D_800D052C[weapon];
    if (player->gear == 1) {
        condition = definition->weaponClass;
    } else {
        condition = definition->alternateClass;
    }
    slot = condition != 0 ? condition[0] : -1;
    if (slot != -1) {
        if (player->gear == 2) {
            switch (weapon) {
            default:
                condition = ((WeaponInfo *)D_800D052C[weapon])->alternateClass;
                if (condition != 0) {
                    return player->ammo[slot] >= condition[3];
                }
                return -1;
            case 4:
                return player->ammo[slot] >= 48;
            case 3:
                return player->ammo[slot] >= 25;
            }
        }
        if (player->gear == 1) {
            switch (weapon) {
            default:
                condition = ((WeaponInfo *)D_800D052C[weapon])->weaponClass;
                if (condition != 0) {
                    return player->ammo[slot] >= condition[3];
                }
                return -1;
            case 4:
                return player->ammo[slot] >= 5;
            case 3:
                return player->ammo[slot] >= 3;
            }
        }
    }
    return -1;
}
