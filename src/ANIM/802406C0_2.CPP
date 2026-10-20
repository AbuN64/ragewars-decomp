#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);

extern void func_80272018_de(CVector3 *out, CVector3 *a, CVector3 *b);


/* Sets up one face of a box as a four-corner quad of kind 4, copying points 0, 1, 2 and 3 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through func_80271F68_de, their cross product through
   func_80272018_de and normalisation through func_8027207C_de. */




extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);


/* The edge vectors belong to this helper; declared in the face function itself, GCC 2.8.1 keeps
   the second edge's frame address in a saved register and grows the frame. */
static inline void quad_normal(struct Quad *quad) {
    CVector3 first;
    CVector3 second;

    func_80271F68_de(&first, &quad->corner[1], &quad->corner[0]);
    func_80271F68_de(&second, &quad->corner[2], &quad->corner[1]);
    func_80272018_de(&quad->normal, &second, &first);
    func_8027207C_de(&quad->normal);
}

void func_80240CAC_de(void *arg0) {
    QueryE0 *object = arg0;
    CVector3 sp10;
    CVector3 sp20;
    CVector3 *temp_s1;
    CVector3 *temp_s0;

    temp_s1 = &object->vectors[1];
    func_80271F68_de(&sp10, temp_s1, &object->vectors[0]);
    func_80271F68_de(&sp20, &object->vectors[2], temp_s1);
    temp_s0 = &object->result;
    func_80272018_de(temp_s0, &sp20, &sp10);
    func_8027207C_de(temp_s0);
}

void func_80240D20_de(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[0];
    quad->corner[2] = points[1];
    quad->corner[1] = points[2];
    quad->corner[0] = points[3];
    quad_normal(quad);
}
