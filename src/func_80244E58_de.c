#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80243A80.h"
#include "types.h"
/* Starts the round once: unless already started, optionally resets the lead player (func_8022E290_de and its
 * three counters) and the player group, then when a new target id is pending selects it through
 * func_8044D3E8_de and func_80286AA8_de, records the start time from func_8040332C_de, marks the round started with
 * no pending target and copies the viewport rectangle into the active camera as floats. */











extern func_80244E48_S1 *D_800E2830;


extern Group D_80145060;

extern struct { ObjRecAt2A8 *unk0; } D_80140FE8_de;
extern char D_8010EC90;


extern struct Shape_func_8021A2D4_de_2 D_801371D4;

extern struct Shape_func_8021A2D4_de_2 D_801371E4;
extern char D_801371E8;

extern struct Shape_func_8021A2D4_de_2 D_8013B2BC;
extern void func_8022E290_de(void *);
extern void func_80239B64_de(void *);
extern void func_80285D30_de(void *);
extern s32 func_8044D3E8_de(void *, Vec3Words *, s32, void *);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8040332C_de(void);

void func_80244E58_de(void) {
    Vec3Words origin;
    ObjRecAt2A8 *camera;
    Player *player;
    Group *group;
    s32 target;
    s32 found;
    Shared_World *table;

    target = D_800E2830->unkD8;
    if (D_800E2830->unk40 != 0) {
        return;
    }
    if (D_800E2830->unk54 != 0) {
        group = &D_80145060;
        player = group->lead;
        if (player != 0) {
            func_8022E290_de(player);
            player->weaponSpinStep = 0.0f;
            player->weaponSpin = 0.0f;
            player->weaponReset = 0;
        }
        func_80239B64_de(group->members);
        func_80285D30_de(&D_8010EC90);
    }
    if (target != -1) {
        table = &D_8011FE88;
        if (D_801371D4.field_0 != target) {
            origin.w[0] = 0;
            origin.w[1] = 0;
            origin.w[2] = 0;
            found = func_8044D3E8_de(table, &origin, target, &D_801371E8);
            D_8013B2BC.field_0 = found;
            D_801371E4.field_0 = found != 0;
            func_80286AA8_de(table, target, found != 0);
        }
    }
    D_800E2830->unk5C = func_8040332C_de();
    D_800E2830->unk50 = 1;
    D_800E2830->unkD8 = -1;
    D_800E2830->unk40 = 1;
    camera = D_80140FE8_de.unk0;
    if (camera != 0) {
        camera->unk29C = D_800E2830->unk108;
        camera->unk2A0 = D_800E2830->unk10C;
        camera->unk2A4 = D_800E2830->unk110;
        camera->unk2A8 = D_800E2830->unk114;
    }
}
