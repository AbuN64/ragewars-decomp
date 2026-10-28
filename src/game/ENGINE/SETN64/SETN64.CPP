#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER_4/8028FD2C_6.H"
#include "SETN64/SETN64.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ACTOR_DEFINITION.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "RENDER_4/8028FD2C_11.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/TRIPLE.H"
#include "RENDER_4/8026AC38.H"
#include "RENDER_4/8028FD2C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJECTSTATE18.H"
#include "WORLD_2/8024E914_8.H"

/* 8028FD2C_4.CPP */
s32 SetN64_GetPackSize(s32 *bitSet) {
    s32 *packBase;
    s32 packSize;
    SetN64_GetPackBaseAndSize(bitSet, &packBase, &packSize);
    return packSize;
}

/* 8028FD2C_6.CPP */
/** Return the byte address named by an indexed word offset from the base. */
void *SetN64_GetPackSection(void *table, s32 index) {
    s32 *entry = (s32 *)table + index;
    return (char *)table + entry[1];
}

s32 SetN64_GetSizedPackSection(s32 packAddress, s32 sectionIndex, s32 *sectionSizeOut) {

    s32 *next = (s32 *)(packAddress + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(packAddress + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return packAddress + entry[1];
}

s32 SetN64_GetPackSectionSize(s32 *table, s32 index) {
    s32 nextIndex = index + 1;
    s32 *next = &table[nextIndex];
    s32 *entry = &table[index];
    s32 size;
    s32 *output = &size;
    *output = next[1] - entry[1];
    return size;
}

/* 8028FD2C_7.CPP */
/** Add an indexed word from the first argument to the second argument. */
int SetN64_GetDirectoryEntry(int *directory, int bankOffset, int level) {
    directory += level;
    return bankOffset + directory[1];
}

s32 SetN64_LocatePackSection(void *directory, s32 bankOffset, s32 sectionIndex, s32 *sectionSizeOut) {

    s32 *next = (s32 *)(directory + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(directory + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return bankOffset + entry[1];
}

s32 SetN64_GetPackSectionOffsetAndSize(s32 directoryAddress, s32 sectionIndex, s32 *sectionSizeOut) {

    s32 *next = (s32 *)(directoryAddress + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(directoryAddress + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return entry[1];
}

void SetN64_GetPackBaseAndSize(int *directory, int **packBaseOut, int *packSizeOut) {
    int *p;
    *packBaseOut = directory;
    p = directory + *directory;
    *packSizeOut = p[1];
}

/* 8028FD2C_9.CPP */
int SetN64_GetRecordBlockSize(int *recordHeader) {
    return recordHeader[0] * recordHeader[1] + 8;
}

void SetN64_GetChunkStorage(void *arg0, void **arg1, s32 *arg2) {
    *arg1 = arg0;
    *arg2 = ((((struct Shape_typemap_13 *) ((s8 *) arg0))->field_0) * (((struct Shape_typemap_13 *) ((s8 *) arg0))->field_4)) + 8;
}

/* 8028FD2C_11.CPP */
void *SetN64_GetChunkPayload(int *arg0, int *arg1) {
    *arg1 = arg0[0] * arg0[1];
    return &((ResidentDataChunk *)(arg0))->data[0];
}

/* Transposes the byte matrix after its eight-byte dimensions header and optionally copies the result back. */

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

void SetN64_TransposeRecords(void *sourceBlock, void *destinationBlock, s32 copyBack)
{
  char *data = &((ResidentDataChunk *)(sourceBlock))->data[0];
  s32 columnCount;
  int first_column;
  s32 rowCount;
  s32 rowIndex;
  s32 columnIndex;
  s32 sourceOffset;
  u8 *sourceByte;
  u8 *destinationByte;
  first_column = 0;
  func_802BD3A0_de(destinationBlock, sourceBlock, 8);
  destinationByte = destinationBlock + 8;
  columnCount = ((struct IntPair *) sourceBlock)->field_4;
  rowCount = ((struct IntPair *) sourceBlock)->field_0;
  columnIndex = first_column;
  if (columnCount > first_column)
  {
    do
    {
      rowIndex = 0;
      if (rowCount > 0)
      {
        sourceOffset = columnIndex;
        do
        {
          sourceByte = data + sourceOffset;
          sourceOffset += columnCount;
          rowIndex += 1;
          *destinationByte = *sourceByte;
          destinationByte += 1;
        }
        while (rowIndex < rowCount);
      }
      columnIndex += 1;
    }
    while (columnIndex < columnCount);
  }
  if (copyBack != 0)
  {
    func_802BD3A0_de(sourceBlock, destinationBlock, (columnCount * rowCount) + 8);
  }
}

/* Spawns a pooled object and registers its bounds and height. */

void GameObject_ResetActorMotion(void *);
s32 Scene_FindModelIdIndex(struct Shared_World *, s32);
s32 Scene_GetIndexedModelResource(void *, s32);
void Scene_SampleWorldLighting(void *, CVector3 *, void *);
void SetN64_RecycleEffectNode(void *, void *);

extern s32 D_800CD764_de[];

void *SetN64_SpawnModelEffect(char *arg0, s32 *referenceCounter, s32 arg2, CVector3 rotation, CVector3 position, s32 effectOwner, f32 initialLifetime)
{
  CVector3 center;
  s32 type;
  f32 far_z;
  s32 modelResource;
  char *effectActor;
  char *previousActiveHead;
  if (((*D_800CD764_de) == 0) || ((type = Scene_FindModelIdIndex(&g_world, arg2), type == (-1))))
  {
    return 0;
  }
  if ((((WorldRecAt3C08 *)(arg0))->free) == 0)
  {
    SetN64_RecycleEffectNode(arg0, ((WorldRecAt3C08 *)(arg0))->tail);
  }
  effectActor = ((WorldRecAt3C08 *)(arg0))->free;
  previousActiveHead = ((WorldRecAt3C08 *)(arg0))->head;
  ((WorldRecAt3C08 *)(arg0))->free = (void *) (((SceneEffect *)(effectActor))->next);
  if (previousActiveHead != 0)
  {
    ((SceneEffect *)(previousActiveHead))->prev = effectActor;
  }
  { char *next = ((WorldRecAt3C08 *)(arg0))->head;
  ((SceneEffect *)(effectActor))->prev = 0;
  ((SceneEffect *)(effectActor))->next = next; }
  ((WorldRecAt3C08 *)(arg0))->head = effectActor;
  if ((((WorldRecAt3C08 *)(arg0))->tail) == 0)
  {
    ((WorldRecAt3C08 *)(arg0))->tail = effectActor;
  }
  ((SceneEffect *)(effectActor))->state = (s32) ((((SceneEffect *)(effectActor))->state) | 1);
  GameObject_ResetActorMotion(effectActor);
  ((SceneEffect *)(effectActor))->lifetime = 0;
  modelResource = Scene_GetIndexedModelResource(&g_world, type);
  ((SceneEffect *)(effectActor))->counter = referenceCounter;
  if (referenceCounter != 0)
  {
    *referenceCounter += 1;
  }
  if (D_801462C8.local != 0)
  {
    ((SceneEffect *)(effectActor))->definition = &g_boundedEffectDefinition.header;
  }
  else
  {
    ((SceneEffect *)(effectActor))->definition = &g_defaultEffectDefinition;
  }
  ((SceneEffect *)(effectActor))->lifetime = initialLifetime;
  ((SceneEffect *)(effectActor))->lifetimeState = 0;
  ((SceneEffect *)(effectActor))->model = type;
  position.y += 10.24f;
  ((SceneEffect *)(effectActor))->position = position;
  ((SceneEffect *)(effectActor))->angle = 0;
  ((SceneEffect *)(effectActor))->angleState = 0;
  ((SceneEffect *)(effectActor))->collisionState = 0;
  ((SceneEffect *)(effectActor))->collisionScale = 1.0f;
  ((SceneEffect *)(effectActor))->collisionFlags = 0;
  ((SceneEffect *)(effectActor))->minX = (f32) (position.x - 81.92f);
  ((SceneEffect *)(effectActor))->minY = (f32) (position.y - 81.92f);
  ((SceneEffect *)(effectActor))->minZ = (f32) (position.z - 81.92f);
  ((SceneEffect *)(effectActor))->maxX = (f32) (position.x + 81.92f);
  ((SceneEffect *)(effectActor))->maxY = (f32) (position.y + 81.92f);
  far_z = position.z;
  ((SceneEffect *)(effectActor))->resource = modelResource;
  ((SceneEffect *)(effectActor))->animation = -1;
  ((SceneEffect *)(effectActor))->frame = 0;
  ((SceneEffect *)(effectActor))->frameState = 0;
  ((SceneEffect *)(effectActor))->owner = effectOwner;
  ((SceneEffect *)(effectActor))->boundsState = 0;
  ((SceneEffect *)(effectActor))->flags = 0x1A;
  ((SceneEffect *)(effectActor))->maxZ = (f32) (far_z + 81.92f);
  ((SceneEffect *)(effectActor))->rotation = rotation;
  ((SceneEffect *)(effectActor))->effectState = 0;
  center.x = ((SceneEffect *)(effectActor))->position.x;
  center.y = (((SceneEffect *)(effectActor))->position.y) + (GameObject_GetActorHeight(effectActor) * 0.5f);
  center.z = ((SceneEffect *)(effectActor))->position.z;
  Scene_SampleWorldLighting(&g_world, &center, (char *)effectActor + 0x1A8);
  return effectActor;
}

/* Updates a world's active actors: counts each actor's lifetime down by the frame time and expires it when the lifetime runs out or when its bounds leave the world box D_801031F0 (unless it is flagged 0x200); an expired active actor loses its active bit, decrements its owner's counter and moves from the active list to the free list, and every other actor is updated through SetN64_UpdateEffectMotionAndBounds. */

extern f32 D_800D2988;

void SetN64_UpdateEffectPool(WorldRecAt3C08 *world) {
    SceneEffect *actor;
    SceneEffect *next;
    s32 expired;
    f32 lifetime;

    next = world->head;
    if (next == 0) {
        return;
    }
    do {
        actor = next;
        next = actor->next;
        expired = 0;
        if (actor->lifetime > 0.0f) {
            lifetime = actor->lifetime - D_800D2988;
            actor->lifetime = lifetime;
            if (lifetime <= 0.0f) {
                expired = 1;
            }
        }
        if (!((D_801031F0.max.x > actor->minX) && (D_801031F0.min.x < actor->maxX) &&
              (D_801031F0.max.z > actor->minZ) && (D_801031F0.min.z < actor->maxZ) &&
              (D_801031F0.max.y > actor->minY) && (D_801031F0.min.y < actor->maxY))) {
            if (!(actor->flags & 0x200)) {
                expired = 1;
            }
        }
        if (expired) {
            if (actor->state & 1) {
                actor->state &= ~1;
                if (actor->counter != 0) {
                    (*actor->counter)--;
                }
                if (actor->prev != 0) {
                    actor->prev->next = actor->next;
                }
                if (actor->next != 0) {
                    actor->next->prev = actor->prev;
                }
                if (world->head == actor) {
                    world->head = actor->next;
                }
                if (world->tail == actor) {
                    world->tail = actor->prev;
                }
                actor->next = world->free;
                actor->prev = 0;
                world->free = actor;
            }
        } else {
            SetN64_UpdateEffectMotionAndBounds(actor);
        }
    } while (next != 0);
}

void SetN64_InitializeEffectSlot(struct EffectSlot *effectSlot) {
    effectSlot->definition = &g_defaultEffectDefinition;
    effectSlot->active = 3;
    effectSlot->state = 0;
}

extern char D_801003F8;
extern char D_80100438;

extern void func_8024F4A0_de(SceneEffect *);
extern void Unicol_MoveActorWithCollision(SceneEffect *, f32, f32, f32, void *);

void SetN64_UpdateEffectMotionAndBounds(SceneEffect *effect)
{
  void *collisionContext;
  f32 motionHoldTime;
  f32 radius;
  f32 x;
  CVector3 saved;
  collisionContext = &D_80100438;
  if (!(effect->definition->gate & 4))
  {
    collisionContext = &D_801003F8;
  }
  motionHoldTime = effect->lifetimeState;
  if (motionHoldTime > 0.0f)
  {
    effect->lifetimeState = (f32) (motionHoldTime - D_800D2988);
    saved = effect->position;
  }
  func_8024F4A0_de(effect);
  if (effect->definition != (&g_defaultEffectDefinition))
  {
    effect->rotation.x = 0.0f;
    effect->rotation.y = 0.0f;
    effect->rotation.z = 0.0f;
  }
  Unicol_MoveActorWithCollision(effect, effect->position.x, effect->position.y, effect->position.z, collisionContext);
  x = effect->position.x;
  radius = D_800C53A4_de;
  effect->minX = (f32) (x - radius);
  effect->minY = (f32) (effect->position.y - radius);
  effect->minZ = (f32) (effect->position.z - radius);
  effect->maxX = (f32) (effect->position.x + radius);
  {
    f32 z = effect->position.z + radius;
    f32 y = effect->position.y + radius;
    effect->maxY = y;
    effect->maxZ = z;
  }
}

/* 8028FD2C_12.CPP */
extern s32 Visdata_TestBoxAgainstFrustum(void *arg0, void *arg1);

extern void Simple_DrawCachedModel(void *arg0);

extern f32 D_801031F8[];

extern s32 func_8024D160_de(void *arg0);

/** Unlink an active node and return it to the global free list. */
void SetN64_RecycleGlobalEffectNode(ListNode80290528 *node) {
    ListNode80290528 *oldHead;

    if (node->flags & 1) {
        node->flags &= ~1;
        if (node->reference_count != 0) {
            (*node->reference_count)--;
        }
        if (node->previous != 0) {
            node->previous->next = node->next;
        }
        if (node->next != 0) {
            node->next->previous = node->previous;
        }
        if (D_80131144 == node) {
            D_80131144 = node->next;
        }
        if (D_80131148 == node) {
            D_80131148 = node->previous;
        }
        oldHead = D_80131140;
        node->previous = 0;
        *(ListNode80290528 *volatile *) &node->next = oldHead;
        D_80131140 = node;
    }
}

void SetN64_DrawVisibleEffects(char *effectPool, char *view) {
    WorldRecAt3C08 *world = (void *)effectPool;
    GameplayCamera *camera = (void *)view;
    SceneEffect *entry;
    f32 value;
    f32 upper;
    f32 scale;
    f32 zero;

    Geometry_BeginModelBatch();
    entry = world->head;
    if (entry != 0) {
        zero = 0.0f;
        upper = D_800C53A8_de;
        scale = D_800C53AC_de;
        do {
            if ((camera->clipBounds[1].x > entry->minX) &&
                (camera->clipBounds[0].x < entry->maxX) &&
                (camera->clipBounds[1].z > entry->minZ) &&
                (camera->clipBounds[0].z < entry->maxZ) &&
                (camera->clipBounds[1].y > entry->minY) &&
                (camera->clipBounds[0].y < entry->maxY) &&
                (Visdata_TestBoxAgainstFrustum(camera->clipPlanes, &entry->minX) != 0)) {
                value = entry->lifetime;
                D_800D15E0 = 0;
                if ((value > zero) && (value <= upper)) {
                    D_800D15E0 = 1;
                    D_800D15E4[3] = value * scale;
                }
                Simple_DrawCachedModel(entry);
                D_800D15E0 = 0;
            }
            entry = entry->next;
        } while (entry != 0);
    }
    Geometry_FlushModelBatch();
}

void SetN64_CollectVisibleEffectNodes(ContainerRecAt3C04 *effectPool, Results *results) {
    f32 *bounds;
    s32 count;
    s32 mask;
    s32 required;
    s32 limit;
    NodeSetN64CollectVisibleEffectNodes *node;

    node = effectPool->head;
    if (node != 0) {
        mask = 0x30000;
        required = 0x20000;
        bounds = D_801031F8 + 1;
        limit = 0x200;
        do {
            func_8024F470_de(node);
            if (((node->flags & mask) == required) &&
                (func_8024D160_de(node) != 0) &&
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
                !(((u16 *)&node->flags)[1] & 0x100) &&
#else
                !(*(u16 *)&node->flags & 0x100) &&
#endif
                (bounds[0] > node->x0) &&
                (bounds[-3] < node->y0) &&
                (bounds[2] > node->x2) &&
                (bounds[-1] < node->y2) &&
                (bounds[1] > node->x1) &&
                (bounds[-2] < node->y1)) {
                count = results->count;
                if (count != limit) {
                    results->nodes[count] = node;
                    results->count = count + 1;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}

void *SetN64_AllocateActorFromPool(ObjectLinks3C0C *container)
{
  void *new_var;
  void *node;
  struct ListNode80290528 *next;
  if ((container->unk_3C00) == 0)
  {
    SetN64_RecycleEffectNode(container, container->unk_3C08);
  }
  node = container->unk_3C00;
  next = container->next;
  container->unk_3C00 = ((ObjectLinks1E0 *)(node))->unk_1DC;
  if (next != 0)
  {
    next->previous = node;
  }
  new_var = container->next;
  ((ObjectLinks1E0 *)(node))->unk_1D8 = 0;
  ((ObjectLinks1E0 *)(node))->unk_1DC = new_var;
  container->next = node;
  if ((container->unk_3C08) == 0)
  {
    container->unk_3C08 = node;
  }
  ((ObjectLinks1E0 *)(node))->unk_1D0 |= 1;
  GameObject_ResetActorMotion(node);
  ((ObjectLinks1E0 *)(node))->unk_1C8 = 0;
  return node;
}

/* 800CA494.CPP */
/* ROM-grounded data: src/rw_pool_80290424_CB094_us_rev1.c */
const unsigned int D_blob_44d8067648dded17f40b[1] = {
    0x42A3D70A,
};

/* 800CA498.CPP */
/* ROM-grounded data: src/rw_pool_802905F4_CB098_us_rev1.c */
const unsigned int D_blob_4aa51b098be20f0efb1c[2] = {
    0x40F00000, 0x42080000,
};
