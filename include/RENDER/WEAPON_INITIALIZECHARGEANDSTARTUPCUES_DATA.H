#ifndef RENDER_WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA_H
#define RENDER_WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA_H
#include "COMMON/WEAPON_MARKER_AND_PROFILE_VIEWS.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/ITEMRECAT20V1.H"
struct PlayerForceMarkerCounterView {
    unsigned char padding_0[5848];
    u16 unk_16D8;
};
struct PlayerTintBlendStateView {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3288];
    f32 unk_12C0;
};
struct PlayerEffectTimerSet {
    char pad[0x1248];
    Timer timers[5];
};
struct PlayerAlternateFireStateView {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3112];
    s32 unk_1210;
    s32 unk_1214;
};
struct PlayerWeaponDelayStateView {
    char pad0[0x170];
    char unk_170;
    char pad170[0x174 - 0x170 - sizeof(char)];
    s32 unk_174;
    char pad174[0x11E4 - 0x174 - sizeof(s32)];
    f32 unk_11E4;
    char pad11E4[0x13E0 - 0x11E4 - sizeof(f32)];
    s32 unk_13E0;
};
struct PlayerForceMarkerHandleView {
    char pad0[0x120C];
    s32 unk120C;
};
struct PlayerWeaponTransitionParameterView {
    unsigned char padding_0[5840];
    s32 unk_16D0;
};
struct PlayerForceMarkerMatrixView {
    char pad0[0x160];
    MatrixF unk160;
};
struct PlayerForceMarkerOwnerView {
    char pad0[0x5DC];
    MatrixF * unk5DC;
};
struct PlayerLoopingSoundHandleView {
    unsigned char padding_0[4540];
    s32 unk_11BC;
};
struct PlayerForceMarkerStateView {
    unsigned char padding_0[4684];
    s32 unk_124C;
};
extern void Playerai_StopPrimaryAttachedSound(void *);
#endif
