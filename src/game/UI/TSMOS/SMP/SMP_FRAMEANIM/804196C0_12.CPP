#include "COMMON/FRUSTUM.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_13.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "MENU_2/804196C0_14.H"
#include "SCENE/802508E0_13.H"

/* Advances a frame sequence after its duration expires, honoring pause, forward/reverse, ping-pong and finite/infinite loop modes, and publishes the selected frame to its target. Reuses the matched FrameSequence contract from SmpFrameAnim_HasSequenceFlags. */
#include "TYPES.H"
#include "MENU/FRAME_SEQUENCE.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */



void SmpFrameAnim_SetSequenceFrame(struct FrameSequence *sequence, s32 frame);
void SmpFrameAnim_AddSequenceFlags(struct FrameSequence *sequence, s32 bits);
void SmpFrameAnim_ClearSequenceFlags(struct FrameSequence *sequence, s32 bits);
s32 SmpFrameAnim_HasSequenceFlags(struct FrameSequence *sequence, s32 bits);
s32 SmpFrameAnim_UpdateFrameSequence(struct FrameSequence *sequence, s32 unused, s32 elapsed) {
    if (SmpFrameAnim_HasSequenceFlags(sequence, 4) == 0) {
        sequence->elapsed += elapsed;
        sequence->target->unk2C = sequence->frames[sequence->frame];
        if (sequence->elapsed > sequence->duration) {
            sequence->elapsed = 0;
            if (SmpFrameAnim_HasSequenceFlags(sequence, 1)) {
                if (sequence->frame < sequence->count - 1) {
                    sequence->frame++;
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 0x10)) {
                    SmpFrameAnim_ClearSequenceFlags(sequence, 1);
                    SmpFrameAnim_AddSequenceFlags(sequence, 2);
                    SmpFrameAnim_SetSequenceFrame(sequence, sequence->count - 2);
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 0x20)) {
                    if (sequence->loops > 0) {
                        sequence->loops--;
                        SmpFrameAnim_SetSequenceFrame(sequence, 0);
                    }
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 8)) {
                    SmpFrameAnim_SetSequenceFrame(sequence, 0);
                }
            } else {
                if (sequence->frame > 0) {
                    sequence->frame--;
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 0x10)) {
                    SmpFrameAnim_ClearSequenceFlags(sequence, 2);
                    SmpFrameAnim_AddSequenceFlags(sequence, 1);
                    SmpFrameAnim_SetSequenceFrame(sequence, 1);
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 0x20)) {
                    if (sequence->loops > 0) {
                        sequence->loops--;
                        SmpFrameAnim_SetSequenceFrame(sequence, sequence->count - 1);
                    }
                } else if (SmpFrameAnim_HasSequenceFlags(sequence, 8)) {
                    SmpFrameAnim_SetSequenceFrame(sequence, sequence->count - 1);
                }
            }
        }
    }
    return 0;
}

/* Creates a frame animation for widget id of the current screen: finds the widget through
   Frontend_FindWidgetByResourceId, allocates and clears a 0x64-byte animation, sets its type fields, widget and
   -1-terminated frame list, counts the frames, initialises its playback state through
   SmpFrameAnim_AddSequenceFlags, SmpFrameAnim_SetSequenceFrame, SmpFrameAnim_SetSequenceDuration and SmpFrameAnim_SetLoopCount, attaches it to the widget through
   Frontend_InsertWidgetBefore and returns it. */






extern Animation *Cache_AllocateMemory(s32 size);




void SmpFrameAnim_SetSequenceDuration(struct FrameSequence *sequence, s32 duration);

void SmpFrameAnim_SetLoopCount(struct FrameSequence *sequence, s32 loops);

extern void Frontend_InsertWidgetBefore(s32 widget, Animation *anim);

void SmpFrameAnim_RegisterFrameAnimClass(void) {
    SmSmngr_RegisterElementHandlers(0xB5F, D_00419A4C, D_00419ADC, 3);
}

