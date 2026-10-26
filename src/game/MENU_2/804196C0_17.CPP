#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "MENU_2/804196C0_17.H"
#include "SCENE/802508E0_13.H"

/* Calls func_80419C84_de on an object, marks it busy at offset 0x44 and copies the low byte of the
   current entry of the word array at 0x4C, selected by the index at 0x74, into offset 0x10 of the
   object at 0x78. */




extern void SmpFlicker_InitFlicker(struct ObjectCode804196C0 *, s32);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3330, an actor kind at D_800E3334 and a handler at D_800E3338: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */

/* Sets the word at offset 0x84 of an object to one. */


void func_80419F18_de(struct StateBlock *object) {
    object->unk84 = 1;
}

/* Copies the byte at offset 0x83 of an object into offset 0x10 of the object at 0x78, and clears
   the pending word at 0x84 that func_80419F18_de sets and SmpFlicker_IsFlickerIdle tests. */




void SmpFlicker_RestoreFlickerValue(struct SourceRecAt84 *source) {
    struct ResourceSmpFlickerCreateFlickerWidget *target = source->target;
    u8 value = source->value;

    source->pending = 0;
    target->value = value;
}

/* Returns one when nothing is pending at offset 0x84 of an object, and otherwise whether the word
   at offset 0x44 is zero; func_80419F18_de sets the pending word and SmpFlicker_RestoreFlickerValue clears it. */


s32 SmpFlicker_IsFlickerIdle(struct ObjectRecAt84 *object) {
    if (object->pending == 0) {
        return 1;
    }
    return object->busy == 0;
}

void SmpFlicker_StartFlicker(struct ObjectCode804196C0 *object, s32 count) {
    SmpFlicker_InitFlicker(object, count);
    object->busy = 1;
    object->target->value = object->entries[object->index];
}

s32 func_80419F9C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3338 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3338;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3330)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3334)) + offset))->field_0;
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

/* Does nothing: an unreferenced empty stub whose only code stores the argument registers a1 to a3
   to their home stack slots. */


void func_8041A02C_de(s32 unused0, struct Triple unused1) {
}

s32 func_8041A03C_de(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}
