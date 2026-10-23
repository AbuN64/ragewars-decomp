#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "MATH/802A2870.H"
#include "RESMGR/802A2230_4.H"
#include "RENDER_2/8025DE50_5.H"

extern void func_802A1B24_de(void *arg0, s32 arg1);

extern unsigned int func_80299B4C_de(void);

extern void func_802A1D7C_de(void *arg0);

extern void func_802A1D14_de(void *arg0);

void func_802A1D7C_de(void *arg0)
{
    Record_func_802A1990_de *object = arg0;
  s32 temp_a1;
  s32 temp_v1;
  s32 var_a1;
  if ((object->field_54) == 0)
  {
    temp_a1 = object->field_58;
    if (temp_a1 < (object->field_4C))
    {
      var_a1 = temp_a1 + 1;
      goto block_7;
    }
  }
  else
  {
    temp_v1 = object->field_58;
    if (temp_v1 == (object->field_4C))
    {
      object->field_58 = object->field_50;
    }
    else
    {
      object->field_58 = temp_v1 + 1;
    }
    var_a1 = object->field_58;
    block_7:
    func_802A1B24_de(object, var_a1);
  }
}

/** Reset the object state and mark non-type-eight linked records. */
int func_802A1DE4_de(struct CommandListController *object) {
    struct LinkedCommandEntry *record = object->entries;
    object->state = 2;
    object->progress = 0;
    while (record != 0) {
        if (record->kind != 8) {
            record->command = 100;
        }
        record = record->next;
    }
    return 0;
}

int func_802A1E20_de(struct CommandListController *object) {
    struct LinkedCommandEntry *record = object->entries;
    object->state = 2;
    object->progress = 0;
    while (record != 0) {
        if (record->kind != 8) {
            record->command = 200;
        }
        record = record->next;
    }
    return 0;
}

s32 func_802A1E5C_de(struct CommandListController *commandListController) {
    struct LinkedCommandEntry *p;

    commandListController->state = 2;
    commandListController->progress = 0;
    func_8025DF34_de(0xE74);
    p = commandListController->entries;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->command = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}

s32 func_802A1EC0_de(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    Record_func_802A1990_de *object = arg0;
    s32 temp_s0;

    temp_s0 = func_8029DB58_de(arg4);
    if (temp_s0 < (s32)func_80299B4C_de()) {
        object->field_5C = 2;
        object->field_48 = 0;
    }
    if (arg3 != 1) {
        return 0;
    }
    object->field_5C = arg3;
    func_802A1D7C_de(object);
    func_8025DF34_de(0xE81);
    return 0;
}

s32 func_802A1F3C_de(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    Record_func_802A1990_de *object = arg0;
    s32 temp_s0;

    temp_s0 = func_8029DB58_de(arg4);
    if (temp_s0 < (s32)func_80299B4C_de()) {
        object->field_5C = 2;
        object->field_48 = 0;
    }
    if (arg3 != 1) {
        return 0;
    }
    object->field_5C = 0;
    func_802A1D14_de(object);
    func_8025DF34_de(0xE81);
    return 0;
}

/** Apply state two for event class three when the subcode is six or seven. */
int func_802A1FB8_de(void *object, int unused, unsigned int event, int subcode) {
    struct CommandListController *controller = object;
    if ((event >> 16) == 3 && subcode < 8 && subcode >= 6) {
        controller->state = 2;
        controller->progress = 0;
    }
    return 0;
}
