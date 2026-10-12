#include "types.h"

typedef struct DraftMessageOwner { char pad0[0x40]; char pool[1]; } DraftMessageOwner;
extern DraftMessageOwner D_80145088;
extern u8 D_8014AEB0;
extern s32 D_8014AEB8, D_8014AEBC, D_8014AEC0, D_8014AEC4, D_8014D068;
extern s32 D_800D2AE0, D_auto_800D2AE4, D_auto_800D2AE8, D_800D2AEC, D_800D2AF0;
extern s32 D_auto_800D2AF4, D_auto_800D2AF8, D_auto_800D2AFC;
extern s32 D_8010B3D8, D_800E28D4;
extern u8 D_800CA60C[], D_auto_800CA620[], D_auto_8014CFE8[];
extern f32 D_auto_800CA634;
extern void *func_80237E80_de(void *, void *, u8 *);
extern void func_80294CA0_us_rev1(void), func_802A84F8_de(void), func_802A8710_de(void);
extern void func_802A8F28_de(void *, s32, s32, s32, s32, s32, f32, f32);

void func_80294F1C_us_rev1(void)
{
    s32 previous, adjusted, remainder;
    f32 scale;

    if (D_800D2AE0 != 0) {
        if (D_8010B3D8 & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0 == 0) {
                    func_80237E80_de(&D_80145088, D_80145088.pool, D_800CA60C);
                    D_8014AEC4 = 1;
                } else {
                    func_80237E80_de(&D_80145088, D_80145088.pool, D_auto_800CA620);
                }
                D_auto_800D2AFC = 1;
                D_8014AEB0 = D_8014AEB0 == 0;
            }
        } else D_auto_800D2AFC = 0;
        if (D_8010B3D8 & 0x2000) {
            if (D_8010B3D8 & 0x200) {
                previous = D_800D2AEC++;
                if (previous >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AEC = 0;
                    D_8014AEC0--;
                }
            }
            if (D_8010B3D8 & 0x100) {
                previous = D_800D2AF0++;
                if (previous >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AF0 = 0;
                    D_8014AEC0++;
                }
            }
        } else {
            if (D_8010B3D8 & 0x200) {
                previous = D_auto_800D2AE4++;
                if (previous >= 3) {
                    adjusted = D_8014AEBC - 1;
                    remainder = (adjusted + D_8014AEB8) % D_8014AEB8;
                    D_8014AEC4 = 1;
                    D_8014AEBC = adjusted;
                    D_8014AEBC = remainder;
                    if ((f32)remainder < 0.0f) remainder = -remainder;
                    D_8014AEBC = remainder;
                    D_auto_800D2AE4 = 0;
                }
            }
            if (D_8010B3D8 & 0x100) {
                previous = D_auto_800D2AE8++;
                if (previous >= 3) {
                    adjusted = D_8014AEBC + 1;
                    remainder = (adjusted) % D_8014AEB8;
                    D_auto_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = adjusted;
                    D_8014AEBC = remainder;
                }
            }
            if (D_8010B3D8 & 0x400) {
                previous = D_auto_800D2AF4++;
                if (previous >= 3) {
                    adjusted = D_8014AEBC - 5;
                    remainder = (adjusted + D_8014AEB8) % D_8014AEB8;
                    D_8014AEBC = adjusted;
                    D_8014AEBC = remainder;
                    if ((f32)remainder < 0.0f) remainder = -remainder;
                    D_8014AEBC = remainder;
                    D_8014AEC4 = 1;
                    D_auto_800D2AF4 = 0;
                }
            }
            if (D_8010B3D8 & 0x800) {
                previous = D_auto_800D2AF8++;
                if (previous >= 3) {
                    adjusted = D_8014AEBC + 5;
                    remainder = (adjusted) % D_8014AEB8;
                    D_auto_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = adjusted;
                    D_8014AEBC = remainder;
                }
            }
        }
        D_8014D068++;
        if (D_8014AEC4) {
            func_80294CA0_us_rev1();
            D_8014AEC4 = 0;
        }
        func_802A84F8_de();
        scale = D_auto_800CA634;
        func_802A8710_de();
        func_802AAB68_de(scale, scale);
        func_802AAB3C_de(255, 255, 255, 200, 200, 200);
        func_802A8F28_de(D_auto_8014CFE8, 16, D_800E28D4 - 48, 255, 0, 0, scale, scale);
    }
}
