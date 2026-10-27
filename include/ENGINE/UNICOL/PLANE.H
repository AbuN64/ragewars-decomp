#ifndef ENGINE_UNICOL_PLANE_H
#define ENGINE_UNICOL_PLANE_H
#include "COMMON/OUTPUT.H"
#include "COMMON/VECTOR3.H"
#include "TYPES.H"
extern s32 Plane_TestPointNearPolygon(Polygon*polygon, CVector3*point, f32 radius);
extern void func_80240C8C_de(void *contactStorage);
extern s32 func_80241260_de(void *plane, CVector3 *testPoint);
#endif
