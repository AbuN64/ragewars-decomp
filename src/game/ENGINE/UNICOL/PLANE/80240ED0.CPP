#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Sets up one face of a box as a four-corner quad of kind 4, copying points 3, 2, 6 and 7 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through GraphU64_SubtractVectors, their cross product through
   GraphU64_CrossVectors and normalisation through func_8027207C_de. Adapted from Plane_BuildBoxFace0 with the copied points changed. */




extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

/* The edge vectors belong to this helper; declared in the face function itself, GCC 2.8.1 keeps
   the second edge's frame address in a saved register and grows the frame. */
static inline void quad_normal(struct Quad *quad) {
    CVector3 first;
    CVector3 second;

    GraphU64_SubtractVectors(&first, &quad->corner[1], &quad->corner[0]);
    GraphU64_SubtractVectors(&second, &quad->corner[2], &quad->corner[1]);
    GraphU64_CrossVectors(&quad->normal, &second, &first);
    GraphU64_NormalizeVec3(&quad->normal);
}

void Plane_BuildBoxFace2(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[3];
    quad->corner[2] = points[2];
    quad->corner[1] = points[6];
    quad->corner[0] = points[7];
    quad_normal(quad);
}
