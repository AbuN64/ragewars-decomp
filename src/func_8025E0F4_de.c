#include "span_1000/code_8025D948.h"
#include "types.h"

extern s32 func_80258D50_de(char *obj, s32 owner);
extern s32 D_8010C080;

/* Return the existing owner-count result to callers that test it. */
s32 func_8025E0F4_de(s32 owner)
{
    return func_80258D50_de((char *)&D_8010C080, owner);
}
