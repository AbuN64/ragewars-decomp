
/* Advances a frame sequence after its duration expires, honoring pause, forward/reverse, ping-pong and finite/infinite loop modes, and publishes the selected frame to its target. Reuses the matched FrameSequence contract from SmpFrameAnim_HasSequenceFlags. */
#include "TYPES.H"
#include "MENU/FRAME_SEQUENCE.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */



extern void SmpFrameAnim_SetSequenceFrame(struct FrameSequence *, s32);
extern void SmpFrameAnim_AddSequenceFlags(struct FrameSequence *, s32);
extern void SmpFrameAnim_ClearSequenceFlags(struct FrameSequence *, s32);
extern s32 SmpFrameAnim_HasSequenceFlags(struct FrameSequence *, s32);
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
