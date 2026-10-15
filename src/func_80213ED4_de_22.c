#include "shared/func_802052C4_de_closed.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_16E000/code_8043962C.h"
#include "common/unused.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "shared/func_802171FC_de_closed.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"

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

void func_802171FC_de(void *arg0, void *arg1) {
    FuncPtr fn = ((struct CallbackState114 *)(arg1))->callback;
    if (fn != 0) {
        fn();
    }
}

extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);




/** Subtract obj->y from arg2 in-place via func_80271F68_de, then return the squared length of (arg1, arg2', arg3). */
f32 func_80217224_de(void *arg0, Vec3 v) {
    f32 temp_f1;

    func_80271F68_de(&v, &v, &((Actor_func_80214310_de *)(arg0))->position);
    temp_f1 = v.y - ((Actor_func_80214310_de *)(arg0))->eye;
    v.y = temp_f1;
    return (v.x * v.x) + (temp_f1 * temp_f1) + (v.z * v.z);
}

/* Squared XZ distance to a point using the existing by-value vector ABI. */
f32 func_80217290_de(void *arg0, Vec3 point)
{
    f32 dx = point.x - ((LevelActor *)arg0)->position0.x;
    f32 dz = point.z - ((LevelActor *)arg0)->position0.z;
    return dx * dx + dz * dz;
}

void func_802172C4_de(void *arg0, void *arg1, Func802172C4Value arg2) {
}

extern void *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);








void func_802172D0_de(void *arg0, void *arg1, s32 arg2) {
    SoundSourceNode *node;
    void *fallback;
    s32 kind;

    node = ((Dest *)arg1)->sound;
    fallback = (void *)-1;
    if (node != 0) {
        if (node->state == arg2) {
            return;
        }
        func_8025CA24_de(func_8025CC6C_de(), ((Dest *)arg1)->sound);
    }

    kind = *(u8 *)arg0;
    if (kind != 0) {
        if (kind >= 0) {
            if (kind < 3) {
                fallback = arg0;
            }
        }
    } else {
        fallback = (void *)((LevelActor *)arg0)->resourceFlags;
    }

    ((Dest *)arg1)->sound =
        func_8025C95C_de(func_8025CC6C_de(), arg2, &((LevelActor *)arg0)->position0,
                      &((LevelActor *)arg0)->position0, (s32)fallback);
}
