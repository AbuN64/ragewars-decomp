#include "span_16E000/code_80444030.h"
#include "types.h"
#include "stddef.h"
/* Updates the selected menu option in response to the current input state. */
s32 func_8026437C_de(char *); /* extern */
 /* extern */
 /* extern */
extern char D_8010B0E0;
extern u32 D_801462D0[];
s32 func_8044421C_de(void) {
 if(((s32 (*)(char *))func_80264388_de)(&D_8010B0E0)) {
 switch(D_801462D0[0]) {
 case 8: D_801462D0[0]=32; break;
 case 16: D_801462D0[0]=8; break;
 case 32: D_801462D0[0]=16; break;
 }
 }
 if(((s32 (*)(char *))func_802643A0_de)(&D_8010B0E0) || func_8026437C_de(&D_8010B0E0)) {
 switch(D_801462D0[0]) {
 case 8: D_801462D0[0]=16; break;
 case 16: D_801462D0[0]=32; break;
 case 32: D_801462D0[0]=8; break;
 }
 }
 return 0;
}
