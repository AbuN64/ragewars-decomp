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

char *func_8028AFEC_de(void *arg0, s32 arg1) {
    return func_8028FDB4_de((((struct ObjectLinks74 *) ((s8 *) arg0))->unk_70), arg1);
}

/** Return an indexed record from the table at object offset 0xA0. */
void *func_8028B00C_de(struct Shared_World *object, int index) {
    char *base = (char *)object->records;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

/* Draws a scene's object list inside a func_8026D980_de and func_8026D9D0_de pass: writes four G_MOVEWORD commands setting the words at 4, 0xC, 0x14 and 0x1C to 5, 5, 0xFFFB and 0xFFFB, then draws each object through func_80249E28_de unless its flag 4 is set, in which case it is deferred to the scene's 64-entry late list. */






extern Gfx *D_80110634;


extern void func_80249E28_de(LevelActor *object, void *camera);

void func_8028B028_de(SceneRecAt10C0 *scene, void *camera) {
    LevelActor *object;
    s32 count;
    s32 i;
    s32 late;
    LevelActor **objects;

    func_8026D980_de();
    count = scene->count;
    gSPMoveWord(D_80110634++, G_MW_CLIP, 4, 5);
    gSPMoveWord(D_80110634++, G_MW_CLIP, 12, 5);
    gSPMoveWord(D_80110634++, G_MW_CLIP, 20, 0xFFFB);
    gSPMoveWord(D_80110634++, G_MW_CLIP, 28, 0xFFFB);
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
    func_8026D9D0_de();
}

extern Gfx *D_80110634;

extern void Particle_DrawRenderList(s32 arg0, s32 arg1);


void func_8028B160_de(s32 arg0, s32 arg1) {
    Gfx *cmd;

    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 4, 1);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 12, 1);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 20, 0xFFFF);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 28, 0xFFFF);
    func_8026D980_de();
    Particle_DrawRenderList(arg0 + 0x1B08, arg1);
    func_8026D9D0_de();
}

s32 func_8028B21C_de(struct Shared_World *arg0, s32 arg1)
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

int func_8028B25C_de(void *arg0, int arg1) {
    unsigned short *base = (unsigned short *)((char *)((struct Shared_World *)(arg0))->modelIds + 8);
    return base[arg1];
}

/* Changes an object's model when the requested model id is present in the resource bank, then rebuilds its model data. */



extern void func_80246BE8_de(Object_func_8028B274_de *,s32,s32,s32);
static inline s32 find(TableRecAt8 *table,u16 id) {
 s32 index=0,count; u16 *entry;entry=table->entries;count=table->count;
 if(count>0) { do {if(*entry==id) return index; index++;entry++;} while(index<count); }
 return -1;
}
void func_8028B274_de(BankRecAt94 *arg0,Object_func_8028B274_de *arg1,s32 arg2,s32 arg3) {
 s32 index=0;
 if(arg1->id!=arg2) {
 index=find(arg0->table,arg2);
 if(index!=-1){arg1->index=index;arg1->id=arg2;func_80246BE8_de(arg1,arg0->field54,arg0->field24,arg3);}
 }
}


void *func_8028B2F8_de(Shared_World *arg0, u16 *arg1) {
    s32 base;
    s32 idx;

    if (arg1 == 0) {
        return 0;
    }
    base = ((char *)func_8028FDB4_de(arg0->modelSections, 0)) + 8;
    idx = *arg1;
    return (void *)(base + idx * 0x64);
}


u32 func_8028B350_de(Shared_World *arg0, s32 arg1) {
    s32 offset;
    s32 result;

    if (arg1 == 0) {
        return -1;
    }
    offset = ((char *)func_8028FDB4_de(arg0->modelSections, 2)) + 8;
    result = arg1 - offset;
    return (u32)result >> 5;
}







s32 func_8028B394_de(void *arg0, s32 arg1) {
    s32 raw;
    s32 base;

    raw = func_8028FDB4_de(((Shared_World *)arg0)->modelSections, 2);
    base = raw + 8;
    if (arg1 < 0 || arg1 >= ((StridedTable *)raw)->count) {
        return 0;
    }
    return base + (arg1 << 5);
}

extern void func_8028FDF8_de(s32 arg0, s32 arg1);




void func_8028B3E4_de(struct Shared_World *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(arg0->secondaryLevels, 0), arg1), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base1 = (u8 *) func_8028FDB4_de(temp_v0, 1);
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




void func_8028B4D0_de(struct Shared_World *arg0, s32 arg1, s32 arg2) {
    void *field84;
    s32 field1B40C;
    void *temp_v0;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    field84 = arg0->secondaryLevels;
    field1B40C = arg0->level;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field84, 0), field1B40C), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    base1 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    base2 = base1;
    mask = 1 << (arg1 & 7);
    if (arg2 != 0) {
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




s32 func_8028B5C0_de(struct Shared_World *arg0, s32 arg1) {
    void *field84;
    s32 field1B40C;
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    field84 = arg0->secondaryLevels;
    field1B40C = arg0->level;
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(field84, 0), field1B40C), 0);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32) temp_v0, 1);
    temp_a0 = (u8 *) func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg1 & 7);
    i = arg1;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}
