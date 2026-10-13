#include "shared/gameplay_camera.h"
#include "shared/gameplay_movement.h"
#include "span_C76B0/data.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"
#include "types.h"
/* Produces a random shake offset for an object: looks up the object's model entry in D_8011FE88 and
 * zeroes the offset when there is none; otherwise eases the horizontal and vertical shake amplitudes
 * at 0xF4 and 0xF8 toward the pair D_800C8668 when the entry is flagged 0x10000 (toward zero when not)
 * and draws each offset component at random within the scaled amplitudes. */







extern func_8020CA10_G1 D_800C3580_de;

extern func_8020CA10_G1 D_800C3584_de;

extern func_8020CA10_G1 D_800C3588_de;

extern func_8020CA10_G1 D_800C358C_de;
extern void *func_8028B2F8_de(char *, s32);









void func_80239EA4_de(void *arg0, Vec3 *out) {
    Shared_func_80234FDC_S2 *o = arg0;
    f32 value;
    Shared_Surface *entry;
    f32 targetX;
    f32 targetY;
    f32 scale;

    targetY = 0.0f;
    targetX = targetY;
    entry = func_8028B2F8_de(&D_8011FE88, (s32)o->unk58);
    if (entry == 0) {
        out->x = targetY;
        out->y = targetY;
        out->z = targetY;
        return;
    }
    if (entry->flags & 0x10000) {
        targetX = D_800C8668;
        targetY = D_800C357C_de;
    }
    value = o->shakeHorizontal + (targetX - o->shakeHorizontal) * D_800C3580_de.unk0;
    scale = D_800C3584_de.unk0;
    o->shakeHorizontal = value;
    o->shakeVertical += (targetY - o->shakeVertical) * D_800C3588_de.unk0;
    out->x = func_80274A90_de(-o->shakeHorizontal * scale, o->shakeHorizontal * scale);
    out->y = func_80274A90_de(0.0f, o->shakeVertical * D_800C358C_de.unk0);
    value = -o->shakeHorizontal * scale;
    out->z = func_80274A90_de(value, o->shakeHorizontal * scale);
}
