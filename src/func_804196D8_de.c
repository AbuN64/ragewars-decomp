/* Advances a frame sequence after its duration expires, honoring pause, forward/reverse, ping-pong and finite/infinite loop modes, and publishes the selected frame to its target. Reuses the matched FrameSequence contract from func_80419A3C_de. */
#include "types.h"

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */
struct FrameTarget { char pad[0x2C]; s32 frame; };
struct FrameSequence {
    char pad0[0x44];
    struct FrameTarget *target;  /* 0x44: its word at 0x2C receives the current frame value */
    s32 *frames;   /* 0x48: terminated by -1 */
    s32 frame;     /* 0x4C: index of the current frame */
    s32 count;     /* 0x50: frames before the terminator */
    s32 elapsed;   /* 0x54: time accumulated on the current frame */
    s32 duration;  /* 0x58: time each frame is shown */
    s32 flags;     /* 0x5C: playback mode bits func_804196D8_de tests */
    s32 loops;     /* 0x60: repetitions left when looping is counted */
};

extern void func_804199DC_de(struct FrameSequence *, s32);
extern void func_80419A18_de(struct FrameSequence *, s32);
extern void func_80419A28_de(struct FrameSequence *, s32);
extern s32 func_80419A3C_de(struct FrameSequence *, s32);
s32 func_804196D8_de(struct FrameSequence *sequence, s32 unused, s32 elapsed) {
    if (func_80419A3C_de(sequence, 4) == 0) {
        sequence->elapsed += elapsed;
        sequence->target->frame = sequence->frames[sequence->frame];
        if (sequence->elapsed > sequence->duration) {
            sequence->elapsed = 0;
            if (func_80419A3C_de(sequence, 1)) {
                if (sequence->frame < sequence->count - 1) {
                    sequence->frame++;
                } else if (func_80419A3C_de(sequence, 0x10)) {
                    func_80419A28_de(sequence, 1);
                    func_80419A18_de(sequence, 2);
                    func_804199DC_de(sequence, sequence->count - 2);
                } else if (func_80419A3C_de(sequence, 0x20)) {
                    if (sequence->loops > 0) {
                        sequence->loops--;
                        func_804199DC_de(sequence, 0);
                    }
                } else if (func_80419A3C_de(sequence, 8)) {
                    func_804199DC_de(sequence, 0);
                }
            } else {
                if (sequence->frame > 0) {
                    sequence->frame--;
                } else if (func_80419A3C_de(sequence, 0x10)) {
                    func_80419A28_de(sequence, 2);
                    func_80419A18_de(sequence, 1);
                    func_804199DC_de(sequence, 1);
                } else if (func_80419A3C_de(sequence, 0x20)) {
                    if (sequence->loops > 0) {
                        sequence->loops--;
                        func_804199DC_de(sequence, sequence->count - 1);
                    }
                } else if (func_80419A3C_de(sequence, 8)) {
                    func_804199DC_de(sequence, sequence->count - 1);
                }
            }
        }
    }
    return 0;
}
