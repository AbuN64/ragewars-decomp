#ifndef UNBAKE_SPAN_1000_CODE_802BB67C_H
#define UNBAKE_SPAN_1000_CODE_802BB67C_H
#include "TYPES.H"
#include "shared/func_802BB8B0_de_closed.h"
struct Node802C07B0;
typedef struct Node802C07B0 Node802C07B0;

struct NodeRecAt1C;
struct NodeRecAt1C {
    void *next;
    void *prev;
    u64 field8;
    u64 field10;
    s32 field18;
    s32 field1C;
};

struct Node802C07B0;
struct Node802C07B0 {
    s32 field0;
    s32 field4;
    u64 field8;
    u64 field10;
    void *field18;
    void *field1C;
};

extern void func_802BB9F8_de();

extern void func_802BBC20_de();


struct ThreadNode;
struct ThreadNode {
    struct ThreadNode *next;
    s32 priority;
    struct ThreadNode **queue;
    s32 unk0C;
    u16 state;
};

struct ThreadNode;
typedef struct ThreadNode ThreadNode;

struct NodeRecAt1C;
typedef struct NodeRecAt1C NodeRecAt1C;

#endif
