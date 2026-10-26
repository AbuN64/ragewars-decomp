#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "MATH/802A2870.H"
#include "RESMGR/802A2230_4.H"
#include "RENDER_2/8025DE50_5.H"

extern void N64Eng_SetNumericWidgetValue(void *arg0, s32 arg1);

extern unsigned int Smos_GetControlRepeatLimit(void);

extern void N64Eng_IncrementNumericWidget(void *arg0);


void N64Eng_IncrementNumericWidget(void *arg0)
{
    RecordN64EngCreateNumericWidget *object = arg0;
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
    N64Eng_SetNumericWidgetValue(object, var_a1);
  }
}

/** Reset the object state and mark non-type-eight linked records. */
int N64Eng_SetLinkedCommand100(struct CommandListController *object) {
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

int N64Eng_SetLinkedCommand200(struct CommandListController *object) {
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

s32 N64Eng_SetLinkedCommand100WithSound(struct CommandListController *commandListController) {
    struct LinkedCommandEntry *p;

    commandListController->state = 2;
    commandListController->progress = 0;
    SoundElement_PlayFlatSound(0xE74);
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

s32 N64Eng_HandleNumericIncrement(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    RecordN64EngCreateNumericWidget *object = arg0;
    s32 temp_s0;

    temp_s0 = XMath_AbsoluteInteger(arg4);
    if (temp_s0 < (s32)Smos_GetControlRepeatLimit()) {
        object->field_5C = 2;
        object->field_48 = 0;
    }
    if (arg3 != 1) {
        return 0;
    }
    object->field_5C = arg3;
    N64Eng_IncrementNumericWidget(object);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}

s32 N64Eng_HandleNumericDecrement(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    RecordN64EngCreateNumericWidget *object = arg0;
    s32 temp_s0;

    temp_s0 = XMath_AbsoluteInteger(arg4);
    if (temp_s0 < (s32)Smos_GetControlRepeatLimit()) {
        object->field_5C = 2;
        object->field_48 = 0;
    }
    if (arg3 != 1) {
        return 0;
    }
    object->field_5C = 0;
    N64Eng_DecrementNumericWidget(object);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}

/** Apply state two for event class three when the subcode is six or seven. */
int N64Eng_CancelSelectionRepeat(void *object, int unused, unsigned int event, int subcode) {
    struct CommandListController *controller = object;
    if ((event >> 16) == 3 && subcode < 8 && subcode >= 6) {
        controller->state = 2;
        controller->progress = 0;
    }
    return 0;
}
