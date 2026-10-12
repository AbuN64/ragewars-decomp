#include "common/types_8a8189af7b05.h"
#include "types.h"

typedef struct DraftQuaternion { f32 x, y, z, w; } DraftQuaternion;
typedef struct DraftWeapon { char pad0[0x24]; s32 mode; char pad28[0x100]; Vec3 direction; } DraftWeapon;
typedef struct DraftWeaponState { u8 active; s8 state; } DraftWeaponState;
typedef struct DraftPlayer {
    char pad0[0x1C]; Vec3 position;
    char pad28[0x10]; u32 flags;
    char pad3C[0x104 - 0x3C]; f32 timer;
    char pad108[6]; u8 firing;
    char pad10F[0x48C - 0x10F]; s8 kind;
    char pad48D[0x594 - 0x48D]; s32 fireMode;
    char pad598[4]; s32 shots;
    char pad5A0[0x34]; s32 playerIndex;
    char pad5D8[4]; DraftWeapon *weapon;
    s32 weaponKind;
    char pad5E4[0x10]; u16 ammo[7]; DraftWeaponState weapons[22]; s16 currentWeapon;
    char pad630[0x20]; u16 state;
    char pad652[0x788 - 0x652]; s32 effectMode;
    char pad78C[8]; s32 effectId;
    char pad798[0x40]; DraftQuaternion aim;
    char pad7E8[0x84]; s32 animation;
    char pad870[0xBE0]; s32 controlled;
    char pad1454[4]; Vec3 effectPosition;
} DraftPlayer;
typedef struct DraftFireMode { s16 ammoIndex; s16 unk2; s16 effect; u16 cost; } DraftFireMode;
typedef struct DraftFireTable { char pad0[0x20]; DraftFireMode *single[3]; DraftFireMode *multi[3]; } DraftFireTable;
extern DraftFireTable *D_800D052C[];
extern s32 D_80140FF8;
extern s32 D_800FF140_de[];
extern s32 D_8011D8D0;
extern f32 D_800C2318_de, D_800C231C_de, D_800C2320_de, D_800C2324_de;
extern f32 D_800C2328_de, D_800C232C_de, D_800C2330_de, D_800C2334_de;
extern DraftQuaternion func_8024796C_de(void *);
extern DraftFireMode *func_8022AA9C_de(void *, s32);
extern void func_8022B144_de(void *, Vec3 *);
extern s32 func_802800C0_de(void *, void *, void *, void *, s32, s32, Vec3, DraftQuaternion, Vec3, Vec3 *, s32, s32);

void func_8021A9A4_de(void *arg0, s32 effect) {
    DraftPlayer *player = arg0;
    DraftWeapon *weapon;
    DraftFireMode *mode;
    DraftFireMode **entries;
    DraftQuaternion aim;
    Vec3 direction;
    Vec3 position;
    s32 i, found, value, extra, flags;
    f32 amount;
    u16 remaining;
    weapon = player->weapon;
    if (player->state < 2 || (s16)player->state == 0x10 || (s16)player->state == 0x11) return;
    aim = func_8024796C_de(player);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) player->fireMode = 2;
    mode = func_8022AA9C_de(player, player->currentWeapon);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) player->fireMode = 1;
    if (mode) {
        entries = D_800D052C[player->currentWeapon]->multi;
        if (!player->controlled && D_80140FF8 == 1) entries = D_800D052C[player->currentWeapon]->single;
        found = 0;
        for (i = 0; i < 3; i++, entries++) {
            if (!*entries) break;
            if ((*entries)->effect == effect) { found = 1; break; }
        }
        if (found) goto fire;
    }
    if (player->currentWeapon != 0 && player->currentWeapon != 0x10) goto spawn;
fire:
    if (weapon) aim = player->aim;
    if (player->currentWeapon != 0 && player->currentWeapon != 0x10) {
        remaining = player->ammo[mode->ammoIndex] - mode->cost;
        player->ammo[mode->ammoIndex] = remaining;
        if ((s16)remaining < 0) player->ammo[mode->ammoIndex] = 0;
        if ((s16)player->ammo[mode->ammoIndex] == 0) {
            if (player->weapons[player->currentWeapon].state == 3 || player->weapons[player->currentWeapon].state == 7) {
                player->weapons[player->currentWeapon].active = 0;
                player->weapons[player->currentWeapon].state = -1;
            }
        }
    }
    if (player->weaponKind == 0x11) {
        if (player->animation == 0x1004) amount = D_800C2318_de;
        else if (player->animation == 4000) amount = D_800C231C_de;
        else {
            if (player->kind == 8) player->animation = 0x1004;
            else player->animation = 4000;
            goto clear;
        }
        goto consume;
    }
    value = player->animation;
    if (value == 1) player->animation = 0x1130;
    else if (value == 0x1130) { amount = D_800C2320_de; goto consume; }
    else if (value == 0xA28) player->animation = 0x1135;
    else if (value == 0x1135) { amount = D_800C2324_de; goto consume; }
    else if (value == 0x14) player->animation = 0x1144;
    else if (value == 0x1144) { amount = D_800C2328_de; goto consume; }
    else if (player->currentWeapon == 0 && player->kind == 8) player->animation = 0x5E5E;
    else {
        value = player->animation;
        if (value == 0x5E5E) { amount = D_800C232C_de; goto consume; }
        if ((u32)(value - 0x5E24) < 3) player->animation = 0x5E56;
        else if (value == 0x5E56) goto ordinary;
        else if (value == 0x5E29) player->animation = 0x5E59;
        else if (value == 0x5E59) goto ordinary;
        else if (value == 0x5E2A) player->animation = 0x5E5A;
        else if (value == 0x5E5A) { amount = D_800C2330_de; goto consume; }
        else if (value == 0x5E2B) player->animation = 0x5E5B;
        else if (value == 0x5E5B) goto ordinary;
        else if (value == 0x5E2C) player->animation = 0x5E5C;
        else {
            value = player->animation;
            if (value == 0x5E5C) goto ordinary;
            if (value == 0x5E2D) player->animation = 0x5E5D;
            else if (value == 0x5E5D) goto ordinary;
            else { player->firing = 0; goto spawn; }
        }
    }
    goto clear;
ordinary:
    amount = D_800C2334_de;
consume:
    if (!(amount <= player->timer)) { player->firing = 0; goto spawn; }
    player->timer -= amount;
clear:
    player->firing = 0;
spawn:
    if (!weapon || weapon->mode == 1) func_8022B144_de(player, &direction);
    else direction = weapon->direction;
    position = player->position;
    extra = 0;
    if (player->effectMode == 2) extra = player->effectId;
    flags = 5;
    if (!(player->flags & 0x1000)) flags = 1;
    func_802800C0_de(&D_8011D8D0, player, player, 0, extra, effect, position, aim,
                     direction, &player->effectPosition, -1, flags);
    if (effect == 0x414 || effect == 0x42D) {
        value = player->shots - 1;
        if (value < 0) value = 0;
        player->shots = value;
    }
    if (player->currentWeapon != 9 && player->currentWeapon != 0x15 && player->currentWeapon != 0x14)
        D_800FF140_de[player->playerIndex]++;
}
