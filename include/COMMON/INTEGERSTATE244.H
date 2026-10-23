#ifndef COMMON_INTEGERSTATE244_H
#define COMMON_INTEGERSTATE244_H
struct SharedPlayer;
#ifndef SPAN_1000_CODE_8022C894_H
#define SPAN_1000_CODE_8022C894_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/EXTERNS_15.H"
struct IntegerState244;
typedef struct IntegerState244 IntegerState244;

struct func_8022CDAC_S1;
struct func_8022CDAC_S1 {
    char pad0[0x658];
    f32 unk658;
    char pad658[0x6A4 - 0x658 - sizeof(f32)];
    f32 unk6A4;
    char pad6A4[0x6C4 - 0x6A4 - sizeof(f32)];
    f32 unk6C4;
};

struct func_8022CC24_S1;
struct func_8022CC24_S1 {
    char pad0[0x660];
    s32 unk660;
    char pad660[0x86C - 0x660 - sizeof(s32)];
    s32 unk86C;
    char pad86C[0x13B4 - 0x86C - sizeof(s32)];
    void * unk13B4;
};

extern void func_8022D420_de(void);

extern void func_8022D4AC_de(struct SharedPlayer *arg0);

struct ObjectLinks1458_2;
typedef struct ObjectLinks1458_2 ObjectLinks1458_2;

extern void func_8022D1A8_de(void *arg0);

extern void func_8022D254_de(void);

struct func_8022D030_S1;
struct func_8022D030_S1 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x10E - 0xE4 - sizeof(u16)];
    s8 unk10E;
    char pad10E[0x650 - 0x10E - sizeof(s8)];
    s16 unk650;
    char pad650[0x658 - 0x650 - sizeof(s16)];
    f32 unk658;
    char pad658[0x6C0 - 0x658 - sizeof(f32)];
    f32 unk6C0;
    char pad6C0[0x6C8 - 0x6C0 - sizeof(f32)];
    f32 unk6C8;
    char pad6C8[0x86C - 0x6C8 - sizeof(f32)];
    s32 unk86C;
};

extern float D_800C2D90_de;

struct func_8022D154_S2;
struct func_8022D154_S2 {
    char pad0[0x6C4];
    s32 unk6C4;
    char pad6C4[0x6E0 - 0x6C4 - sizeof(s32)];
    f32 unk6E0;
};

