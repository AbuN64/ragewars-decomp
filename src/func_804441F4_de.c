#include "span_16E000/code_80444030.h"
/* Returns the name the object at offset 0x5D8 of an actor's owner holds, falling back to
   D_80146302 when the actor has no owner or the owner has no such object. */




extern char D_80146302[];

char *func_804441F4_de(struct ActorRecAt1C *actor) {
    char *name = D_80146302;

    if (actor->owner != 0 && actor->owner->name != 0) {
        name = actor->owner->name;
    }
    return name;
}
