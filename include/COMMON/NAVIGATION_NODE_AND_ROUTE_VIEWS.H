#ifndef COMMON_NAVIGATION_NODE_AND_ROUTE_VIEWS_H
#define COMMON_NAVIGATION_NODE_AND_ROUTE_VIEWS_H
#include "TYPES.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/ITEMRECAT20V1.H"
struct NavigationSearchNodeView;
struct NavigationSearchNodeView {
    s32 key;
    f32 value;
    s32 state;
    s32 fieldC;
    struct NavigationSearchNodeView *next;
    s32 field14;
    s32 field18;
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    s32 field2C;
    s32 field30;
    char * owner;
};

struct RouteRelationTableView;
typedef struct RouteRelationTableView RouteRelationTableView;

struct Node;
struct Node {
    int id;
    char pad4[0xC];
    struct Node *next;
    char pad14[0x18];
    int active;
};

struct NavigationNodeFlagsView;
typedef struct NavigationNodeFlagsView NavigationNodeFlagsView;


extern float g_portalRelatedGoalDefaultValue;





struct NavigationLinkListView;
struct IntPair;
struct NavigationLinkListView {
    s32 pad0[2];
    struct IntPair *table;
    s32 count;
};

struct NavigationSearchNodeView;
typedef struct NavigationSearchNodeView NavigationSearchNodeView;


struct ObjNavAddGoalNode;
typedef struct ObjNavAddGoalNode ObjNavAddGoalNode;

struct NavigationStridedTableView;
typedef struct NavigationStridedTableView NavigationStridedTableView;

struct NavigationSearchGraphView;
typedef struct NavigationSearchGraphView NavigationSearchGraphView;


struct RouteRelationTableView;
struct RouteRelationTableView {
    char pad0[0x4];
    int unk_4;
    char pad4[0x10 - 0x4 - sizeof(int)];
    char * unk_10;
};

struct NavigationLinkListView;
typedef struct NavigationLinkListView NavigationLinkListView;

struct Graph;
typedef struct Graph Graph;






union NavigationPackedFlags;
typedef union NavigationPackedFlags NavigationPackedFlags;

struct NavigationStridedTableView;
struct NavigationStridedTableView {
    s32 stride;
    char data[4];
};

struct NavigationSearchGraphView;
struct NavigationSearchGraphView {
    NavigationStridedTableView *records;
    s32 count;
    char pad8[8];
    NavigationStridedTableView *links;
    char pad14[4];
    s32 result;
    f32 value;
    s32 selected;
    NavigationSearchNodeView *nodes;
};

union NavigationPackedFlags;
union NavigationPackedFlags {
    u32 v0;
    u16 v1;
};

struct NavigationNodeFlagsView;
struct NavigationNodeFlagsView {
    char pad0[0xC];
    NavigationPackedFlags flags;
};

struct Node;
struct ObjNavAddGoalNode;
struct ObjNavAddGoalNode {
    char pad[0x24];
    struct Node *list;
    char pad28[0x10];
    int ids[64];
};



extern float g_portalResetSearchValue;






struct Node;
typedef struct Node Node;


extern float g_portalNodeInitialValue;


struct LinkTable;
struct LinkTable {
    int stride;
    int pad4;
    Link first;
};
struct Graph;
struct LinkTable;
struct Graph {
    char pad0[8];
    struct LinkTable *links;
    int count;
};




#include "COMMON/AIPROFILE.H"



#include "COMMON/REC.H"
typedef struct NavigationPlatform {
    u8 pad0[8];
    CVector3 pos;
    u8 pad14[4];
    ActorMotionResource *resource;
    u8 pad1C[0xC8];
    u16 objectId;
    u8 padE6[0x8A];
    ActorMotionState motion;
    u8 pad2E0[8];
} NavigationPlatform;
typedef struct PlatformRoute { s16 reserved; s16 count; } PlatformRoute;
#endif
