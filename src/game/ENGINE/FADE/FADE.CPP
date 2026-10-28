#include "COMMON/SOUNDVOICEPOOL.H"
#include "stddef.h"
#include "COMMON/VERSION_CALLS.H"

/* Advances streamed music through fade, retry, loading and playback states while updating volume. */
#include "TYPES.H"
#include "COMMON/EXTERNS.H"
#include "sdk/libgultra_inferred/802B3B80_6.H"
#include "sdk/libgultra_inferred/802B3AFC.H"
#include "sdk/libgultra_inferred/802B3B80_7.H"
#include "RENDER/8028FD2C_6.H"
#include "sdk/libgultra_inferred/802AD870_8.H"
extern s32 Defs_FindSortedValue(s32,s32,s32);
extern f32 Menu_ExpandFloatHighWord(u16);
static inline f32 fade_rate(Track *track,f32 time,f32 rate) {track->unk30=time;return (f32)track->unk20/(time*rate);}
void Audio_UpdateMusicPlayback(Track *queue) {
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
    s32 i;
    s32 var_v0;
    struct ALCMidiHdr *temp_s0_2;
    ContextRecAt2BB8 *temp_v0_2;
    struct Resource *temp_v0_4;
    ContextRecAt2BB8 *temp_v0_5;
    struct ALCMidiHdr *var_v0_2;
    temp_v1 = queue->unk18;
    switch (temp_v1) { /* irregular */
    case 0x20:
        if (queue->unk1C & 4) {
            queue->unk1C = 0;
            D_800CBB50_de = -1;
            if (queue->unk28 >= 0) {
                queue->unk18 = 0x40;
                return;
            }
            queue->unk18 = 0x10;
            return;
        }
        return;
    case 0x100:
        if (queue->unk1C & 8) {
            queue->unk18 = 0x80;
            queue->unk1C = 0;
            return;
        }
        temp_v0 = D_800CBB54 + 1;
        D_800CBB54 = temp_v0;
        if (temp_v0 >= 0xA) {
            D_800CBB50_de = -1;
            queue->unk18 = 0x40;
            return;
        }
        break;
    case 0x40:
        temp_a2 = queue->unk28;
        var_v0 = 0x10;
        if (temp_a2 != -1) {
            temp_v0_2 = queue->unk0;
            temp_v0_3 = Defs_FindSortedValue(temp_v0_2->unk2B60, temp_v0_2->unk2B64, temp_a2);
            temp_s0 = temp_v0_3;
            if (temp_s0 != -1) {
                temp_s0 *= 2;
                temp_s0_2 = SetN64_GetPackSection(queue->unk0->unk2B50, temp_s0 | 1);
                temp_v0_4 = SetN64_GetPackSection(queue->unk0->unk2B50, temp_s0);
                queue->unk24 = (s32) temp_v0_4->unk0;
                temp_f0 = Menu_ExpandFloatHighWord(temp_v0_4->unk4);
                queue->unk30 = temp_f0;
                if (temp_f0 <= 0.0f) {
                    queue->unk30 = D_800C3FD0_de;
                }
                var_v0_2 = temp_s0_2;
            } else {
                var_v0_2 = NULL;
            }
            queue->unkC = var_v0_2;
            if (var_v0_2 == NULL) {
                queue->unk18 = 0x100;
                D_800CBB54 = 0;
                queue->unk1C = 0;
                return;
            }
            queue->unk18 = 0x80;
            queue->unk4 = 1;
        case 0x80:
            i = 0;
            func_802AE5B8_de(queue->unk10, queue->unkC);
            alCSPSetSeq(queue->unk14, queue->unk10);
            alCSPSetBank(queue->unk14, queue->unk8->field_4);
            do {
                alCSPSetChlFXMix(queue->unk14, i & 0xFF, 0);
                i += 1;
            } while (i < 0x14);
            temp_f20 = (f32) queue->unk24 * (queue->unk0->unk2BA4 * *(&D_800C3FD0_de+1));
            alCSPSetVol(queue->unk14, (s16) (s32) (temp_f20 * D_800C3FD8_de));
            queue->unk2C = temp_f20;
            func_802AFE80_de(queue->unk14);
            queue->unk1C = 0;
            queue->unk18 = 0x10;
            D_800CBB50_de = queue->unk28;
            return;
        }
        goto block_44;
    case 0x10:
    default:
        if ((D_800CBB50_de > 0) && (alCSPGetState((void *)queue->unk14) == 0)) {
            D_800CBB50_de = 0;
            queue->unk28 = 0;
        } else {
            if (queue->unk38 != 0) {
                var_f20 = (f32) queue->unk24;
                var_f20 *= queue->unk0->unk2BA4 * *(&D_800C3FD8_de+1);
                var_f20 *= queue->unk3C;
                goto block_37;
            }
            temp_v0_5 = queue->unk0;
            var_f20 = (f32) queue->unk24 * (temp_v0_5->unk2BA4 * D_800C3FE0_de);
            if (temp_v0_5->unk2BB8 != 0) {
                var_f20 *= D_800C3FE4;
            }
            if (var_f20 != queue->unk2C) {
block_37:
                alCSPSetVol(queue->unk14, (s16) (s32) (var_f20 * D_800C3FE8_de));
                queue->unk2C = var_f20;
            }
        }
        if (queue->unk28 != D_800CBB50_de) {
            if (D_800CBB50_de > 0) {
                var_f2 = queue->unk30;
                queue->unk1C = 2;
                queue->unk18 = 0x20;
                queue->unk20 = (s32) (queue->unk2C * D_800C3FEC_de);
                if (!(var_f2 >= D_800C3FF0_de)) {
                    var_f2 = D_800C3FF0_de;
                }
                queue->unk34 = fade_rate(queue,var_f2,*(&D_800C3FF0_de+1));
                return;
            }
            var_v0 = 0x40;
            queue->unk1C = 0;
block_44:
            queue->unk18 = var_v0;
        }
        break;
    }
}
