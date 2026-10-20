#ifndef MENU_2_TRACK_TABLES_H
#define MENU_2_TRACK_TABLES_H
#include "COMMON/KEYRECAT1C.H"
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
