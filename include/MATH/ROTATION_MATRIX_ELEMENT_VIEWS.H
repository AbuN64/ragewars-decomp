#ifndef MATH_ROTATION_MATRIX_ELEMENT_VIEWS_H
#define MATH_ROTATION_MATRIX_ELEMENT_VIEWS_H
#include "TYPES.H"
struct RotationMatrixWords {
    f32 m00;
    f32 m01;
    f32 m02;
    f32 m03;
    f32 m10;
    f32 m11;
    f32 m12;
    f32 m13;
    f32 m20;
    f32 m21;
    f32 m22;
    f32 m23;
    f32 m30;
    f32 m31;
    f32 m32;
    f32 m33;
};
struct RotationMatrixElementsView {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 pad0C;
    f32 pad10;
    f32 f14;
    f32 pad18;
    f32 pad1C;
    f32 f20;
    f32 f24;
    f32 f28;
};
#endif
