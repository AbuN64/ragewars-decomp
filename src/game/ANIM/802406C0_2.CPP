#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void Particle_SubtractVectors(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);

extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


/* Sets up one face of a box as a four-corner quad of kind 4, copying points 0, 1, 2 and 3 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through Particle_SubtractVectors, their cross product through
   Particle_CrossVectors and normalisation through func_8027207C_de. */




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
    func_8027207C_de(&quad->normal);
}

void func_80240CAC_de(void *query) {
    QueryE0 *object = query;
    CVector3 sp10;
    CVector3 sp20;
    CVector3 *temp_s1;
    CVector3 *temp_s0;

    temp_s1 = &object->vectors[1];
    Particle_SubtractVectors(&sp10, temp_s1, &object->vectors[0]);
    Particle_SubtractVectors(&sp20, &object->vectors[2], temp_s1);
    temp_s0 = &object->result;
    Particle_CrossVectors(temp_s0, &sp20, &sp10);
    func_8027207C_de(temp_s0);
}

void Anim_BuildBoxFace0(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[0];
    quad->corner[2] = points[1];
    quad->corner[1] = points[2];
    quad->corner[0] = points[3];
    quad_normal(quad);
}
