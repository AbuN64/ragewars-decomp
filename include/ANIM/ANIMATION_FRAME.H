#ifndef ANIM_ANIMATION_FRAME_H
#define ANIM_ANIMATION_FRAME_H
#include "TYPES.H"

/* Published animation descriptor prefix; callers receive a frame pointer. */
struct Shared_AnimFrame {
    u8 kind;
    u8 unknown1;
    u8 shiftS;
    u8 shiftT;
    u8 unk4;
    u8 unk5;
};
typedef struct Shared_AnimInfo {
    s32 count;
    s32 unk4;
    struct Shared_AnimFrame *frame;
} Shared_AnimInfo;
#endif
