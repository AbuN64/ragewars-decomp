#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4514B4,
   and returns one. */
extern char D_00450884[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80444EBC_de(void *first, void *second, void *third) {
    func_804427C4_de(third, second, D_00450884);
    return 1;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451AF0,
   and returns one. */
extern char D_00450E9C[];
extern char D_00451B34[];
extern char D_00451C64[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80444EE8_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    func_804427C4_de(third, second, D_00451B34);
#elif defined(VERSION_EU_X)
    func_804427C4_de(third, second, D_00451C64);
#else
    func_804427C4_de(third, second, D_00450E9C);
#endif
    return 1;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4500F4,
   and returns one. */
extern char D_0044F4A4[];
extern char D_00450E9C[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80444F14_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    func_804427C4_de(third, second, D_00450E9C);
#elif defined(VERSION_EU_X)
    func_804427C4_de(third, second, D_00450E9C);
#else
    func_804427C4_de(third, second, D_0044F4A4);
#endif
    return 1;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_4503E8,
   and returns one. */
extern char D_0044F798[];
extern char D_0044F4A4[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80444F40_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    func_804427C4_de(third, second, D_0044F4A4);
#elif defined(VERSION_EU_X)
    func_804427C4_de(third, second, D_0044F4A4);
#else
    func_804427C4_de(third, second, D_0044F798);
#endif
    return 1;
}

/* Calls func_804427C4_de with the third argument, the second argument and the resource D_451BD4,
   and returns one. */
extern char D_00450F74[];
extern char D_0044F798[];
extern void func_804427C4_de(void *, void *, void *);

s32 func_80444F6C_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    func_804427C4_de(third, second, D_0044F798);
#elif defined(VERSION_EU_X)
    func_804427C4_de(third, second, D_0044F798);
#else
    func_804427C4_de(third, second, D_00450F74);
#endif
    return 1;
}
