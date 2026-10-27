#include "include_asm.h"
#include "COMMON/FRUSTUM.H"
#include "SYSTEM/80296FF8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "TYPES.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SCENERECAT10C0.H"
#include "FX_2/80271B18.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/OBJRECAT3CV2.H"

s32 func_80263154_de(BitReader *, s32);

extern void AnimPool_InitializeBitReader(BitReader *, void *);
/* Decode a 17-by-17 region grid, then replace variable cells with stream offsets. */
void VisData_DecodeRegionGrid(ResourceBitGrid *grid, s32 originX, s32 originZ,
                   DraftStreamData *source, CVector3 *position) {
    CVector3 minimum, maximum;
    u32 streamCount, streamIndex;
    s32 row, column, cellCode, index;
    s32 *streamTable = &source->count;
    grid->originX = originX;
    grid->originY = originZ;
    streamCount = *streamTable;
    streamIndex = 1;
    while (streamIndex < streamCount) {
        AnimPool_InitializeBitReader(&grid->reader, SetN64_GetPackSection(streamTable, streamIndex));
        *(s32 *)&minimum.x = func_80263154_de(&grid->reader, 32);
        *(s32 *)&minimum.y = func_80263154_de(&grid->reader, 32);
        *(s32 *)&minimum.z = func_80263154_de(&grid->reader, 32);
        *(s32 *)&maximum.x = func_80263154_de(&grid->reader, 32);
        *(s32 *)&maximum.y = func_80263154_de(&grid->reader, 32);
        *(s32 *)&maximum.z = func_80263154_de(&grid->reader, 32);
        if (position->x > minimum.x && position->x < maximum.x &&
            position->y > minimum.y && position->y < maximum.y &&
            position->z > minimum.z && position->z < maximum.z) break;
        streamIndex++;
    }
    if (streamIndex == streamCount) {
        AnimPool_InitializeBitReader(&grid->reader, SetN64_GetPackSection(streamTable, 0));
    }
    for (index = row = 0; row < 17; row++) {
        for (column = 0; column < 17; column++, index++) {
            cellCode = func_80263154_de(&grid->reader, 2);
            if (cellCode != 1) {
                if (cellCode != 0) {
                    if (cellCode != 2) {
                        if (cellCode == 3) grid->cells[index] = cellCode;
                    } else grid->cells[index] = 0;
                } else grid->cells[index] = -3;
            } else grid->cells[index] = -2;
        }
    }
    for (index = row = 0; row < 17; row++) {
        for (column = 0; column < 17; column++, index++) {
            if (grid->cells[index] == 0) {
                grid->cells[index] = (u16)grid->reader.bitPos;
                grid->reader.bitPos += func_80263154_de(&grid->reader, 9);
            }
        }
    }
}

/* Tests a centered grid cell and interprets its sentinel value. */


static inline int offset(int v){return v+9;}

/* Looks up the neighbour cell for (x,y) in the object's inline grid when both axes are within 9, and sets its state from the sentinel found (or starts a placement for a normal cell). */


/* Builds six clipping planes from an eye point and four corner points: each of the first five planes takes as its normal the normalised cross product of two edges between the points and as its distance the normal's projection of a point on it (the third plane through the corners, the others through the eye), and the sixth plane is the third plane with its normal reversed, its distance projected through the eye. */







extern void GraphU64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);
extern void GraphU64_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);
static inline void make_plane(PlaneEquation *plane, CVector3 *from, CVector3 *through, CVector3 *to, CVector3 *point) {
    CVector3 a;
    CVector3 b;

    GraphU64_SubtractVectors(&a, through, from);
    GraphU64_SubtractVectors(&b, to, through);
    GraphU64_CrossVectors(&plane->normal, &b, &a);
    GraphU64_NormalizeVec3(&plane->normal);
    plane->distance = plane->normal.x * point->x + plane->normal.y * point->y + plane->normal.z * point->z;
}

static inline s32 func_80297AD4_anyInside(CVector3 *points, s32 count, f32 *plane) {
    s32 i;
    s32 inside = 0;

    for (i = 0; i < count; i++) {
        if (plane[0] * points[i].x + plane[1] * points[i].y + plane[2] * points[i].z <= plane[3]) {
            inside = 1;
            break;
        }
    }
    return inside;
}

