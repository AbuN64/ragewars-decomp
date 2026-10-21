#include "COMMON/SOUNDVOICEPOOL.H"
#include "stddef.h"
#include "COMMON/VERSION_CALLS.H"

/* Advances streamed music through fade, retry, loading and playback states while updating volume. */
#include "TYPES.H"
#include "COMMON/EXTERNS.H"
#include "sdk/libgultra_inferred/802B3B80_6.H"
#include "sdk/libgultra_inferred/802B3AFC.H"
#include "sdk/libgultra_inferred/802B3B80_7.H"
#include "RENDER_4/8028FD2C_6.H"
extern s32 func_802654E8_de(s32,s32,s32);
extern f32 func_802B2350(u16);
extern void func_802AE5B8_de(s32, void *);
static inline f32 fade_rate(Track *track,f32 time,f32 rate) {track->unk30=time;return (f32)track->unk20/(time*rate);}
void func_8025D450_de(Track *arg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f20;
    f32 var_f2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    void *temp_s0_2;
    ContextRecAt2BB8 *temp_v0_2;
    struct Resource *temp_v0_4;
    ContextRecAt2BB8 *temp_v0_5;
    void *var_v0_2;
    temp_v1 = arg0->unk18;
    switch (temp_v1) { /* irregular */
    case 0x20:
        if (arg0->unk1C & 4) {
            arg0->unk1C = 0;
            D_800CBB50_de = -1;
            if (arg0->unk28 >= 0) {
                arg0->unk18 = 0x40;
                return;
            }
            arg0->unk18 = 0x10;
            return;
        }
        return;
    case 0x100:
        if (arg0->unk1C & 8) {
            arg0->unk18 = 0x80;
            arg0->unk1C = 0;
            return;
        }
        temp_v0 = D_800CBB54 + 1;
        D_800CBB54 = temp_v0;
        if (temp_v0 >= 0xA) {
            D_800CBB50_de = -1;
            arg0->unk18 = 0x40;
            return;
        }
        break;
    case 0x40:
        temp_a2 = arg0->unk28;
        var_v0 = 0x10;
        if (temp_a2 != -1) {
            temp_v0_2 = arg0->unk0;
            temp_v0_3 = func_802654E8_de(temp_v0_2->unk2B60, temp_v0_2->unk2B64, temp_a2);
            temp_s0 = temp_v0_3;
            if (temp_s0 != -1) {
                temp_s0 *= 2;
                temp_s0_2 = func_8028FDB4_de(arg0->unk0->unk2B50, temp_s0 | 1);
                temp_v0_4 = func_8028FDB4_de(arg0->unk0->unk2B50, temp_s0);
                arg0->unk24 = (s32) temp_v0_4->unk0;
                temp_f0 = func_802B2350(temp_v0_4->unk4);
                arg0->unk30 = temp_f0;
                if (temp_f0 <= 0.0f) {
                    arg0->unk30 = D_800C3FD0_de;
                }
                var_v0_2 = temp_s0_2;
            } else {
                var_v0_2 = NULL;
            }
            arg0->unkC = var_v0_2;
            if (var_v0_2 == NULL) {
                arg0->unk18 = 0x100;
                D_800CBB54 = 0;
                arg0->unk1C = 0;
                return;
            }
            arg0->unk18 = 0x80;
            arg0->unk4 = 1;
        case 0x80:
            var_s0 = 0;
            func_802AE5B8_de(arg0->unk10, arg0->unkC);
            func_802AFF30_de(arg0->unk14, arg0->unk10);
            func_802AFEB0_de(arg0->unk14, arg0->unk8->field_4);
            do {
                func_802AFEE0_de(arg0->unk14, var_s0 & 0xFF, 0);
                var_s0 += 1;
            } while (var_s0 < 0x14);
            temp_f20 = (f32) arg0->unk24 * (arg0->unk0->unk2BA4 * *(&D_800C3FD0_de+1));
            func_802AFF60_de(arg0->unk14, (s16) (s32) (temp_f20 * D_800C3FD8_de));
            arg0->unk2C = temp_f20;
            func_802AFE80_de(arg0->unk14);
            arg0->unk1C = 0;
            arg0->unk18 = 0x10;
            D_800CBB50_de = arg0->unk28;
            return;
        }
        goto block_44;
    case 0x10:
    default:
        if ((D_800CBB50_de > 0) && (func_802AEAA0_de((void *)arg0->unk14) == 0)) {
            D_800CBB50_de = 0;
            arg0->unk28 = 0;
        } else {
            if (arg0->unk38 != 0) {
                var_f20 = (f32) arg0->unk24;
                var_f20 *= arg0->unk0->unk2BA4 * *(&D_800C3FD8_de+1);
                var_f20 *= arg0->unk3C;
                goto block_37;
            }
            temp_v0_5 = arg0->unk0;
            var_f20 = (f32) arg0->unk24 * (temp_v0_5->unk2BA4 * D_800C3FE0_de);
            if (temp_v0_5->unk2BB8 != 0) {
                var_f20 *= D_800C3FE4;
            }
            if (var_f20 != arg0->unk2C) {
block_37:
                func_802AFF60_de(arg0->unk14, (s16) (s32) (var_f20 * D_800C3FE8_de));
                arg0->unk2C = var_f20;
            }
        }
        if (arg0->unk28 != D_800CBB50_de) {
            if (D_800CBB50_de > 0) {
                var_f2 = arg0->unk30;
                arg0->unk1C = 2;
                arg0->unk18 = 0x20;
                arg0->unk20 = (s32) (arg0->unk2C * D_800C3FEC_de);
                if (!(var_f2 >= D_800C3FF0_de)) {
                    var_f2 = D_800C3FF0_de;
                }
                arg0->unk34 = fade_rate(arg0,var_f2,*(&D_800C3FF0_de+1));
                return;
            }
            var_v0 = 0x40;
            arg0->unk1C = 0;
block_44:
            arg0->unk18 = var_v0;
        }
        break;
    }
}
