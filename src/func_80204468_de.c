#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80203F04.h"
#include "span_1000/code_80206258.h"
#include "shared/level_actor.h"
extern char D_800C8274;
extern char D_002043E0;








void func_80204468_de(void *arg0, void *arg1) {
    ((ActorMotionState *)arg1)->table = &D_800C8274;
    ((ActorMotionState *)arg1)->update = &D_002043E0;
    ((ActorMotionState *)arg1)->unk124 = 0;
    ((ActorMotionState *)arg1)->unk128 = 0;
    ((ActorMotionState *)arg1)->unk12C = 0;
    if (((BreakableDefinition *)((LevelActor *)arg0)->definition)->flags & 1) {
        ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags | 0x10000;
        return;
    }
    ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags & 0xFFFEFFFF;
}
