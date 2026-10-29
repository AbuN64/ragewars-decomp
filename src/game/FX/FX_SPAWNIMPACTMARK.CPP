#include "COMMON/VECTOR4F.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/S1.H"
#include "COMMON/TRIGGER_AND_FLOAT_VALUE_OPERATIONS.H"
#include "SYSTEM/TIMED_EFFECT_AND_ITEM_MENU_VIEWS.H"
#include "FX/GRAPHU64_NORMALIZEVEC3.H"
#include "SYSTEM/LIST.H"
#include "LISTS/LISTS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "SYSTEM/FX_SPAWNIMPACTMARK.H"
#include "include_asm.h"

/* 802A6AC0.CPP */
void Fx_AccumulateEffectComponents(EffectColorContribution *contribution) {
    if (contribution->alpha != 0.0f) {
        g_menuModelFillColor[0] += contribution->red;
        g_menuModelFillColor[1] += contribution->green;
        g_menuModelFillColor[2] += contribution->blue;
        g_menuModelFillColor[3] += contribution->alpha;
    }
    g_menuModelFillColor[4] += contribution->auxiliaryAlpha;
}

extern f32 g_effectContributionInitialScale[2];

void Fx_ClampScalarRange(f32 *scalarPointer) {
    f32 maximum;
    f32 contributionScale;

    contributionScale = (contributionScale = *scalarPointer);
    if (*scalarPointer < 0.0f) {
        *scalarPointer = 0.0f;
    } else {
        maximum = g_effectContributionInitialScale[1];
        if (maximum < contributionScale) {
            *scalarPointer = maximum;
        }
    }
}

void Fx_AddTimedCallback(s32 ownerAddress, s32 callbackContextAddress, s32 callbackAddress, s32 remainingCalls, f32 interval) {
    void *node;

    node = Lists_MoveHeadToInactiveList(ownerAddress + 0x7588);
    if (node != 0) {
        ((TimedEffectCallbackView *)(node))->callback = callbackContextAddress;
        ((TimedEffectCallbackView *)(node))->callbackData = callbackAddress;
        ((TimedEffectCallbackView *)(node))->countdown = 0;
        ((TimedEffectCallbackView *)(node))->interval = interval;
        ((TimedEffectCallbackView *)(node))->remainingCalls = remainingCalls;
    }
}

void PitchMatrixLocal(void *, f32);
void TranslateMatrix(char *, f32, f32, f32);
void ScaleMatrixLocal(void *, f32, f32, f32);
void Graphu64_ConvertMatrixToFixed(f32 *, PackedMatrixWords *);

Particle *Fx_SpawnImpactMark(ParticleQuadPoolScene *scene, CVector3 position, CVector3 normal, s32 surface, s32 owner) {
    f32 matrix[16];
    CQuatern rotation;
    Particle *node;
    IntrusiveList *list;

    rotation = Graphu64_BuildDirectionQuaternion(&normal.x);
    if (g_particleQuadDisplayListState != 0) return 0;
    g_particleQuadDisplayListState = 1;
    list = &scene->lists[surface];
    node = scene->free.head;
    if (node != 0) {
        List_RemoveIntrusive(&scene->free, node);
    } else {
        node = list->head;
        if (node == 0) goto done;
        List_RemoveIntrusive(list, node);
    }
    List_AppendIntrusive(list, node);
    if (node != 0) {
        node->owner = owner;
        MatrixFromQuaternion(&rotation.x, matrix);
        PitchMatrixLocal(matrix, 1.5707965f);
        Graphu64_NormalizeVec3(&normal);
        Graphu64_ScaleVector(&normal, &normal, 2.048f);
        Graphu64_AddVec3(&position, &position, &normal);
        TranslateMatrix((char *)matrix, position.x, position.y, position.z);
        ScaleMatrixLocal(matrix, g_impactMarkScaleConstants, 1.0f, g_impactMarkScaleConstants);
        Graphu64_ConvertMatrixToFixed(matrix, &node->transform.matrix);
    }
done:
    return node;
}

/* 802A6AC0_2.CPP */
extern s32 Linked_UpdateRibbonLifetime(s32 owner, ItemMenuRenderNode *state);

extern f32 g_frameElapsedTime;

extern void Textload_LocateTextureResource(s32 *resourceOutput, s32 sectionIndex);

extern void Particle_EncodeRenderLayer(void *actor, s32 *resource);

typedef struct Image Image;

extern s32 g_lightingBufferIndex;

