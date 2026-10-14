#include "span_16E000/code_804251F4.h"
#include "shared/func_80425674_de_layout.h"
#include "common/unused.h"

extern Shared_Game D_801462C8;
extern MatchRewardsRecord D_80102B00[];

extern s32 func_8022F5C4_de(char *, s32);
extern void func_8022F5A4_de(char *, s32);

s32 func_80425674_de(s32 p) {
    char *record;
    Shared_Game *settings;
    s32 given;

    record = (char *)&D_80102B00[p];
    settings = &D_801462C8;
    given = -1;
    if (settings->controllerMode == 1 && settings->humanWon == 1 && D_8015402C >= 0x23) {
        switch (settings->slots[p].kind) {
        case 0:
            if (func_8022F5C4_de(record, 0x11) == 0) {
                func_8022F5A4_de(record, 0x11);
                given = 0x11;
            }
            break;
        case 1:
            if (func_8022F5C4_de(record, 0x6) == 0) {
                func_8022F5A4_de(record, 0x6);
                given = 0x6;
            }
            break;
        case 2:
            if (func_8022F5C4_de(record, 0x3) == 0) {
                func_8022F5A4_de(record, 0x3);
                given = 0x3;
            }
            break;
        case 3:
            if (func_8022F5C4_de(record, 0x4) == 0) {
                func_8022F5A4_de(record, 0x4);
                given = 0x4;
            }
            break;
        case 4:
            if (func_8022F5C4_de(record, 0xE) == 0) {
                func_8022F5A4_de(record, 0xE);
            }
            break;
        case 5:
            if (func_8022F5C4_de(record, 0x1) == 0) {
                func_8022F5A4_de(record, 0x1);
                given = 0x1;
            }
            break;
        case 6:
            if (func_8022F5C4_de(record, 0x12) == 0) {
                func_8022F5A4_de(record, 0x12);
                given = 0x12;
            }
            break;
        case 7:
            if (func_8022F5C4_de(record, 0x8) == 0) {
                func_8022F5A4_de(record, 0x8);
                given = 0x8;
            }
            break;
        case 8:
            if (func_8022F5C4_de(record, 0x9) == 0) {
                func_8022F5A4_de(record, 0x9);
                given = 0x9;
            }
            break;
        case 9:
            if (func_8022F5C4_de(record, 0xA) == 0) {
                func_8022F5A4_de(record, 0xA);
                given = 0xA;
            }
            break;
        case 17:
            if (func_8022F5C4_de(record, 0x2) == 0) {
                func_8022F5A4_de(record, 0x2);
                given = 0x2;
            }
            break;
        case 18:
            break;
        }
        if (func_8022F5C4_de(record, 0x11) == 1 && func_8022F5C4_de(record, 1) == 1 &&
            func_8022F5C4_de(record, 8) == 1 && func_8022F5C4_de(record, 0xB) == 0) {
            func_8022F5A4_de(record, 0xB);
        }
        if (func_8022F5C4_de(record, 2) == 1 && func_8022F5C4_de(record, 6) == 1 &&
            func_8022F5C4_de(record, 9) == 1 && func_8022F5C4_de(record, 0xC) == 0) {
            func_8022F5A4_de(record, 0xC);
        }
        if (func_8022F5C4_de(record, 3) == 1 && func_8022F5C4_de(record, 0x12) == 1 &&
            func_8022F5C4_de(record, 0xA) == 1 && func_8022F5C4_de(record, 0xD) == 0) {
            func_8022F5A4_de(record, 0xD);
        }
    }
    return given;
}