struct Actor_func_8022D290_de;
struct Actor_func_8022D290_de {
    u8 type;
    char pad_000[0x2];
    s8 unk_0x0003;
    s32 unk_0x0004;
    f32 posX;
    f32 posY;
    f32 posZ;
    s32 field_0x14;
    s32 field_0x18;
    s32 unk_0x001C;
    s32 unk_0x0020;
    s32 unk_0x0024;
    s32 unk_0x0028;
    char pad_new001[0xC];
    s32 unk_0x0038;
    char pad_002[0x4];
    f32 unk_0x0040;
    char pad_003[0x8];
    s32 unk_0x004C;
    f32 unk_0x0050;
    s32 unk_0x0054;
    f32 unk_0x0058;
    s32 unk_0x005C;
    s32 unk_0x0060;
    s32 unk_0x0064;
    s32 unk_0x0068;
    f32 unk_0x006C;
    f32 unk_0x0070;
    s32 unk_0x0074;
    char pad_005[0x8];
    s8 unk_0x0080;
    char pad_006[0x12];
    s8 unk_0x0093;
    u8 unk_0x0094;
    char pad_new002[0x27];
    s32 unk_0x00BC;
    char pad_new003[0x24];
    u16 ownerId;
    char pad_008[0x1A];
    s32 flags;
    f32 aimYaw;
    char pad_009[0x6];
    s8 unk_0x010E;
    char pad_010[0x65];
    s32 unk_0x0174;
    char pad_new004[0x5C];
    f32 unk_0x01D4;
    s32 self;
    char pad_012[0x14];
    s32 eventValue;
    char pad_new005[0x28];
    s32 unk_0x021C;
    char pad_new006[0x40];
    s32 unk_0x0260;
    s32 unk_0x0264;
    char pad_new007[0x34];
    f32 unk_0x029C;
    f32 unk_0x02A0;
    f32 unk_0x02A4;
    f32 unk_0x02A8;
    char pad_new008[0x38];
    s32 unk_0x02E4;
    s32 unk_0x02E8;
    char pad_013b[0x4];
    s32 unk_0x02F0;
    s32 unk_0x02F4;
    s32 unk_0x02F8;
    s32 unk_0x02FC;
    s32 unk_0x0300;
    char pad_new009[0x24];
    f32 unk_0x0328;
    char pad_new010[0x14];
    f32 unk_0x0340;
    s32 unk_0x0344;
    s32 unk_0x0348;
    s32 unk_0x034C;
    f32 unk_0x0350;
    f32 unk_0x0354;
    f32 unk_0x0358;
    f32 unk_0x035C;
    f32 unk_0x0360;
    f32 unk_0x0364;
    s32 unk_0x0368;
    s32 unk_0x036C;
    s32 unk_0x0370;
    s32 unk_0x0374;
    s32 unk_0x0378;
    s32 unk_0x037C;
    char pad_new011[0x68];
    s32 unk_0x03E8;
    char pad_017[0x70];
    s32 unk_0x045C;
    char pad_018[0x24];
    s32 unk_0x0484;
    char pad_019[0x4];
    s8 unk_0x048C;
    char pad_020[0x33];
    s32 unk_0x04C0;
    char pad_021[0x5F];
    s8 unk_0x0523;
    char pad_022[0x54];
    s32 unk_0x0578;
    char pad_023[0x18];
    s32 unk_0x0594;
    char pad_024[0x4];
    s32 unk_0x059C;
    f32 unk_0x05A0;
    char pad_025a[0x24];
    s32 unk_0x05C8;
    char pad_025b[0x4];
    s32 unk_0x05D0;
    s32 unk_0x05D4;
    s32 unk_0x05D8;
    s32 unk_0x05DC;
    s32 unk_0x05E0;
    s32 unk_0x05E4;
    s16 unk_0x05E8;
    s16 unk_0x05EA;
    s32 unk_0x05EC;
    s32 unk_0x05F0;
    s16 unk_0x05F4;
    s16 unk_0x05F6;
    s16 unk_0x05F8;
    s16 unk_0x05FA;
    char pad_027[0x32];
    s16 unk_0x062E;
    s16 unk_0x0630;
    s16 unk_0x0632;
    char pad_028[0x1C];
    s16 unk_0x0650;
    s16 unk_0x0652;
    s16 unk_0x0654;
    char pad_029[0x2];
    f32 unk_0x0658;
    s32 unk_0x065C;
    s32 unk_0x0660;
    s32 unk_0x0664;
    char pad_030[0x4];
    f32 unk_0x066C;
    f32 unk_0x0670;
    char pad_031[0x4];
    f32 unk_0x0678;
    s32 unk_0x067C;
    s32 unk_0x0680;
    s32 unk_0x0684;
    char pad_new012[0x10];
    s32 unk_0x0698;
    f32 unk_0x069C;
    f32 unk_0x06A0;
    f32 unk_0x06A4;
    f32 unk_0x06A8;
    s32 unk_0x06AC;
    s32 unk_0x06B0;
    s32 unk_0x06B4;
    s32 unk_0x06B8;
    s32 unk_0x06BC;
    f32 unk_0x06C0;
    f32 unk_0x06C4;
    f32 unk_0x06C8;
    f32 unk_0x06CC;
    s32 unk_0x06D0;
    f32 unk_0x06D4;
    f32 unk_0x06D8;
    f32 unk_0x06DC;
    f32 unk_0x06E0;
    f32 unk_0x06E4;
    f32 unk_0x06E8;
    f32 unk_0x06EC;
    f32 unk_0x06F0;
    f32 unk_0x06F4;
    s32 unk_0x06F8;
    s32 unk_0x06FC;
    s32 unk_0x0700;
    f32 unk_0x0704;
    f32 unk_0x0708;
    char pad_new013[0xC];
    f32 unk_0x0718;
    s32 unk_0x071C;
    f32 unk_0x0720;
    f32 unk_0x0724;
    f32 unk_0x0728;
    f32 unk_0x072C;
    f32 unk_0x0730;
    f32 unk_0x0734;
    f32 unk_0x0738;
    f32 unk_0x073C;
    f32 unk_0x0740;
    f32 unk_0x0744;
    char pad_new014[0x10];
    f32 unk_0x0758;
    f32 unk_0x075C;
    char pad_037[0x10];
    s16 unk_0x0770;
    char pad_038[0x2];
    s32 unk_0x0774;
    s32 unk_0x0778;
    s32 unk_0x077C;
    f32 unk_0x0780;
    f32 unk_0x0784;
    s32 unk_0x0788;
    f32 unk_0x078C;
    char pad_039[0x4];
    s32 unk_0x0794;
    s32 unk_0x0798;
    s32 unk_0x079C;
    s32 unk_0x07A0;
    s32 unk_0x07A4;
    s32 unk_0x07A8;
    s32 unk_0x07AC;
    s32 unk_0x07B0;
    s32 unk_0x07B4;
    s32 unk_0x07B8;
    f32 unk_0x07BC;
    s32 unk_0x07C0;
    s32 unk_0x07C4;
    s32 unk_0x07C8;
    s32 unk_0x07CC;
    s32 unk_0x07D0;
    s32 unk_0x07D4;
    s32 unk_0x07D8;
    s32 unk_0x07DC;
    s32 unk_0x07E0;
    s32 unk_0x07E4;
    s32 unk_0x07E8;
    f32 unk_0x07EC;
    f32 unk_0x07F0;
    f32 unk_0x07F4;
    char pad_new015[0x4];
    s32 unk_0x07FC;
    char pad_new016[0xC];
    s32 unk_0x080C;
    char pad_new017[0x28];
    f32 unk_0x0838;
    f32 unk_0x083C;
    s32 unk_0x0840;
    char pad_new018[0x8];
    s32 unk_0x084C;
    s32 unk_0x0850; /* action override state */
    f32 unk_0x0854;
    char pad_043[0x8];
    s32 unk_0x0860;
    char pad_044[0x8];
    s32 unk_0x086C;
    s32 unk_0x0870;
    char pad_045a[0xB8];
    s32 unk_0x092C;
    char pad_045b[0x8];
    s32 unk_0x0938;
    char pad_046[0x37C];
    s32 unk_0x0CB8;
    char pad_047[0x4];
    s32 unk_0x0CC0;
    char pad_048[0x8];
    s32 unk_0x0CCC;
    char pad_new020[0x194];
    s32 unk_0x0E64;
    char pad_new021[0x38];
    s32 unk_0x0EA0;
    char pad_new022[0x38];
    s32 unk_0x0EDC;
    char pad_new023[0x10];
    f32 unk_0x0EF0;
    f32 unk_0x0EF4;
    char pad_050[0x24];
    s32 unk_0x0F1C;
    char pad_051[0x4];
    s32 unk_0x0F24;
    char pad_052[0x4];
    f32 unk_0x0F2C;
    f32 unk_0x0F30;
    char pad_053[0x20];
    s32 unk_0x0F54;
    char pad_054[0xF0];
    s32 unk_0x1048;
    char pad_055[0x4];
    s32 unk_0x1050;
    char pad_056[0x4];
    f32 unk_0x1058;
    f32 unk_0x105C;
    char pad_057[0x1C];
    f32 unk_0x107C;
    s32 unk_0x1080;
    s32 unk_0x1084;
    char pad_058[0x4];
    s32 unk_0x108C;
    char pad_059[0x4];
    f32 unk_0x1094;
    f32 unk_0x1098;
    char pad_060[0x20];
    s32 unk_0x10BC;
    s32 unk_0x10C0;
    char pad_061[0x4];
    s32 unk_0x10C8;
    char pad_062[0x4];
    f32 unk_0x10D0;
    f32 unk_0x10D4;
    char pad_063[0x20];
    s32 unk_0x10F8;
    char pad_064[0x8];
    s32 unk_0x1104;
    char pad_065[0x28];
    f32 unk_0x1130;
    s32 unk_0x1134;
    char pad_066[0x8];
    s32 unk_0x1140;
    char pad_067[0x28];
    f32 unk_0x116C;
    s32 unk_0x1170;
    char pad_068[0x8];
    s32 unk_0x117C;
    char pad_069[0x28];
    f32 unk_0x11A8;
    s32 unk_0x11AC;
    s32 unk_0x11B0;
    s32 unk_0x11B4;
    s32 unk_0x11B8;
    s32 unk_0x11BC;
    s32 unk_0x11C0;
    f32 unk_0x11C4;
    s32 unk_0x11C8;
    s32 unk_0x11CC;
    s32 unk_0x11D0;
    s32 unk_0x11D4;
    f32 unk_0x11D8;
    f32 unk_0x11DC;
    f32 unk_0x11E0;
    f32 unk_0x11E4;
    char pad_072[0x4];
    f32 unk_0x11EC;
    s32 unk_0x11F0;
    f32 unk_0x11F4;
    s32 unk_0x11F8;
    s32 unk_0x11FC;
    char pad_new024[0xC];
    s32 unk_0x120C;
    s32 unk_0x1210;
    s32 unk_0x1214;
    s32 unk_0x1218;
    s32 unk_0x121C;
    s32 unk_0x1220;
    char pad_074[0x8];
    s32 unk_0x122C;
    f32 unk_0x1230;
    f32 unk_0x1234;
    s32 unk_0x1238;
    s8 unk_0x123C;
    s8 unk_0x123D;
    s8 unk_0x123E;
    char pad_075[0x1];
    f32 unk_0x1240;
    f32 unk_0x1244;
    char pad_076[0x78];
    f32 unk_0x12C0;
    char pad_077[0x28];
    s32 unk_0x12EC;
    s32 unk_0x12F0;
    char pad_078[0x40];
    s32 unk_0x1334;
    s32 unk_0x1338;
    s32 unk_0x133C;
    char pad_079[0x74];
    void *unk_0x13B4;
    char pad_080[0xC];
    s8 unk_0x13C4;
    char pad_081[0x3];
    s32 unk_0x13C8;
    char pad_082[0x8];
    s32 unk_0x13D4;
    s32 unk_0x13D8;
    char pad_083[0x4];
    s32 unk_0x13E0;
    char pad_084[0x6C];
    s32 unk_0x1450;
    s32 unk_0x1454;
    s32 unk_0x1458;
    s32 unk_0x145C;
    s32 unk_0x1460;
    s32 unk_0x1464;
    s32 unk_0x1468;
    s32 unk_0x146C;
    s32 unk_0x1470;
    s32 unk_0x1474;
    s32 unk_0x1478;
    s32 unk_0x147C;
    char pad_085[0x240];
    f32 unk_0x16C0;
    char pad_086[0x10];
    s32 unk_0x16D4;
    s16 unk_0x16D8;
    char pad_087[0x6];
    s32 unk_0x16E0;
};

