#include "COMMON/RECORD.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "RESMGR/802A23A4_11.H"
#include "MATH/802A2870.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER_2/8025DE50_5.H"
#include "include_asm.h"
#include "SCENE/802508E0_13.H"

extern s32 Widget_ComputeWidgetBounds(QuadN64EngDrawNumericWidgetChildren *, QuadN64EngDrawNumericWidgetChildren *, void *, Args *);

extern void N64Eng_GetClipBounds(u32 *, u32 *, u32 *, u32 *);

extern s32 Node_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);

extern void Widget_DrawVisibleSiblings(void *, Args);

s32 N64Eng_DispatchNumericWidgetEvent(struct Tree *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800CD9B8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800CD9B8;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800CD9B0)) + offset))->field_0 == arg1) {
                actor_kind = arg0->id;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800CD9B4)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

void N64Eng_DrawNumericWidgetChildren(void *widget, Args args) {
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;

    changed = 0;
    if (Widget_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((((Widget *)widget)->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Node_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Widget_DrawVisibleSiblings(((struct Tree *)widget)->child, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}

extern void N64Eng_SetNumericWidgetValue(void *arg0, s32 arg1);

void N64Eng_DecrementNumericWidget(void *arg0)
{
    RecordN64EngCreateNumericWidget *object = arg0;
  s32 temp_a1;
  s32 temp_v1;
  s32 var_a1;
  if ((object->field_54) == 0)
  {
    temp_a1 = object->field_58;
    if ((object->field_50) < temp_a1)
    {
      var_a1 = temp_a1 - 1;
      goto block_7;
    }
  }
  else
  {
    temp_v1 = object->field_58;
    if (temp_v1 == (object->field_50))
    {
      object->field_58 = object->field_4C;
    }
    else
    {
      object->field_58 = temp_v1 - 1;
    }
    var_a1 = object->field_58;
    block_7:
    N64Eng_SetNumericWidgetValue(object, var_a1);

  }
}

extern unsigned int Smos_GetControlRepeatLimit(void);

void N64Eng_IncrementNumericWidget(void *arg0);

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

s32 N64Eng_HandleNumericDecrement(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 fifth) {
    RecordN64EngCreateNumericWidget *object = arg0;
    s32 temp_s0;

    temp_s0 = XMath_AbsoluteInteger(fifth);
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

/* Counts ticks while the controller state is 0 or 1; after ten, steps the list selection backward (state 0) or forward (state 1). Returns 0. */
s32 TickSelectionRepeat(void *widget) {
    struct CommandListController *cmd = widget;

    switch (cmd->state) {
    case 0:
        if (++cmd->progress > 10) {
            N64Eng_DecrementNumericWidget(cmd);
        }
        break;
    case 1:
        if (++cmd->progress > 10) {
            N64Eng_IncrementNumericWidget(cmd);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 N64Eng_FreeNumericWidget(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

#if defined(VERSION_EU_X) || defined(VERSION_US)
unsigned int func_802A206C_de_padding_A2BCC[1] = {
    0x00000000,
};
#endif
