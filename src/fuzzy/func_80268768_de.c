#include "types.h"
#include "common/types_8a8189af7b05.h"

typedef struct SoundDefinition { s32 kind; } SoundDefinition;
typedef struct SoundActor {
    char pad0[0x18];
    SoundDefinition *definition;
} SoundActor;
typedef struct SoundSource {
    u8 kind;
    char pad1[0xCF];
    s32 owner;
} SoundSource;
extern s32 D_80146894;
extern u32 D_801462C8;
extern f32 D_800C4478_de;
extern f32 D_800C447C;
extern f32 D_800C9570;
extern s32 func_8024E968_de(void *);
extern s32 func_8025DEC0_de(s32, Vec3, s32, s32, f32);

void func_80268768_de(SoundActor *actor, SoundSource *source, s32 unused,
                     Vec3 position, s16 sound, s32 view) {
    f32 gain = D_800C4478_de;
    s32 owner = -1;
    u8 kind;
    if (D_80146894 == 0 && func_8024E968_de(actor) == view) {
        kind = source->kind;
        switch (kind) {
        case 0:
            owner = source->owner;
            break;
        case 1:
            if (actor->definition->kind == kind) {
                if (D_801462C8 & 0x40) {
                    gain = D_800C447C;
                }
                if (D_801462C8 & 0x20) {
                    gain = D_800C9570;
                }
            }
            break;
        }
        func_8025DEC0_de(sound, position, 0, owner, gain);
    }
}
