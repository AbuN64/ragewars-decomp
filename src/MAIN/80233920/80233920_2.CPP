#include "span_1000/code_80233920.h"
#include "shared/particle_lighting.h"
#include "common/unused.h"
#include "shared/func_80214624_de_closed.h"
extern u32 D_800CD730;

/* Animate the shared light colors and direction, and both actor tint colors. */
void func_80233DFC_de(View *actor) {
    Vec3 direction;
    f32 phaseScale;
    f32 ambientScale;
    f32 ambient;
    f32 diffuse;
    f32 red;
    f32 green;
    f32 blue;
    s32 channel;
    s8 redByte;
    s8 greenByte;
    s8 blueByte;

    phaseScale = 1.0f;
    channel = 0;
    ambientScale = phaseScale;
    do {
        ambient = (ambientScale * (func_802B7130_de(
            phaseScale * (f32) D_800CD730 * ((f32) (channel + 2) * 4.0f) *
            0.01745329424738884f) * 16.0f)) + 16.0f + 48.0f;
        D_800CBC90[0].ambientCopy[channel] = D_800CBC90[0].ambient[channel] = (u32)ambient;
        diffuse = (((func_802B7130_de(
            phaseScale * (f32) D_800CD730 * ((f32) (channel + 2) * 4.0f) *
            0.01745329424738884f) * 64.0f) + 255.0f) - 64.0f) - 1.0f;
        D_800CBC90[0].diffuseCopy[channel] = D_800CBC90[0].diffuse[channel] = (u32)diffuse;
        channel += 1;
    } while (channel < 3);
    direction.x = func_802B7130_de((f32) (D_800CD730 * 6) * 0.01745329424738884f);
    direction.y = func_802B7130_de((f32) (D_800CD730 * 8) * 0.01745329424738884f);
    direction.z = func_802B6560_de((f32) (D_800CD730 * 10) * 0.01745329424738884f);
    func_8027207C_de(&direction);
    direction.x *= 120.0f;
    direction.y *= 120.0f;
    direction.z *= 120.0f;
    D_800CBC90[0].direction[0] = (u32)direction.x;
    D_800CBC90[0].direction[1] = (u32)direction.y;
    D_800CBC90[0].direction[2] = (u32)direction.z;
    red = (func_802B7130_de(2.0f * (phaseScale * (f32) D_800CD730) * 0.06981317698955536f) * 64.0f) + 128.0f;
    redByte = (u32)red & 0xF8;
    actor->color[0] = redByte;
    actor->secondaryColor[0] = redByte;
    green = (func_802B7130_de(phaseScale * (f32) D_800CD730 * 0.20943953096866608f) * 64.0f) + 128.0f;
    greenByte = (u32)green & 0xF8;
    actor->color[1] = greenByte;
    actor->secondaryColor[1] = greenByte;
    blue = (func_802B7130_de(phaseScale * (f32) D_800CD730 * 0.27925270795822144f) * 64.0f) + 128.0f;
    blueByte = (u32)blue & 0xF8;
    actor->color[2] = blueByte;
    actor->secondaryColor[2] = blueByte;
}
