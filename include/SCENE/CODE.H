#ifndef SCENE_CODE_H
#define SCENE_CODE_H
#include "TYPES.H"
#include "COMMON/SCENERECAT10C0.H"
typedef struct Bounds37 { f32 minX,minY,minZ,maxX,maxY,maxZ; } Bounds37;
typedef struct Item37 { u8 pad0[0xA0]; Bounds37 bounds; u8 padB8[8]; } Item37;
typedef struct Items37 { s32 stride, count; Item37 items[1]; } Items37;
typedef struct Resource37 { void *data; } Resource37;
typedef struct Region37 { Resource37 *resource; Bounds2D37 *bounds; s32 flags; } Region37;
typedef struct World37 { u8 pad0[0x1504]; s32 count; Region37 regions[1]; } World37;
#endif
