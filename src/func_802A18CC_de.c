#include "span_1000/code_802A1264.h"
#include "types.h"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern f64 func_804147F0_eu_x(void);
#else
extern f64 func_804143B0_de(void);
#endif

f64 func_802A18CC_de(void) {
    return 
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_804147F0_eu_x
#else
func_804143B0_de
#endif
() - (0.0);
}
