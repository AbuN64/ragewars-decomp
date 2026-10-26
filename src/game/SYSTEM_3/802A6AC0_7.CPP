#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SYSTEM_3/802A6AC0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_2.H"
#include "AUDIO_3/802BFF30.H"
#include "RENDER/80291054_6.H"
#include "SYSTEM_3/802A6AC0_7.H"
#include "RESMGR/802A0888.H"
#include "GFX/TEXT/802A8A94_5.H"

static inline void toggle(ToggleMenu *menu, MenuItem *item) {
    if ((item->on = !item->on) != 0) {
        item->bounce = 5;
        item->startFrame = menu->frame;
        item->value = item->restoreValue;
        item->extra = item->restoreExtra;
    } else {
        item->bounce = -5;
    }
}

/* Clears a record: its four 0x38-byte entries through an inline per-entry clear, its two leading
   flag bytes and trailing words, and sets the word at 0xE6 to -5. */
static inline void clear_entry(EntryRecAt34 *e) {
    e->unk4 = 0;
    e->unk0 = 0;
    e->unkD = 0;
    e->unk18 = 0;
    e->unk1C = 0;
}

/* Soft-resets the game: checks the "systembootdone" marker (copied from s_systembootdoneText and zero-padded with the memset Resmgr_FillMemory) through func_80293440_de (recording the result in D_801470B0 and re-arming it through func_802934C0_de), and on a cold boot copies the resident code and data back from the cartridge word by word after each PI idle wait, then clears the BSS from D_800E4000 to D_80166000, in both passes skipping the marker, its flag and, when not cold booting, the preserved save, settings and pad regions; finally reinitialises through func_802BAE40_de and func_80292F24_de. */
extern Marker_func_802A71C0_de s_systembootdoneText;


extern char D_800CDD10;

extern s32 D_801470B0;

#include "COMMON/ACTORRECAT5E0.H"


extern char D_800F91F0;

extern char D_800F41F0;

extern s32 D_800E4000;

extern s32 D_80166000;

extern void Render_CopyString(char *marker, char *name);

static inline s32 is_restorable(u32 address) {
    if (address >= (u32)&D_800CDD10 && address < (u32)&D_800CDD10 + 0x10) {
        return 0;
    }
    if (address == (u32)&D_801470B0) {
        return 0;
    }
    if (D_801470B0 != 0) {
        return 1;
    }
    if (address >= (u32)&D_8010BC40 && address < (u32)&D_8010BC40 + 0x430) {
        return 0;
    }
    if (address >= (u32)&D_801462C8 && address < (u32)&D_801462C8 + 0x584) {
        return 0;
    }
    if (address >= (u32)&D_800F91F0 && address < (u32)&D_800F91F0 + 0x5800) {
        return 0;
    }
    if (address >= (u32)&D_800F41F0 && address < (u32)&D_800F41F0 + 0x5000) {
        return 0;
    }
    if (address >= (u32)&D_801462C8 + 0x5D8 && address <= (u32)&D_801462C8 + 0x688) {
        return 0;
    }
    return 1;
}


