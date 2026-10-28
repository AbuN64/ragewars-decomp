#ifndef SOUND_TRIPLERECAT8_H
#define SOUND_TRIPLERECAT8_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct TripleRecAt8;
typedef struct TripleRecAt8 TripleRecAt8;

struct ObjectLinks18;
typedef struct ObjectLinks18 ObjectLinks18;

struct ItemCode8024E130;
struct ItemCode8024E130 {
    unsigned char kind;
    char pad[0x33];
    void *value;
    unsigned flags;
};

extern int func_8024E610_de(void *actorStorage);


struct ObjectLinks18;
struct ObjectLinks18 {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[4];
    void *unk_14;
};


struct LevelActor;
extern int func_8024E2B0_de(struct LevelActor *actor);

struct TripleRecAt8;
struct TripleRecAt8 {
    f32 a;
    s32 b;
    f32 c;
};

struct Object_func_8024E80C_de;
struct StateFlags;
struct Object_func_8024E80C_de {
    char pad[0x14];
    struct StateFlags *key;
};

extern s32 func_8024E208_de(char *actor);

extern float D_800C3D74_de;
#endif
