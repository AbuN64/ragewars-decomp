#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct DraftPlayer26DD0 {
    u8 pad[8]; Vec3 position; u8 pad14[0x48]; f32 rotation[4], yaw;
    u8 pad70[0x698]; f32 x708; u8 pad70C[0xC]; f32 y718;
    u8 pad71C[8]; f32 x724, y728, z72C, x730, y734, z738, x73C, y740, z744;
    u8 pad748[0x38]; f32 y780;
} DraftPlayer26DD0;
extern f32 D_800C2B74_de, D_800C2B78_de, D_80115DEC;
extern void func_80274098_de(void *, void *, void *), func_80274244_de(void *, void *), func_80272C60_de(void *, f32, f32, f32), func_8026F620_de(void *, void *, void *);
void func_80226DD0_de(DraftPlayer26DD0 *player, f32 out[4][4])
{
    f32 qx[4], qy[4], qz[4], rotation[4], q1[4], q2[4];
    f32 m1[4][4], m2[4][4], m3[4][4], m4[4][4], m5[4][4], m6[4][4];
    f32 height, pitch, yaw, roll, x, y, z, scale, baseYaw;
    height = player->y740 + player->y780 - player->y718;
    pitch = player->x724 + player->x730 - player->x708;
    yaw = player->y728 + player->y734;
    roll = player->z72C + player->z738;
    x = player->position.x + player->x73C;
    z = player->position.z + player->z744;
    y = player->position.y;
    baseYaw = player->yaw;
    if (height < D_800C2B74_de) height = D_800C2B74_de;
    scale = D_800C2B78_de;
    rotation[0] = player->rotation[0]; rotation[1] = player->rotation[1];
    rotation[2] = player->rotation[2]; rotation[3] = player->rotation[3];
    roll *= scale;
    D_80115DEC = func_802B7130_de(roll);
    qz[0] = 0; qz[1] = 0; qz[2] = D_80115DEC;
    qz[3] = func_802B6560_de(roll);
    pitch *= scale;
    D_80115DEC = func_802B7130_de(pitch);
    qx[0] = D_80115DEC; qx[1] = 0; qx[2] = 0;
    qx[3] = func_802B6560_de(pitch);
    yaw = (baseYaw + yaw) * scale;
    D_80115DEC = func_802B7130_de(yaw);
    qy[0] = 0; qy[1] = D_80115DEC; qy[2] = 0;
    qy[3] = func_802B6560_de(yaw);
    func_80274098_de(q1, qx, qy);
    func_80274098_de(q2, qz, q1);
    func_80274244_de(q2, m1);
    func_80272C60_de(m2, 0.0f, height, 0.0f);
    func_80274244_de(rotation, m3);
    func_8026F620_de(m5, m1, m2);
    func_8026F620_de(m6, m5, m3);
    func_80272C60_de(m4, x, y, z);
    func_8026F620_de(out, m6, m4);
}
