#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80296014.h"
#include "types.h"

/* Builds six clipping planes from an eye point and four corner points: each of the first five planes takes as its normal the normalised cross product of two edges between the points and as its distance the normal's projection of a point on it (the third plane through the corners, the others through the eye), and the sixth plane is the third plane with its normal reversed, its distance projected through the eye. */





extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *v);

static inline void make_plane(PlaneEquation *plane, Vec3 *from, Vec3 *through, Vec3 *to, Vec3 *point) {
    Vec3 a;
    Vec3 b;

    func_80271F68_de(&a, through, from);
    func_80271F68_de(&b, to, through);
    func_80272018_de(&plane->normal, &b, &a);
    func_8027207C_de(&plane->normal);
    plane->distance = plane->normal.x * point->x + plane->normal.y * point->y + plane->normal.z * point->z;
}

void func_802965B0_de(PlaneEquation *planes, Vec3 *eye, Vec3 *c0, Vec3 *c1, Vec3 *c2, Vec3 *c3) {
    make_plane(&planes[2], c0, c1, c3, c0);
    make_plane(&planes[0], eye, c0, c2, eye);
    make_plane(&planes[1], eye, c3, c1, eye);
    make_plane(&planes[4], eye, c1, c0, eye);
    make_plane(&planes[3], eye, c2, c3, eye);
    planes[5].normal.x = -planes[2].normal.x;
    planes[5].normal.y = -planes[2].normal.y;
    planes[5].normal.z = -planes[2].normal.z;
    planes[5].distance = planes[5].normal.x * eye->x + planes[5].normal.y * eye->y + planes[5].normal.z * eye->z;
}
