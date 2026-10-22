#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#define SG(p, t, o) (*(t *)((u8 *)(p) + (o)))
#define CS(n) ((n) + 5)
extern u8 *D_800E54A4;
extern s32 D_800E54A0, D_800DF4C4, D_800DF4C0;
extern s8 D_80102B0D[], D_800FEB0E[];
extern u8 D_801462C8_raw[];
extern void *func_8025305C_de(), *func_8040EC30_de(), *func_80419E54_de();
extern s32 func_8041B610_de(), func_80404F04_de();
extern void func_8043C210_de(), func_8041B6E8_de(), func_8040E8D8_de(), func_80433BCC_de(), func_804322AC_de(), func_80264770_de();
extern void func_8022EF30_de(), func_802A001C_de(), func_80404E28_de(), func_8040C428_de(), func_802A2394_de(), func_802A2418_de(), func_8025DF34_de();
/* Builds the four-slot player setup screen (0x3474-byte state D_800E54A4, slot records 0xB68 apart): the window and its four
   rows, the scroll items for each slot, then clears or assigns each slot's mode words from the controller and profile state
   of the screen mode at 0x54 (modes 5, 6 and 7 differ), and finally starts the screen sound. Returns 0. */
s32 func_8042FD3C_eu_x(void *root) {
    u8 *g;
    u8 *it;
    s32 i, j, k, v;
    s32 mode;

    g = func_8025305C_de(0x3474);
    D_800E54A4 = g;
    SG(g, void *, 0) = root;
    func_8043C210_de(g + 8, 0x67, 0, 0, 0);
    SG(g, s32, 4) = func_8041B610_de(root, 4);
    for (i = 0; i < 4; i++) {
        func_8041B6E8_de(root, i, CS(0x285));
    }
    for (i = 3; i >= 0; i--) {
        SG(g, s32, 0x38 + 4 * i) = 0;
    }
    SG(g, s32, 0x4C) = 1;
    SG(g, s32, 0x50) = 4;
    it = func_8040EC30_de(root, CS(0x2FB));
    SG(g, u8 *, 0x3C) = it;
    SG(it, u16, 0x14) -= SG(it, u16, 0x18);
    v = SG(it, s16, 0x18);
    SG(g, s32, 0x40) = (v < 0 ? v + 3 : v) >> 2;
    SG(it, u16, 0x14) += SG(it, s16, 0x18) - (SG(g, s32, 0x40) << 2);
    it = func_8040EC30_de(root, CS(0x2A2));
    SG(g, u8 *, 0x44) = it;
    SG(it, u16, 0x14) += SG(it, u16, 0x18);
    v = SG(it, s16, 0x18);
    SG(g, s32, 0x48) = (v < 0 ? v + 3 : v) >> 2;
    SG(it, u16, 0x14) -= SG(it, s16, 0x18) - (SG(g, s32, 0x48) << 2);
    for (i = 0; i < 4; i++) {
        it = func_8040EC30_de(root, CS(0x286));
        SG(it, u8, 0x10) = 0x6E;
        SG(g, void *, 0x24) = func_80419E54_de(CS(0x287), 0xFF);
        it = func_8040EC30_de(root, CS(0x287));
        SG(g, u8 *, 0x28) = it;
        func_8040E8D8_de(it, 0);
        SG(g, u8 *, 0x68 + 0xB68 * i) = func_8040EC30_de(root, CS(0x2FC));
        SG(g, u8 *, 0xBD0 + 0xB68 * i) = func_8040EC30_de(root, CS(0x2A3));
        SG(g, u8 *, 0x1738 + 0xB68 * i) = func_8040EC30_de(root, CS(0x2FD));
        SG(g, u8 *, 0x22A0 + 0xB68 * i) = func_8040EC30_de(root, CS(0x2FA));
        SG(g, s32, 0x54) = D_800E54A0;
        SG(g, s32, 0x2DF8 + 0xC * i) = -1;
        SG(g, s32, 0x2DFC + 0xC * i) = 0;
        SG(g, s32, 0x2E00 + 0xC * i) = 2;
    }
    mode = SG(g, s32, 0x54);
    switch (mode) {
    case 0: it = func_8040EC30_de(root, CS(0x293)); break;
    case 1: it = func_8040EC30_de(root, CS(0x296)); break;
    case 2: it = func_8040EC30_de(root, CS(0x288)); break;
    case 3: it = func_8040EC30_de(root, CS(0x2A1)); break;
    case 4: it = func_8040EC30_de(root, CS(0x295)); break;
    case 5:
        it = func_8040EC30_de(root, CS(0x289));
        func_8040E8D8_de(it, 1);
        SG(it, u8, 0x10) = 0xFF;
        for (i = 0, j = 0; i < 4; i++) {
            if (D_80102B0D[i * 0x190 - 1 + 1] >= 0 && D_80102B0D[i * 0x190 + 1] == 1) {
                D_80102B0D[i * 0x190] = -1;
                D_80102B0D[i * 0x190 + 1] = 0;
                if (D_80102B0D[i * 0x190] < 0) {
                    SG(g, s32, 0x2DF8 + 0xC * j) = 0;
                    SG(g, s32, 0x2DFC + 0xC * j) = i;
                    SG(g, s32, 0x2E00 + 0xC * j) = 1;
                }
            }
            j++;
        }
        func_80433BCC_de(-1);
        break;
    default:
        it = func_8040EC30_de(root, CS(0x297));
        func_8040E8D8_de(it, 1);
        SG(it, u8, 0x10) = 0xFF;
        break;
    }
    for (i = 0; i < 4; i++) {
        SG(g, s32, 0x58 + 0xB68 * i) = 0;
        SG(g, s32, 0x64 + 0xB68 * i) = 0;
        SG(g, s32, 0x6C + 0xB68 * i) = -1;
        func_804322AC_de(i);
        func_80264770_de(i);
        for (j = 0; j < 4; j++) {
            func_8022EF30_de(g + 0xB68 * i + 0x18 + 0x190 * j);
        }
        for (j = 0; j < 16; j++) {
            func_802A001C_de(g + 0xB68 * i + 0x658 + 0x46 * j + 0x28, 0, 0x14);
            func_802A001C_de(g + 0xB68 * i + 0x658 + 0x46 * j + 0x3C, 0, 0xA);
        }
        func_802A001C_de(g + 0xB68 * i + 0xACC, 0, 0xA);
        func_802A001C_de(g + 0xB68 * i + 0xAC2, 0, 0xA);
        func_802A001C_de(g + 0xB68 * i + 0xAB8, 0, 0xA);
        for (k = 0; k < 4; k++) {
            SG(g, s32, 0xB30 + 0xB68 * i + 4 * k) = 0;
            SG(g, s32, 0xB44 + 0xB68 * i + 4 * k) = 0;
            SG(g, s32, 0xB48 + 0xB68 * i + 4 * k) = 2;
            SG(g, s32, 0xB58 + 0xB68 * i + 4 * k) = 0;
        }
        SG(g, s32, 0xB84 + 0xB68 * i) = 0;
        SG(g, s32, 0xB88 + 0xB68 * i) = 0;
        SG(g, s32, 0xBBC + 0xB68 * i) = 0;
        SG(g, s32, 0x5C + 0xB68 * i) = 0;
        SG(g, s32, 0x60 + 0xB68 * i) = -1;
        SG(g, s32, 0xB80 + 0xB68 * i) = -1;
    }
    SG(g, s32, 0x3470) = -1;
    if (SG(g, s32, 0x54) == 5) {
        for (i = 0; i < 4; i++) {
            if (D_800FEB0E[i] == 0 && D_80102B0D[i * 0x190 - 1] >= 0 && D_801462C8_raw[0x148 + 0x96 * i] == 1 &&
                D_801462C8_raw[0x161 + 0x96 * i] == 0) {
                s32 p = D_80102B0D[i * 0x190 - 1];
                SG(g, s32, 0xB68 * p + 0x6C) = 2;
                SG(g, s32, 0xB68 * p + 0x58) = 2;
                SG(g, s32, 0xB68 * p + 0x60) = 6;
            }
        }
        for (i = 0; i < 4; i++) {
            func_804322AC_de(i);
        }
    } else if (SG(g, s32, 0x54) == 6) {
        if (D_800DF4C4 == 0) {
            for (i = 0; i < 4; i++) {
                func_80404E28_de(i);
                v = func_80404F04_de(i);
                if (v >= -4 && v < -2 || v == -2 || v == -1) {
                    SG(g, s32, 0xB68 * i + 0x6C) = 2;
                    SG(g, s32, 0xB68 * i + 0x58) = 2;
                    SG(g, s32, 0xB68 * i + 0x60) = 4;
                    func_804322AC_de(i);
                }
            }
        } else {
            func_80404E28_de(D_800DF4C0);
            v = func_80404F04_de(D_800DF4C0);
            if (v >= -4 && v <= 0) {
                SG(g, s32, 0xB68 * D_800DF4C0 + 0x6C) = 2;
                SG(g, s32, 0xB68 * D_800DF4C0 + 0x58) = 2;
                SG(g, s32, 0xB68 * D_800DF4C0 + 0x60) = 4;
            }
        }
    } else if (SG(g, s32, 0x54) == 7) {
        SG(g, s32, 0x6C) = 2;
        SG(g, s32, 0x58) = 2;
        SG(g, s32, 0x60) = 0xD;
        SG(g, s32, 0x5C) = 0;
        func_804322AC_de(0);
    }
    func_8040C428_de(0);
    func_802A2394_de();
    func_802A2418_de(0);
    func_8025DF34_de(0xE78);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8042FD3C_eu_x);
#endif
#endif
