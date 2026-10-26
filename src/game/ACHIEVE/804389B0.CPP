#include "include_asm.h"
#include "COMMON/LONE/D_800E4680.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/LEVEL_GOAL.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#define SG(p, t, o) (*(t *)((u8 *)(p) + (o)))
#define CS(n) ((n) + 5)
extern u8 *D_800E5830;
extern u8 D_801462C8_raw[], g_playerSettings[];
extern s32 D_8015402C;
extern s8 D_80102B0D[], D_800FEB0E[];
extern char *D_auto_800E2054[], *D_auto_800E20B4[], *D_auto_800E20A4[], *D_800E2044_eu[], *D_800E2074_eu[], *D_800E2094_eu[], *D_800E2084[], *D_auto_800E2034[];
extern u8 D_800FEB0F[], D_800FEB17[], D_800FEB4A[], D_800FEB54[], D_80102C24[], D_8010EB7D[], D_80142358[];
extern s32 D_8010EB94[], D_80146894;
extern void *Cache_AllocateMemory(), *Frontend_FindWidgetByResourceId(), *func_80425C70_de(), *Achieve_GetResultText();
extern s32 Defs_TestBit(), func_80425014_de(), func_80425674_de(), Frontend_FindKeyIndex();
extern void Frontend_SetWidgetFlag08(), Frontend_SetWidgetFlag100(), func_8043C210_de(), func_8043C278_de(), func_80438A88_de(), func_80425D14_de();
extern void Defs_SetBitValue(), XPlus_FillMemory(), func_804259E0_de(), XStdio_FormatBuffer(), XPlus_CopyString(), Achieve_UpdatePlayerPreviewStats(), func_80438614_de();
extern void func_8041B110_de(), Scene_CopyLevelName(), Tsmos_DeactivateControllerState();
extern char *XPlus_UppercaseString();
extern u8 D_800F00DC_raw[];
extern char g_world[];
/* Builds the results screen (0x1C8-byte state D_800E5830): window items, the first active profile, then per screen mode
   (1 single, 3 time trial, 4 team) the stage entry, its time/records and the heading texts in the current language.
   Returns 0. */
