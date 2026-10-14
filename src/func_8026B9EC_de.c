#include "span_1000/code_8026AC38.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8026AC38.h"
#include "abi.h"
#include "gfx.h"
#include "types.h"
#include "gbi.h"
#include "n64sdk.h"

/* Draws the parts of a model resource that the owner has enabled, when the frame command buffer still has 3000 commands free: each part material's low two bits of byte 6 pick an owner flag at 0x102 (0x100, 0x8 or 0x2, 0x80 or 0x20 by bit 4) that must be set before func_80269A80_de accepts the material and its display list is emitted. Adapted from func_8026DA4C_de with the owner argument and the per-material flag switch added. */

extern Gfx *D_80110634;
extern struct Frame118 *D_8011BDC0;
extern u32 D_800E28A4;
extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_8026B504_de(s32 matrix, s32 lights, void *material);
extern s32 func_80269A80_de(void *material, s32 pass);

void func_8026B9EC_de(void **resource, struct Owner104 *owner, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    s32 visible;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); }
    else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        visible = 1;
        switch (((struct Material *)material)->flags & 3) {
        case 2:
            if (!(((struct Material *)material)->flags & 4)) {
                if (!(owner->flags & 8)) {
                    visible = 0;
                }
            } else {
                if (!(owner->flags & 2)) {
                    visible = 0;
                }
            }
            break;
        case 3:
            if (!(((struct Material *)material)->flags & 4)) {
                if (!(owner->flags & 0x80)) {
                    visible = 0;
                }
            } else {
                if (!(owner->flags & 0x20)) {
                    visible = 0;
                }
            }
            break;
        case 1:
            if (!(owner->flags & 0x100)) {
                visible = 0;
            }
            break;
        }
        if (visible && func_80269A80_de(material, pass) != 0) {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
extern u8 D_8010C567;
extern Node_func_8026BC60_de *D_8010C568;
extern Node_func_8026BC60_de *D_8010C56C;
extern s32 D_8010C570;
extern s32 D_8010C578;
extern Node_func_8026BC60_de *D_8010C57C;
extern s32 D_80110640;
extern Node_func_8026BC60_de *D_8010C584;
extern void **D_8011064C;
extern ItemRecAt1C D_8010C590[];
extern Node_func_8026BC60_de D_801144D0[];
extern struct Shape_typemap_165 D_801157D8[];

extern void *func_8028FDB4_de(void *, s32);

/* Returns the node keyed key in the tree under n, or the node a new key would hang from. */
static inline Node_func_8026BC60_de *find_node(Node_func_8026BC60_de *n, u32 key) {
    Node_func_8026BC60_de *parent = ((void *) 0);

    while (n != ((void *) 0)) {
        if (n->key == key) {
            return n;
        }
        parent = n;
        if (key < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    return parent;
}

/* Files each entry of the list the resource D_8011064C holds into one of two keyed trees, allocating a
 * node from D_801144D0 when its key is new, and appends one item per queued parameter in D_801157D8
 * to that node's list; then clears the queue count D_80110640. */
void func_8026BC60_de(void) {
    s32 *list;
    s32 count;
    s32 i;
    s32 j;
    void *entry;
    ResourceSource *source;
    u32 key;
    Node_func_8026BC60_de *parent;
    Node_func_8026BC60_de *node;
    s32 *data;
    ItemRecAt1C *item;
    struct Shape_typemap_165 *param;

    if (D_80110640 != 0) {
        list = func_8028FDB4_de(*D_8011064C, 2);
        count = *list;
        for (i = 0; i < count; i++) {
            entry = func_8028FDB4_de(list, i);
            source = func_8028FDB4_de(entry, 0);
            key = (source->id << 8) | D_8010C567;
            if (source->flags & 0x700) {
                parent = find_node(D_8010C57C, key);
            } else {
                parent = find_node(D_8010C568, key);
            }
            if (parent != ((void *) 0) && parent->key == key) {
                node = parent;
            } else {
                if (D_8010C578 == 120) {
                    break;
                }
                node = &D_801144D0[D_8010C578++];
                node->key = key;
                node->source = source;
                node->tail = ((void *) 0);
                node->head = ((void *) 0);
                if (source->flags & 0x700) {
                    if (parent != ((void *) 0)) {
                        if (node->key < parent->key) {
                            parent->left = node;
                            node->right = ((void *) 0);
                            node->left = ((void *) 0);
                            node->next = parent;
                            node->prev = parent->prev;
                            if (parent->prev != ((void *) 0)) {
                                parent->prev->next = node;
                            }
                            parent->prev = node;
                            if (D_8010C584 == parent) {
                                D_8010C584 = node;
                            }
                        } else {
                            parent->right = node;
                            node->right = ((void *) 0);
                            node->left = ((void *) 0);
                            node->next = parent->next;
                            if (parent->next != ((void *) 0)) {
                                parent->next->prev = node;
                            }
                            node->prev = parent;
                            parent->next = node;
                        }
                    } else {
                        D_8010C57C = node;
                        D_8010C584 = node;
                        node->right = ((void *) 0);
                        node->left = ((void *) 0);
                        node->next = ((void *) 0);
                        node->prev = ((void *) 0);
                    }
                } else {
                    if (parent != ((void *) 0)) {
                        if (node->key < parent->key) {
                            parent->left = node;
                            node->right = ((void *) 0);
                            node->left = ((void *) 0);
                            node->next = parent;
                            node->prev = parent->prev;
                            if (parent->prev != ((void *) 0)) {
                                parent->prev->next = node;
                            }
                            parent->prev = node;
                            if (D_8010C56C == parent) {
                                D_8010C56C = node;
                            }
                        } else {
                            parent->right = node;
                            node->right = ((void *) 0);
                            node->left = ((void *) 0);
                            node->next = parent->next;
                            if (parent->next != ((void *) 0)) {
                                parent->next->prev = node;
                            }
                            node->prev = parent;
                            parent->next = node;
                        }
                    } else {
                        D_8010C568 = node;
                        D_8010C56C = node;
                        node->right = ((void *) 0);
                        node->left = ((void *) 0);
                        node->next = ((void *) 0);
                        node->prev = ((void *) 0);
                    }
                }
            }
            data = func_8028FDB4_de(entry, 1);
            for (j = 0; j < D_80110640; j++) {
                param = &D_801157D8[j];
                if (D_8010C570 != 500) {
                    item = &D_8010C590[D_8010C570++];
                    item->data = data;
                    item->unk4 = param->field_0;
                    item->unk8 = param->field_4;
                    item->unkC = param->field_8;
                    item->unk10 = source->unk18;
                    item->unk12 = source->unk1A;
                    item->unk14 = param->field_C;
                    item->next = ((void *) 0);
                    if (node->tail != ((void *) 0)) {
                        node->tail->next = item;
                    } else {
                        node->head = item;
                    }
                    node->tail = item;
                }
            }
        }
        D_80110640 = 0;
    }
}
