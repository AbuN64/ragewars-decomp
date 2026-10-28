#include "TYPES.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "sdk/libultra/os/802BECB0_3.h"

void __osSiRelAccess(void) {
    osSendMesg(&D_8014EA78, 0, 0);
}
