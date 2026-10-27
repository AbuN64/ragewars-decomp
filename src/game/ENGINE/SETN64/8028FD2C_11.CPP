#include "COMMON/ACTOR_DEFINITION.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_11.H"

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
f32 GameObject_GetActorHeight(void *);
s32 Scene_FindModelIdIndex(struct Shared_World *, s32);
s32 Scene_GetIndexedModelResource(void *, s32);
void Scene_SampleWorldLighting(void *, CVector3 *, void *);
void SetN64_RecycleEffectNode(void *, void *);



extern s32 D_800CD764_de[];










void *SetN64_SpawnModelEffect(char *arg0, s32 *arg1, s32 arg2, CVector3 rotation, CVector3 position, s32 arg9, f32 initialLifetime)
{
  CVector3 center;
  s32 temp_v0;
  f32 far_z;
  s32 temp_v1_2;
  char *temp_s0;
  char *previousActiveHead;
  if (((*D_800CD764_de) == 0) || ((temp_v0 = Scene_FindModelIdIndex(&g_world, arg2), temp_v0 == (-1))))
  {
    return 0;
  }
  if ((((WorldRecAt3C08 *)(arg0))->free) == 0)
  {
    SetN64_RecycleEffectNode(arg0, ((WorldRecAt3C08 *)(arg0))->tail);
  }
  temp_s0 = ((WorldRecAt3C08 *)(arg0))->free;
  previousActiveHead = ((WorldRecAt3C08 *)(arg0))->head;
  ((WorldRecAt3C08 *)(arg0))->free = (void *) (((SceneEffect *)(temp_s0))->next);
  if (previousActiveHead != 0)
  {
    ((SceneEffect *)(previousActiveHead))->prev = temp_s0;
  }
  { char *next = ((WorldRecAt3C08 *)(arg0))->head;
  ((SceneEffect *)(temp_s0))->prev = 0;
  ((SceneEffect *)(temp_s0))->next = next; }
  ((WorldRecAt3C08 *)(arg0))->head = temp_s0;
  if ((((WorldRecAt3C08 *)(arg0))->tail) == 0)
  {
    ((WorldRecAt3C08 *)(arg0))->tail = temp_s0;
  }
  ((SceneEffect *)(temp_s0))->state = (s32) ((((SceneEffect *)(temp_s0))->state) | 1);
  GameObject_ResetActorMotion(temp_s0);
  ((SceneEffect *)(temp_s0))->lifetime = 0;
  temp_v1_2 = Scene_GetIndexedModelResource(&g_world, temp_v0);
  ((SceneEffect *)(temp_s0))->counter = arg1;
  if (arg1 != 0)
  {
    *arg1 += 1;
  }
  if (D_801462C8.local != 0)
  {
    ((SceneEffect *)(temp_s0))->definition = &g_boundedEffectDefinition.header;
  }
  else
  {
    ((SceneEffect *)(temp_s0))->definition = &g_defaultEffectDefinition;
  }
  ((SceneEffect *)(temp_s0))->lifetime = initialLifetime;
  ((SceneEffect *)(temp_s0))->lifetimeState = 0;
  ((SceneEffect *)(temp_s0))->model = temp_v0;
  position.y += 10.24f;
  ((SceneEffect *)(temp_s0))->position = position;
  ((SceneEffect *)(temp_s0))->angle = 0;
  ((SceneEffect *)(temp_s0))->angleState = 0;
  ((SceneEffect *)(temp_s0))->collisionState = 0;
  ((SceneEffect *)(temp_s0))->collisionScale = 1.0f;
  ((SceneEffect *)(temp_s0))->collisionFlags = 0;
  ((SceneEffect *)(temp_s0))->minX = (f32) (position.x - 81.92f);
  ((SceneEffect *)(temp_s0))->minY = (f32) (position.y - 81.92f);
  ((SceneEffect *)(temp_s0))->minZ = (f32) (position.z - 81.92f);
  ((SceneEffect *)(temp_s0))->maxX = (f32) (position.x + 81.92f);
  ((SceneEffect *)(temp_s0))->maxY = (f32) (position.y + 81.92f);
  far_z = position.z;
  ((SceneEffect *)(temp_s0))->resource = temp_v1_2;
  ((SceneEffect *)(temp_s0))->animation = -1;
  ((SceneEffect *)(temp_s0))->frame = 0;
  ((SceneEffect *)(temp_s0))->frameState = 0;
  ((SceneEffect *)(temp_s0))->owner = arg9;
  ((SceneEffect *)(temp_s0))->boundsState = 0;
  ((SceneEffect *)(temp_s0))->flags = 0x1A;
  ((SceneEffect *)(temp_s0))->maxZ = (f32) (far_z + 81.92f);
  ((SceneEffect *)(temp_s0))->rotation = rotation;
  ((SceneEffect *)(temp_s0))->effectState = 0;
  center.x = ((SceneEffect *)(temp_s0))->position.x;
  center.y = (((SceneEffect *)(temp_s0))->position.y) + (GameObject_GetActorHeight(temp_s0) * 0.5f);
  center.z = ((SceneEffect *)(temp_s0))->position.z;
  Scene_SampleWorldLighting(&g_world, &center, (char *)temp_s0 + 0x1A8);
  return temp_s0;
}

/* Updates a world's active actors: counts each actor's lifetime down by the frame time and expires it when the lifetime runs out or when its bounds leave the world box D_801031F0 (unless it is flagged 0x200); an expired active actor loses its active bit, decrements its owner's counter and moves from the active list to the free list, and every other actor is updated through SetN64_UpdateEffectMotionAndBounds. */






extern Box D_801031F0;
extern f32 D_800D2988;
extern void SetN64_UpdateEffectMotionAndBounds(SceneEffect *actor);

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

#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern char D_801003F8;
extern char D_80100438;

extern f32 D_800C53A4_de;
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
