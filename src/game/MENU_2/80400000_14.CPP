#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Samples the current record's clip sequence at time t: walks clip list 0 accumulating each
   clip's end time (the time of its last 0x24-byte key) until the clip spanning t is found or the
   ends are passed, then evaluates that clip's keys through Menu_EvaluateCameraSpline at the time into the
   clip, frozen at the clip start when the clip's second flag word is set; the track-1 counterpart of Menu_GetTrackEyePosition, matched the same way. */







extern func_80203E78_S1 *D_800E2830;

#ifdef NON_MATCHING
#define Menu_EvaluateCameraSpline Menu_EvaluateCameraSpline_value
extern CVector3 Menu_EvaluateCameraSpline(KeyRecAt1C *keys, s32 count, f32 t);
#else
extern CVector3 Menu_EvaluateCameraSpline(KeyRecAt1C *keys, s32 count, f32 t);
#endif

#ifdef NON_MATCHING
/* host build: the by-value body is the symbol Menu_GetTrackTargetPosition_value; the entry that takes the result pointer keeps the name the callers use. */
#define Menu_GetTrackTargetPosition Menu_GetTrackTargetPosition_value
extern CVector3 Menu_GetTrackTargetPosition(f32 t);
#endif
CVector3 Menu_GetTrackTargetPosition(f32 t) {
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
    return Menu_EvaluateCameraSpline(keys, count, t - start);
}
#ifdef NON_MATCHING
#undef Menu_GetTrackTargetPosition
void Menu_GetTrackTargetPosition(CVector3 *out, f32 t) {
    *out = Menu_GetTrackTargetPosition_value(t);
}
#endif
