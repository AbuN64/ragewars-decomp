#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Samples the current record's clip sequence at time t: walks clip list 0 accumulating each
   clip's end time (the time of its last 0x24-byte key) until the clip spanning t is found or the
   ends are passed, then evaluates that clip's keys through func_80400E50_de at the time into the
   clip, frozen at the clip start when the clip's second flag word is set; the track-1 counterpart of func_80401214_de, matched the same way. */







extern func_80203E78_S1 *D_800E2830;

#ifdef NON_MATCHING
#define func_80400E50_de func_80400E50_de_value
#endif
extern CVector3 func_80400E50_de(KeyRecAt1C *keys, s32 count, f32 t);

#ifdef NON_MATCHING
#define func_804013BC_de func_804013BC_de_value
#endif
CVector3 func_804013BC_de(f32 t) {
    s32 i;
    s32 idx;
    s32 count;
    KeyRecAt1C *keys;
    s32 *clip;
    f32 start;
    f32 end;

    start = 0.0f;
    count = 0;
    keys = 0;
    idx = 0;
    i = 0;
    end = start;
    while (i < *((s32 *)func_8028FDB4_de((s32 *)D_800E2830->unk4, 0))) {
        idx = i;
        clip = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de((s32 *)D_800E2830->unk4, 0), idx), 1);
        count = clip[1];
        keys = (KeyRecAt1C *)(clip + 2);
        start = end;
        end = start + keys[count - 1].time;
        if (idx == 0 && t <= start) {
            break;
        }
        if (idx == *((s32 *)func_8028FDB4_de((s32 *)D_800E2830->unk4, 0)) - 1 && end < t) {
            break;
        }
        i = idx + 1;
        if (start <= t && t <= end) {
            break;
        }
    }
    if (((s32 *)func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de((s32 *)D_800E2830->unk4, 0), idx), 2))[1] != 0) {
        t = start;
    }
    return func_80400E50_de(keys, count, t - start);
}
#ifdef NON_MATCHING
#undef func_804013BC_de
void func_804013BC_de(CVector3 *out, f32 t) {
    *out = func_804013BC_de_value(t);
}
#endif
