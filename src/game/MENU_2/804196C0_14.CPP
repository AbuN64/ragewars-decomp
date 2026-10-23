#include "include_asm.h"
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "MENU_2/804196C0_14.H"
#include "SCENE/802508E0_13.H"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3300, an actor kind at D_800E3304 and a handler at D_800E3308: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3300;

extern s32 D_800E3304;

extern Handler802A2B50 D_800E3308;

/* Calls func_802547E4_de with the arguments it was given and returns zero. */

/* func_804196D8_de advances a frame sequence: it adds elapsed time into offset 0x54 and, once that
   exceeds the duration at 0x58, moves the frame index at 0x4C through the -1 terminated array at
   0x48. func_804198CC_de resets the index through here after counting the frames. */


void func_804199DC_de(struct FrameSequence *sequence, s32 frame) {
    sequence->frame = frame;
}

/* Sets how long each frame of a sequence is shown; func_804196D8_de advances the frame once the
   time accumulated at 0x54 exceeds this. func_804198CC_de clears it when it builds the sequence. */


void func_804199E4_de(struct FrameSequence *sequence, s32 duration) {
    sequence->duration = duration;
}

/* Returns a frame sequence's current frame index, which func_804199DC_de sets. */


s32 func_804199EC_de(struct FrameSequence *sequence) {
    return sequence->frame;
}

/* Returns how many frames a sequence holds, counted by func_804198CC_de up to the -1 terminator. */


s32 func_804199F8_de(struct FrameSequence *sequence) {
    return sequence->count;
}

/* Sets how many more times a counted-loop sequence repeats; func_804196D8_de decrements it each
   time the sequence wraps and stops when it reaches zero. func_804198CC_de clears it on creation. */


void func_80419A04_de(struct FrameSequence *sequence, s32 loops) {
    sequence->loops = loops;
}

/* Returns how many more times a counted-loop sequence repeats, which func_80419A04_de sets. */


s32 func_80419A0C_de(struct FrameSequence *sequence) {
    return sequence->loops;
}

/* Sets playback mode bits in a frame sequence; func_804198CC_de sets bit 1 and func_804196D8_de sets
   bit 2 when it reverses a ping-pong sequence. */


void func_80419A18_de(struct FrameSequence *sequence, s32 bits) {
    sequence->flags |= bits;
}

/* Clears playback mode bits in a frame sequence; func_80419A18_de sets them and func_804196D8_de clears
   bit 1 or 2 when it reverses a ping-pong sequence. */


void func_80419A28_de(struct FrameSequence *sequence, s32 bits) {
    sequence->flags &= ~bits;
}

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */


s32 func_80419A3C_de(struct FrameSequence *sequence, s32 bits) {
    return (sequence->flags & bits) != 0;
}

s32 func_80419A4C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3300)) + offset))->field_0 == arg1) {
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


void func_80419ADC_de(s32 unused0, struct Triple unused1) {
}

s32 func_80419AEC_de(void *arg0) {
    func_802547E4_de(arg0);
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
