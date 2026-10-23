#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "FRONTEND/8041BEA8_6.H"

#if defined(VERSION_DE)
INCLUDE_ASM("ovl_80400000", func_8041C614);
#endif
#if !(defined(VERSION_DE))
#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
extern u8 D_800DD460_de[], D_800DD474[];
extern void *func_8028FE28_de(void *, void *, s32);
extern void *func_8028FE3C_de(void *, void *, s32, s32 *);
extern void *func_8028CF6C_de(void *, u16);
extern void func_80246BE8_de(void *, void *, void *, s32);
void func_8041C610_de(struct Unk8041CE88 *arg0, s32 id, s32 extra, s32 expected) {
    u8 *world = (u8 *)&D_8011FE88;
    u8 *out = (u8 *)arg0 + 0x190;
    u16 *list = *(u16 **)(world + 0x94);
    s32 count = *(s32 *)((u8 *)list + 4);
    s32 i = 0;
    s32 found = 0;
    u16 *entry = (u16 *)((u8 *)list + 8);
    void *name;
    void **first;
    void **second;
    void *resource;
    u8 *record;
    s32 size;
    if (count <= 0) {
        return;
    }
    do {
        if (*entry == id) {
            name = func_8028FE28_de(*(void **)(world + 0x54), *(void **)(world + 0x24), i);
            first = func_8025193C_de(0, (u32)name, (u32)name, 0x18, 0, 0, 0, (const char *)D_800DD460_de, 1);
            if (first != 0) {
                resource = func_8028FE3C_de(*first, name, 0, &size);
                second = func_8025193C_de(0, (u32)resource, (u32)resource, size, 0, 0, 0, (const char *)D_800DD474, 1);
                if (second != 0) {
                    record = func_8028CF6C_de(world, *(u16 *)((u8 *)func_8028FDB4_de(*second, 0) + 0x1C));
                    if (*(s16 *)(record + 0xC) == expected && *(s32 *)record == *(s32 *)arg0) {
                        *(s16 *)(out + 4) = i;
                        *(u16 *)(out + 0xE4) = id;
                        func_80246BE8_de(out, *(void **)(world + 0x54), *(void **)(world + 0x24), extra);
                        found = 1;
                    }
                    func_80253754_de(0, second);
                }
                func_80253754_de(0, first);
            }
        }
        i++;
        entry++;
    } while (i < count && !found);
}
#else
INCLUDE_ASM("ovl_80400000", func_8041C610_de);
#endif
#endif

#ifdef NON_MATCHING
/* The names m2c output assumes (its valid-syntax macros), so a draft compiles on its own. */
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
#define M2C_FIELD(base, type, offset) (*(type)((char *)(base) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK(...) (0)
#define M2C_SYNC(...) (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#undef F3DEX_GBI
#undef F3D_GBI
#define F3DEX_GBI_2
#endif
#include "COMMON/GFX.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/TRIPLE.H"
#include "MENU/GFX/80414430_19.H"
#include "TYPES.H"
#include "gbi.h"
#include "particle/80271B18_3.H"
s32 func_80246E44_de(void *);
s32 func_80249E28_de(void *, void *);
s32 func_8024B8C4_de(void *);
s32 func_802737F0_de(void *, f32);
extern MenuModelScreen D_80141008[];
void func_8041C7F4_de(Obj8041CAD8 *self) {
    CVector3 local10;
    CVector3 local20;
    MenuModelScreen *view;
    Obj8041CAD8At190 *draw;
    s32 saved;
    view = D_80141008;
    draw = &self->sub190;
    if (self->unk478 != 0) {
        saved = D_800CC380;
        D_800CC380 = 0;
        {
            Gfx *g = D_80110634++;
            char *address = (char *)(u32)(D_800D297C << 6);
            address += 0x380;
            address += (u32)view;
            gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);
        }
        local10 = self->unk48C;
        func_80272898_de(&view->camera, &local10, &local20);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1);
        }
        func_80417138_de(0x33335);
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
        gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
        gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
        func_8026D844_de();
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        func_8024B8C4_de(draw);
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        if (self->unk49C != 0 || draw->unk10E == 0) {
            func_80246E44_de(draw);
            if (self->unk4A0 != 0) {
                func_802737F0_de(&draw->unk74, (f32)self->unk4A0 * D_800DD488);
            }
        }
        draw->unk6C = self->unk498 * *(&D_800DD488 + 1);
        draw->unk8 = local20;
        draw->unk1C4 = local20;
        func_8026D980_de();
        func_80249E28_de(draw, view);
        draw->unk140 = D_800DF520;
        draw->unk158 = D_800DF520;
        func_8026D9D0_de();
        D_800CC380 = saved;
    }
}

