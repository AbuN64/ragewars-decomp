#ifndef COMMON_CCOLLISIONINFO2_T_H
#define COMMON_CCOLLISIONINFO2_T_H
#include "TYPES.H"

/* An object's collision response (SN debug type CCollisionInfo2_t, 28 bytes): the three
 * behaviours are bytes, the five response constants floats. */
typedef struct CCollisionInfo2_t {
    unsigned long dwFlags;
    char InstanceBehavior;
    char WallBehavior;
    char GroundBehavior;
    char unusedpad;
    float GravityAcceleration;
    float BounceReturnEnergy;
    float GroundFriction;
    float AirFriction;
    float WaterFriction;
} CCollisionInfo2_t;

typedef char CCollisionInfo2_t_size_check[(sizeof(CCollisionInfo2_t) == 0x1C) ? 1 : -1];
#endif
