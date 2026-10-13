#include "span_1000/code_8025C544.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);










void func_8025D350_de(void *arg0, s32 arg1) {
    Player_func_8025CC90_de *player = arg0;
    f64 var_f2;
    s32 temp_v0_2;
    SongHeader *temp_v0;

    temp_v0 = func_8028FDB4_de(player->bank->songs, arg1 * 2);
    temp_v0_2 = temp_v0->tempo;
    var_f2 = (f64) temp_v0_2;
    if (temp_v0_2 < 0) {
        var_f2 += D_800C3FB8_de;
    }
    player->tempoScale = (f32) var_f2 * D_800C3FC0_de;
    player->volume = (f32) temp_v0->volume;
    func_8028FDB4_de(player->bank->songs, (arg1 * 2) | 1);
}
