#include "span_1000/code_8025C544.h"
#include "types.h"

extern void func_80258740_de(s32 *arg0);
extern void *func_80258D40_de(void *arg0);
extern void func_802B2F00_de(void *arg0, s16 arg1);
extern void func_802B2F60_de(void *arg0);
extern void func_802587A4_de(s32 *arg0);




void func_8025D1BC_de(void *arg0) {
    PlayerRecAt1E *player = arg0;
    void *temp_v0_2;
    s32 temp_v0;

    func_80258740_de((s32 *)player->bank);
    temp_v0 = player->state;
    if (temp_v0 != 2 && temp_v0 != 0) {
        player->state = 2;
        temp_v0_2 = func_80258D40_de(player->bank);
        func_802B2F00_de(temp_v0_2, player->id);
        func_802B2F60_de(temp_v0_2);
    }
    func_802587A4_de((s32 *)player->bank);
}
