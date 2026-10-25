#include "include_asm.h"
#include "MENU/TEAMMENU.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "GFX/TEXT/802A8A94_5.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "gbi.h"
extern void Particle_TransformPoint(void *arg0, void *arg1, void *arg2);

extern Gfx *D_80110634;
extern s32 func_8022EB0C_de(Player *player, s32 weapon);
void Team_DrawWeaponIcons(CBarrel *menu, Item *items, s32 count, Player *player) {
    s32 width;
    s32 height;
    f32 fade;
    s32 level;
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 alpha;
    s32 red;
    s16 green;
    s32 blue;
    Racer *view;
    f32 *viewport;
    Item *item;

    level = D_801462C8.hudFade + 0x40;
    fade = menu->m_Alpha * (level < 0x100 ? level : 255.0f);
    item = items;
    while (--count != -1) {
        view = player->owner;
        scaleX = view->viewportWidth * (1.0f / 320.0f);
        scaleY = view->viewportHeight * (1.0f / 240.0f);
        viewport = &view->viewportWidth;
        x = viewport[2] + viewport[0] * 0.5f + item->position.x * 0.5f * viewport[0];
        y = viewport[3] + viewport[1] * 0.5f + item->position.y * 0.5f * viewport[1];
        alpha = item->width;
        if (item->icon != 0) {
            func_802AA950_de(item->icon, 0, &width, &height);
            if (menu->m_Selected == item->slot) {
                blue = red = func_802B6560_de(menu->m_Glow) * 63.0f + 192.0f;
                alpha = 1.0f;
                green = red;
            } else {
                red = func_8022EB0C_de(player, item->weapon);
                red = red == 0 ? 100 : 200;
                green = red;
                blue = red;
            }
            gDPSetEnvColor(D_80110634++, red, green, blue, (u32)(alpha * fade));
            func_802AAC28_de(item->icon, 0, x - width * item->height * scaleX * 0.5f,
                             y - height * item->height * scaleY * 0.5f,
                             scaleX * item->height, scaleY * item->height, 1);
        }
        item++;
    }
}

/* Lays out a player's weapon menu when it is active: for each of the eight slots at 0x1C holding a
   weapon it eases the slot's scale toward its target (1.3 times larger under the cursor at 0x37C),
   turns an offset raised by the menu's opening by the slot's angle to place it, and lists it with its
   weapon's icon from D_800D052C (no icon for weapons outside 0 to 21), then passes the list to
   Team_DrawWeaponIcons. */














extern ObjRecAt6V1 *D_800D052C[];

extern f32 func_80274808_de(f32, f32, f32);

extern void func_802727D8_de(Matrix *);

extern void func_80273C68_de(Matrix *, f32);



void func_80217928_de(CBarrel *menu, s32 arg1, s32 arg2) {
    Matrix matrix;
    CVector3 position;
    Item items[36];
    CVector3 offset;
    s32 count;
    s32 i;
    CBarrelWeapon *slot;
    Item *item;
    f32 target;
    f32 size;
    s32 weapon;

    if (menu->m_Mode != 0) {
        offset.x = 0.0f;
        item = items;
        count = 0;
        offset.y = -0.6f - (0.4f - menu->m_Alpha * 0.4f);
        offset.z = 0.0f;
        for (i = 0; i < 8; i++) {
            slot = &menu->m_WeaponList[i];
            if (menu->m_WeaponList[i].m_Weapon != -1) {
                if (i == menu->m_Selected) {
                    target = *(&D_800C9138_de + 1) * 1.3f;
                } else {
                    target = *(&D_800C9138_de + 1);
                }
                size = 1.0f;
                slot->m_Scale = func_80274808_de(slot->m_Scale, target, *(&D_800C9138_de + 1) * 0.1f);
                func_802727D8_de(&matrix);
                func_80273C68_de(&matrix, slot->m_Rot);
                Particle_TransformPoint(&matrix, &offset, &position);
                weapon = menu->m_WeaponList[i].m_Weapon;
                if (weapon < 0) {
                    goto no_icon;
                }
                if (weapon >= 0x16) {
                no_icon:
                    item->icon = item->width = 0;
                    item->slot = i;
                    item->weapon = menu->m_WeaponList[i].m_Weapon;
                    item->position = position;
                } else {
                    item->slot = i;
                    item->weapon = menu->m_WeaponList[i].m_Weapon;
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
        Team_DrawWeaponIcons(menu, items, count, (Player *)arg2);
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
