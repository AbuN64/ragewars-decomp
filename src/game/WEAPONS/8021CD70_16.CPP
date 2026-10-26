#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"

extern void Nav_EaseValueToward(f32 *value, f32 target, f32 rate);
extern void Weapons_UpdateViewAngles(SharedPlayer *,func_802165F8_S1 *,char *);
extern char D_800CED30;
extern f32 D_800D2988;
extern f32 D_800C29C0_de,D_800C29C4_de,D_800C29C8_de,D_800C29CC_de,D_800C29D0_de,D_800C29D4_de,D_800C29D8_de,D_800C29DC_de,D_800C29E0_de,D_800C29E4_de,D_800C29E8_de,D_800C29EC_de,D_800C29F0_de,D_800C29F4_de,D_800C29F8_de,D_800C29FC_de;
/* State callbacks receive an opaque actor context. */
void func_8022470C_de(void *playerContext, void *bodyContext) {
    SharedPlayer *player = playerContext;
    func_802165F8_S1 *body = bodyContext;
    f32 strafeSpeed;
    f32 elapsedStepTime;
    f32 forwardSpeedMagnitude;
    s32 currentFireAnimation;
    s32 leftStrafeAnimation;
    s32 rightStrafeAnimation;
    s32 forwardAnimation;
    s32 backwardAnimation;
    s32 crouchingView;
    s32 crouchingMovement;
    s32 jumpStarted;
    s32 var_v0_4;
    char *var_a2;
    char *var_a2_2;
    u16 kind;
    s32 nextAnimation;

    Weapons_EaseOwnerHeightEffect(playerContext);
    Nav_EaseValueToward(&player->views5E8.view72C_75.unk72C, 0.0f, 0.25f);
    crouchingView = 1;
    if (!(player->views5E8.view718_70.crouch > D_800C29C0_de)) {
        crouchingView = 0;
    }
    if (crouchingView != 0) {
        Weapons_UpdateViewAngles(player, body, &D_800CE7FC);
    } else {
        Weapons_UpdateViewAngles(player, body, &D_800CE7E4);
    }
    crouchingMovement = 1;
    if (!(player->views5E8.view718_70.crouch > D_800C29C4_de)) {
        crouchingMovement = 0;
    }
    if (crouchingMovement != 0) {
        func_802233F0_de(player, body, &D_800CE7C0);
    } else {
        func_802233F0_de(player, body, &D_800C94EC_de);
    }
    if ((player->views5E8.view7E8_105.unk7E8 == 0) && !(player->views5E8.view6E4_61.unk6E4 > D_800C29C8_de) && !(body->flags & 0xC0000) && (body->model->flags & 2) && (player->views5E8.view6B0_46.unk6B0 & 0x10) && (player->views5E8.view11D8_147.unk11D8 <= 0.0f)) { Weapons_SetPlayerState(player, body, 5); jumpStarted = 1; } else jumpStarted = 0;
    if (jumpStarted == 0) {
        if ((player->views5E8.view6C0_51.unk6C0 == 0.0f) && (player->views5E8.view6C4_54.unk6C4 == 0.0f)) {
            Weapons_SetPlayerState(player, body, 2);
        }
        if (((body->flags & 0x5000) == 0x4000) && (player->views5E8.view6D0_71.onGround != 0)) {
            elapsedStepTime = player->views5E8.view11C4_144.soundTime + D_800D2988;
            player->views5E8.view11C4_144.soundTime = elapsedStepTime;
            if ((player->views5E8.view6C8_56.unk6C8 > D_800C29CC_de) && (D_800C29D0_de <= elapsedStepTime)) {
                player->views5E8.view11C4_144.soundTime = (f32) (elapsedStepTime - D_800C29D0_de);
            }
        }
        kind = player->views1C.viewE4_7.kind;
        if (kind == D_800CE474[2]) {
            if (player->views5E8.view86C_125.unk86C == 0x7DA && player->views1C.view104_11.idleTime >= D_800C29D4_de) player->views5E8.view86C_125.unk86C = 0x7DB; else player->views5E8.view86C_125.unk86C = 0x7DA;
            return;
        }
        if (kind == D_800CE474[0]) {
            currentFireAnimation = player->views5E8.view86C_125.unk86C;
            if (currentFireAnimation == 0xFA0 && player->views1C.view104_11.idleTime < D_800C29D8_de) return;
            if (currentFireAnimation == 0x1004 && player->views1C.view104_11.idleTime < D_800C29DC_de) return;
        }
        if (body->flags & 0xC0000) {
            if (player->views5E8.view6C0_51.unk6C0 >= 0.0f) player->views5E8.view86C_125.unk86C = 0xA32;
            else player->views5E8.view86C_125.unk86C = 0xA37;
            return;
        }
        forwardSpeedMagnitude = player->views5E8.view6C0_51.unk6C0;
        if (forwardSpeedMagnitude < 0.0f) forwardSpeedMagnitude = -forwardSpeedMagnitude;
        strafeSpeed = player->views5E8.view6C4_54.unk6C4;
        if (strafeSpeed < 0.0f) {
            if (forwardSpeedMagnitude < -strafeSpeed) goto sideways;
            goto forward;
        }
        if (forwardSpeedMagnitude < strafeSpeed) {
sideways:
            if (player->views5E8.view6C4_54.unk6C4 < 0.0f) {
                if (player->views13B4.view13B4_3.character != &D_800CED30) { player->views5E8.view86C_125.unk86C = 0x802; return; }
                leftStrafeAnimation = player->views5E8.view86C_125.unk86C;
                if ((u32)(leftStrafeAnimation - 0x5E56) < 7U) {
                    if (player->views1C.view104_11.idleTime >= D_800C29E0_de) player->views5E8.view86C_125.unk86C = 0x5E2B;
                    return;
                }
                if (leftStrafeAnimation == 0x5E5E) {
                    if (player->views1C.view104_11.idleTime >= D_800C29E4_de) player->views5E8.view86C_125.unk86C = 0x5E2B;
                    return;
                }
                player->views5E8.view86C_125.unk86C = 0x5E2B;
            } else {
                if (player->views13B4.view13B4_3.character != &D_800CED30) { player->views5E8.view86C_125.unk86C = 0x80C; return; }
                rightStrafeAnimation = player->views5E8.view86C_125.unk86C;
                if ((u32)(rightStrafeAnimation - 0x5E56) < 7U) {
                    if (player->views1C.view104_11.idleTime >= D_800C29E8_de) player->views5E8.view86C_125.unk86C = 0x5E2C;
                    return;
                }
                if (rightStrafeAnimation == 0x5E5E) {
                    if (player->views1C.view104_11.idleTime >= D_800C29EC_de) player->views5E8.view86C_125.unk86C = 0x5E2C;
                    return;
                }
                player->views5E8.view86C_125.unk86C = 0x5E2C;
            }
        } else {
forward:
            if (player->views5E8.view6C0_51.unk6C0 >= 0.0f) {
                if (player->views13B4.view13B4_3.character != &D_800CED30) { player->views5E8.view86C_125.unk86C = 0x7DA; return; }
                forwardAnimation = player->views5E8.view86C_125.unk86C;
                if ((u32)(forwardAnimation - 0x5E56) < 9U) {
                    if (player->views1C.view104_11.idleTime >= D_800C29F0_de) player->views5E8.view86C_125.unk86C = 0x5E29;
                    return;
                }
                if (forwardAnimation == 0x5E5E) {
                    if (player->views1C.view104_11.idleTime >= D_800C29F4_de) player->views5E8.view86C_125.unk86C = 0x5E29;
                    return;
                }
                player->views5E8.view86C_125.unk86C = 0x5E29;
            } else {
                if (player->views13B4.view13B4_3.character != &D_800CED30) { player->views5E8.view86C_125.unk86C = 0x7DF; return; }
                backwardAnimation = player->views5E8.view86C_125.unk86C;
                if ((u32)(backwardAnimation - 0x5E56) < 7U) {
                    if (player->views1C.view104_11.idleTime >= D_800C29F8_de) player->views5E8.view86C_125.unk86C = 0x5E2A;
                    return;
                }
                nextAnimation = 0x5E5E;
                if (backwardAnimation != nextAnimation) {
                    nextAnimation = 0x5E2A;
                    player->views5E8.view86C_125.unk86C = nextAnimation;
                } else {
                    nextAnimation = 0x5E2A;
                    if (player->views1C.view104_11.idleTime >= D_800C29FC_de) player->views5E8.view86C_125.unk86C = nextAnimation;
                }
            }
        }
    }
}
