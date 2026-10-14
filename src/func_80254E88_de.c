#include "span_1000/code_802508E0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);
extern char D_8010110C;




void func_80254E88_de(s32 arg0, void *arg1) {
    func_80255ED8_de(&D_8010110C, arg1);
    ((Request_func_802524B0_de *)arg1)->flags = 0;
    func_80255CB8_de((char *)&D_8010110C - 0x14, (s32) arg1);
}
