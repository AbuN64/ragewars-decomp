#ifndef COMMON_ITEMRECAT20V1_H
#define COMMON_ITEMRECAT20V1_H
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
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

/* Resource node pool: word 0 is the free-node count, word 0x11 the frame stamp;
   the cache record D_80100570 sits 0xBCC bytes below. */
struct Pool {
    s32 count;
    char pad[0x40];
    s32 field44;
};
extern s32 D_8010513C;

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

struct CellRecAt1A;

struct CellRecAt1A;
struct Menu_func_804241BC_de;
struct Menu_func_804241BC_de {
    char pad[0x44];
    struct CellRecAt1A *list;
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

struct NodeCode8028469C;
struct NodeCode8028469C {
    struct NodeCode8028469C *previous;
    struct NodeCode8028469C *next;
    Clip *key;
    CVector3 position;
    f32 value0;
    f32 value1;
    u32 amplitudeHandle; /* 0x20 */
    char pad24[8];
    u32 lifetimeHandle; /* 0x2C */
    char pad30[8];
    struct NodeCode8028469C **owner;
};

/* Shared free/active node pool initialized by func_80285AC4_de. */
struct PoolRecAt28V1 {
    IntrusiveList free;
    IntrusiveList active;
    s32 baseLevel;
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
    CVector3 v1;
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
struct ALNoteEvent;
struct ALOscEvent;
struct ALVolumeEvent;
struct ALEndEvent;
struct ALTempoEvent;
struct ALEvent;
typedef struct ALNoteEvent ALNoteEvent;
typedef struct ALOscEvent ALOscEvent;
typedef struct ALVolumeEvent ALVolumeEvent;
typedef struct ALEndEvent ALEndEvent;
typedef struct ALTempoEvent ALTempoEvent;
typedef struct ALEvent ALEvent;


struct ListLink;
struct ListLink {
    struct ListLink *next;
    struct ListLink *prev;
};
struct ListLink;
typedef struct ListLink ListLink;

struct ALEventQueue;
struct ALEventQueue {
    ListLink freeList;
    ListLink allocList;
    s32 eventCount;
};

struct ALEvent;

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

struct MenuWidget;
struct MenuWidget {
    char pad0[4];
    struct MenuWidget *sibling;
    struct MenuWidget *child;
    s16 resource;
    u16 kind;
    u8 alpha;
    char pad11[0x1];
    u16 flags;
    s16 x;
    s16 y;
    union { s16 width; s16 w; };
    s16 height;
    char pad1C[0x2C - 0x1C];
    s32 value;
    struct MenuWidget *next;
    s32 field34;
    union { void *text; s32 image; s32 word38; };
    char pad3C[0x8];
    void *field_44;
    u8 field_48;
    u8 field_49;
    u8 field_4A;
    u8 field_4B;
    u8 field_4C;
    u8 field_4D;
    u8 field_4E;
    u8 field_4F;
    u8 field_50;
    u8 field_51;
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
    ListLink node;
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


typedef signed int ( *Handler802A2B50)(void *, signed int, signed int, signed int, signed int);

struct Field_f32_10;
typedef struct Field_f32_10 Field_f32_10;

struct Actor_func_8024A1D0_de;
struct Actor_func_8024A1D0_de {
    char pad0[3];
    s8 pass;
    u32 pad4;
    CVector3 position0;
    u32 pad14[2];
    CVector3 position1;
    u32 pad28[13];
    CQuatern rotation;
    char pad6C[0xB4 - 0x6C];
    void *animation;
    char padB8[0x140 - 0xB8];
    Shared_ParticleLighting lighting[2];
};

struct Resource_func_80419E54_de;
struct Resource_func_80419E54_de {
    char pad[0x10];
    unsigned char value;
    char pad11[0x1B];
    signed int frame;
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

struct OwnerCode8043DF84;
struct OwnerCode8043DF84 {
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
    u8 text[20];
};

struct Key;
struct OwnerRecAt38;
struct OwnerRecAt38 {
    char pad[0x38];
    struct Key *selected;
};

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
    CVector3 normal;
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

struct RecCode80291054;
typedef struct RecCode80291054 RecCode80291054;

struct func_80207B5C_S2;
typedef struct func_80207B5C_S2 func_80207B5C_S2;

extern int D_8010515C;

struct Player_func_804356BC_de;
struct Player_func_804356BC_de {
    s32 state;
    char pad4[0x14];
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

struct OSMesgQueue;

struct Desc;
struct Desc {
    char pad[0x108];
    s32 caps[4];
};

struct OwnerRecAt5D8V2;
struct PlayerOptions;
struct OwnerRecAt5D8V2 {
    char pad[0x5D8];
    struct PlayerOptions *settings; /* its name text comes first */
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
    u16 field0;
    u16 flags; /* +0x02: Scene_FindFloorPolygon, mask0x40 */
    CVector3 *prev;
    CVector3 *cur;
    CVector3 *next;
    u8 reserved10[0x10]; /* ROM advances terrain records by0x20 */
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
    CVector3 unk128;
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
    char pad79[6];
    u8 slot; /* +0x7F */
    s8 character; /* +0x80 */
    u8 variant; /* +0x81: selected costume */
    char pad82[0xF];
    u8 out;
    char pad92[0x4];
};


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

struct CROMInitialOrientation_t;
struct CROMInitialOrientation_t {
    CVector3 position;
    s16 unk_C;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 m_RotY;
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


struct Object6C;
struct Object6C {
    char pad[0x6C];
    s32 value;
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
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;

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

struct TextBoundsText;
struct MenuStyle;
/* The draw style menu item callbacks receive last: alpha and fade scale the item's intensity. */
struct MenuStyle {
    /* The same record func_8043FE3C_de draws through as its fourth argument (func_8043FFAC_S2), and
       func_80445BC0_de reads its id at +0x1C. */
    s16 state;
    s16 x; /* 0x02 */
    s16 y; /* 0x04 */
    char pad6[6];
    struct TextBoundsText *entries; /* 0x0C */
    s32 count; /* 0x10 */
    char pad14[0x1C - 0x14];
    s32 id; /* 0x1C */
    char pad20[0x30 - 0x20];
    f32 alpha; /* 0x30 */
    f32 fade; /* 0x34 */
    s32 unk38;
    s32 unk3C;
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

struct MenuMarker;
struct MenuMarker {
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
    ListLink pFreeList;
    ListLink pAllocList;
    ListLink pLameList;
    s32 paramSamples;
};

struct OSThread_s;

struct ObjRecAt18V2;
typedef struct ObjRecAt18V2 ObjRecAt18V2;

struct func_80254D70_S2;
typedef struct func_80254D70_S2 func_80254D70_S2;


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
    CVector3 value;
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

struct CROMInitialOrientation_t;
typedef struct CROMInitialOrientation_t CROMInitialOrientation_t;

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
struct StateCode80420E90;
struct StateCode80420E90 {
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

struct TutorialProgress;
typedef struct TutorialProgress TutorialProgress;

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
    s32 dirty;
};

struct Node_func_80239AF4_de;
typedef struct Node_func_80239AF4_de Node_func_80239AF4_de;

struct Node_func_80239AF4_de;
struct Node_func_80239AF4_de {
    struct Node_func_80239AF4_de *next;
};

struct ShapeCode802B54A0;
typedef struct ShapeCode802B54A0 ShapeCode802B54A0;

struct ControllerRecAtC7;
struct ControllerRecAtC7 {
    char pad0[0xC6];
    s8 x;
    s8 y;
};

struct CROMEventEntry_t;
struct IntPair;
struct CROMEventEntry_t {
    u16 frame;
    u16 effect;
    s16 bone;
    s16 pad6;
    CVector3 local;
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
        struct { s32 header[2]; CVector3 position; } spatial;
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
    CVector3 unk1C;
};

struct func_80435010_S4;
struct func_80435010_S4 {
    char pad0[0xB9C];
    s32 unkB9C;
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
struct Dialog;
struct Dialog {
    struct Entry_func_80441EB0_de *entries;
    s16 count;
    char pad6[0x1A];
    signed int value;
};

struct Record_func_80439C80_de;
struct Record_func_80439C80_de {
    s32 count;
    char pad4[0x34 - 4];
    s32 handle;
};

struct Shared_PakMenu;
struct PakMenuSlot;

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

struct RecCode802080008020E674;
typedef struct RecCode802080008020E674 RecCode802080008020E674;

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

struct func_8024C8B4_S1;
typedef struct func_8024C8B4_S1 func_8024C8B4_S1;

struct func_8020C9B0_S1;
struct func_8020C9B0_S1 {
    char pad0[0x8];
    char * unk8;
};

struct func_80245A10_S1;
typedef struct func_80245A10_S1 func_80245A10_S1;


struct Params;
typedef struct Params Params;

struct func_802077F4_S4;
typedef struct func_802077F4_S4 func_802077F4_S4;

struct func_80204BB4_S1;
typedef struct func_80204BB4_S1 func_80204BB4_S1;

struct OSMesgQueue;

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
    CVector3 position;
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
    s32 unk0;
    char pad4[0x84];
    s32 unk88;
    char pad8C[0x4];
    signed int resource;
    char pad94[0x8];
    s32 unk9C;
    char padA0[0x10];
    s32 unkB0;
    char padB4[0x10];
    s32 unkC4;
    char padC8[0x34];
    s32 state;
    s32 unk100;
    char pad104[0x34];
    void *unk138;
    signed int unk13C;
    signed int unk140;
    char pad144[0xE14];
    signed int unkF58;
    char padF5C[0x1A4B0];
    signed int unk1B40C;
    char pad1B410[0xC];
    signed int unk1B41C;
    char pad1B420[20];
    signed int unk1B434;
    char pad1B438[0x1DC];
    float unk1B614;
    float unk1B618;
    float unk1B61C;
    struct EntryRecAt18V4 *list[16];
    signed int count;
};
typedef struct World World;

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
    char pad18[0x4];
    signed int value;
};

struct func_802165F8_S1;
struct func_802165F8_S1 {
    char pad0[0x8];
    CVector3 unk8;
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

struct ShapeCode802B54A0;
struct ShapeCode802B54A0 {
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
    ListLink node;
    struct ALVoice_s_func_802B3000_de *vvoice;
    struct ALFilter_s_func_802B3000_de *channelKnob;
    char pad10[0xD8 - 0x10];
    s32 offset;
};

struct ALVoice_s_func_802B3000_de {
    ListLink node;
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

struct OSThread_s;

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
struct ALEndEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
};
struct ALTempoEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
};
struct ALNoteEvent {
    struct ALVoice_s *voice;
};
struct ALVolumeEvent {
    struct ALVoice_s *voice;
    s32 delta;
    u8 vol;
};
struct ALOscEvent {
    struct ALVoiceState *vs;
    void *oscState;
    u8 chan;
};
struct ALEvent {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        ALEndEvent end;
        ALNoteEvent note;
        ALVolumeEvent vol;
        Request spvol;
        InventorySlot sppriority;
        func_80284AF4_G2 spseq;
        func_80284AF4_G2 spbank;
        ALOscEvent osc;
    } msg;
};
struct ALEventListItem {
    ListLink node;
    s32 delta;
    ALEvent evt;
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

struct TutorialProgress;
struct TutorialProgress {
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

struct RecCode8026AC38;
struct RecCode8026AC38 {
    char pad0[0x8];
    func_8026E158_S1_U8 unk8;
};

struct ObjRecAt1454V1;
typedef struct ObjRecAt1454V1 ObjRecAt1454V1;

struct RecCode80291054;
struct RecCode80291054 {
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

struct SlotsCode804196C0;
struct SlotsCode804196C0 {
    char pad[0x4C];
    struct WidgetNode *values[1];
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

struct RecCode802080008020E674;
struct RecCode802080008020E674 {
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

/* Per-button tap, age, repeat and hold counters consumed by the input update. */
typedef struct ControllerButtonHistory {
    s8 taps;
    s8 age;
    s8 repeat;
    s8 held;
} ControllerButtonHistory;

struct ControllerProfile;
struct ControllerProfile {
    s32 connected; /* 0x00 */
    s8 port; /* 0x04 */
    u8 padding005[3];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 inputPreviousButtons;
    s32 inputButtons; /* 0x18 */
    u32 inputPressedButtons; /* 0x1C */
    s32 inputHistory[3]; /* 0x20 */
    ControllerButtonHistory buttonHistory[32]; /* 0x2C */
    s32 previousButtons; /* 0xAC */
    s32 buttons; /* 0xB0 */
    u32 pressedButtons; /* 0xB4 */
    s32 history[2]; /* 0xB8 */
    u32 buttonState; /* 0xC0 */
    s8 stickX; /* 0xC4 */
    s8 stickY; /* 0xC5 */
    s8 previousStickX; /* 0xC6 */
    s8 previousStickY; /* 0xC7 */
    s32 pakActive; /* 0xC8 */
    s32 mode; /* 0xCC */
    f32 pakAmount; /* 0xD0 */
    f32 pakTimer; /* 0xD4 */
    OSPfs pak; /* 0xD8 */
    struct PoolRecAt28V1 effectPool; /* 0x140 */
    struct NodeCode8028469C effectNodes[3]; /* 0x16C */
    s32 reset; /* 0x220 */
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
    CVector3 position;
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
    s32 drawModel;
    s32 updateAnimation;
    s32 allocationMode; /* 0x08: resource allocation request */
    void **model;
    char reserved10[0x10];
    IntrusiveList recycled; /* 0x20 */
};

struct Field_void_4;
typedef struct Field_void_4 Field_void_4;

struct func_80293268_S1;
typedef struct func_80293268_S1 func_80293268_S1;

struct func_80250BD4_S1;
typedef struct func_80250BD4_S1 func_80250BD4_S1;

struct ALEvent;

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

struct MenuStyle;
typedef struct MenuStyle MenuStyle;

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

struct RecCode8026AC38;
typedef struct RecCode8026AC38 RecCode8026AC38;

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

struct StateCode80420E90;
typedef struct StateCode80420E90 StateCode80420E90;

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

struct CROMEventEntry_t;
typedef struct CROMEventEntry_t CROMEventEntry;

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
    u32 flags;
    s32 optionFlags; /* +4: toggled menu option bits */
    u8 unknown8[0x1D - 8];
    u8 local; /* +0x1D: local-player input flag */
    u8 unknown1E[0x581 - 0x1E];
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

struct NodeCode8028469C;
typedef struct NodeCode8028469C NodeCode8028469C;

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
