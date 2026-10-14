#include "types.h"
typedef struct Shared_Profile { char pad0[0x84]; char name[11]; u8 enabled; } Shared_Profile;
typedef struct SharedPlayer_func_8022A398_de { char pad0[0x5D8]; Shared_Profile *nameOwner; void *owner; char pad5E0[0xE08]; s32 next; char text[4][25]; } SharedPlayer_func_8022A398_de;
typedef struct Shared_MatchOptions { char pad0[0x1D]; u8 enabled; } Shared_MatchOptions;
extern Shared_MatchOptions D_801462C8;
extern s32 D_801468F4,D_80146918;
extern char *D_800D3A40,*D_800D3A44,*D_800D3A48,*D_800D3A54,*D_800D3A58;
#include "shared/menu_match_globals.h"
extern void func_802934C0_de(char *,const char *);
extern void func_80239770_de(void *,void *,char *,f32);
void func_80219688_de(SharedPlayer_func_8022A398_de *a,SharedPlayer_func_8022A398_de *b) {
    if (!D_801462C8.enabled) return;
    if (a!=b) {
        if (!a->nameOwner->enabled) return;
        if (D_801468F4) {
            func_802934C0_de(a->text[a->next], D_800D3A40);
            func_802934C0_de(a->text[a->next]+10, b->nameOwner->name);
            if (a->owner) func_80239770_de(&D_80145088,a->owner,a->text[a->next],1.5f);
            a->next++; a->next %= 4;
            func_802934C0_de(b->text[b->next], D_800D3A44);
            func_802934C0_de(b->text[b->next]+11, a->nameOwner->name);
        } else {
            if (!D_80146918) return;
            func_802934C0_de(a->text[a->next], D_800D3A48);
            func_802934C0_de(a->text[a->next]+10, b->nameOwner->name);
            if (a->owner) func_80239770_de(&D_80145088,a->owner,a->text[a->next],1.5f);
            a->next++; a->next %= 4;
            func_802934C0_de(a->text[a->next], D_800D3A54);
            if (a->owner) func_80239770_de(&D_80145088,a->owner,a->text[a->next],1.5f);
            a->next++; a->next %= 4;
            func_802934C0_de(b->text[b->next], D_800D3A44);
            func_802934C0_de(b->text[b->next]+11, a->nameOwner->name);
            if (b->owner) func_80239770_de(&D_80145088,b->owner,b->text[b->next],1.5f);
            b->next++; b->next %= 4;
            func_802934C0_de(b->text[b->next], D_800D3A58);
        }
        if (b->owner) func_80239770_de(&D_80145088,b->owner,b->text[b->next],1.5f);
    }
    b->next++; b->next %= 4;
}
