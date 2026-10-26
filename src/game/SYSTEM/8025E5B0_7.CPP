#include "COMMON/STREAM.H"
#include "COMMON/LONE/D_8010AC80.H"
#include "GAME_2/8025E520.H"
#include "TYPES.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"

/* Resource blocks store a count and relative offsets; unused entries carry
 * the resource builder's DEADBEEF sentinel. */
typedef struct ResourceBlock { s32 count; s32 offset[1]; } ResourceBlock;

typedef struct ResourceHandle { ResourceBlock *block; s32 bytes; } ResourceHandle;

typedef struct MotionHeader {
    s32 channels;
    s32 frames;
    s32 flags;
    f32 duration;
    s32 rotations;
    s32 translations;
    f32 frameCount;
    f32 frameStep;
} MotionHeader;

extern s32 Render_UnpackResource(void **, s32);

extern s32 Render_GetSizedPackSection(s32, s32, s32 *);


extern void *Scene_AllocResourceBlock(s32, void *, s32);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);


extern void Scene_ReplaceResourceBlock(s32, void **, void *);

extern s32 System_ExpandAnimationTracks(void *, void *, s32, s32, s32, s32);

extern const f32 D_800C411C_de, D_800C4120_de, D_800C4124_de;

extern const f32 D_800C4128_de, D_800C412C_de;

extern f32 D_8010AC70, D_8010AC7C;

#include "COMMON/STREAM.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);
extern s32 D_8010AC74, D_8010AC78;

static inline void resource_begin(ResourceBlock *block, s32 count, s32 bytes) {
    s32 i = 1;
    s32 *entry = &block->offset[0];
    block->count = count;
    block->offset[0] = bytes;
    do {
        entry[1] = 0xDEADBEEF;
        i++;
        entry++;
    } while (i <= count);
}

static inline char *resource_reserve(ResourceBlock *block, s32 bytes) {
    s32 count = block->count;
    s32 i = 0;
    s32 *entry;
    s32 sentinel;
    if (count >= 0) {
        sentinel = 0xDEADBEEF;
        entry = &block->count;
loop:
        if (entry[1] != sentinel) {
            i++;
            entry++;
            if (count >= i) goto loop;
        }
    }
    i--;
    block->offset[i+1] = block->offset[i] + bytes;
    return (char *)block + block->offset[i];
}

static inline void resource_copy(ResourceBlock *block, void *from, s32 bytes) {
    char *destination = resource_reserve(block, bytes);
    if (from != 0) func_802BD3A0_de(destination, from, bytes);
}

static inline s32 motion_storage(s32 channels, s32 frames) {
    s32 data = channels * 16;
    s32 offsets = (channels * 4 + 15) & ~7;
    return data * frames + offsets;
}

/* Reads a packed cubic segment and computes its scaled polynomial coefficients. */



/* Rebuild the resource motion blocks, then replace the original handle. */
void func_8025F56C_de(s32 unused, ResourceHandle **handle) {
    s32 bytes0, bytes1, bytes2, bytes3, bytes4, bytes5, bytes6;
    s32 fetchedRotationBytes, fetchedTranslationBytes;
    ResourceBlock *source;
    void *section0, *section1, *section2, *section3, *section4;
    s32 rotationBytes, translationBytes;
    void *section6;
    ResourceBlock *motion;
    MotionHeader *header;
    ResourceHandle *output;
    ResourceBlock *result;
    ResourceBlock *newMotion;
    MotionHeader *newHeader;
    void *rotations, *translations, *newRotations, *newTranslations;
    s32 sourceBytes;
    s32 sourceFrames;
    s32 motionBytes;
    s32 success;
    f32 count;

    if (Render_UnpackResource((void **)handle, 1)) {
        source = (*handle)->block;
        sourceBytes = (*handle)->bytes;
        section0 = (void *)Render_GetSizedPackSection((s32)source, 0, &bytes0);
        section1 = (void *)Render_GetSizedPackSection((s32)source, 1, &bytes1);
        section2 = (void *)Render_GetSizedPackSection((s32)source, 2, &bytes2);
        section3 = (void *)Render_GetSizedPackSection((s32)source, 3, &bytes3);
        section4 = (void *)Render_GetSizedPackSection((s32)source, 4, &bytes4);
        motion = (ResourceBlock *)Render_GetSizedPackSection((s32)source, 5, &bytes5);
        header = (MotionHeader *)Render_GetPackSection((s32 *)motion, 0);
        Render_GetSizedPackSection((s32)motion, 1, &fetchedRotationBytes);
        Render_GetSizedPackSection((s32)motion, 2, &fetchedTranslationBytes);
        section6 = (void *)Render_GetSizedPackSection((s32)source, 6, &bytes6);
        Render_GetPackSection(section3, 0);
        sourceFrames = header->frames;
        D_8010AC84 = sourceFrames;
        D_8010AC88 = sourceFrames;
        header->frameCount = (f32)sourceFrames;
        header->frameStep = D_800C411C_de;
        if (sourceFrames >= 2) {
            count = (f32)(sourceFrames - 1);
            header->frameStep = count / count;
        }
        rotationBytes = motion_storage(header->translations, D_8010AC88);
        translationBytes = motion_storage(header->rotations, D_8010AC88);
        motionBytes = translationBytes + rotationBytes + 0x38;
        output = Scene_AllocResourceBlock(0, handle, sourceBytes - bytes5 + motionBytes + bytes6);
        if (output != 0) {
            result = output->block;
            resource_begin(result, 7, 0x28);
            resource_copy(result, section0, bytes0);
            resource_copy(result, section1, bytes1);
            resource_copy(result, section2, bytes2);
            resource_copy(result, section3, bytes3);
            resource_copy(result, section4, bytes4);
            newMotion = (ResourceBlock *)resource_reserve(result, motionBytes);
            resource_begin(newMotion, 3, 0x18);
            resource_copy(newMotion, header, 0x20);
            resource_reserve(newMotion, rotationBytes);
            resource_reserve(newMotion, translationBytes);
            resource_copy(result, section6, bytes6);
            newHeader = (MotionHeader *)Render_GetPackSection((s32 *)motion, 0);
            rotations = Render_GetPackSection((s32 *)motion, 1);
            translations = Render_GetPackSection((s32 *)motion, 2);
            newRotations = Render_GetPackSection((s32 *)newMotion, 1);
            newTranslations = Render_GetPackSection((s32 *)newMotion, 2);
            D_8010AC78 = 1;
            D_8010AC74 = 0;
            D_8010AC7C = D_800C4120_de;
            D_8010AC80 = D_800C4124_de;
            D_8010AC70 = newHeader->duration;
            if (System_ExpandAnimationTracks(rotations, newRotations, newHeader->translations, 3, newHeader->channels, newHeader->flags) == 0) {
                success = 0;
            } else {
                D_8010AC78 = 0;
                D_8010AC74 = 1;
                D_8010AC7C = D_800C4128_de;
                D_8010AC80 = D_800C412C_de;
                D_8010AC70 = newHeader->duration;
                success = System_ExpandAnimationTracks(translations, newTranslations, newHeader->rotations, 4, newHeader->channels, newHeader->flags) != 0;
            }
            if (success == 0) {
                Scene_ReleaseResource(0, output);
                Scene_ReplaceResourceBlock(0, (void **)handle, 0);
            } else {
                goto replace_output;
            }
        } else {
replace_output:
            Scene_ReplaceResourceBlock(0, (void **)handle, output);
        }
    }
}

