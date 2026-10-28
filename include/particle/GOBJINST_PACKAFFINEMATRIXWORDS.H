#ifndef PARTICLE_GOBJINST_PACKAFFINEMATRIXWORDS_H
#define PARTICLE_GOBJINST_PACKAFFINEMATRIXWORDS_H
#include "COMMON/ACTORRESOURCEHEADER.H"
extern void Gobjinst_InterpolatePoseTranslation(void *outVector, f32 t, void *a, void *b);
extern void Gobjinst_PackAffineMatrixWords(f32 *src, PackedMatrixWords *dst);
extern void Gobjinst_SampleBoneTranslation(void *poseTrack, s32 boneIndex, void *outTranslation);
extern void Gobjinst_SampleBoneRotation(void *poseTrack, s32 boneIndex, CQuatern *outRotation);
extern void Gobjinst_InterpolatePoseRotation(void *cQuatern, f32 t, void *a, void *b);
#endif