#include "COMMON/WORLD.H"
#include "RESMGR/802A0888.H"
extern s32 D_800D297C, D_800E28D0, D_800E28D4;
extern s32 D_800CD8D0;
extern void *func_8028CFA0_de(void *, s32, s32, void *);
extern void func_802466A0_de(void *, s32, s32, s32, void *, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);
extern void func_8024B2D0_de();
#ifdef NON_MATCHING
/* 31/182 aligned edits; remaining: register allocation of the setup prologue (s0/s2/s3 roles) */
void *Frontend_InitModelPreview(Obj8041CAD8 *self, s32 id, s32 arg2, s32 arg3, s32 arg4, CVector3 position, CVector3 facing,
                       f32 scale, s32 arg8) {
    CVector3 scales;
    CVector3 local60;
    CVector3 local70;
    CVector3 local80;
    MenuModelScreen *view;
    Obj8041CAD8At190 *draw;
    Gfx *g;
    char *address;
    f32 ratio;
    Ret8028CFA0 *source;
    address = (char *)(u32)(D_800D297C << 6);
    self->unk4A0 = arg8;
    func_802A001C_de(&local60, 0, 0xC);
    g = D_80110634++;
    draw = &self->sub190;
    address += 0x380;
    view = D_80141008;
    self->unk49C = 1;
    address += (u32)view;
    gSPMatrix(g, (u32)address, G_MTX_LOAD | G_MTX_PROJECTION);
    source = func_8028CFA0_de(&D_8011FE88, id, arg2, g);
    if (source == 0) {
        self->unk478 = 0;
        return 0;
    }
    self->unk0 = id;
    self->unk478 = 1;
    self->unk498 = scale;
    self->copy4 = *source;
    self->unk480 = position;
    self->unk48C = facing;
    self->copy4.unk0 = 0;
    self->copy4.unk4 = 0;
    self->copy4.unk14 = 0;
    self->copy4.unk18 = 0;
    self->copy4.unk1C = 0;
    self->copy4.unk8 = D_800DD490_de;
    ratio = view->width / (f32)D_800E28D0;
    scales.x = self->unk480.x * ratio;
    scales.z = self->unk480.z * ratio;
    scales.y = self->unk480.y * (view->height / (f32) * (&D_800E28D0 + 1));
    draw->unk50 = scales;
    local70 = self->unk48C;
    func_80272898_de(&view->camera, &local70, &local80);
    func_802466A0_de(draw, -1, arg3, D_800CD8D0, &self->copy4, -1, 0, self->unk498 * *(&D_800DD490_de + 1), local80, 0,
                     self->unk480, local60, 0);
    func_8024B2D0_de(draw);
    if (self->unk0 == 9) {
        func_8041CE18_de(self, arg3, arg4, arg2);
    }
    return &self->copy4;
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_InitModelPreview);
#endif

/* Copies the three-word vector passed by value into the object's vector at 0x480. */





void func_8041CDB0_de(ObjRecAt480 *arg0, CVector3 v) {
    arg0->unk480 = v;
}

/* Copies the three-word vector passed by value into the object's vector at 0x48C. */





void func_8041CDDC_de(ObjRecAt48C *arg0, CVector3 v) {
    arg0->unk48C = v;
}

/* Stores arg1 into the word at 0x498 of the object arg0. */



void func_8041CE08_de(ObjRecAt498 *arg0, s32 arg1) {
    arg0->unk498 = arg1;
}

/* Stores a value into the word at offset 0x49C of an object; func_80420618_de and func_8043AB40_de call
   it with zero, Frontend_InitModelPreview writes the same word directly and func_8041C7F4_de reads it. */


void func_8041CE10_de(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Sets field 0x274 of arg0 to 0xFFFF and then calls func_8041C610_de on it, passing its other three arguments through. */
void func_8041CE18_de(Unk8041CE88 *arg0, s32 id, s32 extra, s32 expected) {
    arg0->unk274 = 0xFFFF;
    func_8041C610_de(arg0, id, extra, expected);
}

#if defined(VERSION_US)
unsigned int func_8041CEA8_us_padding_180EA8[2] = {
    0x35657175, 0xD60F0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8041D278_eu_x_padding_10D278[2] = {
    0x0C1077AB, 0x2404006E,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8041D278_eu_padding_193278[2] = {
    0x00021200, 0x00621825,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8041CE38_de_padding_182E38[2] = {
    0x24423834, 0x08102BBC,
};
#endif
