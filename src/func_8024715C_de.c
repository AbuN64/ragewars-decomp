#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80246E34.h"
#include "types.h"
typedef struct CollisionInfo CollisionInfo;







extern CollisionInfo D_801003D8;
extern func_80237E70_G1 D_801041F0;
extern s32 func_80243A90_de(void *arg0, Vec3 arg1, CollisionInfo *arg2);
extern void func_80278E04_de(s32 arg0, s32 arg1, void *arg2);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);









void func_8024715C_de(char *arg0, Vec3 *arg1) {
    CollisionInfo *collision;
    u16 *old_contact;
    s32 collided;
    f32 saved;
    void (*callback)(void *, void *, CollisionInfo *);

    if ((((ObjectLinks23C *)(arg0))->unk_100 & 0x10000) && ((ObjectLinks23C *)(arg0))->unk_1A0 != 0) {
        collision = ((ObjectLinks10 *)(((ObjectLinks23C *)(arg0))->unk_1A0))->unk_C;
        if (collision == 0) {
            collision = &D_801003D8;
        }
        saved = ((ObjectStateC *)(collision))->unk_8.v0;
        if ((u32)(((ObjectLinks23C *)(arg0))->unk_238 - 0x2B0C) < 8) {
            ((ObjectStateC *)(collision))->unk_8.v1 = 0;
        }
        old_contact = ((ObjectLinks23C *)(arg0))->unk_14;
        collided = func_80243A90_de(arg0, *arg1, collision);
        if (old_contact != ((ObjectLinks23C *)(arg0))->unk_14) {
            ((ObjectLinks23C *)(arg0))->unk_1F4 = old_contact;
        }
        ((ObjectStateC *)(collision))->unk_8.v0 = saved;
        if (old_contact != 0 && ((ObjectLinks23C *)(arg0))->unk_14 != 0 &&
                *old_contact != *((ObjectLinks23C *)(arg0))->unk_14 &&
                *((ObjectLinks23C *)(arg0))->unk_18 == 1) {
            func_80278E04_de((s32)old_contact, 0x80, arg0);
            func_80278E04_de((s32)((ObjectLinks23C *)(arg0))->unk_14, 0x40, arg0);
        }
        if (collided != 0 && !(((ObjectLinks23C *)(arg0))->unk_100 & 0x300000) &&
                *((ObjectLinks23C *)(arg0))->unk_18 == 1 && D_801041F0.unk0 != 0 &&
                *D_801041F0.unk0 == 1) {
            func_80278D78_de(D_801041F0.unk0, 0x20, arg0);
        }
        callback = ((struct CallbackState288 *) ((char *) arg0))->callback;
        if (callback != 0) {
            callback(arg0, arg0 + 0x170, collision);
        }
    } else {
        ((ObjectLinks23C *)(arg0))->unk_8 = *arg1;
    }
}
