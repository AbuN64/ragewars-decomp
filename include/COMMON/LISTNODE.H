#ifndef COMMON_LISTNODE_H
#define COMMON_LISTNODE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
union func_802598D4_S1_UD8;
typedef union func_802598D4_S1_UD8 func_802598D4_S1_UD8;

struct ListNode;
struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    unsigned char pad08[0xB4];
    s32 valueBC;
};

struct ListNode;
typedef struct ListNode ListNode;

struct ListNode;
union func_80259A0C_S1_UD8;
union func_80259A0C_S1_UD8 {
    ListNode v0;
    struct ListNode * v1;
};

struct NodeRecAtAC;
typedef struct NodeRecAtAC NodeRecAtAC;

struct NodeRecAtAC;
struct NodeRecAtAC {
    struct NodeRecAtAC *prev;
    struct NodeRecAtAC *next;
    char pad8[0xA4];
    s32 flags;
};

struct Lists;

struct func_80259AD8_S1;
typedef struct func_80259AD8_S1 func_80259AD8_S1;

struct VoiceRecAt8;
typedef struct VoiceRecAt8 VoiceRecAt8;

extern void func_802591D0_de(void *arg0, s16 arg1);

struct ManagerRecAtD8V2;
typedef struct ManagerRecAtD8V2 ManagerRecAtD8V2;

struct func_802598D4_S1;
typedef struct func_802598D4_S1 func_802598D4_S1;

struct ObjectLinks8;
typedef struct ObjectLinks8 ObjectLinks8;

struct Lists;
typedef struct Lists Lists;

struct Link_func_80259784_de;
typedef struct Link_func_80259784_de Link_func_80259784_de;

struct NodeRecAt4C;
struct NodeRecAt4C {
    struct NodeRecAt4C *prev;
    struct NodeRecAt4C *next;
    char pad8[0x14];
    s32 timer;
    char pad20[0x20];
    s16 priority;
    char pad42[6];
    s32 owner;
    CVector3 position;
};

struct Link_func_80259784_de;
struct NodeRecAt4C;
struct Link_func_80259784_de {
    struct NodeRecAt4C *prev;
    struct NodeRecAt4C *next;
};

struct Entry_func_80259784_de;
typedef struct Entry_func_80259784_de Entry_func_80259784_de;

struct Entry_func_80259784_de;
struct Entry_func_80259784_de {
    char pad0[0xAC];
    s32 busy;
    char padB0[0x1C];
};

struct SceneCode802591C0;
struct SceneCode802591C0 {
    char pad0[0x1DBC];
    Entry_func_80259784_de entries[1];
    char pad1E88[0x2A84 - 0x1E88];
    s32 selection;
    s32 previousSelection;
    char pad2A8C[0x28];
    s16 activeSelection;
    s16 pendingSelection;
};
struct ManagerRecAtD8V2;
struct SceneCode802591C0;

struct func_802597A4_S2;
struct func_802597A4_S2 {
    char pad0[0x2A84];
    s32 unk2A84;
    char pad2A84[0x2A88 - 0x2A84 - sizeof(s32)];
    s32 unk2A88;
    char pad2A88[0x2AB4 - 0x2A88 - sizeof(s32)];
    s16 unk2AB4;
    char pad2AB4[0x2AB6 - 0x2AB4 - sizeof(s16)];
    s16 unk2AB6;
};

struct ObjectLinks8;

union func_80259A0C_S1_UD8;
typedef union func_80259A0C_S1_UD8 func_80259A0C_S1_UD8;

extern float D_800C8FF8;

struct Node_func_80259918_de;
struct Node_func_80259918_de {
    struct Node_func_80259918_de *prev;
    struct Node_func_80259918_de *next;
    char pad08[0xB0 - 0x8];
    s32 key;
};

struct Node_func_80259918_de;
struct OwnerRecAtD8;
struct OwnerRecAtD8 {
    s32 unk00;
    struct Node_func_80259918_de *activePrev;
    struct Node_func_80259918_de *activeNext;
    char pad0C[0xD8 - 0xC];
    struct Node_func_80259918_de *otherPrev;
};

struct Glyphs;
struct Glyphs {
    char pad0[0x10];
    s32 bitmaps[1];
};

struct Font;
struct Glyphs;
struct Font {
    char pad0[0xC];
    struct Glyphs *glyphs;
};
struct ContextCode802591C0;
struct Font;
struct ContextCode802591C0 {
    char pad0[0x7C];
    struct Font *font;
    char pad80[4];
    char textures[0xDC - 0x84];
    s16 slots[16];
    char padFC[0x104 - 0xFC];
    s32 frame;
    s32 sequence;
    char pad10C[0x1DB8 - 0x10C];
    char cells[1];
};

struct Slot_func_80259200_de;
struct Slot_func_80259200_de {
    int id;
    char pad[0xC8];
};

struct Cache;
typedef struct Cache Cache;

extern float D_800C3F00_de;

struct Node_func_802598B4_de;
struct Node_func_802598B4_de {
    struct Node_func_802598B4_de *prev;
    struct Node_func_802598B4_de *next;
    s32 unused;
    s32 value;
};


struct Slot_func_80259200_de;
typedef struct Slot_func_80259200_de Slot_func_80259200_de;

struct ObjRecAt1E64;
struct ObjRecAt1E64 {
    char pad[0x102];
    short owner;
    char pad104[0x1E64 - 0x104];
    Slot_func_80259200_de slots[17];
};

struct func_80259B30_S1;
typedef struct func_80259B30_S1 func_80259B30_S1;

struct ObjectLinks2B50;
typedef struct ObjectLinks2B50 ObjectLinks2B50;

struct CellCode802591C0;

struct Node_func_802598B4_de;
typedef struct Node_func_802598B4_de Node_func_802598B4_de;

