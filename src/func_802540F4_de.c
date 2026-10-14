#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"



extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_80254990_de(void *, void *);
extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);

extern char D_800C3EA0_de;
extern OSMesgQueue D_80101140;


void **func_802540F4_de(s32 arg0, void **arg1, s32 arg2, void *arg3, s32 arg4) {
    void **resource;
    s32 size;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;

    resource = func_8025193C_de(0, arg2, arg2, 4, 0, 0, 0, &D_800C3EA0_de, arg4);
    if (resource != 0) {
        size = **(s32 **)resource;
        token = func_802BCF30_de();
        counter = D_8010515C + 1;
        D_8010515C = counter;
        if (counter != 1) {
            func_802BCF50_de(token);
            func_802BB2A0_de(&D_80101140, 0, 1);
        } else {
            func_802BCF50_de(token);
        }
        func_80254990_de(0, resource);
        token2 = func_802BCF30_de();
        counter2 = D_8010515C - 1;
        D_8010515C = counter2;
        if (counter2 != 0) {
            func_802BCF50_de(token2);
            func_802BB420_de(&D_80101140, 0, 1);
        } else {
            func_802BCF50_de(token2);
        }
        resource = func_8025193C_de(0, arg2, arg2, ((size * 4) + 0xF) & ~7,
                                 0, 0, 0, arg3, arg4);
        if (resource != 0) {
            *arg1 = *resource;
            return resource;
        }
    }
    return 0;
}
