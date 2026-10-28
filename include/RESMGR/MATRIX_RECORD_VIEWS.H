#ifndef RESMGR_MATRIX_RECORD_VIEWS_H
#define RESMGR_MATRIX_RECORD_VIEWS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
/* Matrix constructor record: four header words precede the 4x4 matrix. */
typedef struct MatrixRecord {
    u32 header[4];
    Matrix matrix;
} MatrixRecord;
struct Mtx3x4_8029FD54 {
    f32 m[3][4];
};
#endif
