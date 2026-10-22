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
s32 func_80249E28_de(void *, s32 *);
s32 func_8024B8C4_de(void *);
s32 func_802737F0_de(void *, f32);
extern s32 D_80141008;

void func_8041C7F4_de(void *arg0) {
    s32 sp24;
    s32 sp28;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp20;
    Gfx *temp_a0;
    Gfx *temp_a0_2;
    Gfx *temp_a1;
    Gfx *temp_a2;
    Gfx *temp_v1;
    s32 temp_s4;
    s32 temp_v0;
    void *temp_s0;

    temp_s0 = arg0 + 0x190;
    if (M2C_FIELD(arg0, s32 *, 0x478) != 0) {
        temp_s4 = D_800CC380;
        D_800CC380 = 0;
        temp_a2 = D_80110634;
        D_80110634 += 8;
        gSPMatrix(temp_a2, (u32) ((D_800D297C << 6) + 0x380 + &D_80141008), G_MTX_LOAD | G_MTX_PROJECTION);
        
        sp10 = M2C_FIELD(arg0, s32 *, 0x48C);
        sp14 = M2C_FIELD(arg0, s32 *, 0x490);
        sp18 = M2C_FIELD(arg0, s32 *, 0x494);
        func_80272898_de(&D_80141008 + 0x160, &sp10, &sp20);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1U);
        }
        func_80417138_de(0x33335);
        temp_a0 = D_80110634;
        temp_v1 = D_80110634 + 8;
        D_80110634 = temp_v1;
        gDPPipeSync(temp_a0);
        
        temp_a0_2 = temp_v1 + 8;
        D_80110634 = temp_a0_2;
        M2C_FIELD(D_80110634, s32 *, 8) = 0xE3000A01;
        temp_a1 = temp_v1 + 0x10;
        temp_v1->words.w1 = 0x100000;
        D_80110634 = temp_a1;
        M2C_FIELD(temp_v1, s32 *, 8) = 0xE3000C00;
        temp_a0_2->words.w1 = 0x80000;
        D_80110634 = temp_v1 + 0x18;
        M2C_FIELD(temp_v1, s32 *, 0x10) = 0xE3001201;
        temp_a1->words.w1 = 0x2000;
        func_8026D844_de(temp_a0_2, temp_a1, 0xE3000C00, 0xE3001201);
        M2C_FIELD(arg0, s32 *, 0x198) = sp20;
        M2C_FIELD(arg0, s32 *, 0x19C) = sp24;
        M2C_FIELD(arg0, s32 *, 0x1A0) = sp28;
        M2C_FIELD(arg0, s32 *, 0x354) = sp20;
        M2C_FIELD(arg0, s32 *, 0x358) = sp24;
        M2C_FIELD(arg0, s32 *, 0x35C) = sp28;
        func_8024B8C4_de(temp_s0);
        M2C_FIELD(arg0, s32 *, 0x198) = sp20;
        M2C_FIELD(arg0, s32 *, 0x19C) = sp24;
        M2C_FIELD(arg0, s32 *, 0x1A0) = sp28;
        M2C_FIELD(arg0, s32 *, 0x354) = sp20;
        M2C_FIELD(arg0, s32 *, 0x358) = sp24;
        M2C_FIELD(arg0, s32 *, 0x35C) = sp28;
        if ((M2C_FIELD(arg0, s32 *, 0x49C) != 0) || (M2C_FIELD(temp_s0, s8 *, 0x10E) == 0)) {
            func_80246E44_de(temp_s0);
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x4A0);
            if (temp_v0 != 0) {
                func_802737F0_de(arg0 + 0x204, (f32) temp_v0 * M2C_FIELD(&D_800DD488, f32 *, 0));
            }
        }
        M2C_FIELD(temp_s0, f32 *, 0x6C) = (f32) (M2C_FIELD(arg0, f32 *, 0x498) * M2C_FIELD(&D_800DD488, f32 *, 4));
        M2C_FIELD(temp_s0, s32 *, 8) = sp20;
        M2C_FIELD(temp_s0, s32 *, 0xC) = sp24;
        M2C_FIELD(temp_s0, s32 *, 0x10) = sp28;
        M2C_FIELD(temp_s0, s32 *, 0x1C4) = sp20;
        M2C_FIELD(temp_s0, s32 *, 0x1C8) = sp24;
        M2C_FIELD(temp_s0, s32 *, 0x1CC) = sp28;
        func_8026D980_de();
        func_80249E28_de(temp_s0, &D_80141008);
        M2C_FIELD(temp_s0, s32 *, 0x140) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0);
        M2C_FIELD(temp_s0, s32 *, 0x144) = (s32) M2C_FIELD(&D_800DF520, s32 *, 4);
        M2C_FIELD(temp_s0, s32 *, 0x148) = (s32) M2C_FIELD(&D_800DF520, s32 *, 8);
        M2C_FIELD(temp_s0, s32 *, 0x14C) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0xC);
        M2C_FIELD(temp_s0, s32 *, 0x150) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0x10);
        M2C_FIELD(temp_s0, s32 *, 0x154) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0x14);
        M2C_FIELD(temp_s0, s32 *, 0x158) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0);
        M2C_FIELD(temp_s0, s32 *, 0x15C) = (s32) M2C_FIELD(&D_800DF520, s32 *, 4);
        M2C_FIELD(temp_s0, s32 *, 0x160) = (s32) M2C_FIELD(&D_800DF520, s32 *, 8);
        M2C_FIELD(temp_s0, s32 *, 0x164) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0xC);
        M2C_FIELD(temp_s0, s32 *, 0x168) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0x10);
        M2C_FIELD(temp_s0, s32 *, 0x16C) = (s32) M2C_FIELD(&D_800DF520, s32 *, 0x14);
        func_8026D9D0_de();
        D_800CC380 = temp_s4;
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8041C7F4_de);
#endif

