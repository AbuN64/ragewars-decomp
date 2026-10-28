#ifndef COMMON_INTEGERSTATE1250_H
#define COMMON_INTEGERSTATE1250_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern f32 D_800C7E00;

struct IntegerState1250;
typedef struct IntegerState1250 IntegerState1250;

struct ObjectState12C4;
typedef struct ObjectState12C4 ObjectState12C4;


extern int func_8022B460_de(char *object);


struct RecordCode8022AE90;
typedef struct RecordCode8022AE90 RecordCode8022AE90;

struct ObjectState16DA;

extern int func_8022BA90_de(void);





struct Timer;
typedef struct Timer Timer;

struct ScoreTable;
struct ScoreTable {
    u8 pad00[0x3C];
    short value[8];
};
struct RecordCode8022AE90;
struct ScoreTable;
struct RecordCode8022AE90 {
    u8 pad0000[0x5D8];
    struct ScoreTable *scores;
    u8 pad05DC[0x16E0 - 0x5DC];
    struct RecordCode8022AE90 *next;
    u8 pad16E4[4];
};

struct ObjectState12C4;

struct ObjRecAt120C;
typedef struct ObjRecAt120C ObjRecAt120C;

struct Timer;
struct Timer {
    float m_DamagePerFrame;
    float m_FramesRemaining;
    int kind;
    float m_TotalDamage;
    float m_DamageIssued;
    int m_bIsInflator;
};

struct Obj_func_8022B550_de;


struct IntegerState1218;


struct ObjectState13E4;



struct ObjRecAt120C;


extern void func_8022B484_de(char *player);

struct ObjectState16DA;
typedef struct ObjectState16DA ObjectState16DA;

struct Obj_func_8022B550_de;
typedef struct Obj_func_8022B550_de Obj_func_8022B550_de;

struct IntegerState16D4;



struct func_8022B08C_S2;

struct func_8022B08C_S1;

struct Context;
struct RecordCode8022AE90;
struct Context {
    u8 pad00[4];
    struct RecordCode8022AE90 *base;
    u8 pad08[0x18];
    struct RecordCode8022AE90 *head;
};


struct func_8022B08C_S1;
typedef struct func_8022B08C_S1 func_8022B08C_S1;

extern float D_800C7E08;

struct IntegerState11C0;

struct ObjectState13E4;
typedef struct ObjectState13E4 ObjectState13E4;

struct Context;
typedef struct Context Context;

extern void *func_8022BA0C_de(Context *context);


struct IntegerState16D4;
typedef struct IntegerState16D4 IntegerState16D4;


struct func_8022B08C_S2;
typedef struct func_8022B08C_S2 func_8022B08C_S2;




struct IntegerState1250;


struct IntegerState1218;
typedef struct IntegerState1218 IntegerState1218;



struct IntegerState11C0;
typedef struct IntegerState11C0 IntegerState11C0;

#endif
