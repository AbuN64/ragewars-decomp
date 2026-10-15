#ifndef UNBAKE_SPAN_1000_CODE_8023D370_H
#define UNBAKE_SPAN_1000_CODE_8023D370_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Output;
typedef struct Output Output;

struct World;

struct Ray;
typedef struct Ray Ray;

struct Polygon_func_8023E178_de;
struct Polygon_func_8023E178_de {
    s32 type;
    s32 pad4;
    s32 kind;
    char padC[0x8];
    s32 flag;
    Vec3 point;
    char pad24[0x24];
    Vec3 normal;
    char pad54[0x78];
    f32 t;
    Vec3 hit;
};

struct Dst;
typedef struct Dst Dst;

struct Polygon;
typedef struct Polygon Polygon;

struct Ray;
struct Ray {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    Vec3 dir;
    char pad68[0x114];
    f32 nearest;
};

extern float D_800C87C0;

struct func_8023E844_S1;
struct func_8023E844_S1 {
    char pad0[0x18C];
    int unk18C;
    char pad18C[0x190 - 0x18C - sizeof(int)];
    int unk190;
    char pad190[0x194 - 0x190 - sizeof(int)];
    int unk194;
};

struct func_8023E6C0_S1;
typedef struct func_8023E6C0_S1 func_8023E6C0_S1;

struct func_8023ED54_S1;
struct func_8023ED54_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xCC - 0x8 - sizeof(s32)];
    f32 unkCC;
};

struct Polygon;
struct Polygon {
    s32 type;
    f32 response; /* 0x04 */
    s32 kind;
    s32 category; /* 0x0C */
    u32 flags; /* 0x10 */
    s32 vertexCount; /* 0x14 */
    Vec3 vertices[4]; /* 0x18 */
    Vec3 normal; /* 0x48 */
    void *input; /* 0x54 */
    s32 index; /* 0x58 */
    char pad5C[0x70];
    f32 t; /* 0xCC */
    Vec3 hit;
};

struct func_8023E854_S1;
typedef struct func_8023E854_S1 func_8023E854_S1;

extern void func_8023EC54_de(void *arg0, void *arg1);

extern void func_8023EE34_de(void);

struct ObjRecAt18C;
struct ObjRecAt18C {
    char pad0[0x18C];
    Triple unk18C;
};

struct func_8023E854_S2;
typedef struct func_8023E854_S2 func_8023E854_S2;

struct ObjRecAt18C;
typedef struct ObjRecAt18C ObjRecAt18C;

struct Polygon_func_8023E178_de;
typedef struct Polygon_func_8023E178_de Polygon_func_8023E178_de;

struct Ray_func_8023E178_de;
struct Ray_func_8023E178_de {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    Vec3 dir;
    char pad68[0x18];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E178_de nearest;
};

struct func_8023ED54_S1;
typedef struct func_8023ED54_S1 func_8023ED54_S1;

struct Polygon;
typedef struct Polygon Polygon_func_8023E8D4_de;

struct CapsuleSweep;
struct MotionSurface;
struct CapsuleSweep {
    char pad0[0x08];
    f32 radius; /* 0x08 */
    f32 secondaryRadius; /* 0x0C */
    char pad10[0x0C];
    f32 height; /* 0x1C */
    char pad20[0x1C];
    u32 flags; /* 0x3C */
    struct MotionSurface *surface; /* 0x40 */
    Vec3 start;
    Vec3 end;
    char pad5C[0x24];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E8D4_de nearest;
};

struct Instance;
struct Instance {
    u8 pad0[0x14];
    s32 field14;
};
struct Input;
struct Instance;
struct Input {
    u8 pad0[0xB0];
    s32 type;
    u8 padB4[8];
    s32 fieldBC;
    s32 fieldC0;
    u8 padC4[0x34];
    Triple vecF8;
    struct Instance *instance104;
    s32 field108;
    Block70 block10C;
    s32 field17C;
    Triple vec180;
    Vec3 contactNormal; /* 0x18C */
};

struct func_8023EE50_S1;
typedef struct func_8023EE50_S1 func_8023EE50_S1;

struct CapsuleSweep;
typedef struct CapsuleSweep CapsuleSweep;

struct func_8023E844_S1;
typedef struct func_8023E844_S1 func_8023E844_S1;

struct World;

extern float D_800D0648;

