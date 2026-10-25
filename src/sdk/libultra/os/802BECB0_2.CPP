#include "TYPES.H"
#include "COMMON/LONE/D_800D83D0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "sdk/os.h"


/* Takes the access token from the message queue D_8014EA78, first creating that one-message queue
   over D_8014EA70 with osCreateMesgQueue and seeding it with a null message through func_802BB420_de
   when D_800D83D0 says it does not exist yet. Adapted from func_802B99A4_de with the queue, its buffer and its flag changed. */




static inline void create_access_queue(void) {
    extern Slot D_8014EA78;
    extern OSMesg D_8014EA70;
    D_800D83D0[0] = 1;
    osCreateMesgQueue(&D_8014EA78, &D_8014EA70, 1);
    func_802BB420_de(&D_8014EA78, 0, 0);
}

void func_802B9C14_de(void) {
    extern Slot D_8014EA78;
    OSMesg token;

    if (!D_800D83D0[0]) {
        create_access_queue();
    }
    func_802BB2A0_de(&D_8014EA78, &token, 1);
}
