#include "shared/func_804235A8_eu_closed.h"
#include "span_16E000/menu_screen_setup.h"
#include "span_16E000/code_80423280.h"
#include "span_16E000/code_80429C10.h"
#include "span_16E000/code_804366C4.h"

s32 func_8042A2B0_de(void *root, s32 unused, s32 delta) {
    MenuWidget *item;
    f32 alpha;
    s32 fade;
    s32 count, previous, level;
    SetupScreen *countdown;
    if (D_80154020.ready == 1) {
        D_80154020.ready = 0;
        if (D_80154020.value != -1) {
            D_800E4F60->unk44C->alpha = 0x5A;
            func_8029973C_de();
            func_80298368_de(D_80154020.value);
            return 0;
        }
        D_800E4F60->unk44C->alpha = 0xFF;
        D_800E4F60->unk3DC = 9;
        if (D_800E4F60->selection == 0) {
            func_8040E8D8_de(D_800E4F60->unk440, 1);
            item = D_800E4F60->unk448;
        } else item = D_800E4F60->unk444;
        func_8040E8D8_de(item, 1);
        func_8040E8D8_de(D_800E4F60->label, 1);
        func_8040E8D8_de(D_800E4F60->unk3F0, 1);
    }
    switch (D_800E4F60->unk3DC) {
    case 1:
        D_800E4F60->left->x += (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x -= (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E4F60->unk3E8, 1);
            func_80419F58_de(D_800E4F60->text3E4, 4);
            D_800E4F60->unk3DC = 4;
            D_800E4F60->unk3E0 = 4;
        }
        break;
    case 2:
        D_800E4F60->left->x -= (u16)D_800E4F60->leftCount;
        D_800E4F60->right->x += (u16)D_800E4F60->rightCount;
        if (--D_800E4F60->unk3E0 <= 0) {
            D_800E4F60->unk3DC = 3;
            func_8029973C_de();
            func_80298368_de(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk460 == 0) {
            func_802A2360_de();
            D_800E4F60->unk460 = 1;
            func_8040E8D8_de(D_800E4F60->unk458, 0);
        }
        break;
    case 4:
        countdown = D_800E4F60;
        previous = countdown->unk3E0;
        count = previous - 1;
        /* fakematch: preserve the target's comparison-based decrement,
         * which a normal saturating countdown would simplify to max(previous - 1, 0). */
        if (count >= 0) count = previous - (previous >= count);
        else count = 0;
        countdown->unk3E0 = count;
        if (D_800E4F60->unk3E0 <= 0 && func_80419F38_de(D_800E4F60->text3E4)) {
            func_80419F24_de(D_800E4F60->text3E4);
            func_8042A7B4_de(10);
            D_800E4F60->unk3DC = 9;
        }
        break;
    case 5:
        func_8040E8D8_de(D_800E4F60->unk458, 1);
        func_8040E8D8_de(D_800E4F60->unk3E8, 0);
        func_8042B2E4_de();
        func_8042A7B4_de(0);
        D_800E4F60->unk3DC = 2;
        D_800E4F60->unk3E0 = 4;
        func_8040E8D8_de(D_800E4F60->unk448, 0);
        func_8025DF34_de(0xE78);
        break;
    case 6: case 7: break;
    case 8:
        level = func_8040EC30_de(root, 0x312)->alpha;
        fade = level >> 1;
        func_8042A7B4_de(fade);
        if (fade < 10) {
            D_800E4F60->unk3DC = 3;
            func_8042E988_de(11);
            return 0;
        }
        break;
    case 9:
        fade = func_8040EC30_de(root, 0x312)->alpha;
        fade = (fade + 1) * 2;
        if (fade > 65) { fade = 65; D_800E4F60->unk3DC = 3; }
        func_8042A7B4_de(fade);
        if (D_800E4F60->selection == 0) func_8040E8D8_de(D_800E4F60->unk448, 1);
        break;
    }
    if (D_800E4F60->unk3DC == 3) {
        D_800E4F60->unk45C += delta;
        if (D_80154020.value == -1) {
            if (D_800E4F60->selection == 0) {
                alpha = func_802B6560_de((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->unk448;
                item->alpha = (u32)alpha;
            } else {
                alpha = func_802B6560_de((f32)D_800E4F60->unk45C * 0.0033333334f) * 100.0f + 150.0f;
                item = D_800E4F60->item;
                item->alpha = (u32)alpha;
            }
        }
    }
    return 0;
}
