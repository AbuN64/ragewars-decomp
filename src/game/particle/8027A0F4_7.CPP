#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"
#include "particle/8027A0F4_7.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern char D_801379C0;
extern char D_8013B1A8;

extern void func_80279A00_de(void *arg0);
extern void Particle_UpdateMatrix(void *);
extern void Render_DetachParticleSwooshes(void *arg0, void *arg1);










void func_8027FF58_de(void *arg0) {
    s32 *temp_v1_2;
    s32 temp_a1;
    s32 flags;
    s32 i;
    s32 clear_mask;
    s32 remove_offset;
    s32 active_mask;
    s32 flagged_offset;
    s32 head_offset;
    ParticleEffect *temp_s0;
    ParticleEffect *next;
    u8 *head_cursor;

    i = 0;
    clear_mask = 0xFDFFFEFF;
    remove_offset = 0xFC00;
    active_mask = 0x01000000;
    flagged_offset = 0xFC14;
    do {
        __builtin_memcpy(&next, &((EffectSystem *)arg0)->lists[i].head, sizeof(next));
        if (next != 0) {
            do {
                temp_s0 = next;
                next = next->next;
                flags = temp_s0->flags;
                if (flags & 0x100) {
                  if (!(flags & 0x800)) {
                    func_80279A00_de(temp_s0);
                    if (temp_s0->unk1D9 != 0) {
                        Particle_UpdateMatrix(temp_s0);
                        Render_DetachParticleSwooshes(&D_801379C0, temp_s0);
                    }
                    temp_a1 = temp_s0->unk138;
                    if (temp_a1 != 0) {
                        Render_ReleaseLight(&D_8013B1A8, temp_a1);
                        temp_s0->unk138 = 0;
                    }
                    temp_v1_2 = temp_s0->refCount;
                    if (temp_v1_2 != 0) {
                        *temp_v1_2 -= 1;
                    }
                    temp_s0->flags = temp_s0->flags & clear_mask;
                    func_80255ED8_de(temp_s0->list, temp_s0);
                    temp_s0->list = 0;
                    func_80255CB8_de((char *)arg0 + remove_offset, temp_s0);
                    if (temp_s0->flags & active_mask) {
                        func_80255ED8_de((char *)arg0 + flagged_offset, temp_s0);
                    }
                  }
                }
            } while (next != 0);
        }
        i += 1;
    } while (i < 3);
}
