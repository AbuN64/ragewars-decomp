#include "span_16E000/code_804264F0.h"
#include "types.h"



/* Opens the five option windows of screen D_800E4690: for each of options 0 to 4 it picks window
   0x149, 0x14C, 0x14D, 0x14E or 0x14F through jtbl_800DD9F0, opens it under the screen's parent at
   0x970, opens its 0x14B child and shows that through func_8040E8D8_de. The loop walks the table with
   its own pointer, as the cartridge's strength-reduced dispatch does. */
extern ResultsOptionsScreen *D_800E4690;
extern void *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(void *, s32);

#if defined(VERSION_DE)
enum { RESULTS_OPTION_329 = 327, RESULTS_OPTION_331 = 329, RESULTS_OPTION_332 = 330, RESULTS_OPTION_333 = 331, RESULTS_OPTION_334 = 332, RESULTS_OPTION_335 = 333 };
#elif defined(VERSION_EU_X)
enum { RESULTS_OPTION_329 = 333, RESULTS_OPTION_331 = 335, RESULTS_OPTION_332 = 336, RESULTS_OPTION_333 = 337, RESULTS_OPTION_334 = 338, RESULTS_OPTION_335 = 339 };
#else
enum { RESULTS_OPTION_329 = 329, RESULTS_OPTION_331 = 331, RESULTS_OPTION_332 = 332, RESULTS_OPTION_333 = 333, RESULTS_OPTION_334 = 334, RESULTS_OPTION_335 = 335 };
#endif

void func_80428700_de(void) {
    s32 id = 0;
    s32 option;

    for (option = 0; option < 5; option++) {
        switch (option) {
        case 0:
            id = RESULTS_OPTION_329;
            break;
        case 1:
            id = RESULTS_OPTION_332;
            break;
        case 2:
            id = RESULTS_OPTION_333;
            break;
        case 3:
            id = RESULTS_OPTION_334;
            break;
        case 4:
            id = RESULTS_OPTION_335;
            break;
        }
        func_8040E8D8_de(func_8040EC30_de(func_8040EC30_de(D_800E4690->parent, id), RESULTS_OPTION_331), 1);
    }
}
