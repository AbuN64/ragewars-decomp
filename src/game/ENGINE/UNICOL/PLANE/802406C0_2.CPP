#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void GraphU64_SubtractVectors(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);

extern void GraphU64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


/* Sets up one face of a box as a four-corner quad of kind 4, copying points 0, 1, 2 and 3 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through GraphU64_SubtractVectors, their cross product through
   GraphU64_CrossVectors and normalisation through func_8027207C_de. */




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

void func_80240CAC_de(void *query) {
    QueryE0 *object = query;
    CVector3 firstEdge;
    CVector3 secondEdge;
    CVector3 *middleVertex;
    CVector3 *outputNormal;

    middleVertex = &object->vectors[1];
    GraphU64_SubtractVectors(&firstEdge, middleVertex, &object->vectors[0]);
    GraphU64_SubtractVectors(&secondEdge, &object->vectors[2], middleVertex);
    outputNormal = &object->result;
    GraphU64_CrossVectors(outputNormal, &secondEdge, &firstEdge);
    GraphU64_NormalizeVec3(outputNormal);
}

void Plane_BuildBoxFace0(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[0];
    quad->corner[2] = points[1];
    quad->corner[1] = points[2];
    quad->corner[0] = points[3];
    quad_normal(quad);
}
