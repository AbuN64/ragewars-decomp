#include "types.h"
#include "span_1000/code_80246E34.h"



void func_8024B4F4_de(void *arg0, int arg1) {
    Actor36 *actor = arg0;
    func_8024B4E4_de_FuncPtr fn = actor->update;
    fn(arg0, actor->state);
    func_8026EE20_de(actor->matrix, arg1, &actor->box);
}

