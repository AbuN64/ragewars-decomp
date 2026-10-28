#include "COMMON/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO/8025CCB0.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/AUDIO/audio_nextdecodedsampleblock.H"
#include "TEXTURE/80256220_16.H"
#include "AUDIO/802591C0.H"
#include "RENDER/SETN64_GETPACKSECTION.H"

/* Runs a music player's state machine on its channel: a start request loads the song's header and sequence from the song bank, records its tempo scale and volume, sets the sequence, clears the player queue, starts the sequence through Audio_InitDecodeStream, then sets the channel's sample rate from the sequence rate over 22050, its tempo, priority, channel volume, master volume and plays it; a playing song that has ended is stopped and returns to idle or to the start state when it loops, and a stop request stops the sequencer. The state is unsigned with an empty case 0, and the rate and tempo factors are literals so the resident rodata keeps its order. */












extern void Audio_GetDecodeFramesRemaining(void);

extern s32 Audio_InitDecodeStream(void *, s32, s32 *);

extern s32 alSndpGetState(char *);

extern void alSndpSetPitch(char *, f32);

extern void alSndpSetVol(char *, s32);

extern void alSndpSetPan(char *, s32);



extern void alSndpPlay(char *);

void Audio_UpdateDialogPlayer(PlayerRecAt24 *player) {
    extern void alSndpSetSound(char *, s32);
    extern func_80203E78_S1 *D_800D0D78;
    s32 rate;
    char *channel;
    s32 index;
    SongHeader *header;
    void *sequence;

    Sound_AcquireContextLock(player->bank);
    channel = Audio_GetSoundPlayer(player->bank);
    switch (player->state) {
        case 0:
            break;
        case 3:
            Audio_GetDecodeFramesRemaining();
            break;
        case 2:
            alSndpSetSound(channel, player->id);
            if (alSndpGetState(channel) == 0) {
                Audio_ClearDecodeFramesRemaining();
                if (player->loop >= 0) {
                    player->state = 1;
                } else {
                    player->state = 0;
                }
            }
            break;
        case 1:
            ((s32 *)D_80108064)[0] = 0;
            ((u8 *)D_80108064)[4] = 2;
            ((s32 *)D_80108064)[2] = 0;
            index = player->song * 2;
            header = SetN64_GetPackSection(player->bank->songs, index);
            player->tempoScale = header->tempo * 0.01f;
            player->volume = header->volume;
            sequence = SetN64_GetPackSection(player->bank->songs, index | 1);
            ((void **)D_80108064)[-1] = sequence;
            D_800D0D78->unk4 = Audio_InitDecodeStream(sequence, 0x5622, &rate);
            player->state = 3;
            alSndpSetSound(channel, player->id);
            alSndpSetPitch(channel, rate * 4.5351473e-05f);
            alSndpSetVol(channel, (s16)(player->speed * player->tempoScale));
            alSndpSetPan(channel, player->priority);
            alSndpSetPriority(channel, player->id, 0x7F);
            alSndpSetFXMix(channel, (u8)(u32)player->volume);
            alSndpPlay(channel);
            player->loop = -1;
            break;
    }
    Sound_ReleaseContextLock(player->bank);
}