extern float D_800C2DBC_de;

struct func_8022C894_S1;
typedef struct func_8022C894_S1 func_8022C894_S1;

extern void func_8022D49C_de(void);

extern float D_800C2DB8_de;

extern float D_800C7E9C;

struct func_8022D154_S1;
struct func_8022D154_S1 {
    char pad0[0x6C0];
    s32 unk6C0;
};



struct func_8022D154_S2;
typedef struct func_8022D154_S2 func_8022D154_S2;

struct func_8022D154_S1;
typedef struct func_8022D154_S1 func_8022D154_S1;

extern float D_800C7E90;

extern float D_800C2D88_de;

extern float D_800C7E94;

extern float D_800C2D8C_de;

struct func_8022CDAC_S1;
typedef struct func_8022CDAC_S1 func_8022CDAC_S1;

struct func_8022CA04_S2;
struct func_8022CA04_S2 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x20 - 0x18 - sizeof(void*)];
    f32 unk20;
};



struct IntegerState244;
struct IntegerState244 {
    unsigned char padding_0[572];
    s32 unk_23C;
    s32 unk_240;
};

extern float D_800C2D80_de;

extern void func_8022CF18_de(void);

struct func_8022C894_S1;
struct func_8022C894_S1 {
    char pad0[0x6C0];
    f32 unk6C0;
    char pad6C0[0x6C4 - 0x6C0 - sizeof(f32)];
    f32 unk6C4;
};

