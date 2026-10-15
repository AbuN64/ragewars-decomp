#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "types.h"
#include "common/unused.h"

/* Polls the controller paks when they are enabled: after func_80285C78_de it tries to take the pak lock
 * D_8010FBC0 without blocking and, holding it, refreshes the four pak entries through func_80264104_de and
 * advances the pak state (state 0 opens the pak through func_802B74B0_de once func_80264728_de detects it,
 * otherwise closes it through func_802B7560_de; states 1 to 3 reset to 0 and close it), then releases the
 * lock. */

extern u8 D_800CBC10;
extern char D_8010EC90;
extern ControllerProfile D_8010F328[4];
extern u8 D_8010BBB8;
extern char D_8010FBC0;
extern char D_8010FC00;

extern s32 func_802BB420_de(void *, void *, s32);
extern s32 func_802BAD80_de(void *);
extern void func_80264104_de(void *);
extern void func_802B74B0_de(void *);
extern void func_802B7560_de(void *);

void func_80263AF4_de(void) {
    s32 locked;
    s32 i;

    if (D_800CBC10 != 0) {
        func_80285C78_de(&D_8010EC90);
        if ((locked = func_802BB2A0_de(&D_8010FBC0, 0, 0) == 0)) {
            D_800CBC1C = func_802BAD80_de(0);
        }
        if (locked) {
            func_80263740_de();
            for (i = 0; i < 4; i++) {
                func_80264104_de(&D_8010F328[i]);
            }
            switch (D_8010BBB8) {
            case 0:
                if (func_80264728_de() != 0) {
                    D_8010BBB8 = 1;
                    func_802B74B0_de(&D_8010FC00);
                } else {
                    func_802B7560_de(&D_8010FC00);
                }
                break;
            case 1:
            case 2:
            case 3:
                D_8010BBB8 = 0;
                func_802B7560_de(&D_8010FC00);
                break;
            }
            D_800CBC1C = -1;
            func_802BB420_de(&D_8010FBC0, 0, 1);
        }
    }
}

/* Updates the state of the four controller ports: a port whose device is gone clears all three flags; a port whose device responds is marked ready, turning a pending reconnection into a reconnect event; a ready port that stops responding is marked pending. */





void func_80263C24_de(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_8026475C_de(i) != 0) {
            if (func_80264634_de(i) != 0) {
                D_8010B310[i] = 1;
                if (D_8010BC28[i] != 0) {
                    D_8010BBF0[i] = 1;
                    D_8010BC28[i] = 0;
                }
            } else if (D_8010B310[i] != 0) {
                D_8010BC28[i] = 1;
            }
        } else {
            D_8010BBF0[i] = 0;
            D_8010BC28[i] = 0;
            D_8010B310[i] = 0;
        }
    }
}

extern s32 func_80285AC4_de(void *arg0, void *arg1, s32 arg2);




void func_80263CF0_de(void *arg0) {
    char *o = (char *) arg0;
    s32 type;
    s32 bit;
    s32 bit2;
    s32 i;

    type = ((ObjectState224 *)(o))->unk_4;
    bit = ((D_8010FBE3[type * 4] >> 3) ^ 1) & 1;
    if (bit != 0 && ((ObjectState224 *)(o))->unk_0 == 0) {
        i = 0;
        ((ObjectState224 *)(o))->unk_4 = type;
        ((ObjectState224 *)(o))->unk_0 = 0;
        ((ObjectState224 *)(o))->unk_C8 = 0;
        ((ObjectState224 *)(o))->unk_CC = 0;
        ((ObjectState224 *)(o))->unk_220 = 0;
        ((ObjectState224 *)(o))->unk_8 = 0;
        ((ObjectState224 *)(o))->unk_C = 0;
        ((ObjectState224 *)(o))->unk_10 = 0;
        ((ObjectState224 *)(o))->unk_C4 = 0;
        ((ObjectState224 *)(o))->unk_C5 = 0;
        ((ObjectState224 *)(o))->unk_C6 = 0;
        ((ObjectState224 *)(o))->unk_C7 = 0;
        ((ObjectState224 *)(o))->unk_14 = 0;
        ((ObjectState224 *)(o))->unk_18 = 0;
        ((ObjectState224 *)(o))->unk_1C = 0;
        ((ObjectState224 *)(o))->unk_20 = 0;
        ((ObjectState224 *)(o))->unk_24 = 0;
        ((ObjectState224 *)(o))->unk_28 = 0;
        do {
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2C = 0;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2D = 0;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2E = 0x30;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2F = 0;
            i += 1;
        } while (i < 0x20);
        bit2 = ((D_8010FBE3[type * 4] >> 3) ^ 1) & 1;
        ((ObjectState224 *)(o))->unk_D0 = 0;
        ((ObjectState224 *)(o))->unk_D4 = 0;
        ((ObjectState224 *)(o))->unk_0 = bit2;
        func_80285AC4_de(o + 0x140, o + 0x16C, 3);
    }
    ((ObjectState224 *)(o))->unk_0 = bit;
}
