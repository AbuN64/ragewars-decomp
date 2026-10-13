#include "shared/level_actor.h"
#include "span_1000/code_80279208.h"
#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80206258.h"
extern void func_802065C0_de(void *a, void *b, unsigned short c);
extern void func_802472F0_de(void *arg0);

extern void func_80285DB0_de(char *a, void *b, int c);






void func_8020676C_de(void *arg0, void *arg1, void *arg2) {
    func_802065C0_de(arg0, arg1, (u16)((Trigger *)arg2)->unk4);
    ((Actor_func_8024A7A0_de *)arg0)->flags = ((Actor_func_8024A7A0_de *)arg0)->flags | 0x2100;
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}
