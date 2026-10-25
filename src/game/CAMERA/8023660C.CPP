#include "COMMON/GFX.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/RESULTS.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "CAMERA/80233920_7.H"

/* Eases a camera's four framing values at 0x29C, 0x2A0, 0x2A4 and 0x2A8 toward their targets by 16 each
 * frame, snapping to the targets when func_80264B6C_de reports a cut and recording the easing rate 30 in
 * D_800FF224_de whenever a value moves. Adapted from func_8023A294_de as a static helper.
 */

extern s32 Render_IsSnapshotActive(void);


static inline f32 approach(f32 value, f32 target, f32 step) {
    if (Render_IsSnapshotActive() != 0) {
        value = target;
    }
    if (value < target) {
        value += step;
        D_800FF224_de = 30.0f;
        if (target < value) {
            value = target;
        }
    } else if (target < value) {
        value -= step;
        D_800FF224_de = 30.0f;
        if (value < target) {
            value = target;
        }
    }
    return value;
}




void func_8023660C_de(GameplayCamera *camera, f32 a, f32 b, f32 c, f32 d) {
    GameplayCamera *record = camera;
    record->viewWidth = approach(record->viewWidth, a, 16.0f);
    record->viewHeight = approach(record->viewHeight, b, 16.0f);
    record->viewLeft = approach(record->viewLeft, c, 16.0f);
    record->viewTop = approach(record->viewTop, d, 16.0f);
}
