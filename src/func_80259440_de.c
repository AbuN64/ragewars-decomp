#include "span_1000/code_802591C0.h"
#include "types.h"
/* Services the pending glyph requests of a text cache: each request still counting down its delay is ticked and, when it reaches zero, stamped with the current frame and the next sequence number; a request older than sixteen frames is moved to the done list, otherwise it reserves a cell for its glyph and a texture for its bitmap, stopping when none is free, copies itself into the cell, uploads the cell through func_802577F4_de and moves to the done list. The slot address is written as the doubled slot plus the table address because the cartridge adds the scaled index first; array indexing puts the table first (1 word). */















extern void func_80258740_de(Context_func_80259440_de *);
extern void func_802587A4_de(Context_func_80259440_de *);
extern s16 func_8025B034_de(char *, s32, s32, s32, s32);
extern s16 func_802B2510_de(char *, s32);
extern void func_802BD3A0_de(void *, void *, s32);
extern void func_802577F4_de(Context_func_80259440_de *, s32, s32, char *);

static inline void append(ListHead *head, Entry_func_80259440_de *entry) {
    entry->prev = head->prev;
    entry->next = (Entry_func_80259440_de *)head;
    head->prev->next = entry;
    head->prev = entry;
}

void func_80259440_de(Cache *cache) {
    s16 *slots;
    char *textures;
    Glyphs *glyphs;
    Entry_func_80259440_de *entry;
    Entry_func_80259440_de *next;
    s32 slot;
    s16 *cursor;
    s32 free;
    Cell_func_80259440_de *cell;

    func_80258740_de(cache->context);
    slots = cache->context->slots;
    textures = cache->context->textures;
    glyphs = cache->context->font->glyphs;
    for (entry = cache->pending.next; entry != (Entry_func_80259440_de *)&cache->pending; entry = next) {
        next = entry->next;
        if (entry->delay != 0) {
            if (--entry->delay == 0) {
                entry->frame = cache->context->frame;
                entry->sequence = cache->context->sequence++;
                entry->fieldA8 = 0;
            }
            continue;
        }
        if (cache->context->frame - entry->frame >= 16) {
            entry->prev->next = next;
            entry->next->prev = entry->prev;
            append(&cache->done, entry);
            continue;
        }
        slot = func_8025B034_de(cache->context->cells, entry->style, entry->font, entry->glyph, 0);
        if (slot == -1 || slot == 16) {
            break;
        }
        cursor = (s16 *)((slot << 1) + (u32)slots);
        free = *cursor;
        if (free != -1) {
            break;
        }
        *cursor = func_802B2510_de(textures, glyphs->bitmaps[entry->font]);
        if (*cursor == free) {
            break;
        }
        cell = (Cell_func_80259440_de *)(cache->context->cells + 4 + slot * 0xCC);
        func_802BD3A0_de(cell, entry->body, 0xCC);
        cell->sequence = entry->sequence;
        cell->texture = *cursor;
        cell->frame = cache->context->frame;
        cell->index = slot;
        func_802577F4_de(cache->context, cell->sequence, 0, cell->data);
        entry->sequence = free;
        entry->glyph = free;
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
        append(&cache->done, entry);
    }
    func_802587A4_de(cache->context);
}
