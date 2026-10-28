#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/TRIPLE.H"
#include "MENU/TRACK_EVALUATETRACKOPACITY.H"
#include "MENU/TRACK_EVALUATETRACKCOLOR.H"
#include "MENU/TRACK_DRAWLETTERBOXBANDS.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/WORLD.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/AIPROFILE.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "RENDER/SETN64_GETPACKSECTION.H"

extern void SetN64_DrawColorRectangle(void *,u8 *,s32,s32,s32,s32);
static inline u32 toUnsigned(f32 v,f32 limit) { u32 result; if(!(limit<=v)) result=(u32)(s32)v; else { v-=limit; result=(u32)(s32)v; result|=0x80000000; } return result; }
static inline f32 unsignedWidth(u32 v) { f64 d=(s32)v; if((s32)v<0)d+=D_800DCC30; return (f32)d; }
static inline f32 unsignedHeight(u32 v) { f64 d=(s32)v; if((s32)v<0)d+=D_800DCC40_de; return (f32)d; }
void Track_DrawTrackOverlay(ScreenRectangle *rectangle) {
    CVector3 color,baseColor;
    u8 rgba[4];
    u32 width,height,right,bottom;
    f32 alpha,scale,value;
    if(D_800E2830->active) {
        value=rectangle->width;
        if(!(((f32 *)&D_800DCC28)[-1]<=value)) width=(u32)(s32)value;
        else {value-=((f32 *)&D_800DCC28)[-1]; width=(u32)(s32)value; width|=0x80000000;}
        value=rectangle->height;
        if(!(D_800DCC28<=value)) height=(u32)(s32)value;
        else {value-=D_800DCC28; height=(u32)(s32)value; height|=0x80000000;}
        value=unsignedWidth(width)+rectangle->x;
        if(!(((f32 *)&D_800DCC30)[2]<=value)) right=(u32)(s32)value;
        else {value-=((f32 *)&D_800DCC30)[2]; right=(u32)(s32)value; right|=0x80000000;}
        value=unsignedHeight(height)+rectangle->y;
        if(!(D_800DCC48_de<=value)) bottom=(u32)(s32)value;
        else {value-=D_800DCC48_de; bottom=(u32)(s32)value; bottom|=0x80000000;}
        baseColor=Track_EvaluateTrackColor(D_800E2830->time);
        alpha=Track_EvaluateTrackOpacity(D_800E2830->time);
        color=baseColor;
        if(D_800E2830->unknown60) {
            scale=D_800E2830->fade;
            if(scale<0.0f)scale=0.0f;
            color.x=baseColor.x*scale;
            color.y=baseColor.y*scale;
            color.z=baseColor.z*scale;
            alpha+=D_800DCC4C_de-scale;
        }
        value=color.x*((f32 *)&D_800DCC4C_de)[1];
        if(!(value<=((f32 *)&D_800DCC4C_de)[1]))value=((f32 *)&D_800DCC4C_de)[1];
        if(!(0.0f<=value))value=0.0f;
        rgba[0]=(u8)toUnsigned(value,((f32 *)&D_800DCC58_de)[-1]);
        value=color.y*D_800DCC58_de;
        if(!(value<=D_800DCC58_de))value=D_800DCC58_de;
        if(!(0.0f<=value))value=0.0f;
        rgba[1]=(u8)toUnsigned(value,((f32 *)&D_800DCC58_de)[1]);
        value=color.z*D_800DCC60;
        if(!(value<=D_800DCC60))value=D_800DCC60;
        if(!(0.0f<=value))value=0.0f;
        rgba[2]=(u8)toUnsigned(value,((f32 *)&D_800DCC60)[1]);
        value=alpha*((f32 *)&D_800DCC60)[2];
        if(!(value<=((f32 *)&D_800DCC60)[2]))value=((f32 *)&D_800DCC60)[2];
        if(!(0.0f<=value))value=0.0f;
        rgba[3]=(u8)toUnsigned(value,((f32 *)&D_800DCC4C_de)[8]);
        value=0.0f;
        SetN64_DrawColorRectangle(&D_8011FAC0,rgba,width,height,right,bottom);
    }
    if(D_800DE7F4_de)Track_DrawLetterboxBands();
}

/* When the entry table is available, loads it through SetN64_LocatePackSection and Cache_RequestResource, finds the
   last 0x4C-byte entry whose ids match the object's u16 ids at 4 and 0xA, and on a match records
   the owner, the id, the entry index and a pending flag in the current record; the loaded table
   is then released through Cache_UnlockResource. */










extern const char g_cinemaDirectoryText[];

extern s32 SetN64_LocatePackSection(s32 *, s32, s32, s32 *);



/* Returns 1 unless one of the current record's track-2 references names an item, in the first or
   second item table of D_8011FE88 by its side flag, whose kind and subkind are 1 and 5, 9 and 4,
   or 10 and 3. */













