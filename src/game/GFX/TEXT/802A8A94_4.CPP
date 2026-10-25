#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "GFX/802A8A94.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "RESMGR/802A2230_6.H"
#include "SYSTEM/80296FF8_6.H"

s32 func_802A7AA4_de(void *);

extern s32 D_800CDEB4;

s32 func_802AA70C_de(void *, s32 *);

extern s32 D_800CDEC8;

extern int func_802A23B4_de(void);

extern void Text_SetupSpriteMode(s32);

extern void func_802A7660_de(void *arg0, int arg1);


extern f32 D_800CB3A8;

extern f32 D_800CB3B0;

extern f32 D_800C6214_de;

extern f32 D_800C621C_de;

extern f32 D_800C6224_de;

void func_802AA6D0_de(void *arg0, s16 arg1, s16 arg2)
{
  Mover *mover = arg0;
  mover->handle = -1;
  mover->active = 0;
  mover->state = 0;
  mover->x = (f32) arg1;
  mover->y = (f32) arg2;
}

s32 func_802AA70C_de(void *widget, s32 *arg1) {
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_4) = arg1;
    (((struct ObjectLinksC_2 *) ((s8 *) widget))->unk_8) = 2;
    return func_802A7AA4_de(widget);
}

s32 func_802AA730_de(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_40) = arg1;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_3C) = arg2;
    (((struct IntegerState48 *) ((s8 *) arg0))->unk_44) = 0x64;
    return func_802AA70C_de(arg0, &D_800CDEB4);
}

void func_802AA760_de(void *arg0, s32 arg1, s32 arg2) {
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_88) = arg1;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_84) = arg2;
    (((struct IntegerState90 *) ((s8 *) arg0))->unk_8C) = 0x64;
    func_802AA70C_de(arg0 + 0x48, &D_800CDEC8);
}

void func_802AA794_de(char *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[0].target = value;
}

void func_802AA79C_de(void *object, int value) {
    Hud *hud = (void *)object;
    hud->bars[1].target = value;
}

void func_802AA7A4_de(void *arg0) {
    char pad[256];
    (void)pad;

    if (func_802A23B4_de() == 1) {
        func_802A2090_de();
        func_8026D8F8_de();
        System_ResetTextureCache();
    }
    func_802A84F8_de();
    func_802A8710_de();
    func_802AAB68_de(D_800C61F0_de, D_800C61F0_de);
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    Text_SetupSpriteMode(D_801462C8.hudFade);
    if (((Hud *)arg0)->bars[0].enabled != 0) {
        func_802A7660_de(arg0, 1);
    }
    if (((Hud *)arg0)->bars[1].enabled != 0) {
        func_802A7660_de(arg0, 2);
    }
}

/** Return the floating parameter selected by the current global mode. */
f32 func_802AA864_de(void) {
    {
        s32 sw_mode_value = D_80147150;
        if ((unsigned int)sw_mode_value > 6) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_3;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_4;
        case 6: goto sw_mode_2;
        }
    }
    do {
    sw_mode_0:
        return D_800C6214_de;
    sw_mode_1:
        return D_800CB3A8;
    sw_mode_2:
    sw_mode_6:
        return D_800C621C_de;
    sw_mode_3:
        return D_800CB3B0;
    sw_mode_4:
    sw_mode_5:
        return D_800C6224_de;
    sw_mode_default:
        return D_800C6228_de;
    
    } while (0);
}

void func_802AA8EC_de(Table802AB8DC **handle, s32 index, void **out, u8 *tag) {
    Table802AB8DC *table;
    Entry802AB8DC *entry;
    void *result;
    u8 entryTag;
    s32 remainder;

    *out = 0;
    if (handle != 0) {
        table = *handle;
        entry = &table->entries[0];
        remainder = index % table->count;
        remainder *= 8;
        remainder += (s32)entry;
        entry = (Entry802AB8DC *)remainder;
        entryTag = entry->pad4[0];
        result = (u8 *)table + entry->offset;
        *tag = entryTag;
        *out = result;
    }
}
