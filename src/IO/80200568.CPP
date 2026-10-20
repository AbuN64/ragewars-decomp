#include "IO/EXTERNS.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OBJ.H"
#include "TYPES.H"
#include "IO/80200568.H"

/* func_802023C4_de: types.declaration: solved callee prototype */
extern int func_802023C4_de(void);

/* func_802023D0_de: types.declaration: solved callee prototype */

                                                  /* size = 0x18 */

s32 func_80200500_de(void) {
    s32 temp_v0;

    temp_v0 = func_802023C4_de();
    func_802023D0_de(temp_v0 & ~1);
    return temp_v0 & 1;
}

                                                  /* size = 0x18 */

void func_80200538_de(s32 arg0) {
    func_802023D0_de(func_802023C4_de() | arg0);
}

void func_80200568_de(s32 address, s32 value) {
    if (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK) {
        do {
        } while (IO_READ_WORD(PI_STATUS_REG) & PI_STATUS_BUSY_MASK);
    }
    *(s32 *)address = value;
}
