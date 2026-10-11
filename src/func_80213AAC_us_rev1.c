#include "shared/func_80404D84_de_closed.h"
#include "types.h"

/* Sets up a body voice from its spawn parameters: the voice record is reinitialised over 368 bytes by
   func_802A001C_de while the carried-over field at 0x68 is preserved and the voice kind at 0x00 is
   written as 64; func_802138F0_de is then handed the voice, its definition record, and the parameter's
   position words; the parameter's position, path node, path height and record pointers are mirrored
   into the voice's state blocks, its height slots are filled from the parameter height and the global
   D_800C7218, and - when the definition's gate word carries bit 4 and a path node is present - the
   voice's track midpoint is replaced by the terrain height func_80275DD4_de reports at its current
   track position. The voice is then armed (timers and slot tables cleared, several fields set to -1,
   kind bit 0 cleared, the two record addresses 0x24B52C and 0x24B8DC installed), the optional setup
   callback registered in the parameter's holder is run with (params, voice), the 0x08000000 parameter
   flag raises the voice's setup byte at 0xCB, and nothing is returned. */

struct VoiceDef_func_80213AAC_us_rev1 {
    s32 kind; /* 0x00 definition kind, switched on by func_802138F0_de */
    s32 gate; /* 0x04 gate word: bit 0x4 enables the terrain-height update */
};

struct BodyParams_func_80213AAC_us_rev1 {
    char pad00[8];                                        /* 0x00 */
    s32 pos0;                                             /* 0x08 position x, copied as a whole word */
    union {
        s32 pos1_i;                                       /* 0x0C position y as a copied int */
        f32 pos1_f;                                       /* 0x0C same slot read as raw float bits */
    } pos1;
    s32 pos2;                                             /* 0x10 position z, copied as a whole word */
    s32 pathNode;                                         /* 0x14 path node handed to func_80275DD4_de */
    struct VoiceDef_func_80213AAC_us_rev1 *def;           /* 0x18 voice definition record */
    char pad1C[0x50];                                     /* 0x1C */
    f32 height;                                           /* 0x6C path height fed to the voice slots */
    char pad70[0x90];                                     /* 0x70 */
    s32 flags;                                            /* 0x100 bit 0x08000000 enables setup byte 0xCB */
};

struct VoiceRecord_func_80213AAC_us_rev1 {
    s32 unk0;                                             /* 0x00 voice kind: written 64, then bit 0 cleared */
    char pad04[0x12];                                     /* 0x04 */
    u8 unk12;                                             /* 0x12 cleared */
    u8 unk13;                                             /* 0x13 written 20 */
    u8 unk14;                                             /* 0x14 written -1 */
    u8 unk15;                                             /* 0x15 written -1 */
    u8 unk16;                                             /* 0x16 written -1 */
    u8 unk17;                                             /* 0x17 written -1 */
    f32 unk18;                                            /* 0x18 fed with D_800C7218 */
    s32 unk1C;                                            /* 0x1C cleared */
    s32 unk20;                                            /* 0x20 cleared */
    s32 unk24;                                            /* 0x24 cleared */
    s32 unk28;                                            /* 0x28 cleared */
    s32 unk30;                                            /* 0x30 (48) cleared */
    u8 unk34;                                             /* 0x34 (52) written -1 */
    u8 unk35;                                             /* 0x35 (53) written -1 twice */
    char pad36[0xE];                                      /* 0x36 */
    s32 unk44;                                            /* 0x44 (68) cleared */
    s32 unk48;                                            /* 0x48 (72) position mirror x */
    s32 unk4C;                                            /* 0x4C (76) position mirror y */
    s32 unk50;                                            /* 0x50 (80) position mirror z */
    s32 unk54;                                            /* 0x54 (84) second position copy x */
    s32 unk58;                                            /* 0x58 (88) second position copy y */
    s32 unk5C;                                            /* 0x5C (92) second position copy z */
    f32 unk60;                                            /* 0x60 (96) fed with the parameter height */
    s32 unk64;                                            /* 0x64 (100) cleared */
    s32 unk68;                                            /* 0x68 (104) preserved across the reinit */
    s32 unk6C;                                            /* 0x6C (108) cleared */
    s32 unk70;                                            /* 0x70 (112) cleared */
    s32 unk74;                                            /* 0x74 (116) cleared */
    s32 unk78;                                            /* 0x78 (120) cleared */
    s32 unk7C;                                            /* 0x7C (124) cleared */
    s32 unk80;                                            /* 0x80 (128) cleared */
    s32 unk84;                                            /* 0x84 (132) cleared */
    s32 unk88;                                            /* 0x88 (136) cleared */
    f32 unk8C;                                            /* 0x8C (140) fed with the parameter height */
    f32 unk90;                                            /* 0x90 (144) raw bits of the parameter pos1 */
    u8 unk94;                                             /* 0x94 (148) cleared */
    u8 unk95;                                             /* 0x95 (149) written 255 */
    s16 unk96;                                            /* 0x96 (150) written -1 */
    char pad98[6];                                        /* 0x98 */
    f32 unk9C;                                            /* 0x9C (156) fed with the parameter height */
    s32 unkA0;                                            /* 0x0A0 (160) track start x */
    s32 unkA4;                                            /* 0x0A4 (164) track start y */
    s32 unkA8;                                            /* 0x0A8 (168) track start z */
    s32 unkAC;                                            /* 0x0AC (172) path node, raw */
    s32 unkB0;                                            /* 0x0B0 (176) track position x, queried back */
    union {
        s32 unkB4_i;                                      /* 0x0B4 (180) track midpoint as a copied int */
        f32 unkB4_f;                                      /* 0x0B4 (180) midpoint overwritten with a height */
    } unkB4;
    s32 unkB8;                                            /* 0x0B8 (184) track position z, queried back */
    s32 unkBC;                                            /* 0x0BC (188) path node, second copy */
    f32 unkC0;                                            /* 0x0C0 (192) fed with D_800C7218 */
    f32 unkC4;                                            /* 0x0C4 (196) fed with D_800C7218 */
    s16 unkC8;                                            /* 0x0C8 (200) written -1 */
    u8 unkCA;                                             /* 0x0CA (202) written -1 */
    u8 unkCB;                                             /* 0x0CB (203) cleared, then 1 if params flag set */
    char padCC[4];                                        /* 0x0CC */
    s32 unkD0;                                            /* 0x0D0 (208) cleared */
    s32 unkD4;                                            /* 0x0D4 (212) cleared */
    char padD8[0x24];                                     /* 0x0D8 */
    s32 unkFC;                                            /* 0x0FC (252) cleared */
    u8 unk100;                                            /* 0x100 (256) cleared */
    char pad101[1];                                       /* 0x101 */
    s16 unk102;                                           /* 0x102 (258) written -1 */
    char pad104[4];                                       /* 0x104 */
    s32 unk10C;                                           /* 0x10C (268) set to 0x24B8DC */
    char pad110[12];                                      /* 0x110 */
    s32 unk11C;                                           /* 0x11C (284) set to 0x24B52C */
};

