#ifndef COMMON_OBJRECAT20V1_H
#define COMMON_OBJRECAT20V1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"


struct ObjRecAt20V1;
typedef struct ObjRecAt20V1 ObjRecAt20V1;



extern void SetN64_SetFrameDirection(void *arg0, void *arg1);


struct ObjRecAt20V1;

extern void SetN64_OnFrameComplete(void *schedule);

extern void SetN64_ClearFrameDirection(void *arg0);


#endif
