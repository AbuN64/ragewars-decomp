#include "span_1000/code_80203F04.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80204E78.h"
#include "common/types_8a8189af7b05.h"
#include "shared/world.h"
#include "types.h"

/** Clear two flags when the controlling byte and nested flag are set. */
void func_80205494_de(void *arg0, void *arg1) {
    char *nested = ((BreakableHitContext *)arg0)->unk_18;
    if (((ObjectStateCC *)arg1)->unk_CB != 0 &&
        (((struct Descriptor *)nested)->damage.flags & 0x4) != 0) {
        unsigned int flags = ((BreakableHitContext *)arg0)->unk_100;
        flags &= ~0x2000;
        flags &= ~0x100;
        ((BreakableHitContext *)arg0)->unk_100 = flags;
    }
}

typedef struct Owner Owner;



/** Return the word at offset 0x40 through the pointer stored at offset 0x18. */
int func_802054D0_de(void *object) {
    return ((struct Access_s32_40 *) ((Owner *) object)->track)->field;
}

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