struct Node_func_802598B4_de;
union func_802598D4_S1_UD8;
union func_802598D4_S1_UD8 {
    Node_func_802598B4_de v0;
    struct Node_func_802598B4_de * v1;
};

struct func_802598D4_S1;
struct func_802598D4_S1 {
    char pad0[0x4];
    union { Node_func_802598B4_de node; struct { void *first; Node_func_802598B4_de *second; } links; } at4;
    char pad14[0xD8 - 0x4 - sizeof(Node_func_802598B4_de)];
    func_802598D4_S1_UD8 unkD8;
};

struct Entry_func_80259440_de;
struct Entry_func_80259440_de {
    struct Entry_func_80259440_de *prev;
    struct Entry_func_80259440_de *next;
    char body[0x10];
    s32 frame;
    s32 delay;
    char pad20[0x40 - 0x20];
    s16 glyph;
    s16 font;
    s16 style;
    s16 pad46;
    s32 sequence;
    char pad4C[0xA8 - 0x4C];
    s32 fieldA8;
};

struct NodeRecAtC8;
struct NodeRecAtC8 {
    struct NodeRecAtC8 *prev;
    struct NodeRecAtC8 *next;
    char channel[4];
    s32 volume;
    char pad10[4];
    s32 handle;
    s32 frame;
    s32 sample;
    s32 gainA;
    s32 gainB;
    s16 pitch;
    char pad2A[2];
    s32 time;
    char pad30[0x10];
    s16 priority;
    s16 group;
    s16 volume16;
    char pad46[2];
    s32 voice;
    Vec3Words position;
    s32 pad58;
    u8 pan;
    char pad5D[0x4F];
    s32 flags;
    char padB0[4];
    s32 padB4;
    char padB8[0x10];
    s32 mix;
};

struct Link_func_80259260_de;
struct NodeRecAtC8;
struct Link_func_80259260_de {
    struct NodeRecAtC8 *prev;
    struct NodeRecAtC8 *next;
};

struct func_80259280_S1;
typedef struct func_80259280_S1 func_80259280_S1;

struct func_80259AD8_S2;
typedef struct func_80259AD8_S2 func_80259AD8_S2;

struct CellCode802591C0;
typedef struct CellCode802591C0 CellCode802591C0;

struct ObjRecAt1E64;
typedef struct ObjRecAt1E64 ObjRecAt1E64;


struct func_80259AD8_S1;
struct func_80259AD8_S1 {
    char pad0[0x4];
    char unk4;
    char pad4[0x8 - 0x4 - sizeof(char)];
    void * unk8;
};

struct Link_func_80259260_de;
typedef struct Link_func_80259260_de Link_func_80259260_de;

struct ManagerRecAtD8V1;

struct Node_func_80259918_de;
typedef struct Node_func_80259918_de Node_func_80259918_de;

struct ManagerRecAtD8V1;
typedef struct ManagerRecAtD8V1 ManagerRecAtD8V1;

struct VoiceRecAt8;
struct VoiceRecAt8 {
    ListLink link;
    Header header;
};

struct ChannelSet;
struct ChannelSet {
    s32 owner;
    ListLink free;
    Header freeHeader;
    ListLink active;
    Header activeHeader;
    VoiceRecAt8 voices[32];
};

struct func_80259280_S1;
struct func_80259280_S1 {
    char pad0[0x2B8C];
    s16 unk2B8C;
};


struct NodeRecAtC8;
typedef struct NodeRecAtC8 NodeRecAtC8;

struct Entry_func_80259440_de;
struct ListHead;
struct ListHead {
    struct Entry_func_80259440_de *prev;
    struct Entry_func_80259440_de *next;
};

struct ListHead;
typedef struct ListHead ListHead;

struct Cache;
struct ContextCode802591C0;
struct Cache {
    struct ContextCode802591C0 *context;
    ListHead pending;
    char padC[0xD8 - 0xC];
    ListHead done;
};

struct func_80259AD8_S2;
struct func_80259AD8_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0xB0 - 0x4 - sizeof(void*)];
    int unkB0;
};

struct func_80259B30_S1;
struct func_80259B30_S1 {
    char pad0[0x128];
    CVector3 unk128;
    char pad128[0x160 - 0x128 - sizeof(CVector3)];
    char unk160;
};

struct OwnerRecAtD8;
typedef struct OwnerRecAtD8 OwnerRecAtD8;

struct func_802597A4_S2;
typedef struct func_802597A4_S2 func_802597A4_S2;

struct Entry_func_80259440_de;
typedef struct Entry_func_80259440_de Entry_func_80259440_de;

struct func_80259A0C_S1;
typedef struct func_80259A0C_S1 func_80259A0C_S1;

struct NodeRecAt4C;
typedef struct NodeRecAt4C NodeRecAt4C;

struct func_80259A0C_S1;
struct func_80259A0C_S1 {
    char pad0[0x4];
    union { ListNode node; struct { void *first; ListNode *second; } links; } at4;
    char padC4[0xD8 - 0x4 - sizeof(ListNode)];
    func_80259A0C_S1_UD8 unkD8;
};

struct LinkPair;
typedef struct LinkPair LinkPair;

struct Glyphs;
typedef struct Glyphs Glyphs;

struct ContextCode802591C0;
typedef struct ContextCode802591C0 ContextCode802591C0;


struct LinkPair;

struct ObjectLinks2B50;

struct ChannelSet;
typedef struct ChannelSet ChannelSet;

extern s16 func_8025E500_de(void *);
extern s16 func_8025E50C_de(void *);
extern s8 func_8025E554_de(void *);
extern s16 Audio_SelectVoiceSlot(char *, s32, s32, s32, s32);
#endif
