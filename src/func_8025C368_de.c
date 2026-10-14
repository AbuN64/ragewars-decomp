#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"
#include "shared/gameplay_camera.h"

/* Returns how strongly a listener at 0x128 hears a source at 0x34: one minus the squared distance over the squared range D_800D0D10 (zero beyond it), shaped by the source's curve at 0x44 as the eighth power, the square or the plain value. */




extern f32 D_800C3F98_de[];






f32 func_8025C368_de(char *source, char *listener)
{
    SoundSpatialSource *sound = (SoundSpatialSource *)source;
    GameplayCamera *camera = (GameplayCamera *)listener;
    Vec3 *a = &sound->position;
    Vec3 *b = &camera->position;
    f32 dx = a->x - b->x;
    f32 dy;
    f32 dz;
    f32 d;
    f32 t;

    dx *= dx;
    dy = a->y - b->y;
    dy *= dy;
    dz = a->z - b->z;
    dz *= dz;
    d = dx + dy + dz;
    if (d >= D_800D0D10) {
        t = 0.0f;
    } else {
        t = D_800C3F98_de[1] - d / D_800D0D10;
    }
    switch (sound->curve) {
    case 2:
        return t;
    case 0:
        t *= t;
        t *= t;
    case 1:
        return t * t;
    default:
        return 0.0f;
    }
}
