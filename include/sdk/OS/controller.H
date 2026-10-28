#ifndef SDK_OS_CONTROLLER_H
#define SDK_OS_CONTROLLER_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
extern void osContGetReadData(ContPad *data);
extern void __osPackReadData();
#endif
