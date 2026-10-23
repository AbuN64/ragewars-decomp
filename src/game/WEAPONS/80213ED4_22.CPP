#include "COMMON/FUNCPTR.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/UNUSED.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/80213ED4_22.H"

/** Read the next u16 from the cursor stream, wrapping back to base on the -1 sentinel. */
s16 func_802171C8_de(Cursor802171C8 *arg0) {
    u16 *cur;
    u16 value;

    cur = arg0->cur;
    value = *cur;
    cur += 1;
    arg0->cur = cur;
    if (*(s16 *) cur == -1) {
        arg0->cur = arg0->base;
    }
    return (s16) value;
}

void func_802171FC_de(void *arg0, struct CallbackState114 *arg1) {
    FuncPtr fn = arg1->callback;
    if (fn != 0) {
        fn();
    }
}

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);




/** Subtract obj->y from arg2 in-place via func_80271F68_de, then return the squared length of (arg1, arg2', arg3). */
f32 func_80217224_de(void *candidate, CVector3 v) {
    f32 temp_f1;

    func_80271F68_de(&v, &v, &((Actor_func_80214310_de *)(candidate))->position);
    temp_f1 = v.y - ((Actor_func_80214310_de *)(candidate))->eye;
    v.y = temp_f1;
    return (v.x * v.x) + (temp_f1 * temp_f1) + (v.z * v.z);
}

/* Squared XZ distance to a point using the existing by-value vector ABI. */
f32 func_80217290_de(LevelActor *arg0, CVector3 point)
{
    f32 dx = point.x - arg0->position0.x;
    f32 dz = point.z - arg0->position0.z;
    return dx * dx + dz * dz;
}

void func_802172C4_de(void *arg0, void *arg1, Func802172C4Value arg2) {
}

extern void *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);








void func_802172D0_de(void *actor, void *arg1, s32 sixth) {
    CLoopingSoundData *node;
    void *fallback;
    s32 kind;

    node = ((Dest *)arg1)->sound;
    fallback = (void *)-1;
    if (node != 0) {
        if (node->state == sixth) {
            return;
        }
        func_8025CA24_de(func_8025CC6C_de(), ((Dest *)arg1)->sound);
    }

    kind = *(u8 *)actor;
    if (kind != 0) {
        if (kind >= 0) {
            if (kind < 3) {
                fallback = actor;
            }
        }
    } else {
        fallback = (void *)((LevelActor *)actor)->resourceFlags;
    }

    ((Dest *)arg1)->sound =
        func_8025C95C_de(func_8025CC6C_de(), sixth, &((LevelActor *)actor)->position0,
                      &((LevelActor *)actor)->position0, (s32)fallback);
}
