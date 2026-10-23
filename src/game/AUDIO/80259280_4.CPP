#include "COMMON/LISTNODE.H"
#include "AUDIO/80259280.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "TEXTURE/80256220_16.H"
extern void func_8025B6F8_de(void *arg0, int arg1, int arg2);

/* Starts a sound instance from a description: when the scene's free node list is not empty it takes the
 * first node under the audio lock (func_80258740_de/func_802587A4_de), unlinks it, gives it the next handle, the
 * volume, sample, priority, pan and pitch fields decoded from the description, full gain, the scene frame
 * and the position, prepares its channel through func_8025BB7C_de and func_8025BB84_de and inserts it into the
 * active list ahead of the first lower-priority node; returns the handle or -1 when no node is free. */











extern void func_8025BB84_de(void *, void *, s32);


extern s8 func_8025E518_de(void *);


extern u8 func_8025E548_de(void *);

extern s16 func_8025E578_de(void *);


/* Services the pending glyph requests of a text cache: each request still counting down its delay is ticked and, when it reaches zero, stamped with the current frame and the next sequence number; a request older than sixteen frames is moved to the done list, otherwise it reserves a cell for its glyph and a texture for its bitmap, stopping when none is free, copies itself into the cell, uploads the cell through func_802577F4_de and moves to the done list. The slot address is written as the doubled slot plus the table address because the cartridge adds the scaled index first; array indexing puts the table first (1 word). */


















extern s16 func_802B2510_de(char *, s32);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void func_802577F4_de(ContextCode802591C0 *, s32, s32, char *);

static inline void append(ListHead *head, Entry_func_80259440_de *entry) {
    entry->prev = head->prev;
    entry->next = (Entry_func_80259440_de *)head;
    head->prev->next = entry;
    head->prev = entry;
}

s32 func_80259260_de(ManagerRecAtD8V1 *manager, void *desc, Vec3Words *position, s32 volume, s32 extra) {
    NodeRecAtC8 *node;
    NodeRecAtC8 *first;
    NodeRecAtC8 *at;
    s32 *scene;
    s32 priority;

    if (manager->free.next != (NodeRecAtC8 *)&manager->free) {
        func_80258740_de(manager->scene);
        first = manager->free.next;
        first->prev->next = first->next;
        first->next->prev = first->prev;
        scene = manager->scene;
        node = first;
        node->handle = scene[0x108 / 4];
        scene[0x108 / 4] = node->handle + 1;
        node->volume = volume;
        node->voice = -1;
        node->volume16 = volume;
        node->group = func_8025E500_de(desc);
        node->priority = func_8025E518_de(desc);
        node->sample = func_8025E50C_de(desc);
        node->pan = func_8025E548_de(desc);
        node->flags = func_8025E578_de(desc);
        node->pitch = func_8025E554_de(desc);
        node->gainB = 0x7D00;
        node->gainA = 0x7D00;
        node->time = 0;
        node->frame = manager->scene[0x104 / 4];
        node->position = *position;
        node->pad58 = 0;
        node->padB4 = 0;
        func_8025BB7C_de(node->channel, ((struct ContextRecAt2BC0 *)manager->scene)->field2B8C);
        node->mix = manager->scene[0x2BAC / 4];
        func_8025BB84_de(node->channel, desc, extra);
        at = manager->active.next;
        priority = node->priority;
        while (at != (NodeRecAtC8 *)&manager->active) {
            if (at->priority < priority) {
                break;
            }
            at = at->next;
        }
        node->prev = at->prev;
        node->next = at;
        at->prev->next = node;
        at->prev = node;
        func_802587A4_de(manager->scene);
        return node->handle;
    }
    return -1;
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
    CellCode802591C0 *cell;

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
        cell = (CellCode802591C0 *)(cache->context->cells + 4 + slot * 0xCC);
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

void func_8025966C_de(void *arg0, s32 arg1) {
    (((struct ObjectLinks8 *) ((s8 *) arg0))->unk_4) = arg0;
    (((struct ObjectLinks8 *) ((s8 *) arg0))->unk_0) = arg0;
    func_8025B6F8_de(arg0 + 8, arg1, -1);
}

void *func_80259694_de(LinkPair *arg0) {
    arg0->first[1] = (void *) arg0->second;
    arg0->second[0] = (void *) arg0->first;
    return arg0;
}
