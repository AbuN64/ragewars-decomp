#include "shared/world.h"
#include "span_1000/code_8028B64C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"

/* Collects platform actors, records the special actor and selects one of three random states. */



extern Actor_func_8028E284_de *D_800F3CD0[],*D_800F3D0C;
extern s32 D_80142850;
extern s32 func_802A01E8_de(void);
void func_8028E284_de(SceneRecAt140 *scene) {
 s32 count=0,i=9,offset=36;Actor_func_8028E284_de *actor=scene->actors;
 D_800F3D0C=0;
 do {*(Actor_func_8028E284_de **)((char *)D_800F3CD0+offset)=0;i--;offset-=4;} while(i>=0);
 i=0;
 if(scene->count>0)do {
  if(actor->def->type==3) {if(actor->def->id==0xBD6){if(scene->count)D_800F3D0C=actor;else D_800F3D0C=actor;}}
  else if(actor->def->type==10) {if(actor->id==0x64E)D_800F3CD0[count++]=actor;}
  if(count>=10)return;
  actor++;

 }while(++i<scene->count);
 D_80142850=func_802A01E8_de()%3;
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a table through the given
   nibble table. */





extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E390_de(void *arg0, void *table, u8 *remap) {
    s32 i;
    void *data;
    u8 tag;
    ImageSet *set;
    struct Shape_func_802764D4_de_2 *image;
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
        func_802AA8EC_de(table, i, &data, &tag);
        rows = data == 0;
        if (rows) {
            continue;
        }
        set = data;
        rows = set->rows;
        rows--;
        image = (struct Shape_func_802764D4_de_2 *)(set + 1);
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
                image = (struct Shape_func_802764D4_de_2 *)((u8 *)image + ((u32)(width * height) >> 1));
                image++;
            }
            rows--;
        }
    }
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2910, once the resource has been loaded by func_80285180_de. */





extern u8 D_800D2910[];
extern s32 func_80285180_de(void *resource, s32 flags);
extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E4A4_de(void *arg0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct Shape_func_802764D4_de_2 *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = func_80285180_de(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2910;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            func_802AA8EC_de(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct Shape_func_802764D4_de_2 *)(set + 1);
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
                    image = (struct Shape_func_802764D4_de_2 *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2920, once the resource has been loaded by func_80285180_de. Adapted from func_8028E4A4_de with the nibble table changed to D_800D2920. */





extern u8 D_800D2920[];
extern s32 func_80285180_de(void *resource, s32 flags);
extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E5D0_de(void *arg0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct Shape_func_802764D4_de_2 *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = func_80285180_de(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2920;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            func_802AA8EC_de(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct Shape_func_802764D4_de_2 *)(set + 1);
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
                    image = (struct Shape_func_802764D4_de_2 *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}

extern char *func_8028FDB4_de(s32 *, s32);







s32 func_8028E6FC_de(void *arg0)
{
  void *elem;
  s32 i;
  void *field;
  char *new_var;
  void *ret;
  s32 count;
  count = ((Owner_func_8028C6D4_de *)arg0)->count;
  if (count <= 0)
  {
    return 0;
  }
  i = 0;
  elem = arg0;
  do
  {
    field = ((Owner_func_8028C6D4_de *)arg0)->tracks[i].nodes;
    ret = func_8028FDB4_de(*((s32 *) field), 2);
    if ((((s32 *)ret)[1]) != 0)
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
    count = ((Owner_func_8028C6D4_de *)arg0)->count;
    i += 1;

  }
  while (i < count);
  return 0;
}

/** Return an indexed record from the table at object offset 0xAC. */
void *func_8028E770_de(void *object, int index) {
    char *base = (char *)((struct Shared_World *)(object))->actorRecords;
    int stride = *(int *)base;
    return base + (index * stride + 8);
}

extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);




s32 func_8028E78C_de(void *arg0, Vec3 *arg1) {
    Vec3 sp10;
    f32 magnitude;
    u16 type;

    func_80271F68_de(&sp10, &((struct ObjectRecAt1A4 *)(arg0))->x, arg1);
    magnitude = (sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z);
    if (*((struct ObjectRecAt1A4 *)(arg0))->kind != 1) {
        return 0;
    }
    type = ((struct ObjectRecAt1A4 *)(arg0))->team;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0;
    }
    if (((struct ObjectRecAt1A4 *)(arg0))->active == 0) {
        return 0;
    }
    if (((struct ObjectRecAt1A4 *)(arg0))->state == 0x3D) {
        return 0;
    }
    return magnitude <= D_800C533C_de;
}

/* Reports whether arg1 is within range of arg0, using its type and state to pick the check. */





extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);




s32 func_8028E860_de(ObjRecAtE4V2 *arg0, Vec3 *arg1) {
    Vec3 delta;
    u16 type;

    if (arg0->unk0 == 1 && *arg0->unk18 == 7) {
        func_80271F68_de(&delta, &((Player *)(arg0))->pos, arg1);
        delta.y = 0;
        if (262144.0f < delta.x * delta.x + delta.z * delta.z) {
            return 0;
        }
        return 0xFF;
    }
    if (*arg0->unk18 != 1) {
        return 0;
    }
    type = arg0->unkE4;
    if (type == 0x44E || type == 0x453 || type == 0x451 || type == 0x450 ||
        type == 0x454 || type == 0x455 || type == 0x456) {
        return 0xFF;
    }
    return 0;
}
