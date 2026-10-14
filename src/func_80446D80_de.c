#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041C67C.h"
#include "types.h"
/* __osPfsGetStatus, drafted from ultralib src/io/pfsgetstatus.c (2.0I branch): send a status request
   to one controller through the pak PIF RAM block and turn its reply into a pack-present, new-pack
   or failure code. */



extern char D_80154110;
extern void func_80446E58_de(int channel);
extern void func_80446EE4_de(int channel, EntryRecAt3 *data);
extern s32 func_802B9CB0_de(s32 direction, void *data);

s32 func_80446D80_de(void *queue, int channel)
{
    s32 ret = 0;
    void *dummy;
    EntryRecAt3 data;

    func_80446E58_de(channel);

    ret = func_802B9CB0_de(1, &D_80154110);
    func_802BB2A0_de(queue, &dummy, 1);

    ret = func_802B9CB0_de(0, &D_80154110);
    func_802BB2A0_de(queue, &dummy, 1);

    func_80446EE4_de(channel, &data);

    if (((data.team & 1) != 0) && ((data.team & 2) != 0)) {
        return 2;
    } else if ((data.slot != 0) || ((data.team & 1) == 0)) {
        return 1;
    } else if ((data.team & 4) != 0) {
        return 4;
    }

    return ret;
}
