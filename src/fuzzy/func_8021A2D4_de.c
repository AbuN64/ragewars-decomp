#include "types.h"

typedef struct DraftPlayerRenderInfo { char pad0[0x8F]; u8 team; } DraftPlayerRenderInfo;
typedef struct DraftPlayerRenderView { char pad0[0x551]; u8 alpha; } DraftPlayerRenderView;
typedef struct DraftPlayerRender {
    char pad0[0xE4]; u16 kind;
    char padE6[0x4F2]; DraftPlayerRenderInfo *info; DraftPlayerRenderView *view;
    s32 mode, active;
    char pad5E8[0x46]; s16 weapon;
    char pad630[0xBA8]; f32 ghost;
    char pad11DC[0x50]; u32 flags;
    char pad1230[0xC]; u8 red, green, blue, pad123F; f32 opacity;
    char pad1244[0x184]; s32 hidden;
    char pad13CC[0x84]; s32 fixedAlpha;
} DraftPlayerRender;
typedef struct DraftRenderDescriptor { char pad0[0xE]; u8 colour; } DraftRenderDescriptor;
typedef struct DraftRenderFrame { char data[0x18]; } DraftRenderFrame;
typedef struct DraftRenderActor {
    u8 type, colour, pad2; s8 pass;
    char pad4[0x14]; DraftRenderDescriptor *descriptor;
    char pad1C[0x98]; void *matrix;
    char padB8[0x88]; DraftRenderFrame frames[2];
    char pad170[0x68]; DraftPlayerRender *player;
} DraftRenderActor;
typedef struct DraftRenderContext { char pad0[0xC]; void **resource; } DraftRenderContext;
typedef struct DraftRenderWeapon { char pad0[4]; u16 model; } DraftRenderWeapon;
typedef struct DraftRenderGame { char pad0[0x54]; s32 teams; char pad58[0x1B]; u8 teamColour; } DraftRenderGame;
extern DraftRenderGame D_801468A0;
extern s32 D_801468F4, D_800CE47C, D_800C9228_de, D_800D297C, D_800D15E0;
extern u8 D_801462E5;
extern f32 D_800D15E4[5];
extern f32 D_800C22E4_de, D_800C22E8_de, D_800C22EC_de, D_800C22F0_de;
extern DraftRenderWeapon *D_800D052C[];
extern void func_8026B6A0_de(void **, void *, void *, s32, void *, s32, s32);
extern void func_8026D4F0_de(void **, void *, void *, s32, void *, s32, s32, s32, s32, s32, s32);
extern void func_80228FB8_de(void *, s32, void *);
extern void **func_8024BFD4_de(void *, s32);
extern void func_8026DA4C_de(void **, void *, s32, void *, void *, s32);
extern void func_80253754_de(s32, void *);

void func_8021A2D4_de(DraftRenderActor *actor, s32 arg1, DraftRenderContext *context)
{
    DraftPlayerRender *player;
    void **resource;
    s32 temporaryFlag, model;

    player = actor->player;
    if (0.0f < player->ghost) {
        temporaryFlag = !(player->flags & 0x8000);
        if (temporaryFlag) player->flags |= 0x8000;
        D_800D15E4[0] = 0.0f;
        D_800D15E0 = 3;
        if (player->flags & 0x4000) {
            D_800D15E4[2] = 0.0f;
            D_800D15E4[1] = D_800C22E4_de;
        } else {
            D_800D15E4[1] = 0.0f;
            D_800D15E4[2] = D_800C22E8_de;
        }
        if (player->fixedAlpha) D_800D15E4[3] = D_800C22EC_de;
        else D_800D15E4[3] = player->view->alpha;
        D_800D15E4[4] = D_800C22F0_de;
        if (D_801468A0.teams && player->info->team) actor->colour = D_801468A0.teamColour;
        else actor->colour = actor->descriptor->colour;
        func_8026B6A0_de(context->resource, player, actor->matrix, 1,
                       &actor->frames[D_800D297C], 0, actor->pass);
        D_800D15E0 = 0;
        if (temporaryFlag) player->flags &= ~0x8000;
    } else {
        if (D_801462E5) {
            if (player->info->team && D_801468F4 && player->active == 0) return;
            if (D_801462E5 && (player->hidden || player->kind == D_800C9228_de) &&
                player->active == 0) return;
        }
        if (player->flags & 0x20) func_80228FB8_de(actor, arg1, context);
        else {
            if (D_801468A0.teams && player->info->team) actor->colour = D_801468A0.teamColour;
            else actor->colour = actor->descriptor->colour;
            func_8026B6A0_de(context->resource, player, actor->matrix, 1,
                           &actor->frames[D_800D297C], 0, actor->pass);
            if (0.0f < player->opacity) {
                func_8026D4F0_de(context->resource, player, actor->matrix, 1,
                    &actor->frames[D_800D297C], 0, actor->pass, player->red,
                    player->green, player->blue, (s32)player->opacity & 255);
            }
        }
    }
    if ((u32)(player->mode - 0x11) < 2) return;
    if (player->mode == 15) return;
    if (player->info->team && D_801468F4) return;
    if (player->active == 0) return;
    if (player->kind == D_800CE47C) return;
    if (player->flags & 0x20) return;
    model = D_800D052C[player->weapon]->model - 0x4B3;
    if (player->weapon >= 16) model -= 2;
    if (model >= 0) {
        resource = func_8024BFD4_de(actor, model);
        if (resource) {
            func_8026DA4C_de(resource, actor->matrix, 1,
                            &actor->frames[D_800D297C], 0, actor->pass);
            func_80253754_de(0, resource);
        }
    }
}
