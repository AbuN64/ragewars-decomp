#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804290E8.h"
#include "types.h"
/* Handles the menu message func_80299A08_de reports after func_8029973C_de unless func_8043C308_de reports
   screen D_800E4EF0 busy: 0x36B closes the menu through func_804294C4_de, sends code -1 to
   func_8042E988_de and calls func_802998A8_de; 0x369 does the same with page reset func_80429654_de(0)
   and code 0x17 when func_802A1B18_de reports the screen's list at 0x34 non-empty; 0x36A always does
   it with func_8041E5F8_de and code 0x19, then calls func_802A2394_de. Returns zero. */
extern struct func_8020F2A8_S3 *D_800E4EF0;
extern void func_8029973C_de(void);
extern s32 func_8043C308_de(struct func_8020F2A8_S3 *);
extern s32 func_80299A08_de(void);
extern void func_80429654_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de(void);
extern s32 func_802A1B18_de(s32);
extern void func_8041E5F8_de(void);
extern void func_802A2394_de(void);
s32 func_804297F8_de(void) {
    func_8029973C_de();
    if (func_8043C308_de(D_800E4EF0) == 1) {
        return 0;
    }
    switch (func_80299A08_de()) {
#if defined(VERSION_DE)
    case 0x367:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x36B:
#elif defined(VERSION_EU_X)
    case 0x36F:
#endif
        func_804294C4_de();
        func_8042E988_de(-1);
        func_802998A8_de();
        break;
#if defined(VERSION_DE)
    case 0x365:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x369:
#elif defined(VERSION_EU_X)
    case 0x36D:
#endif
        if (func_802A1B18_de(D_800E4EF0->unk34) > 0) {
            func_804294C4_de();
            func_80429654_de(0);
            func_8042E988_de(0x17);
            func_802998A8_de();
        }
        break;
#if defined(VERSION_DE)
    case 0x366:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x36A:
#elif defined(VERSION_EU_X)
    case 0x36E:
#endif
        func_804294C4_de();
        func_80429654_de(0);
        func_8041E5F8_de();
        func_8042E988_de(0x19);
        func_802998A8_de();
        func_802A2394_de();
        break;
    }
    return 0;
}
