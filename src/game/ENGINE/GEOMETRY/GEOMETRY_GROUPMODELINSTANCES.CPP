#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAME_SESSION.H"
#include "RENDER/8026AC38.H"
#include "COMMON/SHAREDPLAYER.H"
#include "abi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "gbi.h"
#include "RENDER/8026AC38_2.H"
#include "RENDER/8028FD2C_6.H"

/* Draws the parts of a model resource that the owner has enabled, when the frame command buffer still has 3000 commands free: each part material's low two bits of byte 6 pick an owner flag at 0x102 (0x100, 0x8 or 0x2, 0x80 or 0x20 by bit 4) that must be set before Geometry_SetupMaterial accepts the material and its display list is emitted. Adapted from Geometry_DrawModelResource with the owner argument and the per-material flag switch added. */

extern Gfx *g_displayListCursor;
#include "COMMON/DISPLAY.H"
extern void Cache_MarkResourceInUse(s32 heap, void **resource);
extern s32 Geometry_ApplyMaterialLighting(s32 matrix, s32 lights, void *material);
extern s32 Geometry_SetupMaterial(void *material, s32 pass);

void Geometry_DrawVisibleOwnerParts(void **resource, struct Owner104 *owner, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    s32 visible;

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    Cache_MarkResourceInUse(0, resource);
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); }
    else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
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
        if (visible && Geometry_SetupMaterial(material, pass) != 0) {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
extern NodeGeometryGroupModelInstances *D_8010C568;
extern NodeGeometryGroupModelInstances *D_8010C56C;
extern NodeGeometryGroupModelInstances *D_8010C57C;
extern NodeGeometryGroupModelInstances *D_8010C584;
extern void **D_8011064C;
extern struct Shape_typemap_165 D_801157D8[];


/* Returns the node keyed key in the tree under n, or the node a new key would hang from. */
static inline NodeGeometryGroupModelInstances *find_node(NodeGeometryGroupModelInstances *n, u32 key) {
    NodeGeometryGroupModelInstances *parent = ((void *) 0);

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
void Geometry_GroupModelInstances(void) {
    s32 *list;
    s32 count;
    s32 i;
    s32 j;
    void *entry;
    ResourceSource *source;
    u32 key;
    NodeGeometryGroupModelInstances *parent;
    NodeGeometryGroupModelInstances *node;
    s32 *data;
    ItemRecAt1C *item;
    struct Shape_typemap_165 *param;

    if (D_80110640 != 0) {
        list = SetN64_GetPackSection(*D_8011064C, 2);
        count = *list;
        for (i = 0; i < count; i++) {
            entry = SetN64_GetPackSection(list, i);
            source = SetN64_GetPackSection(entry, 0);
            key = (source->id << 8) | (u8)D_8010C564;
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
            data = SetN64_GetPackSection(entry, 1);
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