extern void Graphu64_ConvertMatrixToFloat(f32 *, s32);

extern void Graphu64_ClampMatrixToFixedRange(f32 *matrixComponents);

extern void Graphu64_GetMatrixTranslation(char *object, float *output);

extern void Graphu64_GetMatrixScale(void *matrix, f32 *scaleOutput);



extern void Linked_UpdateLinkedNodeTransforms(void *owner);

extern void Linked_UpdateRibbonMatrices(void *, void *);

extern void Linked_DrawTexturedRibbon(s32, void *, s32);

extern void Fx_DrawColoredRibbon(s32, void *, s32);

extern void Linked_AppendRibbonSegment(void *ribbonOwner, void *attachmentState, f32 *local);

void Fx_RecycleOwnerParticles(ParticleQuadPoolScene *particlePool, s32 ownerId) {
    s32 count;
    s32 offset;
    void **slot;
    Particle *node;
    Particle *next;

    if (particlePool->free.count != 0x64) {
        count = 0;
        offset = 0x94E0;
        do {
            slot = &particlePool->lists[count].head;
            node = *slot;
            if (node != 0) {
                do {
                    next = node->next;
                    if (node->owner == ownerId) {
                        List_RemoveIntrusive(slot, node);
                        List_AppendIntrusive(&particlePool->free, node);
                    }
                    node = next;
                } while (node != 0);
            }
            count += 1;
            offset += 0x14;
        } while (count < 0xA);
    }
}

void Fx_UpdateAttachedEffects(RibbonWorld *owner) {
    ItemMenuRenderNode *state;
    ItemMenuRenderNode *next;
    u8 *object;

    state = owner->lists.inactive.head;
    if (state != 0) {
        do {
            next = state->next;
            if (Linked_UpdateRibbonLifetime((s32)owner, state) == 0) {
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

void Fx_UpdateTimedCallbacks(void *owner)
{
  void *node;
  char *callbackNodeAddress;
  void *next;
  f32 value;
  s32 count;
  node = ((AttachedEffectPoolView *)(owner))->activeAttachedEffects;
  if (node != 0)
  {
    do
    {
      value = (((AttachedEffectTimerView *)(node))->remainingTime = (((AttachedEffectTimerView *)(node))->remainingTime) - g_frameElapsedTime);
      next = ((AttachedEffectTimerView *)(node))->next;
      if (value <= 0.0f)
      {
        value += ((AttachedEffectTimerView *)(node))->interval;
        ((AttachedEffectTimerView *)(node))->remainingTime = value;
        if (value < 0.0f)
        {
          ((AttachedEffectTimerView *)(node))->remainingTime = 0.0f;
        }
        (((struct EffectCallbackEntryView *) ((char *) node))->callback)(node);
        count = (((struct AnimationResourceHandleView *) (callbackNodeAddress = (char *) node))->resourceHandle) - 1;
        ((AttachedEffectTimerView *)(node))->remainingCalls = count;
        if (count <= 0)
        {
          Lists_MoveNodeToActiveList((struct Lists18 *)&((AttachedEffectPoolView *)(owner))->attachedEffectLists, node);
        }
      }
      node = next;
    }
    while (node != 0);
  }
}

void Fx_ResolveEntryResource(void *unused, void *itemEntry, void *actor) {
    CItem *entry = itemEntry;
    s32 resourceId;
    s32 *p;

    resourceId = entry->updateCallbackOrTextureId;
    if (resourceId != -1) {
        p = &entry->imageFrameOrTextureHandle;
        Textload_LocateTextureResource(p, resourceId);
        if (actor != 0) {
            Particle_EncodeRenderLayer(actor, p);
        }
    }
}

void Fx_DetachEffectObject(AttachedEffectDetachState *state) {
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
        sprite->primaryData = image->primaryData;
        sprite->secondaryData = image->secondaryData;
    } else {
        sprite->primaryData = image->primaryData;
        sprite->secondaryData = image->primaryData;
    }
    scale = *(&g_impactMarkScaleConstants + 1);
    sprite->width = image->header->width * scale;
    sprite->height = image->header->height * scale;
    if (texture != 0) {
        sprite->extentX = 1 << (texture->header->widthShift + 5);
        sprite->extentX = sprite->extentX * image->header->scale - g_spriteExtentAndUnitConstants;
        height = 1 << (texture->header->heightShift + 5);
        unit = &g_spriteExtentAndUnitConstants + 1;
        sprite->step = *unit / ((f32)sprite->format - *unit);
        sprite->extentY = height;
    }
}

void Fx_UpdateChildTransform(Node44 *parentNode, void *childNode) {
    f32 local[16];
    f32 scale;
    void *entry;
    Matrix *dst;
    Matrix *src;

    entry = ((ChildB4 *)childNode)->attachedEntity;
    if (entry != 0) {
        if (entry == (void *)-1) {
            ((ChildB4 *)childNode)->mat[g_lightingBufferIndex] = ((ChildB4 *)childNode)->mat[g_lightingBufferIndex ^ 1];
            ((ChildB4 *)childNode)->attachedEntity = 0;
        } else {
            Graphu64_ConvertMatrixToFloat(local, entry + ((g_lightingBufferIndex << 6) + 0x60));
            scale = g_childTransformDefaultScale;
            if (((ParticleEffect *)entry)->entry->unk14 != 0) {
                scale = g_childTransformAlternateScale;
            }
            ScaleMatrixLocal(local, scale, scale, scale);
            Graphu64_ClampMatrixToFixedRange(local);
            Graphu64_GetMatrixTranslation((char *)local, &((ChildB4 *)childNode)->pos[0]);
            if (parentNode->flags & 4) {
                Graphu64_GetMatrixScale(local, &((ChildB4 *)childNode)->rot[0]);
            } else {
                Graphu64_ConvertMatrixToFixed(local, (PackedMatrixWords *)(childNode + ((g_lightingBufferIndex << 6) + 0x28)));
            }
        }
        ((ChildB4 *)childNode)->remainingLifetime = parentNode->definition->segmentLifetime;
    }
}

void Fx_UpdateNodeFractions(void *ribbonState) {
    StateSmpUpdateRibbonLifetime *state = ribbonState;
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
                node = node->next;
                accum += delta;
            } while (node != 0);
        }
    }
}

