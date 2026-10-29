#ifndef COMMON_CTX_H
#define COMMON_CTX_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Func802C1F10Node;
struct Func802C1F10Node {
    s32 runQueueNextWord;
    s32 priority;
    void *queue;
    struct Func802C1F10Node *next;
    u16 state;
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
