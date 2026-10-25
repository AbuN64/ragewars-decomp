#include "COMMON/OBJRECAT18V6.H"
#include "SYSTEM_3/802A6AC0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "TYPES.H"
#include "SYSTEM_3/802A6AC0_2.H"
#include "LISTS/80279520.H"
#include "SYSTEM/80255C40_7.H"


extern s32 func_802A2FA4_de(s32 arg0, State802A6DF8 *state);

extern f32 D_800D2988;

extern void func_80295E84_de(s32 *arg0, s32 arg1);

extern void func_80283064_de(void *arg0, s32 *arg1);

typedef struct Image Image;

extern s32 D_800D297C;

extern void Rsp_ConvertMatrixToFloat(f32 *, s32);

extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

extern void func_80272828_de(f32 *arg0);

extern void func_802732D0_de(char *object, float *output);

extern void func_802732EC_de(void *arg0, f32 *arg1);

extern void func_8027027C_de(void *arg0, s32 arg1);

extern void Render_UpdateLinkedNodeTransforms(void *arg0);

extern void func_802A339C_de(void *, void *);

extern void func_802A3718_de(s32, void *, s32);

extern void func_802A3DD4_de(s32, void *, s32);

extern void func_802A25D0_de(void *arg0, void *arg1, f32 *arg2);

void func_802A5D38_de(SceneRecAt95A8 *arg0, s32 arg1) {
    s32 count;
    s32 offset;
    void **slot;
    Particle *node;
    Particle *next;

    if (arg0->free.count != 0x64) {
        count = 0;
        offset = 0x94E0;
        do {
            slot = &arg0->lists[count].head;
            node = *slot;
            if (node != 0) {
                do {
                    next = node->next;
                    if (node->owner == arg1) {
                        func_80255ED8_de(slot, node);
                        func_80255D14_de(&arg0->free, node);
                    }
                    node = next;
                } while (node != 0);
            }
            count += 1;
            offset += 0x14;
        } while (count < 0xA);
    }
}

void func_802A5E08_de(Owner802A6DF8 *owner) {
    State802A6DF8 *state;
    State802A6DF8 *next;
    u8 *object;

    state = owner->lists.inactive.head;
    if (state != 0) {
        do {
            next = state->next;
            if (func_802A2FA4_de((s32)owner, state) == 0) {
                object = state->object;
                if (object != 0) {
                    if (state->flags & 1) {
                        if (object[0x13B] != 0) {
                            object[0x13B]--;
                        }
                    }
                    if (state->flags & 2) {
                        object = state->object;
                        if (object[0x1D9] != 0) {
                            object[0x1D9]--;
                        }
                    }
                }
                state->object = 0;
                if (state->value < state->node->value) {
                    state->value = state->node->value;
                }
                func_802796F4_de((struct Lists18 *)&owner->lists, (ListLink *)state);
            }
            state = next;
        } while (state != 0);
    }
}

void func_802A5EE0_de(void *arg0)
{
  void *node;
  char *new_var;
  void *next;
  f32 value;
  s32 count;
  node = ((ObjectLinks7598 *)(arg0))->unk_7594;
  if (node != 0)
  {
    do
    {
      value = (((ObjectLinks14_2 *)(node))->unk_8 = (((ObjectLinks14_2 *)(node))->unk_8) - D_800D2988);
      next = ((ObjectLinks14_2 *)(node))->next;
      if (value <= 0.0f)
      {
        value += ((ObjectLinks14_2 *)(node))->unk_C;
        ((ObjectLinks14_2 *)(node))->unk_8 = value;
        if (value < 0.0f)
        {
          ((ObjectLinks14_2 *)(node))->unk_8 = 0.0f;
        }
        (((struct CallbackState1C *) ((char *) node))->callback)(node);
        count = (((struct func_8022BC04_S3 *) (new_var = (char *) node))->unk10) - 1;
        ((ObjectLinks14_2 *)(node))->unk_10 = count;
        if (count <= 0)
        {
          func_802796F4_de((struct Lists18 *)&((ObjectLinks7598 *)(arg0))->unk_7588, node);
        }
      }
      node = next;
    }
    while (node != 0);
  }
}

void func_802A5F9C_de(void *unused, void *arg1, void *arg2) {
    EntryRecAt34 *entry = arg1;
    s32 field34;
    s32 *p;

    field34 = entry->unk34;
    if (field34 != -1) {
        p = &entry->unk14;
        func_80295E84_de(p, field34);
        if (arg2 != 0) {
            func_80283064_de(arg2, p);
        }
    }
}

void func_802A5FF0_de(State802A6FE0 *state) {
    u8 *object;

    object = state->object;
    if (object != 0) {
        if (state->flags & 1) {
            if (object[0x13B] != 0) {
                object[0x13B]--;
            }
        }
        if (state->flags & 2) {
            object = state->object;
            if (object[0x1D9] != 0) {
                object[0x1D9]--;
            }
        }
    }
    state->object = 0;
    if (state->value < state->node->value) {
        state->value = state->node->value;
    }
}

