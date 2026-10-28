#include "TYPES.H"
#include "COMMON/LONE/D_8014D6E0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

#if defined(VERSION_DE)

extern u8 D_8014D4B0;

extern u8 D_8014D5E0[];





unsigned char D_auto_func_802B7C48_de_padding_B8848[8] = { 0x00, 0x80, 0x88, 0x21, 0xAF, 0xBF, 0x00, 0x40 };

u32 func_802B7C50_de(Triple *motorContext) {
    Block40 saved;
    u8 *source;
    s32 i;

    source = (u8 *)&D_80154110;
    if (D_800D8380[motorContext->z] == 0) {
        return 5;
    } else {
        u32 result;
        s32 count;

        __osSiGetAccess();
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
        if ((result == 0) && ((__osContDataCrc(&D_8014D6E0) & 0xFF) != saved.bytes[0x26])) {
            result = 4;
        }
        __osSiRelAccess();
        return result;
    }
}
#endif
