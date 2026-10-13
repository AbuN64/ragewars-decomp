#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028308C.h"
#include "types.h"





extern Vec3 D_801042C8;
extern Params D_80100290;
extern char D_8011D8D0;

extern void func_80271818_de(struct Shape_typemap_165 *out, Vec3 *in);
extern s32 func_802800C0_de(void *, void *, void *, s32, s32, s32, Vec3, struct Shape_typemap_165, Triple, s32, s32, s32);




void func_80283480_de(Obj_func_80283920_de *arg0, s32 arg1) {
    struct Shape_typemap_165 q;
    Vec3 pos;

    if ((*arg0->effectFlags & 0x10) != 0) {
        pos = D_801042C8;
    } else {
        pos = arg0->rotation;
    }
    func_80271818_de(&q, &pos);
    func_802800C0_de(&D_8011D8D0, arg0,
                  arg0->effectResource,
                  arg0->effectIndex,
                  arg0->effectCount, arg1,
                  pos, q, D_80100290.v, 0, D_80100290.w,
                  (arg0->unk5C & 0x200006) | 1);
}
