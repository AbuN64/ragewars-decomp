#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "TYPES.H"
#include "gbi.h"
#include "ENGINE/SCENE_6.H"
#include "RENDER_4/8028FD2C_6.H"

char *Scene_GetLinkedResourceSection(void *arg0, s32 resourceId) {
    return SetN64_GetPackSection((((struct ObjectLinks74 *) ((s8 *) arg0))->unk_70), resourceId);
}

/** Return an indexed record from the table at object offset 0xA0. */
void *Scene_GetStridedWorldRecord(struct Shared_World *object, int index) {
    char *base = (char *)object->records;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

/* Draws a scene's object list inside a Geometry_BeginModelBatch and Geometry_FlushModelBatch pass: writes four G_MOVEWORD commands setting the words at 4, 0xC, 0x14 and 0x1C to 5, 5, 0xFFFB and 0xFFFB, then draws each object through func_80249E28_de unless its flag 4 is set, in which case it is deferred to the scene's 64-entry late list. */






extern Gfx *g_displayListCursor;


extern void func_80249E28_de(LevelActor *object, void *camera);

void Scene_DrawOpaqueActors(SceneRecAt10C0 *scene, void *camera) {
    LevelActor *object;
    s32 count;
    s32 i;
    s32 late;
    LevelActor **objects;

    Geometry_BeginModelBatch();
    count = scene->count;
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 4, 5);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 12, 5);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 20, 0xFFFB);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, 28, 0xFFFB);
    objects = scene->objects;
    for (i = 0; i < count; i++) {
        object = objects[i];
        if (object->flags & 4) {
            late = scene->lateCount;
            if (late != 64) {
                scene->late[late] = object;
                scene->lateCount = late + 1;
            }
        } else {
            func_80249E28_de(object, camera);
        }
    }
    Geometry_FlushModelBatch();
}

extern Gfx *g_displayListCursor;

extern void Particle_DrawRenderList(s32 arg0, s32 arg1);


void Scene_DrawWorldParticles(s32 world, s32 view) {
    Gfx *cmd;

    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 4, 1);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 12, 1);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 20, 0xFFFF);
    cmd = g_displayListCursor++;
    gSPMoveWord(cmd, G_MW_CLIP, 28, 0xFFFF);
    Geometry_BeginModelBatch();
    Particle_DrawRenderList(world + 0x1B08, view);
    Geometry_FlushModelBatch();
}

s32 Scene_FindModelIdIndex(struct Shared_World *arg0, s32 arg1)
{
  s32 count;
  s32 i;
  u16 *ptr;
  void *base;
  s32 masked;
  base = arg0->modelIds;
  count = ((struct TableRecAt8 *)(base))->count;
  ptr = &((struct TableRecAt8 *)(base))->entries[0];
  i = 0;
  if (count <= 0)
  {
    goto fail;
  }
  masked = arg1 & 0xFFFF;
  loop_2:
  if ((*ptr) == masked)
  {
 do { return i; } while (0);
  }

  i += 1;
  ptr += 1;
  if (i < count)
  {
    goto loop_2;
  }
  fail:
  return -1;

}

int Scene_GetModelIdAtIndex(void *world, int arg1) {
    unsigned short *base = (unsigned short *)((char *)((struct Shared_World *)(world))->modelIds + 8);
    return base[arg1];
}

/* Changes an object's model when the requested model id is present in the resource bank, then rebuilds its model data. */



extern void GameObject_LoadModel(ObjectSceneChangeInstanceModel *,s32,s32,s32);
static inline s32 find(TableRecAt8 *table,u16 id) {
 s32 index=0,count; u16 *entry;entry=table->entries;count=table->count;
 if(count>0) { do {if(*entry==id) return index; index++;entry++;} while(index<count); }
 return -1;
}
void Scene_ChangeInstanceModel(BankRecAt94 *arg0,ObjectSceneChangeInstanceModel *draw,s32 arg2,s32 arg3) {
 s32 index=0;
 if(draw->id!=arg2) {
 index=find(arg0->table,arg2);
 if(index!=-1){draw->index=index;draw->id=arg2;GameObject_LoadModel(draw,arg0->field54,arg0->field24,arg3);}
 }
}


void *Scene_GetModelRecordByIndexPointer(Shared_World *world, u16 *arg1) {
    s32 base;
    s32 idx;

    if (arg1 == 0) {
        return 0;
    }
    base = ((char *)SetN64_GetPackSection(world->modelSections, 0)) + 8;
    idx = *arg1;
    return (void *)(base + idx * 0x64);
}


u32 Scene_GetModelSectionTwoIndex(Shared_World *world, s32 arg1) {
    s32 offset;
    s32 result;

    if (arg1 == 0) {
        return -1;
    }
    offset = ((char *)SetN64_GetPackSection(world->modelSections, 2)) + 8;
    result = arg1 - offset;
    return (u32)result >> 5;
}







s32 Scene_GetModelSectionTwoRecord(void *world, s32 arg1) {
    s32 raw;
    s32 base;

    raw = SetN64_GetPackSection(((Shared_World *)world)->modelSections, 2);
    base = raw + 8;
    if (arg1 < 0 || arg1 >= ((StridedTable *)raw)->count) {
        return 0;
    }
    return base + (arg1 << 5);
}

extern void func_8028FDF8_de(s32 arg0, s32 arg1);




void Scene_SetSecondaryLevelBit(struct Shared_World *world, s32 index, s32 arg2, s32 arg3) {
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(world->secondaryLevels, 0), index), 0);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (arg2 & 7);
    if (arg3 != 0) {
        idx = arg2;
        if (arg2 < 0) {
            idx = arg2 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg2;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

void func_8028B4C8_de(void) {
}

extern void func_8028FDF8_de(s32 arg0, s32 arg1);




void Scene_SetCurrentSecondaryLevelBit(struct Shared_World *world, s32 arg1, s32 enabled) {
    void *field84;
    s32 field1B40C;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    field84 = world->secondaryLevels;
    field1B40C = world->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field84, 0), field1B40C), 0);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (arg1 & 7);
    if (enabled != 0) {
        idx = arg1;
        if (arg1 < 0) {
            idx = arg1 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg1;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

extern void func_8028FDF8_de(s32 arg0, s32 arg1);




s32 Scene_TestCurrentSecondaryLevelBit(struct Shared_World *world, s32 bitIndex) {
    void *field84;
    s32 field1B40C;
    void *table;
    u8 *stateBits;
    s32 mask;
    s32 i;

    field84 = world->secondaryLevels;
    field1B40C = world->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field84, 0), field1B40C), 0);
    SetN64_GetPackSection(table, 0);
    func_8028FDF8_de((s32) table, 1);
    stateBits = (u8 *) SetN64_GetPackSection(table, 1);
    mask = 1 << (bitIndex & 7);
    i = bitIndex;
    if (i < 0) {
        i += 7;
    }
    return (stateBits[i >> 3] & mask) != 0;
}
