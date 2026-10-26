#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "RENDER_4/8028FD2C_6.H"



struct SharedTrackObject;




/* The copied prefix is exactly 0x50 bytes. */
#include "MENU/TRACK_TYPES.H"





/* The two adjacent track constants are consumed at base and base+4. */



#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "MENU_2/80400000_15.H"

extern f32 D_800E2848;
extern struct SharedTrackConstants D_800DCB28;


f32 func_8040170C_de(f32 t) {
    s32 *track;
    KeyRecAt10 *key;
    s32 count;
    f32 u;
    f32 v;

    track = Render_GetPackSection(D_800E2830->resource, 1);
    count = track[1];
    key = (KeyRecAt10 *)(track + 2);
    if (count == 0) {
        v = 0.0f;
    } else if (t <= key[0].time) {
        v = key[0].value;
    } else if (key[count - 1].time <= t) {
        v = key[count - 1].value;
    } else {
        while (key->time < t) {
            key++;
        }
        u = (t - key[-1].time) / (key->time - key[-1].time);
        v = key[-1].value * (D_800DCB28.unit - u) + key->value * u;
    }
    v *= 2.0f * D_800E2848 + D_800E0B60[0];
    v -= D_800E2848;
    if (D_800E0B60[0] < v) {
        v = D_800E0B60[0];
    }
    if (v < 0.0f) {
        v = 0.0f;
    }
    return v;
}
