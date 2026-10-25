#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"
extern struct SoundOptionsScreen *D_800E58A0;
extern void **D_800E58A4;
#include "COMMON/UNUSED.H"
#include "MENU_2/804379C8_7.H"
#include "SYSTEM_2/8025E280.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"

/* Calls MarkMenuEventHandled, then sets the word at offset 0x14 of the object D_800E58A0 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */



extern void MarkMenuEventHandled();

extern void func_8041A430_de(void *, s32);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E58A8, an actor kind at D_800E58AC and a handler at D_800E58B0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80439390)(void *, s32, s32, s32, s32);



extern Handler80439390 D_800E58B0;

/* Builds a two-slider menu: allocates eight bytes into D_800E58A4 through Scene_AllocateMemory, creates the
   sliders VALUE_1D5/VALUE_1D5+1 and VALUE_1D5+2/VALUE_1D5+3 through func_8041A580_de, stores them in the block and sets them
   to the option bytes D_801462E0[0] and [1] through func_8041A6EC_de, then calls func_8041B110_de with
   VV_01D3. Returns zero. */



extern void **Scene_AllocateMemory(s32);

extern void *func_8041A580_de(s32, s32, s32);

extern void func_8041A6EC_de(void *, s32);

/* Releases the object D_800E58A4 holds through Scene_FreeMemory, clears D_800E58A4 and returns zero. */



/* Updates the two menu options and plays their change sounds. */




extern int func_8041A6E0_de(void *slider);



s32 func_80439174_de(void) {
    struct SoundOptionsScreen *state;

    MarkMenuEventHandled();
    state = D_800E58A0;
    state->target = -1;
    func_8041A430_de(state->menu, 2);
    return 0;
}

s32 func_804391B0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80439390 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E58B0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E58B0;
        index = 0;
        do {
            if (D_800E58A8[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E58AC[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}

s32 func_80439240_de(void) {
    u8 *options;
    void *slider;
    D_800E58A4 = Scene_AllocateMemory(8);
#if defined(VERSION_DE)
    slider = func_8041A580_de(0x1D1, 0x1D1 + 1, 0xFF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    slider = func_8041A580_de(0x1D5, 0x1D5 + 1, 0xFF);
#elif defined(VERSION_EU_X)
    slider = func_8041A580_de(0x1D8, 0x1D8 + 1, 0xFF);
#endif
    options = D_801462C8.volume;
    D_800E58A4[0] = slider;
    func_8041A6EC_de(slider, options[0]);
#if defined(VERSION_DE)
    slider = func_8041A580_de(0x1D1 + 2, 0x1D1 + 3, 0xFF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    slider = func_8041A580_de(0x1D5 + 2, 0x1D5 + 3, 0xFF);
#elif defined(VERSION_EU_X)
    slider = func_8041A580_de(0x1D8 + 2, 0x1D8 + 3, 0xFF);
#endif
    D_800E58A4[1] = slider;
    func_8041A6EC_de(slider, options[1]);
#if defined(VERSION_DE)
    func_8041B110_de(0x1CF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8041B110_de(0x1D3);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x1DC);
#endif
    return 0;
}

s32 func_804392D0_de(void) {
    Scene_FreeMemory(D_800E58A4);
    D_800E58A4 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80439300_de(void) {
    return 0;
}

extern unsigned char D_801462E1[]; /* MIXED func_80439308_de */
int func_80439308_de(void) {
 int value;
 unsigned char *options;
 int sound;
 value=func_8041A6E0_de(D_800E58A4[1]);
 options=D_801462E1;
 if(value!=options[0]){options[0]=value;Render_PlayFlatSound(0x460);}
 value=func_8041A6E0_de(D_800E58A4[0]);
 if(value!=options[-1]){
  options[-1]=value;
  if((unsigned char)value<5) sound=0;
  else {if(func_8025E2C4_de()!=0)goto end; sound=0x34;}
  func_8025E2D4_de(sound);
 }
 end: return 0;
}
