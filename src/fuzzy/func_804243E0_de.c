#include "types.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "span_1000/code_80291054.h"
extern Shared_Game D_801462C8;
extern f32 D_800E16B0,D_800DD684,D_800DD688,D_800DD68C;
/* Two adjacent ROM float thresholds are consumed together. */
extern f32 D_800DD690[2];
extern u8 D_800FEB26[],D_800FEB4A[],D_8014222C;
extern s32 D_800FEB6C[][100],D_800FEB74[][100];
extern s32 func_80426274_de(void);
extern s32 func_80265650_de(void *,s32);
extern void func_80265688_de(u8 *,s32,s32);
/* The shared records retain these two-byte counters in their padding. */
static inline s16 configCounter(const func_8041F2A0_Config *p,s32 offset) { return *(s16 *)(p->pad0+offset); }
static inline s16 settingsCounter(const Shared_PlayerSettingsRecord *p) { return *(s16 *)(p->pad0+4); }
void func_804243E0_de(s32 arg0, s32 *arg1) {
    Shared_PlayerSettingsRecord *var_v1;
    func_8041F2A0_Config *temp_s6;
    s32 *var_s1;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s4;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    u8 *temp_s0;
    u8 *temp_s0_2;
    u8 *temp_s0_5;
    u8 *temp_s0_6;
    u8 *temp_s1;
    u8 *temp_s1_2;
    u8 *temp_s3;

    var_s2 = 0;
    arg1[0] = -1;
    arg1[1] = -1;
    if (func_80426274_de() != 0) {
        temp_s6 = &D_80146398[arg0];
        if (temp_s6->active == 1) {
            var_s0 = 0;
            if ((u8)temp_s6->pad79[0x18] == 0) {
                temp_s4 = arg0 * 0x190;
                temp_s3 = temp_s4 + D_800FEB4A;
                var_s1 = arg1;
                do {
                    if ((func_80265650_de(temp_s3, var_s0) == 0) && ((u8) *(D_800FEB26 + (var_s0 + temp_s4)) >= 2U)) {
                        func_80265688_de(temp_s3, var_s0, 1);
                        if (var_s2 < 2) {
                            *var_s1 = var_s0;
                            var_s1++;
                            var_s2 += 1;
                        }
                    }
                    var_s0 += 1;
                } while (var_s0 < 0x24);
                var_a0 = arg0 * 2;
                if (func_80265650_de((arg0 * 0x190) + D_800FEB4A, 0x24) == 0) {
                    var_a0_2 = 0;
                    if ((((u32) (D_8014222C - 1) < 5U) && (configCounter(temp_s6,4) >= 0xF)) || (((*(f32 *)&D_801468A0.pad10[4]) >= 0.0f) && (configCounter(temp_s6,4) >= 0xF) && (((f32) (s8)D_801462C8.unknown1F[5] - (f32) (s32) ((*(f32 *)&D_801468A0.pad10[4]) * D_800E16B0 * D_800DD684)) <= D_800DD688))) {
                        var_a0_2 = 1;
                    }
                    var_a0 = arg0 * 2;
                    if (var_a0_2 == 1) {
                        func_80265688_de((arg0 * 0x190) + D_800FEB4A, 0x24, 1);
                        if (var_s2 < 2) {
                            arg1[var_s2] = 0x24;
                            var_s2 += 1;
                        }
                        var_a0 = arg0 * 2;
                    }
                }
                var_v0 = arg0 * 2;
                if (func_80265650_de(((((var_a0 + arg0) * 8) + arg0) * 0x10) + D_800FEB4A, 0x25) == 0) {
                    var_a0_3 = 0;
                    if ((((u32) (D_8014222C - 1) < 0xAU) && (configCounter(temp_s6,4) >= 0x19)) || (((*(f32 *)&D_801468A0.pad10[4]) >= 0.0f) && (configCounter(temp_s6,4) >= 0x19) && (((f32) (s8)D_801462C8.unknown1F[5] - (f32) (s32) ((*(f32 *)&D_801468A0.pad10[4]) * D_800DD68C * D_800DD690[0])) <= D_800DD690[1]))) {
                        var_a0_3 = 1;
                    }
                    if (var_a0_3 == 1) {
                        func_80265688_de((arg0 * 0x190) + D_800FEB4A, 0x25, 1);
                        if (var_s2 < 2) {
                            arg1[var_s2] = 0x25;
                            var_s2 += 1;
                        }
                    }
                    var_v0 = arg0 * 2;
                }
                temp_s0 = ((((var_v0 + arg0) * 8) + arg0) * 0x10) + D_800FEB4A;
                var_v0_2 = arg0 * 2;
                if (func_80265650_de(temp_s0, 0x26) == 0) {
                    var_v0_2 = arg0 * 2;
                    if (configCounter(temp_s6,4) == 0) {
                        var_v0_2 = arg0 * 2;
                        if ((s8) D_801462C8.unknown1F[5] >= 0xA) {
                            var_v0_2 = arg0 * 2;
                            if ((s8) D_801462C8.unknown1F[6] >= 0x14) {
                                func_80265688_de(temp_s0, 0x26, 1);
                                if (var_s2 < 2) {
                                    arg1[var_s2] = 0x26;
                                    var_s2 += 1;
                                }
                                var_v0_2 = arg0 * 2;
                            }
                        }
                    }
                }
                temp_s0_2 = ((((var_v0_2 + arg0) * 8) + arg0) * 0x10) + D_800FEB4A;
                var_a0_4 = arg0 * 2;
                if (func_80265650_de(temp_s0_2, 0x27) == 0) {
                    var_a0_5 = arg0 * 3;
                    if (configCounter(temp_s6,0) >= 5) {
                        func_80265688_de(temp_s0_2, 0x27, 1);
                        if (var_s2 < 2) {
                            arg1[var_s2] = 0x27;
                            var_s2 += 1;
                        }
                        var_a0_4 = arg0 * 2;
                        goto block_43;
                    }
                } else {
block_43:
                    var_a0_5 = var_a0_4 + arg0;
                }
                var_v0_3 = arg0 * 2;
                if (func_80265650_de((((var_a0_5 * 8) + arg0) * 0x10) + D_800FEB4A, 0x28) == 0) {
                    var_v1 = D_801462C8.playerSettings;
                    var_v0_3 = arg0 * 2;
                    if ((s8) D_801462C8.unknown1F[6] >= 0x14) {
                        var_a0_6 = 1;
                        var_s0_2 = 0;
loop_47:
                        var_v0_3 = arg0 * 2;
                        if (var_a0_6 == 1) {
                            if ((arg0 != var_s0_2) && ((var_v1->enabled != var_a0_6) || ((u8)var_v1->pad81[0x10] != 0) || ((settingsCounter(var_v1) - configCounter(temp_s6,4)) < 0xA))) {
                                var_a0_6 = 0;
                            }
                            var_s0_2 += 1;
                            var_v1++;
                            if (var_s0_2 >= 4) {
                                if (var_a0_6 == 1) {
                                    func_80265688_de((arg0 * 0x190) + D_800FEB4A, 0x28, 1);
                                    if (var_s2 < 2) {
                                        arg1[var_s2] = 0x28;
                                        var_s2 += 1;
                                    }
                                }
                                var_v0_3 = arg0 * 2;
                            } else {
                                goto loop_47;
                            }
                        }
                    }
                }
                temp_s0_3 = (((var_v0_3 + arg0) * 8) + arg0) * 0x10;
                temp_s1 = temp_s0_3 + D_800FEB4A;
                var_v0_4 = arg0 * 2;
                if (func_80265650_de(temp_s1, 0x29) == 0) {
                    var_v0_4 = arg0 * 2;
                    if (D_800FEB6C[arg0][0] >= 0x3E9) {
                        func_80265688_de(temp_s1, 0x29, 1);
                        if (var_s2 < 2) {
                            arg1[var_s2] = 0x29;
                            var_s2 += 1;
                        }
                        var_v0_4 = arg0 * 2;
                    }
                }
                temp_s0_4 = (((var_v0_4 + arg0) * 8) + arg0) * 0x10;
                temp_s1_2 = temp_s0_4 + D_800FEB4A;
                var_v0_5 = arg0 * 2;
                if (func_80265650_de(temp_s1_2, 0x2A) == 0) {
                    var_v0_5 = arg0 * 2;
                    if (D_800FEB74[arg0][0] >= 0x3E9) {
                        func_80265688_de(temp_s1_2, 0x2A, 1);
                        if (var_s2 < 2) {
                            arg1[var_s2] = 0x2A;
                            var_s2 += 1;
                        }
                        var_v0_5 = arg0 * 2;
                    }
                }
                temp_s0_5 = ((((var_v0_5 + arg0) * 8) + arg0) * 0x10) + D_800FEB4A;
                var_v0_6 = arg0 * 2;
                if (func_80265650_de(temp_s0_5, 0x2B) == 0) {
                    var_v0_6 = arg0 * 2;
                    if (configCounter(temp_s6,10) >= 0xA) {
                        var_v0_6 = arg0 * 2;
                        if ((s8) D_801462C8.unknown1F[5] >= 0xA) {
                            var_v0_6 = arg0 * 2;
                            if ((s8) D_801462C8.unknown1F[6] >= 0x14) {
                                func_80265688_de(temp_s0_5, 0x2B, 1);
                                if (var_s2 < 2) {
                                    arg1[var_s2] = 0x2B;
                                    var_s2 += 1;
                                }
                                var_v0_6 = arg0 * 2;
                            }
                        }
                    }
                }
                temp_s0_6 = ((((var_v0_6 + arg0) * 8) + arg0) * 0x10) + D_800FEB4A;
                if ((func_80265650_de(temp_s0_6, 0x2C) == 0) && (configCounter(temp_s6,2) == 0) && ((s8) D_801462C8.unknown1F[5] >= 0xA) && ((s8) D_801462C8.unknown1F[6] >= 0x14)) {
                    func_80265688_de(temp_s0_6, 0x2C, 1);
                    if (var_s2 < 2) {
                        arg1[var_s2] = 0x2C;
                    }
                }
            }
        }
    }
}
