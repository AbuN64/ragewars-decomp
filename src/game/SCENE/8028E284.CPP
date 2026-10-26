#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "sdk/SCHED/8028DF6C_2.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"
#include "WORLD/8028E6FC.H"

/* Collects platform actors, records the special actor and selects one of three random states. */



extern LevelActor *D_800F3CD0[],*D_800F3D0C;
extern s32 XPlus_NextRandomInteger(void);
void Scene_CollectSecondarySpecialActors(SceneRecAt140 *scene) {
 s32 count=0,i=9,offset=36;LevelActor *actor=scene->actors;
 D_800F3D0C=0;
 do {*(LevelActor **)((char *)D_800F3CD0+offset)=0;i--;offset-=4;} while(i>=0);
 i=0;
 if(scene->count>0)do {
  if(((struct Def *)actor->definition)->type==3) {if(((struct Def *)actor->definition)->id==0xBD6){if(scene->count)D_800F3D0C=actor;else D_800F3D0C=actor;}}
  else if(((struct Def *)actor->definition)->type==10) {if(actor->type==0x64E)D_800F3CD0[count++]=actor;}
  if(count>=10)return;
  actor++;

 }while(++i<scene->count);
 D_801462C8.counters.m_nFragTagSkin=XPlus_NextRandomInteger()%3;
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a table through the given
   nibble table. */





extern void OnScreen_GetImageEntry(void *table, s32 index, void **out, u8 *tag);

void Scene_RemapFourBitImagePixels(void *unused0, void *table, u8 *remap) {
    s32 i;
    void *data;
    u8 tag;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    i = 0;
    end = -1;
    for (; i < 256; i++) {
        end = -1;
        OnScreen_GetImageEntry(table, i, &data, &tag);
        rows = data == 0;
        if (rows) {
            continue;
        }
        set = data;
        rows = set->rows;
        rows--;
        image = (struct IntPair *)(set + 1);
        while (1) {
            if (rows == end) {
                break;
            }
            columns = set->columns;
            columns--;
            for (; columns != end; columns--) {
                width = image->field_0;
                height = image->field_4;
                count = (u32)(width * height) >> 1;
                pixel = (u8 *)(image + 1);
                while (count--) {
                    hi = *pixel >> 4;
                    lo = *pixel & 0xF;
                    hi = remap[hi];
                    lo = remap[lo];
                    *pixel = (hi << 4) | lo;
                    pixel++;
                }
                image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                image++;
            }
            rows--;
        }
    }
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2910, once the resource has been loaded by func_80285180_de. */





extern u8 D_800D2910[];
extern s32 PpDecom_UnpackResource(void *resource, s32 flags);

void Scene_UnpackImagesWithLowBoost(void *unused0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = PpDecom_UnpackResource(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2910;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            OnScreen_GetImageEntry(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct IntPair *)(set + 1);
            while (1) {
                if (rows == end) {
                    break;
                }
                columns = set->columns;
                columns--;
                for (; columns != end; columns--) {
                    width = image->field_0;
                    height = image->field_4;
                    count = (u32)(width * height) >> 1;
                    pixel = (u8 *)(image + 1);
                    while (count--) {
                        hi = *pixel >> 4;
                        lo = *pixel & 0xF;
                        hi = remap[hi];
                        lo = remap[lo];
                        *pixel = (hi << 4) | lo;
                        pixel++;
                    }
                    image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2920, once the resource has been loaded by func_80285180_de. Adapted from Scene_UnpackImagesWithLowBoost with the nibble table changed to D_800D2920. */





extern u8 D_800D2920[];

void Scene_UnpackImagesWithHighBoost(void *unused0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = PpDecom_UnpackResource(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2920;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            OnScreen_GetImageEntry(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct IntPair *)(set + 1);
            while (1) {
                if (rows == end) {
                    break;
                }
                columns = set->columns;
                columns--;
                for (; columns != end; columns--) {
                    width = image->field_0;
                    height = image->field_4;
                    count = (u32)(width * height) >> 1;
                    pixel = (u8 *)(image + 1);
                    while (count--) {
                        hi = *pixel >> 4;
                        lo = *pixel & 0xF;
                        hi = remap[hi];
                        lo = remap[lo];
                        *pixel = (hi << 4) | lo;
                        pixel++;
                    }
                    image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_8028E78C_CB02C[1] = {
    0x4AC80000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8028E78C_CB02C_us_rev1.c */
const unsigned int D_blob_5ed4fa86953393fbfcea[1] = {
    0x4AC80000,
};
#endif

s32 Scene_TestSectorSectionTwoEntries(Shared_World *arg0)
{
  Shared_World *elem;
  s32 i;
  void *field;
  char *new_var;
  void *ret;
  s32 count;
  count = arg0->sectorCount;
  if (count <= 0)
  {
    return 0;
  }
  i = 0;
  elem = arg0;
  do
  {
    field = arg0->sectors[i].resource;
    ret = SetN64_GetPackSection(*((s32 *) field), 2);
    if ((((struct IntPair *)ret)->field_4) != 0)
    {
      if (arg0 || i)
      {
        return 1;
      }
      else
      {
        return 1;
      }
    }
    count = arg0->sectorCount;
    i += 1;

  }
  while (i < count);
  return 0;
}

/** Return an indexed record from the table at object offset 0xAC. */
void *Scene_GetStridedActorRecord(struct Shared_World *object, int index) {
    char *base = (char *)object->actorRecords;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

extern void GraphU64_SubtractVectors(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);




s32 Scene_TestNearbyActiveActor(struct ObjectRecAt1A4 *arg0, CVector3 *arg1) {
    CVector3 vector;
    f32 magnitude;
    u16 type;

    GraphU64_SubtractVectors(&vector, &arg0->x, arg1);
    magnitude = (vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z);
    if (*arg0->kind != 1) {
        return 0;
    }
    type = arg0->team;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0;
    }
    if (arg0->active == 0) {
        return 0;
    }
    if (arg0->state == 0x3D) {
        return 0;
    }
    return magnitude <= D_800C533C_de;
}

/* Reports whether arg1 is within range of arg0, using its type and state to pick the check. */









s32 Scene_ClassifyNearbySpecialActor(ObjRecAtE4V2 *player, CVector3 *arg1) {
    CVector3 delta;
    u16 type;

    if (player->unk0 == 1 && *player->unk18 == 7) {
        GraphU64_SubtractVectors(&delta, &((Player *)(player))->pos, arg1);
        delta.y = 0;
        if (262144.0f < delta.x * delta.x + delta.z * delta.z) {
            return 0;
        }
        return 0xFF;
    }
    if (*player->unk18 != 1) {
        return 0;
    }
    type = player->unkE4;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0xFF;
    }
    return 0;
}
#if defined(VERSION_EU_X)
unsigned int func_8028E860_de_padding_8F66C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C55F4[3] = {
    0x24E7FFFF, 0x0065102B, 0x50400004,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C5344[3] = {
    0x358637BD, 0x358637BD, 0x358637BD,
};
#endif
