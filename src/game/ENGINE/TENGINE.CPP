#include "include_asm.h"
#include "COMMON/PAKQUEUESTATE.H"
#include "TEXTURE/80294C64.H"

#if defined(VERSION_US_REV1)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENTSTATE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WORLD.H"
#include "RENDER_4/8028FD2C_6.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "sdk/AUDIO/802BD1A8_19.H"
#include "TYPES.H"
#include "stddef.h"
u32 Render_LocatePackSection(s32, s32, s32, u32 *);
s32 func_802BD400_de(const char *);
extern s32 D_00295B90_us_rev1;
/* Separate-object views of the menu state words (each access has its own lui; DATA-FRAME-O1 F2b). */
extern struct Node80253610 *D_8014AECC;
extern s32 D_8014AED0;
extern s32 D_8014AED4;
/* Releases the previous texture viewer entry, loads entry D_8014AEB0.selectionIndex from the resident pack,
   wraps the frame selection into its texture/palette tables and prints the "tex N frm F of C" title. */
void Engine_LoadSelectedTexture(void) {
    u32 size;
    u32 key;
    struct Node80253610 *resource;
    s32 *entries;
    s32 *textures;
    s32 *palettes;
    s32 texture;
    s32 palette;
    s32 frame;
    u8 *name;
    s32 i;
    Shared_World *world = &D_8011FE88;

    if (D_8014AECC != NULL) {
        Scene_UnlockResource(NULL, D_8014AECC);
    }
    D_8014AECC = NULL;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    key = Render_LocatePackSection(world->unk50, world->unk20, D_8014AEB0.selectionIndex, &size);
    resource = Scene_RequestResource(0, key - 1, key, size, 9, -1, &D_00295B90_us_rev1, "Artsend Texture", 1);
    entries = (s32 *)resource->field0;
    textures = Render_GetPackSection(entries, 1);
    palettes = Render_GetPackSection(entries, 2);
    while (D_8014AEB0.selectionValue < 0) {
        D_8014AEB0.selectionValue += *textures;
    }
    texture = D_8014AEB0.selectionValue % *textures;
    palette = D_8014AEB0.selectionValue % *palettes;
    D_8014AEB0.resource = resource;
    D_8014AEB0.textureOverride = Render_GetPackSection(textures, texture);
    D_8014AEB0.paletteOverride = Render_GetPackSection(palettes, palette);
    D_8014AEB0.selector = Render_GetPackSection(entries, 0);
    D_8014AEB0.overridesOff = 0;
    D_8014AEB0.entryTable = entries;
    D_8014AEB0.textureTable = textures;
    D_8014AEB0.paletteTable = palettes;
    frame = texture;
    if (*entries == 4) {
        name = Render_GetPackSection(entries, 3);
        for (i = 0; i < func_802BD400_de((char *)name); i++) {
            if (name[i] == '.') {
                name[i] = '\0';
                break;
            }
        }
        func_802BD320_de(D_8014AEB0.displayData, "tex %d frm %d of %d, %s", D_8014AEB0.selectionIndex, frame,
                         *textures, name);
    } else {
        func_802BD320_de(D_8014AEB0.displayData, "tex %d frm %d of %d", D_8014AEB0.selectionIndex, texture,
                         *textures);
    }
    D_8014AEB0.frameCount = 0;
}
#endif

#if defined(VERSION_US_REV1)
/* Handles repeated menu navigation inputs and draws the current menu display.
 * The index/value/changed words form the contiguous selection record; named globals
 * and owner fields provide views of that same menu state. */
#include "COMMON/RESIDENTSTATE.H"
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/CHANNEL.H"

struct MenuGlobalRecAt21B8;

struct SelectionRecAt8;

struct Message;
extern struct MenuGlobalRecAt21B8 D_8014AEB0;
extern s32 D_8014AEC0;


