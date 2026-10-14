#include "span_1000/code_8029BBA0.h"
#include "types.h"


extern const f64 D_800C5B10_de;
extern const f64 D_800C5B18_de;
extern const f64 D_800C5B20_de;

f64 func_8029D964_de(f64 arg0) {
    f64 temp;
    f64 integral;
    f64 limit;

    limit = D_800C5B10_de;
    if (limit <= arg0) {
        return arg0;
    }
    if (arg0 < D_800C5B18_de) {
        return -func_8029D9DC_de(-arg0);
    }
    temp = arg0;
    temp += limit;
    temp -= limit;
    if (arg0 < temp) {
        integral = temp - D_800C5B20_de;
    } else {
        integral = temp;
    }
    return integral;
}
