#include "SOUND/TRIPLERECAT8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SOUND/8022C894.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "SOUND/8024E130_4.H"
extern struct func_8022CA04_S3 *func_8028B2F8_de(Shared_World *, void *);

/* Returns the float at offset 0x20 of the entry func_8028B2F8_de finds in D_8011FE88 for an object's
   key at 0x14, when the key's flag halfword at 2 has bit 0 set; zero otherwise. */









void func_8024E79C_de(void *arg0, Triple t, void *arg4, s32 *arg5, s32 arg6, s32 arg7) {
    char unused[0x150];
    Triple *output = arg4;
    *output = t;
    *arg5 = ((LevelActor *)arg0)->model;
}

int func_8024E7DC_de(void *arg0) {
    int temp_a1 = ((LevelActor *)arg0)->model;
    int var_v0 = 0;
    if (temp_a1 != 0) {
        var_v0 = (int)func_8028B2F8_de(&D_8011FE88, (void *)temp_a1);
    }
    return var_v0;
}

f32 func_8024E80C_de(struct Object_func_8024E80C_de *object) {
    struct func_8022CA04_S3 *entry;

    if (object->key != 0 && (object->key->flags & 1)) {
        entry = func_8028B2F8_de(&D_8011FE88, object->key);
        if (entry != 0) {
            return entry->unk20;
        }
    }
    return 0.0f;
}

/** Return floating-point zero to callers at VRAM 0x8024E854. */
float func_8024E864_de(void) {
    return 0.0f;
}

f32 func_8024E870_de(void *arg0) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f1;
    void *temp_a1;
    temp_a1 = (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_14);
    var_f0 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->cur))->unk4);
    temp_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->prev))->unk4);
    if (!(temp_f1 <= var_f0)) {
        var_f0 = temp_f1;
    }
    var_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->next))->unk4);
    if (!(var_f0 <= var_f1)) {
        var_f1 = var_f0;
    }
    return var_f1 - (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_C);
}

f32 func_8024E8B8_de(void *arg0) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f1;
    void *temp_a1;
    temp_a1 = (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_14);
    var_f0 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->cur))->unk4);
    temp_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->prev))->unk4);
    if (!(var_f0 <= temp_f1)) {
        var_f0 = temp_f1;
    }
    var_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75 *) ((s8 *) temp_a1))->next))->unk4);
    if (!(var_f1 <= var_f0)) {
        var_f1 = var_f0;
    }
    return (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_C) - var_f1;
}

s32 func_8024E900_de(void *arg0)
{
    LevelActor *actor = arg0;
  int new_var;
  new_var = 1;
  if ((actor->kind) != 1)
  {
    if (new_var)
    {
      return 0;
    }
  }
  return (actor->flags) & 1;
}