/* Reports what occupies the board cell at the given coordinates, or nothing when it is out of reach. */
s32 VisData_GetVisibilityCellState(ResourceBitGrid *arg0, s32 arg1, s32 arg2) {
    s32 col;
    s32 row;
    s16 cell;
    if ((((f32) (arg1 - arg0->originX) < 0.0f) ? -(arg1 - arg0->originX) : (arg1 - arg0->originX)) >= 9) {
        return 0;
    }
    if ((((f32) (arg2 - arg0->originY) < 0.0f) ? -(arg2 - arg0->originY) : (arg2 - arg0->originY)) >= 9) {
        return 0;
    }
    col = (arg1 - arg0->originX) + 8;
    row = (arg2 - arg0->originY) + 8;
    cell = arg0->cells[col + (row * 17)];
    if (cell == -2) {
        return 1;
    }
    if (cell == -3) {
        return 0;
    }
    if (cell == -1) {
        return 3;
    }
    return 2;
}

int VisData_TestVisibilityGridBit(ResourceBitGrid *g,int x,int y,int z){
    int v; unsigned int adjusted;if(!(RW_ABS(x-g->originX)<9 && RW_ABS(y-g->originY)<9))return 0;v=g->cells[(x-g->originX)+8+((y-g->originY)+8)*17];if(v==-2)return 1;if(v==-3)return 0;adjusted=z+9;g->reader.bitPos=v+adjusted;return func_80263154_de(&g->reader,1)!=0;}

void VisData_SelectVisibilityCell(ResourceBitGrid *arg0, s32 x, s32 y)
{
    if (RW_ABS(x - arg0->originX) >= 9) {
        return;
    }
    if (RW_ABS(y - arg0->originY) >= 9) {
        return;
    }
    {
        s32 ddx = x - arg0->originX;
        s32 ddy = y - arg0->originY;
        s32 t = (ddy + 8) * 17 + 8;
        s16 val;
        ddx = ddx + t;
        val = arg0->cells[ddx];
        if (val == -2) {
            arg0->cellState = 1;
            return;
        }
        if (val == -3) {
            arg0->cellState = 0;
            return;
        }
        if (val == -1) {
            arg0->cellState = 3;
            return;
        }
        arg0->cellState = 2;
        arg0->reader.bitPos = val;
        arg0->cellValue = func_80263154_de(&arg0->reader, 9);
    }
}

s32 VisData_ReadNextVisibilityBit(ResourceBitGrid *arg0) {
    s32 field;
    field = arg0->cellState;
    if (field != 2) {
        return field == 1;
    }
    return func_80263154_de(&arg0->reader, 1) != 0;
}

void VisData_BuildFrustumPlanes(PlaneEquation *planes, CVector3 *eye, CVector3 *c0, CVector3 *c1, CVector3 *c2, CVector3 *c3) {
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

void VisData_BuildPlaneFromPoints(void *planeEquation, void *arg1, void *arg2, void *arg3) {
    PlaneEquation *plane = planeEquation;
    CVector3 *point = arg1;
    CVector3 sp10;
    CVector3 sp20;
    GraphU64_SubtractVectors(&sp10, arg2, arg1);
    GraphU64_SubtractVectors(&sp20, arg3, arg2);
    GraphU64_CrossVectors(planeEquation, &sp20, &sp10);
    GraphU64_NormalizeVec3(planeEquation);
    plane->distance = (plane->normal.x * point->x)
                                  + (plane->normal.y * point->y)
                                  + (plane->normal.z * point->z);
}

f32 VisData_GetPlaneSegmentFraction(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 x;
    f32 y;
    f32 z;
    f32 dot1;
    f32 dot2;

    x = arg0[0];
    y = arg0[1];
    z = arg0[2];
    dot1 = (x * arg1[0]) + (y * arg1[1]) + (z * arg1[2]);
    dot2 = (x * arg2[0]) + (y * arg2[1]) + (z * arg2[2]);
    if (dot2 == dot1) {
        return D_800C5510_de;
    }
    return (arg0[3] - dot1) / (dot2 - dot1);
}

f32 VisData_EvaluatePlaneAtPoint(f32 *a, f32 *b) {
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]) - a[3];
}

