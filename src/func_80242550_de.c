#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"















extern void func_80271F68_de(Triple *, Triple *, Triple *);
extern void func_80241950_de(OwnerRecAt18 *, Bounds *, Actor_func_80242550_de *, Source_func_802164A8_de *);
extern void func_80241BAC_de(Actor_func_80242550_de *, OwnerRecAt18 *, Bounds *, SurfaceHit *, Source_func_802164A8_de *);
extern void func_80241F24_de(Actor_func_80242550_de *, OwnerRecAt18 *, Bounds *, SurfaceHit *, Source_func_802164A8_de *);

void func_80242550_de(Actor_func_80242550_de *actor, Source_func_802164A8_de *input) {
    Triple saved_previous;
    Triple saved_position;
    SurfaceHit query;
    Bounds bounds;
    OwnerRecAt18 *owner;
    EntryRecAt4V3 *entry;

    owner = actor->owner;
    entry = (EntryRecAt4V3 *)(owner->entries + 0x14);
    if (*actor->flags & 0x40000) {
        saved_previous = actor->previous;
        saved_position = actor->position;
        actor->previous = input->position;
        func_80271F68_de(&actor->position, &input->position, &actor->delta);
        query.word4 = 0;
        query.word8 = 1;
        query.wordC = 0;
        query.word10 = 0;
        query.input = input;
        query.index = -1;
        func_80241950_de(owner, &bounds, actor, input);
        switch (entry->kind) {
        case 1:
            func_80241F24_de(actor, owner, &bounds, &query, input);
            break;
        case 2:
            func_80241BAC_de(actor, owner, &bounds, &query, input);
            break;
        }
        actor->previous = saved_previous;
        actor->position = saved_position;
    }
}
