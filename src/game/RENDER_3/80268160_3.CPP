#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER_3/RANGENODE.H"
#include "TYPES.H"

/* Calls func_802172D0_de on an object, its block at offset 0x170 and a stack argument when the pause word is clear, the object exists and its first byte is one. Adapted from func_802688AC_de with the pause-word test, the callee and the extra stack argument changed, and the call wrapped in do-while(0) so the stack argument loads at entry. */


extern s32 D_80146894;
extern void func_802172D0_de(u8 *, u8 *, s32);

void func_80268864_de(void *unused, u8 *object, s32 third, struct IntPair pair, s32 fifth, s32 sixth) {
    if (D_80146894 == 0 && object != 0 && object[0] == 1) {
        do {
            func_802172D0_de(object, object + 0x170, sixth);
        } while (0);
    }
}

/* Calls func_80217388_de on an object and its block at offset 0x170 when the object exists and its
   first byte is one. The fourth argument is a record passed by value whose first word lands in
   its home slot. */


extern void func_80217388_de(u8 *, u8 *);

void func_802688AC_de(void *unused, u8 *object, s32 third, struct IntPair pair) {
    if (object != 0 && object[0] == 1) {
        func_80217388_de(object, object + 0x170);
    }
}

/* Damages the owner of a live actor (kind 1 with either blast bit of 0x300000 set) that is inside
   the blast: the radius is arg6 scaled by D_800C9570[1], and when the squared radius still covers
   the squared distance from the owner's position at 8 to arg1's position at 8, the remaining
   fraction of the squared radius times arg7 is applied through func_8022B11C_de. */











extern f32 D_800C9570[];
extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
extern void func_8022B11C_de(OwnerRecAt16D4 *, s32);

void func_802688E4_de(ActorRecAt1D8V3 *arg0, Player *player, s32 arg2, Blast blast) {
    CVector3 delta;
    OwnerRecAt16D4 *owner;
    f32 range;
    f32 dist;

    if (arg0->kind == 1 && (arg0->flags & 0x300000) != 0) {
        owner = arg0->owner;
        if (owner->alive != 0) {
            range = (f32)blast.radius * D_800C9570[1];
            func_80271F68_de(&delta, &owner->pos, &player->pos);
            dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            range = range * range;
            if (range < dist) {
                return;
            }
            func_8022B11C_de(owner, (s32)(((range - dist) / range) * (f32)blast.damage) & 0xFFFF);
        }
    }
}

void func_802689BC_de(LevelActor *actor, int arg1, int arg2, Blast blast) {
    actor->effectMode = (u8)blast.radius;
}

/* Calls func_80217388_de on an object and its block at 0x170, sets bit 0x20 in that block's first word, clears flags 0x10000, 0x2000 and 0x100 at offset 0x100, and calls func_80262C88_de when flag 0x80000 remains set. Adapted from func_802790C0_de with the block taken at offset 0x170 of the object, a by-value record added as the fourth argument, and each flag update written as a compound assignment to memory. */


extern void func_80217388_de(u8 *, u8 *);
extern void func_80262C88_de(void *arg0);




void func_802689CC_de(u8 *object, s32 second, s32 third, struct IntPair pair) {
    func_80217388_de(object, (char *)object + 0x170);
    ((LevelActor *)object)->behaviorFlags |= 0x20;
    ((LevelActor *)object)->flags &= 0xFFFEFFFF;
    ((LevelActor *)object)->flags &= ~0x2000;
    ((LevelActor *)object)->flags &= ~0x100;
    if (((LevelActor *)object)->flags & 0x80000) {
        func_80262C88_de(object);
    }
}
