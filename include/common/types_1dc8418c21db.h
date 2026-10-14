#ifndef UNBAKE_COMMON_TYPES_1DC8418C21DB_H
#define UNBAKE_COMMON_TYPES_1DC8418C21DB_H
#include "audio_callbacks.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct ItemRecAt20V1;
struct ItemRecAt20V1 {
    char pad0[0x14];
    s32 x;
    char pad18[8];
    s32 y;
};

struct ObjRecAtE;
struct ObjRecAtE {
    char pad0[0xE];
    s16 unkE;
};

struct ObjRecAtE;
typedef struct ObjRecAtE ObjRecAtE;

struct ObjRecAt1454V2;
struct ObjRecAt1454V2 {
    char pad0[0x1454];
    void * unk1454;
};

struct Pool;
struct Pool {
    s32 count;
    char pad[0x40];
    s32 field44;
};

struct Actor_func_8024A1D0_de;
typedef struct Actor_func_8024A1D0_de Actor_func_8024A1D0_de;

struct StridedTable;
struct StridedTable {
    s32 stride;
    s32 count;
    char data[1];
};

struct FftTables;
typedef struct FftTables FftTables;

struct FftTables;
struct FftTables {
    f32 *sines;
    f32 *cosines;
    s32 *order;
    s32 size;
};

struct ObjRecAt2CV2;
struct ObjRecAt2CV2 {
    char pad0[0x2C];
    int unk2C;
};

extern int D_80142CA8;

struct func_8025C598_S1;
typedef struct func_8025C598_S1 func_8025C598_S1;

struct ObjRecAt4V1;
struct ObjRecAt4V1 {
    char pad0[0x4];
    u8 unk4;
};

struct ObjectState1E;
struct ObjectState1E {
    unsigned char padding_0[29];
    s8 unk_1D;
};

struct ObjRecAt14V3;
struct ObjRecAt14V3 {
    s32 unk0;
    char pad0[0x10];
    s32 unk14;
};

struct Frame_func_804217D4_de;
struct Frame_func_804217D4_de {
    char a[0x16];
    s16 unk16;
    char b[2];
    s16 unk1A;
};

struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
struct Menu_func_804241BC_de {
    char pad[0x44];
    struct Frame_func_804217D4_de *list;
};

struct FieldRow;
struct FieldRow {
    s32 value;
    char pad[8];
};

struct FieldRow;
typedef struct FieldRow FieldRow;

struct Menu_func_8043E494_de;
typedef struct Menu_func_8043E494_de Menu_func_8043E494_de;

struct Clip;
struct Clip {
    s16 mode;
    s16 frames;
};

struct Clip;
typedef struct Clip Clip;

struct Node_func_80285B64_de;
struct Node_func_80285B64_de {
    struct Node_func_80285B64_de *previous;
    struct Node_func_80285B64_de *next;
    Clip *key;
    Vec3 position;
    f32 value0;
    f32 value1;
    u32 amplitudeHandle; /* 0x20 */
    char pad24[8];
    u32 lifetimeHandle; /* 0x2C */
    char pad30[8];
    struct Node_func_80285B64_de **owner;
};

struct GlyphBuffer;
/* Font records contain a four-byte header and 147 eight-byte glyph records. */
typedef struct TextGlyph {
    u32 texture;
    s8 width;
    s8 height;
    s8 offsetX;
    s8 offsetY;
} TextGlyph;

struct GlyphBuffer {
    u32 header;
    TextGlyph glyphs[147];
};

struct func_8029A73C_S1;
typedef struct func_8029A73C_S1 func_8029A73C_S1;

struct Block70;
struct Block70 {
    s32 w[28];
};

struct Block70;
typedef struct Block70 Block70;

struct func_8025E5B0_S1;
struct func_8025E5B0_S1 {
    char pad0[0x14];
    short unk14;
};

struct Entry_func_80441EB0_de;
struct Entry_func_80441EB0_de {
    s16 type;
    char pad[0x22];
};
union func_8020E674_S1_U8;
typedef union func_8020E674_S1_U8 func_8020E674_S1_U8;

union func_8020E674_S1_U8;
union func_8020E674_S1_U8 {
    f32 v0;
    Vec3 v1;
};

struct ALPlayer_s14;
struct ALPlayer_s14 {
    struct ALPlayer_s14 *next;
    void *clientData;
    ALVoiceHandler handler;
    s32 callTime;
    s32 samplesLeft;
};

struct ALPlayer_s14;
typedef struct ALPlayer_s14 ALPlayer_s14;

struct ALEventQueue;
typedef struct ALEventQueue ALEventQueue;

struct Message_func_802AF150_de;
struct Message_func_802AF150_de {
    s16 type;
    char pad[14];
} __attribute__((aligned(4)));

struct Link_func_802596B4_de;
struct Link_func_802596B4_de {
    struct Link_func_802596B4_de *next;
    struct Link_func_802596B4_de *prev;
};

struct Link_func_802596B4_de;
typedef struct Link_func_802596B4_de Link_func_802596B4_de;

struct ALEventQueue;
struct ALEventQueue {
    Link_func_802596B4_de freeList;
    Link_func_802596B4_de allocList;
    s32 eventCount;
};

struct Message_func_802AF150_de;
typedef struct Message_func_802AF150_de Message_func_802AF150_de;

struct Node802A697C;
struct Node802A697C {
    u32 unk0;
    f32 value;
    s32 childValue; /* 0x08 */
    s32 matrixIndex; /* 0x0C */
};

struct ObjRecAt1CV3;
struct ObjRecAt1CV3 {
    char pad0[0x1C];
    Triple unk1C;
};

struct Shape_typemap_6;
struct Shape_typemap_6 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct func_8024C5C4_S2;
typedef struct func_8024C5C4_S2 func_8024C5C4_S2;

struct Brain_func_80212D78_eu_x;
struct Brain_func_80212D78_eu_x {
    struct Actor_func_8022D290_de *player;
    s32 node;
    char pad8[4];
    s32 nextNode;
    char pad10[0x210];
    s32 unk220;
    char pad224[8];
    s32 goal;
    char pad230[0xC];
    s32 triggerLatch; /* 0x23C */
    char pad240[0xBC];
    s32 unk2FC;
    char pad300[0x14];
    s32 busy;
    char pad318[8];
    s32 jumpTimer;
};

struct Output80216D3C;
struct Output80216D3C {
    s32 type;
    s32 unk4;
    s32 unk8;
    Triple first;
    Triple second;
    s32 unk24;
    Triple third;
    Triple fourth;
    s32 unk40;
};

struct Output80216D3C;
typedef struct Output80216D3C Output80216D3C;

struct func_8022ED94_S1;
typedef struct func_8022ED94_S1 func_8022ED94_S1;

struct MatrixF;
struct MatrixF {
    f32 m[4][4];
};

struct Record_func_80433914_de;
typedef struct Record_func_80433914_de Record_func_80433914_de;

struct Record_func_80433914_de;
struct Record_func_80433914_de {
    union {
        struct {
    u8 name[8];
    s32 time;
    s8 owner;
    s8 player;
    char padE[1];
    u8 slot;
    char pad10[7];
    u8 count;
    char pad18[0x25 - 0x18];
    u8 rank;
    u8 plays[0x24]; /* +0x26: per-character match count */
    u8 achievementFlags[0x189 - 0x4A];
    u8 setting[5];
    char pad18E[0x190 - 0x18E];
        };
        struct { char pad0[0x6C]; s32 wins, kills, deaths; } statistics;
    };
};

struct MenuWidget;
struct MenuWidget {
    char pad0[4];
    struct MenuWidget *sibling;
    struct MenuWidget *child;
    s16 resource;
    char padE[2];
    u8 alpha;
    char pad11[3];
    s16 x;
    s16 y;
    union { s16 width; s16 w; };
    s16 height;
    char pad1C[0x2C - 0x1C];
    s32 value;
    struct MenuWidget *next;
    s32 field34;
    union { void *text; s32 image; s32 word38; };
};

struct MenuWidget;
typedef struct MenuWidget MenuWidget;

struct func_8020CA10_G1;
typedef struct func_8020CA10_G1 func_8020CA10_G1;

struct func_8020CA10_G1;
struct func_8020CA10_G1 {
    f32 unk0;
};

struct func_8020EA10_S1;
typedef struct func_8020EA10_S1 func_8020EA10_S1;

struct ALVoice_s;
typedef struct ALVoice_s ALVoice_s;

struct ALVoice_s;
struct ALVoice_s {
    Link_func_802596B4_de node;
    void *pvoice;
    void *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
};

struct ALSynth_func_802B3000_de;
typedef struct ALSynth_func_802B3000_de ALSynth_func_802B3000_de;

struct func_80275120_S1;
struct func_80275120_S1 {
    float unk0;
    char pad0[0x8 - 0x0 - sizeof(float)];
    float unk8;
    char pad8[0xC - 0x8 - sizeof(float)];
    float unkC;
};

struct Queue_func_802517B4_de;
struct Queue_func_802517B4_de {
    void **head;
    s32 unk04;
    s32 count;
    s32 index;
    s32 capacity;
    void **entries;
};

typedef signed int ( *Handler802A2B50)(void *, signed int, signed int, signed int, signed int);

struct Field_f32_10;
typedef struct Field_f32_10 Field_f32_10;

struct Actor_func_8024A1D0_de;
struct Actor_func_8024A1D0_de {
    u32 pad0[2];
    Vec3 position0;
    u32 pad14[2];
    Vec3 position1;
    u32 pad28[13];
    Vector4f rotation;
};

struct Resource_func_80419E54_de;
struct Resource_func_80419E54_de {
    char pad[0x10];
    unsigned char value;
};

struct Field_s32_2E0;
struct Field_s32_2E0 {
    char pad[0x2E0];
    s32 value;
};

struct Entry802AB8DC;
typedef struct Entry802AB8DC Entry802AB8DC;

struct Entry802AB8DC;
struct Entry802AB8DC {
    s32 offset;
    u8 pad4[4];
};

struct Inner8043E56C;
struct Inner8043E56C {
    u8 pad0[4];
    s8 unk4;
};

struct Inner8043E56C;
struct Outer8043E56C;
struct Outer8043E56C {
    u8 pad0[0x20];
    struct Inner8043E56C *unk20;
};

struct Outer8043E56C;
typedef struct Outer8043E56C Outer8043E56C;

struct ObjRecAtCV3;
typedef struct ObjRecAtCV3 ObjRecAtCV3;

struct Owner_func_8043E1F8_de;
struct Owner_func_8043E1F8_de {
    char pad0[0x85C];
    s32 unk85C;
};

struct ALVoice_s_func_802B3000_de;
typedef struct ALVoice_s_func_802B3000_de ALVoice_s_func_802B3000_de;

struct UnitMtx;
typedef struct UnitMtx UnitMtx;

struct UnitMtx;
struct UnitMtx {
    s32 m[16];
};

struct func_8024C864_S1;
typedef struct func_8024C864_S1 func_8024C864_S1;

struct __OSInode;
typedef struct __OSInode __OSInode;

union __OSInodeUnit;
union __OSInodeUnit {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ipage;
};

union __OSInodeUnit;
typedef union __OSInodeUnit __OSInodeUnit;

struct __OSInode;
struct __OSInode {
    __OSInodeUnit inode_page[128];
};

struct TextLayerRect;
typedef struct TextLayerRect TextLayerRect;

struct ObjRecAt2V1;
typedef struct ObjRecAt2V1 ObjRecAt2V1;

struct func_802044C8_S1;
struct func_802044C8_S1 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x100 - 0xE4 - sizeof(u16)];
    s32 unk100;
};

struct Node75;
typedef struct Node75 Node75;

struct ObjRecAt8V2;
struct ObjRecAt8V2 {
    char pad0[0x8];
    char unk8;
};

struct ALMIDIEvent;
typedef struct ALMIDIEvent ALMIDIEvent;

struct ObjRecAt80;
struct ObjRecAt80 {
    char pad0[0x80];
    s8 unk80;
};

struct ResourceManagerState;
struct ResourceManagerState {
    s32 active;
    s32 count;
};

struct Arg1Struct;
typedef struct Arg1Struct Arg1Struct;

struct Arg1Struct;
struct Arg1Struct {
    char pad0[0x1C];
    s32 unk1C;
    char pad1[0x20 - 0x1C - 4];
    s32 unk20;
};

struct func_80206930_S3;
typedef struct func_80206930_S3 func_80206930_S3;

union ObjectLinks4_3;
typedef union ObjectLinks4_3 ObjectLinks4_3;

union ObjectLinks4_3;
union ObjectLinks4_3 {
    void * v0;
    char * v1;
};

struct ObjectStateC_2;
struct ObjectStateC_2 {
    char pad0[0x8];
    ObjectLinks4_3 unk_8;
};

struct ALHeap;
typedef struct ALHeap ALHeap;

