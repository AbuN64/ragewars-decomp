#include "include_asm.h"
#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
#include "particle/80271B18_3.H"

extern unsigned int func_802227F4_de(void *arg0, void *arg1, s32 arg2);


extern void func_802732D0_de(char *, f32 *);

extern char D_8011D8D0;

extern void Particle_ReleaseOwnerEmitters(void *arg0, s32 arg1);

void func_8022B064_de(void *arg0, CVector3 *arg1)
{
  Shared_ActorView *player = arg0;
  void *new_var;
  player->resetPosition = *arg1;
  new_var = arg0;
  func_802227F4_de(new_var, new_var, 0x11);
}

extern void Weapons_BuildPlayerViewTransform(void *, MatrixF *);
void func_8022B09C_de(void *arg0, CVector3 *arg1) {
    CVector3 input;
    MatrixF matrix;
    CVector3 *input_ptr;
    MatrixF *matrix_ptr;

    func_8022B08C_S1 *object = arg0;
    func_8022B08C_S2 *owner;

    input = *arg1;
    input_ptr = &input;
    matrix_ptr = object->unk5DC;

    if (matrix_ptr != 0) {
        owner = (void *)matrix_ptr;
        matrix_ptr = &owner->unk160;
    } else {
        Weapons_BuildPlayerViewTransform(arg0, &matrix);
        matrix_ptr = &matrix;
    }
    Particle_TransformPoint(matrix_ptr, input_ptr, arg1);
}

void func_8022B11C_de(void *arg0, s32 arg1) {
    u16 temp_v0;
    u16 var_v1;
    temp_v0 = (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) + arg1;
    var_v1 = temp_v0;
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = temp_v0;
    if ((u32) (var_v1 & 0xFFFF) >= 0x65U) {
        var_v1 = 0x64;
    }
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = var_v1;
}

void func_8022B144_de(void *arg0, f32 *origin) {
    MatrixF sp10;
    Weapons_BuildPlayerViewTransform(arg0, &sp10);
    func_802732D0_de((char *)&sp10, origin);
}

/** Report whether the word at offset 0x5E4 is zero. */
int func_8022B178_de(struct SharedPlayer *player) {
    return player->views5E4.view5E4_0.unk5E4 == 0;
}

/** Return the word at offset 0x1210. */
int func_8022B184_de(struct SharedPlayer *object) {
    return object->views5E8.view1210_152.unk1210;
}

void func_8022B190_de(s32 actor) {
    Particle_ReleaseOwnerEmitters(&D_8011D8D0, actor);
}

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
typedef struct TogglePlayer { u8 pad0[0x5dc]; void *owner; u8 pad5e0[0xc1c]; f32 timer; CVector3 position; s32 mode; u8 pad1210[0x248]; CVector3 source; u8 pad1464[0xc]; CVector3 direction; s32 enabled; u8 pad1480[0x180]; u8 matrix[0x40]; } TogglePlayer;
extern f32 D_800C2D0C_de;
extern void *D_800D311C,*D_800D3120,*D_800D3124;
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"
extern void func_80273198_de(f32 *,CVector3 *);
extern void Particle_ScaleVector(CVector3 *,CVector3 *,f32);
extern void func_80271F34_de(CVector3 *,CVector3 *,CVector3 *);
extern void func_80273448_de(f32 *,f32,f32,f32);
extern void func_80273D6C_de(f32 *);
extern void func_8027027C_de(f32 *,void *);
void func_8022B1A8(TogglePlayer *player,s32 mode) {
    f32 matrix[16];
    CVector3 position;
    void *owner,*message;
    if (player->enabled != 0) {
        if (player->timer > 0.0f) {
            player->timer = 0;
            func_8025DF34_de(0x578);
            owner = player->owner;
            if (owner == 0) return;
            message = D_800D311C;
        } else {
            player->position = player->source;
            player->mode = mode;
            player->timer = D_800C2D0C_de;
            func_80273198_de(matrix,&player->direction);
            Particle_ScaleVector(&position,&player->direction,5.12f);
            func_80271F34_de(&position,&position,&player->position);
            func_80273448_de(matrix,position.x,position.y,position.z);
            func_80273D6C_de(matrix);
            func_8027027C_de(matrix,player->matrix);
            func_8025DF34_de(0x578);
            owner = player->owner;
            if (owner == 0) return;
            message = D_800D3124;
            if (mode != 0) message = D_800D3120;
        }
        Camera_PostScreenMessage(&D_80145088,owner,message);
    }
}
#else
INCLUDE_ASM("span_1000", func_8022B1A8);
#endif
#endif
