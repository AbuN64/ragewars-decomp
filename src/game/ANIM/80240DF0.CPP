#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Sets up one face of a box as a four-corner quad of kind 4, copying points 7, 6, 5 and 4 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through func_80271F68_de, their cross product through
   func_80272018_de and normalisation through func_8027207C_de. Adapted from func_80240D20_de with the copied points changed. */




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

void func_80240E00_de(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[7];
    quad->corner[2] = points[6];
    quad->corner[1] = points[5];
    quad->corner[0] = points[4];
    quad_normal(quad);
}
