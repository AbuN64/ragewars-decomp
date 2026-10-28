#include "include_asm.h"
#include "SYSTEM/DEFS.H"
#include "sdk/AUDIO/sprintf.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/VECTOR4F.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "particle/GRAPHU64_MATRIXFROMEULERXYZ.H"

/* 80265370.CPP */
extern u32 D_80000318;

extern char D_800C8140_de;

extern char D_1087D;

extern char jtbl_800C19C0;

extern char D_63F8;

extern void *D_800E2830;

extern char D_389E;

/* Returns whether an address lies in either of two resident memory ranges. */
extern char D_800E4000, D_80166000, D_8014CEB0, D_8014DE3A;

/* Tests whether an address lies in either recognized resident range. */
extern char D_00200500;

extern char D_C0DA8;

extern char D_00400000;

extern char D_48B38;

/* Returns the s32 at a byte offset into a resource loaded from the cartridge, then releases it.
   The resource's ROM address is each cartridge's own, because the data before it differs in size. */
extern char D_800C4388_de;

extern void Cache_UnlockResource(s32, void *);

/* Loads the scene's point lights into the display list: with no light in D_8013B1A8 it clears geometry mode bit 0x80, otherwise it sets it and fills eight light slots from the light list, transforming each active light's position into the view, storing its negated view direction, its colour scaled by its intensity, its falloff and a fixed range, marking unused slots off, and emits the light-move command for each slot, then advances the light buffer. The first direction component is truncated into a local before negating. */
extern Gfx *g_displayListCursor;

extern s32 D_8010C4A0;

extern UnitLight D_8010C0A0[];

extern char D_8013B1A8;

extern LightNode *Gdynlight_GetFirstLight(void *);

extern LightNode *Gdynlight_GetNextLight(void *, LightNode *);

u32 Defs_GetMemorySize(void) {
    if (D_80000318 > 0x7FFFFFU) {
        return 0x700000;
    }
    return D_80000318;
}

void Defs_MoveMemory(u8 *split, u8 *arg1, s32 arg2) {
    u8 *var_a3;
    u8 *var_a3_2;
    s32 temp_v0;

    if (arg2 != 0) {
        var_a3 = split;
        if (((u32)arg1 | (u32)split | arg2) & 3) {
            var_a3_2 = arg1;
            if (split < arg1) {
                do {
                    *var_a3 = *var_a3_2;
                    var_a3_2++;
                    arg2--;
                    var_a3++;
                } while (arg2 != 0);
            } else {
                temp_v0 = arg2 - 1;
                var_a3 = split + temp_v0;
                var_a3_2 = arg1 + temp_v0;
                do {
                    *var_a3 = *var_a3_2;
                    var_a3_2--;
                    arg2--;
                    var_a3--;
                } while (arg2 != 0);
            }
        } else {
            if (split < arg1) {
                arg2 >>= 2;
                do {
                    *(u32 *)split = *(u32 *)arg1;
                    arg1 += 4;
                    arg2--;
                    split += 4;
                } while (arg2 != 0);
            } else {
                arg2 >>= 2;
                split += (arg2 * 4) - 4;
                arg1 += (arg2 * 4) - 4;
                do {
                    *(u32 *)split = *(u32 *)arg1;
                    arg1 -= 4;
                    arg2--;
                    split -= 4;
                } while (arg2 != 0);
            }
        }
    }
}

s32 Defs_CompareMemory(u8 *arg0, u8 *arg1, s32 arg2) {
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

s32 Defs_FindSortedValue(void *entries, s32 arg1, s32 arg2) {
    u32 temp_v1;
    u32 var_a3;

    if (arg1 != 0) {
        arg1--;
        var_a3 = 0;
        if (arg1 != 0) {
            do {
                temp_v1 = (u32)(var_a3 + arg1) >> 1;
                if ((u32)*((s32 *)entries + temp_v1) < (u32)arg2) {
                    var_a3 = temp_v1 + 1;
                } else {
                    arg1 = temp_v1;
                }
            } while (var_a3 < (u32)arg1);
        }
        if (*((s32 *)entries + var_a3) == arg2) {
            return (s32)var_a3;
        }
        return -1;
    }
    return -1;
}

s32 Defs_FindSortedGroupRange(u32 *arg0, s32 arg1, u32 group, s32 *arg3, s32 *last) {
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
                if (arg0[temp_v1] < group) {
                    var_a3 = temp_v1 + 1;
                } else {
                    var_t0 = temp_v1;
                }
            } while (var_a3 < (u32)var_t0);
        }
        if (arg0[var_a3] == group) {
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
    while ((var_t0 != -1) && (arg0[var_t0] == group)) {
        var_t0--;
    }
    *arg3 = var_t0 + 1;

    found++;
    while ((found < arg1) && (arg0[found] == group)) {
        found++;
    }
    *last = found - 1;
    return 1;
}

int Defs_GetBitArrayByteCount(int arg0) {
    int result = arg0 + 7;
    if (result < 0) {
        result = arg0 + 0xE;
    }
    return result >> 3;
}

s32 Defs_TestBit(void *arg0, s32 arg1)
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

void Defs_SetBitValue(u8 *arg0, s32 arg1, s32 found) {
    s32 byteIdx;
    s32 mask;

    byteIdx = arg1 / 8;
    mask = 1 << (arg1 % 8);
    if (found != 0) {
        arg0[byteIdx] |= mask;
        return;
    }
    arg0[byteIdx] &= ~mask;
}

void Defs_ToggleBit(s32 arg0, s32 arg1)
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

