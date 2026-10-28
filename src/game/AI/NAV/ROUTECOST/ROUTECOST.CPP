#include "include_asm.h"
#include "COMMON/OBJECTLINKS1458.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "TYPES.H"
#include "AI/NAV/PICKUPTARGET.H"

extern s32 Route_GetRouteRelation(void *relationTable, s32 sourceNode, s32 destinationNode);

extern s32 Portal_SearchRelatedGoalPath(void *obj, s32 key, s32 requested, void *owner);

/** Reset the float field of each occupied player slot's table entry to the default value. */


extern char *Portal_FindSearchNode(CNavData *, int);
extern CNavData D_8013B364;

extern void *Portal_GetGraphPoint(void *, s32);

s32 Nav_UpdateRouteIntermediateGoal(Func8020ED50Arg *owner) {
    s32 *base;

    base = &D_8013B364;
    if (base != 0) {
        if (owner->field10 == -1) {
            return 1;
        }
        if (owner->field4 == owner->field10) {
            return 1;
        }
        if (Route_GetRouteRelation(base, owner->field4, owner->field10) == 0) {
            owner->fieldC = Portal_SearchRelatedGoalPath(base, owner->field4, owner->field10, owner);
        }
    }
    return 1;
}

void Nav_SetLinkedActorNodeCosts(char *arg0) {
    CNavData *table = &D_8013B364;
    int i;
    float value;

    if (table != 0) {
        value = D_800C1EDC_de;
        for (i = 0; i < 10; i++) {
            Actor1DC *a = ((struct ObjectLinks40 *) (arg0 + (i * 4)))->unk_3C;
            if (a != 0) {
                ((struct ObjRecAt18V3 *) Portal_FindSearchNode(table, ((struct func_80203E78_S1 *) ((ObjectLinks1458 *) a->info)->unk_1454)->unk4))->unk18 = value;
            }
        }
    }
}

void Nav_AccumulateNodeTickCosts(void) {
    NavigationSearchNode *node;
    f32 k;

    node = D_801372C8;
    if (node != 0) {
        k = D_800C1EE0_de;
        do {
            node->extra =
                node->extra +
                (f32) (node->ticks * 0x1E) * k;
            node = node->next;
        } while (node != 0);
    }
}
int Nav_IsSearchNodeOpen(void *navigationSearchNode) {
    NavigationSearchNode *node = navigationSearchNode;
    return node->open == 1;
}

void Nav_AddPickupCategoryCosts(void) {
    CNavData *base;
    NavigationSearchNode *node;
    NavigationPoint *result;
    f32 addVal;
    u16 field0E;

    base = &D_8013B364;
    node = base->nodes;
    if (node != 0) {
        addVal = D_800C1EE4_de;
        do {
            result = Portal_GetGraphPoint(base, node->key);
            if (navigation_point_flags(result) & 1) {
                field0E = navigation_point_object_id(result);
                if (func_8020F55C_de(field0E) != 0 || func_8020F57C_de(navigation_point_object_id(result)) != 0) {
                    node->extra = node->extra + addVal;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}


#if defined(VERSION_EU_X)
unsigned int func_8020EF74_eu_x_padding_FB74[3] = {
    0x1C400025, 0x00000000, 0x0C09D14D,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8020EF74_eu_padding_FB74[3] = {
    0x0C0829F4, 0x00452821, 0x08082800,
};
#endif

#if defined(VERSION_US)
const unsigned int D_auto_rodata_unresolved_800C1E18[2] = {
    0x14000000, 0x00000E43,
};
#endif
