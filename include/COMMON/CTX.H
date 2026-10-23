#ifndef COMMON_CTX_H
#define COMMON_CTX_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Func802C1F10Node;
struct Func802C1F10Node {
    s32 field0;
    s32 field4;
    void *field8;
    struct Func802C1F10Node *next;
    u16 field10;
};





struct Ctx;
typedef struct Ctx Ctx;

struct Ctx;
struct Ctx {
    OSMesgQueue *cur;
    s32 f4;
};



struct Func802C1F10Node;
typedef struct Func802C1F10Node Func802C1F10Node;


#endif
