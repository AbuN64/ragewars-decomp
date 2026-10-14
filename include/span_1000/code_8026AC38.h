#ifndef UNBAKE_SPAN_1000_CODE_8026AC38_H
#define UNBAKE_SPAN_1000_CODE_8026AC38_H
#include "types.h"
#include "gfx.h"
#include "common/types_1dc8418c21db.h"
struct ObjectState18;
typedef struct ObjectState18 ObjectState18;

struct Mesh;
struct Mesh {
    u32 list;
    u32 matrix;
    u32 aux;
    u32 vertices;
    u16 scaleS;
    u16 scaleT;
    s32 segmented;
    s32 unused;
    struct Mesh *next;
};

struct Mesh;
typedef struct Mesh Mesh;

struct Material18;
struct Material18 {
    u32 flags;
    char pad4[0x13];
    u8 alpha;
};

struct Material18;
typedef struct Material18 Material18;

struct Group18;
struct Group18 {
    char pad0[3];
    s8 mode;
    Material18 *material;
    Mesh *meshes;
    char padc[8];
    struct Group18 *next;
};

struct ItemRecAt1C;
struct ItemRecAt1C {
    s32 *data;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    s32 unk18;
    struct ItemRecAt1C *next;
};

struct Source_func_8026BC60_de;
struct Source_func_8026BC60_de {
    s32 flags;
    u16 id;
    u8 pad6[0x12];
    u16 unk18;
    u16 unk1A;
};

struct ItemRecAt1C;
struct Node_func_8026BC60_de;
struct Source_func_8026BC60_de;
struct Node_func_8026BC60_de {
    u32 key;
    struct Source_func_8026BC60_de *source;
    struct ItemRecAt1C *head;
    struct ItemRecAt1C *tail;
    struct Node_func_8026BC60_de *prev;
    struct Node_func_8026BC60_de *next;
    struct Node_func_8026BC60_de *left;
    struct Node_func_8026BC60_de *right;
};

extern void func_8026D980_de();

struct Material;
typedef struct Material Material;

extern void func_8026D8F8_de();

struct ItemRecAt1C;
typedef struct ItemRecAt1C ItemRecAt1C;

extern u32 D_800CC360;

extern void func_8026D88C_de();

extern float D_800C4668_de;

extern void func_8026C020_de();

struct Source_func_8026BC60_de;
typedef struct Source_func_8026BC60_de Source_func_8026BC60_de;

struct Owner104;
typedef struct Owner104 Owner104;

extern int D_80137288;

extern void func_8026BC60_de();

struct Frame118;
typedef struct Frame118 Frame118;

struct Node_func_8026BC60_de;
typedef struct Node_func_8026BC60_de Node_func_8026BC60_de;

struct Material;
struct Material {
    u8 pad[6];
    u8 flags;
};

struct Owner104;
struct Owner104 {
    char pad0[0x102];
    unsigned short flags;
};

struct Frame118;
struct Frame118 {
    char pad0[0x114];
    Gfx *commands;
};

struct Group18;
typedef struct Group18 Group18;

extern void func_8026D83C_de(void);

extern void func_8026D844_de();

extern void func_8026D9D0_de();

struct ObjectState18;
struct ObjectState18 {
    s32 flags;
    u8 padding4[0xC];
    u8 color[4];
    u8 fog[4];
};

extern void func_8026D834_de(void);


struct BankRecAt94;
struct Object_func_8028B274_de;
extern void func_8028B274_de(struct BankRecAt94 *, struct Object_func_8028B274_de *, s32, s32);

extern void func_80285570_de(void *, void *);

#endif
