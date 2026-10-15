#include "span_1000/code_80204E78.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80203F04.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80279208.h"
#include "types.h"
#include "span_1000/code_8022F3E8.h"

extern void func_8026DC24_de(void **, s32, s32, void *, s32, s32);


extern s32 func_80214178_de(void *, void *, s32);


extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_802054E0_de(Obj54E0 *arg0, void *arg1) {
    Rec54E0 *rec;

    rec = &arg0->holder->r;
    arg0->flags = arg0->flags & 0xFFFEFFFF;
    func_80278D78_de(arg0, 0x40000, arg0);
    if (rec->unk2C == 0) {
        arg0->flags &= ~0x2000;
        arg0->flags &= ~0x100;
    }
    if (D_8011FE88.mode == 4) {
        if (rec->unk34.whole != -1) {
            func_8025DE54_de(rec->unk34.half.id, arg0->pos.v, 0, -1);
        }
        if (rec->unk30 != -1) {
            func_80216288_de(arg0, rec->unk30, arg0->pos.t, 0);
        }
        func_802170A0_de(arg0, arg1, 8, rec->unk38, rec->unk3C);
    }
}

/** Clear two flags when the controlling byte and nested flag are set. */
void func_802055EC_de(void *arg0, void *arg1) {
    LevelActor *object = arg0;
    BreakableDefinition *nested = (void *)object->definition;
    ObjectStateCC *state = arg1;
    if (state->unk_CB != 0 &&
        (nested->flags & 0x20) != 0) {
        unsigned int flags = object->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        object->flags = flags;
    }
}

/* Draw callback installed by func_8020520C_de; the animation lookup is
 * the same third callback argument consumed by func_8024A1D0_de. */
void func_80205628_de(void *arg0, void *arg1, void *arg2) {
    LevelActor *actor = arg0;
    SpawnDispatchOwner *owner = arg1;
    Lookup *lookup = arg2;

    actor->mask = 1 << owner->spawn;
    if (lookup->unk0 != 0) {
        func_8026DC24_de(lookup->value, actor->fieldB4, 1,
                        &actor->lighting[D_800D297C], 0, owner->remaining);
    }
}

void func_80205694_de(void *arg0, void *arg1) {
    func_80214178_de(arg0, arg1, 1);
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}

void func_802056D0_de(void *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)((Trigger *)arg0)->unk8, (u32)((Trigger *)arg0)->unk4 >> 16, 1);
}

/** Return the object's 0x200 status bit. */
unsigned int func_80205700_de(void *object) {
    struct Hit *hit = object;
    return hit->flags & 0x200;
}

int func_8020570C_de(void *arg0) {
    return ((((Hit *)arg0)->flags >> 9) ^ 1) & 1;
}
