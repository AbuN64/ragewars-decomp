#ifndef COMMON_S1_H
#define COMMON_S1_H
#include "TYPES.H"
/* Initializes an empty list whose nodes keep their links at the given offsets. */
extern void func_80255CA0_de(IntrusiveList *list, s32 prevOffset, s32 nextOffset);

/* Appends node at the tail and returns the new count. */
extern s32 func_80255D14_de(IntrusiveList *list, void *node);

struct Pool80255ACC;



union func_80255F34_S1_U4;
union func_80255F34_S1_U4 {
    char * v0;
    int v1;
};

union func_80255F34_S1_U4;
typedef union func_80255F34_S1_U4 func_80255F34_S1_U4;








#endif
