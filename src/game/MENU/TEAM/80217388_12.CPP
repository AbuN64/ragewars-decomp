#include "COMMON/SHAREDPLAYER.H"
#include "MENU/TEAMMENU.H"
#include "COMMON/UNUSED.H"
#include "particle/80271B18_3.H"

/* Lays out the four team choices around the open menu and draws their icons. */





extern f32 Nav_ApproachValue(f32, f32, f32);
extern void Particle_IdentityMatrix(Matrix *);
extern void RollMatrix(Matrix *, f32);
extern void func_802185D0_de(Menu_func_80218F9C_de *, ItemRecAt18V1 *, s32, void *);

void func_80218F9C_de(Menu_func_80218F9C_de *menu, s32 unused1, void *player) {
    Matrix matrix;
    CVector3 position;
    ItemRecAt18V1 items[4];
    CVector3 offset;
    s32 i;
    SlotRecAt10 *slot;
    ItemRecAt18V1 *item;
    f32 target;

    if (menu->active != 0) {
        offset.x = 0.0f;
        item = items;
        offset.y = -0.6f - (0.4f - menu->open * 0.4f);
        offset.z = 0.0f;
        for (i = 0; i < 4; i++) {
            slot = &menu->slots[i];
            if (i == menu->cursor) {
                target = *(&D_800C9178_de + 1) * 1.3f;
            } else {
                target = *(&D_800C9178_de + 1);
            }
            slot->scale = Nav_ApproachValue(slot->scale, target, *(&D_800C9178_de + 1) * 0.1f);
            Particle_IdentityMatrix(&matrix);
            RollMatrix(&matrix, slot->angle);
            Particle_TransformPoint(&matrix, &offset, &position);
            item->slot = i;
            item->position = position;
            item->icon = i + 0xC1C;
            item->width = 1.0f;
            item->height = 1.0f;
            item++;
        }
        func_802185D0_de(menu, items, 4, player);
    }
}
