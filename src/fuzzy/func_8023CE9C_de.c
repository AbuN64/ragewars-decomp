#include "types.h"

typedef struct Link {
    struct Link *next;
    struct Link *prev;
} Link;

typedef struct {
    u8 pad0[0x12];
    s16 state;
} Thread;

typedef struct {
    u8 pad0[0xC];
    s16 id;
    u8 pad0E[2];
    Link *link;
    Thread *thread;
    u8 *flag;
} Request;

extern Link *D_800FFE20;
extern Link *D_800FFE24;
extern char D_800FFCD0[];
extern void func_8023BD34_de(s32, Link *, u8, u8 *);
extern void func_802BCF70_de(u32, s32);
extern void func_802BD010_de(u32, s32);
extern void func_802BB750_de(Thread *);
extern s32 func_802BB420_de(void *, void *, s32);

void func_8023CE9C_de(Request *req) {
    Link *link;

    if (*req->flag == 0xFF) {
        link = req->link;
        link->next = 0;
        link->prev = D_800FFE24;
        if (D_800FFE24 != 0) {
            D_800FFE24->next = link;
        }
        D_800FFE24 = link;
        if (D_800FFE20 == 0) {
            D_800FFE20 = link;
        }
        func_8023BD34_de(req->id, req->link, *((u8 *)req->thread + 0x17), req->flag);
        func_802BCF70_de((u16)req->id << 12, 0x1000);
        func_802BD010_de((u16)req->id << 12, 0x1000);
    } else {
        link = req->link;
        link->prev = 0;
        link->next = D_800FFE20;
        if (D_800FFE20 != 0) {
            D_800FFE20->prev = link;
        }
        D_800FFE20 = link;
        if (D_800FFE24 == 0) {
            D_800FFE24 = link;
        }
    }
    req->thread->state = 2;
    func_802BB750_de(req->thread);
    func_802BB420_de(D_800FFCD0, req, 1);
}
