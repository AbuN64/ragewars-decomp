#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80212C90.h"
#include "types.h"
#include "span_1000/code_802106E0.h"

extern s32 D_8013B364;


extern void *func_8020C994_de(void *, s32);








void func_80213340_de(void *arg0)
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
                if (((NavigationNode *)func_8020C994_de(table, index))->flags & 0x800) {
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
                candidate = func_802744D4_de() % table[1];
                if (((NavigationNode *)func_8020C994_de(table, candidate))->flags & 0x400) {
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
        result = choices[func_802744D4_de() % count];
    }

    ((Brain_func_80212D78_eu_x *)arg0)->goal = result;
    ((Brain_func_80212D78_eu_x *)arg0)->nextNode = result;
}
