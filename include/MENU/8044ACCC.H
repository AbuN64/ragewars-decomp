#ifndef MENU_8044ACCC_H
#define MENU_8044ACCC_H
#include "TYPES.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "COMMON/PACKED.H"
#include "COMMON/SHAREDPLAYER.H"
/* The resource header is followed by count input records or runtime actors. */
typedef struct LevelBlock {
    s32 size;
    s32 count;
    LevelActor objects[1];
} LevelBlock;
struct ItemsPendingState {
    char p[0x11C0];
    s32 unk11C0;
    s32 unk11C4;
    char q[8];
    s32 unk11D0;
    s32 unk11D4;
};
struct SceneRecAt1B2B4 {
    char pad0[0x1B2B0];
    struct CROMLevel_t *light;
    s16 dir[3];
};
struct func_8044B27C_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    IntrusiveList unkC;
    IntrusiveList unk20;
    char pad34[0x38 - 0x34];
    s32 unk38;
    char pad38[0x40 - 0x38 - sizeof(s32)];
    char unk40;
    char pad40[0xF18 - 0x40 - sizeof(char)];
    s32 unkF18;
    char padF18[0xF1C - 0xF18 - sizeof(s32)];
    s32 unkF1C;
    char padF1C[0xF20 - 0xF1C - sizeof(s32)];
    s32 unkF20;
    char padF20[0xF24 - 0xF20 - sizeof(s32)];
    IntrusiveList unkF24;
    char padF24[0x1200 - 0xF24 - sizeof(IntrusiveList)];
    s32 unk1200;
};
struct Level_func_8044CD8C_de {
    char pad0[0x30];
    s32 key;
    char pad34[0x64 - 0x34];
    s32 file;
    void *grid;
};
struct Node_Items_FindPlacedObjectsByKey {
    s32 index;
    s32 link[2];
};
struct func_8044CBE0_S1 {
    char pad0[0xB8];
    void * unkB8;
    void * unkBC;
    void * unkC0;
    void * unkC4;
    void * unkC8;
    void * unkCC;
    void * unkD0;
    void * unkD4;
    char padD4[0x10];
    void * unkE8;
    void * unkEC;
    void * unkF0;
    void * unkF4;
    char padF4[0x4];
    void * unkFC;
    void * unk100;
    char pad100[0x1B3FC];
    IntrusiveList unk1B500;
};
struct ItemsPreviewStateB {
    char pad[0x3C];
    int resource;
    char pad40[8];
    int bank;
    char pad4c[0x1B3C0];
    int selection;
    char pad1b410[12];
    int changed;
};
struct ObjA {
    s8 pad0;
    s8 type;
    char pad2[0x20 - 2];
    void **block;
    char pad24[0xE8 - 0x24];
};
struct ItemsSelectionState {
    char pad[0x1B2B0];
    ResourceSmpFlickerCreateFlickerWidget *input;
    char pad1b2b4[0x15C];
    int mode;
    int active;
    char pad1b418[0x20];
    int selection;
};
struct ObjRecAt8C8 {
    struct EntryCode8044ACCC entries[4];
    IntrusiveList free;
    IntrusiveList active;
    s16 unk8C8;
};
typedef struct CollisionBuildHeader {
    s32 count;
    s32 offsets[5];
} CollisionBuildHeader;
typedef struct CollisionBuildList {
    s32 kind;
    s32 count;
    CollisionBuildFace items[0];
} CollisionBuildList;
typedef union CollisionBuildMeshHandle {
    struct Shape_typemap_165 canonical;
    struct { void *data; s32 size,refs,flags; } payload;
} CollisionBuildMeshHandle;
typedef struct CollisionBuildVertexList { s32 kind,count; CollisionBuildVertex items[0]; } CollisionBuildVertexList;
typedef struct CollisionBuildTriangleList { s32 kind,count; CollisionBuildTriangle items[0]; } CollisionBuildTriangleList;
typedef struct CollisionBuildWorld {
    char pad0[0x84];
    int *tree;
    char pad88[0x1B2FC - 0x88];
    f32 minY;
    char pad1B300[0x1B40C - 0x1B300];
    s32 group;
} CollisionBuildWorld;
struct LevelCode8044ACCC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    char pad30[4];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    char pad40[48];
    s32 unk70;
    char pad74[4];
    s32 unk78;
    char pad7C[4];
    void *unk80;
    void *unk84;
    s32 unk88;
    char pad8C[4];
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    void *unkB4;
    char padB8[56];
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    char pad100[12];
    void *unk10C;
    char pad110[16];
    s32 unk120;
    s32 unk124;
    char pad128[111072];
    s32 unk1B308;
    char pad1B30C[16];
    s32 unk1B31C;
    char pad1B320[236];
    s32 unk1B40C;
    char pad1B410[516];
    s32 unk1B614;
    s32 unk1B618;
    s32 unk1B61C;
    char pad1B620[64];
    s32 unk1B660;
    char pad1B664[64];
    s32 unk1B6A4;
    char pad1B6A8[4];
    s32 unk1B6AC;
};
struct ItemsPreviewStateA {
    char pad0[4];
    s32 unk4;
    char pad8[48];
    s32 unk38;
    char pad3C[8];
    s32 unk44;
};
#endif
