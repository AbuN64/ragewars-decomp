#ifndef ENGINE_UNICOL_PLANE_H
#define ENGINE_UNICOL_PLANE_H
#include "COMMON/OUTPUT.H"
#include "COMMON/VECTOR3.H"
#include "TYPES.H"
extern s32 Plane_TestPointNearPolygon(Polygon*polygon, CVector3*point, f32 radius);
extern void CPlane_ResetContact(void *contactStorage);
extern s32 CPlane_IsPointBehind(void *plane, CVector3 *testPoint);
#endif