extern void func_8022D20C_de(void);

struct func_8022CC24_S1;
typedef struct func_8022CC24_S1 func_8022CC24_S1;

extern void func_8022D3F4_de(void);

struct Actor_func_8022D290_de;
typedef struct Actor_func_8022D290_de Actor_func_8022D290_de;

extern float D_800C2DC0_de;

struct func_8022D030_S1;
typedef struct func_8022D030_S1 func_8022D030_S1;

extern void func_8022D288_de(void);

extern void func_8022D4A4_de(void);

struct func_8022D198_S1;
typedef struct func_8022D198_S1 func_8022D198_S1;

struct func_8022D204_S1;
typedef struct func_8022D204_S1 func_8022D204_S1;

extern void func_8022C8EC_de(void);

struct func_8022CA04_S5;
struct func_8022CA04_S5 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5D8 - 0x10 - sizeof(s32)];
    void * unk5D8;
};

extern float D_800C2D84_de;

struct FloatState6C8;
typedef struct FloatState6C8 FloatState6C8;

struct func_8022CF28_S2;
struct func_8022CF28_S2 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x20 - 0x8 - sizeof(CVector3)];
    f32 unk20;
    char pad20[0x38 - 0x20 - sizeof(f32)];
    s32 unk38;
};

extern void func_8022C8F4_de(void);

