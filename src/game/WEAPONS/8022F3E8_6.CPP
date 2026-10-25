#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern char D_800CE8DC;


extern s16 func_8022F96C_de(void *arg0);
extern s32 Render_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);












void func_80230630_de(LevelActor *arg0, void *arg1) {
    s32 state;
    void *actor;
    CGameStatus *audio;
    s32 mode;

    actor = arg0->controller;
    state = *(s16 *)(&D_800CE8DC +
                     (((Actor_func_8022D290_de *)actor)->unk_0x0650 * 0x18));
    if ((s8)((Dest *)arg1)->count != 0) {
        if (Weapons_HasAmmoForMode(actor, ((Actor_func_8022D290_de *)actor)->unk_0x062E) == 0) {
            if (((Dest *)arg1)->field13C == 2) {
                ((Dest *)arg1)->field13C = 1;
                if (Weapons_HasAmmoForMode(actor, ((Actor_func_8022D290_de *)actor)->unk_0x062E) == 0) {
                    ((Actor_func_8022D290_de *)actor)->unk_0x0770 = func_8022F96C_de(actor);
                }
            }
        }
    }
    func_8022B9C4_de(actor);
    ((Actor_func_8022D290_de *)actor)->unk_0x11FC = 0;
    ((WeaponAnimationState *)((Shared_ActorView *)actor)->controller)->speed = 0;
    ((Dest *)arg1)->field138 = 0;

    audio = &D_801462C8.counters;
    if ((audio->m_bFragTagOn != 0) &&
        (((Shared_ActorView *)actor)->controls->transientFlag != 0)) {
        if (((Actor_func_8022D290_de *)actor)->unk_0x06B0 & 0x2000) {
            mode = audio->m_nFragTagSkin;
            switch (mode) {
            case 0:
                Render_PlaySoundAtPosition(0x18A1,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 1:
                Render_PlaySoundAtPosition(0x1969,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 2:
                Render_PlaySoundAtPosition(0x1905,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            }
        }
    } else if ((state != 1) && (state != 7) &&
               ((s8)((Dest *)arg1)->count != 0)) {
        func_8022FDAC_de(arg0, arg1);
    }
}
#endif
