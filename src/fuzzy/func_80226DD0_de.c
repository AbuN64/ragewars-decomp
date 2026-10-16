#include "TYPES.H"
#include "common/types_06e4f7ef1f9e.h"
extern f32 D_800C2B74_de, D_800C2B78_de, D_80115DEC;
extern void func_80274098_de(void *, void *, void *), func_80274244_de(void *, void *), func_80272C60_de(void *, f32, f32, f32), func_8026F620_de(void *, void *, void *);
void func_80226DD0_de(SharedPlayer *player, f32 out[4][4])
{
    f32 qx[4], qy[4], qz[4];
    Shared_Quad rotation;
    f32 q1[4], q2[4];
    f32 m1[4][4], m2[4][4], m3[4][4], m4[4][4], m5[4][4], m6[4][4];
    f32 height, pitch, yaw, roll, x, y, z, scale, baseYaw, angle;
    height = player->views5E8.view740_83.unk740 + player->views5E8.view780_116.unk780 - player->views5E8.view718_70.crouch;
    pitch = player->views5E8.view724_72.pitch + player->views5E8.view730_78.unk730[0] - player->views5E8.view704_67.viewPitch;
    yaw = player->views5E8.view728_73.unk728 + player->views5E8.view730_78.unk730[1];
    roll = player->views5E8.view72C_75.unk72C + player->views5E8.view730_78.unk730[2];
    x = player->views0.view8_4.position.x + player->views5E8.view73C_80.unk73C;
    z = player->views0.view8_4.position.z + player->views5E8.view744_85.unk744;
    y = player->views0.view8_4.position.y;
    baseYaw = player->views1C.view6C_5.heading;
    if (height < D_800C2B74_de) height = D_800C2B74_de;
    scale = D_800C2B78_de;
    angle = roll * scale;
    rotation = player->views1C.view5C_6.unk5C;
    D_80115DEC = func_802B7130_de(angle);
    qz[0] = 0; qz[1] = 0; qz[2] = D_80115DEC;
    qz[3] = func_802B6560_de(angle);
    angle = pitch * scale;
    D_80115DEC = func_802B7130_de(angle);
    qx[0] = D_80115DEC; qx[1] = 0; qx[2] = 0;
    qx[3] = func_802B6560_de(angle);
    angle = (baseYaw + yaw) * scale;
    D_80115DEC = func_802B7130_de(angle);
    qy[0] = 0; qy[1] = D_80115DEC; qy[2] = 0;
    qy[3] = func_802B6560_de(angle);
    func_80274098_de(q1, qx, qy);
    func_80274098_de(q2, qz, q1);
    func_80274244_de(q2, m1);
    func_80272C60_de(m2, 0.0f, height, 0.0f);
    func_80274244_de(rotation.f, m3);
    func_8026F620_de(m5, m1, m2);
    func_8026F620_de(m6, m5, m3);
    func_80272C60_de(m4, x, y, z);
    func_8026F620_de(out, m6, m4);
}
