#ifndef PARTICLE_PARTICLE_BUILDMATRIX_H
#define PARTICLE_PARTICLE_BUILDMATRIX_H
#include "TYPES.H"
struct CVector3_t;
struct GameplayCamera;
struct PackedMatrixWords;
struct Shared_Particle;
extern f32 *Particle_ParentTransform(struct Shared_Particle *particle, struct GameplayCamera *camera);
extern void Particle_Attach(struct Shared_Particle *particle, struct CVector3_t *outPosition,
                            struct CVector3_t *outDirection);
extern void Particle_BuildMatrix(struct Shared_Particle *particle, struct PackedMatrixWords *out,
                                 struct GameplayCamera *camera, f32 depth);
#endif
