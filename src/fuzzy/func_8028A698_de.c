#include "types.h"
#include "span_1000/code_8028CCB8.h"
typedef struct DraftSceneA698 {
    u8 pad[0x1B410]; s32 index, state; f32 timer; s32 loaded;
    u8 data[0x10]; s16 id; u8 pad432[2]; s32 current, pending;
    u8 pad43C[0x10]; s32 epoch;
} DraftSceneA698;
extern ColorEntry D_800CD6E4_de[];
extern f32 D_800D2988;
extern s32 D_801462CC;
#include "shared/menu_match_globals.h"
extern char D_80141008;
extern void *D_800D3A9C;
extern void func_804037D4_de(void), func_804030E0_de(s32);
extern s32 func_8044D220_de(void *, s32, s32, void *, s32), func_802934F8_de(void);
extern void func_80286AA8_de(void *, s32, s32), func_80239770_de(void *, void *, void *, f32);
void func_8028A698_de(DraftSceneA698 *scene)
{
    ColorEntry *entry = &D_800CD6E4_de[scene->index];
    s32 id;
    if (scene->state == 1) {
        if (scene->timer == entry->value) {
            if (scene->pending == 999) { func_804037D4_de(); func_804030E0_de(400); }
            if (scene->index == 0) scene->state = 0;
            else scene->state = 2;
            if (scene->pending < 0) { scene->pending = ~scene->pending; scene->loaded = 0; }
            else scene->loaded = func_8044D220_de(scene, -1, scene->pending, scene->data, 1);
            scene->current = scene->pending;
            if (!scene->loaded) id = scene->pending;
            else id = scene->id;
            func_80286AA8_de(scene, id, scene->loaded);
            if (scene->epoch != D_801462CC && func_802934F8_de()) {
                func_80239770_de(&D_80145088, &D_80141008, D_800D3A9C, 4.0f);
                scene->epoch = D_801462CC;
            }
        } else {
            scene->timer += D_800D2988;
            if (entry->value < scene->timer) scene->timer = entry->value;
        }
    } else if (scene->state == 2) {
        if (scene->timer == 0.0f) scene->state = 0;
        else {
            scene->timer -= D_800D2988;
            if (scene->timer < 0.0f) scene->timer = 0.0f;
        }
    }
}