#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
#define FR_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
#define D_80141008_BYTES ((u8 *)&D_80141008)
extern s32 D_800D297C, D_800E28D0, D_800E28D4;
extern s32 D_800CD8D0;
extern void func_802A001C_de();
extern u8 *func_8028CFA0_de();
extern void func_80272898_de();
extern void func_802466A0_de();
extern void func_8024B2D0_de();
void func_8041CAD8_de(Obj8041CAD8 *arg0, s32 id, s32 arg2, s32 arg3, s32 arg4, CVector3 position, CVector3 facing, f32 scale, s32 arg8) {
    u8 *self = (u8 *)arg0;
    CVector3 local60;
    CVector3 localPos;
    CVector3 localFacing;
    CVector3 local80;
    f32 scaleX;
    f32 scaleY;
    f32 scaleZ;
    u8 *copy;
    u8 *source;
    u8 *drawState;
    u32 *displayList;
    u8 *link;
    s32 i;
    func_802A001C_de(&local60, 0, 0xC);
    displayList = (u32 *)D_80110634;
    D_80110634 = (Gfx *)(displayList + 2);
    displayList[0] = 0xDA380007;
    displayList[1] = (u32)(D_80141008_BYTES + 0x380 + D_800D297C * 64);
    FR_FIELD(self, s32, 0x49C) = 1;
    FR_FIELD(self, s32, 0x4A0) = arg8;
    drawState = self + 0x190;
    source = func_8028CFA0_de(&D_8011FE88, id, arg2, displayList);
    if (source == 0) {
        FR_FIELD(self, s32, 0x478) = 0;
        return;
    }
    FR_FIELD(self, s32, 0) = id;
    FR_FIELD(self, s32, 0x478) = 1;
    FR_FIELD(self, f32, 0x498) = scale;
    for (i = 0; i < 0x188; i++) {
        self[4 + i] = source[i];
    }
    FR_FIELD(self, CVector3, 0x480) = position;
    FR_FIELD(self, CVector3, 0x48C) = facing;
    FR_FIELD(self, s32, 4) = 0;
    FR_FIELD(self, s32, 8) = 0;
    FR_FIELD(self, s32, 0x18) = 0;
    FR_FIELD(self, s32, 0x1C) = 0;
    FR_FIELD(self, s32, 0x20) = 0;
    FR_FIELD(self, f32, 0xC) = D_800DD490_de;
    scaleX = FR_FIELD(self, f32, 0x480) * (FR_FIELD(D_80141008_BYTES, f32, 0x29C) / (f32)D_800E28D0);
    scaleZ = FR_FIELD(self, f32, 0x488) * (FR_FIELD(D_80141008_BYTES, f32, 0x29C) / (f32)D_800E28D0);
    scaleY = FR_FIELD(self, f32, 0x484) * (FR_FIELD(D_80141008_BYTES, f32, 0x2A0) / (f32)D_800E28D4);
    FR_FIELD(drawState, f32, 0x50) = scaleX;
    FR_FIELD(drawState, f32, 0x54) = scaleY;
    FR_FIELD(drawState, f32, 0x58) = scaleZ;
    localFacing = FR_FIELD(self, CVector3, 0x48C);
    func_80272898_de(D_80141008_BYTES + 0x160, &localFacing, &local80);
    link = self + 4;
    func_802466A0_de(drawState, -1, arg3, D_800CD8D0, link, -1, 0, FR_FIELD(self, f32, 0x498) * (&D_800DD490_de)[1], local80, 0, FR_FIELD(self, CVector3, 0x480), local60, 0);
    func_8024B2D0_de(drawState);
    if (FR_FIELD(self, s32, 0) == 9) {
        ((void (*)(u8 *, s32, s32, s32))func_8041CE18_de)(self, arg3, arg4, arg2);
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8041CAD8_de);
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
   it with zero, func_8041CAD8_de writes the same word directly and func_8041C7F4_de reads it. */


void func_8041CE10_de(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Sets field 0x274 of arg0 to 0xFFFF and then calls func_8041C610_de on it. */
void func_8041CE18_de(Unk8041CE88 *arg0) {
    arg0->unk274 = 0xFFFF;
#ifdef NON_MATCHING
    func_8041C610_de(arg0, 0, 0, 0);
#else
    func_8041C610_de(arg0);
#endif
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_8041CEA8_us_padding_180EA8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_8041D278_eu_x_padding_10D278);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("ovl_80400000", func_8041D278_eu_padding_193278);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("ovl_80400000", func_8041CE38_de_padding_182E38);
#endif