struct Dst;
struct Dst {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern float D_800C36D8_de;

extern s32 func_8023E864_de(void *arg0, void *arg1);

struct Polygon;


struct CapsuleSweep;


struct Range;
struct Range {
    char pad[8];
    f32 low;
    s32 count;
    f32 high;
    f32 extra;
    f32 limit;
};

extern void func_8023E8B4_de(void *arg0, void *arg1);

extern void func_8023EBFC_de(void *arg0, void *arg1);

extern void func_8023EE00_de();

struct func_8023E854_S2;
struct func_8023E854_S2 {
    char pad0[0x48];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
};

struct func_8023EE24_S1;
typedef struct func_8023EE24_S1 func_8023EE24_S1;

struct Instance;
struct Output;
struct Output {
    struct Instance *instance0;
    s32 instanceValue4;
    Triple vec8;
    s32 field14;
    Block70 block18;
    struct Instance *instance88;
    s32 instanceValue8C;
    Triple vec90;
    u8 pad9C[0x28];
    s32 fieldC4;
    Triple vecC8;
    s32 fieldD4;
    u8 padD8[0xC];
    Triple vecE4;
    Triple vecF0;
    s32 typeFC;
    s32 field100;
};

struct Ray_func_8023E178_de;
typedef struct Ray_func_8023E178_de Ray_func_8023E178_de;

struct func_8023E854_S1;
struct func_8023E854_S1 {
    char pad0[0x18C];
    f32 unk18C;
    char pad18C[0x190 - 0x18C - sizeof(f32)];
    f32 unk190;
    char pad190[0x194 - 0x190 - sizeof(f32)];
    f32 unk194;
};

struct ObjRecAt48;
typedef struct ObjRecAt48 ObjRecAt48;

struct Reusable;
typedef struct Reusable Reusable;

struct ObjRecAt48;
struct ObjRecAt48 {
    char pad0[0x48];
    Triple unk48;
};

struct EntryRecAt24;
typedef struct EntryRecAt24 EntryRecAt24;

struct Dst;
struct EntryRecAt24;
struct EntryRecAt24 {
    struct Dst *dst;
    s32 val0;
    u8 pad1[3];
    u8 flag0;
    u8 pad2[3];
    u8 flag1;
    u8 pad3[3];
    u8 flag2;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 extra;
};

struct func_8023EE50_S1;
struct func_8023EE50_S1 {
    char pad0[0x28];
    EntryRecAt24 unk28;
};

struct Segment_func_8023E6EC_de;
typedef struct Segment_func_8023E6EC_de Segment_func_8023E6EC_de;

struct func_8023EE24_S1;
struct func_8023EE24_S1 {
    unsigned int unk0;
    char pad0[0x14 - 0x0 - sizeof(unsigned int)];
    int unk14;
    char pad14[0x88 - 0x14 - sizeof(int)];
    unsigned int unk88;
    char pad88[0x9C - 0x88 - sizeof(unsigned int)];
    unsigned int unk9C;
    char pad9C[0xB0 - 0x9C - sizeof(unsigned int)];
    unsigned int unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(unsigned int)];
    unsigned int unkB4;
    char padB4[0xC4 - 0xB4 - sizeof(unsigned int)];
    unsigned int unkC4;
};

struct Segment_func_8023E6EC_de;
struct Segment_func_8023E6EC_de {
    char pad0[0x40];
    Field_f32_10 *limits;
    f32 x0;
    char pad48[4];
    f32 y0;
    f32 x1;
    f32 height;
    f32 y1;
    char pad5C[0x74 - 0x5C];
    char node[1];
};

struct Input;
typedef struct Input Input;

extern float D_800C87B4;

struct func_8023ED54_S2;
struct func_8023ED54_S2 {
    char pad0[0x80];
    f32 unk80;
    char pad80[0x17C - 0x80 - sizeof(f32)];
    f32 unk17C;
};

struct func_8023ED54_S2;
typedef struct func_8023ED54_S2 func_8023ED54_S2;

struct Reusable;
struct Reusable {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
    char pad18[0x70];
    s32 unk88;
    char pad8C[0x10];
    s32 unk9C;
    char padA0[0x10];
    s32 unkB0;
    s32 unkB4;
    char padB8[0xC];
    s32 unkC4;
};

struct func_8023E6C0_S1;
struct func_8023E6C0_S1 {
    char pad0[0x8];
    float unk8;
    char pad8[0xC - 0x8 - sizeof(float)];
    float unkC;
    char padC[0x10 - 0xC - sizeof(float)];
    float unk10;
    char pad10[0x14 - 0x10 - sizeof(float)];
    int unk14;
    char pad14[0x18 - 0x14 - sizeof(int)];
    float unk18;
};

struct CapsuleSweep;

extern f32 D_800C3670_de;
extern f32 D_800C3674_de;
extern f32 D_800C3678_de;
extern f32 D_800C367C_de;
extern f32 D_800C3680_de;
extern f32 D_800C3684_de;
extern f32 D_800C3688_de;
extern f32 D_800C368C_de;
extern Vec3 func_802723FC_de(Vec3 *,Vec3 *);

#endif
