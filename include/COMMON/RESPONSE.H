#ifndef COMMON_RESPONSE_H
#define COMMON_RESPONSE_H
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


struct WriteWord;
typedef struct WriteWord WriteWord;



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




extern unsigned char D_B2000001;


extern int D_800D3648;


extern int D_800D3640;




struct Response;
typedef struct Response Response;


extern int D_800D3644;
#endif
