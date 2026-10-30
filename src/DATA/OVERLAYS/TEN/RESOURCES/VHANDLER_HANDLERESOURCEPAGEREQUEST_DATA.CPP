#include "DATA_OVERLAY_SN_RECORDS.H"

#include "include_asm.h"

/* 800FF254.CPP */
#if defined(VERSION_DE) || defined(VERSION_US)
#ifdef VERSION_DE
unsigned int k_VhandlerHandleresourcepagerequestEncodedWords[575] = {
    0xA131C611, 0x0B18060E, 0x50B13131, 0x5027B5F2, 0xC012B102, 0x2415E12E, 0x1A5E41A1, 0xD54E9F4B,
    0x4895E2F6, 0xA1E2092D, 0x3E6F20BF, 0x78B134B5, 0xF4DB1EC0, 0xCA2DA1B5, 0xAE6B4BF2, 0xB87DD3B1,
    0x110A5DE3, 0x0EF1BEDD, 0xA1A3E1F0, 0xF038661D, 0x63B12D02, 0xB2002A36, 0xF035B33F, 0x15D30E45,
    0x03B41EB3, 0x1410016C, 0x13D1F21D, 0xB1FF4FFF, 0x1EF0EE0E, 0xEFB1EEF0, 0x0FE942CE, 0x0FB4B13B,
    0x0FAD20BD, 0x3DFB50B1, 0x01E5EFDF, 0xD113F30B, 0xB10F2C10, 0x5F30DF23, 0xEEA23C11, 0xFC50BD71,
    0x4BCFB3FE, 0xDFF3F1FB, 0xE40A32B1, 0x0B1EA1BF, 0xE1EDB013, 0xB1E14FC2, 0xEA2D1E2F, 0xF0B1FF03,
    0x450047A0, 0x06F2B33F, 0xD1011050, 0x301D03B1, 0x23E12F7C, 0x52D5124F, 0xB33F12E6, 0xE1407A40,
    0x33B1F204, 0xB17042D2, 0xC11EB00F, 0x21311B1F, 0x13E00EA2, 0x41CD2D17, 0xDAAEDFD9, 0xB22FCC40,
    0xC1FB3FE0, 0xECB11DD1, 0x03D04FCF, 0xEF12B1EE, 0x0DEDA000, 0x0F2180B3, 0xEF2DA02F, 0xF1B0FF3D,
    0xB12AD3C4, 0xFAD0CFC0, 0xFDB1C231, 0x2C2FE3A1, 0x1A30B101, 0xDFD11C32, 0xEE5006B1, 0xFD2F5315,
    0xD05103EF, 0xB121F4E0, 0x34313D01, 0x00A37E0D, 0x35F0E2F4, 0x0FDCB151, 0x5E233003, 0x4F4015B1,
    0x4F211502, 0x407F0E20, 0xA375D7BE, 0x4532D450, 0x5FB1E225, 0xFF12FDFE, 0x1D0FB1C6, 0xCAEF1D0C,
    0xFBC0E0C3, 0xF00B30FE, 0xF1E1E0FE, 0xB3293C4E, 0xF1E1BF2D, 0x02B1A3E0, 0x0BFFE01D, 0xD4C2B2F2,
    0x23F251F0, 0x2A0FF2B2, 0x3FF0F312, 0x032D0FEB, 0xB10F0103, 0x06014002, 0xFEA26311, 0x5793014E,
    0x2143B120, 0xD2E11F41, 0xE12320A3, 0x7F614C03, 0x1385064F, 0xB325C231, 0xFD1E313C, 0x04B3EE3E,
    0x1C000EB0, 0xEB3FB1DD, 0x1BFFE1DE, 0x2DED1EB3, 0xC010C2EF, 0x22B110DD, 0xB1F0D0F3, 0x1EF3D40D,
    0xF3B30032, 0xE0F16100, 0x1122B1FE, 0x1D04302F, 0x110E21B1, 0xC14214D2, 0x51F23F1C, 0xA23FE134,
    0xD1EC522E, 0xF1A14D15, 0x11300FEE, 0x9215A1FF, 0x1FF0F0C1, 0xCE0018A3, 0xF10D08E1, 0x1A4A1FB1,
    0xB1EC3DF0, 0xCED0FD2F, 0xFFA0ADED, 0xEEA022DE, 0x2F42B320, 0x3FF50F01, 0x2C20E0B1, 0x204022D5,
    0x3031E212, 0xB1F01EF3, 0xFF4F3100, 0xC0A3EF3D, 0xD1F0E41E, 0xFEB3A300, 0xEB01F0FE, 0xF3E301A3,
    0xE00C2C00, 0xF5FCC11C, 0xA23E231F, 0xFFCE2FDA, 0x2CB125F2, 0x102110E1, 0x321DB101, 0x1F4F12F4,
    0x114F23B1, 0x0103251E, 0x41FF6011, 0xA2FFEFA2, 0x621D1B2F, 0x17A1BCFB, 0xE3AE0F10, 0x3CD1A3E5,
    0xEC1FE0FE, 0xCBC1A2A3, 0x0FDB2EA5, 0xD83A04C0, 0xA1DD3FC3, 0x0DEED6EB, 0xB3A1F11B, 0x3F107E5D,
    0x6511A3C5, 0x40D00514, 0x4313C7A3, 0x7E60E2D1, 0x3E523F5B, 0xA1C56332, 0xB401D73D, 0x3CA20EE2,
    0xEE23DD08, 0xE1EEB3EF, 0xC02B04FE, 0xFFFBE2A1, 0x921DFAE0, 0xDF0A3EA3, 0xB1E0004D, 0xE0B01021,
    0xDFA114F1, 0x7D16F22E, 0xF437A34D, 0x1381E022, 0x5C1FC2A2, 0x317E4940, 0xF11E065C, 0xA1048031,
    0x30E4B222, 0x1EA106B0, 0x3D3406EE, 0x5811A1B5, 0xE22912E5, 0x4C3E31A1, 0xA00C5A06, 0xC22F5FFD,
    0xA3AD4070, 0x14C48B6F, 0x44B3F21E, 0xDF01E140, 0xE000A093, 0x3E40E3BD, 0xE9D314B1, 0x041D32F0,
    0x1E3033A3, 0xA1685633, 0x211F2867, 0x26A1CCD0, 0xB2023E70, 0xDF95B2F1, 0x5F13DCF2, 0xF22302B1,
    0xDDFBE3FC, 0x40F11ED1, 0xA14AFD31, 0xEC6DDEDF, 0x2FA3F073, 0xB0FD1CC4, 0x2E22A2F2, 0xCED4D97D,
    0x40CFDDA2, 0xB2F1F332, 0x1C203EFA, 0xB33CEE00, 0xFF14E1FF, 0x0DA2AD30, 0xC52C908F, 0x3F72A150,
    0xA8FECD21, 0xA61B19A1, 0xE0D6E5C1, 0x6DC2E04F, 0xA33246B4, 0x2E1D0F1E, 0x41B140E0, 0xEFFD1E24,
    0x1F2DA3BF, 0xD4306413, 0x92DDF5B3, 0x3133EFFF, 0xED1F5104, 0xB3FE0DF2, 0xF05013FD, 0x0EB30141,
    0x05FE1C1F, 0xF213A16F, 0x2CB19C40, 0x44A50CA1, 0x1F5B0205, 0x211204D1, 0xA130401E, 0xDD0F3B10,
    0x01A2DFFB, 0xED01C271, 0x2FBFB1D2, 0xF2303F11, 0xAC2025A1, 0xC211FBED, 0xF42F6CF4, 0xA1842EF2,
    0x236D11FD, 0xACB101F1, 0x2FE1FB2D, 0x03D1A338, 0x20BDE2F1, 0x3D4EABB3, 0xD1FF04E1, 0xF0FCFD20,
    0xB3052F1D, 0xF0D0005E, 0x32A1EFDC, 0xDC14F62E, 0x6EFCA1A2, 0xFEF3C446, 0xF03D00A1, 0xD2044226,
    0xED3FDF2C, 0xA1610510, 0x4DDC033E, 0x15A14A14, 0x170E353D, 0x531DA125, 0xCE433501, 0x1BF01FA1,
    0x12240CE1, 0xB1D01F22, 0xA30BFEDE, 0xE201060E, 0xB9A33EFF, 0x51032ECD, 0xC221A351, 0x73EE11DB,
    0x4E27F6A3, 0xF0D02DA1, 0x12E17E01, 0xA3EEBCF2, 0x22E3E42E, 0xECA3D0EC, 0x50E2FFF3, 0x90FEA3DE,
    0x24013C0B, 0x1FDF11A2, 0x300EF3F1, 0x12EA0AF0, 0xA232F1FE, 0xF3BD0EC1, 0x40A305D0, 0xEEECF1F2,
    0x7D11A11E, 0xF1EF1F52, 0xE40D2CA1, 0x4DB34306, 0x102DC0FD, 0xA2104F04, 0x4101CEFE, 0xE4A2013C,
    0x02800E2F, 0xD3139130, 0x7E2879D6, 0x2444A7B2, 0x1210000D, 0x1F10F400, 0xA100CF02, 0xFD3341E0,
    0x01A1FF2E, 0xE7616F20, 0x21C2A310, 0x4FFF32D2, 0xDD1E10A1, 0x10F1301D, 0xB2F401F0, 0x90CECCE7,
    0xD9310FBD, 0xB1A12E81, 0x0B41D22B, 0xFD1EB1F0, 0xDF011D12, 0xDF0BF0A1, 0xEF1F05E0, 0xE101DD3E,
    0x92B43D40, 0x579F9CF7, 0x0BA33004, 0x20DE2B1F, 0x0522915A, 0x3780C03C, 0x74636E93, 0x6CA47DB7,
    0x51460A0A, 0xA1F0E404, 0x10E2023D, 0xF3A04040, 0xFFDD0304, 0xB342A123, 0xC90F1EF0, 0x03D230A1,
    0xDD029D3D, 0x200C4E90, 0xA1FEC141, 0xF00112DF, 0x5DA3B20D, 0x2D403E0F, 0x3FEFA2DE, 0xBDEC100D,
    0x61BE2092, 0xBEB15F01, 0x4C4855E1, 0x9371DD33, 0x3AD1564B, 0x24A11010, 0x14D2022F, 0x330C9154,
    0x576F678F, 0x832FF1A0, 0x1F210511, 0x3421C22E, 0xA122C01F, 0xD20E2F98, 0x02A1EF0E, 0xF111D3FB,
    0x1100A0F1, 0x0EFBC001, 0xF01D23A2, 0xB1CF100E, 0x22F21EFB, 0x93F4BF32, 0x1AF910DB, 0x3FA2EE1E,
    0x12BF0F0E, 0x3030A1F2, 0x20F023E4, 0x212E0293, 0x4EF34081, 0x20C7F351, 0xA1EF5F0E, 0x1F00F24F,
    0x15A130F5, 0x4D2F3030, 0xF5309334, 0xEC262CDC, 0xCE50E5A1, 0x11DF1D0B, 0xE0E0B12C, 0x9202B49D,
    0x5ADC4B5D, 0xD190F225, 0xE4923CCE, 0x0D69A152, 0xE100F1EC, 0xFFF22CA1, 0x1F2DE5DD, 0xFEB32D00,
    0x9228A51E, 0x0EE38FE7, 0x3CA1041C, 0x130F4044, 0xD1139000, 0xF81A0D70, 0x64210692, 0x1AD6E200,
    0x2D012720, 0xA2350F11, 0x2020D1D3, 0x20A20031, 0xEE3E01EF, 0xCDFE92E2, 0x829987EA, 0x5943CCA1,
    0xEDFDF3E0, 0x2404DD1C, 0xA2CA2FEE, 0x3E1F011E, 0xD2913FC4, 0x8AE0248C, 0x9642A241, 0x0B00D030,
    0x0FEFF190, 0x1333CF72, 0x730412F0, 0xA24FFF00, 0xF43121F0, 0xFEA2DDF1, 0xF2E04FE2, 0xF0DFA12E,
    0xE212F324, 0x3C031FA3, 0x30E321C1, 0x3F23D15F, 0x922173F4, 0x01B62569, 0x6FA05101, 0x1011E011,
    0x20FF90E0, 0x6C51EDBD, 0xBEE002A2, 0xEC2DB0FE, 0xE010D2CE, 0x90CBC0EC, 0xCE1E347D, 0xFDA2DEFD,
    0xF19D1002, 0x4D03A1ED, 0x0E1E10B1, 0x4E01E1A1, 0x04E04E03, 0x0F0CE011, 0xA22312F1, 0xFE000F1E,
    0x1490F30E, 0xBCC6100D, 0x73FBA01E, 0xFF0F3342, 0x2FF05391, 0xC7F0D09E, 0x24936D04, 0x90B4FFC8,
    0xEDAF11E1, 0x9192E9F1, 0x3C1E1CE0, 0x255DA231, 0x2010E014, 0xD22FF4A3, 0xED111FF0, 0x0F1CD2FE,
    0x920C8E0B, 0x01611D1D, 0x2393C2FE, 0x262EE06B, 0x3556A1FE, 0x31B04531, 0x3F01E1A1, 0x4326E1F1,
    0x0E3EE241, 0x93E10F3F, 0xB071AEBD, 0x3F91400E, 0xC0F1B3D0, 0xC8F393F0, 0x3A3FE415, 0xCB92B2A2,
    0x1D7F1EF0, 0xFF10F01B, 0x92CEDEA4, 0x4254D3F9, 0x1191C371, 0x7DE40B31, 0x00E4913F, 0x7114C00B,
    0x16530C91, 0x4C842001, 0x43AFCC1A, 0x92D40F60, 0xE0B3DD1C, 0x0193E1ED, 0xEEB61B31, 0x81C2922F,
    0x2F379E4E, 0xB4327DA1, 0x010F0421, 0x11D05F10, 0x92210E80, 0x8E01D072, 0xC093213D, 0x638A3DDD,
    0x271D937A, 0xBCD43B52, 0xE32CCDA3, 0x12B221F2, 0xF0CD0FF4, 0x93402DD6, 0x9EE0F770, 0xA1A31FB0,
    0xC4204F1E, 0x0CFFA1F3, 0xD1214D2F, 0xC0DD0493, 0xFE6D0A1E, 0x0717D122, 0x93B9F330, 0x0313F2B1,
    0xDFA32F02, 0x210EFF40, 0x013091A1, 0x01FA3D27, 0x6220FFA1, 0xE1E0510F, 0x112EF0CE, 0x934F5D12,
    0xECC2BE1F, 0x1E92E41E, 0xDFBDE100, 0x4D0391D0, 0xF2F2E0A0, 0x1D013F93, 0x392D31C5,
};
#endif
#ifdef VERSION_US
struct {
    u8 precedingRecordFragment[5];
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record1;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record2;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record3;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record4;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record5;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record6;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record7;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record8;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record9;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record10;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record11;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record12;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record13;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record14;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record15;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record16;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe32 constant; } left; struct { u8 opcode; SnLe16 symbol; } right; } expression; } record17;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe32 constant; } left; struct { u8 opcode; SnLe16 symbol; } right; } expression; } record18;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record19;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record20;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record21;
    struct { u8 opcode; SnLe16 offset; } record22;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record23;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record24;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record25;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record26;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record27;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record28;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record29;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record30;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record31;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record32;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record33;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record34;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record35;
    struct { u8 opcode; SnLe16 offset; } record36;
    struct { u8 opcode; SnLe16 offset; SnLe32 line; } record37;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record38;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record39;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record40;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record41;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record42;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record43;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record44;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record45;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record46;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record47;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record48;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record49;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record50;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record51;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record52;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record53;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record54;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record55;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record56;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record57;
    struct { u8 opcode; SnLe16 offset; } record58;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record59;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record60;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record61;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record62;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record63;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record64;
    struct { u8 opcode; SnLe16 offset; } record65;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record66;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record67;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record68;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record69;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record70;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record71;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record72;
    struct { u8 opcode; SnLe16 offset; } record73;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record74;
    struct { u8 opcode; SnLe16 offset; } record75;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record76;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record77;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record78;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record79;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record80;
    struct { u8 opcode; SnLe16 offset; } record81;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record82;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record83;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record84;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record85;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record86;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record87;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record88;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record89;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record90;
    struct { u8 opcode; SnLe16 offset; } record91;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record92;
    struct { u8 opcode; SnLe16 offset; } record93;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record94;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record95;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record96;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record97;
    struct { u8 opcode; SnLe16 offset; } record98;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record99;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record100;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record101;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record102;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record103;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record104;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record105;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record106;
    struct { u8 opcode; SnLe16 offset; } record107;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record108;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record109;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record110;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record111;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record112;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record113;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record114;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record115;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record116;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record117;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record118;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record119;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record120;
    struct { u8 opcode; SnLe16 offset; } record121;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record122;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record123;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record124;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record125;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record126;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record127;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record128;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record129;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record130;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record131;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record132;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record133;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record134;
    struct { u8 opcode; SnLe16 offset; } record135;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record136;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record137;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record138;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record139;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record140;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record141;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record142;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record143;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record144;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record145;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record146;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record147;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record148;
    struct { u8 opcode; SnLe16 offset; } record149;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record150;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record151;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record152;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record153;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record154;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record155;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record156;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record157;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record158;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record159;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record160;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record161;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record162;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record163;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record164;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record165;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record166;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record167;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record168;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record169;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record170;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record171;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record172;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record173;
    struct { u8 opcode; SnLe16 offset; } record174;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record175;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record176;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record177;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record178;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record179;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record180;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record181;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record182;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record183;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record184;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record185;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record186;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record187;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record188;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record189;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record190;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record191;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record192;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record193;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record194;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record195;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record196;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record197;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record198;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record199;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record200;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record201;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record202;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record203;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record204;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record205;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record206;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record207;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record208;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record209;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record210;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record211;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record212;
    struct { u8 opcode; SnLe16 offset; } record213;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record214;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record215;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record216;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record217;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record218;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record219;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record220;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record221;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record222;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record223;
    struct { u8 opcode; SnLe16 offset; SnLe32 line; } record224;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record225;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record226;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record227;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record228;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record229;
    u8 followingRecordFragment[6];
} k_VhandlerHandleresourcepagerequestEncodedWords __attribute__((aligned(4))) = {
    { 0x00, 0x04, 0x00, 0x00, 0x00 },
    { 10, 96, SN_LE16(1238), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 98, SN_LE16(1242), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 92, SN_LE16(1248), { 2, SN_LE16(439) } },
    { 52, SN_LE16(1256), 2 },
    { 10, 96, SN_LE16(1298), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1302), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1394), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1398), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1450), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1900) } } },
    { 10, 98, SN_LE16(1454), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1900) } } },
    { 10, 92, SN_LE16(1460), { 2, SN_LE16(439) } },
    { 52, SN_LE16(1468), 2 },
    { 10, 92, SN_LE16(1468), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(56424) } } },
    { 52, SN_LE16(1476), 4 },
    { 10, 96, SN_LE16(1518), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1522), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1570), { 44, { 0, SN_LE32(159121) }, { 2, SN_LE16(388) } } },
    { 10, 98, SN_LE16(1574), { 44, { 0, SN_LE32(159121) }, { 2, SN_LE16(388) } } },
    { 10, 96, SN_LE16(1590), { 2, SN_LE16(435) } },
    { 10, 98, SN_LE16(1598), { 2, SN_LE16(435) } },
    { 10, 92, SN_LE16(1600), { 2, SN_LE16(427) } },
    { 50, SN_LE16(1608) },
    { 10, 96, SN_LE16(1650), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1654), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1706), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 98, SN_LE16(1710), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 92, SN_LE16(1716), { 2, SN_LE16(439) } },
    { 52, SN_LE16(1724), 2 },
    { 10, 96, SN_LE16(1766), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1770), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1862), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1866), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(1918), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1900) } } },
    { 10, 98, SN_LE16(1922), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1900) } } },
    { 10, 92, SN_LE16(1928), { 2, SN_LE16(439) } },
    { 50, SN_LE16(1936) },
    { 56, SN_LE16(1944), SN_LE32(4968) },
    { 10, 92, SN_LE16(1956), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(54584) } } },
    { 52, SN_LE16(1964), 45 },
    { 52, SN_LE16(1976), 2 },
    { 10, 96, SN_LE16(1978), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(1982), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(2032), { 2, SN_LE16(381) } },
    { 52, SN_LE16(2044), 2 },
    { 10, 96, SN_LE16(2058), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(2062), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(2070), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 98, SN_LE16(2074), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 92, SN_LE16(2076), { 2, SN_LE16(376) } },
    { 52, SN_LE16(2096), 2 },
    { 10, 92, SN_LE16(2108), { 2, SN_LE16(440) } },
    { 52, SN_LE16(2124), 2 },
    { 10, 96, SN_LE16(2166), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2170), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(2186), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 98, SN_LE16(2190), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 92, SN_LE16(2196), { 2, SN_LE16(439) } },
    { 50, SN_LE16(2204) },
    { 10, 96, SN_LE16(2250), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2254), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(2268), 2 },
    { 10, 96, SN_LE16(2270), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2274), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(2324), { 2, SN_LE16(381) } },
    { 50, SN_LE16(2336) },
    { 10, 96, SN_LE16(2350), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(2354), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(2362), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 98, SN_LE16(2366), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 92, SN_LE16(2368), { 2, SN_LE16(376) } },
    { 52, SN_LE16(2388), 3 },
    { 10, 92, SN_LE16(2388), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(60016) } } },
    { 50, SN_LE16(2400) },
    { 10, 92, SN_LE16(2404), { 2, SN_LE16(441) } },
    { 50, SN_LE16(2416) },
    { 10, 96, SN_LE16(2458), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2462), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(2478), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 98, SN_LE16(2482), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1884) } } },
    { 10, 92, SN_LE16(2488), { 2, SN_LE16(439) } },
    { 50, SN_LE16(2496) },
    { 10, 96, SN_LE16(2542), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2546), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(2560), 2 },
    { 10, 92, SN_LE16(2560), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(57056) } } },
    { 52, SN_LE16(2568), 2 },
    { 52, SN_LE16(2576), 4 },
    { 52, SN_LE16(2592), 2 },
    { 10, 96, SN_LE16(2594), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2598), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(2648) },
    { 10, 92, SN_LE16(2652), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(32704) } } },
    { 50, SN_LE16(2660) },
    { 10, 92, SN_LE16(2660), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(57920) } } },
    { 52, SN_LE16(2668), 7 },
    { 10, 96, SN_LE16(2670), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2674), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(2724) },
    { 10, 96, SN_LE16(2726), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2730), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(2776), 3 },
    { 10, 96, SN_LE16(2778), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2782), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(2832), { 2, SN_LE16(381) } },
    { 10, 96, SN_LE16(2842), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2846), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(2892) },
    { 10, 96, SN_LE16(2894), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2898), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(2954), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(2958), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(2966), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1908) } } },
    { 10, 98, SN_LE16(2970), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1908) } } },
    { 10, 92, SN_LE16(2972), { 2, SN_LE16(376) } },
    { 52, SN_LE16(2992), 2 },
    { 10, 96, SN_LE16(2994), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(2998), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(3048), { 2, SN_LE16(381) } },
    { 10, 96, SN_LE16(3058), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3062), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(3108) },
    { 10, 96, SN_LE16(3110), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3114), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(3170), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(3174), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(3182), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(2000) } } },
    { 10, 98, SN_LE16(3186), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(2000) } } },
    { 10, 92, SN_LE16(3188), { 2, SN_LE16(376) } },
    { 52, SN_LE16(3208), 2 },
    { 10, 96, SN_LE16(3210), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3214), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(3264), { 2, SN_LE16(381) } },
    { 10, 96, SN_LE16(3274), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3278), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(3324) },
    { 10, 96, SN_LE16(3326), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3330), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(3386), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(3390), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(3398), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(2092) } } },
    { 10, 98, SN_LE16(3402), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(2092) } } },
    { 10, 92, SN_LE16(3404), { 2, SN_LE16(376) } },
    { 52, SN_LE16(3424), 2 },
    { 10, 92, SN_LE16(3432), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(57944) } } },
    { 52, SN_LE16(3440), 2 },
    { 52, SN_LE16(3464), 0 },
    { 52, SN_LE16(3464), 3 },
    { 52, SN_LE16(3464), 0 },
    { 50, SN_LE16(3488) },
    { 52, SN_LE16(3488), 6 },
    { 10, 92, SN_LE16(3516), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(58044) } } },
    { 10, 96, SN_LE16(3526), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(3530), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(3538), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 98, SN_LE16(3542), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 92, SN_LE16(3544), { 2, SN_LE16(376) } },
    { 52, SN_LE16(3564), 3 },
    { 52, SN_LE16(3580), 2 },
    { 10, 96, SN_LE16(3582), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3586), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(3644), 2 },
    { 10, 96, SN_LE16(3646), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3650), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(3694), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3698), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(3752), 2 },
    { 10, 96, SN_LE16(3754), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3758), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(3810), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3814), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(3872), 2 },
    { 10, 96, SN_LE16(3874), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3878), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(3940) },
    { 10, 96, SN_LE16(3942), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3946), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(3990), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(3994), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(4048), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(58592) } } },
    { 52, SN_LE16(4056), 2 },
    { 10, 96, SN_LE16(4058), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4062), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4112), 3 },
    { 10, 92, SN_LE16(4112), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59052) } } },
    { 52, SN_LE16(4120), 3 },
    { 10, 96, SN_LE16(4122), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4126), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4180), 2 },
    { 10, 96, SN_LE16(4182), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4186), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(4230), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4234), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4288), 2 },
    { 10, 96, SN_LE16(4290), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4294), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(4350), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4354), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(4398), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4402), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4464), 3 },
    { 10, 96, SN_LE16(4466), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4470), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(4514), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4518), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4572), 16 },
    { 10, 92, SN_LE16(4592), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59452) } } },
    { 52, SN_LE16(4600), 3 },
    { 10, 96, SN_LE16(4602), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4606), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(4676), 3 },
    { 10, 96, SN_LE16(4678), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4682), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(4748) },
    { 10, 96, SN_LE16(4762), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(4766), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(4774), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 98, SN_LE16(4778), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(1776) } } },
    { 10, 92, SN_LE16(4780), { 2, SN_LE16(376) } },
    { 52, SN_LE16(4800), 3 },
    { 10, 96, SN_LE16(4846), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4850), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(4858), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4862), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 56, SN_LE16(4952), SN_LE32(5118) },
    { 10, 92, SN_LE16(4964), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59056) } } },
    { 52, SN_LE16(4972), 15 },
    { 10, 96, SN_LE16(4974), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(4978), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(5028), 2 },
    { 0x0A, 0x60, 0xA6, 0x13, 0x2C, 0x04 }
};
typedef char k_VhandlerHandleresourcepagerequestEncodedWordsSizeCheck[(sizeof(k_VhandlerHandleresourcepagerequestEncodedWords) == 2300) ? 1 : -1];
#endif
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int g_VhandlerHandleresourcepagerequestEncodedWordSingle[1] = {
    0x3E300DCC,
};
#endif
#if defined(VERSION_US)
unsigned int g_VhandlerHandleresourcepagerequestEncodedWordSingle[1] = {
    0x03000004,
};
#endif
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

