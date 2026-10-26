#ifndef COMMON_OWNERRECAT8V1_H
#define COMMON_OWNERRECAT8V1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct OwnerRecAt8V1;
typedef struct OwnerRecAt8V1 OwnerRecAt8V1;

struct NodeMenuCreateOverlayNode;
typedef struct NodeMenuCreateOverlayNode NodeMenuCreateOverlayNode;

extern s32 SmpOverlay_DispatchSlotEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Record_func_8041B22C_de;
struct Record_func_8041B22C_de {
    s32 words_00[3];
    s16 field_0C;
    u16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

struct Mixer;
typedef struct Mixer Mixer;

struct sm_dlmultiuser_t;
typedef struct sm_dlmultiuser_t sm_dlmultiuser;

struct NodeMenuCreateOverlayNode;
struct OwnerRecAt44;
struct NodeMenuCreateOverlayNode {
    s32 words_00[3];
    s16 tag;
    s16 kind;
    s8 alpha; /* 0x10 */
    u8 reserved11;
    s16 flags;
    s32 words_14[12];
    struct OwnerRecAt44 *owner;
    s32 value;
    s32 words_4C[8];
    s32 field_6C;
};

struct OwnerRecAt44 {
    s32 words_00[2];
    struct NodeMenuCreateOverlayNode *root;
    s32 words_0C[14];
    struct NodeMenuCreateOverlayNode *overlay;
};

struct SlotsRecAt5CV2;
struct SlotsRecAt5CV2 {
    char pad0[0x48];
    s32 count;
    char pad4C[0x5C - 0x4C];
    s32 values[1];
};

struct ChildRecAt38;
struct ChildRecAt38 {
    char pad[0x12];
    u16 flags;
    char pad14[0x38 - 0x14];
    void *target;
};

struct ChildRecAt38;

extern void SmpButton_WrapButtonWidget(s32 arg0);

struct SlotsRecAt5CV1;
struct SlotsRecAt5CV1 {
    char pad[0x5C];
    s32 values[1];
};

extern void SmpButton_RegisterButtonClass();

struct NodeMenuShowSlotById;
typedef struct NodeMenuShowSlotById NodeMenuShowSlotById;

struct Child;
struct Child {
    char pad[0x12];
    u16 flags;
    char pad14[0x34 - 0x14];
    void *target;
};

struct SlotsRecAt5CV2;
extern s32 SmpOverlay_CountUsedSlots(struct SlotsRecAt5CV2 *object);

struct OwnerRecAt44;
typedef struct OwnerRecAt44 OwnerRecAt44;

struct SlotsRecAt4C;
struct ObjRecAtCV1;
struct SlotsRecAt4C {
    char pad[0x4C];
    struct ObjRecAtCV1 *entries[1];
};

struct ChildRecAt2C;
struct ChildRecAt2C {
    char pad[0x12];
    u16 flags;
    char pad14[0x2C - 0x14];
    void *target;
};

struct NodeMenuShowSlotById;
struct NodeMenuShowSlotById {
    s32 words_00[3];
    s16 id;
};

struct sm_dlmultiuser_t;
struct sm_dlmultiuser_t {
    s32 words_00[17];
    void *root;
    s32 NUsers;
    NodeMenuShowSlotById *shown[4];
    s32 locked[4];
    s32 shared;
};

struct sm_dlmultiuser_t;
struct OwnerRecAt8V1;
struct OwnerRecAt8V1 {
    s32 words_00[2];
    struct sm_dlmultiuser_t *context;
};

struct RecordSmpButtonWrapButtonWidget;
struct RecordSmpButtonWrapButtonWidget {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

extern s32 func_8041B340_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct ChildRecAt2C;

struct RecordSmpButtonWrapButtonWidget;
typedef struct RecordSmpButtonWrapButtonWidget RecordSmpButtonWrapButtonWidget;

extern void SmpOverlay_RegisterOverlayClass();

struct Mixer;
struct Mixer {
    char pad[0x4C];
    ObjRecAtCV1 *handlers[4];
    int muted[4];
};

extern void SmpOverlay_ShowSlotNodeById(sm_dlmultiuser *context, s32 index, s32 id);

struct Record_func_8041B22C_de;
typedef struct Record_func_8041B22C_de Record_func_8041B22C_de;

struct Key;
struct MenuRecAt114;
struct OwnerRecAt38;
struct MenuRecAt114 {
    char pad0[0x44];
    struct OwnerRecAt38 *owner;
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
    s32 count;
};

struct ChildRecAt30;
struct ChildRecAt30 {
    char pad[0x12];
    u16 flags;
    char pad14[0x30 - 0x14];
    void *target;
};

struct ChildRecAt30;

struct Child;
#endif
