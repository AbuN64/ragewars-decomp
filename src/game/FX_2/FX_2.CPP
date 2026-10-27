#include "COMMON/VECTOR4F.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/S1.H"
#include "COMMON/EXTERNS_10.H"
#include "SYSTEM_3/802A6AC0.H"
#include "FX_2/80271B18.H"
#include "SYSTEM/80255C40_3.H"
#include "LISTS/80279520.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "SYSTEM_3/802A6AC0_2.H"
#include "include_asm.h"

/* 802A6AC0.CPP */
void Fx_AccumulateEffectComponents(ObjRecAt3CV1 *arg0) {
    if (arg0->unk24 != 0.0f) {
        D_800D15E4[0] += arg0->unk34;
        D_800D15E4[1] += arg0->unk38;
        D_800D15E4[2] += arg0->unk3C;
        D_800D15E4[3] += arg0->unk24;
    }
    D_800D15E4[4] += arg0->unk14;
}

extern f32 D_800C5EA0_de[2];

void Fx_ClampScalarRange(f32 *arg0) {
    f32 new_var;
    f32 new_var2;

    new_var2 = (new_var2 = *arg0);
    if (*arg0 < 0.0f) {
        *arg0 = 0.0f;
    } else {
        new_var = D_800C5EA0_de[1];
        if (new_var < new_var2) {
            *arg0 = new_var;
        }
    }
}

void Fx_AddTimedCallback(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    void *node;

    node = Lists_MoveHeadToInactiveList(arg0 + 0x7588);
    if (node != 0) {
        ((ObjRecAt18V6 *)(node))->unk18 = arg1;
        ((ObjRecAt18V6 *)(node))->unk14 = arg2;
        ((ObjRecAt18V6 *)(node))->unk8 = 0;
        ((ObjRecAt18V6 *)(node))->unkC = arg4;
        ((ObjRecAt18V6 *)(node))->unk10 = arg3;
    }
}

void PitchMatrixLocal(void *, f32);
void TranslateMatrix(char *, f32, f32, f32);
void ScaleMatrixLocal(void *, f32, f32, f32);
void GraphU64_ConvertMatrixToFixed(f32 *, PackedMatrixWords *);

Particle *Fx_SpawnImpactMark(SceneRecAt95A8 *scene, CVector3 position, CVector3 normal, s32 surface, s32 owner) {
    f32 matrix[16];
    CQuatern rotation;
    Particle *node;
    IntrusiveList *list;

    rotation = GraphU64_BuildDirectionQuaternion(&normal.x);
    if (D_800CDBE8 != 0) return 0;
    D_800CDBE8 = 1;
    list = &scene->lists[surface];
    node = scene->free.head;
    if (node != 0) {
        func_80255ED8_de(&scene->free, node);
    } else {
        node = list->head;
        if (node == 0) goto done;
        func_80255ED8_de(list, node);
    }
    func_80255D14_de(list, node);
    if (node != 0) {
        node->owner = owner;
        MatrixFromQuaternion(&rotation.x, matrix);
        PitchMatrixLocal(matrix, 1.5707965f);
        GraphU64_NormalizeVec3(&normal);
        GraphU64_ScaleVector(&normal, &normal, 2.048f);
        GraphU64_AddVec3(&position, &position, &normal);
        TranslateMatrix((char *)matrix, position.x, position.y, position.z);
        ScaleMatrixLocal(matrix, D_800C5EA8_de, 1.0f, D_800C5EA8_de);
        GraphU64_ConvertMatrixToFixed(matrix, &node->transform.matrix);
    }
done:
    return node;
}

/* 802A6AC0_2.CPP */
extern s32 Smp_UpdateRibbonLifetime(s32 arg0, State802A6DF8 *state);

extern f32 D_800D2988;

extern void TextLoad_LocateTextureResource(s32 *arg0, s32 arg1);

extern void Particle_EncodeRenderLayer(void *arg0, s32 *arg1);

typedef struct Image Image;

extern s32 D_800D297C;

extern void GraphU64_ConvertMatrixToFloat(f32 *, s32);

extern void GraphU64_ClampMatrixToFixedRange(f32 *arg0);

extern void GraphU64_GetMatrixTranslation(char *object, float *output);

extern void GraphU64_GetMatrixScale(void *arg0, f32 *arg1);



extern void Smp_UpdateLinkedNodeTransforms(void *arg0);

extern void Smp_UpdateRibbonMatrices(void *, void *);

extern void Smp_DrawTexturedRibbon(s32, void *, s32);

extern void Fx_DrawColoredRibbon(s32, void *, s32);

extern void Smp_AppendRibbonSegment(void *arg0, void *arg1, f32 *arg2);

