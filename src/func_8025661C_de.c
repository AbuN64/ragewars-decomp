#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80256220.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);







void *func_8025661C_de(void *arg0) {
    u32 temp_s2;
    void *temp_s0;

    temp_s2 = func_802BCF30_de();
    temp_s0 = ((CartridgeReadWorker *)arg0)->available.head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&((CartridgeReadWorker *)arg0)->available, (s32) temp_s0);
        ((CartridgeReadRequest *)temp_s0)->active = 1;
        func_80255CB8_de(&((CartridgeReadWorker *)arg0)->pending, (s32) temp_s0);
    }
    func_802BCF50_de(temp_s2);
    return temp_s0;
}

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);






void func_80256688_de(s32 arg0, void *arg1) {
    u32 temp_s2;

    temp_s2 = func_802BCF30_de();
    func_80255ED8_de(&((CartridgeReadWorker *)arg0)->pending, arg1);
    ((CartridgeReadRequest *)arg1)->active = 0;
    func_80255CB8_de(&((CartridgeReadWorker *)arg0)->available, (s32) arg1);
    func_802BCF50_de(temp_s2);
}
