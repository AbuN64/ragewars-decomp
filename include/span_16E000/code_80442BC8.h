#ifndef UNBAKE_SPAN_16E000_CODE_80442BC8_H
#define UNBAKE_SPAN_16E000_CODE_80442BC8_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct Object1C8;
struct Object1C8 {
    char pad[0x1C8];
    s32 first;
    s32 second;
};

struct Descriptor_func_80442D10_de;
struct Descriptor_func_80442D10_de {
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
extern void func_80442CF4_de(s16 *record, struct ObjectRecAt478 *object);

struct ObjRecAt8V4;
struct ObjRecAt8V4 {
    char pad[8];
    u32 flags;
};

struct Descriptor_func_80442D10_de;
struct WidgetRecAt24;
struct WidgetRecAt24 {
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
    struct Descriptor_func_80442D10_de *desc;
    int index;
    void *extra;
    int arg;
};

struct Descriptor_func_80442D10_de;
typedef struct Descriptor_func_80442D10_de Descriptor_func_80442D10_de;

struct WidgetRecAt24;
typedef struct WidgetRecAt24 WidgetRecAt24;

extern void func_80442D10_de(WidgetRecAt24 *w, Descriptor_func_80442D10_de *d, char **arena, int id, int arg);

struct StateRecAtBCV2;
struct StateRecAtBCV2 {
    char pad0[0xB0];
    s32 a;
    s32 b;
    s32 padB8;
    s32 c;
};

struct Handlers_func_804431E4_de;
struct Handlers_func_804431E4_de {
    char pad[0xC];
    void (*callback)();
};
struct Handlers_func_804431E4_de;
struct ObjectRecAt20;
struct StateRecAtBCV2;
struct ObjectRecAt20 {
    char pad[0x14];
    struct Handlers_func_804431E4_de *handlers;
    char pad18[0x20 - 0x18];
    struct StateRecAtBCV2 *state;
};

struct ObjectRecAt20;
extern void func_804431E4_de(struct ObjectRecAt20 *object);

struct ObjectRecAt1C8;
struct ObjectRecAt1C8 {
    char pad[0x1C8];
    s32 count;
};

struct MenuSpriteElement;
typedef struct MenuSpriteElement MenuSpriteElement;

struct Object1C8;
extern void func_80442B5C_de(struct Object1C8 *object);

struct MenuSpriteElement;
struct Shared_HudView;
struct MenuSpriteElement {
    char pad0[0x40];
    struct Shared_HudView *owner;
    char pad44[0x184];
    s32 frame;
    s32 active;
};

extern void func_80442BA8_de(MenuSpriteElement *e);

extern void func_80443528_us_rev1(void);

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
extern s32 func_80442B88_de(struct ObjectRecAt1C8 *object);

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
extern s32 func_80443694_de(void *unused, struct HolderRecAt1CV1 *holder);

extern void func_804433F8_de(void);

struct ObjRecAt8V4;
typedef struct ObjRecAt8V4 ObjRecAt8V4;

extern s32 func_80442CD8_de(s16 *record);

struct ItemRecAt20V2;
struct List_func_80442A60_de;
struct List_func_80442A60_de {
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
