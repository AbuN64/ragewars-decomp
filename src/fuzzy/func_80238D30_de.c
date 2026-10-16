#include "types.h"
#include "gfx.h"
#include "gbi.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector3f;

typedef struct { Gfx * unk0; } func_80238D20_G1;
extern Gfx *D_80110634;
struct func_80238D20_S2;
extern struct func_80238D20_S2 *D_8012D4E4;
typedef struct { s32 unk0; } func_80238D20_G2;
extern s32 D_800E28D0[2];
typedef struct { f32 unk0; } func_80238D20_G3;
extern f32 D_800C3514_de;
extern void func_802A9234_de(s32);
extern s32 func_8026925C_de(s32);
extern void func_80272A10_de(void *, void *, Vector3f *);
extern void func_80238670_de(void *, f32, f32, f32, s32, s32);

typedef struct func_80238D20_S1 func_80238D20_S1;
typedef struct func_80238D20_S2 func_80238D20_S2;
typedef struct RecCode80200610 RecCode80200610;
struct func_80238D20_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x1E0 - 0x8 - sizeof(s32)];
    char unk1E0;
};
struct func_80238D20_S2 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5C - 0x8 - sizeof(char)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    s32* unk118;
    char pad118[0x198 - 0x118 - sizeof(s32*)];
    f32 unk198;
    char pad198[0x1F4 - 0x198 - sizeof(f32)];
    struct func_80238D20_S2 *unk1F4;
};
struct RecCode80200610 {
    char pad0[0x4];
    s32 unk4;
};

void func_80238D30_de(func_80238D20_S1 *arg0) {
    Vector3f value;
    f32 screen_x;
    f32 screen_y;
    f32 half;
    f32 *x;
    f32 *y;
    s32 mask;
    s32 state_mask;
    func_80238D20_S2 *node;

    mask = 8 << arg0->unk8;
    func_802A9234_de(0x64);
    func_8026925C_de(0x1A);
    gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
    node = D_8012D4E4;
    if (node != 0) {
        state_mask = 0x80000;
        x = &screen_x;
        y = &screen_y;
        do {
            if ((node->unk5C & mask) &&
                (*node->unk118 & state_mask)) {
                func_80272A10_de(&arg0->unk1E0, &node->unk8, &value);
                half = (f32)(D_800E28D0[0] / 2);
                *x = value.x * half + half;
                *y = value.y *
                         (f32)(-D_800E28D0[1] / 2) +
                     (f32)(D_800E28D0[1] / 2);
                func_80238670_de(arg0, screen_x, screen_y,
                              node->unk198 * D_800C3514_de,
                              0, 0);
            }
            node = node->unk1F4;
        } while (node != 0);
    }
}

