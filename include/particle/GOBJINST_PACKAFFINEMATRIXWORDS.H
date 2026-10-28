#ifndef FX_2_8024BA6C_6_H
#define FX_2_8024BA6C_6_H
#include "COMMON/ACTORRESOURCEHEADER.H"
extern void Gobjinst_InterpolatePoseTranslation(void *arg0, f32 t, void *a, void *b);
extern void Gobjinst_PackAffineMatrixWords(f32 *src, PackedMatrixWords *dst);
extern void Gobjinst_SampleBoneTranslation(void *arg0, s32 arg1, void *arg2);
extern void Gobjinst_SampleBoneRotation(void *arg0, s32 arg1, CQuatern *arg2);
extern void Gobjinst_InterpolatePoseRotation(void *arg0, f32 t, void *a, void *b);
#endif