/* 800FFB54.CPP */
#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#ifdef VERSION_DE
unsigned int g_VhandlerHandleresourcepagerequestEncodedWords[179] = {
    0x93F0D7E7, 0x709FF00E, 0x61931143, 0x0FDE1D15, 0x452D91CF, 0x0E1E71E7, 0x34FD29A3, 0x01021F41,
    0xE1E21D00, 0x93230208, 0x0DD1E525, 0xBE93DDBD, 0xDC31027B, 0xD09E938D, 0x6A33F2D2, 0xBBC1B091,
    0xC37EF3C2, 0xCFCA12F1, 0x90126F02, 0xF0EE0DFF, 0xEE911F03, 0xD5EC4C0E, 0x4743A1F2, 0x01E10041,
    0x0222FE93, 0xF120F523, 0x3E141DE2, 0x93D0E360, 0x261C04FA, 0x2493F113, 0x132F2801, 0xB1039352,
    0x0EDD2C22, 0xB1FC7291, 0xF44EB0EF, 0xFE412D05, 0x8087ED0F, 0xEFCEAF0A, 0xCB93EFED, 0x59ECE21E,
    0xD31D93C9, 0x32D4B25D, 0x01BC0191, 0x2D5235EC, 0x3FB10104, 0x9312211C, 0xB4FE1114, 0x51926002,
    0x0ECDFF45, 0xF12B93B4, 0x1D0330F2, 0x13EAEF81, 0x9773450F, 0xE1FC7D0C, 0xA30410F0, 0x2F0F0021,
    0x0283F3EE, 0x1D4E1E65, 0xB147931F, 0x0FF20C20, 0x26C11483, 0xCC3ACD2B, 0x0A7FDBED, 0x93D0C0FD,
    0x03A11B1A, 0x0F938001, 0x2CCD1FDC, 0x0F2C8298, 0x05E0E1FB, 0xD00B7093, 0x0143DE54, 0xB430006F,
    0x93214FD0, 0x10512BD7, 0x3E910323, 0xA50371FD, 0x361F9131, 0x5141E4F3, 0x0FEE1E93, 0x36FE3112,
    0xFD2FF101, 0x931600FB, 0x04DFE13E, 0x049302CF, 0x002ACD03, 0xF13F93B0, 0xFF00FC12, 0xFD2E3F91,
    0xBE1FD322, 0xE0D40BEC, 0x91E23C5D, 0xDE4E00EE, 0xB2911416, 0x00F5200E, 0x4E0F9362, 0x21DB20F3,
    0x1022F291, 0x21F1F4BD, 0xFF222E00, 0x910F2ADF, 0x0020E0E2, 0x0B93FFBF, 0x1FF40EEF, 0xD2CC91EE,
    0x3DE4FE01, 0x0EDDE081, 0x20EE4CE4, 0xD25E3ED6, 0x82451FE3, 0x50004C0F, 0x1292FFE2, 0x242F3F03,
    0x2FFD8133, 0x244D2021, 0xD11F4683, 0xE144C061, 0xFF61CFF0, 0x82167EF6, 0x6FF22221, 0x528267C0,
    0x7F15FE88, 0x102F920B, 0x0FC120EC, 0xC1131293, 0xEF240FFD, 0xF002EE1E, 0x83E2322E, 0xFED22E2D,
    0x9082D32E, 0x21F083F4, 0x1EED82ED, 0xF30EFCE1, 0xF1DE2583, 0x4C23E1BE, 0x53DF31E3, 0x91FB2F0F,
    0xE5F0221D, 0x0F82EBA1, 0x9F6DE63D, 0x99B2832E, 0x1D4301DD, 0xFB474F92, 0x00F01111, 0x1FF14600,
    0x82DD5FF2, 0xED0F525F, 0xC282F4E0, 0x1EFFFE44, 0x200283F0, 0xF2DEF100, 0x5F0EFC83, 0x34EF0DCF,
    0x01BEC10F, 0x831E128C, 0x5FFBC61F, 0x4F83A1DC, 0x43D0DF3F, 0xEFD183F2, 0xF63FD024, 0x3EEF1083,
    0x1350D924, 0xF0F2CC01, 0x8360ABD3, 0x115F9C2F, 0x1493FD0E, 0x40E0EFFF, 0x043D73B8, 0x7204E014,
    0x42F3C393, 0x11031010, 0x02021E04, 0x83053F20, 0x01250E10, 0x1F8350D1, 0x0E63EE1A, 0xE40E8303,
    0x0C3FD11B, 0xEFF1E493, 0xFBF1EE11,
};
#endif
#ifdef VERSION_US
struct {
    u8 precedingRecordFragment[3];
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record1;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record2;
    struct { u8 opcode; SnLe16 offset; } record3;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record4;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record5;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record6;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record7;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record8;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record9;
    struct { u8 opcode; SnLe16 offset; } record10;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record11;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record12;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record13;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record14;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record15;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record16;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record17;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record18;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record19;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record20;
    struct { u8 opcode; SnLe16 offset; } record21;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record22;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record23;
    struct { u8 opcode; SnLe16 offset; } record24;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record25;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record26;
    struct { u8 opcode; SnLe16 offset; } record27;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record28;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record29;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record30;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record31;
    struct { u8 opcode; SnLe16 offset; } record32;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record33;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record34;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record35;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record36;
    struct { u8 opcode; SnLe16 offset; } record37;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record38;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record39;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record40;
    struct { u8 opcode; SnLe16 offset; } record41;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record42;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record43;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record44;
    struct { u8 opcode; SnLe16 offset; } record45;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record46;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record47;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record48;
    struct { u8 opcode; SnLe16 offset; } record49;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record50;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record51;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record52;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record53;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record54;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record55;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record56;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record57;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record58;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record59;
    struct { u8 opcode; SnLe16 offset; } record60;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record61;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record62;
    struct { u8 opcode; SnLe16 offset; } record63;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record64;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record65;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record66;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record67;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record68;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record69;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record70;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record71;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record72;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record73;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record74;
    struct { u8 opcode; SnLe16 offset; } record75;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record76;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record77;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record78;
    struct { u8 opcode; SnLe16 offset; } record79;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record80;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record81;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record82;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record83;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record84;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record85;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; SnLe16 symbol; } expression; } record86;
    struct { u8 opcode; SnLe16 offset; u8 lineDelta; } record87;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record88;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record89;
    struct { u8 opcode; SnLe16 offset; } record90;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record91;
    struct { u8 opcode; u8 patchKind; SnLe16 offset; struct { u8 opcode; struct { u8 opcode; SnLe16 section; } left; struct { u8 opcode; SnLe32 constant; } right; } expression; } record92;
} g_VhandlerHandleresourcepagerequestEncodedWords __attribute__((aligned(4))) = {
    { 0x00, 0x00, 0x00 },
    { 10, 98, SN_LE16(5034), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 92, SN_LE16(5084), { 2, SN_LE16(381) } },
    { 50, SN_LE16(5096) },
    { 10, 96, SN_LE16(5142), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5146), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(5196), 13 },
    { 52, SN_LE16(5220), 0 },
    { 52, SN_LE16(5220), 3 },
    { 52, SN_LE16(5220), 0 },
    { 50, SN_LE16(5244) },
    { 52, SN_LE16(5244), 4 },
    { 10, 92, SN_LE16(5272), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59800) } } },
    { 10, 96, SN_LE16(5282), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(5286), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(5294), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 98, SN_LE16(5298), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 92, SN_LE16(5300), { 2, SN_LE16(376) } },
    { 52, SN_LE16(5320), 2 },
    { 52, SN_LE16(5328), 2 },
    { 10, 92, SN_LE16(5340), { 2, SN_LE16(440) } },
    { 50, SN_LE16(5352) },
    { 52, SN_LE16(5364), 2 },
    { 10, 92, SN_LE16(5376), { 2, SN_LE16(442) } },
    { 50, SN_LE16(5388) },
    { 52, SN_LE16(5400), 3 },
    { 10, 92, SN_LE16(5400), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(60016) } } },
    { 50, SN_LE16(5412) },
    { 10, 92, SN_LE16(5416), { 2, SN_LE16(441) } },
    { 52, SN_LE16(5428), 3 },
    { 10, 92, SN_LE16(5460), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59964) } } },
    { 52, SN_LE16(5468), 2 },
    { 50, SN_LE16(5476) },
    { 10, 92, SN_LE16(5476), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59976) } } },
    { 52, SN_LE16(5484), 2 },
    { 52, SN_LE16(5496), 5 },
    { 10, 92, SN_LE16(5504), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(59992) } } },
    { 50, SN_LE16(5512) },
    { 52, SN_LE16(5536), 0 },
    { 52, SN_LE16(5536), 3 },
    { 52, SN_LE16(5536), 0 },
    { 50, SN_LE16(5548) },
    { 52, SN_LE16(5548), 5 },
    { 52, SN_LE16(5556), 2 },
    { 10, 92, SN_LE16(5564), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(60052) } } },
    { 50, SN_LE16(5572) },
    { 52, SN_LE16(5592), 0 },
    { 52, SN_LE16(5592), 21 },
    { 52, SN_LE16(5592), 0 },
    { 50, SN_LE16(5612) },
    { 52, SN_LE16(5612), 4 },
    { 10, 92, SN_LE16(5640), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(60168) } } },
    { 10, 96, SN_LE16(5650), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(5654), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(5662), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 98, SN_LE16(5666), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 92, SN_LE16(5668), { 2, SN_LE16(376) } },
    { 52, SN_LE16(5688), 2 },
    { 10, 96, SN_LE16(5730), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5734), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(5748) },
    { 10, 96, SN_LE16(5750), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5754), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(5764) },
    { 52, SN_LE16(5772), 2 },
    { 10, 92, SN_LE16(5784), { 2, SN_LE16(421) } },
    { 52, SN_LE16(5792), 3 },
    { 10, 96, SN_LE16(5794), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5798), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 96, SN_LE16(5802), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5806), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 52, SN_LE16(5856), 3 },
    { 10, 92, SN_LE16(5868), { 2, SN_LE16(443) } },
    { 10, 96, SN_LE16(5878), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(5882), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(5888) },
    { 52, SN_LE16(5912), 0 },
    { 52, SN_LE16(5912), 3 },
    { 52, SN_LE16(5912), 0 },
    { 50, SN_LE16(5932) },
    { 52, SN_LE16(5932), 4 },
    { 10, 92, SN_LE16(5960), { 44, { 4, SN_LE16(2) }, { 0, SN_LE32(60488) } } },
    { 10, 96, SN_LE16(5970), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 98, SN_LE16(5974), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(0) } } },
    { 10, 96, SN_LE16(5982), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 98, SN_LE16(5986), { 44, { 4, SN_LE16(1) }, { 0, SN_LE32(940) } } },
    { 10, 92, SN_LE16(5988), { 2, SN_LE16(376) } },
    { 52, SN_LE16(6008), 2 },
    { 10, 96, SN_LE16(6010), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(6014), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 50, SN_LE16(6024) },
    { 10, 96, SN_LE16(6066), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } },
    { 10, 98, SN_LE16(6070), { 44, { 4, SN_LE16(3) }, { 0, SN_LE32(4) } } }
};
typedef char g_VhandlerHandleresourcepagerequestEncodedWordsSizeCheck[(sizeof(g_VhandlerHandleresourcepagerequestEncodedWords) == 716) ? 1 : -1];
#endif
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int g_VhandlerHandleresourcepagerequestEncodedWordsTriple[3] = {
    0x2EDF001D, 0x83F4FCA0, 0x0302D211,
};
#endif
#if defined(VERSION_US)
unsigned int g_VhandlerHandleresourcepagerequestEncodedWordsTriple[3] = {
    0x32C41734, 0xCC17020A, 0x5CD81702,
};
#endif
#endif

