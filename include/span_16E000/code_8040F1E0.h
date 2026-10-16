#ifndef UNBAKE_SPAN_16E000_CODE_8040F1E0_H
#define UNBAKE_SPAN_16E000_CODE_8040F1E0_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct SlotRecAtCV1;
struct SlotRecAtCV1 {
    char pad0[8];
    u16 flags;
    char padA[2];
    char data[0x20];
};

struct EntryCode8040B45C80411518;
struct SlotRecAtCV1;
struct EntryCode8040B45C80411518 {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct SlotRecAtCV1 **ns;
    char pad488[4];
    ObjRecAtE *def;
    char pad490[0xC];
};
struct EntryCode8040B45C80411518;
struct Pool_func_80411518_de;
struct Pool_func_80411518_de {
    s16 count;
    char pad2[6];
    struct EntryCode8040B45C80411518 *entries;
};

struct Usage;
struct Usage {
    s32 expiry;
    u16 count;
    u16 pad6;
};

extern void func_80411A3C_de(void);

struct EntryRecAt18V1;
typedef struct EntryRecAt18V1 EntryRecAt18V1;

extern void func_8040F208_de(void *object, int value);

struct SlotRecAtCV2;
struct SlotRecAtCV2 {
    char pad0[4];
    s32 owner;
    u16 flags;
    char padA[2];
    char data[0x20];
};

extern void func_804101BC_de();

struct ChunkRecAt48C;
struct ChunkRecAt48C {
    char pad[0x484];
    void **primary;
    void **optional;
    char rest[0x10];
};

extern void func_8040F210_de(void *object, int value);

struct Resource_func_80410E1C_de;
struct Resource_func_80410E1C_de {
    void *data;
    s32 flags;
    char pad8[0x14];
};
struct Timer_func_80410E1C_de;
struct Timer_func_80410E1C_de {
    s32 owner;
    s16 delay;
};
struct PoolRecAtC;
struct Resource_func_80410E1C_de;
struct Timer_func_80410E1C_de;
struct PoolRecAtC {
    s16 count;
    struct Resource_func_80410E1C_de *resources;
    s32 unk8;
    struct Timer_func_80410E1C_de *timers;
};

struct Field_u16_14;
extern int func_8040F570_de(struct Field_u16_14 *a, struct Field_u16_14 *b);

extern void func_8040F568_de();

extern int D_80153C08;

extern s32 func_8040F160_de(s32 font, u8 *text, s32 length);

extern void func_80411518_de(s32 index);

struct RecordRecAtCV4;
struct RecordRecAtCV4 {
    char pad0[0xA];
    s16 a;
    s16 c;
    char padE[28 - 0xE];
};

struct QuadRecAt2C;
struct QuadRecAt2C {
    char pad[0x2C];
    s32 values[4];
};

extern s32 func_80411A74_de(void);

struct Pool_func_80411518_de;
typedef struct Pool_func_80411518_de Pool_func_80411518_de;

struct ButtonWidget;
typedef struct ButtonWidget ButtonWidget;

extern void func_80410448_de();

struct Glyph;
struct Glyph {
    s8 width;
    char pad[7];
};

struct SlotRecAtCV1;
typedef struct SlotRecAtCV1 SlotRecAtCV1;

struct Glyph;
typedef struct Glyph Glyph;

struct State_func_804101BC_de;
struct State_func_804101BC_de {
    void *active;
    char pad[0x25C];
    void *resource;
    char pad264[0xC];
    s16 count;
};

extern s16 func_80411AA8_de(s32 index);

struct EntryCode8040B45C;
struct SlotRecAtCV2;
struct EntryCode8040B45C {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct SlotRecAtCV2 **pages;
    char pad488[4];
    ObjRecAtE *def;
    unsigned char refCount;
    char pad491[0xB];
};
struct EntryCode8040B45C;
struct Pool_func_8040F580_de;
struct Pool_func_8040F580_de {
    s16 count;
    char pad2[6];
    struct EntryCode8040B45C *entries;
};

struct Style;
struct Style {
    f32 scaleX;
    f32 scaleY;
    s32 v[5];
};

struct UiWidget;
struct UiWidget {
    s32 name;
    struct UiWidget *next;
    struct UiWidget *children;
    char padC[2];
    u16 type;
    char pad10[2];
    u16 flags;
    char pad14[0x18];
    s32 words[4];
    char pad3C[8];
    s32 extra;
};

extern s16 func_80411A44_de(void);

struct FileHeader;
typedef struct FileHeader FileHeader;

struct EntryRecAt18V1;
struct EntryRecAt18V1 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

struct EntryRecAt18V1;
struct FileHeader;
struct FileHeader {
    char pad0[0x25C];
    struct EntryRecAt18V1 *unk25C;
};

struct UiWidget;
typedef struct UiWidget UiWidget;

struct Pair2C;
struct Pair2C {
    char pad[0x2C];
    u8 first;
    u8 second;
};

struct Pair2C;
extern void func_8040F1FC_de(struct Pair2C *record, u8 first, u8 second);

extern s16 func_80411A84_de(s32 index);

struct Usage;
typedef struct Usage Usage;

struct FontRecord;
struct FontRecord {
    char pad[8];
    Glyph glyphs[1];
};

struct SlotRecAtCV2;
typedef struct SlotRecAtCV2 SlotRecAtCV2;

struct Style;
typedef struct Style Style;

struct FontRecord;
typedef struct FontRecord FontRecord;

extern void func_8040F534_de(s32 width, s32 height);

struct PoolRecAtC;
typedef struct PoolRecAtC PoolRecAtC;

struct Pair14;
struct ButtonWidget;
struct ButtonWidget {
    char pad0[0x2C];
    struct Pair14 *normal;
    struct Pair14 *highlighted;
    struct Pair14 *pressed;
};

struct FileState;
struct FileState {
    s32 unk0;
    char pad4[0x244];
    s32 unk248;
};

struct Pool_func_8040F580_de;
typedef struct Pool_func_8040F580_de Pool_func_8040F580_de;

struct FileState;
typedef struct FileState FileState;

struct QuadRecAt2C;
extern void func_8040F218_de(struct QuadRecAt2C *record, s32 first, s32 second, s32 third, s32 fourth);

extern s32 func_80411ACC_de(s32 index);

struct Chunk_func_80410448_de;
struct SlotRecAtCV2;
struct ObjRecAtE;
struct Chunk_func_80410448_de {
    void *active;
    char pad4[0x480];
    struct SlotRecAtCV2 **slots;
    char pad488[4];
    struct ObjRecAtE *header;
    u8 live;
    char pad491[0xB];
};
struct Chunk_func_80410448_de;
struct EntryRecAt8V1;
struct ResourceRecAt6;
struct State_func_80410448_de;
struct State_func_80410448_de {
    char pad0[0x25C];
    s16 count;
    struct EntryRecAt8V1 *entries;
    char pad264[4];
    struct ResourceRecAt6 *resources;
    char pad26C[4];
    s16 chunkCount;
    char pad272[6];
    struct Chunk_func_80410448_de *chunks;
    char pad27C[0x28];
    s32 locked;
};

#endif