struct ObjRecAtB0;
struct ObjRecAtB0 {
    char pad0[0xB0];
    s32 unkB0;
};

struct NodeEvent;
struct NodeEvent {
    s32 words[10];
};

struct Resource_func_80419E54_de;
typedef struct Resource_func_80419E54_de Resource_func_80419E54_de;

struct IntPair;
struct IntPair {
    int field_0;
    int field_4;
};

struct ObjRecAt130;
struct ObjRecAt130 {
    char pad0[0x130];
    f32 unk130;
};

union func_802626BC_S1_U10;
union func_802626BC_S1_U10 {
    s32 v0;
    void * v1;
};

union func_802626BC_S1_U10;
typedef union func_802626BC_S1_U10 func_802626BC_S1_U10;

struct Handler;
struct Handler {
    char pad0[4];
    s16 id;
    char pad6[6];
    union {
        s32 (*targeted)(void *actor, struct Handler *entry, s32 target);
        s32 (*plain)(void *actor, struct Handler *entry);
    } handleC;
    s32 (*handle10)(void *actor, struct Handler *entry);
    s32 (*handle14)(void *actor, struct Handler *entry);
};

struct Shape_typemap_110;
struct Shape_typemap_110 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

struct func_80258BB4_S1;
struct func_80258BB4_S1 {
    char pad0[0x2BA4];
    float unk2BA4;
};

struct ALFilter_s14;
typedef struct ALFilter_s14 ALFilter_s14;

struct ALFilter_s14;
struct ALFilter_s14 {
    struct ALFilter_s14 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
};

struct func_8025BD20_S1;
struct func_8025BD20_S1 {
    char pad0[0x4];
    char unk4;
};

extern int D_801005A8;

struct Key;
struct Key {
    char pad0[0x14];
};

struct Key;
struct OwnerRecAt38;
struct OwnerRecAt38 {
    char pad[0x38];
    struct Key *selected;
};

struct OSPfs_func_80445F80_de;
typedef struct OSPfs_func_80445F80_de OSPfs_func_80445F80_de;

struct EntryRecAt3;
struct EntryRecAt3 {
    u16 id;
    u8 team;
    u8 slot;
};

struct EntryRecAt3;
typedef struct EntryRecAt3 EntryRecAt3;

struct Shape_typemap_21;
struct Shape_typemap_21 {
    unsigned char padding_0[16];
    unsigned char field_10;
};

struct ProfileRecAt16;
struct ProfileRecAt16 {
    char pad0[0x14];
    u8 bonus2;
    u8 bonus0;
    u8 bonus1;
    char pad17[0x190 - 0x17];
};

struct ObjRecAt1454V2;
typedef struct ObjRecAt1454V2 ObjRecAt1454V2;

struct func_8029A73C_S1;
struct func_8029A73C_S1 {
    char pad0[0x520];
    int unk520;
};

struct Field_u16_14;
struct Field_u16_14 {
    char pad[0x14];
    u16 value;
};

struct func_8028469C_S2;
struct func_8028469C_S2 {
    char pad0[0x38];
    void * unk38;
};

struct Block24;
typedef struct Block24 Block24;

struct func_8028B3C0_S1;
typedef struct func_8028B3C0_S1 func_8028B3C0_S1;

struct PlaneEquation;
struct PlaneEquation {
    Vec3 normal;
    f32 distance;
};

struct PlaneEquation;
typedef struct PlaneEquation PlaneEquation;

struct Extra;
struct Extra {
    s32 id;
    f32 scale;
};

struct Block;
struct Block {
    u8 pad000[0x100];
    s32 flags;
    u8 pad104[0x1DC];
    s32 value;
};

struct Block;
typedef struct Block Block;

struct func_80250BD4_S1;
struct func_80250BD4_S1 {
    char pad0[0x20];
    s32 * unk20;
};

struct Vec3Words;
struct Vec3Words {
    s32 w[3];
};

struct func_8022D418_S1;
struct func_8022D418_S1 {
    char pad0[0x658];
    f32 unk658;
    char pad658[0x664 - 0x658 - sizeof(f32)];
    s32 unk664;
    char pad664[0x72C - 0x664 - sizeof(s32)];
    f32 unk72C;
    char pad72C[0x850 - 0x72C - sizeof(f32)];
    s32 unk850;
};

struct func_80293268_S2;
typedef struct func_80293268_S2 func_80293268_S2;

struct func_80207B5C_S2;
typedef struct func_80207B5C_S2 func_80207B5C_S2;

extern int D_8010515C;

struct Player_func_804356BC_de;
struct Player_func_804356BC_de {
    char pad0[0x18];
    char slots[4][400];
    char pad658[0xB68 - 0x658];
};

struct StateFlags;
typedef struct StateFlags StateFlags;

struct StateFlags;
struct StateFlags {
    u16 value;
    u16 flags;
};

struct func_8024C864_S1;
struct func_8024C864_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
};

struct Queue_func_802517B4_de;
typedef struct Queue_func_802517B4_de Queue_func_802517B4_de;

struct Desc;
struct Desc {
    char pad[0x108];
    s32 caps[4];
};

struct OwnerRecAt5D8V2;
struct OwnerRecAt5D8V2 {
    char pad[0x5D8];
    char *name;
};

struct func_8025CA44_S1;
typedef struct func_8025CA44_S1 func_8025CA44_S1;

struct func_802B4ECC_S1;
typedef struct func_802B4ECC_S1 func_802B4ECC_S1;

struct func_80207BB8_S4;
typedef struct func_80207BB8_S4 func_80207BB8_S4;

struct func_8022BC04_S3;
typedef struct func_8022BC04_S3 func_8022BC04_S3;

struct Rec_func_8024C92C_de;
typedef struct Rec_func_8024C92C_de Rec_func_8024C92C_de;

struct Rec_func_8024C92C_de;
struct Rec_func_8024C92C_de {
    s32 x;
    s32 y;
    s32 z;
    s32 pad0;
    s32 pad1;
};

struct func_80204468_S2;
struct func_80204468_S2 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x100 - 0x18 - sizeof(void*)];
    int unk100;
};

struct State_func_804232AC_de;
struct State_func_804232AC_de {
    void *menu;
    char pad4[0x20 - 4];
    s32 value;
};

struct HudStatusShared_MatchRules;
typedef struct HudStatusShared_MatchRules HudStatusShared_MatchRules;

struct func_8022CA04_S3;
struct func_8022CA04_S3 {
    char pad0[0x20];
    f32 unk20;
};

struct ParamsRecAt8V1;
typedef struct ParamsRecAt8V1 ParamsRecAt8V1;

struct Node75;
struct Node75 {
    s32 pad0;
    Vec3 *prev;
    Vec3 *cur;
    Vec3 *next;
};

struct Field_s32_2E0;
typedef struct Field_s32_2E0 Field_s32_2E0;

extern int D_8014693C;

struct func_8028DA50_S1;
struct func_8028DA50_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};

struct InventorySlot;
struct InventorySlot {
    u8 available;
    u8 slot;
};

struct InventorySlot;
typedef struct InventorySlot InventorySlot;

struct func_8024DED0_S2;
typedef struct func_8024DED0_S2 func_8024DED0_S2;

struct func_8024DED0_S2;
struct func_8024DED0_S2 {
    char pad0[0x4C];
    int unk4C;
};

struct ObjRecAt40V1;
typedef struct ObjRecAt40V1 ObjRecAt40V1;

struct func_80242278_S2;
struct func_80242278_S2 {
    char pad0[0x8];
    u8 unk8;
};

struct func_8023945C_S1;
struct func_8023945C_S1 {
    char pad0[0x128];
    Vec3 unk128;
};

struct func_80272848_S1;
struct func_80272848_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

struct ListScreenRecord;
typedef struct ListScreenRecord ListScreenRecord;

struct ListScreenRecord;
struct ListScreenRecord {
    char pad0[0x78];
    u8 active;
    char pad79[0x18];
    u8 out;
    char pad92[0x4];
};

struct Pool;
typedef struct Pool Pool;

struct ObjRecAt14V1;
typedef struct ObjRecAt14V1 ObjRecAt14V1;

struct func_80204EA8_S1;
struct func_80204EA8_S1 {
    char pad0[0x8];
    Triple unk8;
};

extern IntrusiveList D_80137064;

struct func_802A68A0_S3;
typedef struct func_802A68A0_S3 func_802A68A0_S3;

extern float D_8010AC7C;

struct func_80258D60_S1;
struct func_80258D60_S1 {
    char pad0[0x84];
    char unk84;
};

struct ObjRecAt1CV1;
struct ObjRecAt1CV1 {
    char pad0[0x14];
    int unk14;
    char pad14[0x1C - 0x14 - sizeof(int)];
    int unk1C;
};

struct ObjectState14;
struct ObjectState14 {
    Vec3 position;
    s16 unk_C;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unk_E;
    char padE[0x10 - 0xE - sizeof(s16)];
    s16 unk_10;
    char pad10[0x12 - 0x10 - sizeof(s16)];
    s16 unk_12;
};

struct func_8020CA10_S2;
struct func_8020CA10_S2 {
    char pad0[0xC];
    u16 unkC;
};

struct ALEvent_func_802B21A8_de;
struct ALEvent_func_802B21A8_de {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 byte1;
            u8 byte2;
            u32 duration;
        } midi;
    } msg;
};

struct Object6C;
struct Object6C {
    char pad[0x6C];
    s32 value;
};

struct ObjRecAt564;
struct ObjRecAt564 {
    char pad0[0x564];
    s32 unk564;
};

struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Rider;
struct Settings;
struct SharedPlayer_func_80226A34_de;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct ObjRecAt564;
struct SharedPlayer_func_80226A34_de {
    union {
        struct {
            u8 unk0[24];
        } view0_0;
        struct {
            u8 pad0[24];
        } view0_1;
        struct {
            char pad[0x3];
            u8 team;
        } view3_2;
        struct {
            char pad[0x8];
            Vec3 unk8;
        } view8_2;
        struct {
            char pad[0x8];
            Vec3 pos;
        } view8_3;
        struct {
            char pad[0x8];
            Vec3 position;
        } view8_4;
        struct {
            char pad[0x14];
            struct Shared_Model * model;
        } view14_6;
        struct { char pad[8]; s32 positionWords[3]; } positionBits;
    } views0;
    union {
        struct {
            char * unk18;
        } view18_0;
        struct {
            char * track;
        } view18_1;
        struct {
            struct Model * model;
        } view18_2;
        struct {
            struct Body * body;
        } view18_3;
        struct {
            struct Character * character;
        } view18_4;
        struct {
            struct Shared_Body * body;
        } view18_5;
    } views18;
    union {
        struct {
            u8 unk1C[344];
        } view1C_0;
        struct {
            u8 pad1[344];
        } view1C_1;
        struct {
            char pad[0x4];
            f32 velY;
        } view20_2;
        struct {
            char pad[0x1C];
            s32 unk38;
        } view38_2;
        struct {
            char pad[0x1C];
            s32 flags;
        } view38_3;
        struct {
            char pad[0x24];
            f32 unk40;
        } view40_5;
        struct {
            char pad[0x40];
            Shared_Quad unk5C;
        } view5C_6;
        struct {
            char pad[0x50];
            f32 unk6C;
        } view6C_4;
        struct {
            char pad[0x50];
            f32 heading;
        } view6C_5;
        struct {
            char pad[0x50];
            f32 yaw;
        } view6C_9;
        struct {
            char pad[0xC8];
            u16 unkE4;
        } viewE4_6;
        struct {
            char pad[0xC8];
            u16 kind;
        } viewE4_7;
        struct {
            char pad[0xE4];
            s32 unk100;
        } view100_8;
        struct {
            char pad[0xE4];
            s32 flags;
        } view100_9;
        struct {
            char pad[0xE8];
            f32 unk104;
        } view104_10;
        struct {
            char pad[0xE8];
            f32 idleTime;
        } view104_11;
        struct {
            char pad[0xEC];
            s16 anim;
        } view108_16;
        struct {
            char pad[0xF2];
            s8 unk10E;
        } view10E_12;
        struct {
            char pad[0xF2];
            s8 idle;
        } view10E_13;
        struct {
            char pad[0xF2];
            s8 replaying;
        } view10E_14;
        struct {
            char pad[0xF2];
            s8 animPending;
        } view10E_20;
        struct {
            char pad[0x154];
            char unk170[100];
        } view170_15;
        struct {
            char pad[0x154];
            char body[100];
        } view170_16;
        struct {
            char pad[0x154];
            s32 unk170;
        } view170_23;
        struct {
            char pad[0x158];
            s32 unk174;
        } view174_17;
        struct {
            char pad[0x15C];
            u8 unk178[740];
        } view178_18;
        struct {
            char pad[0x15C];
            u8 pad2[740];
        } view178_19;
        struct {
            char pad[0x1B8];
            f32 unk1D4;
        } view1D4_20;
        struct {
            char pad[0x1B8];
            f32 holdTime;
        } view1D4_21;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * unk1D8;
        } view1D8_22;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * self;
        } view1D8_23;
        struct {
            char pad[0x1BC];
            struct SharedPlayer_func_80226A34_de * f1D8;
        } view1D8_24;
        struct {
            char pad[0x1BC];
            void * unk1D8;
        } view1D8_32;
        struct {
            char pad[0x244];
            Vec3 unk260;
        } view260_25;
        struct {
            char pad[0x244];
            Vec3 muzzle;
        } view260_26;
        struct {
            char pad[0x2CC];
            char unk2E8[368];
        } view2E8_27;
        struct {
            char pad[0x2CC];
            char weapon[368];
        } view2E8_28;
        struct {
            char pad[0x2CC];
            Shared_Emitter emitter;
        } view2E8_37;
        struct {
            char pad[0x43C];
            char unk458[384];
        } view458_29;
        struct {
            char pad[0x43C];
            char ammo[384];
        } view458_30;
        struct {
            char pad[0x43C];
            s32 unk458;
        } view458_40;
        struct {
            char pad[0x440];
            s32 unk45C;
        } view45C_31;
        struct {
            char pad[0x444];
            u8 unk460[376];
        } view460_32;
        struct {
            char pad[0x444];
            u8 pad3[376];
        } view460_33;
        struct {
            char pad[0x468];
            struct Shared_Voice * voice;
        } view484_44;
        struct {
            char pad[0x470];
            s8 unk48C;
        } view48C_34;
        struct {
            char pad[0x470];
            s8 state;
        } view48C_35;
        struct {
            char pad[0x4A4];
            void * unk4C0;
        } view4C0_47;
        struct {
            char pad[0x507];
            s8 unk523;
        } view523_36;
        struct {
            char pad[0x507];
            s8 busy;
        } view523_37;
        struct {
            char pad[0x578];
            s32 unk594;
        } view594_38;
        struct {
            char pad[0x578];
            s32 gear;
        } view594_39;
        struct {
            char pad[0x578];
            s32 mode;
        } view594_40;
        struct {
            char pad[0x584];
            f32 unk5A0;
        } view5A0_41;
        struct {
            char pad[0x584];
            f32 charge;
        } view5A0_42;
        struct {
            char pad[0x5B4];
            s32 unk5D0;
        } view5D0_43;
        struct {
            char pad[0x5B4];
            s32 f5D0;
        } view5D0_44;
        struct {
            char pad[0x5B8];
            s32 unk5D4;
        } view5D4_45;
        struct {
            char pad[0x5B8];
            s32 slot;
        } view5D4_46;
        struct {
            char pad[0x5B8];
            s32 profile;
        } view5D4_47;
        struct {
            char pad[0x5B8];
            s32 f5D4;
        } view5D4_48;
    } views1C;
    union {
        struct {
            struct Record * unk5D8;
        } view5D8_0;
        struct {
            struct Record * record;
        } view5D8_1;
        struct {
            struct Controls * controls;
        } view5D8_2;
        struct {
            struct TeamInfo * teamInfo;
        } view5D8_3;
        struct {
            struct Ctrl * ctrl;
        } view5D8_4;
        struct {
            unsigned char * info;
        } view5D8_5;
        struct {
            struct Profile * profile;
        } view5D8_6;
        struct {
            struct Settings * settings;
        } view5D8_7;
        struct {
            s32 f5D8;
        } view5D8_8;
        struct {
            struct Shared_Profile * profile;
        } view5D8_9;
    } views5D8;
    union {
        struct {
            void * unk5DC;
        } view5DC_0;
        struct {
            void * view;
        } view5DC_1;
        struct {
            struct ObjRecAt564 * view;
        } view5DC_2;
        struct {
            u8 pad4[8];
        } view5DC_3;
        struct {
            void * entity;
        } view5DC_4;
        struct {
            struct Rider * rider;
        } view5DC_5;
        struct {
            char * storage;
        } view5DC_6;
        struct {
            char * messages;
        } view5DC_7;
        struct {
            struct Shared_Hud * hud;
        } view5DC_8;
        struct {
            char pad[0x4];
            s32 unk5E0;
        } view5E0_8;
        struct {
            char pad[0x4];
            s32 state;
        } view5E0_9;
        struct {
            char pad[0x4];
            s32 slot;
        } view5E0_10;
    } views5DC;
    union {
        struct {
            s32 unk5E4;
        } view5E4_0;
        struct {
            s32 active;
        } view5E4_1;
        struct {
            s32 health;
        } view5E4_2;
        struct {
            s32 alive;
        } view5E4_3;
        struct {
            s32 holding;
        } view5E4_4;
    } views5E4;
    union {
        struct {
            u8 unk5E8[3140];
        } view5E8_0;
        struct {
            u8 pad5[3140];
        } view5E8_1;
        struct {
            char pad[0x2];
            s16 unk5EA;
        } view5EA_2;
        struct {
            char pad[0x2];
            s16 respawns;
        } view5EA_3;
        struct {
            char pad[0x2];
            s16 runType;
        } view5EA_4;
        struct {
            char pad[0x4];
            s32 unk5EC;
        } view5EC_5;
        struct {
            char pad[0x4];
            s32 model;
        } view5EC_6;
        struct {
            char pad[0x4];
            s32 spawnPoint;
        } view5EC_7;
        struct {
            char pad[0x4];
            s32 f5EC;
        } view5EC_8;
        struct {
            char pad[0x8];
            s32 unk5F0;
        } view5F0_9;
        struct {
            char pad[0x8];
            s32 f5F0;
        } view5F0_10;
        struct {
            char pad[0xC];
            s16 unk5F4[4];
        } view5F4_11;
        struct {
            char pad[0xC];
            s16 ammo[4];
        } view5F4_12;
        struct {
            char pad[0xC];
            s16 ammo[3];
        } view5F4_13;
        struct {
            char pad[0x1A];
            Shared_Slot slots[22];
        } view602_14;
        struct {
            char pad[0x46];
            s16 unk62E;
        } view62E_13;
        struct {
            char pad[0x46];
            s16 weapon;
        } view62E_14;
        struct {
            char pad[0x46];
            s16 character;
        } view62E_17;
        struct {
            char pad[0x68];
            s16 unk650;
        } view650_15;
        struct {
            char pad[0x68];
            s16 state;
        } view650_16;
        struct {
            char pad[0x68];
            s16 action;
        } view650_17;
        struct {
            char pad[0x68];
            s16 mode;
        } view650_18;
        struct {
            char pad[0x6A];
            s16 unk652;
        } view652_19;
        struct {
            char pad[0x6A];
            s16 previous;
        } view652_20;
        struct {
            char pad[0x6A];
            s16 pad652;
        } view652_24;
        struct {
            char pad[0x6C];
            s16 prevState;
        } view654_25;
        struct {
            char pad[0x6E];
            s16 pad656;
        } view656_26;
        struct {
            char pad[0x70];
            f32 unk658;
        } view658_21;
        struct {
            char pad[0x70];
            f32 counter;
        } view658_22;
        struct {
            char pad[0x70];
            f32 stride;
        } view658_23;
        struct {
            char pad[0x70];
            f32 swimTime;
        } view658_24;
        struct {
            char pad[0x70];
            f32 stateTime;
        } view658_31;
        struct {
            char pad[0x74];
            s32 unk65C;
        } view65C_32;
        struct {
            char pad[0x78];
            s32 unk660;
        } view660_25;
        struct {
            char pad[0x78];
            s32 previousTimer;
        } view660_26;
        struct {
            char pad[0x7C];
            s32 unk664;
        } view664_27;
        struct {
            char pad[0x7C];
            s32 timer;
        } view664_28;
        struct {
            char pad[0x84];
            f32 unk66C;
        } view66C_29;
        struct {
            char pad[0x88];
            f32 unk670;
        } view670_30;
        struct {
            char pad[0x88];
            f32 shield;
        } view670_31;
        struct {
            char pad[0x90];
            f32 unk678;
        } view678_40;
        struct {
            char pad[0xA0];
            char unk688[16];
        } view688_32;
        struct {
            char pad[0xA0];
            char body[16];
        } view688_33;
        struct {
            char pad[0xA0];
            Shared_Input input;
        } view688_43;
        struct {
            char pad[0xB0];
            struct Controller * unk698;
        } view698_34;
        struct {
            char pad[0xB0];
            struct Controller * controller;
        } view698_35;
        struct {
            char pad[0xB0];
            void * controller;
        } view698_36;
        struct {
            char pad[0xB0];
            char * emitter;
        } view698_37;
        struct {
            char pad[0xB0];
            char * title;
        } view698_38;
        struct {
            char pad[0xB4];
            f32 unk69C;
        } view69C_39;
        struct {
            char pad[0xB4];
            f32 stick;
        } view69C_40;
        struct {
            char pad[0xBC];
            f32 unk6A4;
        } view6A4_41;
        struct {
            char pad[0xBC];
            f32 strafe;
        } view6A4_42;
        struct {
            char pad[0xC0];
            f32 unk6A8;
        } view6A8_43;
        struct {
            char pad[0xC0];
            f32 lift;
        } view6A8_44;
        struct {
            char pad[0xC4];
            s32 unk6AC;
        } view6AC_45;
        struct {
            char pad[0xC8];
            s32 unk6B0;
        } view6B0_46;
        struct {
            char pad[0xC8];
            s32 input;
        } view6B0_47;
        struct {
            char pad[0xC8];
            s32 state;
        } view6B0_48;
        struct {
            char pad[0xD0];
            s32 unk6B8;
        } view6B8_49;
        struct {
            char pad[0xD0];
            s32 input;
        } view6B8_50;
        struct {
            char pad[0xD8];
            f32 unk6C0;
        } view6C0_51;
        struct {
            char pad[0xD8];
            f32 climb;
        } view6C0_52;
        struct {
            char pad[0xD8];
            f32 speed;
        } view6C0_53;
        struct {
            char pad[0xD8];
            f32 velX;
        } view6C0_64;
        struct {
            char pad[0xDC];
            f32 unk6C4;
        } view6C4_54;
        struct {
            char pad[0xDC];
            f32 side;
        } view6C4_55;
        struct {
            char pad[0xDC];
            f32 velZ;
        } view6C4_67;
        struct {
            char pad[0xE0];
            f32 unk6C8;
        } view6C8_56;
        struct {
            char pad[0xE0];
            f32 speed;
        } view6C8_57;
        struct {
            char pad[0xE4];
            f32 lastVelY;
        } view6CC_70;
        struct {
            char pad[0xE8];
            s32 onGround;
        } view6D0_71;
        struct {
            char pad[0xEC];
            f32 unk6D4;
        } view6D4_58;
        struct {
            char pad[0xF0];
            f32 unk6D8;
        } view6D8_59;
        struct {
            char pad[0xF4];
            f32 unk6DC;
        } view6DC_60;
        struct {
            char pad[0xFC];
            f32 unk6E4;
        } view6E4_61;
        struct {
            char pad[0xFC];
            f32 depth;
        } view6E4_62;
        struct {
            char pad[0xFC];
            f32 airTime;
        } view6E4_77;
        struct {
            char pad[0x100];
            f32 unk6E8;
        } view6E8_63;
        struct {
            char pad[0x100];
            Vec3 unk6E8;
        } view6E8_79;
        struct {
            char pad[0x104];
            f32 unk6EC;
        } view6EC_64;
        struct {
            char pad[0x104];
            f32 height;
        } view6EC_65;
        struct {
            char pad[0x108];
            f32 unk6F0;
        } view6F0_66;
        struct {
            char pad[0x10C];
            f32 unk6F4;
        } view6F4_83;
        struct {
            char pad[0x110];
            Vec3 unk6F8;
        } view6F8_84;
        struct {
            char pad[0x11C];
            f32 unk704;
        } view704_67;
        struct {
            char pad[0x11C];
            f32 lift;
        } view704_68;
        struct {
            char pad[0x130];
            f32 unk718;
        } view718_69;
        struct {
            char pad[0x130];
            f32 crouch;
        } view718_70;
        struct {
            char pad[0x134];
            s32 unk71C;
        } view71C_89;
        struct {
            char pad[0x138];
            f32 swim;
        } view720_90;
        struct {
            char pad[0x13C];
            f32 unk724;
        } view724_71;
        struct {
            char pad[0x13C];
            f32 pitch;
        } view724_72;
        struct {
            char pad[0x140];
            f32 unk728;
        } view728_73;
        struct {
            char pad[0x140];
            f32 kickPitch;
        } view728_74;
        struct {
            char pad[0x144];
            f32 unk72C;
        } view72C_75;
        struct {
            char pad[0x144];
            f32 kickRoll;
        } view72C_76;
        struct {
            char pad[0x144];
            f32 lean;
        } view72C_77;
        struct {
            char pad[0x148];
            f32 unk730[3];
        } view730_78;
        struct {
            char pad[0x148];
            f32 sway[3];
        } view730_79;
        struct {
            char pad[0x154];
            f32 unk73C;
        } view73C_80;
        struct {
            char pad[0x154];
            f32 side;
        } view73C_81;
        struct {
            char pad[0x154];
            Vec3 weapon;
        } view73C_82;
        struct {
            char pad[0x158];
            f32 unk740;
        } view740_83;
        struct {
            char pad[0x158];
            f32 height;
        } view740_84;
        struct {
            char pad[0x15C];
            f32 unk744;
        } view744_85;
        struct {
            char pad[0x15C];
            f32 forward;
        } view744_86;
        struct {
            char pad[0x170];
            f32 unk758;
        } view758_87;
        struct {
            char pad[0x170];
            f32 bobStrength;
        } view758_88;
        struct {
            char pad[0x174];
            f32 unk75C;
        } view75C_89;
        struct {
            char pad[0x174];
            f32 bobSpeed;
        } view75C_90;
        struct {
            char pad[0x188];
            s16 unk770;
        } view770_91;
        struct {
            char pad[0x188];
            s16 nextWeapon;
        } view770_92;
        struct {
            char pad[0x188];
            s16 weapon;
        } view770_113;
        struct {
            char pad[0x18A];
            s16 pad772;
        } view772_114;
        struct {
            char pad[0x18C];
            Vec3 unk774;
        } view774_115;
        struct {
            char pad[0x198];
            f32 unk780;
        } view780_116;
        struct {
            char pad[0x19C];
            f32 unk784;
        } view784_117;
        struct {
            char pad[0x1A0];
            s32 unk788;
        } view788_93;
        struct {
            char pad[0x1A0];
            s32 icons;
        } view788_94;
        struct {
            char pad[0x1B0];
            s32 unk798;
        } view798_95;
        struct {
            char pad[0x1B0];
            s32 carried;
        } view798_96;
        struct {
            char pad[0x1B4];
            Vec3 unk79C;
        } view79C_97;
        struct {
            char pad[0x1B4];
            Vec3 carriedPosition;
        } view79C_98;
        struct {
            char pad[0x1D0];
            s32 unk7B8;
        } view7B8_99;
        struct {
            char pad[0x1D0];
            s32 target;
        } view7B8_100;
        struct {
            char pad[0x1D4];
            f32 unk7BC;
        } view7BC_101;
        struct {
            char pad[0x1D4];
            f32 timer;
        } view7BC_102;
        struct {
            char pad[0x1D8];
            Vec3 unk7C0;
        } view7C0_103;
        struct {
            char pad[0x1D8];
            Vec3 targetPosition;
        } view7C0_104;
        struct {
            char pad[0x200];
            s32 unk7E8;
        } view7E8_105;
        struct {
            char pad[0x200];
            s32 zoomed;
        } view7E8_106;
        struct {
            char pad[0x204];
            f32 unk7EC;
        } view7EC_132;
        struct {
            char pad[0x208];
            f32 unk7F0;
        } view7F0_133;
        struct {
            char pad[0x224];
            struct Mount * unk80C;
        } view80C_107;
        struct {
            char pad[0x224];
            struct Mount * mount;
        } view80C_108;
        struct {
            char pad[0x228];
            s32 unk810;
        } view810_109;
        struct {
            char pad[0x228];
            s32 kind;
        } view810_110;
        struct {
            char pad[0x22C];
            Triple unk814;
        } view814_111;
        struct {
            char pad[0x22C];
            Triple offset;
        } view814_112;
        struct {
            char pad[0x250];
            f32 unk838;
        } view838_113;
        struct {
            char pad[0x250];
            f32 rideTime;
        } view838_114;
        struct {
            char pad[0x254];
            f32 unk83C;
        } view83C_115;
        struct {
            char pad[0x254];
            f32 bump;
        } view83C_116;
        struct {
            char pad[0x258];
            s32 unk840;
        } view840_117;
        struct {
            char pad[0x258];
            s32 surfaced;
        } view840_118;
        struct {
            char pad[0x264];
            s32 unk84C;
        } view84C_149;
        struct {
            char pad[0x26C];
            f32 unk854;
        } view854_147;
        struct {
            char pad[0x274];
            s32 unk85C;
        } view85C_119;
        struct {
            char pad[0x274];
            s32 w85C;
        } view85C_120;
        struct {
            char pad[0x27C];
            s32 unk864;
        } view864_121;
        struct {
            char pad[0x27C];
            s32 f864;
        } view864_122;
        struct {
            char pad[0x280];
            s32 unk868;
        } view868_123;
        struct {
            char pad[0x280];
            s32 f868;
        } view868_124;
        struct {
            char pad[0x284];
            s32 unk86C;
        } view86C_125;
        struct {
            char pad[0x284];
            s32 parameter;
        } view86C_126;
        struct {
            char pad[0x284];
            s32 animation;
        } view86C_127;
        struct {
            char pad[0x288];
            s32 unk870;
        } view870_157;
        struct {
            char pad[0x290];
            Shared_Effect effect;
        } view878_158;
        struct {
            char pad[0x350];
            char unk938[2188];
        } view938_128;
        struct {
            char pad[0x350];
            char strokes[2188];
        } view938_129;
        struct {
            char pad[0x350];
            char strokes[2188];
        } view938_130;
        struct {
            char pad[0x350];
            s32 unk938;
        } view938_162;
        struct {
            char pad[0x6D0];
            s32 unkCB8;
        } viewCB8_163;
        struct {
            char pad[0x6E4];
            s32 unkCCC;
        } viewCCC_164;
        struct {
            char pad[0x758];
            s32 unkD40;
        } viewD40_165;
        struct {
            char pad[0x96C];
            s32 unkF54;
        } viewF54_131;
        struct {
            char pad[0x96C];
            s32 selection;
        } viewF54_132;
        struct {
            char pad[0x9A8];
            s32 unkF90;
        } viewF90_133;
        struct {
            char pad[0x9A8];
            s32 choice;
        } viewF90_134;
        struct {
            char pad[0xBCC];
            s32 unk11B4;
        } view11B4_135;
        struct {
            char pad[0xBCC];
            s32 locked;
        } view11B4_136;
        struct {
            char pad[0xBD0];
            s32 unk11B8;
        } view11B8_137;
        struct {
            char pad[0xBD0];
            s32 frozen;
        } view11B8_138;
        struct {
            char pad[0xBD4];
            s32 unk11BC;
        } view11BC_139;
        struct {
            char pad[0xBD4];
            s32 f11BC;
        } view11BC_140;
        struct {
            char pad[0xBD8];
            s32 unk11C0;
        } view11C0_141;
        struct {
            char pad[0xBD8];
            s32 f11C0;
        } view11C0_142;
        struct {
            char pad[0xBDC];
            f32 unk11C4;
        } view11C4_143;
        struct {
            char pad[0xBDC];
            f32 soundTime;
        } view11C4_144;
        struct {
            char pad[0xBE4];
            s32 unk11CC;
        } view11CC_145;
        struct {
            char pad[0xBE4];
            s32 f11CC;
        } view11CC_146;
        struct {
            char pad[0xBF0];
            f32 unk11D8;
        } view11D8_147;
        struct {
            char pad[0xBF0];
            f32 recoil;
        } view11D8_148;
        struct {
            char pad[0xBF0];
            f32 stun;
        } view11D8_149;
        struct {
            char pad[0xBF4];
            f32 unk11DC;
        } view11DC_185;
        struct {
            char pad[0xBF8];
            f32 unk11E0;
        } view11E0_186;
        struct {
            char pad[0xC00];
            s32 unk11E8;
        } view11E8_150;
        struct {
            char pad[0xC00];
            s32 f11E8;
        } view11E8_151;
        struct {
            char pad[0xC04];
            f32 unk11EC;
        } view11EC_189;
        struct {
            char pad[0xC28];
            s32 unk1210;
        } view1210_152;
        struct {
            char pad[0xC28];
            s32 marker;
        } view1210_153;
        struct {
            char pad[0xC2C];
            s32 unk1214;
        } view1214_154;
        struct {
            char pad[0xC2C];
            s32 marker;
        } view1214_155;
        struct {
            char pad[0xC2C];
            s32 markerShown;
        } view1214_156;
        struct {
            char pad[0xC30];
            s32 unk1218;
        } view1218_157;
        struct {
            char pad[0xC30];
            s32 f1218;
        } view1218_158;
        struct {
            char pad[0xC34];
            s32 unk121C;
        } view121C_159;
        struct {
            char pad[0xC34];
            s32 f121C;
        } view121C_160;
        struct {
            char pad[0xC38];
            s32 unk1220;
        } view1220_161;
        struct {
            char pad[0xC38];
            s32 f1220;
        } view1220_162;
        struct { char pad[0xE]; s16 charge; } chargeView;
        struct { char pad[0x11F4 - 0x5E8]; f32 spin; s32 frame; } rapidFireView;
    } views5E8;
    union {
        struct {
            u32 unk122C;
        } view122C_0;
        struct {
            u32 flags;
        } view122C_1;
        struct {
            s32 options;
        } view122C_2;
        struct {
            s32 f122C;
        } view122C_3;
        struct {
            s32 fxFlags;
        } view122C_4;
    } views122C;
    f32 fxTime;
    f32 fxSpeed;
    s32 fxStage;
    char pad123C[0x4];
    f32 unk1240;
    f32 unk1244;
    char pad1248[0x7C];
    union {
        struct {
            s32 unk12C4;
        } view12C4_0;
        struct {
            s32 f12C4;
        } view12C4_1;
    } views12C4;
    union {
        struct {
            s32 unk12C8;
        } view12C8_0;
        struct {
            s32 f12C8;
        } view12C8_1;
    } views12C8;
    union {
        struct {
            s32 unk12CC[8];
        } view12CC_0;
        struct {
            s32 splitsA[8];
        } view12CC_1;
    } views12CC;
    s32 unk12EC;
    char pad12F0[0x4];
    union {
        struct {
            s32 unk12F4[8];
        } view12F4_0;
        struct {
            s32 splitsB[8];
        } view12F4_1;
    } views12F4;
    char pad1314[0x20];
    union {
        struct {
            s32 unk1334;
        } view1334_0;
        struct {
            s32 f1334;
        } view1334_1;
    } views1334;
    union {
        struct {
            s32 unk1338;
        } view1338_0;
        struct {
            s32 f1338;
        } view1338_1;
    } views1338;
    union {
        struct {
            s32 unk133C;
        } view133C_0;
        struct {
            s32 laps;
        } view133C_1;
        struct {
            s32 lives;
        } view133C_2;
    } views133C;
    union {
        struct {
            s32 unk1340;
        } view1340_0;
        struct {
            s32 stalls;
        } view1340_1;
        struct {
            s32 timer;
        } view1340_2;
        struct {
            s32 respawnTimer;
        } view1340_3;
    } views1340;
    char pad1344[0x70];
    union {
        struct {
            struct StateInfo * unk13B4;
        } view13B4_0;
        struct {
            struct StateInfo * states;
        } view13B4_1;
        struct {
            struct Mode * unk13B4;
        } view13B4_2;
        struct {
            void * character;
        } view13B4_3;
        struct {
            s32 f13B4;
        } view13B4_4;
        struct {
            struct Shared_StateInfo * states;
        } view13B4_5;
    } views13B4;
    char pad13B8[0x10];
    union {
        struct {
            s32 unk13C8;
        } view13C8_0;
        struct {
            s32 w13C8;
        } view13C8_1;
        struct {
            s32 f13C8;
        } view13C8_2;
    } views13C8;
    char pad13CC[0x8];
    s32 unk13D4;
    union {
        struct {
            struct Held * unk13D8;
        } view13D8_0;
        struct {
            struct Held * held;
        } view13D8_1;
    } views13D8;
    char pad13DC[0xC];
    s32 messageIndex;
    char pad13EC[0x64];
    union {
        struct {
            s32 unk1450;
        } view1450_0;
        struct {
            s32 computer;
        } view1450_1;
        struct {
            s32 infinite;
        } view1450_2;
        struct {
            s32 unlimited;
        } view1450_3;
        struct {
            s32 uncounted;
        } view1450_4;
        struct {
            s32 f1450;
        } view1450_5;
    } views1450;
    union {
        struct {
            s32 unk1454;
        } view1454_0;
        struct {
            s32 f1454;
        } view1454_1;
    } views1454;
    char pad1458[0xC];
    union {
        struct {
            Vec3 unk1464;
        } view1464_0;
        struct {
            Vec3 aim;
        } view1464_1;
    } views1464;
    char pad1470[0x10];
    union {
        struct {
            Matrix unk1480[2];
        } view1480_0;
        struct {
            Matrix beams[2];
        } view1480_1;
    } views1480;
    union {
        struct {
            Matrix unk1500[2];
        } view1500_0;
        struct {
            Matrix lasers[2];
        } view1500_1;
    } views1500;
    union {
        struct {
            Matrix unk1580[2];
        } view1580_0;
        struct {
            Matrix dots[2];
        } view1580_1;
    } views1580;
    char pad1600[0xD4];
    union {
        struct {
            s32 unk16D4;
        } view16D4_0;
        struct {
            s32 f16D4;
        } view16D4_1;
    } views16D4;
    u16 unk16D8;
    char pad16DA[0x6];
    union {
        struct {
            struct SharedPlayer_func_80226A34_de * unk16E0;
        } view16E0_0;
        struct {
            struct SharedPlayer_func_80226A34_de * next;
        } view16E0_1;
        struct {
            struct SharedPlayer_func_80226A34_de * next;
        } view16E0_2;
    } views16E0;
};