/* 800FFE2C.CPP */
#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned int g_VhandlerHandleresourcepagerequestEncodedWordsBlock1[93] = {
    0xF283FA02, 0x0304FF41, 0x0FBD8334, 0x1F160F0E, 0x1C232382, 0x2FEEFF01, 0xE02D2732, 0x725D1113,
    0x7AF9A760, 0x6482F204, 0x3EFFDF53, 0x2FB08150, 0x0422F1E0, 0x4CE0DE83, 0x10FCC205, 0x2F0AFFE0,
    0x8100F2F2, 0x1FFB1D2F, 0xE3832FED, 0xEFB2712F, 0xB61E83DF, 0xEC0252F4, 0xED20E272, 0x11FDF023,
    0x1B78B311, 0x8331CEC0, 0x273D12BF, 0x538332C1, 0x411054E1, 0x010F730F, 0x735113F0, 0x5B3F1F82,
    0x43EE4EEE, 0x2FF1FCEC, 0x83CD2101, 0xFFBF1B14, 0xCF83FFF1, 0x3DCBF105, 0x0DE072A2, 0x3CB9CD41,
    0x02F2F082, 0xEB01112F, 0x2DCF02BE, 0x82F1F441, 0x2ED222F0, 0x0082C323, 0x3E0110E0, 0xF0358251,
    0x10C31F31, 0xD1220272, 0x6D24DFDC, 0x903F31ED, 0x8312C144, 0x0FF0F210, 0x21820DFF, 0x1502E0DF,
    0xE25183C1, 0xF901300D, 0xD2300173, 0xC0BA25F2, 0x5C2ED912, 0x73DF5AB2, 0xFF3D37FA, 0xDD713E54,
    0xB23E1FD1, 0x152F824E, 0x0F011F33, 0xFFE01082, 0x21FF116F, 0xE32220FF, 0x733234FC, 0x423F0308,
    0x757203CD, 0xF0D0F511, 0x1AEE7373, 0x0112F40C, 0x6E11CD73, 0xF1E32E8A, 0x45EFE1E8, 0x73DCFC54,
    0xEFA9EE24, 0xD373F2DB, 0x1D12F36A, 0xD9B183D3, 0x411C1FF1, 0xF0004283, 0x0CCE5001, 0x1FE232F0,
    0x73DE4FA0, 0x3CD431ED, 0xAE731A23, 0xEB742ADE, 0x91BE8322,
};
#endif
