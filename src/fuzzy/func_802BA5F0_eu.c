#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BB67C.h"
#include "types.h"
void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2);
s32 func_802BADA0_de(void *arg0);
void func_802BB5F0_de(void *arg0, s32 arg1);
void func_802BAC90_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_802BB750_de(void *arg0);
extern struct OSThread D_80148850;
extern struct OSMesgQueue D_80149A80;
extern s32 D_80149AA0;

void func_802BA5F0_eu(s32 arg0) {
    s32 temp_v0;
    s32 var_s3;
    u32 temp_v0_2;

    if (D_800D4420.active == 0) {
        var_s3 = -1;
        func_802BB9F8_de();
        func_802BAC60_de(&D_80149A80, &D_80149AA0, 5);
        D_80149AC0.hdr.type = 0xD;
        D_80149AC0.hdr.pri = 0;
        D_80149AC0.hdr.retQueue = 0;
        D_80149AE0.hdr.type = 0xE;
        D_80149AE0.hdr.pri = 0;
        D_80149AE0.hdr.retQueue = 0;
        func_802BB550_de(7, &D_80149A80, &D_80149AC0);
        func_802BB550_de(3, &D_80149A80, &D_80149AE0);
        temp_v0 = func_802BADA0_de(0);
        if (temp_v0 < arg0) {
            var_s3 = temp_v0;
            func_802BB5F0_de(0, arg0);
        }
        temp_v0_2 = func_802BCF30_de();
        D_800D4420.active = 1;
        D_800D4420.cmdQueue = &D_80149A80;
        D_800D4420.evtQueue = &D_80149A80;
        D_800D4420.thread = &D_80148850;
        D_800D4420.acsQueue = 0;
        D_800D4420.dma = 0;
        D_800D4420.edma = 0;
        func_802BAC90_de(&D_80148850, 0, D_002BA4C0, &D_800D4420, &D_80149A80, arg0);
        func_802BA210_de();
        func_802BB750_de(&D_80148850);
        func_802BCF50_de(temp_v0_2);
        if (var_s3 != -1) {
            func_802BB5F0_de(0, var_s3);
        }
    }
}
/* Warning: struct OSThread is not defined (only forward-declared) */
/* Warning: struct OSMesgQueue is not defined (only forward-declared) */