union func_80239C2C_S1_UF24;
union func_80239C2C_S1_UF24 {
    void * v0;
    char v1;
};

struct ALHeap;
struct ALHeap {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
};

struct ItemRecAt20V1;
typedef struct ItemRecAt20V1 ItemRecAt20V1;

struct StateBlock;
typedef struct StateBlock StateBlock;

struct Style_func_8043C9AC_de;
struct Style_func_8043C9AC_de {
    char pad0[0x30];
    f32 alpha;
    f32 fade;
};

struct OwnerRecAt5D0;
struct OwnerRecAt5D0 {
    char pad[0x5D0];
    s32 value;
};

struct Holder;
struct OwnerRecAt5D0;
struct Holder {
    char pad[0x1C];
    struct OwnerRecAt5D0 *owner;
};

struct CallbackStateC_4;
typedef struct CallbackStateC_4 CallbackStateC_4;

struct Field_void_4;
struct Field_void_4 {
    char pad[0x4];
    void * value;
};

struct ObjRecAt18V1;
struct ObjRecAt18V1 {
    char pad18[0x18];
    s16 field18;
};

struct func_8022ED94_S1;
struct func_8022ED94_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
};

union func_80239C2C_S1_UF24;
typedef union func_80239C2C_S1_UF24 func_80239C2C_S1_UF24;

