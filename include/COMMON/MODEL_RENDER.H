#ifndef COMMON_MODEL_RENDER_H
#define COMMON_MODEL_RENDER_H
#include "TYPES.H"
#include "COMMON/PARTICLE_LIGHTING.H"
/* Resource render entry points: matrices and lighting are caller-owned buffers. */
void func_8026B6A0_de(void **resource, void *owner, void *matrix, s32 segment, void *lights, void *textures, s32 pass);
void func_8026D4F0_de(void **resource, void *owner, void *matrix, s32 segment, void *lights, void *textures, s32 pass, u8 red, u8 green, u8 blue, u8 alpha);
void func_8026DA4C_de(void **resource, void *matrix, s32 segment, void *lights, void *textures, s32 pass);
void func_8026CBA4_de(void **resource, void *owner, void *matrix, s32 segment, Shared_ParticleLighting *lights, void *textures, s32 pass);
#endif
