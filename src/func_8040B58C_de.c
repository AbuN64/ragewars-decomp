#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"
#include "stddef.h"
/* Confirms the pak menu's channel: picks the team/channel override or the record's own channel byte, marks D_80153784, and if func_80406178_de accepts it opens the pak prompt keyed by the player's storage buffer (or the default buffer if there is no player), otherwise opens the prompt on the default buffer. */
extern s32 func_80406178_de(Record_func_8040B58C_de *, s32, s32);
extern void func_80442574_de(void *, void *, ObjRecAt5DC *, void *, s32);
extern char D_8014561C[];
extern s32 D_8015375C;
extern s32 D_80153784;
extern s32 D_800E28C8;
s32 func_8040B58C_de(void *arg0, Record_func_8040B58C_de *arg1) {
    void *buffer;
    ObjRecAt5DC *player;
    s32 channel;
    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = arg1->inner->unk4;
    }
    D_80153784 = 1;
    if (func_80406178_de(arg1, channel, 1) != 0) {
        player = arg1->player;
        if (player != NULL) {
            buffer = player->unk5DC + 0x554;
        } else {
            buffer = D_8014561C;
        }
        func_80442574_de(buffer, arg1->unk24, arg1->player, arg1->inner, 0);
        return 1;
    }
    func_80442574_de(D_8014561C, arg1->unk24, arg1->player, arg1->inner, 0);
    return 1;
}