void Fx_DrawEffectGeometry(s32 pool, void *ribbon, s32 camera) {
    ItemMenuRenderNode *state = ribbon;
    if (state->flags & 8) {
        Linked_UpdateLinkedNodeTransforms(ribbon);
    }
    if (state->flags & 4) {
        Linked_UpdateRibbonMatrices(ribbon, camera);
    }
    if (state->vertexCount >= 2) {
        if (state->renderMode >= 0) {
            Linked_DrawTexturedRibbon(pool, ribbon, camera);
            return;
        }
        Fx_DrawColoredRibbon(pool, ribbon, camera);
    }
}

void Fx_AppendAttachedTransform(void *ribbonOwner, void *attachmentState, void *particle, s32 sourceMatrix) {
    ItemMenuRenderNode *state = attachmentState;
    f32 local[16];
    Shared_Particle *entry;
    f32 scale;

    entry = state->object;
    if (entry == particle && state->value > 0.0f) {
        Graphu64_ConvertMatrixToFloat(local, sourceMatrix);
        scale = g_attachedTransformDefaultScale;
        if (entry->desc->renderModel != 0) {
            scale = g_attachedTransformModelScale;
        }
        ScaleMatrixLocal(local, scale, scale, scale);
        Graphu64_ClampMatrixToFixedRange(local);
        Linked_AppendRibbonSegment(ribbonOwner, state, local);
    }
}

void *Fx_FindAttachedEffect(RibbonWorld *owner, s32 particleAddress, s32 contextId) {
    ItemMenuRenderNode *node;

    node = owner->lists.inactive.head;
    if (node != 0) {
        do {
            if ((s32)node->object == particleAddress) {
                if (node->contextId == contextId) {
                    return node;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return 0;
}

void Fx_DrawEffectPasses(void *pool, void *camera) {
    ItemMenuRenderNode *node;

    node = ((RibbonWorld *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode < 0) {
            if (node->flags & 8) {
                Linked_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                Linked_UpdateRibbonMatrices(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    Linked_DrawTexturedRibbon(pool, node, camera);
                } else {
                    Fx_DrawColoredRibbon(pool, node, camera);
                }
            }
        }
        node = node->next;
    }

    node = ((RibbonWorld *)pool)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode > 0) {
            if (node->flags & 8) {
                Linked_UpdateLinkedNodeTransforms(node);
            }
            if (node->flags & 4) {
                Linked_UpdateRibbonMatrices(node, camera);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    Linked_DrawTexturedRibbon(pool, node, camera);
                } else {
                    Fx_DrawColoredRibbon(pool, node, camera);
                }
            }
        }
        node = node->next;
    }
}
