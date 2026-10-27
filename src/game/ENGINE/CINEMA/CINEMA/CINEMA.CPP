#include "COMMON/GROUP.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "MENU_2/80400000_16.H"
#include "COMMON/FUNCPTR.H"
#include "CAMERA/EXTERNS.H"
#include "COMMON/EXTERNS_8.H"
#include "CINEMA/CINEMA.H"
#include "include_asm.h"
#include "CAMERA/80243A80_6.H"

/* 80243A80_8.CPP */
/** Read the word at offset 0x38 from the globally selected record. */

/* Reports whether the globally selected record is active (its word at 0x38 is non-zero) and its
   value at 0x1C lies between the bounds at 0x30 and 0x34. */

void Cinema_EndSequence(void) {
    if (Cinema_IsSequenceActive() != 0) {
        s32 owner;
        Shared_MenuContext *record;

        func_80245B74_de(1);
        func_80245BC0_de();
        owner = (s32)D_800E2830->owner;
        if (owner != 0) {
            Cache_ReleaseResource(0, owner);
        }
        record = D_800E2830;
        record->owner = 0;
        record->resource = 0;
        record->active = 0;
        record->state3C = 0;
        record->unknown60 = 0;
    }
}

void func_8024570C_de(void) {
    if (Cinema_IsSequenceActive() != 0 && func_80245764_de() != 0 && D_800E2830->unknown60 == 0) {
        f32 temp = D_800C37D0_de;
        D_800E2830->unknown60 = 1;
        D_800E2830->fade = temp;
    }
}

/** Return the constant success result used by callers at VRAM 0x80245754. */
int func_80245764_de(void) {
    return 1;
}

int func_8024576C_de(void) {
    return D_800E2830->resourceDC != -1;
}

int Cinema_IsSequenceActive(void) {
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}

int Cinema_IsSequenceInWindow(void) {
    Shared_MenuContext *record = D_800E2830;
    float time;
    int inSequenceWindow = 0;

    if (record->active != 0) {
        time = record->time;
        if (record->start <= time && time <= record->end) {
            inSequenceWindow = 1;
        }
    }
    return inSequenceWindow;
}

s32 func_802457E0_de(void) {
    if (D_800E2830->active != 0) {
        if (D_800E2830->time > D_800E2830->end) {
            return 1;
        }
        return 0;
    }
    return 1;
}

/* 80243A80_9.CPP */
/* Calls Menu_UpdateTrackCamera when the globally selected record's word at 0x38 is non-zero. */

/* Calls Menu_DrawTrackOverlay when the globally selected record's word at 0x38 is non-zero. */

/** Clear the global word at VRAM 0x800E2838. */

/* Reports whether Cinema_IsSequenceInWindow accepts the globally selected record and bit 2 of its word at 0x74
   is set. */

/* Returns the globally selected record's word at 0xAC while its word at 0x38 is non-zero, and 0
   otherwise. */

/* Returns the globally selected record's word at 0xA8 while its word at 0x38 is non-zero, and 0
   otherwise. */

extern f32 Menu_EvaluateTrackScalar(f32 arg0);

/** Clear the word at offset 0x100 in the active object. */

extern void XPlus_CopyString(void *arg0, int arg1);

/* Returns the globally selected record's float at 0xA0 scaled by D_800C88CC. */

/* Returns the state object's word at its measured value field. */

s32 func_80245814_de(void) {
    s32 result;
    result = 0;
    if (Cinema_IsSequenceActive() == 0) {
        result = func_8024576C_de() == 0;
    }
    return result;
}

/** Return the word at offset 0x3C of the current global object. */
unsigned int func_80245850_de(void) {
    return D_800E2830->state3C;
}

void Cinema_UpdateSequenceTrack(void *camera) {
    Shared_MenuContext *record = D_800E2830;
    if (record->active != 0) {
        Menu_UpdateTrackCamera(camera);
    }
}

void func_80245894_de(void) {
    Shared_MenuContext *record = D_800E2830;
    if (record->active != 0) {
        Menu_DrawTrackOverlay();
    }
}

/** Set the global word at VRAM 0x800E2838 to one. */
void func_802458C4_de(void) {
    D_800DE7E8 = 1;
}

void func_802458D8_de(void) {
    D_800DE7E8 = 0;
}

/** Return the current global object word. */
unsigned int func_802458E8_de(void) {
    return D_800DE7E8;
}

void func_802458F8_de(void) {
    D_800E2830->state3C = 0;
}

int func_80245908_de(void) {
    Shared_MenuContext *record;
    if (Cinema_IsSequenceInWindow() == 0) {
        return 0;
    }
    record = D_800E2830;
    if ((record->spec.flags & 2) != 0) {
        return 1;
    }
    return 0;
}

int func_80245940_de(void) {
    Shared_MenuContext *record = D_800E2830;
    int cond = record->active != 0;
    if (cond) {
        if (record) {
            return record->spec.settings[1];
        } else {
            return record->spec.settings[1];
        }
    }
    return 0;
}

int func_80245968_de(void) {
    Shared_MenuContext *record = D_800E2830;
    int cond = record->active != 0;
    if (cond) {
        if (record) {
            return record->spec.settings[0];
        } else {
            return record->spec.settings[0];
        }
    }
    return 0;
}

