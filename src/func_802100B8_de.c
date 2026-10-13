#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020FDB0.h"
extern void func_8020FDB0_de(Brain_func_8020FDB0_de *, s32 *);




int func_802100B8_de(void *arg0) {
    Brain_func_8020FDB0_de *brain = arg0;
    char *ammo = brain->player->views18.view18_1.track;
    func_8020FDB0_de(brain, ammo + 0xAC);
    return 1;
}
