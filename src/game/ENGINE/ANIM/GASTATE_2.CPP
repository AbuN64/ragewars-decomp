#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/802609CC.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/LOCALDECODERANGE.H"
#include "SCENE/802508E0_7.H"
#include "RENDER_4/8028FD2C_6.H"

typedef struct Shared_func_80261EB8_S1 SharedRecAt10V1;
typedef struct Shared_func_80261EB8_S2 SharedRecAt20;
typedef StridedTable ObjRecV1;

void System_PrepareAnimationFrames(SharedRecAt10V1 *state, SharedRecAt20 *frames) {
    f32 frameScale;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 framePosition;
    f32 frameCount;
    f32 var_f0;
    s32 **temp_a0;
    s32 *resource;
    s32 *channels;
    s32 temp_a0_2;
    s32 temp_f3;
    s32 temp_f3_2;
    s32 temp_f3_3;
    s32 temp_f3_4;
    s32 temp_f3_5;
    s32 temp_f3_6;
    s32 temp_v1;
    s32 currentFrame;
    s32 loopStart;
    s32 var_v0;
    s32 var_v0_2;
    s32 nextFrame;
    ObjRecV1 *positions;
    StridedTable *section;

    temp_a0 = state->unk10;
    if (temp_a0 == 0) {
        var_v0 = 0;
    } else {
        var_v0 = func_802532F4_de(temp_a0) != 0;
    }
    if (var_v0 != 0) {
        resource = *state->unk10;
        positions = Render_GetPackSection(resource, 1);
        channels = Render_GetPackSection(resource, 5);
        Render_GetPackSection(channels, 0);
        loopStart = state->unkC;
        framePosition = state->unk0;
        frameCount = (f32) state->unk8;
        frames->unk0 = positions->data;
        section = Render_GetPackSection(resource, 2);
        frames->unk4 = section->data;
        frames->unk8 = Render_GetPackSection(channels, 1);
        frameScale = 1.0f;
        frames->unkC = Render_GetPackSection(channels, 2);
        if (framePosition >= 0.0f) {
            var_v0_2 = (s32) framePosition;
            goto block_8;
        }
        temp_f3 = (s32) framePosition;
        var_f0 = (f32) temp_f3;
        if (var_f0 != framePosition) {
            var_v0_2 = temp_f3 - 1;
block_8:
            var_f0 = (f32) var_v0_2;
        }
        frames->unk20 = (f32) (framePosition - var_f0);
        if (loopStart == 0xFFFF) {
            loopStart = 0;
            if (framePosition >= 0.0f) {
                currentFrame = (s32) framePosition;
            } else {
                temp_f3_2 = (s32) framePosition;
                currentFrame = ((f32) temp_f3_2 == framePosition) ? 0 : 1;
                currentFrame = temp_f3_2 - currentFrame;
            }
            if (frameCount <= (f32) currentFrame) {
                currentFrame = 0;
            }
            nextFrame = currentFrame + 1;
            if (frameCount <= (f32) nextFrame) {
                nextFrame = 0;
            }
        } else {
            if (framePosition >= 0.0f) {
                currentFrame = (s32) framePosition;
            } else {
                temp_f3_3 = (s32) framePosition;
                currentFrame = ((f32) temp_f3_3 == framePosition) ? 0 : 1;
                currentFrame = temp_f3_3 - currentFrame;
            }
            if ((frameCount - 1.0f) <= (f32) currentFrame) {
                temp_v1 = state->unkC;
                if (((f32) (u32) temp_v1 * frameScale) <= 0.0f) {
                    currentFrame = (s32) ((f32) (u32) temp_v1 * frameScale);
                } else {
                    currentFrame = ((f32) (s32) ((f32) (u32) temp_v1 * frameScale) == ((f32) (u32) temp_v1 * frameScale)) ? 0 : 1;
                    currentFrame = currentFrame + (s32) ((f32) (u32) temp_v1 * frameScale);
                }
            }
            nextFrame = currentFrame + 1;
            if ((frameCount - 1.0f) <= (f32) nextFrame) {
                temp_a0_2 = state->unkC;
                if (((f32) (u32) temp_a0_2 * frameScale) <= 0.0f) {
                    nextFrame = (s32) ((f32) (u32) temp_a0_2 * frameScale);
                } else {
                    nextFrame = ((f32) (s32) ((f32) (u32) temp_a0_2 * frameScale) == ((f32) (u32) temp_a0_2 * frameScale)) ? 0 : 1;
                    nextFrame = nextFrame + (s32) ((f32) (u32) temp_a0_2 * frameScale);
                }
            }
        }
        frames->unk10 = (s32) (currentFrame * 4);
        frames->unk14 = (s32) (nextFrame * 4);
        if (framePosition >= 0.0f) {
            currentFrame = (s32) framePosition;
        } else {
            temp_f3_4 = (s32) framePosition;
            currentFrame = ((f32) temp_f3_4 == framePosition) ? 0 : 1;
            currentFrame = temp_f3_4 - currentFrame;
        }
        if (frameCount <= (f32) currentFrame) {
            temp_f1 = (f32) loopStart * frameScale;
            if (temp_f1 <= 0.0f) {
                currentFrame = (s32) temp_f1;
                nextFrame = currentFrame + 1;
            } else {
                temp_f3_5 = (s32) temp_f1;
                currentFrame = ((f32) temp_f3_5 == temp_f1) ? 0 : 1;
                currentFrame = currentFrame + temp_f3_5;
                nextFrame = currentFrame + 1;
            }
        } else {
            nextFrame = currentFrame + 1;
        }
        if (frameCount <= (f32) nextFrame) {
            temp_f1_2 = (f32) loopStart * frameScale;
            if (temp_f1_2 <= 0.0f) {
                nextFrame = (s32) temp_f1_2;
                frames->unk18 = currentFrame * 4;
            } else {
                temp_f3_6 = (s32) temp_f1_2;
                nextFrame = ((f32) temp_f3_6 == temp_f1_2) ? 0 : 1;
                nextFrame = nextFrame + temp_f3_6;
                        goto block_75;
            }
        } else {
block_75:
            frames->unk18 = currentFrame * 4;
        }
        frames->unk1C = (s32) (nextFrame * 4);
    }
}
