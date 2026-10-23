#ifndef OVLGAME_80447BB0_H
#define OVLGAME_80447BB0_H
#include "TYPES.H"
struct ObjectState96 {
    char pad0[0x78];
    u8 unk_78;
    char pad78[0x7F - 0x78 - sizeof(u8)];
    s8 unk_7F;
    char pad7F[0x80 - 0x7F - sizeof(s8)];
    s8 unk_80;
    char pad80[0x81 - 0x80 - sizeof(s8)];
    u8 unk_81;
    char pad81[0x91 - 0x81 - sizeof(u8)];
    u8 unk_91;
    char pad91[0x95 - 0x91 - sizeof(u8)];
    u8 unk_95;
};
struct IntegerState88 {
    char pad0[0x74];
    s32 unk_74;
    char pad74[0x84 - 0x74 - sizeof(s32)];
    s32 unk_84;
};
struct ActorCode80447BB0 {
    char pad[0x2E8];
    char firstEffect[0x170]; /* 0x2E8 */
    char secondEffect[0x180]; /* 0x458 */
    struct Part *part;
};
/* A 0x44-byte record: three leading words, two lists of 0x16DC/0x16E0-linked nodes, four trailing words. */
struct RecordCode80447BB0 {
    s32 word0;
    s32 word4;
    s32 word8;
    IntrusiveList listC;
    IntrusiveList list20;
    s32 word34;
    s32 word38;
    s32 word3C;
    s32 word40;
};
#endif
