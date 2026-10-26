#include "COMMON/OBJB.H"
#include "MENU/8044ACCC.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"

/* Resets a 0x1208-byte actor: clears it through XPlus_FillMemory, initialises its three lists at 0xC,
   0x20 and 0xF24 through func_80255CA0_de, sets its words at 0x1200 and 0x38 to 1 and 2, clears those at
   0 to 8 and 0xF18 to 0xF20, and resets the parts at offset 0x40 through func_8044A170_de and
   Camera_UpdateViewProjectionAndEffects. */

extern void func_8044A170_de(void *);

extern void Camera_UpdateViewProjectionAndEffects(void *);

/* Updates each of the group's items (count at 0x8, 0xED8-byte records from the address at 0x4) through
   the block at 0x570 of each, then the group's own block at 0x5B0, all with func_8044A7D0_de. */


extern void Items_InitEntryPool(char *);

void Items_ResetPlayers(func_8044B27C_S1 *actor) {
    char *parts;

    XPlus_FillMemory(actor, 0, 0x1208);
    func_80255CA0_de(&actor->unkC, 0, 4);
    func_80255CA0_de(&actor->unk20, 0, 4);
    func_80255CA0_de(&actor->unkF24, 0, 4);
    parts = &actor->unk40;
    actor->unk1200 = 1;
    actor->unk0 = 0;
    actor->unk4 = 0;
    actor->unk8 = 0;
    actor->unkF18 = 0;
    actor->unkF1C = 0;
    actor->unkF20 = 0;
    actor->unk38 = 2;
    func_8044A170_de(parts);
    Camera_UpdateViewProjectionAndEffects(parts);
}

void Items_InitGroupPools(Triple *group) {
    int i;

    for (i = 0; i < group->z; i++) {
        Items_InitEntryPool((char *)(i * 0xED8 + group->y + 0x570));
    }
    Items_InitEntryPool((char *)group + 0x5B0);
}
