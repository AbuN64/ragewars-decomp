#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Sets up one face of a box as a four-corner quad of kind 4, copying points 4, 5, 1 and 0 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through Particle_SubtractVectors, their cross product through
   Particle_CrossVectors and normalisation through func_8027207C_de. Adapted from Anim_BuildBoxFace0 with the copied points changed. */




extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

/* The edge vectors belong to this helper; declared in the face function itself, GCC 2.8.1 keeps
   the second edge's frame address in a saved register and grows the frame. */
static inline void quad_normal(struct Quad *quad) {
    CVector3 first;
    CVector3 second;

    Particle_SubtractVectors(&first, &quad->corner[1], &quad->corner[0]);
    Particle_SubtractVectors(&second, &quad->corner[2], &quad->corner[1]);
    Particle_CrossVectors(&quad->normal, &second, &first);
    Particle_NormalizeVec3(&quad->normal);
}

void Anim_BuildBoxFace3(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[4];
    quad->corner[2] = points[5];
    quad->corner[1] = points[1];
    quad->corner[0] = points[0];
    quad_normal(quad);
}
