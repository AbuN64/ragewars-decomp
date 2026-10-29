#ifndef ENGINE_AUDIO_AUDIOMGR_AUDIOMGR_WORKER_DMA_AND_FRAME_H
#define ENGINE_AUDIO_AUDIOMGR_AUDIOMGR_WORKER_DMA_AND_FRAME_H
#include "COMMON/CARTRIDGEREADWORKER.H"
extern s32 * Audiomgr_InitializeDmaState(s32 * * dmaState);
extern s32 Audiomgr_RenderAudioFrame(Work56EC8 *audioTask, u32 unused);
#endif
