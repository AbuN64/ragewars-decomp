#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "COMMON/SELF.H"

extern s32 D_8013B364;


extern void *Portal_GetGraphPoint(void *, s32);








void Nav_SelectFlaggedRoamingGoal(void *arg0)
{
    s32 choices[32];
    s32 count;
    s32 result;
    s32 fill;

    result = 0;
    count = result;
    fill = -1;
    {
        s32 index = 31;
        do {
            choices[index] = fill;
            index--;
        } while (index >= 0);

        {
            s32 *table = &D_8013B364;
        index = 0;
        if (table[1] > 0) {
            do {
                if (navigation_point_flags((NavigationPoint *)Portal_GetGraphPoint(table, index)) & 0x800) {
                    choices[count] = index;
                    count++;
                }
                index++;
            } while (index < table[1]);
        }
        }
    }

    if (count == 0) {
        s32 global_count = D_8013B368;
        s32 *table = &D_8013B364;
        s32 tries = 0;
        s32 candidate;
        if (global_count >= 2) {
            candidate = ((Brain_func_80212D78_eu_x *)arg0)->goal;
loop:
            if (tries < 10) {
                candidate = GraphU64_NextRandom() % table[1];
                if (navigation_point_flags((NavigationPoint *)Portal_GetGraphPoint(table, candidate)) & 0x400) {
                    candidate = ((Brain_func_80212D78_eu_x *)arg0)->goal;
                }
                tries++;
                if (candidate != ((Brain_func_80212D78_eu_x *)arg0)->goal) {
                    goto store_both;
                }
                goto loop;
            } else {
                ((Brain_func_80212D78_eu_x *)arg0)->goal = candidate;
                goto store_c;
            }
        } else {
            candidate = 1;
        }
store_both:
        ((Brain_func_80212D78_eu_x *)arg0)->goal = candidate;
store_c:
        ((Brain_func_80212D78_eu_x *)arg0)->nextNode = candidate;
    } else {
        result = choices[GraphU64_NextRandom() % count];
    }

    ((Brain_func_80212D78_eu_x *)arg0)->goal = result;
    ((Brain_func_80212D78_eu_x *)arg0)->nextNode = result;
}