struct Item_func_8042B4D4_de;
struct Item_func_8042B4D4_de {
    char pad[0x10];
    u8 alpha;
    char pad11[0x14 - 0x11];
    s16 x;
};

struct ObjRecAt2V2;
typedef struct ObjRecAt2V2 ObjRecAt2V2;

struct Draw;
typedef struct Draw Draw;

struct func_80258614_S1;
typedef struct func_80258614_S1 func_80258614_S1;

struct State_func_8042D8C4_de;
struct State_func_8042D8C4_de {
    char pad[0xE8];
    s32 count;
};

union func_8026E158_S1_U8;
typedef union func_8026E158_S1_U8 func_8026E158_S1_U8;

struct ALMIDIEvent;
struct ALMIDIEvent {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
};

struct Func802608ECResult;
typedef struct Func802608ECResult Func802608ECResult;

struct Func802608ECResult;
struct Func802608ECResult {
    u32 value;
    f32 start;
    f32 delta;
};

struct MenuRules;
typedef struct MenuRules MenuRules;

struct Extra;
typedef struct Extra Extra;

struct ALSynth_func_802B3000_de;
struct ALSynth_func_802B3000_de {
    void *head;
    Link_func_802596B4_de pFreeList;
    Link_func_802596B4_de pAllocList;
    Link_func_802596B4_de pLameList;
    s32 paramSamples;
};

struct func_8025E58C_S1;
struct func_8025E58C_S1 {
    char pad0[0x10];
    short unk10;
};

struct ObjRecAt18V2;
typedef struct ObjRecAt18V2 ObjRecAt18V2;

struct func_80254D70_S2;
typedef struct func_80254D70_S2 func_80254D70_S2;

struct Node75_func_802750B0_de;
typedef struct Node75_func_802750B0_de Node75_func_802750B0_de;

struct func_80207F90_S1;
struct func_80207F90_S1 {
    char pad0[0x100];
    unsigned int unk100;
};

extern int D_80145048;

struct func_802A2E5C_S2;
typedef struct func_802A2E5C_S2 func_802A2E5C_S2;

struct EntryRecAt0V1;
struct EntryRecAt0V1 {
    s32 value;
    char pad[28 - 4];
};

struct ObjRecAt80;
typedef struct ObjRecAt80 ObjRecAt80;

struct func_8022D418_S1;
typedef struct func_8022D418_S1 func_8022D418_S1;

struct ObjectLinks24_2;
typedef struct ObjectLinks24_2 ObjectLinks24_2;

struct func_80245690_S1;
struct func_80245690_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x38 - 0x4 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x60 - 0x3C - sizeof(s32)];
    s32 unk60;
};

struct ResourceRecAt6;
struct ResourceRecAt6 {
    s32 id;
    s16 retained;
    s16 unused;
};

struct Field_Vec_18;
struct Field_Vec_18 {
    char pad[0x18];
    Vec3 value;
};

struct ObjRecAt2V2;
struct ObjRecAt2V2 {
    char pad0[0x2];
    u16 unk2;
};

extern int D_80111D24;

struct func_80205700_S1;
typedef struct func_80205700_S1 func_80205700_S1;

struct func_8024E58C_S1;
typedef struct func_8024E58C_S1 func_8024E58C_S1;

struct PlayerRecAt58;
typedef struct PlayerRecAt58 PlayerRecAt58;

struct ObjectState14;
typedef struct ObjectState14 ObjectState14;

union func_8022E280_S1_U744;
typedef union func_8022E280_S1_U744 func_8022E280_S1_U744;

union func_8022E280_S1_U744;
union func_8022E280_S1_U744 {
    s32 v0;
    f32 v1;
};

struct Record_func_8043E494_de;
struct Record_func_8043E494_de {
    char pad[0x7B];
    s8 mode;
};

struct Owner_func_8043E494_de;
struct Record_func_8043E494_de;
struct Owner_func_8043E494_de {
    char pad[0x5D8];
    struct Record_func_8043E494_de *record;
};
struct Menu_func_8043E494_de;
struct Owner_func_8043E494_de;
struct Menu_func_8043E494_de {
    char pad[0x1C];
    struct Owner_func_8043E494_de *owner;
};

struct func_8025C8F8_S1;
typedef struct func_8025C8F8_S1 func_8025C8F8_S1;

struct CellRecAt1A;
struct CellRecAt1A {
    char pad[0x16];
    s16 unk16;
    s16 unk18;
    s16 unk1A;
};

struct CellRecAt1A;
struct Obj_func_80421BEC_de;
struct Obj_func_80421BEC_de {
    char pad[0x44];
    struct CellRecAt1A *unk44;
};
struct CellRecAt1A;
struct Obj_func_80421BEC_de;
struct State_func_80421BEC_de;
struct State_func_80421BEC_de {
    struct Obj_func_80421BEC_de *unk0;
    s32 unk4;
    struct CellRecAt1A *unk8;
    s32 unkC;
    s32 unk10;
};

struct ObjRecAt1D8V3;
typedef struct ObjRecAt1D8V3 ObjRecAt1D8V3;

struct func_802165F8_S1;
typedef struct func_802165F8_S1 func_802165F8_S1;

struct Access_s32_5C;
struct Access_s32_5C {
    char pad[0x5C];
    s32 field;
};

struct ObjectState1E_2;
struct ObjectState1E_2 {
    char pad0[0x1D];
    u8 unk_1D;
};

struct func_80258BB4_S1;
typedef struct func_80258BB4_S1 func_80258BB4_S1;

struct func_80255BEC_S1;
typedef struct func_80255BEC_S1 func_80255BEC_S1;

struct State_func_8043E254_de;
typedef struct State_func_8043E254_de State_func_8043E254_de;

struct func_80204EA8_S1;
typedef struct func_80204EA8_S1 func_80204EA8_S1;

struct __OSDir;
typedef struct __OSDir __OSDir;

struct func_80255BEC_S1;
struct func_80255BEC_S1 {
    char pad0[0x8];
    void * unk8;
};

struct BufferPool;
struct BufferPool {
    s16 count;
    func_80255BEC_S1 *primary;
    func_80255BEC_S1 *secondary;
    u16 *flags;
    s16 *refs;
};

struct Node_func_80239AF4_de;
typedef struct Node_func_80239AF4_de Node_func_80239AF4_de;

struct Node_func_80239AF4_de;
struct Node_func_80239AF4_de {
    struct Node_func_80239AF4_de *next;
};

struct func_8022BECC_S2;
typedef struct func_8022BECC_S2 func_8022BECC_S2;

struct ControllerRecAtC7;
struct ControllerRecAtC7 {
    char pad0[0xC6];
    s8 x;
    s8 y;
};

struct EventRecAt14;
struct IntPair;
struct EventRecAt14 {
    u16 frame;
    u16 effect;
    s16 bone;
    s16 pad6;
    Vec3 local;
    struct IntPair params;
};

struct RecordRecAt94;
struct RecordRecAt94 {
    char pad0[0x80];
    s8 kind;
    char pad81[0x13];
    u8 display;
};

struct __OSContRequesFormat;
struct __OSContRequesFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
};

struct func_80272908_S2;
struct func_80272908_S2 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x20 - 0x18 - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x30 - 0x28 - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
};

struct WeaponInfo;
struct WeaponInfo {
    void **resource;
    u16 model;
    char pad6[2];
    s16 capacity;
    char padA[2];
    s16 alternate;
    char padE[0xA];
    f32 chargeRate; /* 0x18 */
    char pad1C[4];
    s16 *weaponClass;
    s16 *alternateClass;
    s16 *thirdClass;
    s16 *computerClasses[3];
    char pad38[0xC];
    f32 scopeBounds[4]; /* 0x44 */
    struct AiBehaviourTable *animation; /* 0x54 */
    s32 animationCount;
};

struct func_8022E694_S1;
typedef struct func_8022E694_S1 func_8022E694_S1;

struct Slot;
typedef struct Slot Slot;

struct ObjRecAt2V1;
struct ObjRecAt2V1 {
    s16 translation;
    short unk2;
};

struct EffectRecAt154;
typedef struct EffectRecAt154 EffectRecAt154;

struct Field_Vec_18;
typedef struct Field_Vec_18 Field_Vec_18;

struct ALVoiceConfig_s;
typedef struct ALVoiceConfig_s ALVoiceConfig_s;

struct InstanceHdr;
struct InstanceHdr {
    union {
        s32 w[5];
        struct { s32 header[2]; Vec3 position; } spatial;
    };
};

struct func_8023EBEC_S1;
typedef struct func_8023EBEC_S1 func_8023EBEC_S1;

extern int D_800CB720;

struct Input80216D3C;
typedef struct Input80216D3C Input80216D3C;

struct __OSDir;
struct __OSDir {
    u32 game_code;
    u16 company_code;
    __OSInodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    u8 ext_name[4];
    u8 game_name[16];
};

struct GlyphBuffer;
typedef struct GlyphBuffer GlyphBuffer;

struct func_80207F90_S1;
typedef struct func_80207F90_S1 func_80207F90_S1;

struct Part;
struct Part {
    char pad[0x78];
    u8 active;
};

struct Player_func_8041EAC4_de;
struct Player_func_8041EAC4_de {
    char pad0[0x78];
    u8 active;
    char pad79[0x96 - 0x79];
};

struct TextEntry;
struct TextEntry {
    s32 id;
    char **text;
};

struct Node75_func_802750B0_de;
struct Node75_func_802750B0_de {
    int pad0;
    void *prev;
    void *cur;
    void *next;
};

struct Label;
struct Label {
    char pad0[0x38];
    char *text;
};

struct ObjRecAt128;
typedef struct ObjRecAt128 ObjRecAt128;

struct EffectRecAt154;
struct EffectRecAt154 {
    unsigned char pad0[0x150];
    f32 field150;
    f32 field154;
};

struct Shape;
struct Shape {
    s32 flags;
    s8 enabled;
};

struct Shape;
typedef struct Shape Shape;

struct UnitVtx;
typedef struct UnitVtx UnitVtx;

struct Access_u8_3;
struct Access_u8_3 {
    char pad[0x3];
    u8 field;
};

struct Actor_func_80214310_de;
typedef struct Actor_func_80214310_de Actor_func_80214310_de;

struct Shield;
struct Shield {
    char pad0[0x68];
    f32 factor;
};

struct Header44;
typedef struct Header44 Header44;

struct Key;
typedef struct Key Key;

union func_8028472C_S2_U118;
union func_8028472C_S2_U118 {
    s32 v0;
    s32 * v1;
};

union func_8028472C_S2_U118;
typedef union func_8028472C_S2_U118 func_8028472C_S2_U118;

struct func_8020D0CC_S1;
struct func_8020D0CC_S1 {
    char pad0[0x24];
    void * unk24;
};

struct func_8022CA04_S4;
typedef struct func_8022CA04_S4 func_8022CA04_S4;

