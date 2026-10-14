#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"




























/* Settles a player's weapon sway and applies its walking bob unless the player is recoiling at 0x11D8:
   eases the kick angles at 0x72C and 0x728 and the three sway angles at 0x730 to 0x738 back to rest,
   caps the bob speed at 0x75C and bob strength at 0x758 and decays both, clearing them once the
   strength falls below 0.06, then advances the bob phase from the stride at 0x658 and eases the
   weapon height at 0x740 (from the model's height at 0xF4 or a default) and its side and forward
   offsets at 0x73C and 0x744 along the camera's heading. */







extern void func_80274870_de(f32 *, f32, f32);




void func_80223E34_de(SharedPlayer_func_80223E34_de *player, func_80203908_S4 *camera) {
    f32 step;
    f32 phase;
    f32 height;
    f32 rate;
    f32 amount;

    if (!(player->views5E8.view11D8_148.recoil > 0.0f)) {
        func_80274870_de(&player->views5E8.view72C_76.kickRoll, 0.0f, 0.25f);
        func_80274870_de(&player->views5E8.view728_74.kickPitch, 0.0f, 0.5f);
        step = 0.08726647496f;
        player->views5E8.view730_79.sway[0] = func_802747A0_de(player->views5E8.view730_79.sway[0], step);
        player->views5E8.view730_79.sway[1] = func_802747A0_de(player->views5E8.view730_79.sway[1], step);
        player->views5E8.view730_79.sway[2] = func_802747A0_de(player->views5E8.view730_79.sway[2], step);
        if (21.0f < player->views5E8.view75C_90.bobSpeed) {
            player->views5E8.view75C_90.bobSpeed = 21.0f;
        }
        if (0.1f < player->views5E8.view758_88.bobStrength) {
            player->views5E8.view758_88.bobStrength = 0.1f;
        }
        player->views5E8.view75C_90.bobSpeed = func_802747A0_de(player->views5E8.view75C_90.bobSpeed, 0.11666667f);
        player->views5E8.view758_88.bobStrength = func_802747A0_de(player->views5E8.view758_88.bobStrength, 0.00055555557f);
        if (player->views5E8.view758_88.bobStrength < 0.06f) {
            player->views5E8.view75C_90.bobSpeed = player->views5E8.view758_88.bobStrength = 0.0f;
        }
        phase = player->views5E8.view658_23.stride * player->views5E8.view75C_90.bobSpeed * 0.017453294f;
        if (player->views18.view18_2.model != 0) {
            height = player->views18.view18_2.model->height * 0.9f;
        } else {
            height = 82.94399261f;
        }
        rate = 0.5f;
        func_80274870_de(&player->views5E8.view740_84.height, height + player->views5E8.view758_88.bobStrength * (func_802B7130_de(phase) * 10.24f), rate);
        amount = player->views5E8.view758_88.bobStrength * (func_802B6560_de(phase) * 8.192f);
        func_80274870_de(&player->views5E8.view73C_81.side, -func_802B7130_de(camera->unk6C + 3.1415927f) * amount, rate);
        func_80274870_de(&player->views5E8.view744_86.forward, -func_802B6560_de(camera->unk6C + 3.1415927f) * amount, rate);
    }
}
