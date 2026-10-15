#include "span_1000/code_8020D370.h"
/* Advances a committed selection's stage against the node list D_8013B364: finishes through
   func_8020DB14_de when there are no stages at 0x1BC, counts once into 0x1C8 the list's kind-6 nodes whose
   id matches the selection id at 0x1C0, then runs func_8020D4AC_de while the stage is within that count,
   func_8020D6E4_de on the stage right after it and func_8020D9C0_de on the one after that. */
#include "types.h"
#include "common/unused.h"
/* Navigation selection/list/node canonical ownership remains unresolved. */







extern NodeList D_8013B364;

extern Node_func_8020D364_de *func_8020C9B0_de(NodeList *list, s32 index);
extern s32 func_8020D4AC_de(Selection *sel);
extern s32 func_8020D6E4_de(Selection *sel);
extern s32 func_8020D9C0_de(Selection *sel);
extern s32 func_8020DB14_de(Selection *sel);

s32 func_8020D370_de(Selection *sel)
{
    NodeList *list = &D_8013B364;
    Node_func_8020D364_de *node;
    s32 i;

    if (list == 0) {
        return 1;
    }
    if (sel->stage == 0) {
        return func_8020DB14_de(sel);
    }
    if (sel->selection != -1 && sel->matches == 0) {
        for (i = 0; i < list->count; i++) {
            node = func_8020C9B0_de(list, i);
            if (node->id == sel->selection && node->kind == 6) {
                sel->matches++;
            }
        }
    }
    if (sel->stage > 0 && sel->stage < sel->matches + 1) {
        return func_8020D4AC_de(sel);
    }
    if (sel->stage == sel->matches + 1) {
        return func_8020D6E4_de(sel);
    }
    if (sel->stage == sel->matches + 2) {
        return func_8020D9C0_de(sel);
    }
    return 1;
}