struct func_8020EA10_S1;
struct func_8020EA10_S1 {
    char pad0[0x78];
    s32 unk78;
};

struct Triple_func_802683E0_de;
typedef struct Triple_func_802683E0_de Triple_func_802683E0_de;

struct PlayerRecord;
typedef struct PlayerRecord PlayerRecord;

struct Shared_HudView;
struct Shared_HudView {
    char pad0[0x24];
    s32 flags;
    char pad28[0x274];
    f32 width;
    f32 height;
    f32 x;
    f32 y;
};

struct ALEventListItem;
typedef struct ALEventListItem ALEventListItem;

struct func_80207BB8_S4;
struct func_80207BB8_S4 {
    char pad0[0x64];
    f32 unk64;
};

struct func_8022CA04_S4;
struct func_8022CA04_S4 {
    char pad0[0x1C];
    Vec3 unk1C;
};

struct func_80435010_S4;
struct func_80435010_S4 {
    char pad0[0xB9C];
    s32 unkB9C;
};

struct Object_func_80442064_de;
struct Object_func_80442064_de {
    char pad[0x14];
    s32 *source;
};

struct PackedMatrixWords;
struct PackedMatrixWords {
    u32 upper[8];
    u32 lower[8];
};

struct func_8024575C_S1;
typedef struct func_8024575C_S1 func_8024575C_S1;

struct func_80239CDC_S1;
struct func_80239CDC_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x10 - 0xC - sizeof(int)];
    int unk10;
};

struct ObjRecAt128;
struct ObjRecAt128 {
    char pad0[0x128];
    f32 unk128;
};

struct OSPifRam;
struct OSPifRam {
    u32 ramarray[15];
    u32 pifstatus;
};

struct ObjRecAt3CV1;
typedef struct ObjRecAt3CV1 ObjRecAt3CV1;

struct Entry_func_80441EB0_de;
struct List_func_80442574_de;
struct List_func_80442574_de {
    struct Entry_func_80441EB0_de *entries;
    s16 count;
};

struct Record_func_80439C80_de;
struct Record_func_80439C80_de {
    s32 count;
    char pad4[0x34 - 4];
    s32 handle;
};

struct Record_func_80409BDC_de;
struct func_80242278_S1;
struct Record_func_80409BDC_de {
    char pad[0x14];
    void *dialogData; /* 0x14 */
    char pad18[4];
    struct SharedPlayer_func_80226A34_de *player; /* 0x1C */
    struct func_80242278_S1 *inner;
};

struct func_8022A5E4_S2;
struct func_8022A5E4_S2 {
    char pad0[0x16E0];
    void * unk16E0;
};

struct MenuPanelRoot;
struct MenuPanelRoot {
    char pad0[0xCC];
    s32 resource;
    char padD0[4];
    s32 resourceSize;
    s32 selected;
    s32 selectedResource;
    s32 window;
};

struct ReadWord;
struct ReadWord {
    s32 word;
    u8 byte;
};

struct func_802044C8_S1;
typedef struct func_802044C8_S1 func_802044C8_S1;

struct MatchMenuObjects;
struct MatchMenuObjects {
    char pad0[0x17F0];
    s32 transition;
};

struct func_8020E674_S1;
typedef struct func_8020E674_S1 func_8020E674_S1;

struct Shape_typemap_13;
struct Shape_typemap_13 {
    int field_0;
    int field_4;
};

struct func_8028B3C0_S1;
struct func_8028B3C0_S1 {
    char pad0[0x84];
    void * unk84;
};

struct ObjRecAt4V1;
typedef struct ObjRecAt4V1 ObjRecAt4V1;

struct ALPlayer_s;
typedef struct ALPlayer_s ALPlayer_s;

struct ALPlayer_s;
struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    void *handler;
    s32 callTime;
    s32 samplesLeft;
};

struct func_8028469C_S2;
typedef struct func_8028469C_S2 func_8028469C_S2;

struct Queue;
struct Queue {
    char pad[0x14];
    s32 items[4];
};

struct HashNode;
struct HashNode {
    s32 key;
    void *value;
    s32 unk08;
    struct HashNode *next;
};

struct InstanceHdr;
typedef struct InstanceHdr InstanceHdr;

struct OSPfs_func_80445F80_de;
struct OSPfs_func_80445F80_de {
    int status;
    void *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct func_8024C8B4_S1;
typedef struct func_8024C8B4_S1 func_8024C8B4_S1;

struct func_8020C9B0_S1;
struct func_8020C9B0_S1 {
    char pad0[0x8];
    char * unk8;
};

struct func_80245A10_S1;
typedef struct func_80245A10_S1 func_80245A10_S1;

struct ALEventListItem;
struct ALEventListItem {
    Link_func_802596B4_de node;
    s32 delta;
    Message_func_802AF150_de evt;
};

struct Params;
typedef struct Params Params;

struct func_802077F4_S4;
typedef struct func_802077F4_S4 func_802077F4_S4;

struct func_80204BB4_S1;
typedef struct func_80204BB4_S1 func_80204BB4_S1;

struct Queue_func_802BB420_de;
typedef struct Queue_func_802BB420_de Queue_func_802BB420_de;

struct func_802B7EB0_S1;
typedef struct func_802B7EB0_S1 func_802B7EB0_S1;

struct MenuRules;
struct MenuRules {
    char pad0[0x1C];
    s32 locked;
};

struct func_80207B5C_S2;
struct func_80207B5C_S2 {
    char pad0[0x24];
    s32 unk24;
};

struct TextEntry;
typedef struct TextEntry TextEntry;

struct func_802428C0_S2;
typedef struct func_802428C0_S2 func_802428C0_S2;

struct ObjRecAt28V2;
typedef struct ObjRecAt28V2 ObjRecAt28V2;

struct Queue_func_802BB420_de;
struct Queue_func_802BB420_de {
    s32 *state;
    s32 unknown4;
    s32 count;
    s32 start;
    s32 capacity;
    s32 *entries;
};

struct func_80272908_S2;
typedef struct func_80272908_S2 func_80272908_S2;

struct Quad_func_802A1BE0_de;
typedef struct Quad_func_802A1BE0_de Quad_func_802A1BE0_de;

struct Quad_func_802A1BE0_de;
struct Quad_func_802A1BE0_de {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
};

struct Params;
struct Params {
    Triple v;
    s32 w;
};

struct Node80253610;
typedef struct Node80253610 Node80253610;

struct func_8023ECAC_S2;
typedef struct func_8023ECAC_S2 func_8023ECAC_S2;

struct ObjRecAt14V3;
typedef struct ObjRecAt14V3 ObjRecAt14V3;

struct func_80251448_S1;
typedef struct func_80251448_S1 func_80251448_S1;

struct Instance8020CD74;
typedef struct Instance8020CD74 Instance8020CD74;

struct ObjRecAt10V2;
struct ObjRecAt10V2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
};

struct UnitVtx;
struct UnitVtx {
    s16 x;
    s16 y;
    s16 z;
    u16 flag;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

extern int D_800D0910;

struct func_80250DBC_S2;
typedef struct func_80250DBC_S2 func_80250DBC_S2;

struct func_8025C8F8_S1;
struct func_8025C8F8_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
    char pad14[0x28 - 0x14 - sizeof(IntrusiveList)];
    s32 unk28;
};

struct func_8024B8DC_S2;
struct func_8024B8DC_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
};


extern unsigned char D_800D297B;

struct Instance8020CD74;
struct Instance8020CD74 {
    s32 w[2];
    Vec3 position;
    s32 remaining[15];
};

struct ObjRecAt26DD4;
typedef struct ObjRecAt26DD4 ObjRecAt26DD4;

struct ObjRecAt26DD4;
struct ObjRecAt26DD4 {
    char pad0[0x26DD4];
    s32 unk26DD4;
};

struct func_80435010_S3;
struct func_80435010_S3 {
    char pad0[0xB8C];
    u8 unkB8C;
};

struct func_802A2BE0_S1;
typedef struct func_802A2BE0_S1 func_802A2BE0_S1;

extern int D_800CD8B8_de;

struct ObjRecAt1454V1;
struct ObjRecAt1454V1 {
    char pad0[0x1454];
    s32 * unk1454;
};

struct Limit;
struct Limit {
    char pad[0x16];
    s16 limit;
};

struct Triple_func_802683E0_de;
struct Triple_func_802683E0_de {
    s32 x;
    f32 y;
    s32 z;
};

struct World;
struct World {
    u8 pad000[0xFC];
    s32 state;
};

struct func_80251448_S1;
struct func_80251448_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x20 - 0x14 - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
};

struct Field;
struct Field {
    char pad[0x14];
    char **text;
};

struct func_802165F8_S1;
struct func_802165F8_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad14[4];
    struct Model *model; /* +0x18: actor definition */
    char pad1C[0x1C];
    u32 flags; /* +0x38 */
    char pad3C[0x30];
    f32 unk6C;
};

struct Field_void_80;
struct Field_void_80 {
    char pad[0x80];
    void * value;
};

struct func_802558C0_S1;
struct func_802558C0_S1 {
    char pad0[0x20];
    char unk20;
};

struct ObjectState1E_2;
typedef struct ObjectState1E_2 ObjectState1E_2;

struct MatrixF;
typedef struct MatrixF MatrixF;

struct func_8023945C_S1;
typedef struct func_8023945C_S1 func_8023945C_S1;

struct Access_s32_50;
typedef struct Access_s32_50 Access_s32_50;

struct ObjRecAtCV3;
struct ObjRecAtCV3 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
};

struct Target_func_8040AB54_de;
struct Target_func_8040AB54_de {
    char pad[0x120];
    s32 flags;
};
struct RecordRecAtCV3;
struct Target_func_8040AB54_de;
struct RecordRecAtCV3 {
    char pad[0xC];
    struct Target_func_8040AB54_de *target;
};

struct func_8022BECC_S2;
struct func_8022BECC_S2 {
    char pad0[0x8];
    short unk8;
};

struct Header;
struct Header {
    u8 data[0xCC];
};

struct Access_u8_3;
typedef struct Access_u8_3 Access_u8_3;

struct Vec3Words;
typedef struct Vec3Words Vec3Words;

struct func_80258D60_S1;
typedef struct func_80258D60_S1 func_80258D60_S1;

struct func_8022A5E4_S2;
typedef struct func_8022A5E4_S2 func_8022A5E4_S2;

struct func_80245690_S1;
typedef struct func_80245690_S1 func_80245690_S1;

struct ObjRecAtA;
typedef struct ObjRecAtA ObjRecAtA;

struct State_func_80421D94_de;
struct State_func_80421D94_de {
    void *first;
    char pad4[0x10 - 4];
    s32 value;
};

struct HudStatusShared_MatchRules;
struct HudStatusShared_MatchRules {
    char pad0[0x14];
    f32 timeLimit; /* +0x14 */
    char pad18[8];
    s32 hideHud;
    s32 teams;
    char pad28[0x4];
    s32 teamScores[5];
    s32 squadScores[5];
    s32 countRule;
    char pad58[0x20];
    s32 squads;
    char pad7C[0x1C];
    s32 markers;
};

struct Shield;
typedef struct Shield Shield;

struct ItemRecAt10;
struct ItemRecAt10 {
    s32 pad0;
    struct ItemRecAt10 *next;
    char pad8[0xE - 8];
    u16 kind;
    u8 alpha;
};

struct Slot;
struct Slot {
    char data[24];
};

struct MenuPanelRoot;
typedef struct MenuPanelRoot MenuPanelRoot;

typedef void ( *VoidCallback)(void);

struct __OSContRequesFormat;
typedef struct __OSContRequesFormat __OSContRequesFormat;

struct func_80205494_S3;
typedef struct func_80205494_S3 func_80205494_S3;

struct ReadWord;
typedef struct ReadWord ReadWord;

extern int D_800D3650;

struct Buf16;
typedef struct Buf16 Buf16;

struct func_80272BA8_S2;
typedef struct func_80272BA8_S2 func_80272BA8_S2;

struct func_8020D0CC_S2;
typedef struct func_8020D0CC_S2 func_8020D0CC_S2;

struct Buf16;
struct Buf16 {
    s16 count;
    s16 _pad2;
    s32 value;
    s32 _pad8;
    s32 _padC;
};

struct ObjRecAt7528;
typedef struct ObjRecAt7528 ObjRecAt7528;

struct Table;
struct Table {
    s32 unk0;
    s32 unk4;
    s32 deltas[1];
};

struct Request;
struct Request {
    s16 type;
};

struct func_802428C0_S2;
struct func_802428C0_S2 {
    char pad0[0x38];
    unsigned int unk38;
};

struct ControllerRecAtC7;
typedef struct ControllerRecAtC7 ControllerRecAtC7;

struct ALFilter_s_func_802B3000_de;
struct ALFilter_s_func_802B3000_de {
    struct ALFilter_s_func_802B3000_de *source;
    void *handler;
    ALSetParam setParam;
};

