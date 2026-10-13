#ifndef RW_TRACK_TABLES_H
#define RW_TRACK_TABLES_H
#include "shared/track_types.h"
typedef struct Shared_TrackClip {
    s32 stride, count;
    Key_func_80401214_de keys[1];
} Shared_TrackClip;
typedef struct Shared_TrackCues {
    s32 stride, count;
    Key_func_80401564_de cues[1];
} Shared_TrackCues;
typedef struct Shared_TrackTable {
    s32 stride, count;
    Entry_func_804030E0_de entries[1];
} Shared_TrackTable;
#endif
