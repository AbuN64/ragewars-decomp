#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80265370.h"
#include "types.h"

extern u32 D_80000318;

u32 func_80265350_de(void) {
    if (D_80000318 > 0x7FFFFFU) {
        return 0x700000;
    }
    return D_80000318;
}

void func_80265378_de(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *var_a3;
    u8 *var_a3_2;
    s32 temp_v0;

    if (arg2 != 0) {
        var_a3 = arg0;
        if (((u32)arg1 | (u32)arg0 | arg2) & 3) {
            var_a3_2 = arg1;
            if (arg0 < arg1) {
                do {
                    *var_a3 = *var_a3_2;
                    var_a3_2++;
                    arg2--;
                    var_a3++;
                } while (arg2 != 0);
            } else {
                temp_v0 = arg2 - 1;
                var_a3 = arg0 + temp_v0;
                var_a3_2 = arg1 + temp_v0;
                do {
                    *var_a3 = *var_a3_2;
                    var_a3_2--;
                    arg2--;
                    var_a3--;
                } while (arg2 != 0);
            }
        } else {
            if (arg0 < arg1) {
                arg2 >>= 2;
                do {
                    *(u32 *)arg0 = *(u32 *)arg1;
                    arg1 += 4;
                    arg2--;
                    arg0 += 4;
                } while (arg2 != 0);
            } else {
                arg2 >>= 2;
                arg0 += (arg2 * 4) - 4;
                arg1 += (arg2 * 4) - 4;
                do {
                    *(u32 *)arg0 = *(u32 *)arg1;
                    arg1 -= 4;
                    arg2--;
                    arg0 -= 4;
                } while (arg2 != 0);
            }
        }
    }
}

s32 func_80265444_de(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *end = arg0 + arg2;

    if (arg2 >= 4 && !((u32)arg0 & 3) && !((u32)arg1 & 3)) {
        end -= 4;
        if (end < arg0) {
            end += 4;
            goto byte_loop;
        }
word_loop:
        if (*(u32 *)arg0 != *(u32 *)arg1) {
            goto word_mismatch;
        }
        arg0 += 4;
        goto word_continue;
word_mismatch:
        arg0 -= 4;
        arg1 -= 4;
        goto word_done;
word_continue:
        arg1 += 4;
        if (arg0 <= end) {
            goto word_loop;
        }
word_done:
        end += 4;
    }

byte_loop:
    while (arg0 < end) {
        u8 left = *arg0;
        u8 right = *arg1;

        if (left != right) {
            if (left < right) {
                return -1;
            }
            return 1;
        }
        arg0++;
        arg1++;
    }
    return 0;
}

s32 func_802654E8_de(void *arg0, s32 arg1, s32 arg2) {
    u32 temp_v1;
    u32 var_a3;

    if (arg1 != 0) {
        arg1--;
        var_a3 = 0;
        if (arg1 != 0) {
            do {
                temp_v1 = (u32)(var_a3 + arg1) >> 1;
                if ((u32)*((s32 *)arg0 + temp_v1) < (u32)arg2) {
                    var_a3 = temp_v1 + 1;
                } else {
                    arg1 = temp_v1;
                }
            } while (var_a3 < (u32)arg1);
        }
        if (*((s32 *)arg0 + var_a3) == arg2) {
            return (s32)var_a3;
        }
        return -1;
    }
    return -1;
}

s32 func_80265550_de(u32 *arg0, s32 arg1, u32 arg2, s32 *arg3, s32 *arg4) {
    u32 temp_v1;
    u32 var_a3;
    s32 var_t0;
    s32 found;

    if (arg1 != 0) {
        var_t0 = arg1 - 1;
        var_a3 = 0;
        if (var_t0 != 0) {
            do {
                temp_v1 = (u32)(var_a3 + var_t0) >> 1;
                if (arg0[temp_v1] < arg2) {
                    var_a3 = temp_v1 + 1;
                } else {
                    var_t0 = temp_v1;
                }
            } while (var_a3 < (u32)var_t0);
        }
        if (arg0[var_a3] == arg2) {
            found = var_a3;
        } else {
            found = -1;
        }
    } else {
        found = -1;
    }

    if (found == -1) {
        return 0;
    }

    var_t0 = found - 1;
    while ((var_t0 != -1) && (arg0[var_t0] == arg2)) {
        var_t0--;
    }
    *arg3 = var_t0 + 1;

    found++;
    while ((found < arg1) && (arg0[found] == arg2)) {
        found++;
    }
    *arg4 = found - 1;
    return 1;
}