extern int D_801427D0;

struct Field_u16_14;
typedef struct Field_u16_14 Field_u16_14;

struct func_804360F4_S2;
struct func_804360F4_S2 {
    char pad0[0x1C];
    void * unk1C;
};

struct ALFilter_s_func_802B3000_de;
struct ALVoice_s_func_802B3000_de;
struct PVoice_s_func_802B3000_de;
struct PVoice_s_func_802B3000_de {
    Link_func_802596B4_de node;
    struct ALVoice_s_func_802B3000_de *vvoice;
    struct ALFilter_s_func_802B3000_de *channelKnob;
    char pad10[0xD8 - 0x10];
    s32 offset;
};

struct ALVoice_s_func_802B3000_de {
    Link_func_802596B4_de node;
    struct PVoice_s_func_802B3000_de *pvoice;
    void *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
};

struct FieldRecAt14;
struct FieldRecAt14 {
    char pad[0x14];
    char *text;
};

struct Header44;
struct Header44 {
    s32 words[11];
};

struct ImageHeader;
struct ImageHeader {
    char pad0[2];
    unsigned char widthShift;
    unsigned char heightShift;
    char pad4[0x1D - 4];
    unsigned char scale;
    char pad1E[0x21 - 0x1E];
    unsigned char width;
    unsigned char height;
    unsigned char format;
    char data[1];
};
struct Image;
struct ImageHeader;
struct Image {
    char pad0[8];
    struct ImageHeader *header;
    s32 fieldC;
    s32 field10;
    char pad14[0x3C - 0x14];
    s32 flags;
};

extern float D_800C4458_de;

struct ObjRecAt6V1;
typedef struct ObjRecAt6V1 ObjRecAt6V1;

struct func_8028DA50_S1;
typedef struct func_8028DA50_S1 func_8028DA50_S1;

extern int D_800D5258;

struct func_802A68A0_S3;
struct func_802A68A0_S3 {
    char pad0[0x118];
    void * unk118;
};

struct ObjRecAtDC;
struct ObjRecAtDC {
    char pad0[0xDC];
    s16 unkDC;
};

struct ModelDef;
struct ModelDef {
    char pad0[0xE];
    u8 colour;
};

struct func_80284AF4_G2;
typedef struct func_80284AF4_G2 func_80284AF4_G2;

struct Obj_func_802B3EDC_de;
struct Obj_func_802B3EDC_de {
    char pad14[0x14];
    s32 count;
    char pad18[0x4];
    s32 *base;
};

struct Brain_func_80212D78_eu_x;
typedef struct Brain_func_80212D78_eu_x Brain_func_80212D78_eu_x;

struct ObjRecAt1D8V3;
struct ObjRecAt1D8V3 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0xC4 - 0x10 - sizeof(f32)];
    s32 unkC4;
    char padC4[0xD0 - 0xC4 - sizeof(s32)];
    s32 unkD0;
    char padD0[0x100 - 0xD0 - sizeof(s32)];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    void * unk1D8;
};

struct func_8020478C_S1;
typedef struct func_8020478C_S1 func_8020478C_S1;

struct Access_s32_50;
struct Access_s32_50 {
    char pad[0x50];
    s32 field;
};

union func_8026E158_S1_U8;
union func_8026E158_S1_U8 {
    s32 v0;
    char v1;
};

struct func_8020C9B0_S1;
typedef struct func_8020C9B0_S1 func_8020C9B0_S1;

struct func_80275120_S1;
typedef struct func_80275120_S1 func_80275120_S1;

struct func_80239760_S2;
struct func_80239760_S2 {
    char pad0[0xE40];
    IntrusiveList unkE40;
};

struct func_802A2E5C_S2;
struct func_802A2E5C_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xE - 0x4 - sizeof(void*)];
    u16 unkE;
    char padE[0x10 - 0xE - sizeof(u16)];
    s8 unk10;
};

struct func_80242278_S2;
typedef struct func_80242278_S2 func_80242278_S2;

struct ObjRecAt1CV3;
typedef struct ObjRecAt1CV3 ObjRecAt1CV3;

struct Work56EC8;
struct Work56EC8 {
    void *owner;
    s16 id;
    char pad6[2];
    char payload[0x40];
    void *base;
    s32 offset;
};

struct MenuSettings;
typedef struct MenuSettings MenuSettings;

struct func_8023ECAC_S2;
struct func_8023ECAC_S2 {
    char pad0[0x44];
    s32 unk44;
    char pad44[0x52 - 0x44 - sizeof(s32)];
    u16 unk52;
};

struct PackedMatrixWords;
typedef struct PackedMatrixWords PackedMatrixWords;

struct ObjRecAt2CV2;
typedef struct ObjRecAt2CV2 ObjRecAt2CV2;

struct func_8020CA10_S2;
typedef struct func_8020CA10_S2 func_8020CA10_S2;

struct func_80254D70_S2;
struct func_80254D70_S2 {
    char pad0[0x8];
    s32 unk8;
};

struct func_8025BD20_S1;
typedef struct func_8025BD20_S1 func_8025BD20_S1;

struct func_8020D0CC_S2;
struct func_8020D0CC_S2 {
    char pad0[0x10];
    void * unk10;
};

struct ObjRecAt1CV1;
typedef struct ObjRecAt1CV1 ObjRecAt1CV1;

struct Header;
typedef struct Header Header;

extern int D_800CC370;

struct StateRecAt14;
struct StateRecAt14 {
    char a[8];
    s32 unk8;
    char b[8];
    char *unk14;
};

struct StateBlock;
struct StateBlock {
    char pad0[0x84];
    s32 unk84;
};

struct Shared_GameMode;
typedef struct Shared_GameMode Shared_GameMode;

extern int D_800E63AC;

struct func_80245A10_S1;
struct func_80245A10_S1 {
    char pad0[0x104];
    int unk104;
};

struct Args;
struct Args {
    u32 words[10];
};

struct func_8025E58C_S1;
typedef struct func_8025E58C_S1 func_8025E58C_S1;

struct Field_f32_10;
struct Field_f32_10 {
    char pad[0x10];
    f32 value;
};

struct func_80435010_S4;
typedef struct func_80435010_S4 func_80435010_S4;

struct PlayerRecAt58;
struct PlayerRecAt58 {
    char pad[0x58];
    int state;
    char pad5C[0xB68 - 0x5C];
};

struct func_8025CA44_S1;
struct func_8025CA44_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
};

extern int D_801534F0[];

struct HashNode;
typedef struct HashNode HashNode;

struct ObjRecAtA;
struct ObjRecAtA {
    char pad0[0xA];
    short unkA;
};

struct func_8029A838_S1;
typedef struct func_8029A838_S1 func_8029A838_S1;

struct Record;
typedef struct Record Record;

extern float D_80146CB8;

struct func_802558C0_S1;
typedef struct func_802558C0_S1 func_802558C0_S1;

struct Shape_typemap_71;
struct Shape_typemap_71 {
    unsigned char padding_0[28];
    int field_1C;
};

struct func_8024E58C_S1;
struct func_8024E58C_S1 {
    f32 unk0;
    char pad0[0x8 - 0x0 - sizeof(f32)];
    f32 unk8;
};

struct BufferPool;
typedef struct BufferPool BufferPool;

struct Request;
typedef struct Request Request;

struct func_80284AF4_G2;
struct func_80284AF4_G2 {
    void * unk0;
};

struct ObjRecAt10V2;
typedef struct ObjRecAt10V2 ObjRecAt10V2;

struct ObjRecAt18V2;
struct ObjRecAt18V2 {
    char pad0[0x18];
    s32 * unk18;
};

struct ObjRecAt6V1;
struct ObjRecAt6V1 {
    char pad0[0x6];
    unsigned short unk6;
};

struct func_80206930_S3;
struct func_80206930_S3 {
    char pad0[0x7];
    unsigned char unk7;
};

struct func_8029A9E0_S1;
typedef struct func_8029A9E0_S1 func_8029A9E0_S1;

struct Shared_HudView;
typedef struct Shared_HudView Shared_HudView;

struct State_func_8043E254_de;
struct State_func_8043E254_de {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[4];
    s32 unk28;
};

struct StateRecAt14;
typedef struct StateRecAt14 StateRecAt14;

struct ObjectLinks24_2;
struct ObjectLinks24_2 {
    char * unk_0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    char * unk_4;
    void * unk_8;
    void * unk_C;
    char padC[0x10 - 0xC - sizeof(void*)];
    s32 unk_10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
};

struct func_8020F2A8_S3;
typedef struct func_8020F2A8_S3 func_8020F2A8_S3;

struct func_802831FC_S1;
typedef struct func_802831FC_S1 func_802831FC_S1;

struct Link;
struct Link {
    unsigned short from;
    unsigned short to;
    unsigned char type;
};

struct CollisionInfo;
struct CollisionInfo {
    s32 w[8];
};

struct ObjRecAt14V1;
struct ObjRecAt14V1 {
    char pad0[0x14];
    void * unk14;
};

struct OSPifRam;
typedef struct OSPifRam OSPifRam;

struct func_8026E158_S1;
struct func_8026E158_S1 {
    char pad0[0x8];
    func_8026E158_S1_U8 unk8;
};

struct ObjRecAt1454V1;
typedef struct ObjRecAt1454V1 ObjRecAt1454V1;

struct func_80293268_S2;
struct func_80293268_S2 {
    char pad0[0x26DBC];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    s8 unk26DC1;
    char pad26DC1[0x26DD8 - 0x26DC1 - sizeof(s8)];
    s32 unk26DD8;
    char pad26DD8[0x26DDC - 0x26DD8 - sizeof(s32)];
    s32 unk26DDC;
};

struct func_80435010_S3;
typedef struct func_80435010_S3 func_80435010_S3;

struct Slots_func_8041B7FC_de;
struct Slots_func_8041B7FC_de {
    char pad[0x4C];
    struct Node_func_8040EB48_de *values[1];
};

struct CellRecAt1A;
typedef struct CellRecAt1A CellRecAt1A;

struct D_800C7470_Pair;
struct D_800C7470_Pair {
    f32 first;
    f32 second;
};

struct func_8024C8B4_S1;
struct func_8024C8B4_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
};

struct Pair14;
struct Pair14 {
    char pad[0x14];
    s16 first;
    s16 second;
};

struct ObjRecAt40V1;
struct ObjRecAt40V1 {
    char p[0x40];
    s32 unk40;
};

struct func_8020E674_S1;
struct func_8020E674_S1 {
    char pad0[0x8];
    func_8020E674_S1_U8 unk8;
};

struct func_80272BA8_S2;
struct func_80272BA8_S2 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x20 - 0x18 - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
};

struct func_804360F4_S2;
typedef struct func_804360F4_S2 func_804360F4_S2;

struct func_802B4ECC_S1;
struct func_802B4ECC_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x24 - 0x18 - sizeof(void*)];
    s32 unk24;
};

struct SlotRecAt0V1;
struct SlotRecAt0V1 {
    s32 key;
    char pad[0x70 - 4];
};

struct Shape_typemap_30;
struct Shape_typemap_30 {
    unsigned char padding_0[32];
    int field_20;
};

struct Block24;
struct Block24 {
    s32 words[6];
};

struct ALVoiceConfig_s;
struct ALVoiceConfig_s {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
};

struct IntegerStateDC_2;
typedef struct IntegerStateDC_2 IntegerStateDC_2;

struct func_802077F4_S4;
struct func_802077F4_S4 {
    char pad0[0x40];
    f32 unk40;
};

struct List;
struct List {
    char pad0[0x48];
    u8 visibleX;
    u8 visibleY;
    u8 maxX;
    u8 maxY;
    u8 cursorX;
    u8 cursorY;
    u8 scrollX;
    u8 scrollY;
    u8 minX;
    u8 minY;
};

struct ObjRecAt7528;
struct ObjRecAt7528 {
    char pad0[0x7528];
    void * unk7528;
};

struct func_8025C598_S1;
struct func_8025C598_S1 {
    s32 unk0;
    char pad0[0xB0 - 0x0 - sizeof(s32)];
    s32 unkB0;
};

struct MatchMenuObjects;
typedef struct MatchMenuObjects MatchMenuObjects;

struct func_80247F08_S1;
struct func_80247F08_S1 {
    char pad0[0x30];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
};