/* Fills a sprite descriptor from an image: its pixel data and format, its two palette or data words, its scaled width and height, and when a second image is given the texture extents from its size shifts and the derived scale and step. */










void func_802A6068_de(Image *image, Image *texture, Sprite *sprite) {
    f32 scale;
    s32 height;
    f32 *unit;

    sprite->data = image->header->data;
    sprite->format = image->header->format;
    if (image->flags & 2) {
        sprite->field8 = image->fieldC;
        sprite->fieldC = image->field10;
    } else {
        sprite->field8 = image->fieldC;
        sprite->fieldC = image->fieldC;
    }
    scale = *(&D_800C5EA8_de + 1);
    sprite->width = image->header->width * scale;
    sprite->height = image->header->height * scale;
    if (texture != 0) {
        sprite->extentX = 1 << (texture->header->widthShift + 5);
        sprite->extentX = sprite->extentX * image->header->scale - D_800C5EB0_de;
        height = 1 << (texture->header->heightShift + 5);
        unit = &D_800C5EB0_de + 1;
        sprite->step = *unit / ((f32)sprite->format - *unit);
        sprite->extentY = height;
    }
}

void func_802A6174_de(Node44 *arg0, void *arg1) {
    f32 local[16];
    f32 scale;
    void *entry;
    Matrix *dst;
    Matrix *src;

    entry = ((ChildB4 *)arg1)->unk_B0;
    if (entry != 0) {
        if (entry == (void *)-1) {
            ((ChildB4 *)arg1)->mat[D_800D297C] = ((ChildB4 *)arg1)->mat[D_800D297C ^ 1];
            ((ChildB4 *)arg1)->unk_B0 = 0;
        } else {
            Rsp_ConvertMatrixToFloat(local, entry + ((D_800D297C << 6) + 0x60));
            scale = D_800C5EB8_de;
            if (((ParticleEffect *)entry)->entry->unk14 != 0) {
                scale = D_800C5EBC_de;
            }
            func_8027347C_de(local, scale, scale, scale);
            func_80272828_de(local);
            func_802732D0_de((char *)local, &((ChildB4 *)arg1)->pos[0]);
            if (arg0->unk_3C & 4) {
                func_802732EC_de(local, &((ChildB4 *)arg1)->rot[0]);
            } else {
                func_8027027C_de(local, arg1 + ((D_800D297C << 6) + 0x28));
            }
        }
        ((ChildB4 *)arg1)->unk_8 = arg0->unk_8->unk_8;
    }
}

void func_802A62BC_de(void *arg0) {
    State_func_802A2FA4_de *state = arg0;
    f32 accum;
    f32 delta;
    ChildB4 *node;

    if (state->amount > 0.0f) {
        accum = 0.0f;
        node = (ChildB4 *)state->nodes;
        if (node != 0) {
            do {
                node->fraction = accum / state->amount;
                delta = node->length;
                node = node->unk_4;
                accum += delta;
            } while (node != 0);
        }
    }
}

void func_802A6304_de(s32 pool, void *arg1, s32 camera) {
    State802A6DF8 *state = arg1;
    if (state->flags & 8) {
        Render_UpdateLinkedNodeTransforms(arg1);
    }
    if (state->flags & 4) {
        func_802A339C_de(arg1, camera);
    }
    if (state->vertexCount >= 2) {
        if (state->renderMode >= 0) {
            func_802A3718_de(pool, arg1, camera);
            return;
        }
        func_802A3DD4_de(pool, arg1, camera);
    }
}

void func_802A63A4_de(void *arg0, void *arg1, void *arg2, s32 arg3) {
    State802A6DF8 *state = arg1;
    f32 local[16];
    Shared_Particle *entry;
    f32 scale;

    entry = state->object;
    if (entry == arg2 && state->value > 0.0f) {
        Rsp_ConvertMatrixToFloat(local, arg3);
        scale = D_800C5EC0_de;
        if (entry->desc->renderModel != 0) {
            scale = D_800C5EC4_de;
        }
        func_8027347C_de(local, scale, scale, scale);
        func_80272828_de(local);
        func_802A25D0_de(arg0, state, local);
    }
}

void *func_802A6450_de(Owner802A6DF8 *arg0, s32 arg1, s32 arg2) {
    State802A6DF8 *node;

    node = arg0->lists.inactive.head;
    if (node != 0) {
        do {
            if ((s32)node->object == arg1) {
                if (node->contextId == arg2) {
                    return node;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return 0;
}

void func_802A6490_de(void *pool, void *camera) {
    State802A6DF8 *node;

    node = ((Owner802A6DF8 *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode < 0) {
            if (node->flags & 8) {
                Render_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                func_802A339C_de(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    func_802A3718_de(pool, node, camera);
                } else {
                    func_802A3DD4_de(pool, node, camera);
                }
            }
        }
        node = node->next;
    }

    node = ((Owner802A6DF8 *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode > 0) {
            if (node->flags & 8) {
                Render_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                func_802A339C_de(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    func_802A3718_de(pool, node, camera);
                } else {
                    func_802A3DD4_de(pool, node, camera);
                }
            }
        }
        node = node->next;
    }
}
