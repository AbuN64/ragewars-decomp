#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Tests a ray against an axis-aligned box: a ray starting inside the box hits at parameter 0; otherwise
 * each axis whose start and end differ gives the parameter where the ray reaches the box face it
 * approaches, and the first such hit nearer than the ray's current nearest hit whose point lies within the
 * face's other two extents is written out. Returns whether the box was hit. */







s32 func_8023DAA0_de(Ray *ray, Box *box, f32 *out) {
    Vec3 hit;
    Vec3 *start;
    Vec3 *end;
    f32 t;

    start = &ray->start;
    end = &ray->end;
    if (box->max.x >= start->x && box->max.y >= start->y && box->max.z >= start->z && box->min.x <= start->x &&
        box->min.y <= start->y && box->min.z <= start->z) {
        *out = 0.0f;
        return 1;
    }
    if (start->x != end->x) {
        if (start->x < end->x) {
            t = (box->min.x - start->x) / (end->x - start->x);
        } else {
            t = (start->x - box->max.x) / (start->x - end->x);
        }
        if (t < ray->nearest) {
            hit.y = start->y + t * ray->dir.y;
            hit.z = start->z + t * ray->dir.z;
            if (box->min.y <= hit.y && hit.y <= box->max.y && box->min.z <= hit.z && hit.z <= box->max.z) {
                *out = t;
                return 1;
            }
        }
    }
    if (start->y != end->y) {
        if (start->y < end->y) {
            t = (box->min.y - start->y) / (end->y - start->y);
        } else {
            t = (start->y - box->max.y) / (start->y - end->y);
        }
        if (t < ray->nearest) {
            hit.x = start->x + t * ray->dir.x;
            hit.z = start->z + t * ray->dir.z;
            if (box->min.x <= hit.x && hit.x <= box->max.x && box->min.z <= hit.z && hit.z <= box->max.z) {
                *out = t;
                return 1;
            }
        }
    }
    if (start->z != end->z) {
        if (start->z < end->z) {
            t = (box->min.z - start->z) / (end->z - start->z);
        } else {
            t = (start->z - box->max.z) / (start->z - end->z);
        }
        if (t < ray->nearest) {
            hit.x = start->x + t * ray->dir.x;
            hit.y = start->y + t * ray->dir.y;
            if (box->min.x <= hit.x && hit.x <= box->max.x && box->min.y <= hit.y && hit.y <= box->max.y) {
                *out = t;
                return 1;
            }
        }
    }
    return 0;
}
