#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_802106E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_802BB15C.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"
s32 func_80265550_de(u32 *arg0, s32 arg1, u32 arg2, s32 *arg3, s32 *arg4);
s32 func_80257BB4_de(void *arg0, Item57BD4 *arg1, Vec3 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_80257DD4_de(void *arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5, s32 arg6) {
    union { u32 word; f32 value; } xbits, ybits, zbits;
    Vec3 position;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    Queue_func_802BB2A0_de *temp_s0;
    Queue_func_802BB420_de *temp_s0_2;
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a0_4;
    s32 *var_a0_5;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_lo;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s8 *temp_v0_3;
    u16 temp_s1;
    u32 temp_a0;
    u32 temp_s5;
    u32 temp_v0_4;
    u32 var_s0_5;
    void *var_v1_2;

    xbits.word = arg2; ybits.word = arg3; zbits.word = arg4;
    position.x = xbits.value; position.y = ybits.value; position.z = zbits.value;

    if (((s16 *) arg0)[258 / sizeof(s16)] != -1) {
        var_v1 = 1;
    } else {
        var_a1 = 0;
        if (arg1 < 0x100) {
            var_a0 = 0;
            var_v1_2 = arg0;
            do {
                if (((s32 *) var_v1_2)[7780 / sizeof(s32)] == arg1) {
                    var_a1 += 1;
                }
                var_a0 += 1;
                var_v1_2 += 0xCC;
            } while (var_a0 < 0x11);
            var_v1 = 1;
            if (var_a1 < 6) {
                goto block_8;
            }
        } else {
block_8:
            var_v1 = 0;
        }
    }
    var_v0 = -1;
    if (var_v1 == 0) {
        if (arg1 < 0x100) {
            temp_s1 = ((u16 *) arg0)[306 / sizeof(u16)];
            var_s0 = 0;
            if ((((s32 *) arg0)[11092 / sizeof(s32)] != 0) && (func_80265550_de(((u32 **) arg0)[11096 / sizeof(u32 *)], ((s32 *) arg0)[11092 / sizeof(s32)], (u32) (s16) arg1, &sp20, &sp24) != 0)) {
                var_a3 = sp20;
                if (var_a3 != sp24) {
                    var_a1_2 = var_a3;
                    if (sp24 >= var_a3) {
                        var_a0_2 = (var_a3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
                        do {
                            temp_v0 = *var_a0_2;
                            var_a0_2 += 4;
                            var_a1_2 += 1;
                            var_s0 += temp_v0 * 0xA;
                        } while (sp24 >= var_a1_2);
                    }
                    temp_a2 = func_802744D4_de() % var_s0;
                    var_a3_2 = sp20;
                    var_s0_2 = 0;
                    if (var_a3_2 < sp24) {
                        var_a0_3 = (var_a3_2 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
loop_19:
                        var_s0_2 += *var_a0_3 * 0xA;
                        var_v0_2 = temp_s1 << 0x10;
                        if (var_s0_2 < temp_a2) {
                            var_a3_2 += 1;
                            var_a0_3 += 4;
                            if (var_a3_2 >= sp24) {
                                goto block_21;
                            }
                            goto loop_19;
                        }
                    } else {
block_21:
                        var_v0_2 = temp_s1 << 0x10;
                    }
                    var_s1 = var_a3_2;
                    if ((var_v0_2 != 0) && (var_a3_2 == ((s32 *) arg0)[304 / sizeof(s32)])) {
                        if (var_a3_2 != sp24) {
                            var_a3 = var_a3_2 + 1;
                        } else {
                            var_a3 = var_a3_2 - 1;
                        }
                        goto block_28;
                    }
                } else {
block_28:
                    var_s1 = var_a3;
                }
            } else {
                var_s1 = -1;
            }
            ((s8 *) arg0)[11156 / sizeof(s8)] = (s8) (s32) func_80274564_de(D_800C3EDC_de);
        } else {
            var_s0_3 = 0;
            if (((s32 *) arg0)[11092 / sizeof(s32)] != 0) {
                var_s1 = -1;
                if (func_80265550_de(((u32 **) arg0)[11096 / sizeof(u32 *)], ((s32 *) arg0)[11092 / sizeof(s32)], (u32) (s16) arg1, &sp28, &sp2C) != 0) {
                    var_a3_3 = sp28;
                    if (var_a3_3 != sp2C) {
                        var_a1_3 = var_a3_3;
                        if (sp2C >= var_a3_3) {
                            var_a0_4 = (var_a3_3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
                            do {
                                temp_v0_2 = *var_a0_4;
                                var_a0_4 += 4;
                                var_a1_3 += 1;
                                var_s0_3 += temp_v0_2 * 0xA;
                            } while (sp2C >= var_a1_3);
                        }
                        temp_a2_2 = func_802744D4_de() % var_s0_3;
                        var_a3_3 = sp28;
                        var_s0_4 = 0;
                        if (var_a3_3 < sp2C) {
                            var_a0_5 = (var_a3_3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
loop_39:
                            var_s0_4 += *var_a0_5 * 0xA;
                            var_s1 = var_a3_3;
                            if (var_s0_4 < temp_a2_2) {
                                var_a3_3 += 1;
                                var_a0_5 += 4;
                                if (var_a3_3 >= sp2C) {
                                    goto block_41;
                                }
                                goto loop_39;
                            }
                        } else {
                            goto block_41;
                        }
                    } else {
block_41:
                        var_s1 = var_a3_3;
                    }
                }
            } else {
                var_s1 = -1;
            }
        }
        var_v0 = -1;
        if (var_s1 != -1) {
            ((s8 **) arg0)[11144 / sizeof(s8 *)] = func_8028FDB4_de(func_8028FDB4_de(((s32 **) arg0)[11084 / sizeof(s32 *)], (s32) (s16) var_s1), 0);
            ((s16 *) arg0)[11148 / sizeof(s16)] = (s16) arg1;
            ((s32 *) arg0)[11152 / sizeof(s32)] = arg6;
            temp_v0_3 = func_8028FDB4_de(func_8028FDB4_de(((s32 **) arg0)[11084 / sizeof(s32 *)], (s32) (s16) var_s1), 1);
            temp_s5 = ((u32 *) temp_v0_3)[4 / sizeof(u32)];
            var_s2 = -1;
            if (temp_s5 != 0) {
                temp_s0 = arg0 + 0x110;
                temp_a0 = func_802BCF30_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_v1 = *((s32 *) ((u8 *) (temp_s0) + 28)) + 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0) + 28)) = temp_v1;
                if (temp_v1 != 1) {
                    func_802BCF50_de(temp_a0);
                    func_802BB2A0_de(temp_s0, NULL, 1);
                } else {
                    func_802BCF50_de(temp_a0);
                }
                temp_s0_2 = arg0 + 0x110;
                var_s2 = ((s32 *) arg0)[268 / sizeof(s32)] + 1;
                ((s32 *) arg0)[268 / sizeof(s32)] = var_s2;
                temp_v0_4 = func_802BCF30_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_v1_2 = *((s32 *) ((u8 *) (temp_s0_2) + 28)) - 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0_2) + 28)) = temp_v1_2;
                if (temp_v1_2 != 0) {
                    func_802BCF50_de(temp_v0_4);
                    func_802BB420_de(temp_s0_2, 0, 1);
                    var_v0_3 = arg1 < 0x100;
                } else {
                    func_802BCF50_de(temp_v0_4);
                    var_v0_3 = arg1 < 0x100;
                }
                if (var_v0_3 != 0) {
                    ((s32 *) arg0)[304 / sizeof(s32)] = var_s1;
                    goto block_55;
                }
                var_s0_5 = 0;
            } else {
block_55:
                var_s0_5 = 0;
            }
            if (temp_s5 != 0) {
                do {
                    temp_lo = var_s0_5 * ((s32 *) temp_v0_3)[0 / sizeof(s32)];
                    var_s0_5 += 1;
                    func_80257BB4_de(arg0, (void *)(temp_v0_3 + temp_lo + 8), &position, var_s1, var_s2, 0, arg5);
                } while (var_s0_5 < temp_s5);
            }
            ((s32 *) arg0)[11152 / sizeof(s32)] = -1;
            var_v0 = var_s2;
        }
    }
    return var_v0;
}
