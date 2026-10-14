#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Calls func_8025E2D4_de with -1, func_8025E384_de, func_8025E33C_de and func_8044DD50_de on D_8011FAC0, and
   returns one. */
extern char D_8011FAC0[];

extern void func_8025E384_de();
extern void func_8025E33C_de();
extern void func_8044DD50_de(void *);

s32 func_80444E30_de(void) {
    func_8025E2D4_de(-1);
    func_8025E384_de();
    func_8025E33C_de();
    func_8044DD50_de(D_8011FAC0);
    return 1;
}

/* Stores 4 into the first halfword of a record. */
void func_80444E70_de(s16 *record) {
    record[0] = 4;
}
