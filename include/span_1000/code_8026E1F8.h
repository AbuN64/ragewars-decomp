#ifndef UNBAKE_SPAN_1000_CODE_8026E1F8_H
#define UNBAKE_SPAN_1000_CODE_8026E1F8_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct ObjRecAt4V7;
typedef struct ObjRecAt4V7 ObjRecAt4V7;

extern float D_800C4758_de;

extern float D_800C4810_de;

extern float D_800C46EC_de;

extern float D_800C4710_de;

extern float D_800C4780_de;

extern void func_8026E350_de(unsigned char first, unsigned char second, unsigned char third, unsigned char fourth);

extern float D_800C4828_de;

struct Node8026E4F8;
typedef struct Node8026E4F8 Node8026E4F8;

extern float D_800C4830_de;

struct func_8026E5E0_S3;
typedef struct func_8026E5E0_S3 func_8026E5E0_S3;

extern float D_800C4730_de;

extern float D_800C47D0_de;

extern Vec3 *func_80271624_de(Vec3 *out, Vec3 *in, f32 amount);

extern float D_800C47C8_de;

extern float D_800C47A8_de;

extern float D_800C4790_de;

extern float D_800C4738_de;

extern float D_800C47E0_de;

extern float D_800C98C8;

extern void func_8026E428_de(void);

extern float D_800C4708_de;

extern float D_800C4700_de;

extern float D_800C4720_de;

struct ObjRecAt4V7;
struct ObjRecAt4V7 {
    u32 unk0;
    u16 unk4;
    char pad4[0xE];
};

extern unsigned char D_800CC3AB;

extern float D_800C482C_de;

extern float D_800C4818_de;

extern unsigned char D_800CC3A8;

extern float D_800C4788_de;

struct BoxRecAtC;
typedef struct BoxRecAtC BoxRecAtC;

struct TreeNode;
struct TreeNode {
    unsigned int key;
    unsigned char padding[12];
    struct TreeNode *link10;
    struct TreeNode *link14;
    struct TreeNode *link18;
    struct TreeNode *link1c;
};

extern unsigned char D_800CC3AA;

extern float D_800C4740_de;

extern float D_800C47C0_de;

extern float D_800C4808_de;

extern void func_8026E4D0_de(void);

struct Node8026E4F8;
struct Node8026E4F8 {
    u32 key;
    char pad4[0x14];
    struct Node8026E4F8 *left;
    struct Node8026E4F8 *right;
};

extern float D_800C47F8_de;

extern float D_800C4798_de;

struct TreeNode;
typedef struct TreeNode TreeNode;

extern float D_800C4800_de;

extern void *func_8026E4F8_de(Node8026E4F8 **arg0, u32 arg1);

extern float D_800C4718_de;

extern float D_800C47A0_de;

extern float D_800C4728_de;

struct func_8026E5E0_S1;
struct func_8026E5E0_S1 {
    char pad0[0xC];
    u32 unkC;
    u16 bone;
    u16 reserved;
};

extern float D_800C4750_de;

extern void func_8026E4C0_de(int *state);

extern float D_800C4768_de;

extern float D_800C46F8_de;

extern float D_800C4778_de;

extern void func_8026E390_de(void);

struct func_8026E5E0_S1;
typedef struct func_8026E5E0_S1 func_8026E5E0_S1;

extern float D_800C47E8_de;

extern float D_800C47EC_de;

extern void func_8026E1F8_de(void **arg0);

struct BoxRecAtC;
struct BoxRecAtC {
    f32 min[3];
    f32 max[3];
};

extern unsigned char D_800CC3A9;

extern float D_800C46F0_de;

extern float D_800C4770_de;

extern float D_800C4820_de;

extern void func_8026EF58_de(f32 *out, f32 *m);

extern float D_800C47F0_de;

extern float D_800C4760_de;

extern float D_800C4748_de;

struct AttachmentTable;
typedef struct AttachmentTable AttachmentTable;

extern float D_800C4824_de;

extern float D_800C98C4;

struct AttachmentTable;
struct AttachmentTable {
    s32 stride;
    u8 pad4[0x6A];
    u8 bytes[1];
};

extern float D_800C4834_de;

extern float D_800C47B0_de;

struct func_8026E5E0_S3;
struct func_8026E5E0_S3 {
    char pad0[0x18];
    s32 *unk18;
    char pad18[0x188];
    s8 unk1A4;
    char pad1A4[0xB];
    f32 unk1B0;
    char pad1B0[0x24];
    ObjRecAt650 *unk1D8;
    char pad1D8[0x6C];
    Triple unk248;
    Triple unk254;
    Triple unk260;
    char pad268[0x74];
    s32 unk2E0;
};

extern float D_800C47B8_de;


/* Reference stored in section zero of a resource entry. */
typedef struct ResourceSectionReference {
    s32 prefix[2];
    s32 resource;
} ResourceSectionReference;

#endif
