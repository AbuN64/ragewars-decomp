#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/ENTRYRECAT0V3.H"
#include "MENU/80403BCC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "MENU/PAK/80403BCC_4.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

/* Returns one less than the word D_8011FEFC points to. */
extern s32 *D_8011FEFC;

/* Looks up the current menu resource through Render_LocatePackSection from the fields at 0x74 and 0x34 of
   D_8011FE88 and, when found, opens it through Scene_RequestResource as widget 0x33 with the handler table
   g_cinemaDirectoryText; returns the result, or 0 when there is no resource. Matched through a local pointer to the menu. */



extern char g_cinemaDirectoryText[];

extern void *Render_LocatePackSection(int, int, int, int *);


/* Blends two values with cubic weights: with u the pooled constant D_800E0CB0[0] less t, from is
   weighted by u cubed less u and to by t cubed less t. The constant lives in a shared literal
   pool outside this object, so it is read by name. */
extern f32 D_800E0CB0[];

/* Looks up the object at offset 4 of the structure D_800E2830 points to through Render_GetPackSection
   with zero, then looks up the result again with the argument, and returns that. */


extern struct Field_void_4 *D_800E2830;

s32 func_80403BCC_de(void) {
    return *D_8011FEFC - 1;
}

int Pak_RequestTrackBundle(void) {
    int size;
    void *res;
    Shared_World *menu = &g_world;

    res = Render_LocatePackSection((int)menu->trackBundle, menu->trackLookup, 0, &size);
    if (res == 0) {
        return 0;
    }
    return Scene_RequestResource(0, res, res, size, 0x33, 0, 0, g_cinemaDirectoryText, 1);
}

f32 Pak_BlendCubic(f32 from, f32 to, f32 t) {
    f32 u = D_800E0CB0[0] - t;

    return from * (u * u * u - u) + to * (t * t * t - t);
}

f32 Pak_BlendLinear(f32 from, f32 to, f32 weight) {
    return from * (D_800E0CB0[1] - weight) + to * weight;
}

void *Pak_GetPackEntry(s32 key) {
    return Render_GetPackSection(Render_GetPackSection(D_800E2830->value, 0), key);
}

s32 func_80403CFC_de(s32 key) {
    return ((s32 *) Render_GetPackSection(Render_GetPackSection(Render_GetPackSection(D_800E2830->value, 0), key), 2))[0];
}

s32 func_80403D4C_de(s32 key) {
    return ((s32 *) Render_GetPackSection(Render_GetPackSection(Render_GetPackSection(D_800E2830->value, 0), key), 2))[1];
}

void *func_80403D9C_de(s32 key) {
    return Render_GetPackSection(Render_GetPackSection(Render_GetPackSection(D_800E2830->value, 0), key), 1);
}

void func_80403DE8_de(void) {
    Render_GetPackSection(D_800E2830->value, 3);
}

/* Returns whether a record's subtype at 0x12 is the one its kind at 0x11 requires: 5 for kind 1, 4 for
   kind 9 and 3 for kind 10; other kinds give 0. */


int func_80403E10_de(RecordRecAt12 *rec) {
    int result = 0;

    switch (rec->kind) {
    case 1:
        if (rec->subtype == 5) {
            result = 1;
        }
        break;
    case 9:
        if (rec->subtype == 4) {
            result = 1;
        }
        break;
    case 10:
        if (rec->subtype == 3) {
            result = 1;
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

#if defined(VERSION_EU)
unsigned int func_80403E10_de_padding_179E88[2] = {
    0x00000000, 0x00000000,
};
#endif
