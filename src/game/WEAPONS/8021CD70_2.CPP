#include "COMMON/MTX.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Builds a player's aiming marker matrices for the current view D_800D297C and turns the marker on at
   0x1214: a beam from the eye (the view position at 0x128, or func_8022B144_de without a view) toward the
   target point, pitched straight up or down when nearly vertical, is stored in the table at 0x1480; the
   laser from the weapon muzzle at 0x260 to the aim point at 0x1464 (lowered by the view's height above
   the muzzle) in the table at 0x1500; and with a surface normal given, a dot flattened against the
   surface and lifted along the normal is stored in the table at 0x1580. */
static inline f32 aimAbs(f32 value) { return value < 0.0f ? -value : value; }

#include "COMMON/UNUSED.H"
#include "COMMON/OBJ.H"
#include "GAME/CODE_8027302C.H"







extern f32 D_800C9F70_de;
extern s32 D_800D297C;
extern void func_8022B144_de(SharedPlayer *, CVector3 *);
extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern void func_802727D8_de(Matrix *);
extern void func_80272E3C_de(Matrix *, f32, f32, f32);
extern void BuildDirectionMatrix(Matrix *, CVector3 *);
extern void TranslateMatrix(Matrix *, CVector3);
extern void func_8027347C_de(Matrix *, f32, f32, f32);
extern f32 Particle_GetPointDistance(CVector3 *, CVector3 *);
extern void Rsp_ConvertMatrixToFixed(Matrix *, Matrix *);
extern CQuatern func_80271818_de(CVector3 *);
extern void MatrixFromQuaternion(CQuatern *, Matrix *);
extern void func_802737F0_de(Matrix *, f32);
extern void Particle_ScaleVector(CVector3 *, CVector3 *, f32);
extern void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);

void func_8021D408_de(SharedPlayer *player, CVector3 *target, CVector3 *normal) {
    CVector3 to;
    CVector3 eye;
    CVector3 lift;
    CVector3 direction;
    CVector3 aim;
    CVector3 origin;
    Matrix matrix;
    CQuatern turn;
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
    Particle_SubtractVectors(&direction, &to, &eye);
    Particle_NormalizeVec3(&direction);
    func_802727D8_de(&matrix);
    if (0.99999899f <= direction.y) {
        func_80272E3C_de(&matrix, -1.57079649f, player->views1C.view6C_5.heading, 0.0f);
    } else if (direction.y <= -0.99999899f) {
        func_80272E3C_de(&matrix, 1.57079649f, player->views1C.view6C_5.heading, 0.0f);
    } else {
        BuildDirectionMatrix(&matrix, &direction);
    }
    TranslateMatrix(&matrix, eye);
    func_802733B4_de(&matrix, 0.0f, 0.0f, D_800C9F70_de);
    func_8027347C_de(&matrix, 0.05f, 1.0f, D_800C9F70_de - Particle_GetPointDistance(&eye, &to));
    Rsp_ConvertMatrixToFixed(&matrix, &player->views1480.view1480_1.beams[D_800D297C]);

    aim = player->views1464.view1464_1.aim;
    if (player->views5DC.view5DC_2.view != 0) {
        height = player->views5DC.view5DC_2.view->unk128.y - player->views1C.view260_26.muzzle.y;
        aimHeight = aim.y;
        height = height < 0.0f ? aimHeight + height : aimHeight - height;
        aim.y = height;
    }
    Particle_SubtractVectors(&direction, &aim, &player->views1C.view260_26.muzzle);
    Particle_NormalizeVec3(&direction);
    func_802727D8_de(&matrix);
    BuildDirectionMatrix(&matrix, &direction);
    TranslateMatrix(&matrix, player->views1C.view260_26.muzzle);
    scale = 1.0f;
    func_8027347C_de(&matrix, scale, scale, -Particle_GetPointDistance(&origin, &player->views1464.view1464_1.aim));
    Rsp_ConvertMatrixToFixed(&matrix, &player->views1500.view1500_1.lasers[D_800D297C]);

    if (normal != 0) {
        lift = *normal;
        turn = func_80271818_de(&lift);
        MatrixFromQuaternion(&turn, &matrix);
        func_802737F0_de(&matrix, 1.57079649f);
        Particle_NormalizeVec3(&lift);
        Particle_ScaleVector(&lift, &lift, 2.048f);
        Particle_AddVec3(&eye, &eye, &lift);
        TranslateMatrix(&matrix, to);
        func_8027347C_de(&matrix, 1.536f, scale, 1.536f);
        Rsp_ConvertMatrixToFixed(&matrix, &player->views1580.view1580_1.dots[D_800D297C]);
    }
    player->views5E8.view1214_155.marker = 1;
}
