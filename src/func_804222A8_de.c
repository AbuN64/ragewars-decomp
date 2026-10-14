#include "span_16E000/code_804221A0.h"
#include "types.h"

/* Event callback for screen D_800E44A0: on event 1 while func_8043C308_de reports the screen in state
   1 it advances the screen through func_8043C080_de and func_8043C2A4_de, and when that leaves it in
   state 2 it tears the match display down through func_80422020_de and func_8042DEA0_de and calls
   func_80264854_de(1). Returns zero. */
extern void *D_800E44A0;
extern s32 func_8043C308_de(void *);
extern void func_8043C080_de(void *);
extern void func_8043C2A4_de(void *);
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_80422020_de(void);
#else
extern void func_8042201C_de(void);
#endif
extern void func_80422020_de(void);
extern void func_8042DEA0_de(void);


s32 func_804222A8_de(s32 arg0, s32 arg1, s32 event) {
    if (event == 1) {
        if (func_8043C308_de(D_800E44A0) != 1) {
            return 0;
        }
        func_8043C080_de(D_800E44A0);
        func_8043C2A4_de(D_800E44A0);
        if (func_8043C308_de(D_800E44A0) != 2) {
            return 0;
        }
#if defined(VERSION_DE)
        func_80422020_de();
#else
        
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_80422020_de
#else
func_8042201C_de
#endif
();
#endif
        func_8042DEA0_de();
        func_80264854_de(1);
    }
    return 0;
}
