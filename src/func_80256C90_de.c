#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "common/data.h"
#include "common/unused.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802B7058.h"
extern u32 D_800CB700_de;
extern u32 D_800CB710;

void func_80256C90_de(void) {
    u32 stop, argument, frame;
    u64 previous;
    u32 messages[2];
    union { void *message; u32 words[2]; } event;
    CacheCountdownEntry *entry;
    void *entryObject;
    stop = 0;
    argument = stop;
    frame = stop;
    previous = 0;
    func_8028F864_de(&D_80142928, messages, (s32)D_80107E00);
    do {
        D_800CB710 = ((func_802BADC0_de() - previous) << 6) / 3000ULL;
        func_802BB2A0_de((void *)D_80107E00, &event.message, 1);
        previous = func_802BADC0_de();
        switch (event.words[0]) {
        case 1:
            frame++;
            if (frame < 21) break;
            frame = 0;
        case 7:
            D_800CB70C_de++;
            while (!(func_802B72C0_de() & 0x80000000)) {
                func_80256EA8_de(D_80107E28[D_800CB700_de % 3], argument);
            }
            entryObject = D_80107DFC;
            for (entry = entryObject; entry; entry = entry->next) {
                if (entry->state) entry->state--;
            }
            break;
        case 4:
            break;
        }
    } while (stop == 0);
    func_802B24D0_de(D_80107E34);
}
