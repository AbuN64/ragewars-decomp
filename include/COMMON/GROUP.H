#ifndef COMMON_GROUP_H
#define COMMON_GROUP_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Work80244494;
typedef struct Work80244494 Work80244494;


struct Group;

extern void func_802458D8_de();

extern void func_8024570C_de();


extern void func_802458F8_de(void);

extern int func_8024576C_de();




struct VectorPair;

struct Group;
typedef struct Group Group;


extern int D_800CB418_de;

extern float D_800C37B0_de;






struct VectorPair;
typedef struct VectorPair VectorPair;



struct Work80244494;


struct func_80244E48_S1;
typedef struct func_80244E48_S1 func_80244E48_S1;




struct MotionSurface;

extern s32 func_802457E0_de(void);



struct GameState;
struct GameState {
    s32 busy;
    char pad4[0x18B0];
    s32 paused;
};

extern int func_80245908_de();

struct func_80244E48_S1;
struct func_80244E48_S1 {
    char pad0[0x40];
    s32 unk40;
    char pad40[0x50 - 0x40 - sizeof(s32)];
    s32 unk50;
    char pad50[0x54 - 0x50 - sizeof(s32)];
    s32 unk54;
    char pad54[0x5C - 0x54 - sizeof(s32)];
    s32 unk5C;
    char pad5C[0xD8 - 0x5C - sizeof(s32)];
    s32 unkD8;
    char padD8[0x108 - 0xD8 - sizeof(s32)];
    s32 unk108;
    char pad108[0x10C - 0x108 - sizeof(s32)];
    s32 unk10C;
    char pad10C[0x110 - 0x10C - sizeof(s32)];
    s32 unk110;
    char pad110[0x114 - 0x110 - sizeof(s32)];
    s32 unk114;
};

struct GameState;
typedef struct GameState GameState;


extern int func_80245764_de();

extern void Camera_EndSequence();



extern int D_800CB420_de;


extern void func_802458C4_de();

extern int D_800CB41C_de;

#endif
