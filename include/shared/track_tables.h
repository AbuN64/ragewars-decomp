#ifndef RW_TRACK_TABLES_H
#define RW_TRACK_TABLES_H
#include "shared/track_types.h"
typedef struct Shared_TrackClip {
    s32 stride, count;
    KeyRecAt1C keys[1];
} Shared_TrackClip;
typedef struct Shared_TrackCues {
    s32 stride, count;
    PositionKey cues[1];
} Shared_TrackCues;
typedef struct Shared_TrackTable {
    s32 stride, count;
    EntryRecAt48 entries[1];
} Shared_TrackTable;
#endif
