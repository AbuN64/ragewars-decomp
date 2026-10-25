#ifndef COMMON_OBJECTLINKS14_H
#define COMMON_OBJECTLINKS14_H
#include "TYPES.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Node8020BC50;
struct Node8020BC50 {
    s32 key;
    f32 value;
    s32 state;
    s32 fieldC;
    struct Node8020BC50 *next;
    s32 field14;
    s32 field18;
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    s32 field2C;
    s32 field30;
    char * owner;
};

struct ObjectLinks14;
typedef struct ObjectLinks14 ObjectLinks14;

struct Node;
struct Node {
    int id;
    char pad4[0xC];
    struct Node *next;
    char pad14[0x18];
    int active;
};

struct ObjectState10;
typedef struct ObjectState10 ObjectState10;


extern float D_800C1D6C_de;

struct Node8020D114;
struct Node8020D114 {
    s32 value;
    char pad04[0xC];
    struct Node8020D114 *next;
    char pad14[0x1C];
    struct Node8020D114 *parent;
};

struct Node8020D114;



struct EntryList8020CCE8;
struct IntPair;
struct EntryList8020CCE8 {
    s32 pad0[2];
    struct IntPair *table;
    s32 count;
};

struct Node8020BC50;
typedef struct Node8020BC50 Node8020BC50;


struct Obj_func_8020D220_de;
typedef struct Obj_func_8020D220_de Obj_func_8020D220_de;

struct Table8020BC50;
typedef struct Table8020BC50 Table8020BC50;

struct Obj8020BC50;
typedef struct Obj8020BC50 Obj8020BC50;


struct ObjectLinks14;
struct ObjectLinks14 {
    char pad0[0x4];
    int unk_4;
    char pad4[0x10 - 0x4 - sizeof(int)];
    char * unk_10;
};

struct EntryList8020CCE8;
typedef struct EntryList8020CCE8 EntryList8020CCE8;

struct Graph;
typedef struct Graph Graph;



struct Node8020D114;
typedef struct Node8020D114 Node8020D114;



union ObjectState4;
typedef union ObjectState4 ObjectState4;

struct Table8020BC50;
struct Table8020BC50 {
    s32 stride;
    char data[4];
};

struct Obj8020BC50;
struct Obj8020BC50 {
    Table8020BC50 *records;
    s32 count;
    char pad8[8];
    Table8020BC50 *links;
    char pad14[4];
    s32 result;
    f32 value;
    s32 selected;
    Node8020BC50 *nodes;
};

union ObjectState4;
union ObjectState4 {
    u32 v0;
    u16 v1;
};

struct ObjectState10;
struct ObjectState10 {
    char pad0[0xC];
    ObjectState4 unk_C;
};

struct Node;
struct Obj_func_8020D220_de;
struct Obj_func_8020D220_de {
    char pad[0x24];
    struct Node *list;
    char pad28[0x10];
    int ids[64];
};



extern float D_800C1D68_de;






struct Node;
typedef struct Node Node;


extern float D_800C1D8C_de;


struct LinkTable;
struct LinkTable {
    int stride;
    int pad4;
    Link first;
};
struct Graph;
struct LinkTable;
struct Graph {
    char pad0[8];
    struct LinkTable *links;
    int count;
};




#include "COMMON/AIPROFILE.H"



#include "COMMON/REC.H"
typedef struct NavigationPlatform {
    u8 pad0[8];
    CVector3 pos;
    u8 pad14[4];
    ActorMotionResource *resource;
    u8 pad1C[0xC8];
    u16 objectId;
    u8 padE6[0x8A];
    ActorMotionState motion;
    u8 pad2E0[8];
} NavigationPlatform;
typedef struct PlatformRoute { s16 reserved; s16 count; } PlatformRoute;
#endif
