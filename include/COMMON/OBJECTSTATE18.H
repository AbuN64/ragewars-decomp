#ifndef COMMON_OBJECTSTATE18_H
#define COMMON_OBJECTSTATE18_H
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
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

struct ResourceSource;
struct ResourceSource {
    s32 flags;
    u16 id;
    u8 pad6[0x12];
    u16 unk18;
    u16 unk1A;
};

struct ItemRecAt1C;
struct Node_func_8026BC60_de;
struct ResourceSource;
struct Node_func_8026BC60_de {
    u32 key;
    struct ResourceSource *source;
    struct ItemRecAt1C *head;
    struct ItemRecAt1C *tail;
    struct Node_func_8026BC60_de *prev;
    struct Node_func_8026BC60_de *next;
    struct Node_func_8026BC60_de *left;
    struct Node_func_8026BC60_de *right;
};

extern void Geometry_BeginModelBatch();

struct Material;
typedef struct Material Material;

extern void func_8026D8F8_de();

struct ItemRecAt1C;
typedef struct ItemRecAt1C ItemRecAt1C;

extern u32 D_800CC360;

extern void Geometry_SelectEffectModes();

extern float D_800C4668_de;


struct ResourceSource;
typedef struct ResourceSource ResourceSource;

struct Owner104;
typedef struct Owner104 Owner104;

extern int D_80137288;



struct Node_func_8026BC60_de;
typedef struct Node_func_8026BC60_de Node_func_8026BC60_de;

struct Material;

struct Owner104;


struct Group18;
typedef struct Group18 Group18;

extern void func_8026D83C_de(void);

extern void func_8026D844_de();

extern void Geometry_FlushModelBatch();

struct ObjectState18;



struct BankRecAt94;
struct Object_func_8028B274_de;

struct MeshMaterial;
struct PackedMeshMaterial;
#endif
