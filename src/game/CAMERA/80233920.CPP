#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/LIGHTDATA.H"
#include "TYPES.H"
#include "CAMERA/80233920.H"

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 func_802B72B0_de(f32);




void func_80233930_de(Effect33920 *arg0, CVector3 position, CVector3 *out) {
    f32 distance;
    f32 value;
    AxisWave *wave;

    Particle_SubtractVectors(&position, &position, &arg0->origin);
    distance = func_802B72B0_de((position.x * position.x) +
                             (position.y * position.y) +
                             (position.z * position.z));
    if (distance < arg0->radius) {
        distance = System_CosineEase(D_800C3090_de - (distance / arg0->radius));

        wave = &arg0->x;
        if (wave->mode == 0) goto x_sine;
        if (wave->mode != 1) goto x_zero;
        value = func_802B7130_de(wave->accumulator * D_800C3094_de) * wave->rate;
        goto x_done;
x_sine:
        value = Nav_RandomBetween(-wave->rate, wave->rate);
        goto x_done;
x_zero:
        value = 0.0f;
x_done:
        out->x += value * distance;

        wave = &arg0->y;
        if (wave->mode == 0) goto y_sine;
        if (wave->mode != 1) goto y_zero;
        value = func_802B7130_de(wave->accumulator * D_800C3098_de) * wave->rate;
        goto y_done;
y_sine:
        value = Nav_RandomBetween(-wave->rate, wave->rate);
        goto y_done;
y_zero:
        value = 0.0f;
y_done:
        out->y += value * distance;

        wave = &arg0->z;
        if (wave->mode == 0) goto z_sine;
        if (wave->mode != 1) goto z_zero;
        value = func_802B7130_de(wave->accumulator * D_800C309C_de) * wave->rate;
        goto z_done;
z_sine:
        value = Nav_RandomBetween(-wave->rate, wave->rate);
        goto z_done;
z_zero:
        value = 0.0f;
z_done:
        out->z += value * distance;
    }
}

/* Advances an overlay's fade: state 1 fades the alpha at 0x551 in over the 0x54B-frame duration up to the
 * maximum at 0x54A, state 2 holds the maximum for 0x54C frames, state 3 fades out over 0x54D frames and
 * returns to state 0; each state change restarts the timer at 0x538, which then advances by the frame
 * time D_800D2988. */



extern f32 D_800D2988;

void func_80233B14_de(Overlay *overlay) {
    switch (overlay->state) {
    case 1:
        if (overlay->fadeIn <= overlay->timer) {
            overlay->state = 2;
            overlay->timer = 0.0f;
            goto hold;
        }
        overlay->alpha = (u32)(overlay->timer / (overlay->fadeIn + 1) * overlay->alphaMax);
        break;
    case 0:
        break;
    case 2:
    hold:
        if (!(overlay->hold <= overlay->timer)) {
            overlay->alpha = overlay->alphaMax;
            break;
        }
        overlay->state = 3;
        overlay->timer = 0.0f;
        /* fallthrough */
    case 3:
        if (overlay->fadeOut <= overlay->timer) {
            overlay->state = 0;
            overlay->timer = 0.0f;
            break;
        }
        overlay->alpha = (u32)(overlay->alphaMax - overlay->timer / (overlay->fadeOut + 1) * overlay->alphaMax);
        break;
    }
    overlay->timer += D_800D2988;
}

/* Finishes an entity for the frame: when a player in the D_80145060 list owns it, draws its rectangle
 * through func_8029311C_de if that player shows outlines (flag 0x1000), using the entity's colour (or the
 * override colour D_800FEAD8 when D_800C9FE4 is set, darkened when option 0x4000 is set); it then
 * notifies the player list through func_8022A398_de when Camera_IsSequenceInWindow is clear and func_802934F8_de is set,
 * and finishes the entity through func_80245894_de. */





extern SharedPlayer *D_80145060;
extern s32 D_800C9FE4;
extern u8 D_800FEAD8[4];
extern s32 D_801462C8;
#include "COMMON/GAME_SESSION.H"
extern char D_80145040;
extern void func_8029311C_de(void *, u8 *, s32, s32, s32, s32);
extern s32 Camera_IsSequenceInWindow(void);
extern s32 func_802934F8_de(void);
extern void func_8022A398_de(void *, View *);
extern void func_80245894_de(View *);

static inline SharedPlayer *find_owner(View *entity) {
    SharedPlayer *player;

    for (player = D_80145060; player != 0; player = player->views16E0.view16E0_1.next) {
        if (player->views5DC.view5DC_4.entity == entity) {
            return player;
        }
    }
    return 0;
}

void func_80233C88_de(View *entity) {
    SharedPlayer *owner;
    u8 color[4];
    s32 i;

    owner = find_owner(entity);
    if (owner == 0) {
        return;
    }
    if (owner->views1C.view38_3.flags & 0x1000) {
        color[0] = entity->color[0];
        color[1] = entity->color[1];
        color[2] = entity->color[2];
        color[3] = entity->color[3];
        if (D_800C9FE4 != 0) {
            for (i = 0; i < 4; i++) {
                color[i] = D_800FEAD8[i];
            }
        }
        if (D_801462C8 & 0x4000) {
            color[0] >>= 3;
            color[1] >>= 3;
            color[2] >>= 3;
        }
        func_8029311C_de(&D_8011FAC0, color, entity->viewport[2], entity->viewport[3], entity->viewport[2] + entity->viewport[0],
                      entity->viewport[3] + entity->viewport[1]);
    }
    if (Camera_IsSequenceInWindow() == 0 && func_802934F8_de() != 0) {
        func_8022A398_de(&D_80145040, entity);
    }
    func_80245894_de(entity);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C2FE4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C33A4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C3364[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C30B4[1] = {
    0x00000000,
};
#endif
