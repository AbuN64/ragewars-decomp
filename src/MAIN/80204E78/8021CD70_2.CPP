#include "span_1000/code_8027302C.h"
#include "TYPES.H"
/* Builds a player's aiming marker matrices for the current view D_800D297C and turns the marker on at
   0x1214: a beam from the eye (the view position at 0x128, or func_8022B144_de without a view) toward the
   target point, pitched straight up or down when nearly vertical, is stored in the table at 0x1480; the
   laser from the weapon muzzle at 0x260 to the aim point at 0x1464 (lowered by the view's height above
   the muzzle) in the table at 0x1500; and with a surface normal given, a dot flattened against the
   surface and lifted along the normal is stored in the table at 0x1580. */
static inline f32 aimAbs(f32 value) { return value < 0.0f ? -value : value; }

#include "common/unused.h"
#include "span_1000/code_802022E0.h"







extern f32 D_800C9F70_de;
extern s32 D_800D297C;
extern void func_8022B144_de(SharedPlayer_func_8021D408_de *, Vec3 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern void func_802727D8_de(Matrix *);
extern void func_80272E3C_de(Matrix *, f32, f32, f32);
extern void func_80273198_de(Matrix *, Vec3 *);
extern void func_80273448_de(Matrix *, Vec3);
extern void func_8027347C_de(Matrix *, f32, f32, f32);
extern f32 func_802726F8_de(Vec3 *, Vec3 *);
extern void func_8027027C_de(Matrix *, Matrix *);
extern void func_80271818_de(Vector4f *, Vec3 *);
extern void func_80274244_de(Vector4f *, Matrix *);
extern void func_802737F0_de(Matrix *, f32);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

void func_8021D408_de(SharedPlayer_func_8021D408_de *player, Vec3 *target, Vec3 *normal) {
    Vec3 to;
    Vec3 eye;
    Vec3 lift;
    Vec3 direction;
    Vec3 aim;
    Vec3 origin;
    Matrix matrix;
    Vector4f turn;
    f32 scale;
    f32 height;
    f32 aimHeight;

    if (player->views5DC.view5DC_2.view != 0) {
        origin = player->views5DC.view5DC_2.view->unk128;
    } else {
        func_8022B144_de(player, &origin);
    }
    eye = origin;
    to = *target;
    func_80271F68_de(&direction, &to, &eye);
    func_8027207C_de(&direction);
    func_802727D8_de(&matrix);
    if (0.99999899f <= direction.y) {
        func_80272E3C_de(&matrix, -1.57079649f, player->views1C.view6C_5.heading, 0.0f);
    } else if (direction.y <= -0.99999899f) {
        func_80272E3C_de(&matrix, 1.57079649f, player->views1C.view6C_5.heading, 0.0f);
    } else {
        func_80273198_de(&matrix, &direction);
    }
    func_80273448_de(&matrix, eye);
    func_802733B4_de(&matrix, 0.0f, 0.0f, D_800C9F70_de);
    func_8027347C_de(&matrix, 0.05f, 1.0f, D_800C9F70_de - func_802726F8_de(&eye, &to));
    func_8027027C_de(&matrix, &player->views1480.view1480_1.beams[D_800D297C]);

    aim = player->views1464.view1464_1.aim;
    if (player->views5DC.view5DC_2.view != 0) {
        height = player->views5DC.view5DC_2.view->unk128.y - player->views1C.view260_26.muzzle.y;
        aimHeight = aim.y;
        height = height < 0.0f ? aimHeight + height : aimHeight - height;
        aim.y = height;
    }
    func_80271F68_de(&direction, &aim, &player->views1C.view260_26.muzzle);
    func_8027207C_de(&direction);
    func_802727D8_de(&matrix);
    func_80273198_de(&matrix, &direction);
    func_80273448_de(&matrix, player->views1C.view260_26.muzzle);
    scale = 1.0f;
    func_8027347C_de(&matrix, scale, scale, -func_802726F8_de(&origin, &player->views1464.view1464_1.aim));
    func_8027027C_de(&matrix, &player->views1500.view1500_1.lasers[D_800D297C]);

    if (normal != 0) {
        lift = *normal;
        func_80271818_de(&turn, &lift);
        func_80274244_de(&turn, &matrix);
        func_802737F0_de(&matrix, 1.57079649f);
        func_8027207C_de(&lift);
        func_80271F9C_de(&lift, &lift, 2.048f);
        func_80271F34_de(&eye, &eye, &lift);
        func_80273448_de(&matrix, to);
        func_8027347C_de(&matrix, 1.536f, scale, 1.536f);
        func_8027027C_de(&matrix, &player->views1580.view1580_1.dots[D_800D297C]);
    }
    player->views5E8.view1214_155.marker = 1;
}