void func_8025FD74_de(Curve *arg0)
{
  s32 sp10;
  int new_var;
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f4;
  f32 temp_f5;
  f32 temp_f6;
  f32 temp_f7;
  f32 var_f1;
  f32 var_f3;
  f64 var_f2;
  s32 temp_a2;
  s32 temp_lo;
  s32 temp_s3;
  s32 temp_s0;
  s32 temp_s1;
  s32 temp_s2;
  u32 temp_s5;
  s32 temp_v0;
  temp_s3 = arg0->unk0;
  temp_lo = arg0->unk28 * ((temp_s3 * 4) + 6);
  sp10 = arg0->unkC + temp_lo;
  temp_s5 = func_802607B8_de(&sp10, 6);
  temp_s1 = func_802607B8_de(&sp10, temp_s3);
  temp_s0 = func_802607B8_de(&sp10, temp_s3);
  temp_s2 = func_802607B8_de(&sp10, temp_s3);
  temp_v0 = func_802607B8_de(&sp10, temp_s3);
  temp_f6 = (f32) temp_s1;
  new_var=temp_s1*0x15;
  temp_a2 = temp_s0 << 5;
  temp_f5 = (f32) (((temp_a2 - new_var) - (temp_s2 * 0xC)) + temp_v0);
  temp_f5 *= 0.33333334f;
  temp_f7 = (f32) ((((temp_s1 * 0xE) - temp_a2) + (temp_s2 * 0x14)) - (temp_v0 * 2));
  new_var = temp_s1 * 0x18;
  temp_f4 = (f32) ((((temp_s0 << 6) - new_var) - (temp_s2 * 0x30)) + (temp_v0 * 8));
  temp_f4 *= 0.33333334f;
  if (temp_s3 != 0)
  {
    var_f3 = arg0->unk8 / ((f32) ((1 << temp_s3) - 1));
  }
  else
  {
    temp_f0 = arg0->unk8 * 0.5f;
    arg0->unk8 = 0.0f;
    var_f3 = arg0->unk8;
    arg0->unk4 = (f32) (arg0->unk4 + temp_f0);
  }
  temp_f6 *= var_f3;
  if (temp_s5 >= 2U)
  {
    var_f2 = (f64) temp_s5;
    var_f1 = 1.0f / (((f32) var_f2) - 1.0f);
  }
  else
  {
    var_f1 = 1.0f;
  }
  temp_f0_2 = var_f1 * var_f3;
  temp_f5 *= temp_f0_2;
  temp_f0_2 *= var_f1;
  temp_f7 *= temp_f0_2;
  temp_f0_2 *= var_f1;
  temp_f6 += arg0->unk4;
  temp_f4 *= temp_f0_2;
  arg0->unk20 = temp_s5;
  arg0->unk14 = temp_f5;
  arg0->unk10 = temp_f6;
  arg0->unk18 = temp_f7;
  arg0->unk1C = temp_f4;
}
