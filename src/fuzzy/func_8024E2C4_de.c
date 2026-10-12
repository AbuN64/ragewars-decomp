#include "types.h"

typedef struct {
    u32 unk0;
} JtblValStruct;

typedef struct {
    u8 pad0[0x18];
    JtblValStruct *unk18;
} JtblSwitchArg;

s32 func_8024E2C4_de(void *arg0) {
    switch (((JtblSwitchArg *)arg0)->unk18->unk0) {
        case 1:
        case 4:
        case 9:
        case 0xB:
            return 0;
        case 0:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 0xA:
        case 0xC:
        case 0xD:
        case 0xE:
        default:
            return 1;
    }
}
