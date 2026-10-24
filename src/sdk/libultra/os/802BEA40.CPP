#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "TYPES.H"
#include "sdk/OSINT/802BEA40.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"


/* Takes the access token from the message queue D_8014EA58, first creating that one-message queue
   over D_8014EA50 with osCreateMesgQueue and seeding it with a null message through func_802BB420_de
   when D_800D83C0 says it does not exist yet. */




static inline void create_access_queue(void) {
    D_800D83C0[0] = 1;
    osCreateMesgQueue(&D_8014EA58, &D_8014EA50, 1);
    func_802BB420_de(&D_8014EA58, 0, 0);
}

void func_802B9950_de(void) {
    D_800D83C0[0] = 1;
    osCreateMesgQueue(&D_8014EA58, &D_8014EA50, 1);
    func_802BB420_de(&D_8014EA58, 0, 0);
}

void func_802B99A4_de(void) {
    OSMesg token;

    if (!D_800D83C0[0]) {
        create_access_queue();
    }
    func_802BB2A0_de(&D_8014EA58, &token, 1);
}
