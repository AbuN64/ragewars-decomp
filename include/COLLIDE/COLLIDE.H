#ifndef COLLIDE_COLLIDE_H
#define COLLIDE_COLLIDE_H
#include "COMMON/CCOLLISIONSETUP_T.H"
extern void CCollision_Initialize(void);
extern void CCollision_ResetResult(void);
extern void CCollision_ApplySetupTable(CCollisionSetup_t *setupTable);
#endif