s32 func_804389B0_eu_x(void *root) {
    u8 *g;
    u8 *it;
    s32 i, v, label;
    u8 lang;
    u8 mode;
    u8 buf[0x40];

    g = Cache_AllocateMemory(0x1C8);
    D_800E5830 = g;
    SG(g, void *, 0x20) = root;
    Frontend_SetWidgetFlag08(root, 0);
    func_8043C210_de(g, 0x67, 0, 0, 0);
    func_8043C278_de(g);
    SG(g, s32, 0x1C) = 1;
    SG(Frontend_FindWidgetByResourceId(root, CS(0x26F)), u8, 0x10) = 0x6E;
    SG(Frontend_FindWidgetByResourceId(root, CS(0x274)), u8, 0x10) = 0x14;
    SG(Frontend_FindWidgetByResourceId(root, CS(0x271)), u8, 0x10) = 0x14;
    SG(Frontend_FindWidgetByResourceId(root, CS(0x284)), u8, 0x10) = 0x19;
    SG(g, s32, 0x94) = 0;
    for (i = 0; i < 4; i++) {
        if (g_playerSettings[0x78 + 0x96 * i] == 1) {
            SG(g, s32, 0x94) = i;
            break;
        }
    }
    func_80438A88_de();
    SG(g, s32, 0x98) = -1;
    lang = D_801462C8_raw[0x581];
    mode = D_801462C8_raw[0xD];
    if (mode == 1) {
        if (SG(D_801462C8_raw, s32, 0x680) == 1) {
            func_80425D14_de(SG(g, s32, 0x94));
            SG(g, s32, 0x9C) = -1;
            if (*D_800E4680 != 0 && Defs_TestBit(D_80102C24 + 1 + SG(g, s32, 0x94) * 0x98 + D_800FEB0F[SG(g, s32, 0x94) * 0x98] * 5, D_8015402C) == 1) {
                it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x282));
                Frontend_SetWidgetFlag08(it, 1);
                SG(it, u8, 0x10) = 0xAF;
                SG(it, char *, 0x38) = D_auto_800E2054[lang];
            } else {
                v = func_80425014_de(SG(g, s32, 0x94));
                SG(g, s32, 0x9C) = v;
                SG(g, void *, 0xAC) = Achieve_GetResultText(v);
                SG(g, s32, 0x98) = -1;
                switch (D_8015402C) {
                case 4: label = 0x2D; break;
                case 9: label = 0x2E; break;
                case 0x16: label = 0x2F; break;
                case 0x23: label = 0x30; break;
                default: label = -1; break;
                }
                if (label != -1 && Defs_TestBit(D_800FEB4A + SG(g, s32, 0x94) * 0x98, label) == 0) {
                    Defs_SetBitValue(D_800FEB4A + SG(g, s32, 0x94) * 0x98, label, 1);
                    func_804259E0_de(SG(g, s32, 0x94));
                    SG(g, s32, 0x98) = label;
                }
                if (D_800FEB17[SG(g, s32, 0x94) * 0x98] >= 0x12) {
                    Defs_SetBitValue(D_8010EB7D + SG(g, s32, 0x94) * 0x98, 1, 1);
                }
                if (D_800FEB17[SG(g, s32, 0x94) * 0x98] >= 0x24) {
                    Defs_SetBitValue(D_8010EB7D + SG(g, s32, 0x94) * 0x98, 2, 1);
                }
                if (D_8015402C >= 0x23) {
                    Defs_SetBitValue(D_800FEB54 + SG(g, s32, 0x94) * 0x98, D_80142358[SG(g, s32, 0x94) * 0x8C], 1);
                    XPlus_FillMemory(D_800FEB54 + 0x2A + SG(g, s32, 0x94) * 0x98, 0, 5);
                    v = func_80425674_de(SG(g, s32, 0x94));
                    if (v >= 0) {
                        i = Frontend_FindKeyIndex(v);
                        XStdio_FormatBuffer(g + 0x18C, D_auto_800E2034[lang], ((char **)SG(D_800F00DC_raw, char *, i * 0x70))[lang]);
                    }
                }
            }
        }
    } else if (mode == 3) {
        if (SG(D_801462C8_raw, s32, 0x5D8 + 0xA8) == 1) {
            func_80425D14_de(SG(g, s32, 0x94));
            v = (s32)func_80425C70_de(D_8015402C, 3, 0);
            SG(D_8010EB94, s32, 0) = SG(v, u8, 0x24) - (s32)(SG(D_801462C8_raw, f32, 0x5D8 + 0x14) * 1.0f);
            if (D_8015402C == 0x23) {
                it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x283));
                Frontend_SetWidgetFlag08(it, 1);
                SG(it, u8, 0x10) = 0xAF;
                SG(it, char *, 0x38) = D_auto_800E20B4[g_languageIndex];
            }
        }
    } else if (mode == 4) {
        if (SG(D_801462C8_raw, s32, 0x680) == mode) {
            func_80425D14_de(SG(g, s32, 0x94));
            if (D_8015402C == 0x23) {
                it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x283));
                Frontend_SetWidgetFlag08(it, 1);
                SG(it, u8, 0x10) = 0xAF;
                SG(it, char *, 0x38) = D_auto_800E20A4[lang];
            }
        }
    } else {
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, CS(0x273)), 0);
        goto tail;
    }
    XPlus_CopyString(g + 0x18C, D_800E2044_eu[lang]);
    it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x283));
    Frontend_SetWidgetFlag08(it, 1);
    SG(it, u8, 0x10) = 0xAF;
    SG(it, u8 *, 0x38) = g + 0x18C;
    Achieve_UpdatePlayerPreviewStats();
    Achieve_UpdatePlayerPreviewStats();
    func_80438614_de();
tail:
    func_8041B110_de(CS(0x272));
    func_8041B110_de(CS(0x273));
    func_8041B110_de(CS(0x277));
    Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, CS(0x273)), 1);
    for (i = 0; i < 4; i++) {
        if (D_80102B0D[i * 0x190] >= 0 && D_800FEB0E[i * 0x190] == 0) {
            break;
        }
    }
    it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x275));
    SG(it, char *, 0x38) = D_800E2074_eu[lang];
    it = Frontend_FindWidgetByResourceId(SG(g, void *, 0x20), CS(0x276));
    if (D_8014DD98.kind == 0) {
        SG(it, char *, 0x38) = D_800E2094_eu[lang];
    } else if (D_8014DD98.kind == 1) {
        SG(it, char *, 0x38) = D_800E2084[g_languageIndex];
    }
    it = Frontend_FindWidgetByResourceId(root, CS(0x270));
    Scene_CopyLevelName(g_world, D_8015402C, buf, 0x3F);
    XPlus_CopyString(g + 0x50, XPlus_UppercaseString(buf));
    SG(it, u8 *, 0x38) = g + 0x50;
    SG(g, void *, 0x24) = Frontend_FindWidgetByResourceId(root, CS(0x278));
    SG(g, s32, 0x1C0) = 1;
    D_80146894 = 1;
    Tsmos_DeactivateControllerState();
    SG(g, s32, 0x90) = 0;
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804389B0_eu_x);
#endif
#endif
