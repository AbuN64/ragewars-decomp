#include "TYPES.H"

typedef struct { u8 pad0[0x79]; u8 yaw, pitch; s8 pitchMode; u8 pad7C; u8 freePitch; } ControlSettings;
typedef struct { u8 pad0[0x5D8]; ControlSettings *settings; u8 pad5DC[0xC0]; f32 yawInput, pitchInput; u8 pad6A4[0x80]; f32 pitch; u8 pad728[0xC4]; f32 damping; u8 pad7F0[0x9C4]; s32 locked; u8 pad11B8[0x20]; f32 cooldown; } Player;
typedef struct { u8 pad0[0x6C]; f32 yaw; } Body;
typedef struct { u8 pad0[0x50]; u32 flags; } Surface;
typedef struct { f32 enableYaw, yawRate, pitchRate, pitchScale, downScale, upScale; } Tuning;
extern void *func_8024E7DC_de(void *);
extern void func_80274870_de(f32 *, f32, f32);
extern f32 D_800C287C_de;
extern f32 D_800C2880_de;
extern f32 D_800C2884_de;
extern f32 D_800C2888_de;
extern f32 D_800C288C_de;
extern f32 D_800C2890_de;
extern f32 D_800C2894_de;
extern f32 D_800C2898_de;
extern f32 D_800C289C_de;
extern f32 D_800C28A0_de;
extern f32 D_800C28A4_de;
extern f32 D_800C28A8_de;
extern f32 D_800C28AC_de;
extern f32 D_800C28B0_de;

void func_802231D4_de(Player *player, Body *body, Tuning *tuning) {
    f32 damp, yawRate, pitchRate, input, value;
    ControlSettings *settings;
    Surface *surface;
    if (player->locked != 0 || 0.0f < player->cooldown) return;
    damp = player->damping * D_800C287C_de;
    settings = player->settings;
    input = ((f32)settings->yaw * D_800C2880_de - D_800C2884_de) * D_800C2888_de;
    damp = D_800C2884_de - damp;
    value = damp * tuning->yawRate;
    yawRate = (input + D_800C288C_de) * value;
    input = ((f32)settings->pitch * D_800C2880_de - D_800C2884_de) * D_800C2890_de;
    value = damp * tuning->pitchRate;
    value = value * tuning->pitchScale;
    pitchRate = (input + D_800C2894_de) * value;
    if (settings->pitchMode == 0) {
        if (settings->freePitch == 0) pitchRate = D_800C2898_de;
    } else if (settings->pitchMode == 1) pitchRate = D_800C2888_de;
    surface = func_8024E7DC_de(body);
    if (surface == 0 || (surface->flags & 0x6000) != 0x2000) {
        if (tuning->enableYaw != 0.0f) {
            value = player->yawInput * D_800C289C_de;
            value = value * tuning->enableYaw;
            value = value * D_800C28A0_de;
            func_80274870_de(&body->yaw, body->yaw + value, yawRate);
        }
    }
    input = -player->pitchInput * D_800C28A4_de;
    if (input < 0.0f) value = input * D_800C28A8_de * tuning->downScale;
    else value = input * D_800C28AC_de * tuning->upScale;
    value = value * D_800C28B0_de;
    func_80274870_de(&player->pitch, value, pitchRate);
}