extern void func_8022D25C_de(void *arg0);

struct func_8022D198_S1;
struct func_8022D198_S1 {
    char pad0[0x4A0];
    CVector3 unk4A0;
    char pad4A0[0x6E8 - 0x4A0 - sizeof(CVector3)];
    CVector3 unk6E8;
    char pad6E8[0x16C4 - 0x6E8 - sizeof(CVector3)];
    CVector3 unk16C4;
};



extern void func_8022D1A0_de(void);

struct ObjectLinks1458_2;
struct ObjectLinks1458_2 {
    char pad0[0x50];
    f32 unk_50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk_54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk_58;
    char pad58[0x658 - 0x58 - sizeof(f32)];
    f32 unk_658;
    char pad658[0x122C - 0x658 - sizeof(f32)];
    s32 unk_122C;
    char pad122C[0x1230 - 0x122C - sizeof(s32)];
    s32 unk_1230;
    char pad1230[0x1238 - 0x1230 - sizeof(s32)];
    s32 unk_1238;
    char pad1238[0x13C8 - 0x1238 - sizeof(s32)];
    s32 unk_13C8;
    char pad13C8[0x1454 - 0x13C8 - sizeof(s32)];
    void * unk_1454;
};

struct func_8022CF28_S2;
typedef struct func_8022CF28_S2 func_8022CF28_S2;

extern float D_800C7E98;

struct func_8022CA04_S2;
typedef struct func_8022CA04_S2 func_8022CA04_S2;

struct FloatState6C8;
struct FloatState6C8 {
    unsigned char padding_0[1700];
    f32 unk_6A4;
    unsigned char padding_6A8[28];
    f32 unk_6C4;
};



struct func_8022D204_S1;
struct func_8022D204_S1 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x11D8 - 0x100 - sizeof(s32)];
    s32 unk11D8;
    char pad11D8[0x11FC - 0x11D8 - sizeof(s32)];
    s32 unk11FC;
};

struct func_8022CA04_S5;
typedef struct func_8022CA04_S5 func_8022CA04_S5;

struct func_8022CF28_S1;
struct func_8022CF28_S1 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x6C0 - 0x5DC - sizeof(void*)];
    f32 unk6C0;
    char pad6C0[0x6C4 - 0x6C0 - sizeof(f32)];
    f32 unk6C4;
    char pad6C4[0x848 - 0x6C4 - sizeof(f32)];
    s32 unk848;
    char pad84C[0x938 - 0x84C];
    char unk938;
};



struct func_8022CF28_S1;
typedef struct func_8022CF28_S1 func_8022CF28_S1;

extern float D_800C2D60_de;

extern void func_8022D198_de(void);

extern void func_8022D3EC_de(void);

extern void func_80274870_de(f32 *value, f32 target, f32 rate);
extern void func_8022CE78_de(s32 arg0, s32 arg1);

extern void Ovlgame_UpdateRunEndPlayer(void *);
struct ObjectLinks854;
extern void func_80225B98_de(struct ObjectLinks854 *a, void *b, int c);

s32 func_8021C45C_de(s32, void *, s32, s32);


#endif
#endif
