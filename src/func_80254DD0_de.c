#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"
#include "span_1000/code_802508E0.h"


extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);
extern char D_8010110C;
extern s32 D_801010F8;








void func_80254DD0_de(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_s0;

    temp_v0 = ((Node_func_80251328_de *)arg1)->owner;
    if (temp_v0 != 0) {
        func_80255488_de(((Request_func_80251F6C_de *)temp_v0)->key);
        temp_s0 = ((Node_func_80251328_de *)arg1)->owner;
        func_80255ED8_de(&D_8010110C, temp_s0);
        ((Request_func_80251F6C_de *)temp_s0)->flags = 0;
        func_80255CB8_de(&D_801010F8, (s32) temp_s0);
    }
}
