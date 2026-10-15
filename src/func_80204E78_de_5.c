#include "span_1000/code_80204E78.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/func_802052C4_de_closed.h"
#include "shared/func_80206724_de_closed.h"
#include "shared/world.h"
#include "span_1000/code_80203F04.h"
#include "types.h"





extern s32 func_80285F58_de(void *, void *);

extern s32 func_80214178_de(void *, void *, s32);

typedef struct Owner Owner;

/** Initialize the dest record's vtable-like fields from source's flag byte. */
void func_8020520C_de(void *source, void *dest) {
    ((SpawnDispatchOwner *)dest)->callbacks = &D_800C8420_de;
    ((SpawnDispatchOwner *)dest)->update = &D_002052C4;
    ((SpawnDispatchOwner *)dest)->draw = &D_00205628;
    ((SpawnDispatchOwner *)dest)->hit = &D_002050A0;
    ((SpawnDispatchOwner *)dest)->spawn = 0;
    ((SpawnDispatchOwner *)dest)->remaining = ((LevelActor *)source)->field3;
}

void func_8020524C_de(void *arg0, void *arg1) {
    if (func_80285F58_de(&D_8011FE88, arg0) == 1) {
        func_80214178_de(arg0, arg1, 1);
    } else {
        func_80214178_de(arg0, arg1, 0);
        ((LevelActor *)arg0)->flags |= 0x10000;
    }
}

void func_802052C4_de(void *arg0, void *arg1) {
    void *obj = ((Shared_CallbackOwner *)(arg1))->hook;
    if (obj != 0) {
        FuncPtr fn = ((Shared_CallbackHook *)(obj))->callback;
        if (fn != 0) {
            fn();
        }
    }
}

/** Return the nested record's field, or a fallback constant when zero. */
int func_802052F8_de(void *arg0) {
    int temp = ((Hold5324 *)((Owner *)arg0)->track)->r.sound;
    if (temp != 0) {
        return temp;
    }
    return 0x5334;
}

int func_80205314_de(void *arg0) {
    return ((Obj5324 *)arg0)->holder->r.unk18;
}

void func_80205324_de(Obj5324 *arg0, s32 *arg1) {
    s32 temp_s3;
    Rec5324 *rec;
    Shared_World *pFlag;

    rec = &arg0->holder->r;
    pFlag = &D_8011FE88;
    func_80285DB0_de(pFlag, arg0, 1);
    func_80278D78_de(arg0, 0x40000, arg0);
    if (arg1[1] == 0) {
        arg0->flags = arg0->flags & 0xFFFEFFFF;
    }
    if (rec->unk18 == 0) {
        arg0->flags &= ~0x2000;
        arg0->flags &= ~0x100;
    }
    temp_s3 = pFlag->mode;
    if (temp_s3 == 4) {
        if (rec->unk20.whole != -1) {
            func_8025DE54_de(rec->unk20.half.id, arg0->pos.v, 0, -1);
        }
        if (rec->unk1C != -1) {
            func_80216288_de(arg0, rec->unk1C, arg0->pos.t, 0);
        }
        func_802170A0_de(arg0, arg1, 4, rec->unk24, rec->unk28);
        /* func_802A5D38_de unlinks the walker by the object's 32-bit identity;
         * the registry holds those identities as s32. */
        func_802A5D38_de(&D_801379C0, (s32)arg0);
        if (pFlag->mode != temp_s3) {
            goto block_10;
        }
    } else {
block_10:
        arg0->flags = (arg0->flags & ~0x100) | 0x08000000;
    }
}

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

/** Return the word at offset 0x40 through the pointer stored at offset 0x18. */
int func_802054D0_de(void *object) {
    return ((struct Access_s32_40 *) ((Owner *) object)->track)->field;
}
