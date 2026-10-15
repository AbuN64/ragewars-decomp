#include "span_1000/code_802B8DD0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

typedef void *OSMesg;

/* Takes the access token from the message queue D_8014EA58, first creating that one-message queue
   over D_8014EA50 with func_802BAC60_de and seeding it with a null message through func_802BB420_de
   when D_800D83C0 says it does not exist yet. */




static inline void create_access_queue(void) {
    extern s32 func_802BB420_de(Slot *, OSMesg, s32);
    extern void func_802BAC60_de(Slot *, OSMesg *, s32);
    extern Slot D_8014EA58;
    extern OSMesg D_8014EA50;
    extern s32 D_800D83C0[];
    D_800D83C0[0] = 1;
    func_802BAC60_de(&D_8014EA58, &D_8014EA50, 1);
    func_802BB420_de(&D_8014EA58, 0, 0);
}

void func_802B9950_de(void) {
    extern void func_802BB420_de(s32 *arg0, s32 arg1, s32 arg2);
    extern void func_802BAC60_de(s32 *arg0, s32 *arg1, s32 arg2);
    extern s32 D_8014EA58;
    extern s32 D_8014EA50;
    extern s32 D_800D83C0;
    D_800D83C0 = 1;
    func_802BAC60_de(&D_8014EA58, &D_8014EA50, 1);
    func_802BB420_de(&D_8014EA58, 0, 0);
}

void func_802B99A4_de(void) {
    extern Slot D_8014EA58;
    extern s32 D_800D83C0[];
    OSMesg token;

    if (!D_800D83C0[0]) {
        create_access_queue();
    }
    func_802BB2A0_de(&D_8014EA58, &token, 1);
}
