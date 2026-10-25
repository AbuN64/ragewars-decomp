#ifndef COMMON_OBJECTLINKS4_2_H
#define COMMON_OBJECTLINKS4_2_H
struct ModelTreeNode;
#ifndef SPAN_1000_CODE_80275E44_H
#define SPAN_1000_CODE_80275E44_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern void func_80276298_de(struct ModelTreeNode *arg0, u16 arg1);

extern void func_802765A0_de(void);

extern void func_802761B8_de(void *arg0);


extern float D_800C4A04_de;

extern void func_80276184_de(void *arg0);

extern float D_800CD3F8[];

extern float D_800C4A00_de;

extern float D_800C4ACC_de;


extern float D_800C49FC_de;

union ObjectLinks4_2;
typedef union ObjectLinks4_2 ObjectLinks4_2;




extern float D_800C4AD0_de;





union ObjectLinks4_2;
union ObjectLinks4_2 {
    void * v0;
    u16 * v1;
};

struct ObjectLinks1C;
struct ObjectLinks1C {
    char pad0[0x4];
    char * unk_4;
    char pad4[0x8 - 0x4 - sizeof(char*)];
    char * unk_8;
    char pad8[0xC - 0x8 - sizeof(char*)];
    char * unk_C;
    char padC[0x10 - 0xC - sizeof(char*)];
    ObjectLinks4_2 unk_10;
    char pad10[0x14 - 0x10 - sizeof(ObjectLinks4_2)];
    ObjectLinks4_2 unk_14;
    char pad14[0x18 - 0x14 - sizeof(ObjectLinks4_2)];
    ObjectLinks4_2 unk_18;
};




extern float D_800C4AC8_de;

extern float D_800C4AC0_de;

struct ObjectLinks1C;
typedef struct ObjectLinks1C ObjectLinks1C;

extern float D_800C4AC4_de;

extern void func_8027640C_de(f32 *arg0, s32 arg1, CVector3 *arg2);

extern float D_800CD4FC[];



extern void func_80276214_de(struct ModelTreeNode *arg0, u16 arg1);


/* Shared object layout established by model-tree consumers. */
struct ModelTreeNode {
    u16 modelId; /* 0x00 */
    u16 flags; /* 0x02 */
    u8 padding004[0xC];
    struct ModelTreeNode *branches[3]; /* 0x10 */
};

extern f32 func_8027631C_de(u16 *arg0, f32 arg1, u16 arg2);

#endif
#endif
