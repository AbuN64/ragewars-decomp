#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "stddef.h"
#include "span_1000/code_80277444.h"
#include "shared/particle_lighting.h"
#include "shared/func_80425674_de_layout.h"
/* Matrices occupy the source record's opaque storage at +0x20 and +0x60. */
extern void func_80272898_de(void *, Vec3 *, Vec3 *);
extern s32 func_80277128_de(void *, f32, f32, f32, Vec3 *, f32 *);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80272A10_de(void *, Vec3 *, Vec3 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern f32 func_80278890_de(void *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);

void func_80289970_de(Object_func_802773D4_de **arg0, s32 arg1, Vec3 *arg2, Shared_ParticleLighting *arg3) {
    Shared_Game *settings;
    f32 weights[128];
    Vec3 directions[128];
    Vec3 transformed;
    Vec3 combinedDirection;
    Vec3 color;
    Vec3 ambient;
    Vec3 backLight;
    Vec3 diffuse;
    Vec3 contribution;
    Vec3 localDirection;
    Vec3 translatedDirection;
    Vec3 animationColor;
    Vec3 animatedContribution;
    Object_func_802773D4_de *animatedVolume;
    Vec3 *transformedPosition;
    Vec3 *colorPtr;
    Vec3 *animationColorPtr;
    Vec3 *direction;
    f32 zero;
    f32 temp_fs0;
    f32 brightness;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 var_fs0f;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    f32 var_fv0f_4;
    f32 var_fv0f_5;
    f32 var_fv0f_6;
    f32 var_fv0f_7;
    f32 var_fv0f_8;
    s32 sampleIndex;
    s32 lightIndex;
    Object_func_802773D4_de *volume;

    settings = &D_801462C8;
    brightness = (f32)(u32)settings->buttons * 0.003921568859368563f;
    animatedVolume = NULL;
    if (settings->flags & 0x4000) {
        arg3->ambientCopy[0] = 0;
        arg3->ambient[0] = 0;
        arg3->ambientCopy[1] = 0;
        arg3->ambient[1] = 0;
        arg3->ambientCopy[2] = 0;
        arg3->ambient[2] = 0;
        arg3->diffuseCopy[0] = 0;
        arg3->diffuse[0] = 0;
        arg3->diffuseCopy[1] = 0;
        arg3->diffuse[1] = 0;
        arg3->diffuseCopy[2] = 0;
        arg3->diffuse[2] = 0;
        arg3->direction[0] = 0x7F;
        arg3->direction[1] = 0;
        arg3->direction[2] = 0;
        return;
    }
    sampleIndex = 0;
    combinedDirection.x = combinedDirection.y = combinedDirection.z = 0.0f;
    ambient.x = ambient.y = ambient.z = 0.0f;
    backLight.x = backLight.y = backLight.z = 0.0f;
    diffuse.x = diffuse.y = diffuse.z = 0.0f;
    if (arg1 > 0) {

        
        transformedPosition = &transformed;
        do {
            volume = arg0[sampleIndex];
            func_80272898_de(volume->pad20, arg2, transformedPosition);
            if (func_80277128_de(volume, transformed.x, transformed.y, transformed.z, &localDirection, &weights[sampleIndex]) != 0) {
                func_80271F34_de(&translatedDirection, &localDirection, transformedPosition);
                func_80272A10_de(volume->pad20 + 0x40, &translatedDirection, &localDirection);
                func_80271F68_de(&directions[sampleIndex], arg2, &localDirection);
                func_8027207C_de(&directions[sampleIndex]);
                color = volume->direction;
                if ((u8)volume->padBA != 0) {
                    temp_fv0 = func_80278890_de(volume);
                    animationColor.x = temp_fv0;
                    animationColor.y = temp_fv0;
                    animationColor.z = temp_fv0;
                    func_80271F9C_de(&contribution, &animationColor, weights[sampleIndex] * volume->value);
                    animatedVolume = volume;
                    if (volume->flagB8 != 0) {
                        func_80271F9C_de(&contribution, &contribution, -1.0f);
                    }
                    func_80271F34_de(&ambient, &ambient, &contribution);
                }
                temp_fv0f = volume->value * 0.5f;
                temp_fs0 = 1.0f - temp_fv0f;
                func_80271F9C_de(&contribution, &color, weights[sampleIndex] * temp_fv0f);
                if (volume->flagB8 != 0) {
                    func_80271F9C_de(&contribution, &contribution, -1.0f);
                }
                func_80271F34_de(&ambient, &ambient, &contribution);
                weights[sampleIndex] *= temp_fs0;
                var_fv0f_2 = color.x; if (var_fv0f_2 < 0.0f) var_fv0f_2 = -var_fv0f_2;
                if (color.y < 0.0f) var_fv0f_3 = var_fv0f_2 - color.y; else var_fv0f_3 = var_fv0f_2 + color.y;
                if (color.z < 0.0f) temp_fs0 = var_fv0f_3 - color.z; else temp_fs0 = var_fv0f_3 + color.z;
                func_80271F9C_de(&contribution, &directions[sampleIndex], *&weights[sampleIndex]);
                func_80271F9C_de(&contribution, &contribution, temp_fs0);
                func_80271F34_de(&combinedDirection, &combinedDirection, &contribution);
                if (volume->flagB8 != 0) {
                    weights[sampleIndex] = -weights[sampleIndex];
                }
            } else {
                directions[sampleIndex].x = 0.0f;
                directions[sampleIndex].y = 0.0f;
                directions[sampleIndex].z = 0.0f;
                weights[sampleIndex] = 0.0f;
            }

            
            sampleIndex += 1;

        } while (sampleIndex < arg1);
    }
    func_8027207C_de(&combinedDirection);
    lightIndex = 0;
    if (arg1 > 0) {

        zero = 0.0f;
        colorPtr = &color;
        animationColorPtr = &animationColor;
        do {
            direction = &directions[lightIndex];
            temp_fs0 = (combinedDirection.x * direction->x) + (combinedDirection.y * direction->y) + (combinedDirection.z * direction->z);
            volume = arg0[lightIndex];
            var_fs0f = 1.0f - temp_fs0; if (temp_fs0 < zero) var_fs0f = 1.0f;
            var_fs0f *= 0.5f;
            color = volume->direction;
            temp_fs0 = 1.0f - var_fs0f;
            if (volume == animatedVolume) {
                temp_fv0_2 = func_80278890_de(volume);
                animationColor.x = temp_fv0_2;
                animationColor.y = temp_fv0_2;
                animationColor.z = temp_fv0_2;
                func_80271F9C_de(&animatedContribution, animationColorPtr, temp_fs0 * weights[lightIndex]);
                func_80271F34_de(&diffuse, &diffuse, &animatedContribution);
                func_80271F9C_de(&animatedContribution, animationColorPtr, var_fs0f * weights[lightIndex]);
                func_80271F34_de(&backLight, &backLight, &animatedContribution);
            }
            func_80271F9C_de(&contribution, colorPtr, temp_fs0 * weights[lightIndex]);
            func_80271F34_de(&diffuse, &diffuse, &contribution);


            func_80271F9C_de(&contribution, colorPtr, var_fs0f * weights[lightIndex]);
            func_80271F34_de(&backLight, &backLight, &contribution);
            lightIndex++;
        } while (lightIndex < arg1);
    }
    func_80271F9C_de(&backLight, &backLight, 0.5f);
    func_80271F34_de(&ambient, &ambient, &backLight);
    if (ambient.x < 0.0f) {
        diffuse.x += ambient.x;
    }
    if (ambient.y < 0.0f) {
        diffuse.y += ambient.y;
    }
    if (ambient.z < 0.0f) {
        diffuse.z += ambient.z;
    }
    var_fv0 = ambient.x;
    if (!(var_fv0 <= 255.0f)) var_fv0 = 255.0f;
    if (!(5.0f <= var_fv0)) var_fv0 = 5.0f;
    ambient.x = var_fv0 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_4 = ambient.y;
    if (!(var_fv0f_4 <= 255.0f)) var_fv0f_4 = 255.0f;
    var_fv0_2 = var_fv0f_4;
    if (!(5.0f <= var_fv0_2)) var_fv0_2 = 5.0f;
    ambient.y = var_fv0_2 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_5 = ambient.z;
    if (!(var_fv0f_5 <= 255.0f)) var_fv0f_5 = 255.0f;
    var_fv0_3 = var_fv0f_5;
    if (!(5.0f <= var_fv0_3)) var_fv0_3 = 5.0f;
    ambient.z = var_fv0_3 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_6 = diffuse.x;
    if (!(var_fv0f_6 <= 255.0f)) var_fv0f_6 = 255.0f;
    var_fv0_4 = var_fv0f_6;
    if (!(5.0f <= var_fv0_4)) var_fv0_4 = 5.0f;
    diffuse.x = var_fv0_4 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_7 = diffuse.y;
    if (!(var_fv0f_7 <= 255.0f)) var_fv0f_7 = 255.0f;
    var_fv0_5 = var_fv0f_7;
    if (!(5.0f <= var_fv0_5)) var_fv0_5 = 5.0f;
    diffuse.y = var_fv0_5 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_8 = diffuse.z;
    if (!(var_fv0f_8 <= 255.0f)) var_fv0f_8 = 255.0f;
    if (!(5.0f <= var_fv0f_8)) var_fv0f_8 = 5.0f;
    diffuse.z = var_fv0f_8 * (1.0f - brightness) + brightness * 255.0f;
    arg3->ambient[0] = arg3->ambientCopy[0] = (u32)ambient.x;
    arg3->ambient[1] = arg3->ambientCopy[1] = (u32)ambient.y;
    arg3->ambient[2] = arg3->ambientCopy[2] = (u32)ambient.z;
    arg3->diffuse[0] = arg3->diffuseCopy[0] = (u32)diffuse.x;
    arg3->diffuse[1] = arg3->diffuseCopy[1] = (u32)diffuse.y;
    arg3->diffuse[2] = arg3->diffuseCopy[2] = (u32)diffuse.z;
    arg3->direction[0] = (s32)(combinedDirection.x * 127.0f);
    arg3->direction[1] = (s32)(combinedDirection.y * 127.0f);
    arg3->direction[2] = (s32)(combinedDirection.z * 127.0f);
}