void Fx_RecycleOwnerParticles(SceneRecAt95A8 *arg0, s32 arg1) {
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

void Fx_UpdateAttachedEffects(Owner802A6DF8 *owner) {
    State802A6DF8 *state;
    State802A6DF8 *next;
    u8 *object;

    state = owner->lists.inactive.head;
    if (state != 0) {
        do {
            next = state->next;
            if (Smp_UpdateRibbonLifetime((s32)owner, state) == 0) {
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
                Lists_MoveNodeToActiveList((struct Lists18 *)&owner->lists, (ListLink *)state);
            }
            state = next;
        } while (state != 0);
    }
}

void Fx_UpdateTimedCallbacks(void *arg0)
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
          Lists_MoveNodeToActiveList((struct Lists18 *)&((ObjectLinks7598 *)(arg0))->unk_7588, node);
        }
      }
      node = next;
    }
    while (node != 0);
  }
}

void Fx_ResolveEntryResource(void *unused, void *arg1, void *arg2) {
    CItem *entry = arg1;
    s32 field34;
    s32 *p;

    field34 = entry->unk34;
    if (field34 != -1) {
        p = &entry->unk14;
        TextLoad_LocateTextureResource(p, field34);
        if (arg2 != 0) {
            Particle_EncodeRenderLayer(arg2, p);
        }
    }
}

void Fx_DetachEffectObject(State802A6FE0 *state) {
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

void Fx_ConfigureSpriteImage(Image *image, Image *texture, Sprite *sprite) {
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

void Fx_UpdateChildTransform(Node44 *arg0, void *arg1) {
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
            GraphU64_ConvertMatrixToFloat(local, entry + ((D_800D297C << 6) + 0x60));
            scale = D_800C5EB8_de;
            if (((ParticleEffect *)entry)->entry->unk14 != 0) {
                scale = D_800C5EBC_de;
            }
            ScaleMatrixLocal(local, scale, scale, scale);
            GraphU64_ClampMatrixToFixedRange(local);
            GraphU64_GetMatrixTranslation((char *)local, &((ChildB4 *)arg1)->pos[0]);
            if (arg0->unk_3C & 4) {
                GraphU64_GetMatrixScale(local, &((ChildB4 *)arg1)->rot[0]);
            } else {
                GraphU64_ConvertMatrixToFixed(local, (PackedMatrixWords *)(arg1 + ((D_800D297C << 6) + 0x28)));
            }
        }
        ((ChildB4 *)arg1)->unk_8 = arg0->unk_8->unk_8;
    }
}

void Fx_UpdateNodeFractions(void *arg0) {
    StateSmpUpdateRibbonLifetime *state = arg0;
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

void Fx_DrawEffectGeometry(s32 pool, void *arg1, s32 camera) {
    State802A6DF8 *state = arg1;
    if (state->flags & 8) {
        Smp_UpdateLinkedNodeTransforms(arg1);
    }
    if (state->flags & 4) {
        Smp_UpdateRibbonMatrices(arg1, camera);
    }
    if (state->vertexCount >= 2) {
        if (state->renderMode >= 0) {
            Smp_DrawTexturedRibbon(pool, arg1, camera);
            return;
        }
        Fx_DrawColoredRibbon(pool, arg1, camera);
    }
}

void Fx_AppendAttachedTransform(void *arg0, void *arg1, void *arg2, s32 arg3) {
    State802A6DF8 *state = arg1;
    f32 local[16];
    Shared_Particle *entry;
    f32 scale;

    entry = state->object;
    if (entry == arg2 && state->value > 0.0f) {
        GraphU64_ConvertMatrixToFloat(local, arg3);
        scale = D_800C5EC0_de;
        if (entry->desc->renderModel != 0) {
            scale = D_800C5EC4_de;
        }
        ScaleMatrixLocal(local, scale, scale, scale);
        GraphU64_ClampMatrixToFixedRange(local);
        Smp_AppendRibbonSegment(arg0, state, local);
    }
}

void *Fx_FindAttachedEffect(Owner802A6DF8 *arg0, s32 arg1, s32 arg2) {
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

void Fx_DrawEffectPasses(void *pool, void *camera) {
    State802A6DF8 *node;

    node = ((Owner802A6DF8 *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode < 0) {
            if (node->flags & 8) {
                Smp_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                Smp_UpdateRibbonMatrices(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    Smp_DrawTexturedRibbon(pool, node, camera);
                } else {
                    Fx_DrawColoredRibbon(pool, node, camera);
                }
            }
        }
        node = node->next;
    }

    node = ((Owner802A6DF8 *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode > 0) {
            if (node->flags & 8) {
                Smp_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                Smp_UpdateRibbonMatrices(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    Smp_DrawTexturedRibbon(pool, node, camera);
                } else {
                    Fx_DrawColoredRibbon(pool, node, camera);
                }
            }
        }
        node = node->next;
    }
}
