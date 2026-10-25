#ifndef AUDIO_2_INTEGERSTATE1DC4_H
#define AUDIO_2_INTEGERSTATE1DC4_H
#include "TYPES.H"

struct ObjRecAt2B9C;
typedef struct ObjRecAt2B9C ObjRecAt2B9C;

struct SortTable;
typedef struct SortTable SortTable;

struct ContextRecAt2BC0;
extern void *func_80258BF4_de(struct ContextRecAt2BC0 *arg0, int arg1);

struct SceneRecAt2B5C;
struct SceneRecAt2B5C {
    char pad0[0x130];
    s32 lastPick;
    char pad134[0x2B54 - 0x134];
    s32 count;
    s32 ids;
    s32 *weights;
};

struct SceneRecAt2B5C;
typedef struct SceneRecAt2B5C SceneRecAt2B5C;

extern s32 func_80259038_de(SceneRecAt2B5C *scene, s16 id, s16 avoid);

struct SortTable;
struct SortTable {
    char unknown00[0xE];
    s16 count;
    u32 entries[1];
};

extern void func_80258F6C_de(SortTable *table);

extern float D_800C8FE0;

extern void func_80258B94_de(struct ContextRecAt2BC0 *arg0, int arg1);

extern void func_80258BBC_de(struct ContextRecAt2BC0 *object, float value);

extern int func_80258D2C_de(void *object);

struct ObjRecAt2B9C;
struct ObjRecAt2B9C {
    char pad[0x2B9C];
    int level;
};

extern char *func_80258BC4_de(char *object, int index);

extern void func_80258D38_de(struct ContextRecAt2BC0 *arg0, int arg1);

extern int func_80258FF4_de(char *arg0, int id);

extern void *func_80258BDC_de(struct ContextRecAt2BC0 *arg0, int arg1);

typedef struct Slot_func_80258FF4_de Slot_func_80258FF4_de;

extern double D_800C3EE8_de;

extern void func_80258B8C_de(struct ContextRecAt2BC0 *arg0, float arg1);

extern float D_800C8FE4;
#endif
