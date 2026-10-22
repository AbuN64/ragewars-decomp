#include "include_asm.h"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_2.H"

/* Advances an animation player one frame: returns 1 when there is no player or clip, or after wrapping
   past frame 7 back to 0; otherwise prepares and shows the current frame through func_802106E0_de and
   func_80210964_de, advances the frame at 0x1CC and returns 0. */


extern void func_802106E0_de(void *, int);
extern void func_80210964_de(void *, int);

int func_80210E88_de(PlayerRecAt1CC *p) {
    if (p == 0) {
        return 1;
    }
    if (p->clip == 0) {
        return 1;
    }
    if (p->frame < 8) {
        func_802106E0_de(p->clip, p->frame);
        func_80210964_de(p->clip, p->frame);
        p->frame++;
        return 0;
    }
    p->frame = 0;
    return 1;
}

s32 func_80210EFC_de(f32 arg0) {
    f32 var_f0;

    arg0 += D_800C1FD8_de;
    if (D_800C1FDC_de <= arg0) {
        do {
            arg0 -= D_800C1FDC_de;
        } while (D_800C1FDC_de <= arg0);
    }
    var_f0 = 0.0f;
    if (arg0 < var_f0) {
        do {
            arg0 += D_800C1FE0_de;
        } while (arg0 < var_f0);
    }
    if (D_800C1FE4_de < arg0) {
        arg0 = D_800C1FE4_de;
    }
    if (arg0 < D_800C1FE8_de) {
        arg0 = D_800C1FE8_de;
    }
    arg0 *= D_800C1FEC_de;
    arg0 *= D_800C1FF0_de;
    var_f0 = 0.0f;
    if (arg0 < var_f0) {
        arg0 = var_f0;
    }
    if (D_800C1FF0_de <= arg0) {
        arg0 = *(&D_800C1FF0_de + 1);
    }
    return (s32)arg0;
}

int func_80210FE8_de(int arg0) {
    int result = arg0 + 1;
    if (result == 8) {
        result = 0;
    }
    return result;
}

int func_80211000_de(int arg0) {
    int result = arg0 - 1;
    if (arg0 == 0) {
        result = 7;
    }
    return result;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_80211014);
#endif
