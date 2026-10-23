#ifndef COMMON_FLOOR_RESOURCE_H
#define COMMON_FLOOR_RESOURCE_H
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/ITEMRECAT20V1.H"

/* One cell of the floor grid: the polygons of the cell lie in its x/z bounds. */
typedef struct FloorCell {
    Bounds2D37 bounds;
    u32 count;
} FloorCell;



#endif
