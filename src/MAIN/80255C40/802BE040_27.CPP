#include "span_1000/code_802B8DD0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802BB15C.h"
#include "TYPES.H"
#include "MAIN/802B8DD0.H"

typedef void *OSMesg;

/* Takes the access token from the message queue D_8014EA78, first creating that one-message queue
   over D_8014EA70 with osCreateMesgQueue and seeding it with a null message through func_802BB420_de
   when D_800D83D0 says it does not exist yet. Adapted from func_802B99A4_de with the queue, its buffer and its flag changed. */




static inline void create_access_queue(void) {
    extern s32 func_802BB420_de(Slot *, OSMesg, s32);
    extern void osCreateMesgQueue(Slot *, OSMesg *, s32);
    extern Slot D_8014EA78;
    extern OSMesg D_8014EA70;
    extern s32 D_800D83D0[];
    D_800D83D0[0] = 1;
    osCreateMesgQueue(&D_8014EA78, &D_8014EA70, 1);
    func_802BB420_de(&D_8014EA78, 0, 0);
}

void func_802B9BC0_de(void) {
    extern void func_802BB420_de(s32 *arg0, s32 arg1, s32 arg2);
    extern void osCreateMesgQueue(s32 *arg0, s32 *arg1, s32 arg2);
    extern s32 D_8014EA78;
    extern s32 D_8014EA70;
    extern s32 D_800D83D0;
    D_800D83D0 = 1;
    osCreateMesgQueue(&D_8014EA78, &D_8014EA70, 1);
    func_802BB420_de(&D_8014EA78, 0, 0);
}

void func_802B9C14_de(void) {
    extern Slot D_8014EA78;
    extern s32 D_800D83D0[];
    OSMesg token;

    if (!D_800D83D0[0]) {
        create_access_queue();
    }
    func_802BB2A0_de(&D_8014EA78, &token, 1);
}
