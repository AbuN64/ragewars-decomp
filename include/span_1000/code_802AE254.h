#ifndef UNBAKE_SPAN_1000_CODE_802AE254_H
#define UNBAKE_SPAN_1000_CODE_802AE254_H
#include "TYPES.H"


struct Response;
struct Response {
    u8 handshake;
    u8 pad11[3];
    u32 output;
    u8 byte;
};

struct TransferScratch;
typedef struct TransferScratch TransferScratch;

extern s32 func_802B1790_us_rev1(u32 arg0);

struct WriteWord;
typedef struct WriteWord WriteWord;


extern s32 func_802B15EC_us_rev1(s32 *arg0);

struct ReadWordRecAt4;
typedef struct ReadWordRecAt4 ReadWordRecAt4;


struct TransferScratch;
struct TransferScratch {
    u8 response;
    u8 status;
    u16 pad;
    s32 output;
};

struct WriteWord;
struct WriteWord {
    u32 word;
    u8 byte;
    u8 value;
};

struct ReadWordRecAt4;
struct ReadWordRecAt4 {
    u32 word;
    u8 byte;
};

struct CommandState;
struct CommandState {
    u8 command;
    u8 pad01[3];
    ReadWordRecAt4 address;
    ReadWordRecAt4 callback;
    WriteWord output;
};

struct CommandState;
typedef struct CommandState CommandState;

struct ReadHalfword;
typedef struct ReadHalfword ReadHalfword;

struct ReadHalfword;
struct ReadHalfword {
    s32 word;
    u8 byte;
    u16 value;
    u8 next_byte;
};

extern int func_802AD264_de(void);



extern unsigned char D_B2000001;

extern void func_802B1554_us_rev1(void);

extern int D_800D3648;


extern int D_800D3640;

extern s32 func_802B1734_us_rev1(u32 arg0);

extern s32 func_802B16B4_us_rev1(u8 *arg0, s32 arg1);

extern s32 func_802B156C_us_rev1(u16 *arg0);

struct Response;
typedef struct Response Response;

extern void func_802B155C_us_rev1(int arg0);

extern int D_800D3644;


#endif
