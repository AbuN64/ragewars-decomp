#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"




























/* Revives a player whose down timer at 0x1340 has run past its limit (30 ticks, or 900 in
   control modes 12 and 15 while D_80146938 asks): clears the timer and calls func_8044972C_de
   unless the session at 0x98 is running and the player's team membership at 0x94 and control
   mode disagree, or it is teamless and active outside session mode 3. */







extern Session D_801468A0;
extern s32 D_80146938;
extern void func_8044972C_de(SharedPlayer_func_80209CD8_de *);

void func_80209CD8_de(SharedPlayer_func_80209CD8_de **arg0) {
    s32 limit;
    Controls *controls;
    Session *session;
    s8 mode;

    if (D_80146938 != 0) {
        mode = (*arg0)->views5D8.view5D8_2.controls->mode;
        if (mode == 0xC || mode == 0xF) {
            limit = 0x384;
        } else {
            limit = 0x1E;
        }
    } else {
        limit = 0x1E;
    }
    if (limit < (*arg0)->views1340.view1340_2.timer) {
        session = &D_801468A0;
        do {
            (*arg0)->views1340.view1340_2.timer = 0;
        } while (0);
        if (session->running != 0) {
            controls = (*arg0)->views5D8.view5D8_2.controls;
            if (controls->team == 0) {
                if (controls->active == 0 || session->mode == 3) {
                    func_8044972C_de(*arg0);
                }
            } else {
                mode = controls->mode;
                if (mode == 0xC || mode == 0xF) {
                    func_8044972C_de(*arg0);
                }
            }
        } else {
            func_8044972C_de(*arg0);
        }
    }
}
