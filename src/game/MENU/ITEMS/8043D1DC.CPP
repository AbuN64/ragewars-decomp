#include "include_asm.h"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/RG.H"



#if defined(VERSION_DE)
typedef struct { char pad0[0x80]; s8 choice; } Func_8043DB50_Slot;
typedef struct { char pad0[0x5D8]; Func_8043DB50_Slot *slot; s32 pad5DC; s32 style; } Func_8043DB50_Rec;
typedef struct { char pad0[0x1C]; Func_8043DB50_Rec *rec; struct ControllerProfile *player; } Func_8043DB50_Obj;
extern s16 D_auto_800E1DAA[][2];
extern u8 D_auto_800C9237[][4];
extern u8 D_auto_800C9233[][4];
extern char D_0044FA6C[];
extern s32 func_8026437C_de(struct ControllerProfile *object);
extern void func_8044A0C4_de(void *rec, s32 choice);
extern void func_8025DF34_de(s32 id);
extern void func_804427C4_de(s32 a, void *obj, void *res);
extern s32 func_80442488_de(void *obj, s32 value, s32 a, s32 b, s32 c, s32 d);
extern void func_8044214C_de(s32 a, s32 b, s32 c);
/* Steps the choice byte at 0x80 of the slot the record at 0x1C of arg1 points to: while the player passes func_8026437C_de it plays the sound for the record's style and runs the resource D_0044FA6C; otherwise func_80442488_de moves the choice and the remapping tables D_auto_800C9237 (func_80264388_de) and D_auto_800C9233 (func_802643A0_de or func_8026437C_de) are applied before the display is refreshed; returns 1 or 0. */
s32 func_8043DB50_de(s32 arg0, Func_8043DB50_Obj *arg1, s32 arg2) {
    Func_8043DB50_Rec *rec = arg1->rec;
    Func_8043DB50_Slot *slot = rec->slot;
    if (func_8026437C_de(arg1->player) != 0) {
        func_8044A0C4_de(rec, slot->choice);
        func_8025DF34_de(D_auto_800E1DAA[rec->style][0]);
        func_804427C4_de(arg2, arg1, D_0044FA6C);
        return 1;
    }
    slot->choice = func_80442488_de(arg1, slot->choice, 1, 0, 0x12, 1);
    if (func_80264388_de(arg1->player) != 0) {
        slot->choice = D_auto_800C9237[slot->choice][0];
    }
    if (func_802643A0_de(arg1->player) != 0 || func_8026437C_de(arg1->player) != 0) {
        slot->choice = D_auto_800C9233[slot->choice][0];
    }
    func_8044A0C4_de(rec, slot->choice);
    func_8044214C_de(arg0, 0xB, slot->choice);
    return 0;
}
#endif
#if defined(VERSION_DE) || defined(VERSION_US) || defined(NON_MATCHING)
s32 func_8043DCA4_de(TextBoundsText *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->value;
    switch (temp_v0) {
    case 2:
    default:
        if (D_80142235 != 0) {
            arg0->text = &D_800D3D14;
        } else {
            arg0->text = &D_800D3D18;
        }
        break;
    case 3:
        if (D_80142236 != 0) {
            arg0->text = &D_800D3D1C;
        } else {
            arg0->text = &D_800D3D20;
        }
        break;
    case 4:
        if (D_80142237 != 0) {
            arg0->text = &D_800D3D24;
        } else {
            arg0->text = &D_800D3D28;
        }
        break;
    case 5:
        if (D_80142238 != 0) {
            arg0->text = &D_800D3D2C;
        } else {
            arg0->text = &D_800D3D30;
        }
        break;
    case 6:
        if (D_80142239 != 0) {
            arg0->text = &D_800D3D34;
        } else {
            arg0->text = &D_800D3D38;
        }
        break;
    case 7:
        if (D_8014223A != 0) {
            arg0->text = &D_800D3D3C;
        } else {
            arg0->text = &D_800D3D40;
        }
        break;
    case 8:
        if (D_8014223B != 0) {
            arg0->text = &D_800D3D44;
        } else {
            arg0->text = &D_800D3D48;
        }
        break;
    case 9:
        if (D_8014223D != 0) {
            arg0->text = &D_800D3D4C;
        } else {
            arg0->text = &D_800D3D50;
        }
        break;
    }
    return 0;
}
#endif
