#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
#include "shared/func_80286080_de_closed.h"
#include "span_1000/code_8022E938.h"
#include "types.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_8021E2A0_de_closed.h"




void func_8022E948_de(Player *arg0) {
    u8 *ptr;

    ptr = &D_801462E5;
    if (*ptr != 0) {
        return;
    }
    if (*(s32 *)(ptr - 0x55) != 0) {
        if (arg0->inputFlags & 0x20) {
            return;
        }
    }
    if (!(arg0->actionFlags & 0x800)) {
        return;
    }
    if (arg0->toggle != 0) {
        arg0->toggle = 0;
        return;
    }
    arg0->toggle = 1;
}

void func_8022E9A8_de(Player *arg0) {
    u8 *ptr;
    WeaponInfo *temp_v0;
    s16 temp_a1;
    u16 temp_a1u;

    ptr = &D_801462E5;
    if (*ptr != 0) {
        return;
    }
    if (arg0->weaponLocked != 0) {
        if (arg0->weaponBusy != 0) {
            return;
        }
    }
    if (*(s32 *)(ptr - 0x55) != 0) {
        if (arg0->inputFlags & 0x20) {
            return;
        }
    }
    if (!(arg0->actionFlags & 0x200)) {
        return;
    }
    temp_v0 = D_800D052C[arg0->weapon];
    temp_a1 = temp_v0->alternate;
    temp_a1u = (u16)temp_v0->alternate;
    if (temp_a1 == -1) {
        return;
    }
    if (arg0->actions[temp_a1][0] != 0) {
        arg0->weapon = (s16)temp_a1u;
    }
}
