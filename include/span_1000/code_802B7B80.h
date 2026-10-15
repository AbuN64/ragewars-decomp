#ifndef UNBAKE_SPAN_1000_CODE_802B7B80_H
#define UNBAKE_SPAN_1000_CODE_802B7B80_H
#include "types.h"
struct Block40;
struct Block40 {
    u8 bytes[0x28];
};

struct OSMesgQueue;
typedef struct OSMesgQueue OSMesgQueue;
struct OSMesgQueue {
    void **mtqueue;
    void **fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
};
struct OSPfs;
struct OSPfs {
    int status;
    struct OSMesgQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct __OSContRamReadFormat;
struct __OSContRamReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
};

struct Block40;
typedef struct Block40 Block40;

extern unsigned int func_802B80B4_eu(void *arg0);



struct __OSContRamReadFormat;
typedef struct __OSContRamReadFormat __OSContRamReadFormat;

struct OSPfs;
typedef struct OSPfs OSPfs;


struct Triple;
extern u32 func_802B7B80_us(struct Triple *);
extern u32 func_802B7C50_de(struct Triple *);
extern u32 func_802B7F30_eu_x(struct Triple *);
#endif
