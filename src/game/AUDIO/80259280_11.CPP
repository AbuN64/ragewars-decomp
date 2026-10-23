#include "include_asm.h"
#include "COMMON/LISTNODE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "COMMON/OBJRECAT4V6.H"
#include "AUDIO/8025A3EC.H"
#include "COMMON/UNUSED.H"
#include "AUDIO/80259280.H"
#include "COMMON/TRIPLE.H"
#include "COMMON.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "FX_2/80271B18.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "AUDIO/80259280_11.H"

/* Returns the stereo pan of a sound at a position for a listener: centre (0x40) without a listener, when
 * the sound is horizontally within a small radius or straight ahead; otherwise the horizontal direction
 * in listener space is compared with the forward axis through func_802745D0_de and func_802B7130_de, given the
 * side's sign, and scaled around the centre by D_800C8FF8. */

extern void func_80272BCC_de(void *, CVector3 *, CVector3 *);



s16 func_80259B10_de(CVector3 *position, GameplayCamera *listener) {
    CVector3 forward;
    CVector3 offset;
    CVector3 local;
    f32 pan;

    if (listener == 0) {
        return 0x40;
    }
    func_80271F68_de(&offset, &listener->position, position);
    if (offset.x * offset.x + offset.z * offset.z < D_800C3F00_de) {
        return 0x40;
    }
    func_80272BCC_de(&listener->unk160, &offset, &local);
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
extern struct Bytes12 *func_80258BDC_de(ContextRecAt2BC0 *, s32);
extern s16 func_802AD270_de(f32);

extern s32 func_8025E584_de(ControllerCode802591C0 *);
extern s32 func_8025E590_de(ControllerCode802591C0 *);


void func_80259C5C_de(ViewRecAtB0 *view, ControllerCode802591C0 *controller, s32 flags) {
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

#ifdef NON_MATCHING
/* Starts or retunes a voice's pan: seeds the gain from the sound table (the id compared with each entry of the
 * 0x1F pairs at D_800CB7F0 gives its scale), halves it when the shared flag says so, takes the pan angles from the
 * preset or the controller yaw, measures how loudly the listener hears it (squared distance falloff raised to the
 * power the voice kind asks for) and writes the left and right levels, interpolating the pan over the given
 * steps when the controller asks for a ramp. */
extern float D_800CB7F0[];
extern float D_800C3F34_de;
extern SoundEnvelope *func_80258BC4_de(ContextRecAt2BC0 *context, int index);
void func_80259F68_de(Voice *voice, ControllerCode802591C0 *control, s32 unused2) {
    u8 *colour;
    s32 i;
    f32 from;
    f32 to;
    f32 reach;
    f32 level;
    f32 dx, dy, dz;
    f32 distance;
    f32 span;
    s32 angle;
    s32 index;
    s32 stepped;
    SoundEnvelope *preset;

    colour = voice->context->field2B88;
    voice->volumeScale = D_800C3F20_de;
    if (voice->soundId < 0x100) {
        for (i = 0; i < 0x1F; i++) {
            if (voice->soundId == (s32)D_800CB7F0[i * 2]) {
                voice->volumeScale = D_800CB7F0[i * 2 + 1];
                break;
            }
        }
    }
    if (func_80245798_de()) {
        voice->volumeScale = voice->volumeScale * D_800C3F24_de;
    }
    if (control->field8 != -1) {
        preset = func_80258BC4_de(voice->context, control->field8);
        voice->envelope[0] = preset->flags;
        voice->envelope[1] = preset->initial;
        voice->envelope[2] = preset->target;
        voice->envelopeFrames = preset->frames;
        voice->envelopeExtra = preset->reserved8;
    } else {
        voice->envelope[0] = func_802AD270_de((f32)control->fieldF);
    }
    if ((control->flags & 0x800) || voice->fieldC0 == 1 || voice->context->field2B98 == 0) {
        reach = D_800C3F34_de;
        voice->field2C = reach;
        voice->field30 = reach;
    } else {
        from = (f32)colour[0] * D_800C3F28_de;
        to = (f32)colour[1] * D_800C3F28_de;
        reach = D_800C3F2C_de;
        if (from != reach) {
            reach = from;
            if (to != from) {
                reach = from + func_80274564_de(to - from);
            }
        }
        dx = voice->position.x - voice->context->field2B98->position.x;
        dy = voice->position.y - voice->context->field2B98->position.y;
        dz = voice->position.z - voice->context->field2B98->position.z;
        distance = dx * dx + dy * dy + dz * dz;
        level = 0.0f;
        if (!(D_800D0D10 <= distance)) {
            level = D_800C3F30_de - distance / D_800D0D10;
        }
        switch (voice->distanceMode) {
        case 0:
            level = level * level;
            level = level * level;
        case 1:
            level = level * level;
            voice->field2C = level;
            break;
        case 2:
            voice->field2C = level;
            break;
        default:
            level = 0.0f;
            voice->field2C = level;
            break;
        }
        voice->field30 = level;
    }
    if (control->flags & 4) {
        voice->left = (s32)func_802B2350(voice->envelope[0]);
        span = func_802B2350(voice->envelope[1]);
        span -= func_802B2350(voice->envelope[2]);
        if (voice->envelopeFrames == 0) {
            voice->envelopeStep = 0.0f;
        } else {
            voice->envelopeStep = span / voice->envelopeFrames;
        }
        voice->envelopeValue = func_802B2350(voice->envelope[1]);
        angle = (s32)func_802B2350(voice->envelope[0]);
        index = angle < 0 ? -angle : angle;
        stepped = (s32)((f32)D_80107FA0[index] * voice->envelopeValue);
        voice->left = (s32)((f32)stepped * reach);
        index = angle < 0 ? -angle : angle;
        voice->envelope[0] = func_802AD270_de((f32)D_80107FA0[index] * reach);
        voice->right = (s32)func_802B2350(voice->envelope[0]);
    } else {
        angle = (s32)func_802B2350(voice->envelope[0]);
        index = angle < 0 ? -angle : angle;
        voice->left = (s32)((f32)D_80107FA0[index] * reach);
        voice->right = voice->left;
    }
}
#else
INCLUDE_ASM("span_1000", func_80259F68_de);
#endif