Animation *SmpFrameAnim_CreateFrameSequence(s32 id, s32 *frames) {
    s32 widget;
    Animation *anim;

    widget = (s32)Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), (u16)id);
    Frontend_GetScreenData(GetMenuScreenOwner());
    anim = Cache_AllocateMemory(0x64);
    XPlus_FillBytes(anim, 0, 0x64);
    anim->kindB = 0xB5F;
    anim->flags = 8;
    anim->kindA = 0xB5F;
    anim->widget = widget;
    anim->unk54 = 0;
    anim->frames = frames;
    anim->unk5C = 0;
    anim->count = 0;
    while (frames[anim->count] != -1) {
        anim->count++;
    }
    SmpFrameAnim_AddSequenceFlags(anim, 1);
    SmpFrameAnim_SetSequenceFrame(anim, 0);
    SmpFrameAnim_SetSequenceDuration(anim, 0);
    SmpFrameAnim_SetLoopCount(anim, 0);
    Frontend_InsertWidgetBefore(widget, anim);
    return anim;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at g_smpEventHandlerTables, an actor kind at D_800E3304 and a handler at D_800E3308: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */

/* func_804196D8_de advances a frame sequence: it adds elapsed time into offset 0x54 and, once that
   exceeds the duration at 0x58, moves the frame index at 0x4C through the -1 terminated array at
   0x48. SmpFrameAnim_CreateFrameSequence resets the index through here after counting the frames. */


void SmpFrameAnim_SetSequenceFrame(struct FrameSequence *sequence, s32 frame) {
    sequence->frame = frame;
}

/* Sets how long each frame of a sequence is shown; func_804196D8_de advances the frame once the
   time accumulated at 0x54 exceeds this. SmpFrameAnim_CreateFrameSequence clears it when it builds the sequence. */


void SmpFrameAnim_SetSequenceDuration(struct FrameSequence *sequence, s32 duration) {
    sequence->duration = duration;
}

/* Returns a frame sequence's current frame index, which SmpFrameAnim_SetSequenceFrame sets. */


s32 SmpFrameAnim_GetSequenceFrame(struct FrameSequence *sequence) {
    return sequence->frame;
}

/* Returns how many frames a sequence holds, counted by SmpFrameAnim_CreateFrameSequence up to the -1 terminator. */


s32 SmpFrameAnim_GetFrameCount(struct FrameSequence *sequence) {
    return sequence->count;
}

/* Sets how many more times a counted-loop sequence repeats; func_804196D8_de decrements it each
   time the sequence wraps and stops when it reaches zero. SmpFrameAnim_CreateFrameSequence clears it on creation. */


void SmpFrameAnim_SetLoopCount(struct FrameSequence *sequence, s32 loops) {
    sequence->loops = loops;
}

/* Returns how many more times a counted-loop sequence repeats, which SmpFrameAnim_SetLoopCount sets. */


s32 SmpFrameAnim_GetLoopCount(struct FrameSequence *sequence) {
    return sequence->loops;
}

/* Sets playback mode bits in a frame sequence; SmpFrameAnim_CreateFrameSequence sets bit 1 and func_804196D8_de sets
   bit 2 when it reverses a ping-pong sequence. */


void SmpFrameAnim_AddSequenceFlags(struct FrameSequence *sequence, s32 bits) {
    sequence->flags |= bits;
}

/* Clears playback mode bits in a frame sequence; SmpFrameAnim_AddSequenceFlags sets them and func_804196D8_de clears
   bit 1 or 2 when it reverses a ping-pong sequence. */


void SmpFrameAnim_ClearSequenceFlags(struct FrameSequence *sequence, s32 bits) {
    sequence->flags &= ~bits;
}

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */


s32 SmpFrameAnim_HasSequenceFlags(struct FrameSequence *sequence, s32 bits) {
    return (sequence->flags & bits) != 0;
}

s32 SmpFrameAnim_DispatchEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3308 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3308;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&g_smpEventHandlerTables)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3304)) + offset))->field_0;
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


void SmpFrameAnim_IgnoreEvent(s32 unused0, struct Triple unused1) {
}

s32 SmpFrameAnim_DestroyController(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

#if defined(VERSION_US)
unsigned int func_80419B8C_us_padding_17DB8C[1] = {
    0x554E445F,
};
#endif

#if defined(VERSION_EU)
unsigned int func_80419F4C_eu_padding_18FF4C[1] = {
    0x02221023,
};
#endif
