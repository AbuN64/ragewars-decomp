#ifndef LIBGULTRA_H
#define LIBGULTRA_H

#include "TYPES.H"
extern int Libultra_SendDebugLinkIdentification(void);

extern s32 Libultra_ReceiveDebugLinkMemory(void);

extern s32 Libultra_SendDebugLinkMemory(void);

extern void Libultra_RunDebugLinkCommands();

extern u32 Libultra_ExchangeDebugLinkStrings(u8 *firstString, u8 *secondString);

extern int Libultra_SubmitDebugLinkBlock(void * stream, int elementBytes, int elementCount, int requestCode);

extern u32 Libultra_ExchangeDebugLinkWords(u32 firstWord, u32 secondWord, u32 thirdWord);

extern u32 Libultra_ExchangeDebugLinkWord(u32 requestWord);

extern s32 Libultra_SendDebugLinkString(u8 *text);

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
extern f32 alSeqTicksToSec(SequenceTicksPerQuarterView *sequence, s32 ticks, s32 tempo);

extern u32 alSeqSecToTicks(SequenceTicksPerQuarterView *seq, f32 sec, u32 tempo);

#include "COMMON/PARAMSRECAT8V3.H"
extern void _handleEvent(struct ALSndPlayer * sndp, union ALSndpEvent * event);

extern s32 _sndpVoiceHandler(void *node);

extern s32 readVarLen(ALSeq_s *);
extern const float g_sequenceMicrosecondsPerSecond;
extern s32 readVarLen(struct ALSeq_s *sequence);

extern void alSynDelete(s32 *initializedFlag);

#include "COMMON/ALPARAM_S.H"
extern void init_lpfilter(AudioLowPassFilter *lp);

extern int __osDpDeviceBusy();

#include "acmd.h"
extern void osViSetYScale(f32 yScale);

extern s32 g_serialDmaAssertText;
extern s32 s_sirawdmaText;

#endif
