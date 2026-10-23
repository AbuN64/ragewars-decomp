#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

/* Sets up one face of a box as a four-corner quad of kind 4, copying points 2, 1, 5 and 6 of the
   input into corners 3, 2, 1 and 0 and deriving its normal at 0x48 from the edges corner 1 minus
   corner 0 and corner 2 minus corner 1 through func_80271F68_de, their cross product through
   func_80272018_de and normalisation through func_8027207C_de. Adapted from Anim_BuildBoxFace0 with the copied points changed. */




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

void Anim_BuildBoxFace5(struct Quad *quad, CVector3 *points) {
    quad->kind = 4;
    quad->corner[3] = points[2];
    quad->corner[2] = points[1];
    quad->corner[1] = points[5];
    quad->corner[0] = points[6];
    quad_normal(quad);
}

s32 func_80241260_de(void *plane, CVector3 *arg1) {
    Plane *object = plane;
    CVector3 offset;
    s32 outside;

    func_80271F68_de(&offset, arg1, &object->pos);
    outside = 0;
    if (!((object->normal.x * offset.x) + (object->normal.y * offset.y) + (object->normal.z * offset.z) >= 0.0f)) {
        outside = 1;
    }
    return outside;
}