/* Draw active toggle-menu items in activation order, then draw the open menu
* with a pulsing highlight on its selected item. */
void func_802A6900_de(ToggleMenu *panel, Input_func_802A65E0_de *player) {
    MenuItem *sorted[4];
    s32 width;
    s32 height;
    MenuItem *slot;
    MenuItem *first;
    MenuItem *second;
    f32 *view;
    s32 i;
    s32 swapped;
    s32 n;
    s16 magnitude;
    s32 pulse;
    s16 r, g, b;
    f32 spacing;
    f32 opacity;
    f32 sx, sy;
    f32 x, y;
    f32 unit;
    f32 colorScale;
    f32 fadeStep;
    f32 grid;
    f32 origin;
    s32 row;
    f32 factor;

    spacing = 0.0f;
    for (i = 0; i < 4; i++) {
        sorted[i] = &panel->items[i];
    }
    do {
        swapped = 0;
        for (i = 0; i < 3; i++) {
            first = sorted[i];
            second = sorted[i + 1];
            if ((u32)first->startFrame > (u32)second->startFrame) {
                swapped = 1;
                sorted[i] = second;
                sorted[i+1] = first;
            }
        }
    } while (swapped);
    r = g = b = 255;
    i = 0;
    n = i;
    colorScale = 255.0f;
    fadeStep = 0.1f;
    grid = 0.25f;
    origin = 0.75f;
    unit = 0.5f;

    view = player->view->viewport;
    sx = view[0] * 0.0015625f;
    sy = view[1] * 0.0020833334f;
    for (i = 0; i < 4; i++) {
        slot = sorted[i];
        magnitude = slot->bounce;
        if ((f32)magnitude < 0.0f) {
            magnitude = -magnitude;
        }
        if (slot->active && (slot->on || magnitude != 0)) {
            func_802AA950_de(slot->image, slot->imageFrame, &width, &height);
            if (width != 0) {
                opacity = (magnitude != slot->bounce ? (f32)magnitude : (f32)(5-magnitude)) * fadeStep;
                row = n;
                if (n < 0) {
                    row = n + 3;
                }
                row >>= 2;
                x = view[2] + view[0]*unit + ((origin - (f32)(n-row*4)*grid)+spacing)*unit*view[0];
                y = view[3] + view[1]*unit + (origin - (f32)(row))*unit*view[1];
                gDPSetEnvColor(g_displayListCursor++, r, g, b, opacity*colorScale);
                func_802AAC28_de(slot->image, slot->imageFrame,
                (s16)(s32)(x-(f32)width*sx*unit),
                (s16)(s32)(y-(f32)height*sy*unit), sx, sy, 1);
                if (magnitude != slot->bounce && opacity < grid) {
                    spacing += grid - opacity;
                }
                n++;
            }
        }
    }
    if (panel->state) {
        i = 0;
        n = i;
        unit = 0.5f;

        sx = view[0]*0.003125f;
        colorScale = (f32)(panel->timer*51);
        sy = view[1]*0.004166667f;
        for (i = 0; i < 4; i++) {
            slot = &panel->items[i];
            if (slot->active) {
                func_802AA950_de(slot->image, slot->imageFrame, &width, &height);
                if (width != 0) {
                    row = n;
                    if (n < 0) {
                        row = n + 3;
                    }
                    row >>= 2;
                    x = view[2]+view[0]*unit+((2.0f*(f32)(n-row*4)*0.25f)+-0.75f)*unit*view[0];
                    y = view[3]+view[1]*unit+((2.0f*(f32)(row))+-0.5f)*unit*view[1];
                    if (i == panel->selected) {
                        pulse = panel->blink;
                        factor = (f32)((((f32)pulse < 0.0f ? -pulse : pulse) * 191) / 5 + 64);
                        opacity = factor * 0.00390625f;
                        r = 255;
                        g = 255;
                        b = 255;
                    } else {
                        r = 128;
                        g = 128;
                        b = 128;
                        opacity = unit;
                    }
                    gDPSetEnvColor(g_displayListCursor++, r, g, b, opacity*colorScale);
                    n++;
                    func_802AAC28_de(slot->image, slot->imageFrame,
                    (s16)(s32)(x-(f32)width*sx*unit),
                    (s16)(s32)(y-(f32)height*sy*unit), sx, sy, 1);
                }
            }
        }
    }
}

void func_802A6F68_de(CItemMenu *rec) {
    int i;
    for (i = 0; i < 4; i++) {
        clear_entry(&rec->entries[i]);
    }
    rec->unk0 = 0;
    rec->m_ModePos = 0;
    rec->m_LastItemPos = 0;
    rec->m_ItemAlphaFade = -5;
    rec->m_FrameCount = 0;
}

/* Finds or allocates one of four records and updates its parameters. */
s32 func_802A6FB8_de(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 var_a1;
    u32 key;
    char *temp_v1;
    EntryRecAt34 *var_v1;
    EntryRecAt34 *var_v1_2;
    var_a1 = 0;
    key = arg2 & 0xFFFF;
    for (var_a1 = 0; var_a1 < 4; var_a1++) {
        if (((CItemMenu *)arg0)->entries[var_a1].unk0 != 0 &&
            ((CItemMenu *)arg0)->entries[var_a1].unkC == key) {
            break;
        }
    }
    if (var_a1 == 4) {
        for (var_a1 = 0; var_a1 < 4; var_a1++) {
            if (((CItemMenu *)arg0)->entries[var_a1].unk0 == 0) {
                break;
            }
        }
        if (var_a1 == 4) {
            return 0;
        }
    }
    temp_v1 = arg0 + ((var_a1 * 0x38) + 4);
    ((CItemMenu *)arg0)->m_LastItemPos = var_a1;
    ((EntryRecAt34 *)(temp_v1))->unk0 = 1;
    ((EntryRecAt34 *)(temp_v1))->unk8 = arg1;
    ((EntryRecAt34 *)(temp_v1))->unkC = arg2;
    ((EntryRecAt34 *)(temp_v1))->unk10 = arg3;
    ((EntryRecAt34 *)(temp_v1))->unk14 = arg4;
    ((EntryRecAt34 *)(temp_v1))->unk28 = arg5;
    ((EntryRecAt34 *)(temp_v1))->unk2C = arg6;
    ((EntryRecAt34 *)(temp_v1))->unk30 = arg7;
    ((EntryRecAt34 *)(temp_v1))->unkD = (u8) (((EntryRecAt34 *)(temp_v1))->unkD + 1);
    ((EntryRecAt34 *)(temp_v1))->unk34 = arg8;
    return 1;
}

