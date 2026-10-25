#ifndef OVLGAME_80405454_H
#define OVLGAME_80405454_H
#include "TYPES.H"
struct Shape_typemap_165;
/* The render buffer record (D_8014D438): the resource handles behind the render globals. */
struct RecordRecAt1C {
    s32 ready;
    struct Shape_typemap_165 *displayLists;
    struct Shape_typemap_165 *fifo;
    struct Shape_typemap_165 *frameBuffers[3];
    struct Shape_typemap_165 *zBuffer;
    struct Shape_typemap_165 *audioHeap;
};
#endif
