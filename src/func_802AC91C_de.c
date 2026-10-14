#include "shared/gameplay_transition.h"
#include "shared/world.h"
#include "span_1000/code_80233920.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"

extern char D_800D31D0;




void *func_802AC91C_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D31D0;
    i = 3;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern char D_800D3230;




void *func_802AC950_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3230;
    i = 5;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x14;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern char D_800D32A8;




void *func_802AC984_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D32A8;
    i = 7;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern char D_800D3368;




void *func_802AC9B8_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3368;
    i = 1;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x14;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern char D_800D33C0;




void *func_802AC9EC_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D33C0;
    i = 0xF;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x10;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern char D_800D3390;




void *func_802ACA20_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3390;
    i = 2;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x10;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern int func_8024E924_de(void *arg0);
extern s32 func_802AB6EC_de(void *arg0, void *arg1, s32 arg2);
extern void func_80290548_de(void *arg0);
extern void func_8028B898_de(void *arg0, void *arg1, s32 arg2);
extern void func_80278E04_de(s32 arg0, s32 arg1, void *arg2);





void func_802ACA54_de(void *arg0, void *arg1) {
    u16 temp_v0;
    u16 temp_v1;

    temp_v1 = ((struct Shared_ProjectileView *)(arg1))->flags;
    if (temp_v1 & 8) {
        if (((struct Shared_ProjectileView *)(arg1))->stateFlags & 1) {
            goto block_4;
        }
    } else if (!(temp_v1 & 1)) {
block_4:
        if (func_802AB6EC_de(arg0, arg1, func_8024E924_de(arg1)) != 0) {
            temp_v0 = ((struct Shared_ProjectileView *)(arg1))->flags | 1;
            ((struct Shared_ProjectileView *)(arg1))->flags = temp_v0;
            if (temp_v0 & 8) {
                func_80290548_de(arg1);
                return;
            }
            func_8028B898_de(&D_8011FE88, arg1, 1);
            func_80278E04_de(((struct Shared_ProjectileView *)(arg1))->source, 0x400, arg0);
        }
    }
}

extern char D_80145088;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
extern void func_80222BE8_de(void *, s16, s16);
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);


/** Apply an effect descriptor's optional setup, resource, sound, and callback. */
s32 func_802ACB18_de(void *arg0, void *arg1) {
    void *resource;
    s32 sound;
    s32 callback;
    if (((struct EntryRecAtE *)(arg1))->index != -1) {
        func_80222BE8_de(arg0, ((struct EntryRecAtE *)(arg1))->index,
                      ((struct EntryRecAtE *)(arg1))->argument);
    }

    resource = ((EntryRecAtE *)arg1)->resource;
    sound = ((struct EntryRecAtE *)(arg1))->sound;
    callback = ((struct EntryRecAtE *)(arg1))->callback;
    if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
        func_802391AC_de(((struct Actor_func_802AB400_de *)(arg0))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            func_80237E80_de(&D_80145088,
                          ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80152789]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        func_8025DE54_de(sound,
                      ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}

extern char D_80145088;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
extern s32 func_8022AC00_de(void *arg0);
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);


/** Advance a timed effect and apply its optional resource, sound, and callback. */
s32 func_802ACC04_de(void *arg0, void *arg1) {
    s32 result;
    void *resource;
    s32 sound;
    s32 callback;

    result = 0;
    if (((struct Actor_func_802AB400_de *)(arg0))->count > 0) {
        s32 limit;

        ((struct Actor_func_802AB400_de *)(arg0))->count +=
            ((struct TimedItemEffect *)(arg1))->amount << 8;
        limit = func_8022AC00_de(arg0);
        if (((struct Actor_func_802AB400_de *)(arg0))->count < limit) {
            limit = ((struct Actor_func_802AB400_de *)(arg0))->count;
        }
        result = 1;
        ((struct Actor_func_802AB400_de *)(arg0))->count = limit;
        ((struct Actor_func_802AB400_de *)(arg0))->active = limit;
    }

    if (result != 0) {
        resource = ((EntryRecAtE *)arg1)->resource;
        sound = ((struct TimedItemEffect *)(arg1))->sound;
        callback = ((struct TimedItemEffect *)(arg1))->callback;
        if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
            func_802391AC_de(((struct Actor_func_802AB400_de *)(arg0))->owner,
                          0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (resource != 0) {
                func_80237E80_de(&D_80145088,
                              ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80152789]);
#else
                          *(void **)resource);
#endif
            }
        }
        if (sound != 0) {
            func_8025DE54_de(sound,
                          ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
        }
        if (callback != 0) {
            func_8025E11C_de(callback);
        }
    }
    return result;
}

extern char D_80145088;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);




/** Apply an accumulating effect descriptor and its optional payloads. */
s32 func_802ACD28_de(void *arg0, void *arg1) {
    void *resource;
    s32 sound;
    s32 callback;
    s32 amount;

    amount = ((struct Actor_func_802AB400_de *)(arg0))->fraction +
             (u16)((struct EntryRecAtE *)(arg1))->index;
    ((struct Actor_func_802AB400_de *)(arg0))->fraction = amount;
    if ((s16)amount >= 100) {
        ((struct Actor_func_802AB400_de *)(arg0))->fraction = amount - 100;
        if (((struct Actor_func_802AB400_de *)(arg0))->lives < 9) {
            ((struct Actor_func_802AB400_de *)(arg0))->lives =
                (u16)((struct Actor_func_802AB400_de *)(arg0))->lives + 1;
        }
    }

    resource = ((EntryRecAtE *)arg1)->resource;
    sound = ((struct EntryRecAtE *)(arg1))->sound;
    callback = ((struct EntryRecAtE *)(arg1))->callback;
    if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
        func_802391AC_de(((struct Actor_func_802AB400_de *)(arg0))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            func_80237E80_de(&D_80145088,
                          ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80152789]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        func_8025DE54_de(sound,
                      ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}
