#include "include_asm.h"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"
#include "sdk/OSINT/802C0CB0.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"
#include "AUDIO/80259280_5.H"

/* Returns the physical address of a cached copy of a data block: finds the cache entry keyed by the
 * block's address and refreshes the copy (and flushes it from the data cache) when the size changed;
 * otherwise reuses a free entry or allocates and links a new 0x90-byte one, copies the block into it and
 * marks it in use. */



extern CacheEntry *D_80107DFC;

extern void *D_80107EA0;

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void func_802BD280_de(void *, s32);

extern s32 func_802B0340_de(s32, s32, void *, s32, s32);

/* Returns the physical address of a ROM offset through the 0x300-byte ROM window cache: a cached window
 * covering the offset and length is stamped with the current frame; otherwise a free window node is
 * linked in address order (or at the head), aligned to an even start, stamped, counted, filled from ROM
 * through func_80256454_de and its buffer address returned with the odd byte added back. */






extern Window *D_80107DF8;

extern char D_801011B8;

extern void func_80256454_de(void *, u32, s32, s32, void *, s32, s32);

void func_80256FC0_de(void) {
    u32 i;
    s32 value;
    Window *node;
    Window *next;

    value = 0;
    for (i = 0; i < D_800CB704_de; i++) {
        func_802BB2A0_de(&D_80107DD8, &value, 1);
    }

    node = D_80107DF4[0];
    if (node != 0) {
        do {
            next = node->next;
            if (node->frame + 1 < D_800CB700_de) {
                if (D_80107DF4[0] == node) {
                    D_80107DF4[0] = next;
                }
                func_802B2450_de((ListLink *)node);
                if (D_80107DF4[1] != 0) {
                    func_802B2480_de(node, (void **)D_80107DF4[1]);
                } else {
                    D_80107DF4[1] = node;
                    node->next = 0;
                    node->prev = 0;
                }
            }
            node = next;
        } while (node != 0);
    }

    D_800CB704_de = 0;
    D_800CB700_de++;
}

u32 func_802570C0_de(void *block, s32 size) {
    CacheEntry *entry;
    CacheEntry *unused;

    unused = 0;
    for (entry = D_80107DFC; entry != 0; entry = entry->next) {
        if (entry->key == block) {
            entry->state = 3;
            if (entry->size != size) {
                entry->size = size;
                func_802BD3A0_de(entry->data, block, size);
                func_802BD280_de(entry->data, size);
            }
            return func_802BBBC0_de(entry->data);
        }
        if (entry->state == 0) {
            unused = entry;
        }
    }
    if (unused == 0) {
        unused = (CacheEntry *)func_802B0340_de(0, 0, D_80107EA0, 1, 0x90);
        unused->next = D_80107DFC;
        D_80107DFC = unused;
        D_800CB714++;
    }
    unused->key = block;
    unused->state = 3;
    unused->size = size;
    func_802BD3A0_de(unused->data, block, size);
    return func_802BBBC0_de(unused->data);
}

u32 func_802571F0_de(s32 offset, s32 length) {
    Window *window;
    Window *after;
    Window **pool;
    u32 address;
    s32 end;
    s32 top;
    s32 odd;
    s32 word;

    after = 0;
    address = offset + D_801076A0;
    end = address + length;
    for (window = D_80107DF4[0]; window != 0; window = window->next) {
        top = window->base + 0x300;
        word = window->base;
        if (address < word) {
            break;
        }
        after = window;
        if (top >= end) {
            window->frame = D_800CB700_de;
            return func_802BBBC0_de(window->buffer + address - window->base);
        }
    }
    pool = &D_80107DF8;
    window = *pool;
    *pool = window->next;
    func_802B2450_de((ListLink *)window);
    if (after != 0) {
        func_802B2480_de(window, after);
    } else if (pool[-1] != 0) {
        after = pool[-1];
        pool[-1] = window;
        window->next = after;
        window->prev = 0;
        after->prev = window;
    } else {
        pool[-1] = window;
        window->next = 0;
        window->prev = 0;
    }
    odd = address & 1;
    address -= odd;
    window->base = address;
    window->frame = D_800CB700_de;
    word = window->buffer;
    D_800CB704_de++;
    func_80256454_de(&D_801011B8, address, 0x300, word, &D_80107DD8, 0, 1);
    return func_802BBBC0_de(word) + odd;
}