/* Returns whether a point lies on the inner side of all six planes of a frustum, each stored as a normal and a distance. Adapted from VisData_TestBoxAgainstFrustum with the per-axis box minimum replaced by the point's dot product with each plane normal, tested directly in the loop. */
s32 VisData_ContainsPoint(f32 (*planes)[4], f32 *point) {
    s32 i;
    f32 *plane;

    for (i = 0; i < 6; i++) {
        plane = planes[i];
        if (!(plane[0] * point[0] + plane[1] * point[1] + plane[2] * point[2] <= plane[3])) {
            return 0;
        }
    }
    return 1;
}

/* Returns 1 when each of the six planes has at least one of the n points on or inside it (normal dot point <= plane distance), else 0. */





s32 VisData_TestPointsAgainstFrustum(CQuatern *planes, s32 n, CVector3 *points) {
    s32 i;
    s32 j;
    s32 inside;

    for (i = 0; i < 6; i++) {
        inside = 0;
        for (j = 0; j < n; j++) {
            if (planes[i].x * points[j].x + planes[i].y * points[j].y + planes[i].z * points[j].z <= planes[i].w) {
                inside = 1;
                break;
            }
        }
        if (!inside) {
            return 0;
        }
    }
    return 1;
}

/* Returns 1 when every frustum plane except plane two has at least one of the points on its inner side. */
s32 VisData_TestPointsAgainstFivePlanes(Frustum *frustum, s32 count, CVector3 *points) {
    s32 p;
    f32 *plane;

    for (p = 0; p < 6; p++) {
        if (p == 2) {
            continue;
        }
        plane = frustum->planes[p];
        if (!func_80297AD4_anyInside(points, count, plane)) {
            return 0;
        }
    }
    return 1;
}

/* Tests a box against six planes, returning 1 when for every plane the sum of the per-axis minimum products does not exceed the plane distance, else 0. Adapted from VisData_TestBoxAgainstPlane, with its body inlined into a loop over six four-float planes and the loop-invariant product computed first. */

s32 VisData_TestBoxAgainstFrustum(f32 (*arg0)[4], f32 *arg1) {
    s32 i;
    s32 inside;
    f32 *plane;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 x;
    f32 y;
    f32 z;
    f32 sum;

    for (i = 0; i < 6; i++) {
        plane = arg0[i];
        temp_f0 = plane[0];
        temp_f0_2 = arg1[3] * temp_f0;
        x = arg1[0] * temp_f0;
        if (!(x <= temp_f0_2)) {
            x = temp_f0_2;
        }
        temp_f0_3 = plane[1];
        y = arg1[1] * temp_f0_3;
        temp_f1 = arg1[4] * temp_f0_3;
        sum = x;
        if (!(y <= temp_f1)) {
            y = temp_f1;
        }
        sum += y;
        temp_f0_4 = plane[2];
        z = arg1[2] * temp_f0_4;
        temp_f1_2 = arg1[5] * temp_f0_4;
        if (!(z <= temp_f1_2)) {
            z = temp_f1_2;
        }
        sum += z;
        inside = sum <= plane[3];
        if (!inside) {
            return 0;
        }
    }
    return 1;
}

s32 VisData_TestBoxAgainstPlane(f32 *arg0, f32 *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 x;
    f32 y;
    f32 z;
    f32 sum;

    temp_f0 = arg0[0];
    x = arg1[0] * temp_f0;
    temp_f0_2 = arg1[3] * temp_f0;
    if (!(x <= temp_f0_2)) {
        x = temp_f0_2;
    }
    temp_f0_3 = arg0[1];
    y = arg1[1] * temp_f0_3;
    temp_f1 = arg1[4] * temp_f0_3;
    sum = x;
    if (!(y <= temp_f1)) {
        y = temp_f1;
    }
    sum += y;
    temp_f0_4 = arg0[2];
    z = arg1[2] * temp_f0_4;
    temp_f1_2 = arg1[5] * temp_f0_4;
    if (!(z <= temp_f1_2)) {
        z = temp_f1_2;
    }
    sum += z;
    if (sum <= arg0[3]) {
        return 1;
    }
    return 0;
}

#if defined(VERSION_US)
char rodata_unresolved_80296C08[8] =
    "\000\000\000\003s16R";
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_80296930_CB2A0[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80296930_CB2A0_us_rev1.c */
const unsigned int D_blob_0e557f3de25e32e16abb[1] = {
    0x3F800000,
};
#endif
