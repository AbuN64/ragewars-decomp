#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/OSINT/802BEA40.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
#include "include_asm.h"
#include "sdk/OSINT/802BEA40_2.H"

/* 802BEA40.CPP */
/* Takes the access token from the message queue D_8014EA58, first creating that one-message queue
   over D_8014EA50 with osCreateMesgQueue and seeding it with a null message through func_802BB420_de
   when D_800D83C0 says it does not exist yet. */

static inline void create_access_queue(void) {
    D_800D83C0[0] = 1;
    osCreateMesgQueue(&D_8014EA58, &D_8014EA50, 1);
    osSendMesg(&D_8014EA58, 0, 0);
}

void __osPiCreateAccessQueue(void) {
    D_800D83C0[0] = 1;
    osCreateMesgQueue(&D_8014EA58, &D_8014EA50, 1);
    osSendMesg(&D_8014EA58, 0, 0);
}

void __osPiGetAccess(void) {
    OSMesg token;

    if (!D_800D83C0[0]) {
        create_access_queue();
    }
    osRecvMesg(&D_8014EA58, &token, 1);
}

/* 802BEA40_2.CPP */
void func_802B9A10_de(void) {
    osSendMesg(&D_8014EA58, 0, 0);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B9968[2] = {
    0x70000000, 0x66000000,
};
#endif