f32 Defs_CosineEase(f32 fraction)
{
  f32 clampBound;
  f32 clampedFraction;
  clampedFraction = fraction;
  if (clampedFraction < 0.0f)
  {
    clampBound = 0.0f;
    clampedFraction = clampBound;
  }
  else
  {
    clampBound = D_800C4398_de;
    if (clampBound < clampedFraction)
    {
      clampedFraction = clampBound;
    }
  }
  return (D_800C43A0_de - Math_Cosf(clampedFraction * D_800C439C_de)) * (((struct func_802077F4_S2 *) ((char *) (&D_800C43A0_de)))->unk4);
}

/** Return whether an address lies within one of three recognized ranges. */
int Defs_IsAddressInStaticRanges(u32 callback) {
    if (callback >= (u32)&D_800C8140_de &&
        callback < (u32)&D_800C8140_de + (u32)&D_1087D) {
        return 1;
    }
    if (callback >= (u32)&jtbl_800C19C0 &&
        callback < (u32)&jtbl_800C19C0 + (u32)&D_63F8) {
        return 1;
    }
    if (callback >= (u32)&D_800E2830 &&
        callback < (u32)&D_800E2830 + (u32)&D_389E) {
        return 1;
    }
    return 0;
}

int Defs_IsAddressInBufferRanges(u32 address) {
    if (address >= (u32)&D_800E4000 && address < (u32)&D_80166000) return 1;
    if (address >= (u32)&D_8014CEB0 && address < (u32)&D_8014DE3A) return 1;
    return 0;
}

int Defs_IsAddressInCodeRanges(u32 callback) {
    if (callback >= (u32)&D_00200500 &&
        callback < (u32)&D_00200500 + (u32)&D_C0DA8) {
        return 1;
    }
    if (callback >= (u32)&D_00400000 &&
        callback < (u32)&D_00400000 + (u32)&D_48B38) {
        return 1;
    }
    return 0;
}

void Defs_NoOperation(void) {
}

/** Formats one value into buffer. */
void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value) {
    func_802BD320_de(buffer, format, value);
}
/** Formats one value into buffer. */
void Defs_FormatSingleInteger(char *buffer, const char *format, s32 value) {
    func_802BD320_de(buffer, format, value);
}
/** Formats three values into buffer. */
void Defs_FormatThreeIntegers(char *buffer, const char *format, s32 a, s32 b, s32 c) {
    func_802BD320_de(buffer, format, a, b, c);
}
/** Formats four values into buffer. */
void Defs_FormatFourIntegers(char *buffer, const char *format, s32 a, s32 b, s32 c, s32 d) {
    func_802BD320_de(buffer, format, a, b, c, d);
}

s32 Defs_ReadResourceWord(s32 arg0) {
    void **resource;
    s32 result;

#if defined(VERSION_DE)
    resource = Cache_RequestResource(0, 0x28BB00, 0x28BB00, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#elif defined(VERSION_EU_X)
    resource = Cache_RequestResource(0, 0x290384, 0x290384, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#else
    resource = Cache_RequestResource(0, 0x28B244, 0x28B244, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#endif
    result = *(s32 *)((char *)*resource + arg0);
    Cache_UnlockResource(0, resource);
    return result;
}

void Defs_SetupPointLights(char *view) {
    LightNode *node;
    LightData *data;
    f32 position[4];
    f32 out[4];
    s32 i;
    s32 x;

    node = Gdynlight_GetFirstLight(&D_8013B1A8);
    if (node == 0) {
        Gfx *g = g_displayListCursor++;
        gSPGeometryMode(g, 0x80, 0);
        D_8010C4A0 += 8;
        return;
    }
    gSPGeometryMode(g_displayListCursor++, 0, 0x80);
    for (i = 0; i < 8; i++) {
        if (node != 0 && node->active != 0) {
            data = node->data;
            position[0] = node->position[0];
            position[1] = node->position[1];
            position[2] = node->position[2];
            Graphu64_TransformPoint(view + 0x220, position, out);
            x = out[0];
            D_8010C0A0[i + D_8010C4A0].dir[0] = -x;
            D_8010C0A0[i + D_8010C4A0].dir[1] = out[1];
            D_8010C0A0[i + D_8010C4A0].dir[2] = -(s32)out[2];
            D_8010C0A0[i + D_8010C4A0].color[3] = data->color[3] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[2] = data->color[0] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[1] = data->color[1] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[0] = data->color[2] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].falloff = data->falloff;
            D_8010C0A0[i + D_8010C4A0].near = data->near;
            D_8010C0A0[i + D_8010C4A0].range = 0x7F80;
        } else {
            D_8010C0A0[i + D_8010C4A0].falloff = -0x8000;
        }
        if (node != 0) {
            node = Gdynlight_GetNextLight(&D_8013B1A8, node);
        }
        {
            Gfx *g = g_displayListCursor++;
            gSPMoveMem(g, 10, ((i + 1) * 2 + 10) * 8, 16, &D_8010C0A0[i + D_8010C4A0]);
        }
    }
    D_8010C4A0 += 8;
}

#if defined(VERSION_US)
char rodata_unresolved_800C42E4[12] =
    "\000\000\000\000\010m_bFlag";
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4664[3] = {
    0x24020001, 0xA4620000, 0x0C0AFC14,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C43B4[3] = {
    0x41A00000, 0x3F800000, 0x41200000,
};
#endif

/* DATA_800C9498.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C9498 */
unsigned int D_blob_b4748ea260bef0e9dfa6[2] = {
    0x40F00000, 0x42080000,
};
#endif
