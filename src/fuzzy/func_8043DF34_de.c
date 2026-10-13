#include "span_1000/code_80291054.h"
extern f32 D_800DE320, D_800DE324_de;

void func_8043DF34_de(f32 duration, s32 mode, s32 option, s32 teams, s32 last) {
    s32 i;
    D_801468A0.counter80 = 0;
    D_801468A0.timeLimit = duration * D_800DE320;
    D_801468A0.mask = 0xA00;
    D_801468A0.elapsed = 0;
    D_801468A0.option78 = last;
    D_801468A0.mode = mode;
    D_801468A0.teams = teams;
    D_801468A0.option54 = option;
    for (i = 0; i < 5; i++) {
        D_801468A0.scores[i] = 0;
        D_801468A0.counts[i] = 0;
    }
    D_801468A0.round = 0;
    D_801468A0.state = 0;
    if (D_801468A0.timeLimit == 0.0f) D_801468A0.timeLimit = D_800DE324_de;
}
