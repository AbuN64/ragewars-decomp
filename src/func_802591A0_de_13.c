#include "span_1000/code_802591C0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"
#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "packed_float.h"
#include "shared/gameplay_camera.h"

/* Returns the stereo pan of a sound at a position for a listener: centre (0x40) without a listener, when
 * the sound is horizontally within a small radius or straight ahead; otherwise the horizontal direction
 * in listener space is compared with the forward axis through func_802745D0_de and func_802B7130_de, given the
 * side's sign, and scaled around the centre by D_800C8FF8. */

extern void func_80272BCC_de(void *, Vec3 *, Vec3 *);



s16 func_80259B10_de(Vec3 *position, void *listener) {
    Vec3 forward;
    Vec3 offset;
    Vec3 local;
    f32 pan;

    if (listener == 0) {
        return 0x40;
    }
    func_80271F68_de(&offset, &((GameplayCamera *)(listener))->position, position);
    if (offset.x * offset.x + offset.z * offset.z < D_800C3F00_de) {
        return 0x40;
    }
    func_80272BCC_de(&((GameplayCamera *)(listener))->unk160, &offset, &local);
    local.y = 0.0f;
    forward.x = forward.y = local.y;
    forward.z = (&D_800C3F00_de)[1];
    func_8027207C_de(&local.x);
    pan = func_802B7130_de(func_802745D0_de(local.x * forward.x + local.y * forward.y + local.z * forward.z));
    if (local.x == 0.0f) {
        return 0x40;
    }
    if (0.0f < local.x) {
        if (pan < 0.0f) {
            pan = -pan;
        }
    } else {
        pan = -fabsf(pan);
    }
    return pan * D_800C8FF8 + D_800C8FF8;
}

/* Updates a view's heading from its controller: clears its turn rates, takes the base angles from the controller's preset (or the heading from its default yaw), adds the stick turn derived from func_80274A90_de of the two stick axes, nudges it up for flag 0x40 and down for flag 0x80, caps it at the limit, optionally records the heading and the pitch step over the step count and the current pitch, and finally maps the heading through the 60-entry curve table D_800CB8EC with linear interpolation. The turn is truncated to 16 bits into an int, and the next table index is its own s16. */
extern struct Bytes12 *func_80258BDC_de(s32, s32);
extern s16 func_802AD270_de(f32);

extern s32 func_8025E584_de(Controller_func_80259C5C_de *);
extern s32 func_8025E590_de(Controller_func_80259C5C_de *);


void func_80259C5C_de(ViewRecAtB0 *view, Controller_func_80259C5C_de *controller, s32 flags) {
    s16 x;
    s16 y;
    f32 fx;
    f32 fy;
    s32 turn;
    f32 diff;
    f32 position;
    s16 index;
    s16 next;
    f32 base;
    f32 result;
    struct Motion *motion;
    struct Angles *angles;

    motion = &view->motion;
    angles = &view->angles;
    motion->rate1 = motion->rate2 = 0.0f;
    if (controller->preset != -1) {
        *(struct Bytes12 *)angles = *func_80258BDC_de(view->presets, controller->preset);
    } else {
        angles->heading = func_802AD270_de(controller->yaw);
    }
    x = func_8025E584_de(controller);
    y = func_8025E590_de(controller);
    fy = y;
    fx = x;
    turn = (s16)(s32)(fx + ((func_80274A90_de(fy, fx)) < 0.0f ? -(func_80274A90_de(fy, fx)) : (func_80274A90_de(fy, fx))));
    angles->heading = func_802AD270_de(RW_BITS_TO_FLOAT(angles->heading) + turn);
    if (flags & 0x40) {
        angles->heading = func_802AD270_de(RW_BITS_TO_FLOAT(angles->heading) + D_800C3F0C_de);
    }
    if (flags & 0x80) {
        angles->heading = func_802AD270_de(RW_BITS_TO_FLOAT(angles->heading) - D_800C3F10_de);
    }
    if (RW_BITS_TO_FLOAT(angles->heading) >= D_800C3F14_de) {
        angles->heading = func_802AD270_de(D_800C3F14_de);
    }
    if (controller->flags & 2) {
        motion->heading = RW_BITS_TO_FLOAT(angles->heading);
        diff = RW_BITS_TO_FLOAT(angles->pitch);
        diff -= RW_BITS_TO_FLOAT(angles->target);
        if (angles->steps == 0) {
            view->pitchStep = 0.0f;
        } else {
            view->pitchStep = diff / angles->steps;
        }
        view->pitch = RW_BITS_TO_FLOAT(angles->pitch);
    }
    position = (RW_BITS_TO_FLOAT(angles->heading) + D_800C3F18_de) * D_800C3F1C_de;
    index = position;
    if (index != position) {
        next = index + 1;
        base = D_800CB8EC[index];
        result = base + (position - index) * (D_800CB8EC[next] - base);
    } else {
        result = D_800CB8EC[index];
    }
    motion->heading = result;
    angles->heading = func_802AD270_de(result);
}
