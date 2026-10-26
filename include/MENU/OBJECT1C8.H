#ifndef MENU_OBJECT1C8_H
#define MENU_OBJECT1C8_H
#include "TYPES.H"
#include "COMMON/LONE/D_8014DE50.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Object1C8;
struct Object1C8 {
    char pad[0x1C8];
    s32 first;
    s32 second;
};

struct WidgetDescriptor;
struct WidgetDescriptor {
    short type;
    short pad;
    int flags;
    unsigned short x;
    unsigned short y;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    int value;
};

struct ObjectRecAt478;
struct ObjectRecAt478 {
    char pad[0x478];
    s32 flag;
};

struct ObjectRecAt478;

struct ObjRecAt8V4;
struct ObjRecAt8V4 {
    char pad[8];
    u32 flags;
};

struct WidgetDescriptor;
struct CMenuItem_t;
struct CMenuItem_t {
    int id;
    unsigned short type;
    unsigned short pad;
    int flags;
    unsigned short x;
    unsigned short y;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    int value;
    struct WidgetDescriptor *desc;
    int index;
    void *extra;
    int m_pMenu;
};

struct WidgetDescriptor;
typedef struct WidgetDescriptor WidgetDescriptor;

struct CMenuItem_t;
typedef struct CMenuItem_t CMenuItem;


struct StateRecAtBCV2;
struct StateRecAtBCV2 {
    char pad0[0xB0];
    s32 a;
    s32 b;
    s32 padB8;
    s32 c;
};

struct HandlersItemsInvokeHandlerAndClearItemState;
struct HandlersItemsInvokeHandlerAndClearItemState {
    char pad[0xC];
    void (*callback)();
};
struct HandlersItemsInvokeHandlerAndClearItemState;
struct ObjectRecAt20;
struct StateRecAtBCV2;
struct ObjectRecAt20 {
    char pad[0x14];
    struct HandlersItemsInvokeHandlerAndClearItemState *handlers;
    char pad18[0x20 - 0x18];
    struct StateRecAtBCV2 *state;
};

struct ObjectRecAt20;

struct ObjectRecAt1C8;
struct ObjectRecAt1C8 {
    char pad[0x1C8];
    s32 count;
};

struct MenuSpriteElement;
typedef struct MenuSpriteElement MenuSpriteElement;

struct Object1C8;

struct MenuSpriteElement;
struct Shared_HudView;
struct MenuSpriteElement {
    char pad0[0x40];
    struct Shared_HudView *owner;
    char pad44[0x184];
    s32 frame;
    s32 active;
};



struct Handlers;
struct Handlers {
    char pad[0xC];
    void (*callback)(void *, void *);
};
struct Handlers;
struct ItemRecAt20V2;
struct StateRecAtBCV2;
struct ItemRecAt20V2 {
    char pad0[8];
    s32 resource;
    char padC[0x14 - 0xC];
    struct Handlers *handlers;
    char pad18[0x20 - 0x18];
    struct StateRecAtBCV2 *state;
};

struct ObjectRecAt1C8;

struct OwnerRecAt698;
struct OwnerRecAt698 {
    char pad[0x698];
    s32 value;
};

struct HolderRecAt1CV1;
struct OwnerRecAt698;
struct HolderRecAt1CV1 {
    char pad[0x1C];
    struct OwnerRecAt698 *owner;
};

struct HolderRecAt1CV1;


struct ObjRecAt8V4;
typedef struct ObjRecAt8V4 ObjRecAt8V4;


struct ItemRecAt20V2;
struct ListPakClearMenuItemList;
struct ListPakClearMenuItemList {
    struct ItemRecAt20V2 *head;
};

struct ObjectRecAt14;
struct ObjectRecAt14 {
    s32 pad0;
    s16 kind;
    char pad6[0x14 - 6];
    void **target;
};


#endif
