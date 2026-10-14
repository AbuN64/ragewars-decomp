#include "types.h"
typedef struct Shared_MenuSelection {
    u32 unknown0;
    s8 index;
} Shared_MenuSelection;
typedef struct Shared_MenuHandle {
    u8 unknown0[0x1C];
    struct SharedPlayer *owner;
    Shared_MenuSelection *selection;
} Shared_MenuHandle;
typedef struct Shared_MenuInput {
    u32 unknown0[8];
    s32 buttons;
} Shared_MenuInput;

#include "types.h"
#include "common/types_8a8189af7b05.h"
struct Shared_Model { u16 unknown0; u16 flags; };
struct Shared_Placed { Vec3 pos; u32 unknownC; s16 kind; };
struct Shared_Scratch { union { struct { s32 damage[5]; } view0_0; struct { Vec3 to; } view0_1; } views0; };
struct Shared_StateInfo { u32 unknown0; void (*update)(void *, void *); s32 *flags; u32 unknownC[3]; };
struct Shared_Surface { u8 unknown0[0x28]; f32 timer; u8 unknown2C[0x18]; s32 flags; u32 unknown48; u16 item; u16 unknown4E; u16 sound; };
struct Shared_PickupDef { u32 unknown0; s32 flags; u8 unknown8[0x10]; f32 radius; u32 unknown1C; s32 item; };
struct Shared_Pickup { u32 unknown0[2]; Vec3 pos; u32 unknown14; struct Shared_PickupDef *def; };
struct Shared_CharInfo { u32 unknown0; u16 sound; u16 unknown6; s16 ammo; u16 unknownA; union { struct { s16 next_s; } viewC_0; struct { u16 next_u; } viewC_1; } viewsC; };
struct Shared_Floor { u8 unknown0[0xE8]; f32 y; };
struct Shared_Profile { u8 unknown0[0x81]; u8 team; u8 controllerFlag; u8 quantity; u8 unknown84[0xB]; u8 remote; u8 unknown90[4]; u8 counts; };
struct Shared_Hud { u8 unknown0[0x120]; s32 score; u16 unknown124; u16 bonus; };
struct Shared_Shadow { u32 unknown0[2]; Vec3 pos; };
struct Shared_Voice { u32 unknown0[4]; s32 bank; };

#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"

struct Field;

extern char *D_800D7670[];
extern char *D_800D3648_de[];
extern char *D_800D364C_de[];
extern char *D_800D3650_de[];
extern char *D_800D3654[];
extern char *D_800D3658[];
extern char D_800DE2F0[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8043E2D8_de(struct Field *field, Shared_MenuHandle *holder) {
    s32 value = holder->owner->views5D8.view5D8_9.profile->quantity;
    char *text;

    if (value == 0) {
        field->text = D_800D3654;
    } else if (value == 10) {
        field->text = D_800D3658;
    } else {
        switch (holder->selection->index) {
        case 0:
        default:
            field->text = D_800D7670;
            break;
        case 1:
            field->text = D_800D3648_de;
            break;
        case 2:
            field->text = D_800D364C_de;
            break;
        case 3:
            field->text = D_800D3650_de;
            break;
        }
        text = *field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DE2F0, value);
    }
    return 0;
}
