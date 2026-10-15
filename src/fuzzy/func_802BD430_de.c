#include "audio_callbacks.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "stddef.h"
#include "types.h"
#include "stdarg.h"
unsigned char *func_802BD3C8_de(unsigned char *string, unsigned char value);
void func_802BD974_de(_Pft *px, va_list *pap, int code, unsigned char *ac);
extern u8 D_800C7AF0_de;
extern u8 D_800C7B10_de;
extern s8 D_800D52B0;
extern s8 D_800D52D4;


s32 func_802BD430_de(void *(*arg0)(void *, s8 *, s32), void *arg1, s8 *arg2, va_list arg3) {
    _Pft state;
    u8 buffer[32];
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s0_6;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s8 *var_a1;
    s8 *var_s2;
    s8 *var_s2_2;
    u8 *temp_v0;
    u8 var_s1;
    u8 var_v0;
    void *var_s3;

    var_s3 = arg1;
    var_a1 = arg2;
    state.nchar = 0;
loop_1:
    var_s1 = (u8) *var_a1;
    var_s2 = var_a1;
    if (var_s1 != 0) {
loop_3:
        var_s0 = var_s2 - var_a1;
        if (var_s1 != 0x25) {
            var_s2 += 1;
            var_s1 = (u8) *var_s2;
            if (var_s1 == 0) {
                goto block_5;
            }
            goto loop_3;
        }
    } else {
block_5:
        var_s0 = var_s2 - var_a1;
    }
    if (var_s0 > 0) {
        var_s3 = arg0(var_s3, var_a1, var_s0);
        if (var_s3 != NULL) {
            state.nchar += var_s0;
            goto block_9;
        }
    } else {
block_9:
        var_s2_2 = var_s2 + 1;
        if (var_s1 != 0) {
            state.flags = 0;
loop_11:
            temp_v0 = func_802BD3C8_de(&D_800C7AF0_de, (u8) *var_s2_2);
            if (temp_v0 != NULL) {
                var_s2_2 += 1;
                switch (*temp_v0) {
                case ' ': state.flags |= 1; break;
                case '+': state.flags |= 2; break;
                case '-': state.flags |= 4; break;
                case '#': state.flags |= 8; break;
                case '0': state.flags |= 16; break;
                }
                goto loop_11;
            }
            if ((u8) *var_s2_2 != 0x2A) {
                state.width = 0;
loop_22:
                if ((u32) ((u8) *var_s2_2 - 0x30) < 0xAU) {
                    if (state.width < 0x3E7) {
                        state.width = ((state.width * 0xA) + (u8) *var_s2_2) - 0x30;
                    }
                    var_s2_2 += 1;
                    goto loop_22;
                }
            } else {
                temp_a0 = va_arg(arg3, int);
                state.width = temp_a0;
                if (temp_a0 < 0) {
                    state.width = -temp_a0;
                    state.flags |= 4;
                }
                var_s2_2 += 1;
            }
            if ((u8) *var_s2_2 != 0x2E) {
                state.prec = -1;
            } else {
                var_s2_2 += 1;
                if ((u8) *var_s2_2 != 0x2A) {
                    state.prec = 0;
loop_32:
                    if ((u32) ((u8) *var_s2_2 - 0x30) < 0xAU) {
                        if (state.prec < 0x3E7) {
                            state.prec = ((state.prec * 0xA) + (u8) *var_s2_2) - 0x30;
                        }
                        var_s2_2 += 1;
                        goto loop_32;
                    }
                } else {
                    var_s2_2 += 1;
                    state.prec = va_arg(arg3, int);
                }
            }
            var_v0 = 0;
            if (func_802BD3C8_de(&D_800C7B10_de, (u8) *var_s2_2) != NULL) {
                var_v0 = (u8) *var_s2_2;
                var_s2_2 += 1;
            }
            state.qual = var_v0;
            temp_v1 = var_v0 & 0xFF;
            if (temp_v1 == 0x6C) {
                if ((u8) *var_s2_2 == temp_v1) {
                    state.qual = 0x4C;
                    var_s2_2 += 1;
                }
            }
            func_802BD974_de(&state, &arg3, (s32) (u8) *var_s2_2, buffer);
            temp_a0_2 = state.width - (state.n0 + state.nz0 + state.n1 + state.nz1 + state.n2 + state.nz2);
            state.width = temp_a0_2;
            if (!(state.flags & 4) && (temp_a0_2 > 0)) {
                var_s1_2 = temp_a0_2;
                var_v0_2 = (u32) var_s1_2 < 0x21U;
loop_42:
                var_s0_2 = 0x20;
                if (var_v0_2 != 0) {
                    var_s0_2 = var_s1_2;
                }
                if (var_s0_2 <= 0) {
                    var_s1_2 -= var_s0_2;
                    goto block_49;
                }
                var_s3 = arg0(var_s3, &D_800D52B0, var_s0_2);
                var_s1_2 -= var_s0_2;
                if (var_s3 != NULL) {
                    state.nchar += var_s0_2;
block_49:
                    var_v0_2 = (u32) var_s1_2 < 0x21U;
                    if (var_s1_2 <= 0) {
                        goto block_50;
                    }
                    goto loop_42;
                }
            } else {
block_50:
                if (state.n0 > 0) {
                    var_s3 = arg0(var_s3, (s8 *) &buffer, state.n0);
                    if (var_s3 != NULL) {
                        state.nchar += state.n0;
                        goto block_53;
                    }
                } else {
block_53:
                    if (state.nz0 > 0) {
                        var_s1_3 = state.nz0;
                        var_v0_3 = (u32) var_s1_3 < 0x21U;
loop_55:
                        var_s0_3 = 0x20;
                        if (var_v0_3 != 0) {
                            var_s0_3 = var_s1_3;
                        }
                        if (var_s0_3 <= 0) {
                            var_s1_3 -= var_s0_3;
                            goto block_62;
                        }
                        var_s3 = arg0(var_s3, &D_800D52D4, var_s0_3);
                        var_s1_3 -= var_s0_3;
                        if (var_s3 != NULL) {
                            state.nchar += var_s0_3;
block_62:
                            var_v0_3 = (u32) var_s1_3 < 0x21U;
                            if (var_s1_3 <= 0) {
                                goto block_63;
                            }
                            goto loop_55;
                        }
                    } else {
block_63:
                        if (state.n1 > 0) {
                            var_s3 = arg0(var_s3, (s8 *)state.s, state.n1);
                            if (var_s3 != NULL) {
                                state.nchar += state.n1;
                                goto block_66;
                            }
                        } else {
block_66:
                            if (state.nz1 > 0) {
                                var_s1_4 = state.nz1;
                                var_v0_4 = (u32) var_s1_4 < 0x21U;
loop_68:
                                var_s0_4 = 0x20;
                                if (var_v0_4 != 0) {
                                    var_s0_4 = var_s1_4;
                                }
                                if (var_s0_4 <= 0) {
                                    var_s1_4 -= var_s0_4;
                                    goto block_75;
                                }
                                var_s3 = arg0(var_s3, &D_800D52D4, var_s0_4);
                                var_s1_4 -= var_s0_4;
                                if (var_s3 != NULL) {
                                    state.nchar += var_s0_4;
block_75:
                                    var_v0_4 = (u32) var_s1_4 < 0x21U;
                                    if (var_s1_4 <= 0) {
                                        goto block_76;
                                    }
                                    goto loop_68;
                                }
                            } else {
block_76:
                                if (state.n2 > 0) {
                                    var_s3 = arg0(var_s3, (s8 *)&state.s[state.n1], state.n2);
                                    if (var_s3 != NULL) {
                                        state.nchar += state.n2;
                                        goto block_79;
                                    }
                                } else {
block_79:
                                    if (state.nz2 > 0) {
                                        var_s1_5 = state.nz2;
                                        var_v0_5 = (u32) var_s1_5 < 0x21U;
loop_81:
                                        var_s0_5 = 0x20;
                                        if (var_v0_5 != 0) {
                                            var_s0_5 = var_s1_5;
                                        }
                                        if (var_s0_5 <= 0) {
                                            var_s1_5 -= var_s0_5;
                                            goto block_88;
                                        }
                                        var_s3 = arg0(var_s3, &D_800D52D4, var_s0_5);
                                        var_s1_5 -= var_s0_5;
                                        if (var_s3 != NULL) {
                                            state.nchar += var_s0_5;
block_88:
                                            var_v0_5 = (u32) var_s1_5 < 0x21U;
                                            if (var_s1_5 <= 0) {
                                                goto block_89;
                                            }
                                            goto loop_81;
                                        }
                                    } else {
block_89:
                                        var_a1 = var_s2_2 + 1;
                                        if ((state.flags & 4) && (var_s1_6 = state.width, (state.width > 0))) {
                                            var_v0_6 = (u32) var_s1_6 < 0x21U;
loop_92:
                                            var_s0_6 = 0x20;
                                            if (var_v0_6 != 0) {
                                                var_s0_6 = var_s1_6;
                                            }
                                            if (var_s0_6 <= 0) {
                                                var_s1_6 -= var_s0_6;
                                                goto block_99;
                                            }
                                            var_s3 = arg0(var_s3, &D_800D52B0, var_s0_6);
                                            var_s1_6 -= var_s0_6;
                                            if (var_s3 != NULL) {
                                                state.nchar += var_s0_6;
block_99:
                                                var_v0_6 = (u32) var_s1_6 < 0x21U;
                                                if (var_s1_6 <= 0) {
                                                    var_a1 = var_s2_2 + 1;
                                                    goto loop_1;
                                                }
                                                goto loop_92;
                                            }
                                        } else {
                                            goto loop_1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return state.nchar;
}
