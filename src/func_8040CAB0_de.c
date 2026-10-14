#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040C780.h"
#include "span_16E000/code_804143D8.h"
#include "types.h"
/* Flushes the queued text sprite batches: when any are queued it selects render mode 0x53333 if
   not already active, saves the clip rectangle and applies the queue's own, then walks the texture
   pages from the lowest first page to the highest last page among the batches, loading each page
   once through func_80410F54_de and func_804174F4_de (stopping the page when it cannot load) and drawing
   every batch's run of sprites on that page at depth 10 through func_80418DA0_de; finally it restores
   the clip rectangle and empties the queue. */







extern s32 D_8014D570;
extern s32 D_8014D580;
extern s32 D_8014D584;
extern s32 D_8014D588;
extern s32 D_8014D58C;
extern Batch D_8014D590[];
extern s32 D_800E2AB8;


extern s32 D_8014D714;


extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);
extern void func_802A1870_de(s32 left, s32 right, s32 top, s32 bottom);
extern s32 func_80410F54_de(s32 page, s32 a, s32 b);
extern void func_804174F4_de(s32 texture);
extern void func_80418DA0_de(f32 x, f32 y, f32 z, s32 color, f32 scale, s32 glyph);

static inline void func_8040CB30_restore(struct Shape_typemap_165 *clip) {
    func_802A1870_de(clip->field_0, clip->field_8, clip->field_4, clip->field_C);
}

void func_8040CAB0_de(void) {
    u16 first;
    u16 last;
    u16 page;
    s32 i;
    s32 current;
    s32 loaded;
    s32 texture;
    struct Shape_typemap_165 clip;
    Batch *batch;
    SpriteRecAt14 *sprite;

    if (D_8014D570 == 0) {
        return;
    }
    first = 0x60;
    last = 0;
    if (D_800DEA6C != 0x53333 || D_800E2AB8 == 0) {
        D_800DEA6C = 0x53333;
        func_80417138_de(0x53333);
        D_800E2AB8 = 1;
    }
    func_802A1898_de(&clip.field_0, &clip.field_8, &clip.field_4, &clip.field_C);
    func_802A1870_de(D_8014D580, D_8014D588, D_8014D584, D_8014D58C);
    for (current = 0; current < D_8014D570; current++) {
        sprite = D_8014D590[current].cursor;
        page = sprite->page;
        if (first < page) {
            page = first;
        }
        first = page;
        page = sprite[D_8014D590[current].count - 1].page;
        if (page < last) {
            page = last;
        }
        last = page;
    }
    for (current = first; current <= last; current++) {
        loaded = 0;
        for (i = 0; i < D_8014D570; i++) {
            batch = &D_8014D590[i];
            while (current == batch->cursor->page && batch->count > 0) {
                sprite = batch->cursor;
                if (!loaded) {
                    texture = func_80410F54_de(current & 0xFF, D_8014D710, D_8014D714);
                    if (texture == 0) {
                        i = D_8014D570;
                        break;
                    }
                    func_804174F4_de(texture);
                    loaded = 1;
                }
                func_80418DA0_de(sprite->x, sprite->y, 10.0f, sprite->color, sprite->scale, sprite->glyph);
                batch->cursor++;
                batch->count--;
            }
        }
    }
    func_8040CB30_restore(&clip);
    D_8014D570 = 0;
}