#include "COMMON/AUDIO_CONTEXT.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/ALAUXBUS_S.H"
#include "COMMON/AUDIO_INITIALIZE.H"
#include "TEXTURE/80256220.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern int D_8014D420_de, D_8014D45C;
extern float D_800C3ED0_de, D_800C3ED4;
typedef struct AudioBankHeader {
    s32 reserved0;
    s32 table;
    s32 reserved8;
    ALBankFile *bankFile;
} AudioBankHeader;
extern void func_802567A4_de(MenuRules *lock);
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);
extern void Texture_InitializeAudioWorker(ALSynConfig *, s32, AudioInitializeTiming *);
extern void func_802B2650_de(void *, void *);
extern void func_8025768C_de(ContextRecAt2BC0 *);
extern void func_8025D844_de(void *, void *);
extern void func_802596B4_de(void *, void *);
extern void func_8025B758_de(void *, void *);
extern void func_8025D158_de(void *, void *);
extern s32 D_800CD8C0_de;
extern s32 D_800CB724;
extern s32 D_800CB720;
extern s32 D_801076A0;
s32 func_80265964_de(s32 arg0);
void *func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2);
static inline void LockEnter(MenuRules *lock) {
    u32 mask = func_802BCF30_de();
    if (++lock->locked != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}
static inline void LockLeave(MenuRules *lock) {
    u32 mask = func_802BCF30_de();
    if (--lock->locked != 0) {
        __osRestoreInt(mask);
        func_802BB420_de(lock, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

/* Initialises the audio context: creates and takes its lock, sets up the frame heap and the synthesizer,
 * loads the sound bank and sorts the first instrument sounds by address, creates the sound player, clears the
 * voice handles and seeds the mix volumes from the saved settings bytes, then releases the lock. */
void func_80257360_de(ContextRecAt2BC0 *ctx) {
    ALSynConfig config;
    AudioInitializeTiming timing;
    AudioBankHeader *loaded;
    ALInstrument *instrument;
    ALSound *swap;
    s32 size;
    s32 j, i;
    s32 n;

    func_802567A4_de(&ctx->lock);
    LockEnter(&ctx->lock);
    ctx->soundState = 0;
    alHeapInit(ctx->frames, D_8014D420_de, D_8014D45C);
    config.maxVVoices = 0x25;
    config.maxPVoices = 0x25;
    config.maxUpdates = 0x100;
    config.fxType = 6;
    config.params = &D_800CB724;
    timing.frequency = 0x5622;
    timing.frameTime = 1;
    config.dmaproc = 0;
    config.heap = ctx->frames;
    timing.samples = 0x800;
    Texture_InitializeAudioWorker(&config, D_800CD8C0_de, &timing);
    D_801076A0 = func_80265964_de(8);
    size = func_80265964_de(4) - func_80265964_de(0);
    loaded = func_8023C78C_de(size, 0, func_80265964_de(0));
    ctx->field1D6C = loaded->table;
    ctx->resource = loaded->bankFile;
    ctx->font = ctx->resource->bankArray[0];
    func_8025768C_de(ctx);
    func_8025D844_de(ctx->panel, ctx);
    instrument = ctx->font->instArray[0];
    for (i = 0; i < instrument->soundCount; i++) {
        for (j = i + 1; j < instrument->soundCount; j++) {
            if ((u32)instrument->soundArray[j] < (u32)instrument->soundArray[i]) {
                swap = instrument->soundArray[i];
                instrument->soundArray[i] = instrument->soundArray[j];
                instrument->soundArray[j] = swap;
            }
        }
    }
    ctx->field24 = 0x11;
    ctx->field28 = 0xC0;
    ctx->field2C = ctx->frames;
    func_802B2650_de(ctx->list, &ctx->field24);
    {
        s16 noHandle = -1;

        for (n = 15; n >= 0; n--) {
            ctx->handles[n] = noHandle;
        }
    }
    ctx->selectedHandle = -1;
    ctx->field2B8C = -1;
    ctx->soundCounter = 0;
    ctx->frame = 0;
    ctx->field2B88 = 0;
    ctx->field2B94 = 0x40;
    ctx->field2B98 = 0;
    ctx->field2BB8 = 0;
    ctx->field2B9C = 0;
    func_802596B4_de(ctx->view, ctx);
    func_8025B758_de(ctx->menu, ctx);
    ctx->red = D_801462C8.volume[1] * D_800C3ED0_de;
    ctx->green = D_801462C8.volume[0] * D_800C3ED0_de;
    ctx->blue = D_801462C8.volume[2] * D_800C3ED0_de;
    ctx->field2BAC = 0;
    ctx->field2BB0 = D_801462C8.unknown17;
    ctx->field2BB4 = 1;
    ctx->alpha = D_800C3ED4;
    func_8025D158_de(ctx->dialog, ctx);
    D_800CB720 = 1;
    LockLeave(&ctx->lock);
}

#include "COMMON/AUDIO_CONTEXT.H"
#include "COMMON/EXTERNS_14.H"
#include "TYPES.H"
s32 func_80265964_de(s32 arg0);
void *func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2);
void func_8025768C_de(ContextRecAt2BC0 *ctx) {
    s32 total;
    s32 *index;
    s32 *rest;
    s32 *tables;
    s32 *names;
    s32 *refs;
    s32 *sounds;
    s32 *seq;
    s32 *group;
    void *section;

    total = func_80265964_de(0x14) - func_80265964_de(0x10);
    ctx->soundData = func_8023C78C_de(total, 0, func_80265964_de(0x10));
    section = func_8028FDB4_de(ctx->soundData, 0);
    func_8028FDB4_de(ctx->soundData, 1);
    tables = func_8028FDB4_de(section, 0);
    names = func_8028FDB4_de(section, 1);
    index = func_8028FDB4_de(section, 2);
    ctx->instrumentIndex = index;
    ctx->instrumentCount = *index;
    ctx->instrumentData = tables + 2;
    ctx->envelopeData = names + 2;
    rest = func_8028FDB4_de(section, 3);
    refs = func_8028FDB4_de(section, 4);
    sounds = func_8028FDB4_de(section, 5);
    ctx->tableCount2B7C = rest[1];
    ctx->table2B70 = rest + 2;
    ctx->tableCount2B80 = refs[1];
    ctx->table2B74 = refs + 2;
    ctx->tableCount2B84 = sounds[1];
    ctx->table2B78 = sounds + 2;
    group = func_8028FDB4_de(ctx->soundData, 1);
    seq = func_8028FDB4_de(group, 0);
    ctx->sequenceData = seq + 2;
    ctx->sequenceCount = seq[1];
    ctx->sequenceIndex = func_8028FDB4_de(group, 1);
}

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct SoundSlot {
    char pad00[0xC]; s32 id; char pad10[8]; s32 rate;
    char pad1C[4]; s16 volume;
    char pad22[2]; s32 pitch; char pad28[1]; u8 pan; char pad2A[2]; f32 gain;
    char pad30[0x70]; s32 playing; u32 flags; char padA8[0x1C]; s32 scaled; char padC8[4];
} SoundSlot;
typedef struct SoundManager { s32 header; SoundSlot slots[17]; } SoundManager;
typedef struct SoundContext {
    char pad00[0x84]; char voice[0x7E]; s16 pending;
    char pad104[0x34]; char sequence[0x1C80]; SoundManager manager;
    char pad2B48[0x54]; s32 volume;
    f32 gain; char pad2BA4[4]; f32 specialGain; char pad2BAC[0xC]; s32 scaled;
} SoundContext;
extern f32 D_800C3ED8_de;

extern void alSndpSetPitch(void *, s32);
extern void func_802B2DE0_de(void *, u8);
extern void alSndpSetPan(void *, u8);
extern void func_802B2F10_de(void *, s16);

s32 Texture_UpdateSoundSlot(SoundContext *context, s32 id) {
    s32 i;
    s16 index;
    SoundSlot *slot;
    u8 volume;
    f32 gain;
    if (id == -1) return -1;
    for (i = 0; i < 17; ++i)
        if (context->manager.slots[i].id == id) break;
    if (i == 17) i = -1;
    index = i;
    if (index == -1) return -1;
    if (index == 16) {
        /* the original leaves the owner and position arguments unset (stale a2/a3); pass an explicit empty owner and origin */
        static CVector3 origin;
        func_80259784_de(context->sequence, 16, 0, &origin);
        return -1;
    }
    slot = &context->manager.slots[index];
    if (slot->rate == 0 && !(slot->flags & 4)) {
        slot->flags |= 8;
        context->pending = -1;
        return 0;
    }
    if (!func_8025B854_de((SlotRecAtB8 *)&context->manager, index)) {
        alSndpSetPitch(context->voice, slot->pitch);
        volume = 127;
        if (slot->volume + context->volume < 128)
            volume = (u8)slot->volume + (u8)context->volume;
        func_802B2DE0_de(context->voice, volume);
        alSndpSetPan(context->voice, slot->pan);
        if (slot->flags & 0x200) gain = context->specialGain;
        else {
            gain = context->gain;
            if (slot->scaled && context->scaled) gain *= D_800C3ED8_de;
        }
        func_802B2F10_de(context->voice, (s16)(s32)((f32)slot->rate * gain * slot->gain));
        if (!slot->playing) func_8025B8BC_de((SlotRecAtB8 *)&context->manager, index);
    }
    context->pending = -1;
    return 0;
}
#else
INCLUDE_ASM("span_1000", Texture_UpdateSoundSlot);
#endif
