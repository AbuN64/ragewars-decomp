#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"

/* Spawns the standing effects of an animation for an object: every event whose effect id is 6 or 7 is placed by transforming its local point through the object's matrix at 0x74 and spawned through func_80265E10_de with its parameters. */







extern EventRecAt14 *func_80262598_de(void *);
extern s32 func_802625C4_de(void *);
extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);
extern void func_80265E10_de(char *, char *, u16, s32, Vec3, struct Shape_func_802764D4_de_2);

void func_8024C1C4_de(char *obj, void *anim)
{
    EventRecAt14 *e;
    s32 count;
    s32 i;
    Vec3 pos;

    e = func_80262598_de(anim);
    count = func_802625C4_de(anim);
    for (i = 0; i < count; i++) {
        switch (e[i].effect) {
        case 6:
        case 7:
            func_80272898_de(obj + 0x74, &e[i].local, &pos);
            func_80265E10_de(obj, obj, e[i].effect, -1, pos, e[i].params);
        }
    }
}