struct ControllerProfile;
/* Four-byte controller connection sample copied with the button history. */
typedef struct ControllerConnectionSample {
    u16 reserved;
    u8 connectionStatus;
    u8 flags;
} __attribute__((aligned(4))) ControllerConnectionSample;
struct ControllerProfile {
    u8 padding000[4];
    s8 port; /* 0x04 */
    u8 padding005[0x18 - 5];
    s32 inputButtons; /* 0x18 */
    ControllerConnectionSample inputConnection; /* 0x1C */
    s32 inputHistory[3]; /* 0x20 */
    u8 padding02C[0xAC - 0x2C];
    s32 previousButtons; /* 0xAC */
    s32 buttons; /* 0xB0 */
    ControllerConnectionSample connection; /* 0xB4 */
    s32 history[2]; /* 0xB8 */
    u32 buttonState; /* 0xC0 */
    s8 stickX; /* 0xC4 */
    s8 stickY; /* 0xC5 */
    s8 previousStickX; /* 0xC6 */
    s8 previousStickY; /* 0xC7 */
    u8 padding0C8[4];
    s32 mode; /* 0xCC */
    u8 padding0D0[0x224 - 0xD0];
};

struct Args;
typedef struct Args Args;

struct ObjRecAt8V2;
typedef struct ObjRecAt8V2 ObjRecAt8V2;

struct func_80272848_S1;
typedef struct func_80272848_S1 func_80272848_S1;

struct Actor_func_80214310_de;
struct Actor_func_80214310_de {
    char pad0[8];
    Vec3 position;
    char pad14[0x70 - 0x14];
    f32 eye;
};

struct World_func_8028787C_de;
typedef struct World_func_8028787C_de World_func_8028787C_de;

struct ObjectState1E;
typedef struct ObjectState1E ObjectState1E;

extern int D_800CC38C;

struct func_80203908_S4;
typedef struct func_80203908_S4 func_80203908_S4;

struct Link;
typedef struct Link Link;

struct Draw;
struct Draw {
    char pad0[8];
    s32 allocationMode; /* 0x08: resource allocation request */
    void *model;
    char reserved10[0x10];
    IntrusiveList recycled; /* 0x20 */
};

struct Field_void_4;
typedef struct Field_void_4 Field_void_4;

struct func_80293268_S1;
typedef struct func_80293268_S1 func_80293268_S1;

struct func_80250BD4_S1;
typedef struct func_80250BD4_S1 func_80250BD4_S1;

struct ALEvent_func_802B21A8_de;
typedef struct ALEvent_func_802B21A8_de ALEvent_func_802B21A8_de;

struct func_8022E694_S1;
struct func_8022E694_S1 {
    char pad0[0x44];
    s32 unk44;
};

struct ObjRecAt14V2;
struct ObjRecAt14V2 {
    char pad[0x14];
    u8 **unk14;
};

struct func_8020478C_S1;
struct func_8020478C_S1 {
    char pad0[0x4];
    unsigned short unk4;
    char pad4[0xA - 0x4 - sizeof(unsigned short)];
    unsigned short unkA;
};

struct World_func_8028787C_de;
struct World_func_8028787C_de {
    u8 padding000[0x80];
    void *levels; /* 0x80 */
    void *secondaryLevels; /* 0x84 */
    u8 padding088[0x1B384];
    s32 level; /* 0x1B40C */
};

struct func_80250DBC_S2;
struct func_80250DBC_S2 {
    char pad0[0xE];
    s8 unkE;
};

struct Field_void_80;
typedef struct Field_void_80 Field_void_80;

struct Node80253610;
struct Node80253610 {
    s32 field0;
    s32 field4;
    s32 references;
    u32 flags;
};

struct ObjRecAt14V2;
typedef struct ObjRecAt14V2 ObjRecAt14V2;

struct func_80247F08_S1;
typedef struct func_80247F08_S1 func_80247F08_S1;

struct HudStatusShared_Settings;
typedef struct HudStatusShared_Settings HudStatusShared_Settings;

struct func_80204BB4_S1;
struct func_80204BB4_S1 {
    char pad0[0x2C];
    void * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(void*)];
    void * unk108;
};

struct func_80239760_S2;
typedef struct func_80239760_S2 func_80239760_S2;

struct func_8023EBEC_S1;
struct func_8023EBEC_S1 {
    char pad0[0x3C];
    s32 unk3C;
};


struct func_8022CA04_S3;
typedef struct func_8022CA04_S3 func_8022CA04_S3;

struct NodeEvent;
typedef struct NodeEvent NodeEvent;

struct Style_func_8043C9AC_de;
typedef struct Style_func_8043C9AC_de Style_func_8043C9AC_de;

struct Access_s32_5C;
typedef struct Access_s32_5C Access_s32_5C;

struct ObjRecAt130;
typedef struct ObjRecAt130 ObjRecAt130;

struct func_80293268_S1;
struct func_80293268_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x88 - 0xC - sizeof(s32)];
    s32 unk88;
};

struct Work56EC8;
typedef struct Work56EC8 Work56EC8;

struct Table;
typedef struct Table Table;

extern int D_80153500[];

struct func_8029A838_S1;
struct func_8029A838_S1 {
    s32 unk0;
    char pad0[0x10 - 0x0 - sizeof(s32)];
    s32 unk10;
};

struct RecordRecAt14;
struct RecordRecAt14 {
    char pad[8];
    s32 flags;
    char padC[0x14 - 0xC];
    s32 value;
};

struct ResourceManagerState;
typedef struct ResourceManagerState ResourceManagerState;

struct StridedTable;
typedef struct StridedTable StridedTable;

struct D_800C7470_Pair;
typedef struct D_800C7470_Pair D_800C7470_Pair;

struct ProfileRecAt16;
typedef struct ProfileRecAt16 ProfileRecAt16;

struct ObjRecAtB0;
typedef struct ObjRecAtB0 ObjRecAtB0;

struct ControllerProfile;
typedef struct ControllerProfile ControllerProfile;

struct func_8024B8DC_S2;
typedef struct func_8024B8DC_S2 func_8024B8DC_S2;

struct func_80205494_S3;
struct func_80205494_S3 {
    char pad0[0x14];
    unsigned int unk14;
};

struct TextLayerRect;
struct TextLayerRect {
    char pad[0x14];
    int x;
    int right;
    int y;
};

struct Shared_GameMode;
struct Shared_GameMode {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x8];
    s32 unk28;
};

struct Query;
struct Query {
    f32 radius;
    f32 bottom;
    f32 top;
    f32 top1;
    f32 bottom1;
    f32 top2;
    f32 bottom2;
    f32 minX;
    f32 minZ;
    f32 maxX;
    f32 maxZ;
    s32 flag;
};

struct ItemRecAt10;
struct MenuRecAt54;
struct MenuRecAt54 {
    char pad0[8];
    struct ItemRecAt10 *items;
    char padC[0x54 - 0xC];
    s32 state;
};

struct func_8022E3B4_S3;
struct func_8022E3B4_S3 {
    char pad0[0x4];
    s16 unk4;
};

extern int D_80100598[];

struct ObjRecAt3CV1;
struct ObjRecAt3CV1 {
    char pad0[0x14];
    f32 unk14;
    char pad14[0x24 - 0x14 - sizeof(f32)];
    f32 unk24;
    char pad24[0x34 - 0x24 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

struct func_80204468_S2;
typedef struct func_80204468_S2 func_80204468_S2;

struct func_80203908_S4;
struct func_80203908_S4 {
    char pad0[0x6C];
    f32 unk6C;
};

struct PixelFormat;
struct PixelFormat {
    char pad0[0x14];
    u32 mask[4];
    s32 shift[4];
};

struct ObjRecAtDC;
typedef struct ObjRecAtDC ObjRecAtDC;

struct func_8020D9C0_S1;
typedef struct func_8020D9C0_S1 func_8020D9C0_S1;

struct func_802045CC_S1;
typedef struct func_802045CC_S1 func_802045CC_S1;

struct ALFilter_s_func_802B3000_de;
typedef struct ALFilter_s_func_802B3000_de ALFilter_s_func_802B3000_de;

struct ObjectStateC_2;
typedef struct ObjectStateC_2 ObjectStateC_2;

struct func_8026E158_S1;
typedef struct func_8026E158_S1 func_8026E158_S1;

struct PixelFormat;
typedef struct PixelFormat PixelFormat;

struct Input80216D3C;
struct Input80216D3C {
    s32 unk0;
    s32 unk4;
    Triple vec;
};

struct CallbackStateC_4;
struct CallbackStateC_4 {
    char pad0[0x8];
    void (*callback)(void *, s32, void *);
};

struct func_8029A9E0_S1;
struct func_8029A9E0_S1 {
    char pad0[0x4];
    unsigned int unk4;
};

struct State_func_80421BEC_de;
typedef struct State_func_80421BEC_de State_func_80421BEC_de;

struct RecordRecAt20V1;
struct ObjRecAtB0;
struct RecordRecAt20V1 {
    char pad[0x20];
    struct ObjRecAtB0 *inner;
};

struct Status;
struct Status {
    char pad0[0x78];
    u8 active;
    char pad79[0x80 - 0x79];
    s8 kind;
    char pad81[150 - 0x81];
};

struct Model;
typedef struct Model Model;

struct func_802428C0_S1;
typedef struct func_802428C0_S1 func_802428C0_S1;

struct func_802045CC_S1;
struct func_802045CC_S1 {
    char pad0[0x12C];
    s32 unk12C;
};

struct EntryRecAt8V1;
struct EntryRecAt8V1 {
    s32 unused;
    s32 flags;
    char rest[0x14];
};

struct HudStatusShared_Settings;
struct HudStatusShared_Settings {
    s32 flags;
    s32 selection;
    char pad8[0x5];
    u8 trialKind;
    char padE[0x8];
    u8 hudFade;
    char pad17[0x6];
    u8 hudShown;
    char pad1E[0xB2];
    ListScreenRecord roster[8];
    char pad580[0x1];
    u8 language;
    char pad582[0x32];
    s32 state;
    char pad5B8[0x20];
    HudStatusShared_MatchRules rules;
    char pad674[0xC];
    s32 humanWon;
};

struct func_80205700_S1;
struct func_80205700_S1 {
    char pad0[0xC];
    unsigned int unkC;
};

extern int D_8010BBF0[];

struct WeaponInfo;
typedef struct WeaponInfo WeaponInfo;

struct func_8024575C_S1;
struct func_8024575C_S1 {
    char pad0[0xDC];
    int unkDC;
};

struct func_8020D9C0_S1;
struct func_8020D9C0_S1 {
    char pad0[0x14];
    f32 unk14;
};

extern int D_800CC388;

struct ObjRecAt28V2;
struct ObjRecAt28V2 {
    char pad0[0x28];
    int unk28;
};

struct EventRecAt14;
typedef struct EventRecAt14 EventRecAt14;

struct func_8022BC04_S3;
struct func_8022BC04_S3 {
    char pad0[0x10];
    s32 unk10;
};

struct func_802A2BE0_S1;
struct func_802A2BE0_S1 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x12 - 0x8 - sizeof(void*)];
    u16 unk12;
};

struct ObjRecAt4V3;
typedef struct ObjRecAt4V3 ObjRecAt4V3;

struct MenuSettings;
struct MenuSettings {
    u8 padding[0x581];
    u8 language;
};

struct func_802B7EB0_S1;
struct func_802B7EB0_S1 {
    char pad0[0x14];
    char unk14;
    char pad14[0x3C - 0x14 - sizeof(char)];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
};

struct func_802831FC_S1;
struct func_802831FC_S1 {
    char pad0[0xFC3C];
    s8 * unkFC3C;
};

struct IntegerStateDC_2;
struct IntegerStateDC_2 {
    unsigned char padding[216];
    s32 state;
};

struct func_8022E3B4_S3;
typedef struct func_8022E3B4_S3 func_8022E3B4_S3;

struct func_80239CDC_S1;
typedef struct func_80239CDC_S1 func_80239CDC_S1;

struct func_8020F2A8_S3;
struct func_8020F2A8_S3 {
    char pad0[0x34];
    s32 unk34;
};

struct Node_func_80285B64_de;
typedef struct Node_func_80285B64_de Node_func_80285B64_de;

struct func_8024C5C4_S2;
struct func_8024C5C4_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    char unk8;
};

struct func_80258614_S1;
struct func_80258614_S1 {
    char pad0[0x110];
    s32 unk110;
    char pad110[0x138 - 0x110 - sizeof(s32)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
};

struct Obj_func_802B3EDC_de;
typedef struct Obj_func_802B3EDC_de Obj_func_802B3EDC_de;

struct func_8020D0CC_S1;
typedef struct func_8020D0CC_S1 func_8020D0CC_S1;

struct ParamsRecAt8V1;
struct ParamsRecAt8V1 {
    s16 f0;
    s32 f4;
    s16 f8;
};

struct func_802428C0_S1;
struct func_802428C0_S1 {
    char pad0[0x3C];
    unsigned int unk3C;
};

extern int D_80145070;

struct PlayerRecord;
struct PlayerRecord {
    char data[0x190];
};

struct ObjRecAt4V3;
struct ObjRecAt4V3 {
    void * unk0;
    char pad0[0x4 - 0x0 - sizeof(void*)];
    s32 unk4;
};

struct func_8025E5B0_S1;
typedef struct func_8025E5B0_S1 func_8025E5B0_S1;

#endif
