#include "span_1000/code_8022D944.h"
#include "types.h"
#include "common/types_8fd754e1e915.h"

extern void func_80218464_de();




void func_8022DA04_de(void *arg0) {
    struct Player *player = arg0;
    func_80218464_de(&player->weaponBusy);
    player->locked = 0;
}