struct BodySetup_func_80213AAC_us_rev1 {
    void (*setup)(void *, void *);                        /* 0x00 optional callback, called as (params, voice) */
};

extern f32 D_800C7218;

extern void func_802138F0_de(void *, void *, s32, s32, s32, void *);
extern f32 func_80275DD4_de(s32, s32, s32);

void func_80213AAC_us_rev1(struct BodyParams_func_80213AAC_us_rev1 *params,
                           struct VoiceRecord_func_80213AAC_us_rev1 *voice,
                           struct BodySetup_func_80213AAC_us_rev1 *setup) {
    s32 carried;
    s32 node;

    carried = voice->unk68;
    func_802A001C_de(voice, 0, 368);
    voice->unk0 = 64;
    voice->unk68 = carried;
    func_802138F0_de(voice, params->def, params->pos0, params->pos1.pos1_i, params->pos2, params);
    voice->unk11C = 0x24B52C;
    voice->unk10C = 0x24B8DC;
    voice->unk34 = -1;
    voice->unk35 = -1;
    voice->unk30 = 0;
    voice->unk48 = params->pos0;
    voice->unk4C = params->pos1.pos1_i;
    voice->unk50 = params->pos2;
    voice->unk54 = params->pos0;
    voice->unk58 = params->pos1.pos1_i;
    voice->unk5C = params->pos2;
    voice->unk6C = 0;
    voice->unk70 = 0;
    voice->unk74 = 0;
    voice->unk60 = params->height;
    voice->unk64 = 0;
    voice->unk78 = 0;
    voice->unk7C = 0;
    voice->unk80 = 0;
    voice->unk84 = 0;
    voice->unk88 = 0;
    voice->unk8C = params->height;
    voice->unk90 = params->pos1.pos1_f;
    voice->unk9C = params->height;
    voice->unkA0 = params->pos0;
    voice->unkA4 = params->pos1.pos1_i;
    voice->unkA8 = params->pos2;
    voice->unkAC = params->pathNode;
    voice->unkB0 = params->pos0;
    voice->unkB4.unkB4_i = params->pos1.pos1_i;
    voice->unkB8 = params->pos2;
    node = params->pathNode;
    voice->unkBC = node;
    if ((params->def->gate & 4) != 0 && node != 0) {
        voice->unkB4.unkB4_f = func_80275DD4_de(node, voice->unkB0, voice->unkB8);
    }
    voice->unkCA = -1;
    voice->unk13 = 20;
    voice->unk95 = 255;
    voice->unk0 = voice->unk0 & ~1;
    voice->unkC8 = -1;
    voice->unk35 = -1;
    voice->unk14 = -1;
    voice->unk15 = -1;
    voice->unk16 = -1;
    voice->unk17 = -1;
    voice->unk102 = -1;
    voice->unk96 = -1;
    voice->unkCB = 0;
    voice->unkD0 = 0;
    voice->unkD4 = 0;
    voice->unk44 = 0;
    voice->unk12 = 0;
    voice->unk1C = 0;
    voice->unk20 = 0;
    voice->unk24 = 0;
    voice->unk28 = 0;
    voice->unk100 = 0;
    voice->unk94 = 0;
    voice->unkFC = 0;
    voice->unkC0 = D_800C7218;
    voice->unkC4 = D_800C7218;
    voice->unk18 = D_800C7218;
    if (setup != 0 && setup->setup != 0) {
        setup->setup(params, voice);
    }
    if (params->flags & 0x08000000) {
        voice->unkCB = 1;
    }
}
