#include "DATA_OVERLAY_SN_RECORDS.H"

#include "DATA/OVLTBL/ITEMS_COPYLOCALIZEDPLAYERNAMESUFFIX.H"
#include "TYPES.H"

/* 800F2F40_2.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
#ifdef VERSION_DE
unsigned int k_ItemsCopylocalizedplayernamesuffixEncodedWordsBlock1[8] = {
    0x00435988, 0x00000E0A, 0x00000013, 0x0042F768, 0x00000E08, 0x00000013, 0x0042F8DC, 0x00000E06,
};
#endif
#ifdef VERSION_US
struct {
    u8 precedingRecordFragment[5];
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record1;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record2;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record3;
    u8 followingRecordFragment[6];
} k_ItemsCopylocalizedplayernamesuffixEncodedWordsBlock1 __attribute__((aligned(4))) = {
    { 0x00, 0xAC, 0x7D, 0x00, 0x00 },
    { 52, SN_LE16(896), 42 },
    { 10, 92, SN_LE16(896), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(63148) } } },
    { 52, SN_LE16(912), 2 },
    { 0x0A, 0x5C, 0x90, 0x03, 0x02, 0x92 }
};
typedef char k_ItemsCopylocalizedplayernamesuffixEncodedWordsBlock1SizeCheck[(sizeof(k_ItemsCopylocalizedplayernamesuffixEncodedWordsBlock1) == 32) ? 1 : -1];
#endif
#endif

/* 800F3470_2.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
#ifdef VERSION_DE
unsigned int k_ItemsCopylocalizedplayernamesuffixEncodedWords[124] = {
    0x00000013, 0x0042EF10, 0x00000E03, 0x00000013, 0x00435990, 0x00000002, 0x00000013, 0x00432118,
    0x00000001, 0x00000013, 0x00430698, 0x0000000A, 0x00000013, 0x0042FB08, 0x0000000B, 0x00000013,
    (unsigned int)Frontend_DestroyPakProfileScreen_Address, 0x00000005, 0x00000013, 0x004303B8, 0x00000006, 0x00000013, 0x004300D8, 0x00000008,
    0x00000013, 0x0042FF00, 0x00000007, 0x00000013, 0x0042FFE8, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x00000001, (unsigned int)Frontend_DestroyPauseMenu_Address, 0x00000E08, 0x00000001,
    0x00435C28, 0x00000E0A, 0x00000001, 0x00435C20, 0x00000E06, 0x00000001, 0x00435AF4, 0x00000E03,
    0x00000001, 0x00435BC0, 0x00000001, 0x00000001, 0x00435C98, 0x00000002, 0x00000001, 0x00435C78,
    0x0000000A, 0x00000001, 0x00435C30, 0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x0000001F,
    0x00435EB4, 0x00000E08, 0x0000001F, 0x00435FDC, 0x00000E0A, 0x0000001F, 0x00435ED4, 0x00000E06,
    0x0000001F, 0x00435DE0, 0x00000E03, 0x0000001F, 0x00435E7C, 0x00000001, 0x0000001F, 0x00436004,
    0x00000002, 0x0000001F, 0x00435FE4, 0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x00000020,
    0x00436248, 0x00000E08, 0x00000020, 0x00436354, 0x00000E0A, 0x00000020, 0x00436268, 0x00000E06,
    0x00000020, 0x0043617C, 0x00000E03, 0x00000020, 0x00436210, 0x00000001, 0x00000020, 0x0043637C,
    0x00000002, 0x00000020, 0x0043635C, 0x00000000, 0x00000000, 0x00000000, 0xB25DCFB1, 0xB34020C4,
    0x00000000, 0x00000000, 0x00000E07, 0x00000005, 0x00436B28, 0x00000E08, 0x00000005, 0x00436B30,
    0x00000E06, 0x00000005, 0x004364B0, 0x00000E03,
};
#endif
#ifdef VERSION_US
#if defined(VERSION_US)
struct {
    u8 precedingRecordFragment[1];
    struct { u8 opcode; SnLe16 offset; } record0;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record1;
    struct { u8 opcode; SnLe16 offset; } record2;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record3;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record4;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record5;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record6;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record7;
    struct { u8 opcode; SnLe16 offset; } record8;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record9;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record10;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record11;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record12;
    struct { u8 opcode; SnLe16 offset; } record13;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record14;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record15;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record16;
    struct { u8 opcode; SnLe16 offset; } record17;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record18;
    struct { u8 opcode; SnLe16 offset; } record19;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record20;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record21;
    struct { u8 opcode; SnLe16 offset; } record22;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record23;
    struct { u8 opcode; SnLe16 offset; } record24;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record25;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record26;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record27;
    struct { u8 opcode; SnLe16 offset; } record28;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record29;
    struct { u8 opcode; SnLe16 offset; } record30;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record31;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record32;
    struct { u8 opcode; SnLe16 offset; } record33;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record34;
    struct { u8 opcode; SnLe16 offset; } record35;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record36;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record37;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record38;
    struct { u8 opcode; SnLe16 offset; } record39;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record40;
    struct { u8 opcode; SnLe16 section; } record41;
    struct { u8 opcode; SnLe16 codeSize; u8 codeFragment[158]; } record42;
} k_ItemsCopylocalizedplayernamesuffixEncodedWords __attribute__((aligned(4))) = {
    { 0x01 },
    { 50, SN_LE16(920) },
    { 10, 92, SN_LE16(924), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(64660) } } },
    { 50, SN_LE16(932) },
    { 10, 92, SN_LE16(936), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32184) } } },
    { 52, SN_LE16(944), 3 },
    { 10, 92, SN_LE16(944), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32172) } } },
    { 52, SN_LE16(952), 5 },
    { 10, 92, SN_LE16(952), { 2, SN_LE16(402) } },
    { 50, SN_LE16(960) },
    { 10, 96, SN_LE16(962), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(966), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(970), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(974), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(1080) },
    { 10, 92, SN_LE16(1080), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32172) } } },
    { 52, SN_LE16(1088), 4 },
    { 10, 92, SN_LE16(1088), { 2, SN_LE16(402) } },
    { 50, SN_LE16(1096) },
    { 10, 92, SN_LE16(1100), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(52984) } } },
    { 50, SN_LE16(1108) },
    { 10, 96, SN_LE16(1110), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1114), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(1164) },
    { 10, 92, SN_LE16(1168), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32704) } } },
    { 50, SN_LE16(1176) },
    { 10, 92, SN_LE16(1176), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32172) } } },
    { 52, SN_LE16(1184), 3 },
    { 10, 92, SN_LE16(1184), { 2, SN_LE16(402) } },
    { 50, SN_LE16(1192) },
    { 10, 92, SN_LE16(1196), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(53760) } } },
    { 50, SN_LE16(1204) },
    { 10, 96, SN_LE16(1206), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1210), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(1260) },
    { 10, 92, SN_LE16(1264), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32704) } } },
    { 50, SN_LE16(1272) },
    { 10, 92, SN_LE16(1272), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32172) } } },
    { 52, SN_LE16(1280), 35 },
    { 10, 92, SN_LE16(1284), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32184) } } },
    { 50, SN_LE16(1292) },
    { 52, SN_LE16(1316), 0 },
    { 6, SN_LE16(3) },
    { 2, SN_LE16(168), { 0x00, 0x00, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0A, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x08, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } }
};
typedef char k_ItemsCopylocalizedplayernamesuffixEncodedWordsSizeCheck[(sizeof(k_ItemsCopylocalizedplayernamesuffixEncodedWords) == 496) ? 1 : -1];
#endif
#endif
#endif

/* 800F3470_3.CPP */
#if defined(VERSION_DE)
extern char Player_FreeAlternatePlayerSettingsScreen_Address[];
extern char Frontend_HandleProfileResetConfirm_Address[];
extern char g_Frontend_FreeEquipmentScreenPackedAddress24[];
u32 g_itemsCopylocalizedplayernamesuffixWritableWordsDe[404] = {
    0x00000005, 0x00436AF8, 0x0000000A, 0x00000005, 0x00436BAC, 0x00000002,
    0x00000005, 0x00436C18, 0x00000001, 0x00000005, 0x00436BB4, 0x00000008,
    0x0000005C, 0x00436C54, 0x00000007, 0x0000005C, 0x00436D0C, 0x00000000,
    0x00000000, 0x00000000, 0x00000E07, 0x0000000C, 0x0043700C, 0x00000E08,
    0x0000000C, 0x00437014, 0x00000E06, 0x0000000C, 0x00436E54, 0x00000E03,
    0x0000000C, 0x00436FDC, 0x00000002, 0x0000000C, 0x0043708C, 0x00000001,
    0x0000000C, (unsigned int)Player_FreeAlternatePlayerSettingsScreen_Address, 0x00000008, 0x000001C2, 0x004370D4, 0x00000007,
    0x000001C2, 0x00437184, 0x00000000, 0x00000000, 0x00000000, 0xE559E3A1,
    0x00000000, 0x00000000, 0x00000E08, 0x00000009, 0x00437404, 0x00000E06,
    0x00000009, 0x004372D0, 0x00000E07, 0x00000009, 0x004373D4, 0x00000E03,
    0x00000009, 0x004373A4, 0x00000001, 0x00000009, 0x00437570, 0x00000002,
    0x00000009, 0x00437534, 0x00000000, 0x00000000, 0x00000000, 0x00000E08,
    0x0000001E, 0x004377D0, 0x00000E06, 0x0000001E, 0x004376D8, 0x00000E07,
    0x0000001E, 0x004377A8, 0x00000E03, 0x0000001E, 0x00437778, 0x00000001,
    0x0000001E, 0x004378F0, 0x00000002, 0x0000001E, 0x004378B4, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x00000012, 0x00438C44,
    0x00000E07, 0x00000012, 0x00438A94, 0x00000E06, 0x00000012, 0x00437A10,
    0x00000E03, 0x00000012, 0x00438A64, 0x00000002, 0x00000012, 0x00438E1C,
    0x00000001, 0x00000012, 0x00438D54, 0x00000E0A, 0x00000012, 0x00438A9C,
    0x00000000, 0x00000000, 0x00000000, 0xED1BA083, 0x1472E040, 0x9ACE57A0,
    0x00000000, 0x00000000, 0x00000E07, 0x00000006, 0x00438FD0, 0x00000E08,
    0x00000006, 0x00438FD8, 0x00000E06, 0x00000006, 0x00438ED0, 0x00000E03,
    0x00000006, 0x00438FA0, 0x00000002, 0x00000006, 0x00439134, 0x00000001,
    0x00000006, 0x004390E8, 0x00000000, 0x00000000, 0x00000000, 0x00000E07,
    0x0000000D, 0x004392C0, 0x00000E08, 0x0000000D, 0x004392C8, 0x00000E06,
    0x0000000D, 0x00439200, 0x00000E03, 0x0000000D, 0x00439290, 0x00000002,
    0x0000000D, 0x004393C4, 0x00000001, 0x0000000D, 0x00439368, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000E08, 0x00000018, 0x004395E8,
    0x00000E06, 0x00000018, 0x004394A0, 0x00000E03, 0x00000018, 0x004395B8,
    0x00000001, 0x00000018, 0x00439710, 0x00000002, 0x00000018, (unsigned int)Frontend_HandleProfileResetConfirm_Address,
    0x0000000A, 0x00000018, 0x004396B0, 0x00000000, 0x00000000, 0x00000000,
    0x030F775D, 0x30B05309, 0x00000E06, 0x00000021, 0x00439CF0, 0x00000002,
    0x00000021, 0x00439DC4, 0x00000001, 0x00000021, 0x00439D18, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x000000CF, 0x00000130, 0x000000E8,
    0x000000E9, 0x000000EA, 0x000000EB, 0x000000EC, 0x000000ED, 0x00000120,
    0x0000011F, 0x0000011E, 0x0000011D, 0x0000011C, 0x000000DC, 0x000000DE,
    0x000000E0, 0x000000E2, 0x000000E4, 0x000000E6, 0x000000F5, 0x00000131,
    0x0000010F, 0x00000110, 0x00000111, 0x00000112, 0x00000113, 0x00000114,
    0x00000126, 0x00000127, 0x00000128, 0x00000129, 0x0000012A, 0x000000F9,
    0x000000FB, 0x000000FD, 0x000000FF, 0x00000101, 0x00000103, 0x000000CD,
    0x00000132, 0x000000EE, 0x000000EF, 0x000000F0, 0x000000F1, 0x000000F2,
    0x000000F3, 0x0000012F, 0x0000012E, 0x0000012D, 0x0000012C, 0x0000012B,
    0x000000D1, 0x000000D3, 0x000000D5, 0x000000D7, 0x000000D9, 0x000000DB,
    0x000000F7, 0x00000133, 0x00000115, 0x00000116, 0x00000117, 0x00000118,
    0x00000119, 0x0000011A, 0x00000121, 0x00000122, 0x00000123, 0x00000124,
    0x00000125, 0x00000104, 0x00000106, 0x00000108, 0x0000010A, 0x0000010C,
    0x0000010E, 0x00000098, 0x00001397, 0x0000000A, 0x800D30E4, 0x000000AD,
    0x00001396, 0x0000000C, 0x800D30EC, 0x000000AF, 0x000013AD, 0x0000000B,
    0x800D30E8, 0x000000B3, 0x000013A9, 0x00000001, 0x800D30C0, 0x000000A2,
    0x0000139B, 0x0000000F, 0x800D30F8, 0x0000009A, 0x000013A1, 0x0000000D,
    0x800D30F0, 0x0000009B, 0x000013A2, 0x00000009, 0x800D30E0, 0x00000099,
    0x0000139A, 0x00000008, 0x800D30DC, 0x000000AA, 0x0000138D, 0x0000000E,
    0x800D30F4, 0x000000AE, 0x0000138F, 0x00000007, 0x800D30D8, 0x000000B0,
    0x0000138C, 0x00000002, 0x800D30C4, 0x000000A9, 0x000013A7, 0x00000005,
    0x800D30D0, 0x000000AB, 0x0000139E, 0x00000003, 0x800D30C8, 0x000000AC,
    0x00001393, 0x00000006, 0x800D30D4, 0x000000B1, 0x0000138B, 0x00000004,
    0x800D30CC, 0x00000E07, 0x00000008, 0x0043A2F0, 0x00000E08, 0x00000008,
    0x0043A5B8, 0x00000E0A, 0x00000008, 0x0043A850, 0x00000E06, 0x00000008,
    0x00439E90, 0x00000E03, 0x00000008, 0x0043BB30, 0x0000000A, 0x00000008,
    (unsigned int)g_Frontend_FreeEquipmentScreenPackedAddress24, 0x00000002, 0x00000008, 0x0043BEE8, 0x00000001, 0x00000008,
    0x0043AB00, 0x00000007, 0x00007530, 0x0043BDB0, 0x00000005, 0x00007530,
    0x0043BC80, 0x00000008, 0x00007530, 0x0043BE4C, 0x00000006, 0x00007530,
    0x0043BD18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x800E1C4C, 0x62696720, 0x63686561, 0x74206163, 0x74697661,
    0x74656400, 0x800E1C68, 0x6A616E65, 0x73206368, 0x65617420, 0x61637469,
    0x76617465, 0x64000000, 0x800E1C80, 0xD0543EBB, 0x8014235C, 0x801423F2,
    0x80142488, 0x8014251E,
};
#endif
