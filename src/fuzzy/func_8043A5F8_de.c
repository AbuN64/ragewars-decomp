#include "TYPES.H"
typedef struct DraftWidget3A5F8 { u8 pad[0x14]; u16 x; } DraftWidget3A5F8;
typedef struct DraftPanel3A5F8 { void *widget; u8 pad[0x4CC]; } DraftPanel3A5F8;
typedef struct DraftScreen3A5F8 {
    void *root; u8 pad4[0x4D0-4]; DraftPanel3A5F8 panels[3];
    void *fourth; u8 pad1344[4]; DraftWidget3A5F8 *left;
    u16 pad134C, leftStep; DraftWidget3A5F8 *right; u16 pad1354, rightStep;
    s32 state, timer; void *animation, *widget, *returnScreen;
} DraftScreen3A5F8;
typedef struct DraftRow3A5F8 { u16 id; u8 pad[2]; } DraftRow3A5F8;
typedef struct DraftIds3A5F8 { DraftRow3A5F8 rows[5]; u8 pad[0x38]; } DraftIds3A5F8;
extern DraftScreen3A5F8 *D_800E59E0;
extern DraftIds3A5F8 D_800E5A06[4];
extern void func_8025DF34_de(s32), func_8040E8D8_de(void *, s32), func_80419F58_de(void *, s32);
extern void func_8029973C_de(void), func_80298368_de(void *), func_802A2360_de(void), func_80419F24_de(void *);
extern s32 func_80419F38_de(void *);
extern void *func_8040EC30_de(void *, s32);
s32 func_8043A5F8_de(void)
{
    DraftScreen3A5F8 *screen;
    s32 i, j, timer;
    screen = D_800E59E0;
    switch (screen->state) {
    case 1:
        screen->left->x += screen->leftStep;
        screen->right->x -= screen->rightStep;
        if (--screen->timer <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E59E0->widget, 1);
            func_80419F58_de(D_800E59E0->animation, 4);
            D_800E59E0->state = 4;
            D_800E59E0->timer = 4;
        }
        break;
    case 2:
        screen->left->x -= screen->leftStep;
        screen->right->x += screen->rightStep;
        if (--screen->timer <= 0) {
            screen->state = 3;
            func_8029973C_de();
            func_80298368_de(D_800E59E0->returnScreen);
            return 0;
        }
        break;
    case 3: func_802A2360_de(); return 0;
    case 4:
        timer = screen->timer - 1;
        if (timer < 0) timer = 0;
        else timer = screen->timer - (screen->timer < timer ^ 1);
        screen->timer = timer;
        if (D_800E59E0->timer > 0) return 0;
        if (!func_80419F38_de(D_800E59E0->animation)) return 0;
        func_80419F24_de(D_800E59E0->animation);
        D_800E59E0->state = 3;
        break;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E59E0->state = 2;
        D_800E59E0->timer = 4;
        func_8040E8D8_de(D_800E59E0->widget, 0);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                func_8040E8D8_de(func_8040EC30_de(D_800E59E0->root, D_800E5A06[i].rows[j].id), 0);
            }
            if (i < 3) func_8040E8D8_de(D_800E59E0->panels[i].widget, 0);
            else func_8040E8D8_de(D_800E59E0->fourth, 0);
        }
        break;
    }
    return 0;
}
