#include "span_1000/code_80217388.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "math_helpers.h"
#include "TYPES.H"
#include "common/unused.h"

/* Lays out a player's weapon menu when it is active: for each of the eight slots at 0x1C holding a
   weapon it eases the slot's scale toward its target (1.3 times larger under the cursor at 0x37C),
   turns an offset raised by the menu's opening by the slot's angle to place it, and lists it with its
   weapon's icon from D_800D052C (no icon for weapons outside 0 to 21), then passes the list to
   func_80217630_de. */














extern ObjRecAt6V1 *D_800D052C[];

extern f32 func_80274808_de(f32, f32, f32);

extern void func_802727D8_de(Matrix *);

extern void func_80273C68_de(Matrix *, f32);

extern void func_80272898_de(Matrix *, Vec3 *, Vec3 *);

extern void func_80217630_de(Menu *, Item *, s32, s32);

void func_80217928_de(Menu *menu, s32 arg1, s32 arg2) {
    Matrix matrix;
    Vec3 position;
    Item items[36];
    Vec3 offset;
    s32 count;
    s32 i;
    SlotRecAt14 *slot;
    Item *item;
    f32 target;
    f32 size;
    s32 weapon;

    if (menu->active != 0) {
        offset.x = 0.0f;
        item = items;
        count = 0;
        offset.y = -0.6f - (0.4f - menu->open * 0.4f);
        offset.z = 0.0f;
        for (i = 0; i < 8; i++) {
            slot = &menu->slots[i];
            if (menu->slots[i].weapon != -1) {
                if (i == menu->cursor) {
                    target = *(&D_800C9138_de + 1) * 1.3f;
                } else {
                    target = *(&D_800C9138_de + 1);
                }
                size = 1.0f;
                slot->scale = func_80274808_de(slot->scale, target, *(&D_800C9138_de + 1) * 0.1f);
                func_802727D8_de(&matrix);
                func_80273C68_de(&matrix, slot->angle);
                func_80272898_de(&matrix, &offset, &position);
                weapon = menu->slots[i].weapon;
                if (weapon < 0) {
                    goto no_icon;
                }
                if (weapon >= 0x16) {
                no_icon:
                    item->icon = item->width = 0;
                    item->slot = i;
                    item->weapon = menu->slots[i].weapon;
                    item->position = position;
                } else {
                    item->slot = i;
                    item->weapon = menu->slots[i].weapon;
                    item->position = position;
                    item->icon = D_800D052C[weapon]->unk6;
                    item->width = size;
                    item->height = size;
                }
                item++;
                count++;
            } else {
                item->icon = item->width = 0;
            }
        }
        func_80217630_de(menu, items, count, arg2);
    }
}

/* Returns which of eight menu directions a player's stick points in: -1 inside a dead zone of radius
   60, a diagonal (1, 3, 5 or 7) when both axes are non-zero and their magnitudes differ by less than 46,
   otherwise 2 or 6 when the horizontal axis dominates and 0 or 4 when the vertical one does, reading
   the stick bytes at 0xC6 and 0xC7 of the controller at 0x698. */
s32 func_80217B3C_de(PlayerRecAt698 *player) {
    ControllerRecAtC7 *controller;
    s8 x;
    s8 y;
    controller = player->controller;
    x = controller->x;
    y = controller->y;
    if (x * x + y * y < 3600) {
        return -1;
    }
    if (RW_ABS(RW_ABS(x) - RW_ABS(y)) < 46 && x != 0 && y != 0) {
        if (x * y > 0) {
            if (x > 0) {
                return 1;
            }
            if (controller->x != 0) {
                return 5;
            }
            return 5;
        }
        return y > 0 ? 7 : 3;
    }
    if (RW_ABS(x) > RW_ABS(y)) {
        return x <= 0 ? 6 : 2;
    }
    if (y > 0) {
        return 0;
    }
    return 4;
}