void Track_RequestTrackByIds(struct SharedTrackObject *owner, func_8020478C_S1 *obj) {
    s32 size;
    s32 **table;
    s32 key;
    s32 found;
    s32 i;
    s32 n;
    EntryRecAt4V2 *entry;
    s32 id4;
    s32 idA;

    found = -1;
    if (D_800DE7E8 != 0) {
        id4 = obj->unk4;
        idA = obj->unkA;
        key = SetN64_LocatePackSection(D_8011FEFC, D_8011BDFC, 0, &size);
        if (key == 0) {
            table = 0;
        } else {
            table = Cache_RequestResource(0, key, key, size, 0x33, 0, 0, g_cinemaDirectoryText, 1);
        }
        n = *D_8011FEFC - 1;
        entry = (EntryRecAt4V2 *)(*table + 2);
        for (i = 0; i < n; i++, entry++) {
            if (entry->id4 == id4 && entry->id0 == idA) {
                found = i;
            }
        }
        if (found != -1) {
            D_800E2830->target = owner;
            D_800E2830->targetD8 = idA;
            D_800E2830->resourceDC = found;
            D_800E2830->field58 = 1;
        }
        Cache_UnlockResource(0, table);
    }
}

s32 Track_RequestTrackByKey(s32 key) {
    s32 size;
    s32 **table;
    s32 loaded;
    s32 i;
    s32 n;
    EntryRecAt48 *entries;

    if (D_800DE7E8 == 0) {
        return 0;
    }
    loaded = SetN64_LocatePackSection(D_8011FEFC, D_8011BDFC, 0, &size);
    if (loaded == 0) {
        table = 0;
    } else {
        table = Cache_RequestResource(0, loaded, loaded, size, 0x33, 0, 0, g_cinemaDirectoryText, 1);
    }
    i = 0;
    entries = (EntryRecAt48 *)(*table + 2);
    n = *D_8011FEFC - 1;
    for (; i < n; i++) {
        if (entries[i].id8 == key) {
            if ((entries[i].flags & 3) == 0) {
                D_800E2830->targetD8 = entries[i].id0;
            }
            D_800E2830->requestE0 = key;
            D_800E2830->resourceDC = i;
            D_800E2830->field58 = 1;
            break;
        }
    }
    Cache_UnlockResource(0, table);
    Cinema_ClearMessageCount();
    return D_800E2830->targetD8;
}

void Track_RequestTrackByName(char *name) {
    s32 size;
    s32 **table;
    s32 loaded;
    s32 i;
    s32 id;
    s32 n;
    EntryRecAt18V5 *entries;

    if (D_800DE7E8 != 0) {
        loaded = SetN64_LocatePackSection(D_8011FEFC, D_8011BDFC, 0, &size);
        if (loaded == 0) {
            table = 0;
        } else {
            table = Cache_RequestResource(0, loaded, loaded, size, 0x33, 0, 0, g_cinemaDirectoryText, 1);
        }
        i = 0;
        entries = (EntryRecAt18V5 *)(*table + 2);
        n = *D_8011FEFC - 1;
        for (; i < n; i++) {
            if (((s32 (*)(char *, char *))SetN64_CompareByteStrings)(name, entries[i].name) == 0) {
                D_800E2830->requestE0 = entries[i].id8;
                id = entries[i].id0;
                D_800E2830->resourceDC = i;
                D_800E2830->field58 = 1;
                D_800E2830->targetD8 = id;
                break;
            }
        }
        Cache_UnlockResource(0, table);
    }
}

s32 Track_HasNoTrackRequestItems(void) {
    s32 found;
    s32 *track;
    Triple *refs;
    ItemRecAt12 *item;
    s32 i;
    s32 n;
    s32 hit;

    Shared_World *tables;
    found = 0;
    track = SetN64_GetPackSection(D_800E2830->resource, 2);
    n = track[1];
    refs = (Triple *)(track + 2);
    for (i = 0; i < n; i++) {
        tables = &g_world;
        if (refs[i].y == 0) {
            item = &((ItemRecAt12 *)tables->recordArray)[refs[i].z];
        } else {
            item = &((ItemRecAt12 *)tables->alternateRecordArray)[refs[i].z];
        }
        hit = 0;
        switch (item->kind) {
            case 1:
                if (item->subkind == 5) {
                    hit = 1;
                }
                break;
            case 9:
                if (item->subkind == 4) {
                    hit = 1;
                }
                break;
            case 10:
                if (item->subkind == 3) {
                    hit = 1;
                }
                break;
            default:
                hit = 0;
                break;
        }
        if (hit) {
            found = 1;
        }
    }
    return found ^ 1;
}

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_constants_80402BA0_E1854_us_rev1.c */
const unsigned int D_blob_a5ffcbf0d25acc16f622[2] = {
    0x4F000000, 0x4F000000,
};
#endif
