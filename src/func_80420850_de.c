#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"
/* Chooses a different enabled random character, updates its preview and selects an available costume. */









extern Selection_func_80420850_de *D_800E42D0;
extern Choice D_800E3A50[];
extern u8 D_800FEB57[][0x190];
extern s32 func_802744D4_de(void);
extern s32 func_8040EBD0_de(void *widget);

extern s32 func_8041F18C_de(s32 id);
extern void *func_8040EC30_de(void *parent, s32 id);
extern void func_8041CAD8_de(void *preview, s32 a1, s32 model, s32 a3, s32 a4, Vec3 scale, Vec3 position, f32 angle, s32 flags);

void func_80420850_de(s32 player) {
    s32 tries;
    s32 done;
    s32 id;
    s32 kind;
    s32 index;
    s32 costumes;

    tries = 0;
    done = 0;
    do {
        id = D_800E3A50[func_802744D4_de() % 17].id;
        if (func_8040EBD0_de(func_8040EC30_de(D_800E42D0->screen, (u16)id)) == 0 && D_800E42D0->rows[player].choice != id) {
            done = 1;
        } else if (++tries > 5000) {
#if defined(VERSION_DE)
            id = 0x90;
#elif defined(VERSION_EU_X)
            id = 0x96;
#else
            id = 0x92;
#endif
            done = 1;
        }
    } while (!done);
    D_800E42D0->rows[player].choice = id;
    kind = func_8041F1D8_de(id);
    index = func_8041F18C_de(D_800E42D0->rows[player].choice);
    {
        Vec3 scale;
        scale.x = D_800E3A50[index].scale[player];
        scale.y = D_800E3A50[index].scale[player];
        scale.z = D_800E3A50[index].scale[player];
        func_8041CAD8_de(D_800E42D0->rows[player].preview, 9, kind + 0x38F, 75, 24000, scale,
                      D_800E3A50[index].position[player], D_800E3A50[index].angle[player],
                      D_800E3A50[index].flags[player]);
    }
    costumes = D_800FEB57[player][kind];
    if (costumes <= 0) {
        costumes = 1;
    }
    D_800E42D0->rows[player].costume = func_802744D4_de() % costumes;
}