void func_80245990_de(void *letterboxEnabled) {
    D_800DE7F4_de = letterboxEnabled;
}

f32 func_802459A0_de(void) {
    Shared_MenuContext *record = D_800E2830;
    f32 response;

    if (record->active == 0) {
        return D_800C37D4_de;
    }
    response = record->response;
    if (!(D_800C37D8_de < response)) {
        return Menu_EvaluateTrackScalar(record->time);
    }
    return response;
}

void Cinema_SetResponse(float responseValue) {
    D_800E2830->response = responseValue;
}

void Cinema_ClearResponse(void) {
    D_800E2830->response = 0.0f;
}

void func_80245A20_de(int loopMode) {
    D_800E2830->unknown104[0] = loopMode;
}

/** Copy a two-word record into the global record and clear two trailing fields. */
void func_80245A30_de(void) {
    Shared_MenuContext *record = D_800E2830;
    int hi = D_800E28D4;
    int lo = D_800E28D0;
    record->unknown104[2] = hi;
    record->unknown104[1] = lo;
    record->unknown104[3] = 0;
    record->unknown104[4] = 0;
}

/** Store four incoming words into the global record's tail fields. */
void func_80245A5C_de(int viewportWidth, int viewportHeight, int viewportLeft, int viewportTop) {
    Shared_MenuContext *record = D_800E2830;
    record->unknown104[2] = viewportHeight;
    record->unknown104[1] = viewportWidth;
    record->unknown104[3] = viewportLeft;
    record->unknown104[4] = viewportTop;
}

void Cinema_AddMessage(int goal) {
    Shared_MenuContext *record = D_800E2830;
    int idx = record->messageCount;
    XPlus_CopyString(record->messages[idx], goal);
    record = D_800E2830;
    record->messageCount = record->messageCount + 1;
}

void Cinema_ClearMessageCount(void) {
    D_800E2830->messageCount = 0;
}

float func_80245AD8_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return (record->spec.scaleA0) * (D_800C88CC);
}

/** Return the word at offset 0xB0 of the current global object. */
unsigned int func_80245AF8_de(void) {
    return D_800E2830->spec.unknown48;
}

s32 Cinema_GetSequenceRequest(void) {
    return D_800E2830->requestE0;
}

/* Returns the word at offset 0xE0 of the object D_800E2830 points to. The interval also holds an
   empty function with no symbol of its own, compiled here as the file-local stub after it. */

static void func_80245B20_de(void) {
}

void Cinema_ReleaseSequenceContext(void) {
    int owner = (s32)D_800E2830->owner;
    Shared_MenuContext *record;
    if (owner != 0) {
        Cache_ReleaseResource(0, owner);
    }
    record = D_800E2830;
    record->owner = 0;
    record->resource = 0;
    record->active = 0;
    record->state3C = 0;
    record->unknown60 = 0;
}

/* 80243A80_10.CPP */
void func_80245B74_de(s32 unused) {
    Shared_MenuContext *record;
    Shared_MenuVoidCallback fn;

    record = D_800E2830;
    if (record->initialized44 == 0) {
        fn = record->callback10;
        if (fn != 0) {
            record->callback10 = 0;
            fn();
        }
        record = D_800E2830;
        record->initialized44 = 1;
    }
}

void func_80245BC0_de(void) {
    if (D_800E2830->closed == 0) {
        {
            void *owner = D_800E2830->owner;
            if (owner != 0) {
                Cache_ReleaseResource(0, owner);
            }
        }
        {
            void *record = D_800E2830;
            FuncPtr fn = ((Shared_MenuContext *)(record))->onClose;

            ((Shared_MenuContext *)(record))->owner = 0;
            ((Shared_MenuContext *)(record))->resource = 0;
            ((Shared_MenuContext *)(record))->active = 0;
            ((Shared_MenuContext *)(record))->state3C = 0;
            ((Shared_MenuContext *)(record))->unknown60 = 0;
            if (fn != 0) {
                ((Shared_MenuContext *)(record))->onClose = 0;
                fn();
            }
        }
        D_800E2830->closed = 1;
    }
}

/* 80243A80_11.CPP */
extern f32 D_800D2988;

/** Read the word at offset 0x38 from the globally selected record. */

void func_80245C38_de(void) {
    f32 value;
    f32 limit;
    Shared_MenuContext *record;

    if (Cinema_IsSequenceActive() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->time20 = D_800E2830->time;
            return;
        }
        record = D_800E2830;
        record->time20 = *(volatile f32 *)&record->time;
        record->time += D_800D2988 * D_800C37E0_de;
        if (record->start <= record->time) {
            func_80244E58_de();
        }
        value = D_800E2830->time;
        limit = D_800E2830->clipEnd;
        if (limit <= value) {
            if (D_800E2830->unknown104[0] == 1) {
                D_800E2830->time = value - limit;
                return;
            }
            D_800E2830->time = limit;
            if (D_800E2830->fieldB4 != 0) {
                D_800E2830->state3C = 1;
                D_800E2830->fieldB4 = 0;
            }
        }
    }
}

int func_80245D14_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80245D08[2] = {
    0x00940A00, 0x08001800,
};
#endif
