#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "include_asm.h"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "TYPES.H"

#include "RENDER_4/8028FD2C_6.H"
extern CVector3 Track_EvaluateCameraSpline(SplineNode *nodes, s32 count, f32 w);
extern void GraphU64_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);
extern f32 Graphu64_GetVerticalAngle(CVector3 *direction);
extern f32 GraphU64_GetHorizontalAngle(CVector3 *direction);

/* First point of the current track's camera path (pack section 0 of section 0 of the resource), or the origin with no track. */
static inline CVector3 TrackStartEye(void) {
    CVector3 point;
    CVector3 origin;
    StridedTable *path;
    if (D_800E2830->active == 0) {
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        return origin;
    }
    path = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), 0), 0);
    point = Track_EvaluateCameraSpline((SplineNode *)path->data, path->count, 0.0f);
    return point;
}

/* First point of the current track's target path (pack section 1), or 10 units along x with no track. */
static inline CVector3 TrackStartTarget(void) {
    CVector3 point;
    CVector3 fallback;
    StridedTable *path;
    if (D_800E2830->active == 0) {
        fallback.y = 0.0f;
        fallback.z = 0.0f;
        fallback.x = 10.0f;
        return fallback;
    }
    path = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), 0), 1);
    point = Track_EvaluateCameraSpline((SplineNode *)path->data, path->count, 0.0f);
    return point;
}

/* Pitch and heading from the track's start point toward its end point (roll 0); all zero with no active track. */
CVector3 Menu_GetTrackStartAngles(void) {
    CVector3 eye, target, direction, angles;
    if (D_800E2830->active == 0) {
        angles.x = 0.0f;
        angles.y = 0.0f;
        angles.z = 0.0f;
        return angles;
    } else {
        eye = TrackStartEye();
        target = TrackStartTarget();
        GraphU64_SubtractVectors(&direction, &target, &eye);
        angles.x = -Graphu64_GetVerticalAngle(&direction);
        angles.y = GraphU64_GetHorizontalAngle(&direction);
        angles.z = 0.0f;
        return angles;
    }
}

/* Sets the word at offset 0xB4 of the object D_800E2830 points to. */




extern int D_800DE7E8;

extern unsigned char *D_80145060;

extern void Track_RequestTrackByKey(int);

static inline int test_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    return *bits & (mask << index);
}

static inline void set_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    *bits |= mask << index;
}

/* Returns the initial track vector or the configured fallback when no track is active. */


 /* extern */

 /* extern */


/* Sums the duration values from the active resource tracks. */



/* Returns the first word of what SetN64_GetPackSection gives for the object at offset 4 of the structure
   D_800E2830 points to, asked with zero. */




/* Walks three lookups through SetN64_GetPackSection from the object at offset 4 of the structure
   D_800E2830 points to: first with zero, then with the argument, and returns the third lookup, with 0. */




/* Calls SetN64_GetPackSection on the object at offset 4 of the structure D_800E2830 points to, with 1. */




/* Returns the byte size of a block holding a 0x30-byte header and a 36-byte record for every entry
   counted at offset 4 of the two lists SetN64_GetPackSection returns for an object with zero and with
   two. */




void func_804037D4_de(void) {
    D_800E2830->fieldB4 = 1;
}

void Menu_TriggerTrackEvent(int event) {
    unsigned char *bits = D_80145060;
    int index;
    if (D_800DE7E8 != 0) {
        index = event - 0x259;
        if ((unsigned int)index < 6 && bits != 0) {
            if (test_bit(bits + 0x638, index)) return;
            set_bit(bits + 0x638, index);
        }
        Track_RequestTrackByKey(event);
    }
}

CVector3 Menu_GetTrackStartEye(void) {
    CVector3 splinePoint;
    CVector3 fallback;
    StridedTable *table;
    if (D_800E2830->active == 0) {
        fallback.x = 0;
        fallback.y = 0;
        fallback.z = 0;
        return fallback;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), 0), 0);
    splinePoint = Track_EvaluateCameraSpline((SplineNode *)table->data, table->count, 0.0f);
    return splinePoint;
}

CVector3 Menu_GetTrackStartTarget(void) {
    CVector3 splinePoint;
    CVector3 fallback;
    StridedTable *table;
    if (D_800E2830->active == 0) {
        fallback.y = 0;
        fallback.z = 0;
        fallback.x = D_800DCC7C_de;
        return fallback;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), 0), 1);
    splinePoint = Track_EvaluateCameraSpline((SplineNode *)table->data, table->count, 0.0f);
    return splinePoint;
}

f32 Menu_GetTrackDuration(void) {
    f32 clipDuration;
    f32 result;
    s32 *finalKey;
    s32 index;

    result = 0.0f;
    index = 0;
loop_1:
    if (index < *((s32 *)SetN64_GetPackSection(D_800E2830->resource, 0))) {
        finalKey = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), index), 0);
        finalKey = (s32 *)((char *)finalKey + finalKey[1] * 0x24);
        clipDuration = *(f32 *)finalKey;
        index += 1;
        result += clipDuration;
        goto loop_1;
    }
    return result;
}

s32 Menu_GetTrackClipCount(void) {
    return *((s32 *)SetN64_GetPackSection(D_800E2830->resource, 0));
}

void *Menu_GetTrackClip(s32 key) {
    return SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(D_800E2830->resource, 0), key), 0);
}

void *Menu_GetTrackCues(void) {
    return SetN64_GetPackSection(D_800E2830->resource, 1);
}

/** Advance a byte pointer by eight bytes. */
void *CTrackResource_GetRecordPayload(void *value) {
    ObjRecAt8V2 *record = value;
    return &record->unk8;
}

/** Return the selected bit from a packed byte array. */
u32 Menu_TestBit(u8 *bits, s32 index)
{
    s32 byte = index >> 3;
    u32 mask;

    index &= 7;
    mask = 1;
    bits += byte;
    return *bits & (mask << index);
}

/* Sets or clears bit n of a bitmap according to the third argument. */
void Menu_AssignBit(u8 *bits, s32 n, s32 set) {
    s32 index = n >> 3;
    s32 mask = 1 << (n & 7);

    if (set) {
        bits[index] |= mask;
    } else {
        bits[index] &= ~mask;
    }
}

s32 Menu_GetTrackSplineStorageSize(void *object) {
    struct IntPair *first = SetN64_GetPackSection(object, 0);
    struct IntPair *second = SetN64_GetPackSection(object, 2);
    s32 size = first->field_4 * 36;

    return size + second->field_4 * 36 + 0x30;
}
