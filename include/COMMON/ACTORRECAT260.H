#ifndef COMMON_ACTORRECAT260_H
#define COMMON_ACTORRECAT260_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"

struct ActorRecAt260;
typedef struct ActorRecAt260 ActorRecAt260;

struct ActorRecAt260;
struct ActorRecAt260 {
    char pad[0x58];
    int flags58;
    char pad5c[0xC4];
    int flags120;
    char pad124[0x9C];
    int flags1c0;
    char pad1c4[0x4C];
    int flags210;
    char pad214[0x24];
    int flags238;
    char pad23c[0x24];
    int flags260;
};

struct ArgRecAt1C;
struct ArgRecAt1C {
    char pad[12];
    ActorRecAt260 *unkC;
    char pad2[12];
    int unk1C;
};


struct ArgRecAt1C;
typedef struct ArgRecAt1C ArgRecAt1C;


struct ActorCode80443868804438BC;
struct ActorCode80443868804438BC {
    char pad0[4928];
    s32 unk1340;
    char pad1344[268];
    s32 unk1450;
};

struct ActorCode80443868804438BC;
struct StateRecAt1C;
struct StateRecAt1C {
    char pad0[28];
    struct ActorCode80443868804438BC * unk1C;
};

struct CaptionEntry;
typedef struct CaptionEntry CaptionEntry;


struct ObjectRecAt1C;
typedef struct ObjectRecAt1C ObjectRecAt1C;

struct Leaf;
struct Leaf {
    char pad[0x8E];
    u8 flag;
};
struct Leaf;
struct Middle;
struct Middle {
    char pad[0x5D8];
    struct Leaf *leaf;
};
struct Middle;
struct RootRecAt1C;
struct RootRecAt1C {
    char pad[0x1C];
    struct Middle *middle;
};

struct OwnerCode8043DF84;
typedef struct OwnerCode8043DF84 OwnerCode8043DF84;

struct ActorRecAt260;
struct ObjectRecAt1C;
struct ObjectRecAt1C {
    char pad[0xC];
    struct ActorRecAt260 *actor;
    char pad10[0xC];
    OwnerCode8043DF84 *parent;
};


struct ActorCode80443868;
struct ActorCode80443868 {
    char pad[0x5D0];
    int waiting;
    char pad5D4[4];
    ObjRecAt8F *info;
};
struct ActorCode80443868;
struct PlayerRecAt1C;
struct PlayerRecAt1C {
    char pad[0x1C];
    struct ActorCode80443868 *actor;
};

struct PlayerRecAt1C;
typedef struct PlayerRecAt1C PlayerRecAt1C;


struct RecordRecAtCV3;

struct CaptionEntry;
struct CaptionEntry {
    char pad0[4];
    s32 width;
    char pad8[4];
    f32 scaleX;
    f32 scaleY;
    char pad14[2];
    u16 x;
    char pad18[6];
    u16 y;
};


struct ActorCode80443868804438BC;
typedef struct ActorCode80443868804438BC ActorCode80443868804438BC;

struct RootRecAt1C;


struct StateRecAt1C;
typedef struct StateRecAt1C StateRecAt1C;



struct MenuRules;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 Player_FormatPlayerResultScore(struct LayeredText *field, struct MenuRules *holder);
#endif



#endif
