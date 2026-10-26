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

extern s32 PpDecom_UnpackResource(void **, s32);

extern s32 SetN64_GetSizedPackSection(s32, s32, s32 *);


extern void *Cache_AllocResourceBlock(s32, void *, s32);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);


extern void Cache_ReplaceResourceBlock(s32, void **, void *);

extern s32 PolyTrak_ExpandAnimationTracks(void *, void *, s32, s32, s32, s32);

extern const f32 D_800C411C_de, D_800C4120_de, D_800C4124_de;

extern const f32 D_800C4128_de, D_800C412C_de;

extern f32 D_8010AC70, D_8010AC7C;

#include "COMMON/STREAM.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);
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

    if (PpDecom_UnpackResource((void **)handle, 1)) {
        source = (*handle)->block;
        sourceBytes = (*handle)->bytes;
        section0 = (void *)SetN64_GetSizedPackSection((s32)source, 0, &bytes0);
        section1 = (void *)SetN64_GetSizedPackSection((s32)source, 1, &bytes1);
        section2 = (void *)SetN64_GetSizedPackSection((s32)source, 2, &bytes2);
        section3 = (void *)SetN64_GetSizedPackSection((s32)source, 3, &bytes3);
        section4 = (void *)SetN64_GetSizedPackSection((s32)source, 4, &bytes4);
        motion = (ResourceBlock *)SetN64_GetSizedPackSection((s32)source, 5, &bytes5);
        header = (MotionHeader *)SetN64_GetPackSection((s32 *)motion, 0);
        SetN64_GetSizedPackSection((s32)motion, 1, &fetchedRotationBytes);
        SetN64_GetSizedPackSection((s32)motion, 2, &fetchedTranslationBytes);
        section6 = (void *)SetN64_GetSizedPackSection((s32)source, 6, &bytes6);
        SetN64_GetPackSection(section3, 0);
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
        output = Cache_AllocResourceBlock(0, handle, sourceBytes - bytes5 + motionBytes + bytes6);
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
            newHeader = (MotionHeader *)SetN64_GetPackSection((s32 *)motion, 0);
            rotations = SetN64_GetPackSection((s32 *)motion, 1);
            translations = SetN64_GetPackSection((s32 *)motion, 2);
            newRotations = SetN64_GetPackSection((s32 *)newMotion, 1);
            newTranslations = SetN64_GetPackSection((s32 *)newMotion, 2);
            D_8010AC78 = 1;
            D_8010AC74 = 0;
            D_8010AC7C = D_800C4120_de;
            D_8010AC80 = D_800C4124_de;
            D_8010AC70 = newHeader->duration;
            if (PolyTrak_ExpandAnimationTracks(rotations, newRotations, newHeader->translations, 3, newHeader->channels, newHeader->flags) == 0) {
                success = 0;
            } else {
                D_8010AC78 = 0;
                D_8010AC74 = 1;
                D_8010AC7C = D_800C4128_de;
                D_8010AC80 = D_800C412C_de;
                D_8010AC70 = newHeader->duration;
                success = PolyTrak_ExpandAnimationTracks(translations, newTranslations, newHeader->rotations, 4, newHeader->channels, newHeader->flags) != 0;
            }
            if (success == 0) {
                Cache_ReleaseResource(0, output);
                Cache_ReplaceResourceBlock(0, (void **)handle, 0);
            } else {
                goto replace_output;
            }
        } else {
replace_output:
            Cache_ReplaceResourceBlock(0, (void **)handle, output);
        }
    }
}

void func_8025FD74_de(Curve *compressedCurve)
{
  s32 bitCursor;
  int new_var;
  f32 halfRange;
  f32 coefficientScale;
  f32 temp_f0_3;
  f32 cubicCoefficient;
  f32 linearCoefficient;
  f32 constantCoefficient;
  f32 quadraticCoefficient;
  f32 inverseSampleSpan;
  f32 quantizedValueScale;
  f64 sampleCountDouble;
  s32 secondSampleTimes32;
  s32 segmentBitOffset;
  s32 valueBitWidth;
  s32 secondSample;
  s32 firstSample;
  s32 thirdSample;
  u32 segmentSampleCount;
  s32 fourthSample;
  valueBitWidth = compressedCurve->unk0;
  segmentBitOffset = compressedCurve->unk28 * ((valueBitWidth * 4) + 6);
  bitCursor = compressedCurve->unkC + segmentBitOffset;
  segmentSampleCount = func_802607B8_de(&bitCursor, 6);
  firstSample = func_802607B8_de(&bitCursor, valueBitWidth);
  secondSample = func_802607B8_de(&bitCursor, valueBitWidth);
  thirdSample = func_802607B8_de(&bitCursor, valueBitWidth);
  fourthSample = func_802607B8_de(&bitCursor, valueBitWidth);
  constantCoefficient = (f32) firstSample;
  new_var=firstSample*0x15;
  secondSampleTimes32 = secondSample << 5;
  linearCoefficient = (f32) (((secondSampleTimes32 - new_var) - (thirdSample * 0xC)) + fourthSample);
  linearCoefficient *= 0.33333334f;
  quadraticCoefficient = (f32) ((((firstSample * 0xE) - secondSampleTimes32) + (thirdSample * 0x14)) - (fourthSample * 2));
  new_var = firstSample * 0x18;
  cubicCoefficient = (f32) ((((secondSample << 6) - new_var) - (thirdSample * 0x30)) + (fourthSample * 8));
  cubicCoefficient *= 0.33333334f;
  if (valueBitWidth != 0)
  {
    quantizedValueScale = compressedCurve->unk8 / ((f32) ((1 << valueBitWidth) - 1));
  }
  else
  {
    halfRange = compressedCurve->unk8 * 0.5f;
    compressedCurve->unk8 = 0.0f;
    quantizedValueScale = compressedCurve->unk8;
    compressedCurve->unk4 = (f32) (compressedCurve->unk4 + halfRange);
  }
  constantCoefficient *= quantizedValueScale;
  if (segmentSampleCount >= 2U)
  {
    sampleCountDouble = (f64) segmentSampleCount;
    inverseSampleSpan = 1.0f / (((f32) sampleCountDouble) - 1.0f);
  }
  else
  {
    inverseSampleSpan = 1.0f;
  }
  coefficientScale = inverseSampleSpan * quantizedValueScale;
  linearCoefficient *= coefficientScale;
  coefficientScale *= inverseSampleSpan;
  quadraticCoefficient *= coefficientScale;
  coefficientScale *= inverseSampleSpan;
  constantCoefficient += compressedCurve->unk4;
  cubicCoefficient *= coefficientScale;
  compressedCurve->unk20 = segmentSampleCount;
  compressedCurve->unk14 = linearCoefficient;
  compressedCurve->unk10 = constantCoefficient;
  compressedCurve->unk18 = quadraticCoefficient;
  compressedCurve->unk1C = cubicCoefficient;
}
