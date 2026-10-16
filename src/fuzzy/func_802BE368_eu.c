#include "acmd.h"
#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_802BE0D0_de_closed.h"
#include "span_1000/code_802BE0D0.h"
#include "TYPES.H"
Acmd *func_802BE368_eu(ALLoadFilter48_2 *arg0, s16 *arg1, s32 arg2, s32 unused, Acmd *arg4) {
    u32 sp18;                                     /* compiler-managed */
    s32 sp20;
    Acmd *temp_v0;
    Acmd *var_s2;
    Acmd *var_s2_2;
    Acmd *var_s2_3;
    Acmd *var_v0;
    s16 temp_s6;
    s16 var_s4;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4_2;
    s32 var_s5;
    s32 var_s6;
    u32 temp_a1_2;
    u32 temp_v1;
    u32 temp_v1_4;
    u32 temp_v1_5;
    ALWaveTable_s *temp_a0;

    temp_a0 = arg0->table;
    var_s2_2 = arg4;
    var_s5 = arg2;
    sp20 = 0;
    if (var_s5 != 0) {
        var_s2_2->words.w0 = (arg0->bookSize & 0xFFFFFF) | 0x0B000000;
        var_s2_3 = var_s2_2 + 1;
        var_a0 = 0;
        var_s2_2->words.w1 = func_802570C0_de(temp_a0->waveInfo.adpcmWave.book->book, arg0->bookSize);
        temp_a1 = arg0->sample;
        temp_v1 = arg0->loop.end;
        if (temp_v1 < (u32) (var_s5 + temp_a1)) {
            var_a0 = (u32) arg0->loop.count > 0U;
        }
        var_s1 = var_s5;
        if (var_a0 != 0) {
            var_s1 = temp_v1 - temp_a1;
        }
        temp_v1_2 = arg0->lastsam;
        if (temp_v1_2 != 0) {
            var_s6 = 0x10 - temp_v1_2;
        } else {
            var_s6 = 0;
        }
        var_a2 = var_s1 - var_s6;
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        var_s3 = (s32) (var_a2 + 0xF) >> 4;
        temp_a3 = var_s3 * 9;
        if (var_a0 != 0) {
            sp18 = arg0->first;
            var_s2 = func_802BEC34_de(var_s2_3, arg0, var_a2, temp_a3, (s16) (s32) *arg1, 0, sp18);
            if (arg0->lastsam != 0) {
                *arg1 = (u16) *arg1 + ((u16)arg0->lastsam * 2);
            } else {
                *arg1 = (u16) *arg1 + 0x20;
            }
            temp_a1_2 = arg0->loop.start;
            arg0->lastsam = arg0->loop.start & 0xF;
            arg0->sample = (s32) temp_a1_2;
            arg0->memin = (s32)temp_a0->base + (((temp_a1_2 >> 4) + 1) * 9);
            var_s4 = *arg1;
            if (var_s1 < var_s5) {
                do {
                    temp_v1_3 = var_s4 + ((var_s3 + 1) << 5);
                    var_s4 += var_s1 * 2;
                    temp_s6 = temp_v1_3 & ~0x1F;
                    temp_v1_4 = arg0->loop.count;
                    var_s5 -= var_s1;
                    if ((temp_v1_4 != -1U) && (temp_v1_4 != 0)) {
                        arg0->loop.count = temp_v1_4 - 1;
                    }
                    temp_v1_5 = arg0->loop.end - arg0->loop.start;
                    var_s1 = var_s5;
                    if ((u32) var_s5 >= temp_v1_5) {
                        var_s1 = (s32) temp_v1_5;
                    }
                    var_a2_2 = var_s1 + (arg0->lastsam - 0x10);
                    if (var_a2_2 < 0) {
                        var_a2_2 = 0;
                    }
                    var_s3 = (s32) (var_a2_2 + 0xF) >> 4;
                    sp18 = arg0->first | 2;
                    temp_v0 = func_802BEC34_de(var_s2, arg0, var_a2_2, var_s3 * 9, (s16) (s32) temp_s6, 0, sp18);
                    temp_v0->words.w1 = (var_s4 << 0x10) | ((var_s1 * 2) & 0xFFFF);
                    temp_v0->words.w0 = ((temp_s6 + (arg0->lastsam * 2)) & 0xFFFFFF) | 0x0A000000;
                    var_s2 = temp_v0 + 1;
                } while (var_s1 < var_s5);
            }
            arg0->lastsam = (var_s5 + arg0->lastsam) & 0xF;
            arg0->sample += var_s5;
            arg0->memin += var_s3 * 9;
            return var_s2;
        }
        temp_a0 = arg0->table;
        var_a0_2 = (arg0->memin + temp_a3) - ((s32)temp_a0->base + temp_a0->len);
        temp_s1 = var_s3 * 0x10;
        if (var_a0_2 < 0) {
            var_a0_2 = 0;
        }
        var_s4_2 = (var_a0_2 / 9) * 0x10;
        temp_v1_6 = temp_s1 + var_s6;
        if (temp_v1_6 < var_s4_2) {
            var_s4_2 = temp_v1_6;
        }
        if ((var_s4_2 - (var_s4_2 & 0xF)) < var_s5) {
            sp20 = 1;
            sp18 = arg0->first;
            var_s2_3 = func_802BEC34_de(var_s2_3, arg0, temp_s1 - var_s4_2, temp_a3 - var_a0_2, (s16) (s32) *arg1, 0, sp18);
            if (arg0->lastsam != 0) {
                *arg1 = (u16) *arg1 + ((u16)arg0->lastsam * 2);
            } else {
                *arg1 = (u16) *arg1 + 0x20;
            }
            arg0->lastsam = (var_s5 + arg0->lastsam) & 0xF;
            arg0->sample += var_s5;
            arg0->memin += var_s3 * 9;
        } else {
            arg0->lastsam = 0;
            arg0->memin += var_s3 * 9;
        }
        var_v0 = var_s2_3;
        if (var_s4_2 != 0) {
            arg0->lastsam = 0;
            if (sp20 != 0) {
                var_a2_3 = ((var_s6 + temp_s1) - var_s4_2) * 2;
            } else {
                var_a2_3 = 0;
            }
            var_s2_2 = var_s2_3 + 1;
            var_s2_3->words.w1 = var_s4_2 * 2;
            var_s2_3->words.w0 = ((var_a2_3 + *arg1) & 0xFFFFFF) | 0x02000000;
            goto block_40;
        }
        /* Duplicate return node #41. Try simplifying control flow for better match */
        return var_v0;
    }
block_40:
    var_v0 = var_s2_2;
    return var_v0;
}
