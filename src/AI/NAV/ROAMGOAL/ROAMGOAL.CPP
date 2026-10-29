#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "COMMON/SELF.H"

extern s32 g_navigationGraph;


extern void *Portal_GetGraphPoint(void *, s32);








void Nav_SelectFlaggedRoamingGoal(void *controller)
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
            s32 *table = &g_navigationGraph;
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
        s32 global_count = g_navigationNodeCount;
        s32 *table = &g_navigationGraph;
        s32 tries = 0;
        s32 candidate;
        if (global_count >= 2) {
            candidate = ((NavigationBrainView *)controller)->goal;
loop:
            if (tries < 10) {
                candidate = Graphu64_NextRandom() % table[1];
                if (navigation_point_flags((NavigationPoint *)Portal_GetGraphPoint(table, candidate)) & 0x400) {
                    candidate = ((NavigationBrainView *)controller)->goal;
                }
                tries++;
                if (candidate != ((NavigationBrainView *)controller)->goal) {
                    goto store_both;
                }
                goto loop;
            } else {
                ((NavigationBrainView *)controller)->goal = candidate;
                goto store_c;
            }
        } else {
            candidate = 1;
        }
store_both:
        ((NavigationBrainView *)controller)->goal = candidate;
store_c:
        ((NavigationBrainView *)controller)->nextNode = candidate;
    } else {
        result = choices[Graphu64_NextRandom() % count];
    }

    ((NavigationBrainView *)controller)->goal = result;
    ((NavigationBrainView *)controller)->nextNode = result;
}
