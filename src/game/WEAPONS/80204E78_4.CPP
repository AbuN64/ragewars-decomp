#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/FUNCPTR.H"
#include "COMMON/SHARED_VOIDCALLBACK.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECAT30.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4.H"

extern s32 Render_TestActorStateBit(void *, void *);


typedef struct Owner Owner;

/** Initialize the dest record's vtable-like fields from source's flag byte. */
void func_8020520C_de(LevelActor *source, void *dest) {
    ((SpawnDispatchOwner *)dest)->callbacks = &D_800C8420_de;
    ((SpawnDispatchOwner *)dest)->update = &D_002052C4;
    ((SpawnDispatchOwner *)dest)->draw = &D_00205628;
    ((SpawnDispatchOwner *)dest)->hit = &D_002050A0;
    ((SpawnDispatchOwner *)dest)->spawn = 0;
    ((SpawnDispatchOwner *)dest)->remaining = source->field3;
}

void func_8020524C_de(LevelActor *actor, void *arg1) {
    if (Render_TestActorStateBit(&D_8011FE88, actor) == 1) {
        Weapons_RequestActorState(actor, arg1, 1);
    } else {
        Weapons_RequestActorState(actor, arg1, 0);
        actor->flags |= 0x10000;
    }
}

void func_802052C4_de(void *arg0, Shared_CallbackOwner *callbackOwner) {
    void *obj = callbackOwner->hook;
    if (obj != 0) {
        FuncPtr fn = ((Shared_CallbackHook *)(obj))->callback;
        if (fn != 0) {
            fn();
        }
    }
}

/** Return the nested record's field, or a fallback constant when zero. */
int func_802052F8_de(void *owner) {
    int temp = ((Hold5324 *)((Owner *)owner)->track)->r.sound;
    if (temp != 0) {
        return temp;
    }
    return 0x5334;
}

int func_80205314_de(void *arg0) {
    return ((Obj5324 *)arg0)->holder->r.unk18;
}

void func_80205324_de(Obj5324 *arg0, s32 *arg1) {
    s32 mode;
    Rec5324 *rec;
    Shared_World *pFlag;

    rec = &arg0->holder->r;
    pFlag = &D_8011FE88;
    Render_SetActorStateBit(pFlag, arg0, 1);
    func_80278D78_de(arg0, 0x40000, arg0);
    if (arg1[1] == 0) {
        arg0->flags = arg0->flags & 0xFFFEFFFF;
    }
    if (rec->unk18 == 0) {
        arg0->flags &= ~0x2000;
        arg0->flags &= ~0x100;
    }
    mode = pFlag->mode;
    if (mode == 4) {
        if (rec->unk20.whole != -1) {
            Render_PlaySoundAtPosition(rec->unk20.half.id, arg0->pos.v, 0, -1);
        }
        if (rec->unk1C != -1) {
            Weapons_SpawnActorEffect(arg0, rec->unk1C, arg0->pos.t, 0);
        }
        Weapons_SpawnFlaggedEffects(arg0, arg1, 4, rec->unk24, rec->unk28);
        /* func_802A5D38_de unlinks the walker by the object's 32-bit identity;
         * the registry holds those identities as s32. */
        func_802A5D38_de(&D_801379C0, (s32)arg0);
        if (pFlag->mode != mode) {
            goto block_10;
        }
    } else {
block_10:
        arg0->flags = (arg0->flags & ~0x100) | 0x08000000;
    }
}

/** Clear two flags when the controlling byte and nested flag are set. */
void func_80205494_de(BreakableHitContext *breakableHitContext, ObjectStateCC *arg1) {
    char *nested = breakableHitContext->unk_18;
    if (arg1->unk_CB != 0 &&
        (((struct Descriptor *)nested)->damage.flags & 0x4) != 0) {
        unsigned int flags = breakableHitContext->unk_100;
        flags &= ~0x2000;
        flags &= ~0x100;
        breakableHitContext->unk_100 = flags;
    }
}

/** Return the word at offset 0x40 through the pointer stored at offset 0x18. */
int func_802054D0_de(void *object) {
    return ((struct Access_s32_40 *) ((Owner *) object)->track)->field;
}