int func_8026563C_de(int arg0) {
    int result = arg0 + 7;
    if (result < 0) {
        result = arg0 + 0xE;
    }
    return result >> 3;
}

s32 func_80265650_de(void *arg0, s32 arg1)
{
  s32 temp_a1;
  s32 temp_v0;
  s32 var_a1;
  u8 *temp_a1_2;
  int new_var;
  var_a1 = arg1;
  temp_v0 = var_a1;
  if (temp_v0 < 0)
  {
    var_a1 = temp_v0 + 7;
  }
  temp_a1 = var_a1 >> 3;
  new_var = 1 << (temp_v0 - (temp_a1 * 8));
  temp_a1_2 = (u8 *)arg0 + temp_a1;
  return (*temp_a1_2 & new_var) != 0;
}

void func_80265688_de(u8 *arg0, s32 arg1, s32 arg2) {
    s32 byteIdx;
    s32 mask;

    byteIdx = arg1 / 8;
    mask = 1 << (arg1 % 8);
    if (arg2 != 0) {
        arg0[byteIdx] |= mask;
        return;
    }
    arg0[byteIdx] &= ~mask;
}

void func_802656DC_de(s32 arg0, s32 arg1)
{
  s32 temp_a1;
  s32 temp_v0;
  s32 var_a1;
  u8 *temp_a1_2;
  int new_var;
  var_a1 = arg1;
  temp_v0 = var_a1;
  if (temp_v0 < 0)
  {
    var_a1 = temp_v0 + 7;
  }
  temp_a1 = var_a1 >> 3;
  new_var = 1 << (temp_v0 - (temp_a1 * 8));
  temp_a1_2 = arg0 + temp_a1;
  *temp_a1_2 ^= new_var;
}





f32 func_80265714_de(f32 arg0)
{
  f32 var_f1;
  f32 var_f0;
  var_f0 = arg0;
  if (var_f0 < 0.0f)
  {
    var_f1 = 0.0f;
    var_f0 = var_f1;
  }
  else
  {
    var_f1 = D_800C4398_de;
    if (var_f1 < var_f0)
    {
      var_f0 = var_f1;
    }
  }
  return (D_800C43A0_de - func_802B6560_de(var_f0 * D_800C439C_de)) * (((struct func_802077F4_S2 *) ((char *) (&D_800C43A0_de)))->unk4);
}

extern char D_800C8140_de;
extern char D_1087D;
extern char jtbl_800C19C0;
extern char D_63F8;
extern void *D_800E2830;
extern char D_389E;

/** Return whether an address lies within one of three recognized ranges. */
int func_80265784_de(u32 arg0) {
    if (arg0 >= (u32)&D_800C8140_de &&
        arg0 < (u32)&D_800C8140_de + (u32)&D_1087D) {
        return 1;
    }
    if (arg0 >= (u32)&jtbl_800C19C0 &&
        arg0 < (u32)&jtbl_800C19C0 + (u32)&D_63F8) {
        return 1;
    }
    if (arg0 >= (u32)&D_800E2830 &&
        arg0 < (u32)&D_800E2830 + (u32)&D_389E) {
        return 1;
    }
    return 0;
}

/* Returns whether an address lies in either of two resident memory ranges. */
extern char D_800E4000, D_80166000, D_8014CEB0, D_8014DE3A;
int func_8026581C_de(u32 address) {
    if (address >= (u32)&D_800E4000 && address < (u32)&D_80166000) return 1;
    if (address >= (u32)&D_8014CEB0 && address < (u32)&D_8014DE3A) return 1;
    return 0;
}

/* Tests whether an address lies in either recognized resident range. */
extern char D_00200500;
extern char D_C0DA8;
extern char D_00400000;
extern char D_48B38;

int func_80265878_de(u32 arg0) {
    if (arg0 >= (u32)&D_00200500 &&
        arg0 < (u32)&D_00200500 + (u32)&D_C0DA8) {
        return 1;
    }
    if (arg0 >= (u32)&D_00400000 &&
        arg0 < (u32)&D_00400000 + (u32)&D_48B38) {
        return 1;
    }
    return 0;
}

void func_802658DC_de(void) {
}

extern void func_802BD320_de(void);

/** Thin wrapper around func_802BD320_de. */
void func_802658E4_de(void) {
    func_802BD320_de();
}
