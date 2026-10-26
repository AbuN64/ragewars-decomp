#include "COMMON/EXTERNS_18.H"
#include "COMMON/LONE/D_8014D6E0.H"
#include "COMMON/LONE/D_8014D5C0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern u8 D_8014D4B0;
extern u8 D_8014D5E0[];




u32 func_802B7F30_eu_x(Triple *motorContext) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = (u8 *)&D_80154110;
    if (D_800D8380[motorContext->z] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        func_802B9C14_de();
        D_8014D4B0 = 3;
        __osSiRawStartDma(1, &D_8014D5E0[motorContext->z << 6]);
        osRecvMesg(motorContext->y, 0, 1);
        __osSiRawStartDma(0, (u8 *)&D_80154110);
        osRecvMesg(motorContext->y, 0, 1);
        count = motorContext->z;
        if (count != 0) {
            i = 0;
            if (count > 0) {
                do {
                    i++;
                    source++;
                } while (i < count);
            }
        }
        saved = *(Block40 *)source;
        result = (saved.bytes[2] & 0xC0) >> 4;
        if ((result == 0) && ((func_802B8C88_de(&D_8014D6E0) & 0xFF) != saved.bytes[0x26])) {
            result = 4;
        }
        func_802B9C80_de();
        return result;
    }
}





u32 func_802B80F4_eu_x(Triple *motorContext) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = (u8 *)&D_80154110;
    if (D_800D8380[motorContext->z] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        func_802B9C14_de();
        D_8014D4B0 = 3;
        __osSiRawStartDma(1, &D_8014D4C0[motorContext->z << 6]);
        osRecvMesg(motorContext->y, 0, 1);
        __osSiRawStartDma(0, (u8 *)&D_80154110);
        osRecvMesg(motorContext->y, 0, 1);
        count = motorContext->z;
        if (count != 0) {
            i = 0;
            if (count > 0) {
                do {
                    i++;
                    source++;
                } while (i < count);
            }
        }
        saved = *(Block40 *)source;
        result = (saved.bytes[2] & 0xC0) >> 4;
        if ((result == 0) && ((func_802B8C88_de(&D_8014D5C0) & 0xFF) != saved.bytes[0x26])) {
            result = 4;
        }
        func_802B9C80_de();
        return result;
    }
}
#endif
