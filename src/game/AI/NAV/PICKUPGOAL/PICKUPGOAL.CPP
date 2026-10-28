#include "include_asm.h"
#include "COMMON/OBJECTLINKS1458.H"
#include "TYPES.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "AI/NAV/NAV_SETPICKUPGOALWEIGHTS.H"

/* 8020EAE0.CPP */
/* Commits a pending selection to the controller D_8013B364: returns at once when nothing is
   requested at 0xC, the request is already active at 0x4, or it continues the committed request at
   0x28 through valid links at 0x14 and 0x18 that are already current or that Portal_FindLinkIndex joins;
   otherwise it resets the controller, runs the pending release passes flagged at 0x2F4, 0x2F8 and
   0x2FC, rebuilds through Nav_SetPickupGoalWeights, loads the request, clears the controller's link word,
   reselects the active entry, copies the four link words from 0x14 and records the request as
   committed. Always returns 1. Written from its own assembly with early returns. */

extern s32 D_8013B364;
extern s32 Portal_FindLinkIndex(s32 *, s32, s32);
extern void Portal_ResetSearchState(s32 *);
extern void Nav_SetLinkedActorNodeCosts(void *);
extern void Nav_AccumulateNodeTickCosts(void *);
extern void Nav_AddPickupCategoryCosts(void *);
extern void Route_ClearGoalList(s32 *);
extern void Nav_AddGoalNode(s32 *, s32);
extern void Route_SearchPathByKey(s32 *, s32);
extern void Route_ReconstructSearchPath(s32 *, s32 *, s32);

s32 Nav_RebuildRequestedGoalRoute(void *arg0) {
    s32 *base;
    s32 requested;
    s32 current;
    s32 link;

    base = &D_8013B364;
    if (base == 0) {
        return 1;
    }
    requested = ((Func8020ED50Arg *)arg0)->fieldC;
    if (requested == -1) {
        return 1;
    }
    current = ((Func8020ED50Arg *)arg0)->field4;
    if (current == requested) {
        return 1;
    }
    if (((Func8020ED50Arg *)arg0)->committed == requested) {
        link = ((Func8020ED50Arg *)arg0)->links[0];
        if (link != -1 && ((Func8020ED50Arg *)arg0)->links[1] != -1) {
            if (current == link) {
                return 1;
            }
            if (Portal_FindLinkIndex(base, current, link) != -1) {
                return 1;
            }
        }
    }
    Portal_ResetSearchState(base);
    if (((Func8020ED50Arg *)arg0)->releaseFlags[0] != 0) {
        Nav_SetLinkedActorNodeCosts(arg0);
    }
    if (((Func8020ED50Arg *)arg0)->releaseFlags[1] != 0) {
        Nav_AccumulateNodeTickCosts(arg0);
    }
    if (((Func8020ED50Arg *)arg0)->releaseFlags[2] != 0) {
        Nav_AddPickupCategoryCosts(arg0);
    }
    Nav_SetPickupGoalWeights(arg0);
    Route_ClearGoalList(base);
    Nav_AddGoalNode(base, ((Func8020ED50Arg *)arg0)->fieldC);
    base[6] = -1;
    Route_SearchPathByKey(base, ((Func8020ED50Arg *)arg0)->field4);
    Route_ReconstructSearchPath(base, &((Func8020ED50Arg *)arg0)->links[0], 4);
    ((Func8020ED50Arg *)arg0)->linkState = 0;
    ((Func8020ED50Arg *)arg0)->selection = -1;
    ((Func8020ED50Arg *)arg0)->committed = ((Func8020ED50Arg *)arg0)->fieldC;
    return 1;
}

extern u8 D_8011D8D0[];
extern s32 Portal_FindNearestPointIndex(s32 *, void *);
extern u8 *Portal_FindSearchNode(s32 *, s32);
/* Finds the nav node of obj and stores weight as its goal weight (+0x18). */
#define navigationNodeOf(graph, obj, out) do { (out) = Portal_FindSearchNode((graph), Portal_FindNearestPointIndex((graph), (obj))); } while (0)
#define navigationSetGoalWeight(graph, obj, weight) do { u8 *node_; navigationNodeOf(graph, obj, node_); *(f32 *)(node_ + 0x18) = (weight); } while (0)
void Nav_SetPickupGoalWeights(void *arg) {
    s32 *ctrl = &D_8013B364;
    u8 *node;
    u8 *link;
    s32 i;
    u8 *tbl = D_8011D8D0;
    if (ctrl == 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        for (node = *(u8 **)(tbl + 0xFC28 + i * 0x14); node != 0; node = *(u8 **)(node + 0x1EC)) {
            switch (*(u16 *)(node + 4)) {
            case 0x41E:
                link = *(u8 **)(node + 0x12C);
                if (link == 0 || *link != 1 || !(*(s32 *)(link + 0x100) & 0x300000) || link == (u8 *)*(s32 **)arg) {
                    break;
                }
            case 0x402:
            case 0x404:
            case 0x40B:
            case 0x40F:
                navigationSetGoalWeight(ctrl, node + 8, 51200.0f);
                break;
            default:
                break;
            }
        }
    }
}

/* 800C6E84_11.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8020EDCC_C7BCC[3] = {
    0x47480000, 0x4123D70A, 0xC4199999,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C21C8[2] = {
    0x002301B0, 0x00230104,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8020EDCC_C7BCC_us_rev1.c */
const unsigned int D_blob_db5938c31029476434e9[1] = {
    0x47480000,
};

/* ROM-grounded data: src/rw_pool_8020EE50_C7BD0_us_rev1.c */
const unsigned int D_blob_b357b72b76d4c13fda02[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_8020EEA4_C7BD4_us_rev1.c */
const unsigned int D_blob_a86961089d07a2efc2e5[1] = {
    0xC4199999,
};
#endif
