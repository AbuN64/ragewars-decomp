#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8026E1F8.h"
#include "shared/world.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_80246E34.h"
extern void func_80247004_de(Obj_func_80247004_de *);
extern void **func_8025193C_de(s32,s32,s32,s32,s32,s32,void *,void *,s32);
extern void func_80253754_de(void *, Node80253610 *);
void func_80246E44_de(Actor36 *actor) {
    Vec3 before, after;
    u32 flags, mode;
    void **resource;
    void *box;
    flags = actor->flags;
    if (!(flags & 0x40000)) return;
    if (D_8011FE88.mode == 4 && !(flags & 0x2000)) return;
    mode = flags & 0x300000;
    before = actor->position;
    func_802472F0_de(actor);
    after = actor->position;
    actor->position = before;
    if (mode == 0 && *actor->kind != 0) {
        func_80271F68_de(&after, &after, &before);
        func_80271F34_de(&after, &after, &actor->displacement);
        func_8024715C_de((void *)actor, &after);
        if (*actor->kind == 1) {
            func_8028A27C_de(&D_8011FE88, actor, &before, &actor->position);
        }
    }
    func_80247004_de((void *)actor);
    resource = func_8025193C_de(0, actor->size, actor->size, actor->alignment, 0, 0, 0, D_800C38F4_de, 1);
    if (resource != 0) {
        box = func_8028FDB4_de(*resource, 0);
        actor->update(actor, actor->state);
        func_8026EE20_de(actor->matrix, box, &actor->box);
        func_80253754_de(0, (void *)resource);
    }
}