void func_80294F1C_us_rev1(void) {
    f32 scale;
    s32 temp_a0;
    s32 regpart_temp_a0; 
    s32 count_0;
    s32 count_1;
    s32 count_2;
    s32 count_3;
    s32 count_4;
    s32 count_5;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_10; 
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_v1;
    s32 var_v1_2;
    s32 minusOne; 
    struct SelectionRecAt8 *selection; 


    if (D_800D2AE0 != 0) {
        if (D_8010F328[0].buttons & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0.alternateTitle == 0) {
                    Camera_PostScreenMessage(&D_80145088, (u8 *)&D_80145088 + 0x40, D_800CA60C);
                    D_8014AEB0.titleWasShown = 1;
                } else {
                    Camera_PostScreenMessage(&D_80145088, (u8 *)&D_80145088 + 0x40, D_auto_800CA620);
                }
                D_auto_800D2AFC = 1;
                D_8014AEB0.alternateTitle = (u8) ((u8) D_8014AEB0.alternateTitle < 1U);
            }
        } else {
            D_auto_800D2AFC = 0;
        }
        if (D_8010F328[0].buttons & 0x2000) {
            if (D_8010F328[0].buttons & 0x200) {
                count_0 = D_800D2AEC;
                temp_v1 = count_0; 
                count_0 += 1;
                D_800D2AEC = count_0;
                if (temp_v1 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AEC = 0;
                    D_8014AEC0 -= 1;
                }
            }
            if (D_8010F328[0].buttons & 0x100) {
                count_1 = D_800D2AF0;
                temp_v1_2 = count_1; 
                count_1 += 1;
                D_800D2AF0 = count_1;
                if (temp_v1_2 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AF0 = 0;
                    D_8014AEC0 += 1;
                }
            }
        } else {
            if (D_8010F328[0].buttons & 0x200) {
                count_2 = D_auto_800D2AE4;
                temp_v1_3 = count_2; 
                count_2 += 1;
                D_auto_800D2AE4 = count_2;
                if (temp_v1_3 >= 3) {
                    minusOne = D_8014AEBC;
                    minusOne -= 1;
                    temp_v0_2 = minusOne + D_8014AEB8.unk0;
                    var_v1 = temp_v0_2 % D_8014AEB8.unk0;
                    D_8014AEB0.titleWasShown = 1;
                    ((struct SelectionRecAt8 *)&D_8014AEBC)->index = minusOne;
                    D_8014AEBC = var_v1;
                    if ((f32) var_v1 < 0.0f) {
                        var_v1 = -var_v1;
                    }
                    D_8014AEB0.selectionIndex = var_v1;
                    D_auto_800D2AE4 = 0;
                }
            }
            if (D_8010F328[0].buttons & 0x100) {
                count_3 = D_auto_800D2AE8;
                temp_v1_4 = count_3; 
                count_3 += 1;
                D_auto_800D2AE8 = count_3;
                if (temp_v1_4 >= 3) {
                    temp_v1_5 = D_8014AEBC + 1;
                    temp_a0 = temp_v1_5 % D_8014AEB8.unk0;
                    D_auto_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_5; 
                    D_8014AEBC = temp_a0;
                }
            }
            if (D_8010F328[0].buttons & 0x400) {
                count_4 = D_auto_800D2AF4;
                temp_v1_7 = count_4; 
                count_4 += 1;
                D_auto_800D2AF4 = count_4;
                if (temp_v1_7 >= 3) {
                    regpart_temp_a0 = D_8014AEBC - 5;
                    temp_v0_3 = regpart_temp_a0 + D_8014AEB8.unk0;
                    var_v1_2 = temp_v0_3 % D_8014AEB8.unk0;
                    D_8014AEB0.selectionIndex = regpart_temp_a0;
                    selection = (struct SelectionRecAt8 *)&D_8014AEBC;
                    D_8014AEBC = var_v1_2;
                    if ((f32) var_v1_2 < 0.0f) {
                        var_v1_2 = -var_v1_2;
                    }
                    selection->index = var_v1_2;
                    selection->changed = 1;
                    D_auto_800D2AF4 = 0;
                }
            }
            if (D_8010F328[0].buttons & 0x800) {
                count_5 = D_auto_800D2AF8;
                temp_v1_8 = count_5; 
                count_5 += 1;
                D_auto_800D2AF8 = count_5;
                if (temp_v1_8 >= 3) {
                    temp_v1_9 = D_8014AEBC + 5;
                    temp_a0 = temp_v1_9 % D_8014AEB8.unk0;
                    D_auto_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_9; 
                    D_8014AEBC = temp_a0;
                }
            }
        }
        D_8014AEB0.frameCount += 1;
        if (D_8014AEB0.titleWasShown != 0) {
            Engine_LoadSelectedTexture();
            D_8014AEB0.titleWasShown = 0;
        }
        func_802A84F8_de();
        scale = D_auto_800CA634;
        func_802A8710_de();
        func_802AAB68_de(scale, scale);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de((char *)&D_8014AEB0.displayData, 0x10, D_800E28D4 - 0x30, 0xFF, 0, 0, scale, scale);
    }
}
#endif