s32 func_802A7098_de(void *arg0)
{
  s32 var_a1;
  s32 var_a2;
  s8 *new_var;
  var_a2 = 0;
  var_a1 = 3;
  do
  {
    new_var = ((s8 *) (arg0 + ((((struct OwnerRecAtE4 *)(arg0))->id) * 0x38))) + 4;
    if ((*((s32 *) new_var)) != 0)
    {
      var_a2 += 1;
    }
    var_a1 -= 1;
  }
  while (var_a1 >= 0);
  return var_a2 != 0;
}

/* Moves a menu's cursor at 0xE4 over its four 0x38-byte entries, forward when arg1 is zero and backward otherwise, wrapping around and skipping entries whose word at 0x4 is zero; returns the entry landed on. */
s32 func_802A70D4_de(MenuCode802A6AC0 *menu, s32 backward) {
    u16 cursor;
    if (backward == 0) {
        do {
            menu->cursor++;
            menu->cursor %= 4;
        } while (menu->entries[menu->cursor].active == 0);
        return menu->cursor;
    }
    do {
        cursor = --menu->cursor;
        if (cursor >= 4) {
            cursor = 3;
        }
        menu->cursor = cursor;
    } while (menu->entries[cursor].active == 0);
    return cursor;
}

void func_802A7168_de(EntryRecAt34 *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unkD = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
}

void func_802A7180_de(void *arg0, void *arg1) {
    s32 temp_v0;
    temp_v0 = (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_4) == 0;
    (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_4) = temp_v0;
    if (temp_v0 != 0) {
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_18) = 5;
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_1C) = (s32) (((struct State_func_8042D8C4_de *) ((s8 *) arg1))->count);
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_20) = (f32) (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_28);
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_24) = (s32) (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_2C);
        return;
    }
    (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_18) = -5;
}

s32 func_802A71C0_de(void) {
    u32 *src;
    u32 *dst;
    s32 count;
    u32 status;
    u32 *piStatus;
    char name[16];
    *(Marker_func_802A71C0_de *)name = s_systembootdoneText;
    Resmgr_FillMemory(&name[15], 0, 1);
    if (((s32 (*)(char *, char *))func_80293440_de)(&D_800CDD10, name) == 0) {
        D_801470B0 = 0;
    } else {
        D_801470B0 = 1;
        Render_CopyString(&D_800CDD10, name);
    }
    if (D_801470B0 == 0) {
        src = (u32 *)0xB0001000;
        dst = (u32 *)0x80000400;
        piStatus = (u32 *)0xA4600010;
        count = 0x3FFFF;
        do {
            status = *piStatus & 3;
            while (status != 0) {
            }
            if (is_restorable((u32)dst | 0x80000000)) {
                *dst = *src;
            }
            dst++;
            src++;
        } while (count-- != 0);
    }
    for (dst = (u32 *)&D_800E4000; (u32)dst < (u32)&D_80166000; dst++) {
        if (is_restorable((u32)dst | 0x80000000)) {
            *dst = 0;
        }
    }
    func_802BAE40_de();
    func_80292F24_de();
    return 0;
}

void func_802A754C_de(void) {
}

s32 func_802A7554_de(u32 address) {
    address |= 0x80000000;
    if (((address) >= (u32)&(D_800CDD10) && (address) < (u32)&(D_800CDD10) + (0x10)) || address == (u32)&D_801470B0) {
        return 0;
    }
    if (D_801470B0 != 0) {
        return 1;
    }
    if (((address) >= (u32)&(D_8010BC40) && (address) < (u32)&(D_8010BC40) + (0x430))) {
        return 0;
    }
    if (((address) >= (u32)&(D_801462C8) && (address) < (u32)&(D_801462C8) + (0x584))) {
        return 0;
    }
    if (((address) >= (u32)&(D_800F91F0) && (address) < (u32)&(D_800F91F0) + (0x5800))) {
        return 0;
    }
    if (((address) >= (u32)&(D_800F41F0) && (address) < (u32)&(D_800F41F0) + (0x5000))) {
        return 0;
    }
    if (address >= (u32)&D_801462C8.counters && address <= (u32)&D_801462C8.counters + 0xB0) {
        return 0;
    }
    return 1;
}

void func_802A7654_de(void) {
}
