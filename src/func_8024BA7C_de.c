#include "common/unused.h"
#include "gfx.h"
#include "span_1000/code_8024BA6C.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"


/* Draws an actor's attached model: when the actor has one, allocates a matrix from the pool D_8011FFB0,
 * fills it with the given transform multiplied by the camera matrix (func_8026F898_de, func_80272828_de,
 * func_8026FC9C_de), loads it into the display list, draws the model through func_8026C6D8_de with the
 * actor's per-frame state for the current frame, then reloads the camera's per-frame matrix. */






extern Gfx *D_80110634;
extern s32 D_800D297C;
extern s32 func_802799C0_de(void *, s32);
extern void func_8026F898_de(f32 *, f32 *, f32 *);
extern void func_80272828_de(f32 *);
extern void func_8026FC9C_de(f32 *, s32);
extern void func_8026C6D8_de(s32, s32, s32, s32, void *, s32, s32);




void func_8024BA7C_de(void *actor, Camera *camera, f32 *transform, u8 layer) {
    struct LevelActor *object = actor;
    f32 mf[16];
    s32 mtx;
    s32 matrices;
    Gfx *restore;
    Gfx *load;
    s32 offset;

    if (object->fieldB4 != 0) {
        mtx = func_802799C0_de(&D_8011FFB0, 1);
        if (mtx != 0) {
            matrices = camera->matrices;
            func_8026F898_de(mf, transform, (f32 *)(matrices + 0x1E0));
            func_80272828_de(mf);
            func_8026FC9C_de(mf, mtx);
            gSPMatrix(D_80110634++, mtx, G_MTX_LOAD | G_MTX_PROJECTION);
            func_8026C6D8_de(layer, camera->style, object->fieldB4, 1,
                          &object->lighting[D_800D297C], 0, object->field3);
            restore = D_80110634++;
            offset = (D_800D297C << 6) + 0x380;
            gSPMatrix(restore, matrices + offset, G_MTX_LOAD | G_MTX_PROJECTION);
        }
    }
}
