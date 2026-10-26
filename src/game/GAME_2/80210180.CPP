#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("span_1000", Nav_CheckCloseAttackRoute);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2224[3] = {
    0x00804021, 0x00854821, 0x0109082B,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C2224[3] = {
    0x3FE52EDF, 0x3F800000, 0x3FE52EDF,
};
#endif
#endif

#if !(defined(VERSION_EU)) || (defined(NON_MATCHING) && (defined(VERSION_EU)))
/* Route-following check for a computer driver's brain: when it has a target at 0x64, it calls UpdateCloseAttack if func_802099B4_de reports the target reached, and again when its route node at 0xC (unless -1) lies closer than 100 to the position Nav_GetControllerPosition gives; always returns one. */
typedef struct Brain {
    char pad0[0xC];
    s32 node;
    char pad10[0x64 - 0x10];
    void *target;
} Brain;

extern char D_8013B364[];

extern s32 Nav_HasLineOfSight(Brain *, void *);
extern void UpdateCloseAttack(Brain *arg0);
extern void *Nav_GetControllerPosition(Brain *arg0);
extern void *Nav_GetGraphPoint(char *, s32);
extern f32 GraphU64_GetPointDistance(void *, void *);

s32 Nav_CheckCloseAttackRoute(Brain *brain) {
    void *pos;

    if (brain->target == 0) {
        return 1;
    }
    if (Nav_HasLineOfSight(brain, brain->target) != 0) {
        UpdateCloseAttack(brain);
    }
    if (brain->node == -1) {
        return 1;
    }
    pos = Nav_GetControllerPosition(brain);
    if (GraphU64_GetPointDistance(pos, Nav_GetGraphPoint(D_8013B364, brain->node)) < 100.0f) {
        UpdateCloseAttack(brain);
    }
    return 1;
}
#endif
